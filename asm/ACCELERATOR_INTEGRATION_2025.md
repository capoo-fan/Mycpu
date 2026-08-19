# 将硬件加速器接入 CPU：以 2025 年个人赛题为例

本文面向当前仓库的 LA32R 双发射流水线，说明如何把“顺序遍历数组并归约”的硬件
加速器接到 CPU。示例采用 [2025 年题面](asm/questions/2025.png)：统计数组第一个元素
在整个数组中出现的次数。

本文只修改设计方法与接线说明，不声称当前 `myCPU/*.v` 已经完成加速器整机接入。
仓库已有可复用的加速器模块和软件基线，文末的 cycles 分为“CPU 软件实测”和
“加速器核接实际 SRAM 桥实测”；完成整机接线后，还应按本文方法补测端到端数据。

## 1. 题目与地址空间

2025 年题目的要求是：

- 数组元素为 32 位无符号整数；
- 数组起始地址为 `0x8040_0000`；
- 数组长度为 `0x0030_0000` 字节，即 `786,432` 个 word；
- 比较目标为 `A[0]`，数据随机生成，必须完整遍历；
- 结果写到 `0x8070_0000`，结果宽度为 32 bit。

比赛程序看到的是虚地址，当前 SoC 使用的对应关系是：

| CPU 地址 | 物理地址 | 存储体 |
| --- | --- | --- |
| `0x8000_0000..0x803f_ffff` | `0x1c00_0000..0x1c3f_ffff` | BaseRAM |
| `0x8040_0000..0x807f_ffff` | `0x1c40_0000..0x1c7f_ffff` | ExtRAM |

如果加速器接在 `addr_translate` 之后、与 CPU 的类 SRAM 数据口共享总线，加速器参数应
使用物理地址：

```verilog
.ARRAY_BEGIN (32'h1c40_0000),
.ARRAY_END   (32'h1c70_0000),
.RESULT_ADDR (32'h1c70_0000)
```

不要一部分地址使用 `0x804x_xxxx`、另一部分使用 `0x1c4x_xxxx`。当前 SRAM bridge
碰巧只使用部分地址位，混用可能暂时通过仿真，但会模糊接口语义并给后续 Cache/MMU
接入留下问题。

## 2. 软件基线

仓库中有三份相关文件：

- [`2025.c`](asm/answer/2025/2025.c)：C 参考实现；
- [`2025.asm`](asm/answer/2025/2025.asm)：GCC `-O3` 生成的 8 路展开版本；
- [`2025.s`](asm/answer/2025/2025.s)：手写 4 路展开版本。

基线算法可概括为：

```c
key = A[0];
count = 0;
for (i = 0; i < 786432; i++)
    count += (A[i] == key);
MEM32[0x80700000] = count;
```

当前性能最好的是 `2025.asm`。它每轮读取 8 个 word，使用 4 个独立计数器减少累加
相关，循环 `0x300000 / 32 = 98,304` 次。动态指令数为：

```text
8 + 34 × 98,304 + 5 = 3,342,349 instructions
```

使用仓库的确定性 3 MiB STREAM 数据进行复测：

```bash
cd ~/Mycpu
source .venv/bin/activate
export GCCPREFIX=/opt/loongarch-env/loongarch32r-toolchain/bin/loongarch32r-linux-gnusf-

make -C asm \
  PROGRAM=answer/2025/2025.asm \
  ENTRY=count_first \
  DATA=../supervisor/build/utility/stream/stream_input.bin \
  DATA_ADDR=0x80400000 \
  EXPECT_VALUE=1 \
  EXPECT_ADDR=0x80700000 \
  WATCH_ADDR=0x80700000 \
  WATCH_WORDS=1 \
  run
```

2026-08-18 在当前 `asm` 分支、Verilator 5.050 上的结果是：

```text
CHECK word PASS addr=80700000 value=00000001
USER_PERF scope=PROGRAM_ONLY cycles=4423959 instructions=3342349
IPC=0.755511 CPI=1.323608
```

这里使用 `USER_PERF`，因为它只统计题目程序从入口到 `jr $r1` 退休的区间；
`SIM_PERF` 还包含 monitor 接收 `G` 命令、保存现场和返回后的串口收尾，不适合比较
算法本体。

