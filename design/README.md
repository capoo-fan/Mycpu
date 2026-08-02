# 龙芯杯设计报告 LaTeX 工程

## 编译

```bash
xelatex -interaction=nonstopmode main.tex
xelatex -interaction=nonstopmode main.tex
```

也可使用：

```bash
latexmk -xelatex main.tex
```

## 必须填写/替换的内容

1. 在 `main.tex` 顶部填写学校、姓名、学号。
2. 用最终上板数据填写 STREAM、MATRIX、CRYPTONIGHT、资源和时序表格。
3. 直接替换 `figures/` 下同名 PDF 文件，保持文件名不变即可更新图片。
4. 最终提交前核对 `thinpad_top.v` 中 `CPU_CLK_FREQ` 与 PLL 实际频率一致。
5. 当前上传版本的 `load_wakeup` 接口在 MEM/ISSUE 中存在，但顶层未连通；报告未将其计为已启用功能。
6. 参考设计说明应根据实际代码来源再次人工核对，不能删除真实借鉴或第三方 IP 信息。

## 图片文件约定

- `01_system_architecture.pdf`：系统总体结构图
- `02_pipeline_structure.pdf`：流水线结构图
- `03_icache_structure.pdf`：I-Cache 组织与回填图
- `04_issue_forwarding.pdf`：发射与前递图
- `05_bpu_structure.pdf`：分支预测器图
- `06_memory_bridge.pdf`：存储与 UART 桥接图
- `07_simulation_waveform.pdf`：仿真波形/日志
- `08_timing_summary.pdf`：Vivado 时序摘要
- `09_resource_utilization.pdf`：Vivado 资源利用率
- `10_board_demo.pdf`：上板与串口运行照片
