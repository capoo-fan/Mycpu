## Plan: MyCPU 双发射 In-Order 改造

在保持 in-order 与 precise exception 的前提下，把当前单发射 5 级流水升级为 2 发射结构。推荐采用“Slot0 全功能 + Slot1 轻量 ALU”的双槽方案，并强约束“每周期最多 1 条复杂指令（Branch/Mem/Mul/Div/CSR/异常类）+ 最多 1 条访存”。这样可以复用现有 LSU、共享 Mul/Div，先把结构跑通，再迭代逼近 2 IPC。

**Steps**
1. 阶段A-架构冻结：确定双发射规则表与提交语义。明确 Slot0/Slot1 指令合法性、同发射禁止条件（RAW/WAW、同周期分支取跳、CSR/异常冲突）、flush 优先级与“Slot0 老于 Slot1”的提交顺序。后续所有改造以此为唯一约束源。
2. 阶段A-总线协议重构（depends on 1）：在 mycpu.vh 重定义双槽级间总线与前递总线（FS→DS、DS→ES、ES→MS、MS→WS、FWD、WS→RF），统一位段布局为 slot0/slot1 打包格式，并保留单槽 valid 位用于 bubble 表示。
3. 阶段A-顶层连线骨架（depends on 2）：在 mycpu_top.v 扩展阶段端口与总线连线，先完成“接口编译可过”的骨架，不改内部行为，确保后续阶段可逐个替换。
4. 阶段B-寄存器堆升级（parallel with 5, depends on 2）：把 regfile.v 从 2R1W 升级为 4R2W，定义同周期双写冲突策略（建议在 ID 发射阶段禁止同周期写同一 rd，硬件侧保留固定优先级兜底）。
5. 阶段B-前端双取指（parallel with 4, depends on 1）：改 IF_stage.v 与 icache.v，实现每周期输出 2 条指令及有效位。处理 8B 对齐、跨 16B cache line 边界、分支/异常冲刷下的双槽缓冲清空与取消逻辑。
6. 阶段C-ID 双译码与发射仲裁（depends on 3,4,5）：在 ID_stage.v 增加双指令译码、同周期配对判定、依赖检测矩阵（slot0→slot1、历史流水线→slot0/slot1）、双槽源操作数选择与前递优先级。实现“能双发就双发，不能则 slot0 单发 + slot1 bubble”。
7. 阶段D-EXE 双槽执行（depends on 6）：在 EXE_stage.v 建立双 ALU 执行通路；Mul/Div 仅允许 Slot0 占用共享单元，Slot1 遇到 Mul/Div 直接在 ID 限制不发。同步扩展 es_ready_go/es_allowin 语义，保证同一发射组 in-order 推进。
8. 阶段D-MEM 单 LSU 兼容双槽（depends on 7）：在 MEM_stage.v 保留单 LSU 请求模型（每周期最多 1 条访存），规定访存仅在 Slot0；Slot1 仅做旁路通过。扩展 ms_fwd_bus/ms_to_ws_bus 的双槽打包，保证访存等待时成组阻塞不破坏顺序。
9. 阶段D-WB 双提交与双写回（depends on 8）：在 WB_stage.v 实现每周期最多 2 条提交与 2 路写回，严格按 Slot0→Slot1 顺序生效。异常/ERTN/中断仍以最老指令优先，若 Slot0 触发 flush，则同组 Slot1 取消提交。
10. 阶段E-总线桥与系统联调（depends on 8）：在 sram_axi_bridge.v 保持单数据请求语义不变，仅确认与新 MEM handshake 的兼容性；必要时补充仲裁公平性，避免 ICache 对数据访存长期饿死。
11. 阶段E-调试接口与可观测性（parallel with 10, depends on 9）：扩展 mycpu_top.v 调试导出为双槽提交信息（至少包含 pc、we、wnum、wdata 的 slot 维度），并保留兼容旧单槽观测口的映射方式。
12. 阶段E-性能收敛（depends on 10,11）：在不突破既定约束的前提下，优化 ID 发射策略与前递优先级，重点提升 ALU+ALU、ALU+Branch、ALU+Load/Store 场景的双发射命中率。

**Relevant files**
- /home/qianfu/Mycpu/mycpu.vh — 双槽总线位宽与位段定义
- /home/qianfu/Mycpu/mycpu_top.v — 双槽阶段连线、调试端口扩展
- /home/qianfu/Mycpu/IF_stage.v — 双取指、双槽缓冲、flush/cancel 规则
- /home/qianfu/Mycpu/icache.v — 双指令输出与跨行处理
- /home/qianfu/Mycpu/ID_stage.v — 双译码、发射仲裁、依赖与前递矩阵
- /home/qianfu/Mycpu/regfile.v — 4R2W 端口化与双写策略
- /home/qianfu/Mycpu/EXE_stage.v — 双 ALU 通路与共享 Mul/Div 约束
- /home/qianfu/Mycpu/MEM_stage.v — 单 LSU + 双槽透传模型
- /home/qianfu/Mycpu/WB_stage.v — 双提交、双写回、异常优先级
- /home/qianfu/Mycpu/sram_axi_bridge.v — 与单 LSU 语义对齐、仲裁检查

**Verification**
1. 编译与静态检查：确保所有阶段接口位宽、打包解包、握手信号在重构后一致，且无悬空/位宽截断告警。
2. 功能回归：先以“只发 Slot0（Slot1 恒 bubble）”模式验证与现有单发射行为一致，再打开双发射策略验证功能不回退。
3. 顺序语义校验：重点检查 flush、异常、ERTN、Load-Use、Mul/Div 长延迟场景下，提交顺序始终保持 Slot0 老于 Slot1。
4. 性能检查：统计双发射命中率与 CPI 变化，确认 ALU 密集代码中 IPC 明显提升并接近目标。

**Decisions**
- 已确认：in-order + precise exception。
- 已确认：支持 ALU+ALU、ALU+Branch、ALU+Load/Store。
- 已确认：每周期最多 1 条复杂指令、最多 1 条访存。
- 已确认：Mul/Div 共享单套资源，冲突在 ID 限制发射。
- 已确认：本次计划侧重改造步骤，不展开细粒度测试用例设计。
- 本次范围不包含：乱序执行、双访存并发、分支预测器体系重写。

**Further Considerations**
1. 若后续需要进一步逼近 2 IPC，可在本计划完成后新增“Slot1 支持部分 Load”作为二期目标，但这会牵引 MEM 与 bridge 从单请求模型升级为多未决请求模型。
2. 若综合后时序压力过大，优先保持 ID 仲裁与前递正确性，再考虑分阶段寄存或路径重定时。