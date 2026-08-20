# 多周期握手 Reduction 加速器

适用于完整读取数组、逐项更新归约状态，最后只写一个 32-bit 结果的题目。

## 算法接口

- `run_start`：新任务开始，初始化全局归约状态；
- `in_valid && in_ready`：接收当前元素，`in_first` 标识第一项；
- `out_valid`：当前元素已经完成归约更新；
- `result`：当前归约结果。

engine 在 `out_valid` 到达前不会读取下一项。默认
`reduction_handshake_logic.v` 用 4 个计算周期演示无符号最大值归约。

验证命令：

```bash
build_dir=$(mktemp -d /tmp/reduction-handshake.XXXXXX)
verilator --binary --timing --top-module tb_array_reduction_handshake_engine \
  --Mdir "$build_dir" \
  asm/Template/Handshake/Reduction/tb_array_reduction_handshake_engine.v \
  asm/Template/Handshake/Reduction/array_reduction_handshake_engine.v \
  asm/Template/Handshake/Reduction/reduction_handshake_logic.v
"$build_dir/Vtb_array_reduction_handshake_engine"
```
