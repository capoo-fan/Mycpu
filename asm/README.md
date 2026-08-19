# 龙芯杯 LA32R 汇编题 CPU 仿真框架

本目录用于把龙芯杯决赛汇编题答案编译后，通过 supervisor monitor 的真实串口协议
装入当前 `myCPU/*.v`，在 Verilator 中运行、检查结果并统计周期和退休指令数。框架不修改
CPU，也不恢复 `debug_wb_*` 长线；指令计数由 testbench 观察 MEM→WB 有效握手完成。

仿真流程如下：

1. 从 supervisor BaseRAM 镜像复位并启动 CPU；
2. 等待 `MONITOR for Loongarch32 - initialized.` 串口欢迎词；
3. 用 monitor `A` 命令把待测程序写入 SRAM；
4. 发送 `G` 和 32-bit 小端入口地址；
5. 执行汇编，程序用 `jr $r1` 返回 monitor；
6. 收到 monitor 的 `0x07` 停止标记后输出性能数据并校验结果。

## 1. 环境准备

在仓库根目录执行：

```bash
cd ~/Mycpu
source .venv/bin/activate
export GCCPREFIX=/opt/loongarch-env/loongarch32r-toolchain/bin/loongarch32r-linux-gnusf-
verilator --version
```

Verilator 必须输出：

```text
Verilator 5.050 2026-07-01
```

Makefile 会检查该版本。首次运行若缺少
`supervisor/build/kernel/auto/axi_ram.mif`，会自动调用 `supervisor/build_all.sh`。

## 2. 最快上手

仓库自带一个 5 条指令的示例：

```bash
make -C asm \
  PROGRAM=programs/hello.s \
  EXPECT_VALUE=0x12345678 \
  EXPECT_ADDR=0x80700000 \
  WATCH_ADDR=0x80700000 \
  WATCH_WORDS=1 \
  run
```

成功时关键输出类似：

```text
CHECK word PASS addr=80700000 value=12345678
RESULT entry=80100000 program_bytes=20
========== PERFORMANCE SUMMARY ==========
SIM_PERF scope=G_TO_07 cycles=1579 instructions=250 IPC=0.158328 CPI=6.316000
USER_PERF scope=PROGRAM_ONLY cycles=56 instructions=5 IPC=0.089286 CPI=11.200000
=========================================
MEM_WRITES count=1 logged=1
WRITE addr=1c700000 data=12345678
PASS asm monitor test
```

只要出现 `CHECK ... PASS` 和最后一行 `PASS asm monitor test`，程序返回和结果检查都已
通过。没有配置 `EXPECT`/`EXPECT_VALUE` 时，`PASS` 只说明程序正常返回，不代表算法结果
正确；正式测试应始终配置一种结果断言。

## 3. 汇编程序约定

支持 `.s`、`.S` 和 `.asm`。默认入口符号是 `_start`，默认链接/装载地址是比赛常用的
`0x80100000`：

```asm
    .text
    .globl _start
_start:
    # ...题目代码...
    jr      $r1
```

如果编译器生成的入口名是 `count_first`、`sqrt` 等，用 `ENTRY` 指定：

```bash
make -C asm PROGRAM=answer/2025/2025.asm ENTRY=count_first run
```

框架从 ELF 符号表解析实际入口，不假设入口一定等于 `.text` 首地址。程序必须最终通过
`jr $r1`（或等价的、从程序镜像跳回 monitor 的控制转移）结束。测试框架把首次从程序
镜像跳到镜像外的已退休分支视为用户程序完成；不要在结束前跳到镜像外的辅助函数。

LA32R 的 `lu12i.w` 立即数是有符号 20 bit。写 `0x80400`/`0x80700` 可能被汇编器报告
`Immediate overflow`，可使用工具链生成形式，例如：

```asm
    lu12i.w $r12, -2143289344>>12   # 0x80400000
    lu12i.w $r15, -2140143616>>12   # 0x80700000
```

每次 `run` 都会重新链接汇编，因此改变 `ENTRY` 或 `PROGRAM_ADDR` 不会误用旧 ELF。
反汇编保存在 `.build/<程序名>/<程序名>.disasm`，提交前应检查入口和热循环。

## 4. 装载真题输入

### 4.1 连续大块数据

`DATA` 支持小端原始 `.bin`，或每行一个 32-bit 二进制字的 `.mif`。`.bin` 会自动转换。
`DATA_ADDR` 是第一个字在 CPU 地址空间中的地址：

