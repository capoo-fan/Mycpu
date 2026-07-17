# supervisor-32：32位监控程序（“龙芯杯”个人赛）

本目录包含 LA32R supervisor/monitor 程序、串口终端和内置性能测试。软件从 `0x1c000000` 启动，通过串口命令读写内存、读写用户寄存器并跳转到 `UTEST_*` 测试入口。

## CPU 指令需求

运行当前 supervisor 至少需要实现以下普通整数、访存和跳转指令：

```text
lu12i.w, pcaddu12i, addi.w, add.w, sub.w, slt,
and, andi, or, ori, xor,
sll.w, slli.w, srli.w,
ld.b, ld.w, st.b, st.w,
b, bl, beq, bne, jirl,
mul.w
```

`mul.w` 由 `UTEST_MATRIX` 和 `UTEST_CRYPTONIGHT` 使用；若只运行 monitor 基本命令，可暂时不覆盖乘法测试。

无 cache CPU 仍建议实现 `cpucfg`，并让 `CPUCFG[0x10]` 返回 I-cache 和 D-cache 均不存在。这样 supervisor 会跳过 cache 初始化、DMW 配置和返回前 cache 写回，保持复位后的直接地址模式。

有 cache CPU 还需要实现：

```text
cpucfg, csrwr, csrxchg, cacop
```

相关 CSR/CPUCFG 最小要求：

- `CPUCFG[0x10]`：bit0 表示 L1 I-cache 存在，bit2 表示 L1 D-cache 存在。
- `CPUCFG[0x11]`：I-cache 几何参数。
- `CPUCFG[0x12]`：D-cache 几何参数，`[30:24]` 为 offset bits，`[23:16]` 为 index bits，`[15:0]` 为 max way。
- `CSR.CRMD` (`0x0`)：支持 `DA`、`PG` 以及直接地址/分页模式切换。
- `CSR.DMW0` (`0x180`) 和 `CSR.DMW1` (`0x181`)：支持直接映射窗口。
- `cacop 0x00`：I-cache index invalidate。
- `cacop 0x01`：D-cache index invalidate。
- `cacop 0x09`：D-cache index writeback invalidate。

当前 supervisor 不依赖异常返回、TLB 指令、LL/SC、浮点、除法或中断处理。

## SoC 地址空间需求

当前软件按以下物理地址访问 SoC：

| 地址范围 | 用途 | 是否必需 |
| --- | --- | --- |
| `0x1c000000 - 0x1c3fffff` | BaseRAM，存放 supervisor/kernel | 必需 |
| `0x1c400000 - 0x1c7fffff` | ExtRAM，存放测试输入、工作区和结果 | 必需 |
| `0x1f000000 - 0x1f0fffff` | UART 窗口 | 必需 |
| `0x1f100000 - 0x1f5fffff` | DVI/confreg/DMA/FFT 等扩展外设 | 当前 supervisor 不依赖 |

BaseRAM 和 ExtRAM 各 4 MiB。当前测试常用地址包括：

- `UTEST_STREAM`：从 `0x1c100000` 复制到 `0x1c400000`。
- `UTEST_MATRIX`：`A=0x1c400000`，`B=0x1c410000`，`C=0x1c420000`。
- `UTEST_CRYPTONIGHT`：2 MiB 工作区从 `0x1c400000` 开始。
- `UTEST_MIXED`：使用 `0x1c500000`、`0x1c510000`、`0x1c520000`。

复位后 CPU 应从 `0x1c000000` 取指。无 cache 情况下虚地址等于物理地址。有 cache 情况下 supervisor 配置：

- `DMW0 = 0x00000019`：`0x00000000 - 0x1fffffff` 身份映射，MAT=cacheable。
- `DMW1 = 0xa0000009`：`0xa0000000 - 0xbfffffff` 映射到低 512 MiB 物理地址，MAT=uncached。

因此 cache 模式下 UART 虚地址 `0xbf000000` 实际访问物理 `0x1f000000`。

