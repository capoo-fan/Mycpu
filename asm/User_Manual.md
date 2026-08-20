# User_Manual

## 包含的资料

- Loongarch 指令表，查询指令
- 加速器使用指南 ACCELERATOR_INTEGRATION_2025
- 二分的模版
- 各种函数的模版

## C语言与汇编测试

将要测试的汇编程序写入到 user-sample.s 文件中

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