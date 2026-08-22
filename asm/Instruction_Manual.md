# POPCOUNT 自定义指令接入手册：以 2020 年位计数题为例

本文面向当前仓库中的 LA32R 双发射五级流水线 CPU，完整说明如何加入一条读取
`rj`、写回 `rd` 的单周期自定义指令：

```text
popcount.acc rd, rj

GPR[rd] = GPR[rj] 中二进制 1 的数量
```

接入完成后，2020 年题目仍保留题目要求的最外层循环，只把原来逐位右移的内层循环
替换成一条硬件位计数指令。这样既没有用数学公式直接写出最终答案，也不会让硬件
加速器绕过汇编循环要求。

本文基于当前 `myCPU/` 的实际总线宽度和字段顺序编写。若这些文件以后又增加了其他
控制字段，应重新核算总线宽度，不能机械照搬数字。

## 1. 接入方案概览

### 1.1 指令语义

```text
输入：rj 的 32-bit 值
输出：0..32，零扩展成 32 bit 后写入 rd
异常：无
访存：无
分支：无
CSR：无
```

典型示例：

```text
GPR[r10] = 0xf000000f
popcount.acc r14, r10
GPR[r14] = 8
```

### 1.2 指令编码

当前 CPU 没有实现整数除法，但已经把精确编码 `0x00200000` 用作整机数组加速命令。
为了保留该命令，POPCOUNT 使用同一未实现 `div.w` 主操作码下的另一组编码：

```text
31                         15 14       10 9         5 4         0
+----------------------------+-----------+-----------+-----------+
| div.w 主操作码：17'h00040  | rk = 1    | rj        | rd        |
+----------------------------+-----------+-----------+-----------+
```

即：

```text
编码 = 0x00200400 | (rj << 5) | rd
```

例如 `rd=r14`、`rj=r10`：

```text
0x00200400 | (10 << 5) | 14 = 0x0020054e
```

GNU 反汇编器会把它显示为：

```asm
div.w $r14,$r10,$r1
```

这是预期现象，因为工具链不知道本 CPU 对该编码定义了自定义语义。CPU 内部实际执行
POPCOUNT。以后如果实现标准 `div.w`，必须重新分配自定义编码，不能同时保留这次的
编码约定。

### 1.3 流水线位置

本指令按普通 ALU 指令处理：

```text
IF 取到 32-bit 编码
  ↓
InstBuffer 调用 inst_decoder，产生 alu_op[12]
  ↓
ISSUE 读取 rj，检查 RAW，先限制为 lane0 单发
  ↓
EX 使用组合加法树计算 Popcount
  ↓
MEM 透传 32-bit 结果
  ↓
WB 写回 rd
```

它不使用现有 `accel_start/busy/done/flush` 通路，不接管数据 SRAM 接口，也不修改
`WB_stage` 的提交结构。

## 2. 需要修改的文件

| 文件 | 操作 |
| --- | --- |
| `myCPU/popcount32.v` | 新建组合位计数核心 |
| `myCPU/mycpu.vh` | 扩展译码和 ISSUE→EX 总线宽度 |
| `myCPU/inst_buffer.v` | 将最高 payload 分组扩大 1 bit |
| `myCPU/inst_decoder.v` | 识别编码并生成 `alu_op[12]` |
| `myCPU/ISSUE_stage.v` | 扩展 ALU 操作码并限制 POPCOUNT 为 lane0 单发 |
| `myCPU/EXE_stage.v` | 扩展两路 ALU 操作码寄存器和复位值 |
| `myCPU/alu.v` | 增加 POPCOUNT 运算和结果选择 |
| `asm/programs/user_sample.s` | 使用自定义机器码完成 2020 题 |

以下文件不需要修改：

- `myCPU/MEM_stage.v`：结果继续复用现有 `es_final_result_0` 字段；
- `myCPU/WB_stage.v`：继续作为普通 GPR 写回，不增加 debug FIFO 或反压；
- `myCPU/mycpu_top.v`：没有新顶层端口、总线仲裁或加速器实例；
- `myCPU/array_accel_engine.v` 和 `myCPU/accelerator_logic.v`：它们仍服务于原来的整机
  数组 Reduction 命令；
- `asm/programs/Makefile`：其 RTL 列表使用 `myCPU/*.v`，新建的 `popcount32.v` 会自动
  加入 Verilator 构建。

## 3. 新建 `myCPU/popcount32.v`

新建文件，内容如下：

```verilog
`timescale 1ns / 1ps
`default_nettype none

module popcount32 (
    input  wire [31:0] value,
    output wire [31:0] count
);

    // SWAR 分组加法：相邻位 → 2-bit 组 → 4-bit 组 → byte → word。
    wire [31:0] stage_1 =
        value - ((value >> 1) & 32'h5555_5555);

    wire [31:0] stage_2 =
        (stage_1 & 32'h3333_3333) +
        ((stage_1 >> 2) & 32'h3333_3333);

    wire [31:0] stage_3 =
        (stage_2 + (stage_2 >> 4)) & 32'h0f0f_0f0f;

    wire [31:0] stage_4 = stage_3 + (stage_3 >> 8);
    wire [31:0] stage_5 = stage_4 + (stage_4 >> 16);

    assign count = {26'b0, stage_5[5:0]};

endmodule

`default_nettype wire
```

必须覆盖的边界值：

| 输入 | 输出 |
| --- | ---: |
| `0x00000000` | 0 |
| `0x00000001` | 1 |
| `0x80000000` | 1 |
| `0xffffffff` | 32 |
| `0x55555555` | 16 |
| `0xaaaaaaaa` | 16 |

## 4. 修改 `myCPU/mycpu.vh`

### 4.1 修改前

```verilog
`define DS_DEC_BUS_WD   170
`define IBUF_ENTRY_BUS_WD (`FS_TO_DS_BUS_WD + `DS_DEC_BUS_WD)
`define DS_TO_ES_BUS_WD 255
`define FS_TO_DS_BUS_WD 97
`define DS_TO_ES_BUS_1_WD 223
```

