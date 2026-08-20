# 硬件加速器接入手册：以 2025 年个人赛题为例

本文给出当前仓库 LA32R 双发射 CPU 的完整接入方法。目标是用一条自定义命令启动
Reduction 加速器，独占 CPU 数据类 SRAM 接口，扫描 ExtRAM 中的 3 MiB 数组，统计
`A[0]` 出现的次数，将结果写回固定地址，然后从触发指令的下一条指令继续执行。

本文按当前 `myCPU/` RTL 编写。所有需要新增、替换的代码都完整列出，不使用“原字段”、
“其余端口”或省略号代替代码。没有明确要求修改的 RTL 文件保持不变。

> 当前仓库已经有 `myCPU/array_accel_engine.v` 和
> `myCPU/accelerator_logic.v`，但 CPU 流水线尚未完成整机接线。本文说明的是完成接线所需
> 的全部改动，不表示这些改动已经应用到 RTL。

## 1. 接入结果和修改文件

接入后的执行顺序如下：

```text
0x00200000 自定义命令进入 lane0
        ↓
ISSUE 单发并设置 special_block
        ↓
命令停留在 EX，等待 MEM 和旧数据事务全部排空
        ↓
accel_start 拉高一个周期
        ↓
array_accel_engine 拉高 takeover_req
        ↓
mycpu_top 将数据总线所有权交给加速器
        ↓
加速器读取 0x1c400000..0x1c6fffff
        ↓
加速器把计数写到 0x1c700000，并等待写响应
        ↓
accel_done 拉高一个周期
        ↓
EX 发出 accel_flush，PC 跳到触发指令 PC+4
```

需要处理的文件如下：

| 文件 | 操作 |
| --- | --- |
| `myCPU/array_accel_engine.v` | 从 Reduction 模板复制，接入时不改模块内部 |
| `myCPU/accelerator_logic.v` | 完整替换为 2025 年计数逻辑 |
| `myCPU/mycpu.vh` | 修改两条级间总线宽度 |
| `myCPU/inst_buffer.v` | 扩展最高 payload 分组，完整保存新增的 `is_accel` 位 |
| `myCPU/inst_decoder.v` | 新增精确命令译码，并把 `is_accel` 放入译码总线 |
| `myCPU/ISSUE_stage.v` | 解包 `is_accel`，限制 lane0 单发，传入 EX |
| `myCPU/EXE_stage.v` | 保存命令状态，产生单拍 start，等待 done，发出完成冲刷 |
| `myCPU/MEM_stage.v` | 导出可安全接管数据口的 `mem_stage_empty` |
| `myCPU/mycpu_top.v` | 实例化加速器，连接控制信号，仲裁请求和响应 |
| `asm/programs/user_sample.s` | 替换为命令、返回值清零和返回指令组成的短程序 |

以下文件不要修改：

- `myCPU/WB_stage.v`：加速器命令不进入 MEM/WB，也不通过寄存器返回结果；
- `myCPU/data_txn_tracker.v`：继续观察仲裁后的真实数据口事务；
- `thinpad_top.v`：`mycpu_top` 的外部端口没有变化；
- `thinpad_sram_uart_bridge.v`：加速器复用现有类 SRAM 协议；
- `debug_wb_*` 相关逻辑：四个 debug 端口继续绑定常量，不能恢复写回长线或 debug FIFO。

## 2. 地址、命令和接口约定

2025 年题目的虚拟地址为：

| 用途 | CPU 虚地址 | 顶层数据口物理地址 |
| --- | --- | --- |
| 数组起点 | `0x8040_0000` | `0x1c40_0000` |
| 数组开区间终点 | `0x8070_0000` | `0x1c70_0000` |
| 结果地址 | `0x8070_0000` | `0x1c70_0000` |

加速器接在 `addr_translate` 之后，因此必须使用物理地址。扫描区间是
`[0x1c40_0000, 0x1c70_0000)`，最后一个元素地址是 `0x1c6f_fffc`。

触发命令使用当前 CPU 尚未实现的精确 `div.w $r0,$r0,$r0` 编码：

```asm
.word 0x00200000
```

只识别这一条 32 bit 编码，不能把所有 `div.w` 编码都劫持为加速器命令。该命令不读
通用寄存器、不写通用寄存器、不发普通访存、只从 lane0 单发，并作为串行化长延迟命令
停留在 EX。

加速器与数据口必须遵守以下握手规则：

- `mem_req` 在 `mem_addr_ok` 前保持有效，`mem_wr`、`mem_addr`、`mem_wstrb` 和
  `mem_wdata` 同时保持稳定；
- 请求被 `mem_addr_ok` 接受后，必须等待与该请求对应的 `mem_data_ok`；
- 当前 bridge 只按单笔事务使用，因此 `MAX_OUTSTANDING` 固定为 1；
- 结果写请求收到 `mem_data_ok` 后才能拉高 `done`；
- 总线所有者切换时，请求和所有响应/ready 信号必须一起切换。

## 3. 添加加速器源文件

### 3.1 `myCPU/array_accel_engine.v`

在仓库根目录执行：

```bash
cp asm/Template/Reduction/array_accel_engine.v myCPU/array_accel_engine.v
```

该文件完整复制，不修改模块名、端口和状态机。顶层实例化时通过参数设置题目地址和
outstanding 数量。不要同时把 `asm/Template/Map/accelerator_logic.v` 放入
`myCPU/`，因为 Map 和 Reduction 模板都定义了同名模块 `accelerator_logic`。