## 3. 加速器结构

这道题属于 Reduction：读取整个数组，维护少量状态，最后只写一个结果。仓库已经提供：

- [`array_accel_engine.v`](asm/Template/Reduction/array_accel_engine.v)：固定的地址遍历、
  类 SRAM 握手、结果写回状态机；
- [`accelerator_logic.v`](asm/Template/Reduction/accelerator_logic.v)：比赛现场需要替换的
  算法逻辑；
- [`Accelerator.v`](asm/answer/2025/Accelerator.v)：将遍历和 2025 算法写在一起的
  单文件参考实现。

建议正式接入时使用“固定 engine + 独立 logic”，便于下一年只替换算法。不要同时编译
Reduction、Map 两套模板，因为两边都有同名 `accelerator_logic` 模块。

用于综合的源文件应放入 `myCPU/`（例如 `myCPU/array_accel_engine.v` 和
`myCPU/accelerator_logic.v`），或显式加入仿真与 Vivado 的 RTL 文件列表。只修改
`asm/Template/` 不会自动把模块实例带进 CPU。当前项目会同步 `myCPU/*.v` 到 Vivado
仓库，因此比赛现场把最终版本放在 `myCPU/` 最不容易漏文件。

数据流如下：

```text
自定义触发指令
      │ start
      ▼
EX 长延迟占位 ── busy/done ──► 完成后 flush 到 PC+4
      │
      │ takeover_req/grant
      ▼
数据口仲裁器 ──► array_accel_engine ──► accelerator_logic
      │                 │                        │
      │                 └── 地址递增             └── key/count
      ▼
thinpad_sram_uart_bridge ──► ExtRAM
```

Reduction engine 的关键接口为：

| 信号 | 方向 | 含义 |
| --- | --- | --- |
| `start` | CPU → 加速器 | 一拍启动脉冲 |
| `busy` | 加速器 → CPU | 从接受启动到结果写回完成一直为 1 |
| `done` | 加速器 → CPU | 一拍完成脉冲 |
| `takeover_req` | 加速器 → 仲裁器 | 请求独占数据口 |
| `takeover_grant` | 仲裁器 → 加速器 | CPU 旧事务已排空且数据口已切换 |
| `mem_req/addr_ok` | 主设备握手 | 请求被下游接受 |
| `mem_data_ok` | 下游 → 主设备 | 读数据返回或写事务完成 |

必须遵守两条规则：

1. `mem_req` 在 `mem_addr_ok` 前保持有效，地址和写数据保持稳定；
2. 一次请求被接受后，等待对应 `mem_data_ok`，不能把旧 CPU 响应误当成加速器响应。

## 4. 编写 2025 算法逻辑

`array_accel_engine` 已经区分第一个元素和后续元素。把 Reduction 模板中的算法区改成：

```verilog
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
        result_reg <= 32'd1;       // A[0] 一定等于自身
    end
    else if (data_valid) begin
        if (data == key_reg)
            result_reg <= result_reg + 32'd1;
    end
end

assign result = result_reg;
```

`ARRAY_END` 是开区间。处理地址 `0x1c6f_fffc` 返回的数据后才写结果，不能漏掉最后一个
word。计数器保留 32 bit；虽然本题最大计数只需 20 bit，结果协议仍要求写 4 字节。

## 5. 选择触发指令

当前 CPU 没有实现 `div.w`，可只保留一个精确编码作为加速器命令：

```asm
    div.w  $r0, $r0, $r0
```

对应机器码是：

```asm
    .word 0x00200000
```

建议译码条件包含完整操作数，而不是劫持所有 `div.w`，并把它加入 `inst_known`：

```verilog
wire inst_accel = (inst == 32'h0020_0000);
```

这样以后实现真正的除法指令时，只有 `$r0,$r0,$r0` 这一种编码保留为命令。该命令：

- 不读取通用寄存器；
- 不写通用寄存器；
- 不直接发起普通 load/store；
- 只能进入 lane 0；
- 不能与 lane 1 指令同发；
- 属于串行化长延迟指令。

加速后的题目程序只需要：

```asm
    .global _start
    .text
_start:
    .word   0x00200000       # 启动加速器并等待完成
    jr      $r1
```