### 4.2 修改后

```verilog
`define DS_DEC_BUS_WD   171
`define IBUF_ENTRY_BUS_WD (`FS_TO_DS_BUS_WD + `DS_DEC_BUS_WD)
`define DS_TO_ES_BUS_WD 256
`define FS_TO_DS_BUS_WD 97
`define DS_TO_ES_BUS_1_WD 224
```

原因：

- `alu_op` 从 12 bit 增至 13 bit，因此 `DS_DEC_BUS_WD` 增加 1；
- `IBUF_ENTRY_BUS_WD` 是表达式，会自动从 267 变成 268；
- lane0 和 lane1 的 ISSUE→EX 总线都携带 `alu_op`，所以两条总线各增加 1；
- EX→MEM 以后传递的是已经算好的 32-bit 结果，后续总线宽度不变。

不要顺手修改任何 `ES_TO_MS`、`MS_TO_WS` 或 `WS_TO_RF` 宽度。

## 5. 修改 `myCPU/inst_buffer.v`

`IBUF_ENTRY_BUS_WD` 从 267 增加到 268。当前 InstBuffer 把宽 payload 拆成五组 45 bit
和最后一组 42 bit，因此只扩大最高的 `g5` 分组。

### 5.1 扩大三个 `g5` 寄存器

把：

```verilog
reg [41:0] front_bus_0_g5;
reg [41:0] front_bus_1_g5;
reg [41:0] next_front_bus_1_g5;
```

改为：

```verilog
reg [42:0] front_bus_0_g5;
reg [42:0] front_bus_1_g5;
reg [42:0] next_front_bus_1_g5;
```

`next_front_bus_0` 本来就使用参数化的完整总线宽度，不需要单独改声明。

### 5.2 修改所有最高分组切片

把本文件中的所有：

```verilog
[266:225]
```

改为：

```verilog
[267:225]
```

当前文件需要修改的位置包括：

```verilog
next_front_bus_1_g5 = fifo_front_1[267:225];
next_front_bus_1_g5 = fifo_front_0[267:225];
next_front_bus_1_g5 = fifo_front_1[267:225];
next_front_bus_1_g5 = fifo_front_1[267:225];
next_front_bus_1_g5 = fifo_front_0[267:225];

