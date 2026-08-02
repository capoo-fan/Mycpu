# 核心架构与开发指南

## 构建与运行指令

CPU 源文件仓库位于 ~/Mycpu,可用于仿真测试正确性

本机项目仿真优先使用 Verilator 5.050。

```bash
verilator --version
```

版本输出必须为 `Verilator 5.050 2026-07-01`。该安装包含 `--binary` 和 `--timing`，
用于后续将四程序长时间回归迁移到 Verilator；Icarus 只保留作兼容性检查。

本项目的 CPU 回归只使用 supervisor 中的以下四个汇编性能程序：

- `UTEST_STREAM`：连续读写、SRAM/cache 大容量数据通路；
- `UTEST_MATRIX`：乘法、累加、多层循环、load/store 和数据相关；
- `UTEST_CRYPTONIGHT`：2 MiB 工作区、伪随机访存、乘法和长时间稳定性；
- `UTEST_MIXED`：顺序访存、随机访存、分支和 ALU 混合负载。

不把 SIMPLE、Fibonacci、官方 trace 或额外 CPU 自检加入本项目的验收结果。

---

vivado 仓库位于 ~/thinpad_top，用于生成时序报告，且 CPU 设计文件会自动同步 ～/Mycpu/myCPU 文件夹

真实工程已经创建完成，位于 ~/thinpad_top/run_vivado/project/thinpad_top.xpr

vivado 仓库结构如下

```text
.
|-- asm/
|   |-- Makefile
|   `-- user-sample.s
|
|-- src/
|   |-- soc/
|   |   |-- *.v
|   |   `-- xilinx_ip/
|   `-- vivado_cannot/
|
|-- run_vivado/
|   |-- constraints/
|   |   `-- thinpad_top.xdc
|   |-- simulation/
|   `-- flow/
|       |-- create_vivado_project.tcl
|       |-- lint_hdl.py
|       |-- implement_design.tcl
|       |-- check_timing.py
|       `-- generate_bitstream.tcl
|
`-- README.md
```

修改代码后生成时序报告:

```
vivado -mode batch \
    -log ~/thinpad_top/run_vivado/implement.log \
    -journal ~/thinpad_top/run_vivado/implement.jou \
    -source ~/thinpad_top/run_vivado/flow/implement_design.tcl
```

新生成的时序报告位于 `~/thinpad_top/run_vivado/project/thinpad_top.runs/impl_1`  

自动更新流程

```
每轮 RTL 修改完成后，必须按照以下顺序执行：

备份上一份 thinpad_top_timing_summary_rounted.rpt 于 ~/thinpad_top/reports/ 下
        ↓
运行 Vivado implementation
        ↓
检查 Vivado 是否成功生成新的 thinpad_top_timing_summary_rounted.rpt
        ↓
Agent 读取 thinpad_top_timing_summary_rounted.rpt
        ↓
