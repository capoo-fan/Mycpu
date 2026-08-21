# Map 加速器模板

适用于 `result[i] = F(array[i])`。Map 与 Reduction 现在使用相同的 engine
模块名、配置参数和 CPU/存储器接口，可以用同一段顶层例化代码接入 CPU。

## 统一 engine 接口

模块名固定为 `array_accel_engine`，配置参数固定为：

- `ARRAY_BEGIN`：输入数组首地址；
- `ARRAY_END`：输入数组独占上界；
- `RESULT_ADDR`：Map 结果数组首地址。

控制端口均为 `start/busy/done` 和 `takeover_req/takeover_grant`；存储器端口均为
`mem_req/mem_wr/mem_size/mem_wstrb/mem_addr/mem_wdata` 与
`mem_addr_ok/mem_data_ok/mem_rdata`。因此从 Map 切换为 Reduction 时，CPU 顶层只需
更换同名 engine 和 `accelerator_logic.v` 源文件，不需要改例化端口。

## 连续访存约定

默认算法为组合恒等映射。读响应到达时，engine 同拍提出对应写请求；写响应到达时，
同拍提出下一元素的读请求。首笔请求出现后到最后一笔写请求之间，engine 不主动拉低
`mem_req`。如果 `mem_addr_ok=0`，当前请求及其全部载荷保持不变；这属于下游背压。

下游必须满足：

- 每笔被 `mem_addr_ok` 接受的请求恰好返回一次 `mem_data_ok`；
- 响应最早在请求被接受后的下一拍返回，且严格保持请求顺序；
- 若希望达到每拍一笔请求，下游也必须能每拍接受并返回一笔事务。

只在 `accelerator_logic.v` 的 USER MODIFY REGION 中实现无状态组合 `F(x)`。该高吞吐
模板要求同拍产生结果；寄存流水或多周期算法应使用 `Template/Handshake/Map`。

源区间和结果区间可以完全分离，也可以 `RESULT_ADDR == ARRAY_BEGIN` 原地映射；不支持
两个区间仅部分重叠，因为无气泡流水无法保留逐元素 `memmove` 式覆盖语义。

## 验证

testbench 会周期性拉低 `mem_addr_ok`，同时检查请求保持、读写顺序、地址、结果以及
engine 是否主动插入空拍：

```bash
build_dir=$(mktemp -d /tmp/map-template.XXXXXX)
verilator --binary --timing --top-module tb_array_map_engine \
  --Mdir "$build_dir" \
  asm/Template/Map/tb_array_map_engine.v \
  asm/Template/Map/array_accel_engine.v \
  asm/Template/Map/accelerator_logic.v
"$build_dir/Vtb_array_map_engine"
```