题目要求结果在固定内存地址，不要求命令向寄存器返回结果，因此无需给写回总线增加一条
长数据线。

## 6. 流水线接入

### 6.1 `inst_decoder.v`

在 [`inst_decoder.v`](myCPU/inst_decoder.v) 增加 `inst_accel`，并将它放入译码总线。
同时保证：

```text
gr_we=0, mem_we=0, res_from_mem=0,
need_rj=0, need_rkd=0, is_bj=0
```

需要相应增加 `DS_DEC_BUS_WD` 和 `DS_TO_ES_BUS_WD`。每一级打包和解包的字段顺序必须
同步修改；最常见的接入错误就是只改一端，导致后续控制位整体错位。

### 6.2 `ISSUE_stage.v`

把 `is_accel_0` 加入 `special_0`，把 `is_accel_1` 加入 `special_1`，使触发指令只从
lane 0 单发。触发指令发射时置串行化 scoreboard，完成冲刷前禁止年轻指令继续进入 EX：

```verilog
wire special_0 = is_csr_0 || is_cacop_0 || is_cpucfg_0 || is_accel_0;
wire special_1 = is_csr_1 || is_cacop_1 || is_cpucfg_1 || is_accel_1;

assign special_fire = ds_to_es_valid_0 &&
                      (is_csr_0 || is_cacop_0 || is_accel_0);
```

当前 `special_block` 在 pipeline flush 时清除，所以完成时必须产生一次加速器 flush。
不要仅用 `busy` 直接反压 WB；项目要求 WB 保持每拍可提交两条普通写回。

### 6.3 `EXE_stage.v`

触发指令进入 EX 后原地等待，不让它进入 MEM/WB。为避免错误路径上的触发指令产生
不可撤销的内存写入，必须先等所有更老指令离开 MEM，再产生一次 `accel_start`，并保存
恢复地址 `es_pc_0 + 4`：

```verilog
wire accel_hold = es_valid_0 && es_is_accel_0;
wire accel_start = accel_hold && !accel_started &&
                   mem_stage_empty && !pipeline_flush;

wire es_ready_go = mul_packet_ready && !accel_hold;
```

`mem_stage_empty` 应由 MEM 显式导出，覆盖普通 ALU、分支和访存包，不能只检查
`data_sram_req`。否则一个更老的误预测分支可能在同一拍冲刷触发指令，而错误路径加速器
已经开始修改 ExtRAM。

`accel_started` 在触发指令离开、reset 或 flush 时清零。不能在 EX 停留的每一拍重复拉高
`start`。加速器 `done` 到达后，由 `mycpu_top` 产生：

```text
accel_flush = 1
accel_flush_target = saved_accel_pc + 4
```

把它加入现有 flush 优先级，并保证 reset、CSR/异常冲刷的优先级高于普通分支和加速器
完成事件。完成冲刷会杀掉仍停在 EX 的命令、清空年轻指令，并从 `PC+4` 继续执行。

这种做法只让 `start/done/PC` 走局部控制路径，不需要把 `busy` 扇出到 WB、debug 或整条
写回数据通路。

## 7. 数据口仲裁

推荐在 [`mycpu_top.v`](myCPU/mycpu_top.v) 的地址翻译之后、模块对外类 SRAM 数据口
之前加入二选一仲裁器。先把 MEM 原本直接驱动的信号改名为 `cpu_data_*`，加速器使用
`accel_data_*`，对外端口根据 `accel_owns_bus` 选择。

核心结构如下，示例省略位宽重复项：

```verilog
assign data_sram_req   = accel_owns_bus ? accel_mem_req   : cpu_data_req;
assign data_sram_wr    = accel_owns_bus ? accel_mem_wr    : cpu_data_wr;
assign data_sram_size  = accel_owns_bus ? 2'b10           : cpu_data_size;
assign data_sram_wstrb = accel_owns_bus ? accel_mem_wstrb : cpu_data_wstrb;
assign data_sram_addr  = accel_owns_bus ? accel_mem_addr  : cpu_data_paddr;
assign data_sram_wdata = accel_owns_bus ? accel_mem_wdata : cpu_data_wdata;

assign cpu_data_addr_ok  = !accel_owns_bus && data_sram_addr_ok;
assign cpu_data_data_ok  = !accel_owns_bus && data_sram_data_ok;
assign cpu_data_rdata    = data_sram_rdata;
assign cpu_fast_ready    = !accel_owns_bus && data_sram_fast_ready;
assign cpu_fast_data_ok  = !accel_owns_bus && data_sram_fast_data_ok;

assign accel_mem_addr_ok =  accel_owns_bus && data_sram_addr_ok;
assign accel_mem_data_ok =  accel_owns_bus && data_sram_data_ok;
assign accel_mem_rdata   = data_sram_rdata;
```