```bash
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

这个命令用 3 MiB 的确定性数据跑 `questions/2025.png` 对应的现有汇编答案。该测试数据
的第一个 32-bit 字只出现一次，所以期望计数是 1。它用于验证框架和 CPU，不是官方
决赛隐藏数据。

在当前 `myCPU` 上的实测结果为：

```text
SIM_PERF scope=G_TO_07 cycles=4425568 instructions=3342594 IPC=0.755292 CPI=1.323992
USER_PERF scope=PROGRAM_ONLY cycles=4423959 instructions=3342349 IPC=0.755511 CPI=1.323608
```

反汇编中初始化 8 条、循环体 34 条、循环 `3 MiB / 32 B = 98,304` 次、收尾 5 条，
动态用户指令数恰好为 `8 + 34 × 98,304 + 5 = 3,342,349`，与仿真退休计数一致。

单个 `DATA` 区间不能跨越一片 4 MiB SRAM 边界。支持以下两种等价地址写法：

| CPU 虚地址 | SRAM 物理地址 | 存储体 |
| --- | --- | --- |
| `0x80000000..0x803fffff` | `0x1c000000..0x1c3fffff` | BaseRAM |
| `0x80400000..0x807fffff` | `0x1c400000..0x1c7fffff` | ExtRAM |

### 4.2 稀疏输入和覆盖值

当输入位于多个不连续地址时，使用 `INIT=<文本文件>`。每个有效行是“32-bit 字对齐地址
32-bit 值”，均按十六进制解释；空行、注释行和行尾注释会忽略：

```text
# dividend / divisor
80400000 00000064
80700000 00000007
```

运行示例：

```bash
make -C asm PROGRAM=programs/hello.s INIT=programs/sparse_example.init run
```

若同时指定 `DATA` 和 `INIT`，先装入连续 `DATA`，再用 `INIT` 覆盖稀疏地址，最后才通过
monitor `A` 命令装入程序。

## 5. 自动检查结果

单个结果字使用：

```bash
EXPECT_VALUE=0x12345678 EXPECT_ADDR=0x80700000
```

连续结果区使用 `EXPECT=<结果.bin|结果.mif>` 和起始地址：

```bash
make -C asm \
  PROGRAM=programs/map.s \
  DATA=cases/map_input.bin DATA_ADDR=0x80400000 \
  EXPECT=cases/map_expected.bin EXPECT_ADDR=0x80500000 \
  run
