# User_Manual

## 包含的资料

- Loongarch 指令表，查询指令
- [硬件加速器接入手册](Acc_Manual.md)
- 二分的模版
- 各种函数的模版

## C语言与汇编测试

竞赛提交工程中的标准文件名为 `asm/user-sample.s`。本仓库的本地仿真入口为
`asm/programs/user_sample.s`；测试提交文件时，将其内容复制到该入口后运行仿真。

使用下述命令进行编译测试：

```bash
cd ~/Mycpu
make -C asm/programs
```

使用 `INIT_VALUES` 参数可以指定写入内存的初始值，使用 `WATCH_ADDR` 和 `WATCH_WORDS` 参数可以指定要观察的内存地址和长度。

仿真会输出程序执行的 cycles 和 IPC 信息，以及指定内存区域的内容。

```bash
[INIT] 0x80400000: 1 64 50 49 100
[ENTRY] source=.text address=0x80100000 _start=0x00000000
RESULT entry=80100000 program_bytes=128
+----------+--------------+--------------+----------+----------+
| SCOPE    | CYCLES       | INST         | IPC      | CPI      |
+----------+--------------+--------------+----------+----------+
| G_TO_07  |      3933612 |      3539203 | 0.899734 | 1.111440 |
+----------+--------------+--------------+----------+----------+
MEM_WRITES count=1 logged=1
WRITE addr=1c700000 data=00000001
MEMORY addr=80400000 words=5
MEM addr=80400000 data=00000001
MEM addr=80400004 data=00000040
MEM addr=80400008 data=00000032
MEM addr=8040000c data=00000031
MEM addr=80400010 data=00000064
MEMORY addr=80700000 words=5
MEM addr=80700000 data=00000001
MEM addr=80700004 data=00000000
MEM addr=80700008 data=00000000
MEM addr=8070000c data=00000000
MEM addr=80700010 data=00000000
PASS asm monitor test
```

根据输出结果中的 cycles ，再结合主频，可以计算出程序的执行时间。

$time = \frac{cycles}{frequency(MHZ)*1000}$，例如： 3933612 个 cycles，主频为 150MHZ，则执行时间为： $\frac{3933612}{150*1000} = 26.224$ ms

## 在线实验平台 TCP 烧录测试

`term.py` 运行在本机，通过在线平台显示的 TCP 串口转发地址与 monitor 通信。
这个过程是将程序临时写入 SRAM，不是重新生成 bitstream，也不是写入 NOR Flash。

2025 年题目的手写汇编约定为：

| 区域     | 虚拟地址     | 用途                                    |
| -------- | ------------ | --------------------------------------- |
| 用户程序 | `0x80100000` | `user-sample.s` 装载和执行入口          |
| 数组 A   | `0x80400000` | `0x300000` 字节，共 786432 个 32 位整数 |
| 结果     | `0x80700000` | 第一个元素在数组中的出现次数            |

请勿把本题的程序改装到 `0x1c300000`。`user-sample.s` 中的数据地址和竞赛环境均按
`0x80xxxxxx` 虚拟地址约定工作。

### 1. 检查 `user-sample.s`

手写汇编版本不需要加入 `Accelerator.v`，也不应使用自定义加速指令。程序必须满足：

- 第一条真实指令是 `.text` 段入口；
- 运行期间不破坏 `$r1`；
- 程序末尾使用 `jr $r1` 或 `jirl $r0,$r1,0` 返回 monitor；
- 不调用未装入 SRAM 的外部函数。

在竞赛工程根目录中先编译：

```bash
source ~/Mycpu/.venv/bin/activate
export GCCPREFIX=loongarch32r-linux-gnusf-
make -C asm
```
### 2. 连接在线平台

烧写 bitstream 后

先打开串口，选择文件，找到 supervisor/build/kernel/kernel.bin ，将监控程序烧录进去

确认打印欢迎信息：
```text
MONITOR for Loongarch32 - initialized.
```

网页串口应为 `115200` baud、8 位数据、无校验、1 位停止位。看到欢迎信息后：