`takeover_grant` 不能简单连接成 `takeover_req`。触发指令在 EX 时，前面更老的 load/store
可能仍在 MEM 或等待 `data_ok`。应由 `MEM_stage` 显式导出 `mem_stage_empty`；它既用于
禁止错误路径启动，也用于总线 grant，至少满足：

```text
MEM 中没有任何有效指令包
&& 没有已接受但未返回的 load/MMIO 事务
&& 当前没有 CPU data request
```

仲裁状态机为：

```text
CPU_OWNS
  └─ takeover_req && mem_stage_empty ─► ACCEL_OWNS

ACCEL_OWNS
  └─ !takeover_req ────────────────► CPU_OWNS
```

`thinpad_sram_uart_bridge` 中的 posted-store 槽会在 CPU store 退休后继续排空。即使 MEM
已经 idle，加速器的首个请求也必须等 bridge 真正给出 `addr_ok`；不要假定 grant 后
下一拍必然接受请求。

如果以后加入 DCache，还要在 grant 前对加速区间做 writeback + invalidate，并在完成后
再次 invalidate，或者把加速器接入一致性端口。当前分支的数据路径没有 DCache，题目区间
可以直接通过类 SRAM 数据口访问。

## 8. cycles 对比

使用相同的 3 MiB 确定性输入，且第一个 word 在数组中只出现一次：

| 版本 | 统计边界 | cycles | 结果 |
| --- | --- | ---: | --- |
| CPU 软件 `2025.asm` | `USER_PERF`，入口到 `jr` 退休 | 4,423,959 | PASS，count=1 |
| `Accelerator.v` + 当前 SRAM bridge | `start` 到 `done` | 3,145,731 | PASS，count=1 |

第二行不是按状态数推算：它由 Verilator 5.050 编译 `Accelerator.v`、当前
`thinpad_sram_uart_bridge.v` 和独立 testbench，载入与软件相同的 `input.mif` 后计数得到。
独立测试中没有 CPU 旧事务，因此 grant 可在请求接管后立即给出；所有 ExtRAM
`addr_ok/data_ok` 时序仍来自实际 bridge。

相对变化：

```text
减少 cycles = 4,423,959 - 3,145,731 = 1,278,228
cycles 降幅 = 1,278,228 / 4,423,959 = 28.89%
加速比       = 4,423,959 / 3,145,731 = 1.406×
```

加速比没有达到数量级提升，原因不是比较/计数逻辑慢，而是当前实现一次只允许一个
outstanding read。`thinpad_sram_uart_bridge` 的 ExtRAM 读经过接受、两个 ACCESS 状态和
DONE，完整扫描仍接近每个 word 4 cycles。硬件消除了约 334 万条动态指令以及循环分支，
但没有提高 SRAM 每拍返回的 word 数。

这两行使用了略有不同的边界：软件值是完整用户程序，硬件值是加速器核本体。完成整机
接入后，应以触发程序的 `USER_PERF` 作为最终“加速后”数字；它会额外包含触发指令、
总线排空、完成 flush 和 `jr` 的少量周期。本文不把尚未实测的整机数字写成结论。

若要继续优化，应优先改进连续读吞吐，而不是复制更多比较器：

1. 让 SRAM 读控制器支持连续地址流水；
2. 将“地址请求”和“返回比较”解耦；
3. 在接口允许时支持多个 outstanding 请求；
4. 最后再考虑每拍处理多个 word。

## 9. 完成整机接入后的验证

### 9.1 题目程序

把两条指令的触发程序保存为 `asm/answer/2025/2025_accel.s` 后运行：