### 3.2 `myCPU/accelerator_logic.v`

将该文件完整替换为以下内容：

```verilog
`timescale 1ns / 1ps
`default_nettype none

module accelerator_logic (
    input  wire        clk,
    input  wire        resetn,
    input  wire        run_start,
    input  wire        first_valid,
    input  wire        data_valid,
    input  wire [31:0] data,
    output wire [31:0] result
);

    reg [31:0] key_reg;
    reg [31:0] result_reg;

    always @(posedge clk) begin
        if (!resetn) begin
            key_reg    <= 32'b0;
            result_reg <= 32'b0;
        end
        else if (run_start) begin
            key_reg    <= 32'b0;
            result_reg <= 32'b0;
        end
        else if (first_valid) begin
            key_reg    <= data;
            result_reg <= 32'd1;
        end
        else if (data_valid) begin
            if (data == key_reg)
                result_reg <= result_reg + 32'd1;
        end
    end

    assign result = result_reg;

endmodule

`default_nettype wire
```

`first_valid` 对应 `A[0]`，所以保存 key 的同时把计数置为 1。`data_valid` 只对应后续
元素，避免把 `A[0]` 计算两次。

## 4. 修改级间总线宽度和 IBuffer

### 4.1 修改 `myCPU/mycpu.vh`

打开 `myCPU/mycpu.vh`，找到以下三行：

```verilog
`define DS_DEC_BUS_WD   169

`define IBUF_ENTRY_BUS_WD (`FS_TO_DS_BUS_WD + `DS_DEC_BUS_WD)

`define DS_TO_ES_BUS_WD 254
```

完整替换为：

```verilog
`define DS_DEC_BUS_WD   170

`define IBUF_ENTRY_BUS_WD (`FS_TO_DS_BUS_WD + `DS_DEC_BUS_WD)

`define DS_TO_ES_BUS_WD 255
```

`DS_TO_ES_BUS_1_WD` 保持 223，不增加 lane1 的 EX 总线字段。新字段都加在现有总线最高
位，因此原有低位字段位置不变。但是 `inst_buffer.v` 对完整 payload 做了固定宽度的分组
寄存，必须按下一节同步扩展最高分组；只修改宏会丢失新增的最高位。

### 4.2 修改 `myCPU/inst_buffer.v`

`IBUF_ENTRY_BUS_WD` 从 266 增加到 267 后，IBuffer payload 的完整位范围变为
`[266:0]`。现有 `g0` 至 `g4` 每组 45 bit，共覆盖 225 bit，因此 `g5` 必须是
42 bit，并覆盖 `[266:225]`：

```text
g0 = [44:0]
g1 = [89:45]
g2 = [134:90]
g3 = [179:135]
g4 = [224:180]
g5 = [266:225]
```

#### 4.2.1 扩展两路 front 的 g5 寄存器

找到：

```verilog
  reg [40:0] front_bus_0_g5;
  reg [40:0] front_bus_1_g5;
```

分别替换为：

```verilog
  reg [41:0] front_bus_0_g5;
  reg [41:0] front_bus_1_g5;
```

`front_bus_0_r` 和 `front_bus_1_r` 的拼接语句不需要改写；当 g5 扩展到 42 bit 后，
拼接结果自然变为 `42 + 5 × 45 = 267` bit。

#### 4.2.2 扩展 lane1 下一值的 g5 寄存器

找到：

```verilog
  reg [40:0] next_front_bus_1_g5;
```

替换为：

```verilog
  reg [41:0] next_front_bus_1_g5;
```

#### 4.2.3 替换完整的 lane1 g5 选择块

将负责 `next_front_bus_1_g5` 的整个组合逻辑块替换为：

```verilog
  always @(*)
  begin
    next_front_bus_1_g5 = front_bus_1_g5;
    if (pop_1)
      next_front_bus_1_g5 = fifo_front_1[266:225];
    else if (pop_0)
    begin
      if (front_valid_1_r && (cnt != CNT_ZERO))
        next_front_bus_1_g5 = fifo_front_0[266:225];
      else if (!front_valid_1_r)
        next_front_bus_1_g5 = fifo_front_1[266:225];
    end
    else if (!front_valid_0_r)
      next_front_bus_1_g5 = fifo_front_1[266:225];
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
      next_front_bus_1_g5 = fifo_front_0[266:225];
  end
```

#### 4.2.4 扩展 lane0 g5 的写入切片

在 IBuffer payload 的时序写入块中找到：

```verilog
      if (front0_we_g5)
        front_bus_0_g5 <= next_front_bus_0[265:225];
```

替换为：

```verilog
      if (front0_we_g5)
        front_bus_0_g5 <= next_front_bus_0[266:225];
```

`front_bus_1_g5 <= next_front_bus_1_g5;` 不需要修改，因为两端已经同时扩展为 42 bit。
`HOT_RADDR1_LSB` 和 `HOT_RADDR2_LSB` 也不需要修改，因为新增字段位于整个 payload 的
最高位，原有寄存器地址字段仍保持原 bit 位置。

如果遗漏本节，Verilator 会报告：

```text
Operator ASSIGNW expects 267 bits on the Assign RHS,
but Assign RHS's REPLICATE generates 266 bits
```

此时 `fifo` 虽然保存了 bit 266，但 front 分组寄存器只保存到 bit 265，重组时最高位被
补成 0，导致 `is_accel_0` 永远无法到达 ISSUE。

## 5. 修改 `myCPU/inst_decoder.v`

### 5.1 声明并译码命令

在以下声明之后：

```verilog
  wire inst_csrwr, inst_csrxchg;