```

`EXPECT=.bin` 同样按小端 32-bit 字自动转换。比较失败时最多打印前 16 个不一致地址，
随后以非零状态结束。`EXPECT` 与 `EXPECT_VALUE` 互斥。

`WATCH_ADDR`/`WATCH_WORDS` 只负责打印最终内存窗口，便于人工观察，不替代自动断言。
`WRITE` 最多记录用户程序阶段最先发生的 256 次 SRAM 写事务；`MEM_WRITES count` 始终
给出完整写事务数。

## 6. 性能统计的严格定义

框架同时报告两个区间，以免把“G 命令总耗时”和“汇编本体效率”混为一谈。

### `SIM_PERF scope=G_TO_07`

这是题目要求的主统计口径：

- 起点：testbench 在 UART 接收接口上呈现 `G` (`0x47`) 后的第一个时钟上升沿；
- 终点：monitor 在 UART 发送接口上呈现结束标记 `0x07` 的时钟上升沿（包含该拍）；
- `cycles`：该闭区间经历的 CPU 时钟拍数；
- `instr`：该区间进入 WB 的所有有效指令数，两路同拍退休时加 2。

因此它包含 `G` 后四字节入口地址的接收、monitor 启动/保存现场、用户汇编以及返回后的
monitor 收尾，完整回答“从发出 G 命令到完成一共多少 cycle / 指令”。testbench 的
UART 使用 SoC 内部 ready/clear 握手，不模拟物理串口波特率，所以这里统计的是 CPU/SoC
协议执行周期，不是串口线上的真实传输时间。

### `USER_PERF scope=PROGRAM_ONLY`

- 起点：`pc_out` 首次等于 ELF 的 `ENTRY` 后的第一个完整时钟周期；
- 终点：跳回 monitor 的用户返回指令进入 WB 的周期（包含该拍）；
- `cycles`：包括流水线填充、Cache miss、数据 SRAM 等待和分支恢复；
- `instr`：只统计 PC 位于当前程序镜像内的 `ms_to_ws_valid_0/1`，不混入 monitor 指令。

优化汇编时主要比较 `USER_PERF`；复现题目要求的端到端口径时使用
`SIM_PERF`。`IPC=instructions/cycles`，`CPI=cycles/instructions`。两行采用固定的
`key=value` 格式，便于脚本直接提取 cycles、instructions 和 IPC。

## 7. 全部 Make 变量

| 变量 | 默认值 | 作用 |
| --- | --- | --- |
| `PROGRAM` | `programs/hello.s` | 待测 `.s`/`.S`/`.asm` |
| `ENTRY` | `_start` | ELF 入口符号 |
| `PROGRAM_ADDR` | `0x80100000` | 链接和 monitor 装载基址 |
| `DATA` | 空 | 连续输入 `.bin`/`.mif` |
| `DATA_ADDR` | `0x80400000` | 连续输入起始地址 |
| `INIT` | 空 | 稀疏“地址 值”初始化文件 |
| `EXPECT` | 空 | 连续期望结果 `.bin`/`.mif` |
| `EXPECT_VALUE` | 空 | 单个期望 32-bit 值 |
| `EXPECT_ADDR` | `0x80700000` | 期望结果起始地址 |
| `WATCH_ADDR` | `0x80700000` | 人工观察窗口起始地址 |
| `WATCH_WORDS` | `8` | 人工观察的 32-bit 字数，0 为关闭 |
| `MAX_CYCLES` | `300000000` | 从复位开始的仿真超时上限 |
| `WAVE` | `0` | 设为 1 时生成 VCD 波形 |
| `WAVE_FILE` | `.build/<程序>/<程序>.vcd` | 波形输出文件 |
| `GCCPREFIX` | `loongarch32r-linux-gnusf-` | LA32R 工具链前缀 |
| `VERILATOR` | `verilator` | Verilator 可执行文件 |

## 8. 多题与重复测试

多个使用相同入口、数据和检查参数的程序可以顺序运行：

```bash
make -C asm suite PROGRAMS='programs/a.s programs/b.s programs/c.asm'
```

任意程序编译、超时或断言失败都会立即停止。各题的地址、输入或期望不同，建议分别写成
独立 shell 命令，避免误把上一题配置用于下一题。

## 9. 波形定位

短用例可直接生成 VCD：

```bash
make -C asm PROGRAM=programs/hello.s WAVE=1 run
```

默认文件为 `.build/hello/hello.vcd`。长时间、大数组题的全量波形会非常大，先用较小输入
复现，再打开波形检查：

1. IF：`cpu.pc_out`、`cpu.pc_inst_req`、`cpu.if_suspend`；
2. ISSUE：`cpu.issue_pop_0/1`、`cpu.ds_to_es_valid_0/1`；
3. EX/MEM：`cpu.es_to_ms_valid_0/1`、`data_addr`、`data_wdata`、握手信号；
4. WB：`cpu.ms_to_ws_valid_0/1`、`cpu.u_mem.ms_pc_0/1`；
5. UART：`uart_rx_ready/clear`、`uart_tx_start/data`。

框架不会恢复 `debug_wb_*`，也不会给 WB 增加 FIFO 或反压。

## 10. 生成物与清理

生成文件位于 `asm/.build/`：

```text
.build/
├── <程序名>/
│   ├── <程序名>.elf
│   ├── <程序名>.bin
│   ├── <程序名>.mif
│   ├── <程序名>.disasm
│   └── input.mif / expected.mif / 波形（按需）
└── verilator/
    └── Vasm_monitor_tb
```

它们已被 Git 忽略，可安全清理：

```bash
make -C asm clean
```

## 11. 常见失败

- `entry symbol ... not found`：用 `ENTRY=实际函数名`，或在汇编中导出 `_start`。
- `Immediate overflow`：把 `0x80400` 一类 `lu12i.w` 立即数改成有符号表达式。
- `memory region ... invalid`：地址必须 4 字节对齐、位于两片 SRAM，且连续镜像不能跨片。
- `user program exit was not observed`：确认程序最终执行 `jr $r1`，且没有破坏 `$r1`。
- `asm monitor timeout`：先增大 `MAX_CYCLES`；若 PC 长期不变，再按流水线/Cache 波形定位。
- `MISMATCH`：先检查 `.bin` 是否为小端、输入/输出基址是否与题面一致，再检查汇编算法。
- 只有 `PASS`、没有 `CHECK`：尚未启用结果断言，不能作为正确性结论。

本框架只改动仿真和构建文件，不参与 FPGA 综合，因此使用它本身不需要重新跑 Vivado
implementation；若随后修改了 `myCPU/*.v`，仍必须按仓库根目录 `AGENTS.md` 的流程完成
四程序功能回归和 Vivado 时序检查。