根据关键路径决定下一轮修改
```

## Debug 信号约束

- `WB_stage` 中不允许存在 debug FIFO、debug 事件寄存器或由 debug 引起的
  `ws_allowin` 反压。WB 每拍可同时提交两条普通写回。
- `mycpu_top` 的四个 `debug_wb_*` 只是为了兼容龙芯 SoC 现有命名端口，必须绑定为
  常量，不得从流水线引出 PC、寄存器号或写回数据长线。
- 上板顶层的 LED/数码管不再使用 debug 写回信号。定位问题时使用仿真波形中的
  IF/ISSUE/EX/MEM/WB 内部信号，不得为此恢复 debug FIFO。

## 四程序详细测试方法

### 1. 生成 supervisor 程序与正确结果

在 Mycpu 仓库根目录激活已准备的 Python 环境，并显式指定 LA32R 工具链：

```bash
MYCPU_ROOT=$(pwd)
source .venv/bin/activate
export GCCPREFIX=/opt/loongarch-env/loongarch32r-toolchain/bin/loongarch32r-linux-gnusf-
cd supervisor
PYTHON="$MYCPU_ROOT/.venv/bin/python" ./build_all.sh
```

构建必须成功产生：

- `build/kernel/auto/axi_ram.mif`：四程序使用的 supervisor BaseRAM 镜像；
- `build/kernel/auto/utest_symbols.txt`：四个 `UTEST_*` 的实际入口；
- `build/utility/{stream,matrix,crypto,mixed}/`：输入、正确结果与比较文件；
- `build/utility/disasm/`：四程序的独立 `.bin`、LA32R `.disasm` 和 `MANIFEST.txt`。

用以下命令确认汇编入口和反汇编范围：

```bash
cat build/kernel/auto/utest_symbols.txt
cat build/utility/disasm/MANIFEST.txt
less build/utility/disasm/stream.disasm
less build/utility/disasm/matrix.disasm
less build/utility/disasm/cryptonight.disasm
less build/utility/disasm/mixed.disasm
```

### 2. 在完整 SoC 仿真中自动测试 CPU

当前仓库的类 SRAM `mycpu_top` 可直接使用本地 testbench：

```bash
make -f test/supervisor_perf.mk stream
make -f test/supervisor_perf.mk matrix
make -f test/supervisor_perf.mk cryptonight
make -f test/supervisor_perf.mk mixed
# 或者按上述顺序一次运行
make -f test/supervisor_perf.mk suite
```

该 testbench 不使用 `debug_wb_*`；它等待 monitor 串口欢迎词，通过 `G` 命令启动
`utest_symbols.txt` 中的入口，收到 `0x07` 结束标志后逐字检查 ExtRAM。Icarus
运行 STREAM、MATRIX 和 CryptoNight 可能耗时较长，正式回归优先使用下述
Verilator/XSIM 场景。

`supervisor/sim/` 需要作为 `nscscc-solo-la-soc` 的 supervisor 子模块使用。在该父仓库
根目录激活上述虚拟环境，确保父仓库已使用当前 `myCPU/*.v` 和 supervisor
内容。父仓库的默认 CPU 合同是 AXI `core_top`；当前类 SRAM `mycpu_top` 必须经过
匹配的 SRAM-to-AXI wrapper 后才能接入，没有 wrapper 时使用上述本地 testbench。
首次执行 STREAM 时加 `--prepare`，其余用例复用构建产物：

```bash
python3 sim/run.py sdk/software/examples/supervisor/sim/cases/stream.json --prepare
python3 sim/run.py sdk/software/examples/supervisor/sim/cases/matrix.json
python3 sim/run.py sdk/software/examples/supervisor/sim/cases/cryptonight.json
python3 sim/run.py sdk/software/examples/supervisor/sim/cases/mixed.json
```

也可只用四程序套件一次运行，首个失败即停止：

```bash
python3 sim/run.py sdk/software/examples/supervisor/sim/suite.json --prepare
```

通过条件：

- STREAM：`0x1c400000` 开始的 3 MiB 与 `stream_input.bin` 完全相同；
- MATRIX：`0x1c420000` 开始的 C 矩阵与 `matrix_expected.bin` 完全相同；
- CryptoNight：`0x1c400000` 开始的 2 MiB 工作区与 `crypto.bin` 完全相同；
- MIXED：`0x1c520000` 开始的 5 字签名与 `mixed_signature.bin` 完全相同。

### 3. 失败定位

对失败场景在命令末尾加 `+wave`。由于 debug 写回线已删除，波形必须直接检查：

1. IF：`pc_out`、`pc_inst_req`、`if_suspend`、ICache hit/refill 状态；
2. ISSUE：两路 valid/pop、RAW 前递、load-use 等待；
3. EX/MEM：ALU/乘法结果、分支冲刷、`data_sram_req/wr/addr/wdata`；
4. WB：`ws_valid_0/1`、`ws_to_rf_bus`、CSR flush；
5. 存储器：`data_sram_addr_ok/data_ok`、byte enable、cache 命中/回填/写回。

先修复功能错误，四个场景全部通过后才允许进行频率、CPI 或 cache 性能优化。

## 🏗 架构上下文

- 本项目是龙芯杯的个人赛参赛作品，追求高频率和高性能，代码中不允许出现过度消耗布线资源的情况。
- 本项目实现的是一个带有五级流水线架构的 LA32R (LoongArch) 指令集处理器。
- 分支预测模块（BPU）当前与取指阶段（IF）紧耦合。
- 缓存设计采用哈佛架构（指令和数据缓存分离），需严格保证缓存一致性逻辑。
- mycpu_ref 是一个功能完整的参考模型，主要用于验证和测试。

## 🛠 开发指南

- **模块化设计**：每个功能模块（如 IF、ID、EX、MEM、WB）应独立开发和测试，确保接口清晰。
- 具体架构需要参考 mycpu_ref 下的 设计参考.pdf 文档，确保实现细节与设计规范一致。。
