# Reduction 加速器模板

适用于完整读取数组、维护少量归约状态、最后只写一个 32-bit 结果的题目，例如最大值、
求和、计数和校验。Reduction 与 Map 使用相同的 `array_accel_engine` 模块名、配置参数及
CPU/存储器接口。

## 算法握手

`accelerator_logic.v` 使用与 Map 相同风格的 ready/valid 接口，并额外提供首元素标志：

- `run_start`：开始新任务并初始化全局归约状态；
- `in_valid && in_ready`：接收一个元素，`in_first` 标识 `A[0]`；
- `out_valid`：该元素处理完成，归约状态已更新；
- `result`：当前归约结果。

每次输入握手必须按顺序产生且只产生一次 `out_valid`。上一项尚未 `out_valid` 时，engine
不会让下一项进入算法；下一项最多预取到 engine 的单入口缓冲中。`out_valid` 和下一次
输入握手可以同拍发生，因此单拍算法在首项之后能够每拍接收一个元素，不插入算法空拍。

默认 `accelerator_logic.v` 用一拍完成无符号最大值归约。多周期算法只修改 USER MODIFY
REGION，并应保持 `in_ready/out_valid` 的握手语义。

## 访存约定

engine 最多保留一笔未返回的读请求。算法接收当前项的同拍会预取下一项：单拍算法配合
一拍响应的 SRAM bridge 时，读请求、读响应和算法输入都能逐拍连续；多周期算法则把
预取结果保存在输入缓冲中，直到旧元素完成。

下游必须满足：

- 每笔被 `mem_addr_ok` 接受的请求恰好返回一次 `mem_data_ok`；
- `mem_data_ok` 最早在请求被接受后的下一拍返回，且严格保持请求顺序；
- `mem_addr_ok=0` 时，engine 保持当前请求及其载荷不变。

## 验证

先检查 Verilator 版本：

```bash
verilator --version
```

单拍测试验证相邻算法输入逐拍连续；四拍测试验证上一项完成前下一项不能进入，并验证完成
拍能直接接收下一项：

```bash
build_dir=$(mktemp -d /tmp/reduction-template.XXXXXX)
verilator --binary --timing --top-module tb_array_accel_engine \
  --Mdir "$build_dir/one-cycle" \
  asm/Template/Reduction/tb_array_accel_engine.v \
  asm/Template/Reduction/array_accel_engine.v \
  asm/Template/Reduction/accelerator_logic.v
"$build_dir/one-cycle/Vtb_array_accel_engine"

verilator --binary --timing --top-module tb_array_accel_engine \
  -DREDUCTION_DEMO_CYCLES=4 \
  --Mdir "$build_dir/four-cycle" \
  asm/Template/Reduction/tb_array_accel_engine.v \
  asm/Template/Reduction/array_accel_engine.v \
  asm/Template/Reduction/accelerator_logic.v
"$build_dir/four-cycle/Vtb_array_accel_engine"

verilator --binary --timing --top-module tb_array_accel_engine \
  -DREDUCTION_DEMO_CYCLES=4 -DREDUCTION_TEST_ADDR_STALL \
  --Mdir "$build_dir/backpressure" \
  asm/Template/Reduction/tb_array_accel_engine.v \
  asm/Template/Reduction/array_accel_engine.v \
  asm/Template/Reduction/accelerator_logic.v
"$build_dir/backpressure/Vtb_array_accel_engine"
```
