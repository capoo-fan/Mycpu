## Plan: myCPU IF四级流水改造

在保持“先单条32-bit取指”的前提下，把当前 IF_stage 拆成4个子模块，先完成前端时序重构，再逐步向 mycpu_ref 的前端行为靠齐。第一阶段不追求双发射，只建立可扩展的四级 IF 骨架与稳定的 flush/stall 闭环。

**Steps**
1. 阶段定义与接口冻结（Phase A，阻塞后续）
1. 定义 IF0~IF3 四级职责与级间总线，新增 IF0_TO_IF1、IF1_TO_IF2、IF2_TO_IF3、IF3_TO_DS 总线字段与 valid/allowin 协议。*阻塞后续所有实现*
1. IF0（PC/预测级）：处理 nextpc 选择（br_target 优先于 pred_target），只做地址生成与请求发起资格判断，不消费返回数据。*阻塞 IF1/IF2*
1. IF1（请求提交级）：完成 inst request 提交与 addr_ok 握手，锁存请求上下文（pc、pred_target、epoch）。*依赖 IF0*
1. IF2（返回对齐级）：处理 data_ok/rdata、取消在途请求、异常返回过滤，形成“新鲜指令包”。*依赖 IF1*
1. IF3（发射缓冲级）：对接 ds_allowin，做 front buffer/queue 与 fs_to_ds_valid 输出。*依赖 IF2*
1. 模块拆分与骨架接线（Phase B）
1. 新建 4 个子模块并保留原 IF_stage 作为壳层路由（或重命名为 IF_frontend_top），先接通时钟复位和级间总线，不改功能语义。*依赖 Phase A*
1. 先迁移当前 IF_stage 的等价行为：单在途请求、单条数据返回、单条缓存（fs_buf）到 IF3。*依赖前一步*
1. 增加统一 epoch/tag（1~2 bit 即可）用于 flush 后返回数据丢弃，替代单 fs_cancel 对深流水的脆弱处理。*依赖 IF1/IF2*
1. 与 BPU/ICache 的时序对齐（Phase C）
1. BPU 输入保持 if_pc/if_valid 来自 IF1 请求提交点（req&&addr_ok），避免预测训练错拍。*依赖 Phase B*
1. ICache 接口先保持单条32-bit语义，确保 IF2 收到 data_ok 时可按 epoch 验证后再进入 IF3。*依赖 Phase B*
1. 若后续扩展到双发射，再在 IF2 输出端扩展为双槽包（inst0/inst1 + pc0/pc1 + pred信息），不回改 IF0/IF1。*并行设计预留*
1. 顶层重连与总线变更（Phase D）
1. 在 mycpu_top 中替换 IF_stage 例化为 IF 前端顶层（4子模块组合），调整 BPU、icache、ID_stage 的连接点。*依赖 Phase C*
1. 更新 mycpu.vh 总线宽度宏与新增 IF 级间宏，确保包打解包一致。*依赖前一步*
1. 验证与回归（Phase E）
1. 功能验证：复位后首条PC、顺序取指、分支冲刷后不接收旧返回、ID backpressure 下无丢指令。
1. 时序验证：连续 addr_ok/data_ok、addr先到data后到、flush 与 data_ok 同拍、ds_allowin 长时间为0。
1. 对齐验证：对照 mycpu_ref 前端行为，确认“flush优先级 > stall 保持 > 正常发射”的控制顺序。

**Relevant files**
- /home/qianfu/Mycpu/myCPU/IF_stage.v — 现有 IF 行为基线（单在途+fs_buf），将被拆分/重构
- /home/qianfu/Mycpu/myCPU/mycpu_top.v — IF/BPU/ICache/ID 的连接枢纽
- /home/qianfu/Mycpu/myCPU/mycpu.vh — 级间总线宽度与宏定义
- /home/qianfu/Mycpu/myCPU/BPU.v — if_valid 采样点与预测训练时序
- /home/qianfu/Mycpu/myCPU/icache.v — 地址握手与数据返回接口
- /home/qianfu/Mycpu/myCPU/icache_refill.v — miss refill 与外部存储桥接
- /home/qianfu/Mycpu/myCPU/ID_stage.v — ds_allowin、br_taken/br_target 的反馈来源
- /home/qianfu/Mycpu/mycpu_ref/myCPU.v — 参考前端闭环（PC/BPU/inst_cache/inst_buffer）
- /home/qianfu/Mycpu/mycpu_ref/inst_cache.v — 参考的分级 stall/flush 传播模式
- /home/qianfu/Mycpu/mycpu_ref/inst_buffer.v — 参考发射缓冲与前端解耦

**Verification**
1. 先做波形检查：IF0~IF3 的 valid/allowin 与请求返回握手必须一一对应。
1. 构造分支冲刷场景：flush 前后 epoch 改变，旧 data_ok 不能进入 IF3。
1. 构造后端阻塞场景：ds_allowin=0 持续多拍时 IF3 缓冲稳定，前级不会无限发请求。
1. 构造 cache miss 场景：addr_ok 后延迟多拍 data_ok，仍能保持 PC/inst 对齐。
1. 回归现有功能测试集，确认无首条指令丢失、无重复取指、无错跳转。

**Decisions**
- 已确认：第一阶段保持单条32-bit取指，不立即引入双发射取指。
- 已确认：采用“拆4个子模块”而非单文件硬切分。
- 已确认：接口允许调整，因此优先保证结构清晰与后续扩展性。
- 本阶段包含：IF 四级化、握手/冲刷/缓冲重构、与 BPU/ICache/ID 对接。
- 本阶段不包含：双发射前端、inst_buffer/inst_decoder 全量迁移、后端流水改成 mycpu_ref 同构。