## UART 最小接口

如果使用固定波特率 UART，可以只实现两个有效寄存器：

| 物理地址 | 名称 | 行为 |
| --- | --- | --- |
| `0x1f000000` | `UART_DATA` | 写低 8 位发送 1 字节；读返回接收字节 |
| `0x1f000005` | `UART_STATUS` | bit0=`RX_READY`，bit5=`TX_READY` |

串口读写伪代码：

```c
while ((UART_STATUS & 0x20) == 0) {}
UART_DATA = ch;

while ((UART_STATUS & 0x01) == 0) {}
ch = UART_DATA;
```

真实板卡需要配置波特率。若保持当前 supervisor 初始化代码不变，UART 还需要兼容以下 16550 风格写入：

| 地址偏移 | 写入值 | 含义 |
| --- | --- | --- |
| `+2` | `0x07` | 清 FIFO，可简化为忽略 |
| `+3` | `0x80` | 设置 `DLAB=1`，进入 divisor 配置 |
| `+1` | `0x00` | `DLH` |
| `+0` | `0x0e` | `DLL`，25 MHz UART 时钟下约 115200 baud |
| `+3` | `0x03` | 8 data bits、no parity、1 stop bit，并退出 divisor 配置 |
| `+4` | `0x00` | modem control，可简化为忽略 |

简化实现中，`+1/+2/+3/+4` 至少应允许写入不报错；真正运行依赖 `UART_DATA(+0)` 和 `UART_STATUS(+5)`。

## term.py 使用方法

`term/term.py` 是 Linux/WSL 环境下的 supervisor 交互工具。当前只使用 `-t` TCP 网络模式，没有本地执行模式，也不直接打开本地串口设备；它必须连接到一个已经运行的 SoC/仿真环境提供的 TCP 串口桥。运行前需要：

- Python 3。
- LoongArch32R 工具链在 `PATH` 中，或通过 `GCCPREFIX` 指定前缀；`A`/`F` 命令会调用 `loongarch32r-linux-gnusf-as`、`objcopy` 和 `objdump`。

常用启动方式：

```bash
cd sdk/software/examples/supervisor
python3 term/term.py -t 127.0.0.1:6666
```

其中 `127.0.0.1:6666` 是 TCP 串口桥的地址和端口，按实际仿真或上板代理程序修改。

默认启动后会等待并打印 supervisor 欢迎词。如果程序已经运行到命令循环，不想等待欢迎词，可加 `-c`：

```bash
python3 term/term.py -t 127.0.0.1:6666 -c
```

进入 `>>` 提示符后支持以下命令：

| 命令 | 作用 |
| --- | --- |
| `R` | 读取并打印用户寄存器备份。 |
| `D` | Dump 内存；依次输入起始地址和字节数，字节数必须是 4 的倍数。 |
| `A` | 从指定地址开始逐行输入汇编指令或 32-bit 机器码，并写入目标内存。空行结束。 |
| `F` | 从文件装载代码/数据到指定地址；Linux 版依赖本地 LoongArch 工具链，Windows 版 `term_win.py` 按二进制文件写入。 |
| `G` | 跳转到指定地址执行程序；收到 `0x06` 后开始计时，收到 `0x07` 后停止计时。 |
| `Q` | 退出终端。 |

常见性能测试入口：

```text
UTEST_MATRIX      0x1c002030
UTEST_CRYPTONIGHT 0x1c0020f0
UTEST_MIXED       0x1c002184
```

运行示例：

```text
>> G
>>addr: 0x1c002030
elapsed time: 12.345s
```

## 构建与运行

在 `kernel/` 下构建 supervisor：

```bash
make clean && make
```

生成的 `kernel.bin`、`kernel.s` 和 `axi_ram.mif` 会同步到 SDK 顶层。仿真时 BaseRAM 通常装载 `sdk/axi_ram.mif`，ExtRAM 可按测试需要装载 `sdk/ext_ram.mif` 或 utility 目录生成的数据文件。