1. 点击网页中的“关闭串口”，避免网页和 Python 争抢接收数据；
2. 复制页面当前显示的“网络转发” `IP:端口`；
3. 在本机执行下列命令，用实际地址替换 `<IP:端口>`。

```bash
source ~/Mycpu/.venv/bin/activate
export GCCPREFIX=loongarch32r-linux-gnusf-
python3 ~/Mycpu/supervisor/term/term.py -t <IP:端口> -c
```

`-c` 表示欢迎信息已经被网页读取，`term.py` 不再等待这 38 字节。如果先运行
`term.py`、再按开发板的 RST 键，则可以省略 `-c`。

### 3. 装载汇编程序

在 `term.py` 的 `>>` 提示符中输入：

```text
>> F
>>file name: asm/programs/user_sample.s
>>addr: 0x80100000
```

这里的相对路径以启动 `term.py` 时的当前目录为基准；不确定时可直接输入
`user-sample.s` 的绝对路径。

Linux 版 `term.py` 的 `F` 命令读取的是汇编源文件，它会在本机调用 LA32R 汇编器并将机器码
通过 monitor 写入 SRAM。不要把 `.bin` 文件交给这个 `term.py`；`term_win.py` 的 `F` 命令则恰好相反，
只按二进制文件写入。

装载完成后可读回前 128 字节，确认目标地址不是空数据：

```text
>> D
>>addr: 0x80100000
>>num: 128
```

### 4. 确认 2025 题目输入

上述 `F` 命令只装载用户程序，不会自动在 `0x80400000` 生成 3 MiB 随机数组。
正式评测器会准备测试数据；普通在线工作区手工运行时，必须先确认当前 ExtRAM 中是否已有
需要的输入。

```text
>> D
>>addr: 0x80400000
>>num: 20
```

若需要通过串口另行装入完整 3 MiB 输入，115200 baud 是明显瓶颈。现有逐字 `F`
实现需要发送大量 monitor 包，可能用时约 15 分钟且中途没有进度输出；单个大块 `A`
包仍需约 4.5 分钟。因此，完整随机数据正确性优先使用本地仿真或平台正式评测；
`term.py` 更适合装载程序、读回少量数据和定位上板问题。

### 5. 执行并读回结果

输入确认完成后，使用与装载地址相同的入口执行：

```text
>> G
>>addr: 0x80100000
```

用户程序执行期间不会输出进度。只有末尾的 `jr $r1` 正确返回 monitor，并且 monitor 发出
`0x07` 结束标志后，`term.py` 才会显示：

```text
elapsed time: ...s
>>
```

读回结果：

```text
>> D
>>addr: 0x80700000
>>num: 4
```

读到的 32 位值应等于 786432 个输入整数中 `A[0]` 的出现次数。出现
`elapsed time` 只表示程序成功返回，必须再将该结果与同一份输入的软件参考结果比较，才能判定算法正确。

### 6. 长时间无返回的定位

- 连接后一直等待欢迎信息：欢迎信息已被网页读走，重新连接时加 `-c`。
- TCP 无法连接或协议错乱：关闭网页串口，并确认使用本次会话显示的最新 `IP:端口`。
- 停在 `reading from file ...`：检查是否给 Linux `term.py` 传入了文本 `.s`，并且装载地址是
  `0x80100000`。若误用 `0x1c300000`，当前工具会先生成约 204 MB 的临时二进制。
- 装入大块输入时长时间无提示：串口仍在传输数据，不要立即按 RST 或再建立第二个连接。
- `G 0x80100000` 后数秒仍不返回：优先检查装载地址和执行地址是否一致、程序是否保留
  `$r1`、末尾是否执行 `jr $r1`。这段手写程序的正常运行时间不应达到秒级。
- 如果上述条件均正确，则按 IF、ISSUE、EX/MEM、WB 顺序检查 `0x80400000` 到
  `0x80700000` 扫描过程中的 PC、valid/stall/flush、load 请求与返回、`bne` 跳转和最后的写回。