```

插入：

```verilog
  wire inst_accel;
```

在以下现有赋值之后：

```verilog
  assign inst_csrxchg = (inst[31:24] == 8'h04) &&
       (rj != 5'd0) && (rj != 5'd1);
```

插入：

```verilog
  assign inst_accel = (inst == 32'h0020_0000);
```

### 5.2 替换 `inst_known`

将原来的整段 `wire inst_known =` 替换为：

```verilog
  wire inst_known = inst_add_w | inst_sub_w | inst_slt | inst_sltu |
       inst_nor | inst_and | inst_or | inst_xor |
       inst_slli_w | inst_srli_w | inst_srai_w |
       inst_addi_w | inst_ld_w | inst_st_w |
       inst_jirl | inst_b | inst_bl | inst_beq | inst_bne |
       inst_lu12i_w |
       inst_slti | inst_sltui | inst_andi | inst_ori | inst_xori |
       inst_sll_w | inst_srl_w | inst_sra_w | inst_pcaddu12i |
       inst_blt | inst_bge | inst_bltu | inst_bgeu |
       inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu |
       inst_st_b | inst_st_h |
       inst_mul_w |
       inst_cpucfg | inst_cacop | inst_csrwr | inst_csrxchg |
       inst_accel;
```

### 5.3 替换寄存器写使能

将原来的整段 `wire gr_we =` 替换为：

```verilog
  wire gr_we         = inst_known & ~inst_accel &
       ~inst_st_w & ~inst_st_b & ~inst_st_h &
       ~inst_beq & ~inst_bne & ~inst_b &
       ~inst_blt & ~inst_bge & ~inst_bltu & ~inst_bgeu &
       ~inst_cacop;
```

### 5.4 替换第一源操作数需求

将原来的整段 `wire ds_need_rj =` 替换为：

```verilog
  wire ds_need_rj  = ~inst_accel &
       ~inst_b & ~inst_bl & ~inst_lu12i_w &
       ~inst_pcaddu12i & ~inst_csrwr;
```

`ds_need_rkd` 是正向列举，`inst_accel` 没有出现在该列表中，所以不修改。

### 5.5 替换完整的译码总线打包

将文件中从 `assign dec_bus = {` 开始、到对应 `};` 结束的整个打包语句替换为：

```verilog
  assign dec_bus = {
    inst_accel,
    alu_op, imm, br_offs, jirl_offs,
    rf_raddr1, rf_raddr2, dest,
    src1_is_pc, src2_is_imm, res_from_mem, gr_we, mem_we,
    is_mul,
    ld_byte, ld_half, ld_sign_ext, st_byte, st_half,
    ds_need_rj, ds_need_rkd, ds_is_bj,
    inst_beq, inst_bne, inst_blt, inst_bge, inst_bltu, inst_bgeu,
    inst_jirl, inst_bl, inst_b,
    inst_cpucfg, inst_cacop, cacop_code,
    is_csr, inst_csrxchg, csr_num
  };
```

命令没有匹配任何普通 ALU、load/store、branch、CSR 或 CACOP 译码，所以除新增的
`inst_accel` 外，`mem_we`、`res_from_mem`、`is_mul` 和 `ds_is_bj` 自然为 0。

## 6. 修改 `myCPU/ISSUE_stage.v`

### 6.1 新增 lane0 字段并替换 lane0 解包

在 lane0 译码信号声明区、`wire [11:0] alu_op_0;` 之前插入：

```verilog
  wire        is_accel_0;
```

将 lane0 的整个译码总线解包赋值替换为：

```verilog
  assign {is_accel_0,
          alu_op_0, imm_0, br_offs_0, jirl_offs_0,
          rf_raddr1_0, rf_raddr2_0, dest_0,
          src1_is_pc_0, src2_is_imm_0, res_from_mem_0, gr_we_0, mem_we_0,
          is_mul_0,
          ld_byte_0, ld_half_0, ld_sign_ext_0, st_byte_0, st_half_0,
          need_rj_0, need_rkd_0, is_bj_0,
          inst_beq_0, inst_bne_0, inst_blt_0, inst_bge_0,
          inst_bltu_0, inst_bgeu_0,
          inst_jirl_0, inst_bl_0, inst_b_0,
          is_cpucfg_0, is_cacop_0, cacop_code_0,
          is_csr_0, is_csrxchg_0, csr_num_0} = dec_bus_0;
```

### 6.2 新增 lane1 字段并替换 lane1 高位解包

在 lane1 译码信号声明区、`wire [11:0] alu_op_1;` 之前插入：

```verilog
  wire        is_accel_1;
```

将 lane1 原来的高位解包和三个低位单独赋值全部替换为：

```verilog
  assign is_accel_1 = dec_bus_1[`DS_DEC_BUS_WD-1];

  assign {alu_op_1, imm_1, br_offs_1, jirl_offs_1,
          rf_raddr1_1, rf_raddr2_1, dest_1,
          src1_is_pc_1, src2_is_imm_1, res_from_mem_1, gr_we_1, mem_we_1,
          is_mul_1,
          ld_byte_1, ld_half_1, ld_sign_ext_1, st_byte_1, st_half_1,
          need_rj_1, need_rkd_1, is_bj_1,
          inst_beq_1, inst_bne_1, inst_blt_1, inst_bge_1,
          inst_bltu_1, inst_bgeu_1,
          inst_jirl_1, inst_bl_1, inst_b_1}
       = dec_bus_1[`DS_DEC_BUS_WD-2:23];

  assign is_cpucfg_1 = dec_bus_1[22];
  assign is_cacop_1  = dec_bus_1[21];
  assign is_csr_1    = dec_bus_1[15];
```

lane1 只读取 `is_accel_1` 来禁止该命令从 lane1 发射，不把该字段传入
`ds_to_es_bus_1`。

### 6.3 替换特殊指令分类

找到：

```verilog
  wire special_0 = is_csr_0 || is_cacop_0 || is_cpucfg_0;
  wire special_1 = is_csr_1 || is_cacop_1 || is_cpucfg_1;
```

替换为：

```verilog
  wire special_0 = is_csr_0 || is_cacop_0 || is_cpucfg_0 || is_accel_0;
  wire special_1 = is_csr_1 || is_cacop_1 || is_cpucfg_1 || is_accel_1;
```

已有 `issue1_fire_for_ex` 和 `issue1_fire_for_consume` 都包含 `!special_0`，所以
`is_accel_0` 为 1 时 lane1 不会同发；`special_1` 又保证命令位于 IBuffer lane1 时不能
作为 lane1 指令越过 lane0。

### 6.4 替换串行化 scoreboard 触发条件

找到：

```verilog
  assign special_fire = ds_to_es_valid_0 && (is_csr_0 || is_cacop_0);
```

替换为：

```verilog
  assign special_fire = ds_to_es_valid_0 && (is_csr_0 || is_cacop_0 || is_accel_0);
```

### 6.5 替换 lane0 ISSUE→EX 总线打包

将整个 lane0 ISSUE→EX 总线打包赋值替换为：

```verilog
  assign ds_to_es_bus_0 = {is_accel_0,
                           store_data_late_0,
                           src_raddr2_0,
                           ds_pc_0,
                           alu_op_0,
                           ds_alu_src1_0,
                           ds_alu_src2_0,
                           ds_rkd_value_0,
                           res_from_mem_0,
                           gr_we_0,
                           mem_we_0,
                           dest_0,
                           (front_valid_0 && is_mul_0),
                           ld_byte_0,
                           ld_half_0,
                           ld_sign_ext_0,
                           st_byte_0,
                           st_half_0,
                           ds_pred_taken_0,
                           ds_pred_target_0,
                           ds_br_op_0,
                           ds_br_offs_0,
                           is_cpucfg_0,
                           is_cacop_0,
                           cacop_code_0,
                           is_csr_0,
                           is_csrxchg_0,
                           csr_num_0,
                           rj0_use_load_wakeup,
                           rkd0_use_load_wakeup
                          };
```

`ds_to_es_bus_1` 保持原样。

## 7. 修改 `myCPU/MEM_stage.v`

### 7.1 新增模块端口

在端口列表中找到：

```verilog
    output wire                         cacop_flush,
    output wire [31:0]                  cacop_flush_target,
    // 类SRAM 数据接口
```

替换为：

```verilog
    output wire                         cacop_flush,
    output wire [31:0]                  cacop_flush_target,
    output wire                         mem_stage_empty,
    // 类SRAM 数据接口
```

### 7.2 增加完整排空判定

在以下现有数据口赋值之后：

```verilog
  assign data_sram_req   = ms_has_mem_op && !ms_data_pending &&
       !ms_rdata_buf_valid &&
       (!selected_mem_we || selected_store_data_ready);
  assign data_sram_wr    = selected_mem_we;
  assign data_sram_size  = ms_mem_size;
  assign data_sram_wstrb = selected_mem_we ? ms_st_strb : 4'b0;
  assign data_sram_addr  = selected_addr;
  assign data_sram_wdata = ms_st_data;
```

紧接着插入：

```verilog
  assign mem_stage_empty =
       !ms_valid_0 &&
       !ms_valid_1 &&
       (ms_wait_kind == WAIT_NONE) &&
       !ms_data_pending &&
       !ms_response_waiting &&
       !ms_fast_response_waiting &&
       !ms_rdata_buf_valid &&
       !cacop_req_sent &&
       !data_sram_req;
```

不能把该信号简化成 `!ms_valid_0 && !ms_valid_1`。posted-store 可以先从 MEM 退休，
但 bridge 的最终 `data_ok` 还未返回，此时 `ms_data_pending` 仍然为 1；若立即切总线，旧
CPU 响应可能被加速器消费。

## 8. 修改 `myCPU/EXE_stage.v`

### 8.1 新增模块端口

在端口列表中找到：

```verilog
    input  wire                         flush,
    input  wire                         ms_allowin,
```

替换为：

```verilog
    input  wire                         flush,
    input  wire                         mem_stage_empty,
    input  wire                         accel_done,
    input  wire                         ms_allowin,
```

在端口列表中找到：

```verilog
    output wire                         csr_busy,
    output wire                         cacop_busy,
    output wire [13:0]                  csr_raddr,
```

替换为：

```verilog
    output wire                         csr_busy,
    output wire                         cacop_busy,
    output wire                         accel_start,
    output wire                         accel_flush,
    output wire [31:0]                  accel_flush_target,
    output wire [13:0]                  csr_raddr,
```

### 8.2 新增 EX 状态

在以下现有声明之后：

```verilog
  reg         es_valid_0;
  reg  [31:0] es_pc_0;
```

插入：

```verilog
  reg         es_is_accel_0;
  reg         accel_started;
  reg  [31:0] accel_resume_pc;
```

在 lane0 输入字段声明区、`wire [31:0] ds_pc_0;` 之前插入：

```verilog
  wire        ds_is_accel_0;
```

### 8.3 替换 lane0 ISSUE→EX 总线解包

将 lane0 的整个 ISSUE→EX 总线解包赋值替换为：

```verilog
  assign {ds_is_accel_0,
          ds_store_data_late_0, ds_store_data_src_0,
          ds_pc_0, ds_alu_op_0, ds_alu_src1_0,
          ds_alu_src2_0, ds_rkd_value_0,
          ds_res_from_mem_0, ds_gr_we_0, ds_mem_we_0, ds_dest_0,
          ds_is_mul_0,
          ds_ld_byte_0, ds_ld_half_0, ds_ld_sign_ext_0,
          ds_st_byte_0, ds_st_half_0,
          ds_pred_taken_0, ds_pred_target_0,
          ds_br_op_0, ds_br_offs_0,
          ds_is_cpucfg_0, ds_is_cacop_0, ds_cacop_code_0,
          ds_is_csr_0, ds_is_csrxchg_0, ds_csr_num_0,
          ds_load_wakeup_rj_0,
          ds_load_wakeup_rkd_0} = ds_to_es_bus_0;
```

### 8.4 让命令停留在 EX，并产生 start/flush

找到：

```verilog
  wire mul_packet_ready = !es_valid_0 || !mul_pending_0;
  wire es_ready_go = mul_packet_ready;
  wire es_busy     = es_valid_0 || es_valid_1;
```

替换为：

```verilog
  wire mul_packet_ready = !es_valid_0 || !mul_pending_0;
  wire accel_hold = es_valid_0 && es_is_accel_0;
  wire es_ready_go = mul_packet_ready && !accel_hold;
  wire es_busy     = es_valid_0 || es_valid_1;

  assign accel_start = accel_hold &&
       !accel_started &&
       mem_stage_empty &&
       !flush;

  assign accel_flush = accel_hold && accel_started && accel_done;
  assign accel_flush_target = accel_resume_pc;
```

`accel_hold` 使命令不产生 `es_to_ms_valid_0`，因此命令不会进入 MEM/WB。MEM 仍可继续
运行并排空更老指令。

### 8.5 新增 start 状态寄存器

在 `assign es_to_ms_bus_1` 打包结束之后、第一个 EX 有效位时序块之前插入：

```verilog
  always @(posedge clk)
  begin
    if (reset || flush)
    begin
      accel_started   <= 1'b0;
      accel_resume_pc <= 32'b0;
    end
    else if (accel_start)
    begin
      accel_started   <= 1'b1;
      accel_resume_pc <= es_pc_0 + 32'd4;
    end
  end
```

### 8.6 在 EX 控制寄存器的四条路径维护 `es_is_accel_0`

EX 的大控制寄存器时序块有 reset、flush、`promote_mul_tail` 和
`es_head_slot_open` 四条路径。分别插入以下赋值。

在 reset 分支的 `es_pc_0 <= 32'b0;` 之后插入：

```verilog
      es_is_accel_0     <= 1'b0;
```

在 flush 分支的 `es_gr_we_0 <= 1'b0;` 之前插入：

```verilog
      es_is_accel_0     <= 1'b0;
```

在 `promote_mul_tail` 分支的 `es_pc_0` 赋值之前插入：

```verilog
      es_is_accel_0     <= 1'b0;
```

在 `es_head_slot_open` 分支的 `es_pc_0 <= ds_pc_0;` 之前插入：

```verilog
      es_is_accel_0     <= ds_to_es_valid_0 && ds_is_accel_0;
```

四条路径都必须写，尤其不能让乘法尾包提升时继承上一条加速器命令的控制位。

### 8.7 替换 EX 前递类别

找到：

```verilog
  wire es_result_forwardable_0 =
       !(es_is_csr_0 || es_is_cpucfg_0 || es_is_cacop_0);
```

替换为：

```verilog
  wire es_result_forwardable_0 =
       !(es_is_csr_0 || es_is_cpucfg_0 ||
         es_is_cacop_0 || es_is_accel_0);
```

## 9. 修改 `myCPU/mycpu_top.v`

顶层修改分为五部分：声明信号、修改冲刷、修改地址翻译、连接 EX/MEM、实例化并仲裁
数据口。按本节顺序修改可以避免一个输出被两个模块同时驱动。

### 9.1 新增 CPU 内部数据口和加速器信号

在以下现有声明之后：

```verilog
  wire        load_wakeup_valid;
  wire [31:0] load_wakeup_data;
```

插入完整信号组：

```verilog
  // MEM 到顶层仲裁器的 CPU 数据口
  wire        cpu_data_req;
  wire        cpu_data_wr;
  wire [ 1:0] cpu_data_size;
  wire [ 3:0] cpu_data_wstrb;
  wire [31:0] cpu_data_vaddr;
  wire [31:0] cpu_data_paddr;
  wire [31:0] cpu_data_wdata;
  wire        cpu_data_addr_ok;
  wire        cpu_data_data_ok;
  wire [31:0] cpu_data_rdata;
  wire        cpu_data_fast_ready;
  wire        cpu_data_fast_data_ok;
  wire [31:0] cpu_data_fast_rdata;
  wire        cpu_data_store_ready;
  wire        cpu_data_addr_is_sram;

  // 加速器控制和数据口
  wire        mem_stage_empty;
  wire        accel_start;
  wire        accel_busy;
  wire        accel_done;
  wire        accel_takeover_req;
  wire        accel_takeover_grant;
  wire        accel_flush;
  wire [31:0] accel_flush_target;
  reg         accel_owns_bus;

  wire        accel_mem_req;
  wire        accel_mem_wr;
  wire [ 1:0] accel_mem_size;
  wire [ 3:0] accel_mem_wstrb;
  wire [31:0] accel_mem_addr;
  wire [31:0] accel_mem_wdata;
  wire        accel_mem_addr_ok;
  wire        accel_mem_data_ok;
  wire [31:0] accel_mem_rdata;
```

在 PC 信号声明区删除：

```verilog
  wire [31:0] data_sram_vaddr;
```

### 9.2 替换流水线冲刷优先级

找到：

```verilog
  wire        pipeline_flush = csr_flush || cacop_flush || br_taken;
  wire [31:0] pipeline_flush_target = csr_flush ? csr_flush_target :
       cacop_flush ? cacop_flush_target : br_target;
```

替换为：

```verilog
  wire        pipeline_flush = csr_flush || cacop_flush ||accel_flush || br_taken;
  wire [31:0] pipeline_flush_target =
       csr_flush   ? csr_flush_target   :
       cacop_flush ? cacop_flush_target :
       accel_flush ? accel_flush_target :
                     br_target;
```

### 9.3 修改数据地址翻译和 SRAM 属性

找到：

```verilog
  wire data_sram_addr_is_sram = ~data_sram_addr[24];
```

替换为：

```verilog
  assign cpu_data_addr_is_sram = ~cpu_data_paddr[24];
```

将整个数据地址翻译实例替换为：

```verilog
  addr_translate u_data_addr_translate(
                   .clk   (clk),
                   .resetn(resetn),
                   .ctx_update(csr_ctx_update),
                   .ctx_in(csr_trans_ctx),
                   .vaddr (cpu_data_vaddr),
                   .paddr (cpu_data_paddr)
                 );
```

`data_txn_tracker` 实例保持原样，继续连接顶层对外的 `data_sram_req`、
`data_sram_wr`、`data_sram_addr` 和 `data_sram_data_ok`。

### 9.4 替换 EX 实例

将整个 `EXE_stage u_exe` 实例替换为：

```verilog
  EXE_stage u_exe(
              .clk               (clk),
              .resetn            (resetn),
              .ds_to_es_valid_0  (ds_to_es_valid_0),
              .ds_to_es_valid_1  (ds_to_es_valid_1),
              .ds_to_es_bus_0    (ds_to_es_bus_0),
              .ds_to_es_bus_1    (ds_to_es_bus_1),
              .ds_mul_src1_0     (ds_mul_src1_0),
              .ds_mul_src2_0     (ds_mul_src2_0),
              .ds_mul_src1_1     (ds_mul_src1_1),
              .ds_mul_src2_1     (ds_mul_src2_1),
              .flush             (pipeline_flush),
              .mem_stage_empty   (mem_stage_empty),
              .accel_done        (accel_done),
              .ms_allowin        (ms_allowin),
              .load_wakeup_valid (load_wakeup_valid),
              .load_wakeup_data  (load_wakeup_data),
              .es_allowin        (es_allowin),
              .es_to_ms_valid_0  (es_to_ms_valid_0),
              .es_to_ms_valid_1  (es_to_ms_valid_1),
              .es_to_ms_bus_0    (es_to_ms_bus_0),
              .es_to_ms_bus_1    (es_to_ms_bus_1),
              .es_fwd_bus_0      (es_fwd_bus_0),
              .es_fwd_bus_1      (es_fwd_bus_1),
              .csr_busy          (es_csr_busy),
              .cacop_busy        (es_cacop_busy),
              .accel_start       (accel_start),
              .accel_flush       (accel_flush),
              .accel_flush_target(accel_flush_target),
              .csr_raddr         (csr_raddr),
              .csr_rdata         (csr_rdata)
            );
```

### 9.5 替换 MEM 实例

将整个 `MEM_stage u_mem` 实例替换为：

```verilog
  MEM_stage u_mem(
              .clk                    (clk),
              .resetn                 (resetn),
              .es_to_ms_valid_0       (es_to_ms_valid_0),
              .es_to_ms_valid_1       (es_to_ms_valid_1),
              .es_to_ms_bus_0         (es_to_ms_bus_0),
              .es_to_ms_bus_1         (es_to_ms_bus_1),
              .ws_allowin             (ws_allowin),
              .ws_to_rf_bus           (ws_to_rf_bus),
              .ms_allowin             (ms_allowin),
              .ms_to_ws_valid_0       (ms_to_ws_valid_0),
              .ms_to_ws_valid_1       (ms_to_ws_valid_1),
              .ms_to_ws_bus_0         (ms_to_ws_bus_0),
              .ms_to_ws_bus_1         (ms_to_ws_bus_1),
              .ms_fwd_bus_0           (ms_fwd_bus_0),
              .ms_fwd_bus_1           (ms_fwd_bus_1),
              .load_wakeup_valid      (load_wakeup_valid),
              .load_wakeup_data       (load_wakeup_data),
              .csr_busy               (ms_csr_busy),
              .cacop_busy             (ms_cacop_busy),
              .br_taken               (br_taken),
              .br_target              (br_target),
              .bpu_valid              (bpu_ex_valid),
              .bpu_is_bj              (bpu_ex_is_bj),
              .bpu_pc                 (bpu_ex_pc),
              .bpu_real_taken         (bpu_ex_real_taken),
              .bpu_real_target        (bpu_ex_real_target),
              .icacop_req_valid       (icacop_req_valid),
              .icacop_req_code        (icacop_req_code),
              .icacop_req_addr        (icacop_req_addr),
              .icacop_req_ready       (icacop_req_ready),
              .icacop_done            (icacop_done),
              .cacop_flush            (cacop_flush),
              .cacop_flush_target     (cacop_flush_target),
              .mem_stage_empty        (mem_stage_empty),
              .data_sram_req          (cpu_data_req),
              .data_sram_wr           (cpu_data_wr),
              .data_sram_size         (cpu_data_size),
              .data_sram_wstrb        (cpu_data_wstrb),
              .data_sram_addr         (cpu_data_vaddr),
              .data_sram_wdata        (cpu_data_wdata),
              .data_sram_addr_is_sram (cpu_data_addr_is_sram),
              .data_sram_store_ready  (cpu_data_store_ready),
              .data_sram_addr_ok      (cpu_data_addr_ok),
              .data_sram_data_ok      (cpu_data_data_ok),
              .data_sram_rdata        (cpu_data_rdata),
              .data_sram_fast_ready   (cpu_data_fast_ready),
              .data_sram_fast_data_ok (cpu_data_fast_data_ok),
              .data_sram_fast_rdata   (cpu_data_fast_rdata)
            );
```

### 9.6 实例化加速器

在数据地址翻译实例之后、`PC u_pc` 实例之前插入：

```verilog
  array_accel_engine #(
    .ARRAY_BEGIN     (32'h1c40_0000),
    .ARRAY_END       (32'h1c70_0000),
    .RESULT_ADDR     (32'h1c70_0000),
    .MAX_OUTSTANDING (16'd1)
  ) u_array_accel (
    .clk              (clk),
    .resetn           (resetn),
    .start            (accel_start),
    .busy             (accel_busy),
    .done             (accel_done),
    .takeover_req     (accel_takeover_req),
    .takeover_grant   (accel_takeover_grant),
    .mem_req          (accel_mem_req),
    .mem_wr           (accel_mem_wr),
    .mem_size         (accel_mem_size),
    .mem_wstrb        (accel_mem_wstrb),
    .mem_addr         (accel_mem_addr),
    .mem_wdata        (accel_mem_wdata),
    .mem_addr_ok      (accel_mem_addr_ok),
    .mem_data_ok      (accel_mem_data_ok),
    .mem_rdata        (accel_mem_rdata)
  );
```

### 9.7 插入总线所有权状态机和完整仲裁

紧接加速器实例之后插入：

```verilog
  always @(posedge clk)
  begin
    if (!resetn)
      accel_owns_bus <= 1'b0;
    else if (!accel_owns_bus)
    begin
      if (accel_takeover_req && mem_stage_empty && !cpu_data_req)
        accel_owns_bus <= 1'b1;
    end
    else if (!accel_takeover_req)
      accel_owns_bus <= 1'b0;
  end

  assign accel_takeover_grant = accel_owns_bus;

  assign data_sram_req = accel_owns_bus ?
       accel_mem_req : cpu_data_req;
  assign data_sram_wr = accel_owns_bus ?
       accel_mem_wr : cpu_data_wr;
  assign data_sram_size = accel_owns_bus ?
       accel_mem_size : cpu_data_size;
  assign data_sram_wstrb = accel_owns_bus ?
       accel_mem_wstrb : cpu_data_wstrb;
  assign data_sram_addr = accel_owns_bus ?
       accel_mem_addr : cpu_data_paddr;
  assign data_sram_wdata = accel_owns_bus ?
       accel_mem_wdata : cpu_data_wdata;

  assign cpu_data_addr_ok =
       !accel_owns_bus && data_sram_addr_ok;
  assign cpu_data_data_ok =
       !accel_owns_bus && data_sram_data_ok;
  assign cpu_data_rdata = data_sram_rdata;
  assign cpu_data_fast_ready =
       !accel_owns_bus && data_sram_fast_ready;
  assign cpu_data_fast_data_ok =
       !accel_owns_bus && data_sram_fast_data_ok;
  assign cpu_data_fast_rdata = data_sram_fast_rdata;
  assign cpu_data_store_ready =
       !accel_owns_bus && data_sram_store_ready;

  assign accel_mem_addr_ok =
       accel_owns_bus && data_sram_addr_ok;
  assign accel_mem_data_ok =
       accel_owns_bus && data_sram_data_ok;
  assign accel_mem_rdata = data_sram_rdata;
```

请求、普通响应、fast 响应和 store ready 必须全部按所有者隔离，不能只 mux 请求。

## 10. 修改 `asm/programs/user_sample.s`

将文件完整替换为：

```asm
    .global _start
    .section .text

_start:
    .word 0x00200000
    or    $r4, $r0, $r0
    jr    $r1
```

`or $r4,$r0,$r0` 保留统一用户程序模板的返回值约定。加速器完成冲刷先回到这条指令，
再由 `jr $r1` 返回 monitor。

## 11. 编译和分级验证

先确认 Verilator：

```bash
verilator --version
```

必须输出 `Verilator 5.050 2026-07-01`。然后使用仓库 testbench 提供的乘法器仿真模型
完成 RTL 展开和编译：

```bash
make -C asm/programs verilate
```

不要只对 `mycpu_top` 执行一个不带 testbench 的 `verilator --lint-only myCPU/*.v`；
综合使用的 `mult_gen_0` 是 Vivado IP，而本地 Verilator 所需的同名行为模型定义在
`asm/sim/asm_monitor_tb.v` 中。上面的 Makefile 目标会自动加入该模型和正确选项。

常见 lint 结果的含义：

- `WIDTHEXPAND` 且出现 `267`、`266`：`inst_buffer.v` 的 g5 仍是 41 bit，或仍有
  `[265:225]` 切片没有改为 `[266:225]`；
- 其他 `WIDTH`：总线宽度或打包/解包字段漏改；
- `MULTIDRIVEN`：`data_sram_addr` 仍被地址翻译和仲裁器同时驱动；
- `PINMISSING`：EX/MEM 新端口没有在顶层连接；
- `UNDRIVEN`：CPU 或加速器响应信号漏接；
- `MULTITOP`：测试模块或第二套同名加速器被放入 `myCPU/`。

生成 supervisor 和输入：

```bash
cd ~/Mycpu
source .venv/bin/activate
export GCCPREFIX=loongarch32r-linux-gnusf-
MYCPU_ROOT=$(pwd)
cd supervisor
PYTHON="$MYCPU_ROOT/.venv/bin/python" ./build_all.sh
cd "$MYCPU_ROOT"
```

运行 2025 完整 3 MiB 输入：

```bash
make -C asm/programs \
  DATA=../../supervisor/build/utility/stream/stream_input.bin \
  DATA_ADDR=0x80400000 \
  EXPECT_VALUE=1 \
  EXPECT_ADDR=0x80700000 \
  WATCH_ADDR=0x80700000 \
  WATCH_WORDS=1 \
  run
```

需要波形时在同一命令中增加 `WAVE=1`。波形必须按顺序满足：

```text
inst == 0x00200000，is_accel_0 == 1
ds_to_es_valid_0 == 1，ds_to_es_valid_1 == 0
accel_start 只高一个周期，且该拍 mem_stage_empty == 1
accel_takeover_req == 1，随后 accel_owns_bus == 1
第一次读地址为 0x1c400000
最后一次读地址为 0x1c6ffffc
唯一一次写地址为 0x1c700000
结果写收到 data_sram_data_ok 后 accel_done 才为 1
accel_flush == 1，accel_flush_target 等于触发 PC+4
PC 先执行 or $r4,$r0,$r0，再执行 jr $r1 返回 monitor
```

同时检查以下不变量：

- IBuffer 中 `fifo_front_0[266]`、`front_bus_0_r[266]`、
  `dec_bus_0[169]` 和 `is_accel_0` 必须在命令到达对应阶段时依次为 1；
- `accel_mem_req && !accel_mem_addr_ok` 时请求字段保持稳定；
- `accel_owns_bus == 1` 时所有 CPU 的 `addr_ok/data_ok/fast_ready/fast_data_ok/store_ready`
  均为 0；
- `accel_owns_bus == 0` 时 `accel_mem_addr_ok` 和 `accel_mem_data_ok` 均为 0；
- 读请求数为 786432，写请求数为 1；
- `accel_start`、`accel_done` 和 `accel_flush` 都只能持续一个周期。

最后运行规定的四程序回归：

```bash
make -f test/supervisor_perf.mk suite
```

必须确认 STREAM、MATRIX、CRYPTONIGHT 和 MIXED 全部 PASS。不要把 SIMPLE、Fibonacci、
官方 trace 或额外 CPU 自检混入本项目验收结果。


## 13. 常见错误

- 命令译码后又变回普通空操作：`inst_buffer.v` 的 g5 没有扩展到 42 bit，bit 266 在
  front payload 分组时丢失；
- `accel_start` 连续为 1：`accel_started` 没有置位或复位；
- 命令进入 lane1：`is_accel_1` 或 `special_1` 漏接；
- 命令与 lane1 同发：`special_0` 漏加 `is_accel_0`；
- 命令进入 MEM：`es_ready_go` 没有加入 `!accel_hold`；
- 第一个 word 错误：总线直接 grant，或旧 CPU `data_ok` 没有隔离；
- CPU 在加速期间误完成访存：只 mux 请求，没有隔离全部响应和 ready；
- 结果仍为旧值：结果写请求尚未收到 `data_ok` 就产生 `done`；
- 最终计数少 1：`first_valid` 没把计数初始化为 1；
- 漏读最后一个 word：误把 `ARRAY_END` 当成最后元素地址；
- 顶层多驱动：地址翻译仍直接驱动 `data_sram_addr`；
- 普通程序永久阻塞：完成时没有用 `accel_flush` 清除 `special_block`；
- reset 后偶发启动：`es_is_accel_0`、`accel_started` 或 `accel_owns_bus` 没复位；
- 增大 `MAX_OUTSTANDING` 后失效：下游不支持多笔未完成请求或不能保证顺序返回。