```bash
make -C asm \
  PROGRAM=answer/2025/2025_accel.s \
  ENTRY=_start \
  DATA=../supervisor/build/utility/stream/stream_input.bin \
  DATA_ADDR=0x80400000 \
  EXPECT_VALUE=1 \
  EXPECT_ADDR=0x80700000 \
  WATCH_ADDR=0x80700000 \
  WATCH_WORDS=1 \
  run
```

至少检查以下事件顺序：

```text
触发指令 lane0 单发
→ accel_start 仅一拍
→ 旧 CPU 访存完成
→ takeover_grant
→ 读取 0x1c400000
→ 最后读取 0x1c6ffffc
→ 写 0x1c700000
→ done 仅一拍
→ flush 到触发 PC+4
→ jr $r1 返回 monitor
```

长数组不要默认开全程波形。先缩小 engine 参数和输入范围验证状态机，再跑完整 3 MiB
数据；完整测试以 `CHECK ... PASS` 和最终 `PASS asm monitor test` 为准。

### 9.2 CPU 回归

加速器不能破坏普通程序。按仓库规定只运行四个 supervisor 性能程序：

```bash
make -f test/supervisor_perf.mk suite
```

必须确认 STREAM、MATRIX、CryptoNight 和 MIXED 全部 PASS。不要把 SIMPLE、官方 trace
或额外 CPU 自检混入本项目验收结果。

### 9.3 综合与时序

修改 `myCPU/*.v` 后必须同步到 Vivado 工程，备份上一份 routed timing report，然后按
仓库规定重新创建工程和 implementation：

```bash
vivado -mode batch -source ~/thinpad_top/run_vivado/flow/create_vivado_project.tcl

vivado -mode batch \
  -log ~/thinpad_top/run_vivado/implement.log \
  -journal ~/thinpad_top/run_vivado/implement.jou \
  -source ~/thinpad_top/run_vivado/flow/implement_design.tcl
```

读取新生成的 `thinpad_top_timing_summary_routed.rpt`，确认 WNS ≥ 0。不得修改
`implement_design.tcl`，也不得用 false path、multicycle path 等不符合真实语义的约束
隐藏加速器关键路径。

重点观察：

- `accel_owns_bus` 到数据口 mux 是否成为高扇出关键路径；
- `mem_rdata == key_reg` 与 `result_reg + 1` 是否满足时序；
- `busy/done` 是否被不必要地拉到 IF、WB 和 debug；
- 新增状态机、地址计数器和比较器的 LUT/FF 开销；
- 加速器加入后四程序的频率、cycles 和功能结果是否保持正常。

## 10. 常见错误

- **start 一直为 1**：EX 被暂停后每拍重新启动，加速器永远无法结束。必须生成单拍脉冲。
- **直接 grant**：旧 load 的 `data_ok` 被加速器消费，首元素 key 错误。
- **只 mux 请求、不 mux 响应**：CPU 和加速器同时看到同一响应，状态机失步。
- **触发指令双发**：lane1 的年轻指令可能在总线接管前产生副作用。
- **结果写回后立即释放但不等 data_ok**：monitor 可能先读到旧值。
- **地址层级混用**：虚地址参数接在物理口上，换桥接器或加 Cache 后访问错误。
- **漏处理最后一个 word**：把 `ARRAY_END` 当成最后元素地址而不是开区间。
- **恢复 debug 长线**：加速器完成状态不应通过 `debug_wb_*` 输出，也不能让 WB 因 debug
  反压。

## 11. 接入检查表

- [ ] 只选择 Reduction 或 Map 中的一套 engine/logic；
- [ ] 2025 logic 正确保存 `A[0]`，初始 count 为 1；
- [ ] 自定义命令完整译码，且无寄存器/内存副作用；
- [ ] 命令只在 lane0 单发；
- [ ] `start`、`done` 都是一拍；
- [ ] EX 等待期间，旧 MEM 事务仍能继续完成；
- [ ] start 和 grant 都只在 `mem_stage_empty` 后产生；
- [ ] 请求和响应均按总线所有者路由；
- [ ] 写结果收到 `data_ok` 后才完成；
- [ ] 完成 flush 精确跳到触发指令 `PC+4`；
- [ ] 2025 题目完整输入结果正确；
- [ ] 四程序 supervisor 回归全部通过；
- [ ] Vivado implementation 成功且 WNS ≥ 0。
