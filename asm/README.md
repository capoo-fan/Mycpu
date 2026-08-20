# user_sample.s 与 myCPU 仿真

本目录只编译和仿真 [programs/user_sample.s](programs/user_sample.s)。Makefile 通过
supervisor monitor 将程序装入当前 `myCPU/*.v`，运行结束后输出 cycles、退休指令数、
IPC、CPI、写事务以及两组内存数据。


## 1. 环境

在仓库根目录执行：

```bash
cd ~/Mycpu
source .venv/bin/activate
export GCCPREFIX=loongarch32r-linux-gnusf-
verilator --version
```

Verilator 必须为 `Verilator 5.050 2026-07-01`。若 supervisor BaseRAM 镜像不存在，
Makefile 会自动执行 `supervisor/build_all.sh`。

## 2. 运行

把待测试的统一模板内容保存到 `asm/programs/user_sample.s`，然后执行：

```bash
make -C asm/programs
```

只编译，不启动仿真：

```bash
make -C asm/programs program
```

生成波形：

```bash
make -C asm/programs WAVE=1
```

## 3. 统一模板与自动入口

图片中的模板可以原样使用：

```asm
    .global _start
    .section text
_start:
.text
    # 用户程序，第一条真实指令位于这里
    # ...
    jr      $r1
```

这类模板会把 `_start` 符号链接到 `0x00000000`，而真正的 `.text` 位于
`0x80100000`。Makefile 会自动处理：

1. 若 `_start` 位于已上传的程序镜像内，使用 `_start`；
2. 否则使用 `.text` 段首地址；
3. 若入口不在镜像内或未按 4 字节对齐，立即报错。

正常情况下会打印：

```text
[ENTRY] source=.text address=0x80100000 _start=0x00000000
```

模板必须满足：

- `.text` 后第一条指令是真实入口；
- 程序最终通过 `jr $r1` 返回 monitor；
- 执行期间不破坏 `$r1`；
- 不调用未装入 SRAM 的外部函数。

## 4. 默认输入与内存输出

未指定 `DATA` 或 `INIT` 时，Makefile 会从 `0x80400000` 开始写入五个 32 位值：

```text
1 2 3 4 5
```

可在命令行修改：

```bash
make -C asm/programs \
  INIT_ADDR=0x80400000 \
  INIT_VALUES='10 20 30 40 50'
```

仿真结束默认打印两组各 5 个字：

```text
MEMORY addr=80400000 words=5
MEM addr=80400000 data=...
...
MEMORY addr=80700000 words=5
MEM addr=80700000 data=...
```

对应变量是：

```text
WATCH_ADDR=0x80400000    WATCH_WORDS=5
WATCH_ADDR_2=0x80700000  WATCH_WORDS_2=5
```

## 5. 文件输入与自动检查

大块连续输入使用 `DATA`，支持小端 `.bin` 或每行一个 32 位二进制字的 `.mif`：

```bash
make -C asm/programs \
  DATA=cases/input.bin \
  DATA_ADDR=0x80400000
```

设置 `DATA` 后不会再写入默认的 `1、2、3、4、5`。稀疏输入可通过 `INIT` 指定文本文件，
每行是十六进制的“地址 值”：

```text
80400000 deadbeef
80700004 01234567
```

单字结果检查：

```bash
make -C asm/programs \
  EXPECT_VALUE=5 \
  EXPECT_ADDR=0x80700000
```

连续结果使用 `EXPECT=<结果.bin|结果.mif>`。`EXPECT` 与 `EXPECT_VALUE` 不能同时设置。
没有结果断言时，最后的 `PASS` 只表示程序成功返回，不代表算法结果正确。

## 6. 性能输出

```text
RESULT entry=80100000 program_bytes=...
+----------+--------------+--------------+----------+----------+
| SCOPE    | CYCLES       | INST         | IPC      | CPI      |
+----------+--------------+--------------+----------+----------+
| G_TO_07  |          ... |          ... |      ... |      ... |
+----------+--------------+--------------+----------+----------+
```

性能只使用 `G_TO_07` 总区间：Makefile 开始发送 `G` 命令后，第一个 CPU 时钟上升沿计为
第 1 个 cycle；monitor 发出结束标记 `0x07` 的时钟周期计入最后一拍。`INST` 是该区间
两路 WB 的退休指令总数，`IPC = INST / CYCLES`，`CPI = CYCLES / INST`。该口径包含
monitor 接收入口地址、启动程序和返回收尾的开销。

## 7. 常用变量

| 变量 | 默认值 | 作用 |
| --- | --- | --- |
| `PROGRAM_ADDR` | `0x80100000` | `.text` 链接和 monitor 装载地址 |
| `INIT_ADDR` | `0x80400000` | 默认输入起始地址 |
| `INIT_VALUES` | `1 2 3 4 5` | 默认输入值 |
| `DATA` | 空 | 连续输入 `.bin` 或 `.mif` |
| `DATA_ADDR` | `0x80400000` | 连续输入地址 |
| `INIT` | 空 | 自定义稀疏初始化文件 |
| `EXPECT` | 空 | 连续期望结果 |
| `EXPECT_VALUE` | 空 | 单字期望结果 |
| `EXPECT_ADDR` | `0x80700000` | 结果检查地址 |
| `WATCH_ADDR` | `0x80400000` | 第一组观察地址 |
| `WATCH_WORDS` | `5` | 第一组字数，0 表示关闭 |
| `WATCH_ADDR_2` | `0x80700000` | 第二组观察地址 |
| `WATCH_WORDS_2` | `5` | 第二组字数，0 表示关闭 |
| `MAX_CYCLES` | `300000000` | 仿真超时周期数 |
| `WAVE` | `0` | 设为 1 时生成 VCD |

## 8. 生成物与错误定位

程序生成物位于 `asm/.build/user_sample/`，包括 ELF、BIN、MIF、反汇编、初始化文件和
可选 VCD；Verilator 生成物位于 `asm/.build/verilator/`。

```bash
make -C asm/programs clean
```

常见错误：

- `no executable .text section`：模板没有实际 `.text` 指令；
- `.text entry is outside...`：链接地址与装载地址不一致；
- `Immediate overflow`：`lu12i.w` 地址立即数应使用模板中的有符号表达式；
- `user program exit was not observed`：程序没有执行 `jr $r1`，或 `$r1` 被破坏；
- `asm monitor timeout`：程序死循环，或 `MAX_CYCLES` 太小；
- `MISMATCH`：结果地址、输入格式或算法结果错误。

这些构建和 testbench 功能不参与 FPGA 综合。只有修改 `myCPU/*.v` 后，才需要执行四程序
回归和 Vivado implementation。
