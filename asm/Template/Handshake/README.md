# 串行握手加速器模板

本目录提供两个“每个元素可多周期处理”的自包含模板：

- `Map/`：实现 `dst[i] = F(src[i])`；
- `Reduction/`：实现 `result = reduce(src[i])`。

两个 engine 都严格按以下顺序工作：

```text
读取当前元素 -> 算法接收 -> 等待算法 out_valid -> 处理后续访存 -> 下一元素
```

算法没有报告当前元素完成前，engine 不会发出下一个元素的读请求。
总线上任意时刻也最多只有一笔未完成事务，可接入普通 SRAM-like bridge。

这是新增模板，不会替换 `asm/Template/Map` 和 `asm/Template/Reduction` 中的原有高吞吐版本。