front_bus_0_g5 <= next_front_bus_0[267:225];
```

`g0..g4` 的边界和以下两个地址镜像偏移保持不变：

```verilog
localparam integer HOT_RADDR1_LSB = `FS_TO_DS_BUS_WD + 56;
localparam integer HOT_RADDR2_LSB = `FS_TO_DS_BUS_WD + 51;
```

原因是新增的 `alu_op[12]` 位于译码总线高端，而 `rj/rkd` 字段以下的低位布局没有移动。

## 6. 修改 `myCPU/inst_decoder.v`

### 6.1 声明指令

在已有：

```verilog
wire inst_accel;
```

附近增加：

```verilog
wire inst_popcount;
```

### 6.2 增加精确译码

保留原整机加速命令：

```verilog
assign inst_accel = (inst == 32'h0020_0000);
```

紧接着增加：

```verilog
// 自定义 popcount.acc rd, rj：借用未实现的 div.w rd,rj,r1 编码。
assign inst_popcount = (inst[31:10] == 22'h000801);
```

比较 `inst[31:10]` 的效果是：

- 固定主操作码；
- 固定 `rk=1`；
- 允许 `rj` 和 `rd` 随指令变化；
- 不会与精确编码 `0x00200000` 的整机加速命令重叠。

### 6.3 加入已知指令集合

原来的末尾是：

```verilog
inst_cpucfg | inst_cacop | inst_csrwr | inst_csrxchg |
inst_accel;
```

改成：

```verilog
inst_cpucfg | inst_cacop | inst_csrwr | inst_csrxchg |
inst_accel | inst_popcount;
```

### 6.4 将 ALU 操作码扩大到 13 bit

把：

```verilog
wire [11:0] alu_op;
```

改成：

```verilog
wire [12:0] alu_op;
```

保留原 `alu_op[0]..alu_op[11]`，再增加：

```verilog
assign alu_op[12] = inst_popcount;
```

### 6.5 核对控制信号，不要误加第二源操作数

现有逻辑已经能为 POPCOUNT 产生正确控制：

```text
rf_raddr1 = rj
dest      = rd
gr_we     = 1
mem_we    = 0
need_rj   = 1
need_rkd  = 0
is_bj     = 0
is_mul    = 0
```

因此：

- 不要把 `inst_popcount` 加入 `src_reg_is_rd`；
- 不要把它加入 `src2_is_imm`；
- 不要把它加入 `ds_need_rkd`；
- 不要像 `inst_accel` 那样从 `gr_we` 中排除；
- 不要把它放入 `inst_accel` 字段。

`dec_bus` 的拼接语句不需要新增独立字段，因为 `inst_popcount` 已经编码进
`alu_op[12]`。总线只因 `alu_op` 自身扩大而增加 1 bit。

## 7. 修改 `myCPU/ISSUE_stage.v`

### 7.1 扩大两路 ALU 操作码

把：

```verilog
wire [11:0] alu_op_0;
wire [11:0] alu_op_1;
```

改成：

```verilog
wire [12:0] alu_op_0;
wire [12:0] alu_op_1;
```

两处 `dec_bus` 解包语句的字段顺序不变。lane1 使用的参数化切片：

```verilog
dec_bus_1[`DS_DEC_BUS_WD-2:23]
```

也不需要改端点表达式；宏宽度增加后，它会自动覆盖扩大的 `alu_op_1`。

### 7.2 生成本地指令类型

在发射能力判断附近增加：

```verilog
wire is_popcount_0 = alu_op_0[12];
wire is_popcount_1 = alu_op_1[12];
```

### 7.3 初次接入限制为 lane0 单发

原代码：

```verilog
wire special_0 = is_csr_0 || is_cacop_0 || is_cpucfg_0 || is_accel_0;
wire special_1 = is_csr_1 || is_cacop_1 || is_cpucfg_1 || is_accel_1;
```

改成：

```verilog
wire special_0 = is_csr_0 || is_cacop_0 || is_cpucfg_0 ||
                  is_accel_0 || is_popcount_0;
wire special_1 = is_csr_1 || is_cacop_1 || is_cpucfg_1 ||
                  is_accel_1 || is_popcount_1;
```

这里的作用只是：

- POPCOUNT 位于 front0 时，不让 front1 同拍发射；
- POPCOUNT 位于 front1 时，先发射 front0，下一拍它移动到 front0；
- 最终只有 lane0 执行 POPCOUNT，因此只需要一套硬件。

但是，下面的 `special_fire` **不能**加入 POPCOUNT。必须保持：

```verilog
assign special_fire = ds_to_es_valid_0 &&
                      (is_csr_0 || is_cacop_0 || is_accel_0);
```

`special_fire` 会设置跨周期的 `special_block`，只适合最后通过 flush 清除的 CSR、CACOP
和整机加速命令。POPCOUNT 是普通单周期写回指令，没有完成 flush；若误加进去，后续
普通程序会永久阻塞。

### 7.4 ISSUE→EX 拼接

以下拼接结构不增加独立字段：

```verilog
assign ds_to_es_bus_0 = {
    is_accel_0,
    ...,
    alu_op_0,
    ...
};

assign ds_to_es_bus_1 = {
    ds_pc_1,
    alu_op_1,
    ...
};
```

只要第 4 节已把两条总线各扩大 1 bit，扩大的 `alu_op` 会自动占用新增位。

现有 RAW 检测也无需新增比较器：译码已经设置 `need_rj=1`、`gr_we=1`、`dest=rd`，
所以 POPCOUNT 的输入依赖、输出依赖和 `$r0` 规则都会复用普通 ALU 路径。

## 8. 修改 `myCPU/EXE_stage.v`

### 8.1 扩大寄存器和解包线网

把以下四个声明从 `[11:0]` 改为 `[12:0]`：

```verilog
reg  [12:0] es_alu_op_0;
reg  [12:0] es_alu_op_1;
wire [12:0] ds_alu_op_0;
wire [12:0] ds_alu_op_1;
```

### 8.2 修改复位值

把：

```verilog
es_alu_op_0 <= 12'b0;
es_alu_op_1 <= 12'b0;
```

改为：

```verilog
es_alu_op_0 <= 13'b0;
es_alu_op_1 <= 13'b0;
```

`flush` 分支通过清除 `es_valid_*` 和写使能抑制副作用，保持现有结构即可；正常装载分支
也已经执行：

```verilog
es_alu_op_0 <= ds_alu_op_0;
es_alu_op_1 <= ds_alu_op_1;
```

### 8.3 给两路 ALU 设置硬件参数

lane0 ALU 修改为：

```verilog
alu #(
    .HAS_MUL      (1),
    .HAS_POPCOUNT (1)
) u_alu_0 (
    // 原端口保持不变
);
```

lane1 ALU 修改为：

```verilog
alu #(
    .HAS_MUL      (1),
    .HAS_POPCOUNT (0)
) u_alu_1 (
    // 原端口保持不变
);
```

由于 ISSUE 已禁止 POPCOUNT 进入 lane1，lane1 不需要第二套 Popcount 加法树。

### 8.4 前递和写回不需要新增字段

POPCOUNT 的 `alu_op[0]` 和 `alu_op[1]` 都为 0，因此现有前递选择：

```verilog
wire [31:0] es_fwd_result_0 = es_is_mul_0 ? es_mul_result_0 :
     ((es_alu_op_0[0] || es_alu_op_0[1]) ?
      alu_fast_result_0 : alu_result_0);
```

会自然选择 `alu_result_0`。它又没有被列入 `es_result_forwardable_0` 的排除项，所以紧随
其后的 `add.w` 可以直接取得 EX 前递结果，无需插入 `nop`。

不要把 POPCOUNT 加入以下排除式：

```verilog
!(es_is_csr_0 || es_is_cpucfg_0 || es_is_cacop_0 || es_is_accel_0)
```

否则必须同步扩展 ISSUE 的等待镜像，且会产生额外气泡。

## 9. 修改 `myCPU/alu.v`

### 9.1 增加参数并扩大操作码

模块头改成：

```verilog
module alu #(
    parameter HAS_MUL      = 1,
    parameter HAS_POPCOUNT = 1
)(
    input  wire        clk,
    input  wire        resetn,
    input  wire [12:0] alu_op,
    input  wire [31:0] alu_src1,
    input  wire [31:0] alu_src2,
    input  wire [31:0] mul_src1,
    input  wire [31:0] mul_src2,
    output wire [31:0] alu_result,
    output wire [31:0] alu_fast_result,
    output wire [31:0] mul_result
);
```

### 9.2 增加操作选择

在其他 `op_*` 声明附近增加：

```verilog
wire op_popcount;
assign op_popcount = alu_op[12];
```

### 9.3 只在需要的 lane 实例化硬件

在最终结果选择前增加：

```verilog
wire [31:0] popcount_result;

generate
    if (HAS_POPCOUNT) begin : gen_popcount
        popcount32 u_popcount32 (
            .value (alu_src1),
            .count (popcount_result)
        );
    end
    else begin : gen_no_popcount
        assign popcount_result = 32'b0;
    end
endgenerate
```

该文件已经有一个乘法器 `generate` 块。Verilog 允许同一模块出现多个具名 generate
块，只要块名不重复。

### 9.4 加入最终结果 mux

在 `alu_result` 的按位选择式末尾加入：

```verilog
| ({32{op_popcount}} & popcount_result)
```

完整尾部应类似：

```verilog
assign alu_result = ({32{op_add|op_sub}} & add_sub_result)
       | ({32{op_slt       }} & slt_result)
       | ({32{op_sltu      }} & sltu_result)
       | ({32{op_and       }} & and_result)
       | ({32{op_nor       }} & nor_result)
       | ({32{op_or        }} & or_result)
       | ({32{op_xor       }} & xor_result)
       | ({32{op_lui       }} & lui_result)
       | ({32{op_sll       }} & sll_result)
       | ({32{op_srl|op_sra}} & sr_result)
       | ({32{op_popcount  }} & popcount_result);
```

译码必须保证 ALU 操作码一热；POPCOUNT 指令只能置 `alu_op[12]`，不能同时置普通
ADD/逻辑/移位位。

## 10. 编写 2020 年测试程序

将 `asm/programs/user_sample.s` 改成：

```asm
    .global _start
    .section .text

    # 参数使用寄存器编号，而不是 $rN 文本。
    .macro popcount_acc rd_id, rj_id
        .word 0x00200400 | ((\rj_id & 31) << 5) | (\rd_id & 31)
    .endm

_start:
    # r11 = 0x31112，作为开区间终点。
    lu12i.w $r11, 200704>>12
    ori      $r11, $r11, 274

    addi.w   $r10, $r0, 1       # i = 1
    addi.w   $r12, $r0, 0       # ans = 0

.Loop:
    popcount_acc 14, 10         # r14 = popcount(r10)
    add.w    $r12, $r12, $r14   # ans += r14
    addi.w   $r10, $r10, 1      # i++
    bne      $r10, $r11, .Loop

    # CPU 虚地址 0x80700000；顶层转换后为 0x1c700000。
    lu12i.w  $r15, -522496
    st.w     $r12, $r15, 0

    or       $r4, $r0, $r0
    jr       $r1
```

边界说明：

- `$r10` 从 1 开始；
- 每次循环先计算当前 `$r10`；
- 计算后自增；
- 当自增结果等于 `0x31112` 时退出；
- 因而最后一个实际参与计算的数正好是 `0x31111`。


### 11.2 只编译测试程序并检查机器码

```bash
make -C asm/programs program
loongarch32r-linux-gnusf-objdump -d asm/.build/user_sample/user_sample.elf
```

对于宏调用 `popcount_acc 14, 10`，反汇编中应看到机器码：

```text
0020054e
```

反汇编助记符显示为 `div.w $r14,$r10,$r1` 是正常的。

### 11.3 运行 2020 完整测试

```bash
make -C asm/programs \
    EXPECT_VALUE=0x001a876b \
    MAX_CYCLES=300000000
```

必须同时满足：

```text
CHECK word PASS addr=80700000 value=001a876b
PASS asm monitor test
```

不能只看程序返回；必须确认结果地址中的值。

### 11.4 建议增加的指令级定向测试

在跑 2020 长循环前，建议用短程序依次测试：

```text
popcount(0x00000000) = 0
popcount(0x00000001) = 1
popcount(0x80000000) = 1
popcount(0xffffffff) = 32
popcount(0x55555555) = 16
```

还必须覆盖三类流水线相关：

```asm
# 普通 ALU → POPCOUNT，验证 rj 输入前递
addi.w       $r10, $r0, 7
popcount_acc 14, 10

# POPCOUNT → 普通 ALU，验证结果前递
popcount_acc 14, 10
add.w        $r12, $r12, $r14

# rd == rj，验证读旧值、写新值
popcount_acc 10, 10
```

### 11.5 四程序 CPU 回归

加入新指令不得破坏原有指令和 monitor：

```bash
make -f test/supervisor_perf.mk stream
make -f test/supervisor_perf.mk matrix
make -f test/supervisor_perf.mk cryptonight
make -f test/supervisor_perf.mk mixed
```


按流水级检查：

### IF / InstBuffer

```text
指令值                  = 0x0020054e（以 r14,r10 为例）
dec_bus 中 alu_op[12]   = 1
rf_raddr1               = 10
dest                    = 14
need_rj                 = 1
need_rkd                = 0
gr_we                    = 1
```

### ISSUE

```text
is_popcount_0            = 1
ds_to_es_valid_0         = 1
ds_to_es_valid_1         = 0
ds_alu_src1_0            = 当前 i
```

如果上一条指令刚写 `$r10`，还应确认 `rj_value_0` 来自正确的 EX/MEM/WB 前递优先级。

### EX

```text
es_alu_op_0[12]          = 1
es_alu_src1_0            = 当前 i
popcount_result          = 当前 i 的置位数
alu_result_0             = popcount_result
es_fwd_valid_0           = 1
```

### MEM / WB

```text
es_to_ms_valid_0         = 1
gr_we                    = 1
dest                     = rd
final_result             = popcount_result
WB 对 rd 写回一次
```

不得为了观察这些值恢复 `debug_wb_*` 长线或在 WB 中加入 debug FIFO；直接查看各流水级
内部信号。

## 13. 常见错误

### 13.1 POPCOUNT 后程序永久停住

最常见原因是把 `is_popcount_0` 加进了 `special_fire`。该信号会建立全局
`special_block`，而 POPCOUNT 没有对应 flush 去清除它。

### 13.2 所有指令译码突然错位

检查：

```text
DS_DEC_BUS_WD       = 171
IBUF_ENTRY_BUS_WD   = 268
DS_TO_ES_BUS_WD     = 256
DS_TO_ES_BUS_1_WD   = 224
InstBuffer g5       = [42:0]
InstBuffer 最高切片 = [267:225]
```

只改宏而没扩大 InstBuffer 的固定分组，会丢失译码总线最高位或造成拼接宽度告警。

### 13.3 POPCOUNT 得到 0，但译码正确

检查：

- `alu.v` 输入是否已经扩大成 `[12:0]`；
- `op_popcount` 是否连接 `alu_op[12]`；
- lane0 是否设置 `.HAS_POPCOUNT(1)`；
- 最终 `alu_result` 是否加入 `popcount_result` 选择项。

### 13.4 紧随 POPCOUNT 的 ADD 使用旧值

检查 `es_fwd_result_0` 是否选择 `alu_result_0`，以及 POPCOUNT 是否意外被加入
`es_result_forwardable_0` 的排除列表。也要检查译码是否正确设置 `gr_we` 和 `dest`。

### 13.5 与原整机加速命令冲突

两者应为：

```text
整机加速命令：inst == 0x00200000
POPCOUNT：     inst[31:10] == 0x000801，即 rk=1
```

不要把 POPCOUNT 写成匹配整个 `div.w` 操作码，否则会把原来的 `0x00200000` 一起覆盖。

## 16. 独立教程：接入同时使用 `rj`、`rk` 和 `rd` 的完整指令

本章讨论一种完整的“两源一目的”自定义算术指令：

```text
custom.acc rd, rj, rk

GPR[rd] = F(GPR[rj], GPR[rk])
```

这里的 `rj`、`rk`、`rd` 不是三路输入：

| 字段 | 作用 | 是否从寄存器堆读取 | 是否参与 RAW 检查 |
| --- | --- | --- | --- |
| `rj` | 第一源寄存器 | 是 | 是 |
| `rk` | 第二源寄存器 | 是 | 是 |
| `rd` | 目的寄存器 | 否 | 作为生产者目的 tag |

下面把 `andn.acc` 当作一条独立的新指令，从原始 CPU 开始完整接入。它的语义为：

```text
GPR[rd] = GPR[rj] & ~GPR[rk]
```

本章是独立教程，**不假设 POPCOUNT 或其他自定义 ALU 指令已经接入**。开始本章前的
CPU 基线必须是：

```text
alu_op                    [11:0]
DS_DEC_BUS_WD             170
IBUF_ENTRY_BUS_WD         267
DS_TO_ES_BUS_WD           255
DS_TO_ES_BUS_1_WD         223
```

如果当前工作树已经加入 POPCOUNT，请不要直接套用本章的绝对宽度；应选择保留哪一条
自定义指令，或者重新分配另一个 ALU 操作位并重新核算所有总线。本章以下代码只描述
“原始 CPU + ANDN”这一种完整、可独立验证的配置。

本章需要修改：

| 文件 | 操作 |
| --- | --- |
| `myCPU/mycpu.vh` | 为新的 ALU 操作位扩大三级总线 |
| `myCPU/inst_buffer.v` | 扩大最高 payload 分组，防止新增位被截断 |
| `myCPU/inst_decoder.v` | 识别三寄存器编码并声明两个源、一个目的 |
| `myCPU/ISSUE_stage.v` | 扩大两路操作码，复用现有双源 RAW 检查 |
| `myCPU/EXE_stage.v` | 扩大两路操作码寄存器 |
| `myCPU/alu.v` | 在两路 ALU 中实现 `rj & ~rk` |
| `asm/programs/user_sample.s` | 编码指令并执行功能、前递测试 |

`MEM_stage.v`、`WB_stage.v` 和 `mycpu_top.v` 不需要修改；本指令不访存、不接管总线、
不产生 flush，也不使用整机加速器的 `start/busy/done` 协议。

### 16.1 分配包含三个寄存器字段的编码

一条两源一目的指令必须让 `rk/rj/rd` 三个 5-bit 字段都可变，因此译码时只能固定
`[31:15]`，不能固定 `[31:10]`：

```text
31                         15 14       10 9         5 4         0
+----------------------------+-----------+-----------+-----------+
| 自定义主操作码              | rk        | rj        | rd        |
+----------------------------+-----------+-----------+-----------+
```

本例借用当前 CPU 尚未实现的 `mod.w` 编码族：

```text
inst[31:15] = 17'h00041
```

机器码生成公式：

```text
0x00208000 | (rk << 10) | (rj << 5) | rd
```

例如：

```text
andn.acc r14, r10, r11
= 0x00208000 | (11 << 10) | (10 << 5) | 14
= 0x0020ad4e
```

不要再比较 `inst[31:10]`，否则会把 `rk` 固定成常数，第二源寄存器无法变化。以后若
实现标准 `mod.w`，应重新分配自定义操作码。

### 16.2 调整 `myCPU/mycpu.vh`

`andn.acc` 独占新的 `alu_op[12]`。从原始 CPU 配置修改为：

```verilog
`define DS_DEC_BUS_WD   171
`define IBUF_ENTRY_BUS_WD (`FS_TO_DS_BUS_WD + `DS_DEC_BUS_WD)
`define DS_TO_ES_BUS_WD 256
`define FS_TO_DS_BUS_WD 97
`define DS_TO_ES_BUS_1_WD 224
```

后续总线仍不变，因为 EX 之后只传递计算结果、写使能和 `rd` tag。

### 16.3 调整 `myCPU/inst_buffer.v`

`IBUF_ENTRY_BUS_WD` 从 267 变成 268，最高分组扩大 1 bit：

```verilog
reg [42:0] front_bus_0_g5;
reg [42:0] front_bus_1_g5;
reg [42:0] next_front_bus_1_g5;
```

把原始文件中的所有：

```verilog
[266:225]
```

改为：

```verilog
[267:225]
```

`HOT_RADDR1_LSB` 和 `HOT_RADDR2_LSB` 仍不变。新增 ALU 操作位仍位于宽译码 payload
的高端，没有改变 `rj/rk` 地址在低位部分的位置。

### 16.4 修改 `myCPU/inst_decoder.v`

#### 16.4.1 声明和译码

增加：

```verilog
wire inst_andn_acc;

assign inst_andn_acc = (inst[31:15] == 17'h00041);
```

这里必须只固定 `[31:15]`。此时已有字段拆解可以直接复用：

```verilog
wire [4:0] rd = inst[4:0];
wire [4:0] rj = inst[9:5];
wire [4:0] rk = inst[14:10];
```

#### 16.4.2 加入已知指令集合

```verilog
wire inst_known =
    // 前面的原有指令保持不变；只修改末尾
    inst_cpucfg | inst_cacop | inst_csrwr | inst_csrxchg |
    inst_accel | inst_andn_acc;
```

#### 16.4.3 扩大 ALU 操作码

```verilog
wire [12:0] alu_op;

// alu_op[0]..alu_op[11] 保持原定义
assign alu_op[12] = inst_andn_acc;
```

#### 16.4.4 正确声明两个源操作数

本 CPU 对普通三寄存器算术指令采用：

```verilog
wire [4:0] rf_raddr1 = rj;
wire [4:0] rf_raddr2 = (src_reg_is_rd | is_csr) ? rd : rk;
```

`andn.acc` 不应加入 `src_reg_is_rd`，因此第二读地址自然就是 `rk`。

必须把它加入 `ds_need_rkd`：

```verilog
wire ds_need_rkd =
    inst_beq | inst_bne | inst_st_w |
    inst_blt | inst_bge | inst_bltu | inst_bgeu |
    inst_st_b | inst_st_h |
    inst_add_w | inst_sub_w | inst_slt | inst_sltu |
    inst_nor | inst_and | inst_or | inst_xor |
    inst_sll_w | inst_srl_w | inst_sra_w |
    inst_mul_w | is_csr | inst_andn_acc;
```

现有 `ds_need_rj` 对它会自然得到 1，不需要额外修改。最终控制信号必须是：

```text
rf_raddr1  = rj
rf_raddr2  = rk
dest       = rd
need_rj    = 1
need_rkd   = 1
gr_we      = 1
mem_we     = 0
res_from_mem = 0
src1_is_pc = 0
src2_is_imm = 0
is_bj      = 0
```

特别注意：

- 不要把 `inst_andn_acc` 加入 `src2_is_imm`，否则 EX 的第二操作数会变成立即数；
- 不要把它加入 `src_reg_is_rd`，否则第二读地址会错误地变成 `rd`；
- 不要从 `gr_we` 中排除它，否则计算结果永远不会写回；
- `rd=$r0` 时允许执行，但寄存器堆必须像普通指令一样丢弃写回。

### 16.5 修改 `myCPU/ISSUE_stage.v`

#### 16.5.1 扩大两路 ALU 操作码

```verilog
wire [12:0] alu_op_0;
wire [12:0] alu_op_1;
```

`dec_bus` 解包字段顺序保持不变，lane1 参数切片仍保持：

```verilog
dec_bus_1[`DS_DEC_BUS_WD-2:23]
```

#### 16.5.2 两个源值的选择路径

现有 ISSUE 已经为两路指令各提供两个寄存器堆读口：

```verilog
rj_value_0  // lane0 第一源，地址 rj
rkd_value_0 // lane0 第二源，地址 rk 或 rd
rj_value_1  // lane1 第一源
rkd_value_1 // lane1 第二源
```

当译码满足 `need_rj=1`、`need_rkd=1` 时，现有比较器会分别检查：

```text
rj 对 EX lane0/lane1、MEM lane0/lane1、WB 的 RAW
rk 对 EX lane0/lane1、MEM lane0/lane1、WB 的 RAW
```

现有操作数生成会自动得到：

```verilog
wire [31:0] ds_alu_src1_0 =
    src1_is_pc_0 ? ds_pc_0 : rj_value_0;

wire [31:0] ds_alu_src2_0 =
    src2_is_imm_0 ? imm_0 : rkd_value_0;
```

所以 `andn.acc` 在 EX 收到：

```text
ds_alu_src1_0 = GPR[rj] 或其最新前递值
ds_alu_src2_0 = GPR[rk] 或其最新前递值
dest_0        = rd
```

不需要新增 32-bit 操作数总线或寄存器堆端口。

#### 16.5.3 同包 RAW

如果 lane0 指令写出的 `rd` 被 lane1 的 `rj` 或 `rk` 使用，现有
`raw_0_to_1` 会阻止错误双发：

```verilog
wire raw_0_to_1 = gr_we_0 && (dest_0 != 5'b0) &&
     ((src1_rj_valid  && (dest_0 == src_raddr1_1)) ||
      (src1_rkd_valid && (dest_0 == src_raddr2_1)));
```

这里第二项是否生效完全依赖 `need_rkd_1=1`。若忘记在 decoder 中设置它，下面这种
程序会错误地双发并读取旧 `$r11`：

```asm
addi.w   $r11, $r0, 3
andn.acc $r14, $r10, $r11
```

#### 16.5.4 将它保持为普通双发射 ALU 指令

ANDN 只增加一个逐位取反和与操作，适合在两路 ALU 中都实现。不要把它加入
`special_0`、`special_1` 或 `special_fire`，这些表达式保持原样：

```verilog
wire special_0 = is_csr_0 || is_cacop_0 || is_cpucfg_0 || is_accel_0;
wire special_1 = is_csr_1 || is_cacop_1 || is_cpucfg_1 || is_accel_1;

assign special_fire = ds_to_es_valid_0 &&
                      (is_csr_0 || is_cacop_0 || is_accel_0);
```

因此 `andn.acc` 满足 `lane1_regular_alu`：

```text
gr_we=1, is_bj=0, mem_op=0, is_mul=0, special=0
```

它既可从 lane0 发射，也可从 lane1 发射；两条无相关 ANDN 还可以同拍发射。现有
`raw_0_to_1` 会阻止同包中 lane1 错误读取 lane0 尚未产生的 `rd`。

### 16.6 修改 `myCPU/EXE_stage.v`

将四个 ALU 操作码声明改为 13 bit：

```verilog
reg  [12:0] es_alu_op_0;
reg  [12:0] es_alu_op_1;
wire [12:0] ds_alu_op_0;
wire [12:0] ds_alu_op_1;
```

复位值改为：

```verilog
es_alu_op_0 <= 13'b0;
es_alu_op_1 <= 13'b0;
```

不需要新增 `es_rj`、`es_rk` 或 `es_rd`：

- `rj` 的值已经在 `es_alu_src1_0`；
- `rk` 的值已经在 `es_alu_src2_0`；
- `rd` 的编号已经在 `es_dest_0`；
- `es_gr_we_0` 控制是否写回。

指令结果仍通过 `es_exec_result_0 → es_final_result_0 → es_to_ms_bus_0` 传递，MEM/WB
总线不增加字段。

### 16.7 修改 `myCPU/alu.v`

把 ALU 操作码输入扩大到：

```verilog
input wire [12:0] alu_op;
```

增加操作选择和结果：

```verilog
wire op_andn_acc = alu_op[12];
wire [31:0] andn_acc_result = alu_src1 & ~alu_src2;
```

最终结果 mux 增加：

```verilog
| ({32{op_andn_acc}} & andn_acc_result)
```

`alu.v` 被 `u_alu_0` 和 `u_alu_1` 各实例化一次，因此上述逻辑会自然出现在两路 ALU
中，不需要新增参数或在 `EXE_stage.v` 修改实例端口。

### 16.8 MEM 和 WB 为什么不用修改

执行完成后，本指令已经退化成一条普通 32-bit GPR 写回：

```text
result = F(rj_value, rk_value)
gr_we  = 1
dest   = rd
```

MEM 不关心结果由 ADD 还是 ANDN 产生；WB 也只使用 `gr_we/dest/data`。
因此不能为了该指令新建 WB FIFO、事件寄存器或 debug 写回长线。

### 16.9 汇编宏

```asm
    .macro andn_acc rd_id, rj_id, rk_id
        .word 0x00208000 | ((\rk_id & 31) << 10) | ((\rj_id & 31) << 5) | (\rd_id & 31)
    .endm

    # r14 = r10 & ~r11
    andn_acc 14, 10, 11
```

对于上例，程序镜像中应出现 `0x0020ad4e`。GNU objdump 很可能显示标准 `mod.w`
助记符，这不代表 CPU 执行了除法。

### 16.10 必须覆盖的相关测试

除了运算边界，还要验证两个源和一个目的的所有重叠情况：

```text
rd != rj != rk            普通情况
rd == rj                  先读旧 rj，再覆盖 rd
rd == rk                  先读旧 rk，再覆盖 rd
rj == rk                  两个输入来自同一寄存器
rd == rj == rk            同一寄存器同时承担两个源和目的
rd == r0                  计算可执行，但写回必须丢弃
rj == r0                  第一操作数必须为 0
rk == r0                  第二操作数必须为 0
```

流水线相关至少覆盖：

```asm
# 前一条生产 rj
addi.w   $r10, $r0, 7
andn_acc 14, 10, 11

# 前一条生产 rk
addi.w   $r11, $r0, 3
andn_acc 14, 10, 11

# 自定义指令生产下一条的 rj
andn_acc 14, 10, 11
add.w    $r12, $r14, $r13

# 自定义指令生产下一条的 rk
andn_acc 14, 10, 11
add.w    $r12, $r13, $r14
```

波形中必须看到：

```text
rf_raddr1 = rj
rf_raddr2 = rk
need_rj   = 1
need_rkd  = 1
dest      = rd
ds_alu_src1 = 最新 rj 值
ds_alu_src2 = 最新 rk 值
WB 只对 rd 写回一次
```

若 `rj` 正确而 `rk` 总是旧值，优先检查 `ds_need_rkd`；若 `rk` 变成 `rd` 的旧值，优先
检查是否误加到了 `src_reg_is_rd`；若结果正确但没有写回，检查 `inst_known`、`gr_we`
和 `dest`。

### 16.11 完整 `asm/programs/user_sample.s`

下面的程序不仅检查运算结果，还刻意制造两类紧邻相关：

- `ori $r11,...` 紧接 `andn.acc`，验证第二源 `rk` 的前递；
- `andn.acc` 紧接 `st.w`，验证自定义指令结果作为 store 数据的相关处理。

```asm
    .global _start
    .section .text

    .macro andn_acc rd_id, rj_id, rk_id
        .word 0x00208000 | ((\rk_id & 31) << 10) | ((\rj_id & 31) << 5) | (\rd_id & 31)
    .endm

_start:
    # r10 = 0x0f0f0f0f
    lu12i.w $r10, 0x0f0f0
    ori      $r10, $r10, 0xf0f

    # r11 = 0x00ff00ff
    lu12i.w $r11, 0x00ff0
    ori      $r11, $r11, 0x0ff

    # r14 = 0x0f0f0f0f & ~0x00ff00ff = 0x0f000f00
    andn_acc 14, 10, 11

    # 虚地址 0x80700000，顶层转换后的物理地址是 0x1c700000。
    lu12i.w $r15, -522496
    st.w     $r14, $r15, 0

    or       $r4, $r0, $r0
    jr       $r1
```

该测试的唯一正确结果为：

```text
0x0f000f00
```

### 16.12 编译和仿真验证

#### 16.12.1 工具版本

```bash
verilator --version
```

必须是：

```text
Verilator 5.050 2026-07-01
```

#### 16.12.2 只编译程序并核对编码

```bash
make -C asm/programs program
loongarch32r-linux-gnusf-objdump \
    -d asm/.build/user_sample/user_sample.elf
```

`andn_acc 14,10,11` 必须生成：

```text
0020ad4e
```

objdump 可能把它显示成 `mod.w $r14,$r10,$r11`。应以机器码为准。

#### 16.12.3 运行结果检查

```bash
make -C asm/programs \
    EXPECT_VALUE=0x0f000f00 \
    MAX_CYCLES=10000000
```

必须同时出现：

```text
CHECK word PASS addr=80700000 value=0f000f00
PASS asm monitor test
```

只看到程序返回不算通过；必须检查 `0x80700000` 中的结果。

#### 16.12.4 原 CPU 四程序回归

ANDN 定向测试通过后，再确认新增译码位没有破坏原指令：

```bash
make -f test/supervisor_perf.mk stream
make -f test/supervisor_perf.mk matrix
make -f test/supervisor_perf.mk cryptonight
make -f test/supervisor_perf.mk mixed
```

正式验收只使用这四个程序；额外 ANDN 自检只作为开发期定向测试。


按流水级检查以下值。

#### IF / InstBuffer

```text
指令                  = 0x0020ad4e
inst[31:15]           = 17'h00041
rk/rj/rd              = 11 / 10 / 14
alu_op[12]            = 1
```

如果 `alu_op[12]` 在 decoder 中为 1、到 InstBuffer 前端却变成 0，优先检查：

```text
DS_DEC_BUS_WD          = 171
IBUF_ENTRY_BUS_WD      = 268
g5                     = [42:0]
最高切片               = [267:225]
```

#### ISSUE

```text
rf_raddr1_0            = 10
rf_raddr2_0            = 11
need_rj_0              = 1
need_rkd_0             = 1
dest_0                 = 14
gr_we_0                = 1
src2_is_imm_0          = 0
ds_alu_src1_0          = 0x0f0f0f0f
ds_alu_src2_0          = 0x00ff00ff
```

特别检查 `$r11` 是否来自前一条 `ori` 的最新前递值。若这里仍是旧值，问题属于 RAW
检测或 `need_rkd`，不是 ANDN 组合逻辑。

#### EX

```text
es_alu_op_0[12]        = 1
es_alu_src1_0          = 0x0f0f0f0f
es_alu_src2_0          = 0x00ff00ff
andn_acc_result        = 0x0f000f00
alu_result_0           = 0x0f000f00
es_fwd_valid_0         = 1
```

#### MEM / WB

```text
es_to_ms_valid         = 1
gr_we                  = 1
dest                   = 14
writeback data         = 0x0f000f00
最终 store 地址        = 0x1c700000
最终 store 数据        = 0x0f000f00
```

不得为了观察这些值恢复 `debug_wb_*` 长线、WB debug FIFO 或 debug 反压。

### 16.14 常见错误

#### 16.14.1 `rj` 正确、`rk` 错误

检查 `inst_andn_acc` 是否加入 `ds_need_rkd`，以及是否误加进 `src_reg_is_rd`。

#### 16.14.2 运算结果正确但没有写回

依次检查：

```text
inst_known
gr_we
dest=rd
es_to_ms_valid
WB 写使能
```

不要把 `inst_andn_acc` 从 `gr_we` 中排除。

#### 16.14.3 指令只能位于 lane0 或导致永久阻塞

检查是否误把 ANDN 加入 `special_0/special_1/special_fire`。本章实现的是两路普通 ALU
指令，不需要特殊指令 scoreboard，也没有 flush 去清除 `special_block`。

#### 16.14.4 普通指令突然全部计算错误

这通常不是 ANDN 布尔表达式的问题，而是宽总线字段错位。逐项确认：

```text
inst_decoder alu_op     [12:0]
ISSUE 两路 alu_op       [12:0]
EX ds/es 两路 alu_op    [12:0]
alu.v alu_op            [12:0]
```

并确认只扩大了 `DS_DEC` 和两条 `DS_TO_ES` 总线，未修改 EX→MEM→WB 总线。

#### 16.14.5 与标准 `mod.w` 冲突

本章有意借用尚未实现的 `mod.w` 主操作码。以后加入标准除法/取模单元时，必须先迁移
`andn.acc` 编码并同步修改汇编宏，不能让两个语义匹配同一编码。



ANDN 本身逻辑较浅，但新增 `alu_op[12]` 会进入 ALU 结果选择和前递网络。应读取实际
关键路径和 WNS，而不能凭 RTL 结构假定时序一定不变。

### 16.16 ANDN 独立教程验收清单

- [ ] 基线不依赖 POPCOUNT，`alu_op` 从 12 bit 独立扩展到 13 bit；
- [ ] 编码只固定 `[31:15]=17'h00041`，三个寄存器字段都可变；
- [ ] `DS_DEC/IBUF/DS_TO_ES0/DS_TO_ES1` 分别为 `171/268/256/224`；
- [ ] InstBuffer 最高分组为 43 bit，最高切片为 `[267:225]`；
- [ ] `rf_raddr1=rj`、`rf_raddr2=rk`、`dest=rd`；
- [ ] `need_rj=1`、`need_rkd=1`、`gr_we=1`；
- [ ] `alu_op[12]` 从 decoder 完整到达两路 ALU；
- [ ] ANDN 没有加入 `special_fire`，没有使用整机加速器协议；
- [ ] lane0、lane1、同包 RAW 和前递测试均正确；
- [ ] `0x0020ad4e` 得到 `0x0f000f00`；
- [ ] STREAM、MATRIX、CRYPTONIGHT、MIXED 全部通过；
- [ ] Vivado 使用原 `implement_design.tcl` 完成 implementation 并读取 routed 报告。

## 17. POPCOUNT 教程最终验收清单

- [ ] `0x00200000` 原整机加速命令仍能精确译码；
- [ ] POPCOUNT 编码固定 `rk=1`，`rj/rd` 可变；
- [ ] `alu_op` 全链路均为 13 bit；
- [ ] InstBuffer 的 268-bit payload 没有截断；
- [ ] POPCOUNT 读取 `rj`、不读取 `rk`、写回 `rd`；
- [ ] POPCOUNT 初始版本只进入 lane0；
- [ ] `special_fire` 没有包含 POPCOUNT；
- [ ] EX 结果可前递，紧随其后的 ADD 无需 `nop`；
- [ ] `0/1/0xffffffff/0x55555555` 等边界测试通过；
- [ ] 2020 结果为 `0x001a876b`；
- [ ] STREAM、MATRIX、CRYPTONIGHT、MIXED 全部通过；
- [ ] 新 Vivado implementation 成功生成 routed timing report；
- [ ] WNS 通过真实电路优化获得，没有加入虚假时序例外。
