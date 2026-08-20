# 多周期握手 Map 加速器

适用于 `dst[i] = F(src[i])`。当前项经过“读取、算法处理、写回”完整流程后，
engine 才会读取下一项；不会预取。

## 算法接口

- `in_valid && in_ready`：接收一个输入；
- `out_valid`：当前输入已处理完，`out_data` 有效。

`out_valid` 可在输入接收后的任意后续周期产生。每接收一个输入，必须恰好产生一次
`out_valid`。默认 `map_handshake_logic.v` 用 4 个计算周期演示 identity 操作。

## 使用

1. 在 `array_map_handshake_engine` 实例中设置 `SRC_BEGIN`、`SRC_END` 和 `DST_BEGIN`；
2. 修改 `map_handshake_logic.v` 的 USER MODIFY REGION；
3. 保持输入/输出握手规则不变。

验证命令：

```bash
build_dir=$(mktemp -d /tmp/map-handshake.XXXXXX)
verilator --binary --timing --top-module tb_array_map_handshake_engine \
  --Mdir "$build_dir" \
  asm/Template/Handshake/Map/tb_array_map_handshake_engine.v \
  asm/Template/Handshake/Map/array_map_handshake_engine.v \
  asm/Template/Handshake/Map/map_handshake_logic.v
"$build_dir/Vtb_array_map_handshake_engine"
```
