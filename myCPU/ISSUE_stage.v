`include "mycpu.vh"

module ISSUE_stage(
    input  wire                           clk,
    input  wire                           resetn,
    // 来自 IF 阶段的指令信息
    input  wire                           front_valid_0,
    input  wire [`IBUF_ENTRY_BUS_WD-1:0]  front_bus_0,
    input  wire [4:0]                     front_raddr1_0_hot,
    input  wire [4:0]                     front_raddr2_0_hot,
    input  wire                           front_valid_1,
    input  wire [`IBUF_ENTRY_BUS_WD-1:0]  front_bus_1,
    input  wire [4:0]                     front_raddr1_1_hot,
    input  wire [4:0]                     front_raddr2_1_hot,
    output wire                           pop_0,
    output wire                           pop_1,
    output wire                           special_fire,
    input  wire                           br_taken,
    input  wire                           special_block,

    input  wire                           es_allowin,
    // 前递信息
    input  wire [`ES_FWD_BUS_WD-1  :  0]  es_fwd_bus_0,
    input  wire [`ES_FWD_BUS_1_WD-1:  0]  es_fwd_bus_1,
    input  wire [`MS_FWD_BUS_WD-1  :  0]  ms_fwd_bus_0,
    input  wire [`MS_FWD_BUS_1_WD-1:  0]  ms_fwd_bus_1,
    input  wire [`WS_TO_RF_BUS_WD-1:  0]  ws_to_rf_bus,
    input  wire                           load_wakeup_valid,
    // 送到 ES 阶段的信息
    output wire                           ds_to_es_valid_0,
    output wire                           ds_to_es_valid_1,
    output wire [`DS_TO_ES_BUS_WD-1:  0]  ds_to_es_bus_0,
    output wire [`DS_TO_ES_BUS_1_WD-1:0]  ds_to_es_bus_1,
    output wire [31:0]                    ds_mul_src1_0,
    output wire [31:0]                    ds_mul_src2_0,
    output wire [31:0]                    ds_mul_src1_1,
    output wire [31:0]                    ds_mul_src2_1
  );

  // 两条指令译码
  wire [`DS_DEC_BUS_WD-1:0]   dec_bus_0;
  wire [`FS_TO_DS_BUS_WD-1:0] fs_bus_0;
  wire [`DS_DEC_BUS_WD-1:0]   dec_bus_1;
  wire [`FS_TO_DS_BUS_WD-1:0] fs_bus_1;

  assign {dec_bus_0, fs_bus_0} = front_bus_0;
  assign {dec_bus_1, fs_bus_1} = front_bus_1;

  wire [31:0] ds_pc_0;
  wire [31:0] ds_inst_0;
  wire        ds_pred_taken_0;
  wire [31:0] ds_pred_target_0;

  wire [31:0] ds_pc_1;
  wire [31:0] ds_inst_1;
  wire        ds_pred_taken_1;
  wire [31:0] ds_pred_target_1;

  assign {ds_pc_0, ds_inst_0, ds_pred_taken_0, ds_pred_target_0} = fs_bus_0;
  assign {ds_pc_1, ds_inst_1, ds_pred_taken_1, ds_pred_target_1} = fs_bus_1;

  wire [11:0] alu_op_0;
  wire [31:0] imm_0;
  wire [31:0] br_offs_0;
  wire [31:0] jirl_offs_0;
  wire [ 4:0] rf_raddr1_0;
  wire [ 4:0] rf_raddr2_0;
  wire [ 4:0] dest_0;
  wire        src1_is_pc_0;
  wire        src2_is_imm_0;
  wire        res_from_mem_0;
  wire        gr_we_0;
  wire        mem_we_0;
  wire        is_mul_0;
  wire        ld_byte_0;
  wire        ld_half_0;
  wire        ld_sign_ext_0;
  wire        st_byte_0;
  wire        st_half_0;
  wire        need_rj_0;
  wire        need_rkd_0;
  wire        is_bj_0;
  wire        inst_beq_0;
  wire        inst_bne_0;
  wire        inst_blt_0;
  wire        inst_bge_0;
  wire        inst_bltu_0;
  wire        inst_bgeu_0;
  wire        inst_jirl_0;
  wire        inst_bl_0;
  wire        inst_b_0;
  wire        is_cpucfg_0;
  wire        is_cacop_0;
  wire [ 4:0] cacop_code_0;
  wire        is_csr_0;
  wire        is_csrxchg_0;
  wire [13:0] csr_num_0;

  assign {alu_op_0, imm_0, br_offs_0, jirl_offs_0,
          rf_raddr1_0, rf_raddr2_0, dest_0,
          src1_is_pc_0, src2_is_imm_0, res_from_mem_0, gr_we_0, mem_we_0,
          is_mul_0,
          ld_byte_0, ld_half_0, ld_sign_ext_0, st_byte_0, st_half_0,
          need_rj_0, need_rkd_0, is_bj_0,
          inst_beq_0, inst_bne_0, inst_blt_0, inst_bge_0, inst_bltu_0, inst_bgeu_0,
          inst_jirl_0, inst_bl_0, inst_b_0,
          is_cpucfg_0, is_cacop_0, cacop_code_0,
          is_csr_0, is_csrxchg_0, csr_num_0} = dec_bus_0;

  wire [11:0] alu_op_1;
  wire [31:0] imm_1;
  wire [31:0] br_offs_1;
  wire [31:0] jirl_offs_1;
  wire [ 4:0] rf_raddr1_1;
  wire [ 4:0] rf_raddr2_1;
  wire [ 4:0] dest_1;
  wire        src1_is_pc_1;
  wire        src2_is_imm_1;
  wire        res_from_mem_1;
  wire        gr_we_1;
  wire        mem_we_1;
  wire        is_mul_1;
  wire        ld_byte_1;
  wire        ld_half_1;
  wire        ld_sign_ext_1;
  wire        st_byte_1;
  wire        st_half_1;
  wire        need_rj_1;
  wire        need_rkd_1;
  wire        is_bj_1;
  wire        inst_beq_1;
  wire        inst_bne_1;
  wire        inst_blt_1;
  wire        inst_bge_1;
  wire        inst_bltu_1;
  wire        inst_bgeu_1;
  wire        inst_jirl_1;
  wire        inst_bl_1;
  wire        inst_b_1;
  wire        is_cpucfg_1;
  wire        is_cacop_1;
  wire        is_csr_1;

  assign {alu_op_1, imm_1, br_offs_1, jirl_offs_1,
          rf_raddr1_1, rf_raddr2_1, dest_1,
          src1_is_pc_1, src2_is_imm_1, res_from_mem_1, gr_we_1, mem_we_1,
          is_mul_1,
          ld_byte_1, ld_half_1, ld_sign_ext_1, st_byte_1, st_half_1,
          need_rj_1, need_rkd_1, is_bj_1,
          inst_beq_1, inst_bne_1, inst_blt_1, inst_bge_1, inst_bltu_1, inst_bgeu_1,
          inst_jirl_1, inst_bl_1, inst_b_1} = dec_bus_1[`DS_DEC_BUS_WD-1:23];
  assign is_cpucfg_1 = dec_bus_1[22];
  assign is_cacop_1  = dec_bus_1[21];
  assign is_csr_1    = dec_bus_1[15];

  // InstBuffer 为四个源寄存器地址维护了独立的低扇出副本
  wire [4:0] src_raddr1_0 = front_raddr1_0_hot;
  wire [4:0] src_raddr2_0 = front_raddr2_0_hot;
  wire [4:0] src_raddr1_1 = front_raddr1_1_hot;
  wire [4:0] src_raddr2_1 = front_raddr2_1_hot;

  // 拆解前递总线
  wire        es_bus_valid_0;
  wire        es_bus_gr_we_0;
  wire        es_bus_fwd_valid_0;
  wire        es_bus_res_from_mem_0;
  wire [ 4:0] es_bus_dest_0;
  wire [31:0] es_fwd_data_0;

  wire        es_bus_valid_1;
  wire        es_bus_gr_we_1;
  wire        es_bus_fwd_valid_1;
  wire [ 4:0] es_bus_dest_1;
  wire [31:0] es_fwd_data_1;

  assign {es_bus_valid_0, es_bus_gr_we_0, es_bus_fwd_valid_0,
          es_bus_res_from_mem_0, es_bus_dest_0, es_fwd_data_0} = es_fwd_bus_0;
  assign {es_bus_valid_1, es_bus_gr_we_1, es_bus_fwd_valid_1,
          es_bus_dest_1, es_fwd_data_1} = es_fwd_bus_1;

  // EX hazard 元数据在 ISSUE 本地同步镜像。它与 EX 在同一时钟沿
  // 捕获同一个发射包，使 RAW 比较不再从 EX 跨区返回 InstBuffer；
  // 前递数据本身仍直接使用 EX 结果，因此零气泡 ALU 前递不变。
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg        es_valid_0;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg        es_gr_we_0;
  reg        es_fwd_valid_0;
  reg        es_res_from_mem_0;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg [4:0]  es_dest_0;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg        es_valid_1;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg        es_gr_we_1;
  reg        es_fwd_valid_1;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg [4:0]  es_dest_1;

  always @(posedge clk)
  begin
    if (!resetn || br_taken)
    begin
      es_valid_0        <= 1'b0;
      es_gr_we_0        <= 1'b0;
      es_fwd_valid_0    <= 1'b0;
      es_res_from_mem_0 <= 1'b0;
      es_dest_0         <= 5'b0;
      es_valid_1        <= 1'b0;
      es_gr_we_1        <= 1'b0;
      es_fwd_valid_1    <= 1'b0;
      es_dest_1         <= 5'b0;
    end
    else if (es_allowin)
    begin
      es_valid_0        <= ds_to_es_valid_0;
      es_gr_we_0        <= ds_to_es_valid_0 && gr_we_0;
      es_fwd_valid_0    <= ds_to_es_valid_0 && gr_we_0 &&
                           !res_from_mem_0 &&
                           !is_cpucfg_0 && !is_cacop_0 && !is_csr_0;
      es_res_from_mem_0 <= ds_to_es_valid_0 && res_from_mem_0;
      es_dest_0         <= dest_0;
      es_valid_1        <= ds_to_es_valid_1;
      es_gr_we_1        <= ds_to_es_valid_1 && gr_we_1;
      es_fwd_valid_1    <= ds_to_es_valid_1 && gr_we_1 &&
                           !res_from_mem_1;
      es_dest_1         <= dest_1;
    end
  end

  wire        ms_valid_0;
  wire        ms_gr_we_0;
  wire        ms_fwd_valid_0;
  wire        ms_res_from_mem_0;
  wire [ 4:0] ms_dest_0;
  wire [31:0] ms_fwd_data_0;

  wire        ms_valid_1;
  wire        ms_gr_we_1;
  wire        ms_fwd_valid_1;
  wire [ 4:0] ms_dest_1;
  wire [31:0] ms_fwd_data_1;

  assign {ms_valid_0, ms_gr_we_0, ms_fwd_valid_0,
          ms_res_from_mem_0, ms_dest_0, ms_fwd_data_0} = ms_fwd_bus_0;
  assign {ms_valid_1, ms_gr_we_1, ms_fwd_valid_1,
          ms_dest_1, ms_fwd_data_1} = ms_fwd_bus_1;

  (* keep = "true", equivalent_register_removal = "no" *)
  reg        ex_wait_valid_0;
  (* keep = "true", equivalent_register_removal = "no" *)
  reg [4:0]  ex_wait_dest_0;

  wire        ws_rf_we_0;
  wire [ 4:0] ws_rf_waddr_0;
  wire [31:0] ws_rf_wdata_0;

  wire        ws_rf_we_1;
  wire [ 4:0] ws_rf_waddr_1;
  wire [31:0] ws_rf_wdata_1;

  assign {ws_rf_we_0, ws_rf_waddr_0, ws_rf_wdata_0,
          ws_rf_we_1, ws_rf_waddr_1, ws_rf_wdata_1} = ws_to_rf_bus;

  wire [31:0] rf_rdata1_0;
  wire [31:0] rf_rdata2_0;
  wire [31:0] rf_rdata1_1;
  wire [31:0] rf_rdata2_1;

  regfile_4r2w u_regfile(
                 .clk    (clk),
                 .raddr1 (src_raddr1_0),
                 .rdata1 (rf_rdata1_0),
                 .raddr2 (src_raddr2_0),
                 .rdata2 (rf_rdata2_0),
                 .raddr3 (src_raddr1_1),
                 .rdata3 (rf_rdata1_1),
                 .raddr4 (src_raddr2_1),
                 .rdata4 (rf_rdata2_1),
                 .we0    (ws_rf_we_0),
                 .waddr0 (ws_rf_waddr_0),
                 .wdata0 (ws_rf_wdata_0),
                 .we1    (ws_rf_we_1),
                 .waddr1 (ws_rf_waddr_1),
                 .wdata1 (ws_rf_wdata_1)
               );

  // 指令是否需要 rj/rkd
  wire src0_rj_valid  = need_rj_0  && (src_raddr1_0 != 5'b0);
  wire src0_rkd_valid = need_rkd_0 && (src_raddr2_0 != 5'b0);
  wire src1_rj_valid  = need_rj_1  && (src_raddr1_1 != 5'b0);
  wire src1_rkd_valid = need_rkd_1 && (src_raddr2_1 != 5'b0);

  // 最小化的返回拍唤醒只覆盖 lane0 普通寄存器 ALU/乘法消费者。
  // 分支、访存地址、CSR/CACOP/CPUCFG 和 lane1 继续走原前递/等待路径。
  // 目的 tag 直接复用 ms_fwd_bus_0 中的 ms_dest_0，不增加 tag 线
  // 或比较器；现有 RAW 命中后只需再看这一位完成事件。
  wire load_wakeup_consumer_0 = gr_we_0 && !res_from_mem_0 &&
       !mem_we_0 && !is_bj_0 &&
       !(is_csr_0 || is_cacop_0 || is_cpucfg_0);
  wire load_wakeup_usable_0 =
       load_wakeup_valid && load_wakeup_consumer_0;

  // EXE MEM WB 前递数据检测
  // 第一条指令的前递检测
  wire rj0_hit_es0  = src0_rj_valid  && es_valid_0 && es_gr_we_0 && (es_dest_0 != 5'b0) && (es_dest_0 == src_raddr1_0);
  wire rj0_hit_es1  = src0_rj_valid  && es_valid_1 && es_gr_we_1 && (es_dest_1 != 5'b0) && (es_dest_1 == src_raddr1_0);

  wire rj0_hit_ms0  = src0_rj_valid  && ms_valid_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) && (ms_dest_0 == src_raddr1_0);
  wire rj0_hit_ms1  = src0_rj_valid  && ms_valid_1 && ms_gr_we_1 && (ms_dest_1 != 5'b0) && (ms_dest_1 == src_raddr1_0);

  wire rj0_wait_es1 = rj0_hit_es1 && !es_fwd_valid_1;
  wire rj0_wait_ms1 = rj0_hit_ms1 && !ms_fwd_valid_1;
  wire rj0_wait_ms0 =
       rj0_hit_ms0 && !ms_fwd_valid_0 && !load_wakeup_usable_0;
  wire rj0_wait_ex = src0_rj_valid &&
       ex_wait_valid_0 && (ex_wait_dest_0 == src_raddr1_0);
  wire rj0_wait =
       rj0_wait_es1 || rj0_wait_ex || rj0_wait_ms1 || rj0_wait_ms0;

  // 若有更年轻的 EX 或同包 lane1 生产者，仍按原年龄优先级取值，
  // 不允许较老的 Load 响应覆盖它。
  wire rj0_use_load_wakeup = load_wakeup_usable_0 && rj0_hit_ms0 &&
       !rj0_hit_es1 && !rj0_hit_es0 && !rj0_hit_ms1;

  // 年轻生产者优先。直接描述数据优先级，避免先生成一热选择量、
  // 再经 32 组 AND/OR 归并；后者会把 EX 算术前递到乘法器输入
  // 映射成更深的 LUT 链。
  wire [31:0] rj_value_0 =
       (rj0_hit_es1 && es_fwd_valid_1) ? es_fwd_data_1 :
       (rj0_hit_es0 && es_fwd_valid_0) ? es_fwd_data_0 :
       (rj0_hit_ms1 && ms_fwd_valid_1) ? ms_fwd_data_1 :
       (rj0_hit_ms0 && ms_fwd_valid_0) ? ms_fwd_data_0 :
                                         rf_rdata1_0;

  wire rkd0_hit_es0 = src0_rkd_valid && es_valid_0 && es_gr_we_0 && (es_dest_0 != 5'b0) && (es_dest_0 == src_raddr2_0);
  wire rkd0_hit_es1 = src0_rkd_valid && es_valid_1 && es_gr_we_1 && (es_dest_1 != 5'b0) && (es_dest_1 == src_raddr2_0);

  wire rkd0_hit_ms0 = src0_rkd_valid && ms_valid_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) && (ms_dest_0 == src_raddr2_0);
  wire rkd0_hit_ms1 = src0_rkd_valid && ms_valid_1 && ms_gr_we_1 && (ms_dest_1 != 5'b0) && (ms_dest_1 == src_raddr2_0);

  // 地址源和普通数据源仍在 ISSUE 等待；Store 写数据单独在下方判断，
  // 若生产者是 lane0 load，则携带源寄存器 tag 提前进入 EX。
  wire rkd0_wait_ex = src0_rkd_valid &&
       ex_wait_valid_0 && (ex_wait_dest_0 == src_raddr2_0);
  wire rkd0_wait_es1 = rkd0_hit_es1 && !es_fwd_valid_1;
  wire rkd0_wait_ms1 = rkd0_hit_ms1 && !ms_fwd_valid_1;
  wire rkd0_wait_ms0 =
       rkd0_hit_ms0 && !ms_fwd_valid_0 && !load_wakeup_usable_0;
  wire rkd0_wait =
       rkd0_wait_es1 || rkd0_wait_ex || rkd0_wait_ms1 || rkd0_wait_ms0;

  wire rkd0_use_load_wakeup = load_wakeup_usable_0 && rkd0_hit_ms0 &&
       !rkd0_hit_es1 && !rkd0_hit_es0 && !rkd0_hit_ms1;

  wire [31:0] rkd_value_0 =
       (rkd0_hit_es1 && es_fwd_valid_1) ? es_fwd_data_1 :
       (rkd0_hit_es0 && es_fwd_valid_0) ? es_fwd_data_0 :
       (rkd0_hit_ms1 && ms_fwd_valid_1) ? ms_fwd_data_1 :
       (rkd0_hit_ms0 && ms_fwd_valid_0) ? ms_fwd_data_0 :
                                          rf_rdata2_0;

  // 第二条指令的前递检测
  wire rj1_hit_es0  = src1_rj_valid  && es_valid_0 && es_gr_we_0 && (es_dest_0 != 5'b0) && (es_dest_0 == src_raddr1_1);
  wire rj1_hit_es1  = src1_rj_valid  && es_valid_1 && es_gr_we_1 && (es_dest_1 != 5'b0) && (es_dest_1 == src_raddr1_1);

  wire rj1_hit_ms0  = src1_rj_valid  && ms_valid_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) && (ms_dest_0 == src_raddr1_1);
  wire rj1_hit_ms1  = src1_rj_valid  && ms_valid_1 && ms_gr_we_1 && (ms_dest_1 != 5'b0) && (ms_dest_1 == src_raddr1_1);

  wire rj1_wait_es1 = rj1_hit_es1 && !es_fwd_valid_1;
  wire rj1_wait_ms1 = rj1_hit_ms1 && !ms_fwd_valid_1;
  wire rj1_wait_ms0 = rj1_hit_ms0 && !ms_fwd_valid_0;
  wire rj1_wait = src1_rj_valid &&
       (rj1_wait_es1 ||
        (ex_wait_valid_0 && (ex_wait_dest_0 == src_raddr1_1)) ||
        rj1_wait_ms1 || rj1_wait_ms0);
  wire [31:0] rj_value_1 =
       (rj1_hit_es1 && es_fwd_valid_1) ? es_fwd_data_1 :
       (rj1_hit_es0 && es_fwd_valid_0) ? es_fwd_data_0 :
       (rj1_hit_ms1 && ms_fwd_valid_1) ? ms_fwd_data_1 :
       (rj1_hit_ms0 && ms_fwd_valid_0) ? ms_fwd_data_0 :
                                         rf_rdata1_1;

  wire rkd1_hit_es0 = src1_rkd_valid && es_valid_0 && es_gr_we_0 && (es_dest_0 != 5'b0) && (es_dest_0 == src_raddr2_1);
  wire rkd1_hit_es1 = src1_rkd_valid && es_valid_1 && es_gr_we_1 && (es_dest_1 != 5'b0) && (es_dest_1 == src_raddr2_1);
  wire rkd1_hit_ms0 = src1_rkd_valid && ms_valid_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) && (ms_dest_0 == src_raddr2_1);
  wire rkd1_hit_ms1 = src1_rkd_valid && ms_valid_1 && ms_gr_we_1 && (ms_dest_1 != 5'b0) && (ms_dest_1 == src_raddr2_1);
  wire rkd1_wait_es1 = rkd1_hit_es1 && !es_fwd_valid_1;
  wire rkd1_wait_ms1 = rkd1_hit_ms1 && !ms_fwd_valid_1;
  wire rkd1_wait_ms0 = rkd1_hit_ms0 && !ms_fwd_valid_0;
  wire rkd1_wait = src1_rkd_valid &&
       (rkd1_wait_es1 ||
        (ex_wait_valid_0 && (ex_wait_dest_0 == src_raddr2_1)) ||
        rkd1_wait_ms1 || rkd1_wait_ms0);

  wire [31:0] rkd_value_1 =
       (rkd1_hit_es1 && es_fwd_valid_1) ? es_fwd_data_1 :
       (rkd1_hit_es0 && es_fwd_valid_0) ? es_fwd_data_0 :
       (rkd1_hit_ms1 && ms_fwd_valid_1) ? ms_fwd_data_1 :
       (rkd1_hit_ms0 && ms_fwd_valid_0) ? ms_fwd_data_0 :
                                          rf_rdata2_1;

  // EX 依赖的乘法已由 mul*_dep_es 停一拍，DSP 输入只需 MEM/RF
  // 前递；下一拍生产者已进入 MEM，从而物理切断无效的 EX->DSP 线。
  assign ds_mul_src1_0 =
       (rj0_hit_ms1 && ms_fwd_valid_1) ? ms_fwd_data_1 :
       (rj0_hit_ms0 && ms_fwd_valid_0) ? ms_fwd_data_0 : rf_rdata1_0;
  assign ds_mul_src2_0 =
       (rkd0_hit_ms1 && ms_fwd_valid_1) ? ms_fwd_data_1 :
       (rkd0_hit_ms0 && ms_fwd_valid_0) ? ms_fwd_data_0 : rf_rdata2_0;
  assign ds_mul_src1_1 =
       (rj1_hit_ms1 && ms_fwd_valid_1) ? ms_fwd_data_1 :
       (rj1_hit_ms0 && ms_fwd_valid_0) ? ms_fwd_data_0 : rf_rdata1_1;
  assign ds_mul_src2_1 =
       (rkd1_hit_ms1 && ms_fwd_valid_1) ? ms_fwd_data_1 :
       (rkd1_hit_ms0 && ms_fwd_valid_0) ? ms_fwd_data_0 : rf_rdata2_1;

  // Store 的地址源 rj 必须在 ISSUE 就绪；数据源 rkd 若只等待一个
  // lane0 load，则允许先进入 EX，稍后在 MEM 从该 load/WB 前递。
  // 对 CSR/CPUCFG/CACOP 等低频未就绪结果仍保持原有阻塞。
  wire rkd0_hard_wait = rkd0_wait_es1 || rkd0_wait_ms1;
  wire rkd0_late_wait = rkd0_wait_ex || rkd0_wait_ms0;
  wire rkd0_late_ok =
       mem_we_0 &&
       (rkd0_wait_ex ? es_res_from_mem_0 : ms_res_from_mem_0);
  wire store_data_late_0 =
       !rkd0_hard_wait && rkd0_late_wait && rkd0_late_ok;
  // EX 普通结果到下一拍乘法 DSP 是跨区长线。只对“乘法确实读取
  // 上一拍 EX 结果”这一小类 RAW 插入一拍，其他 ALU 前递仍保持
  // 零气泡；结果下一拍从 MEM 前递，切断 EX->DSP 路径。
  wire mul0_dep_es = is_mul_0 &&
       ((es_fwd_valid_1 && (rj0_hit_es1 || rkd0_hit_es1)) ||
        (es_fwd_valid_0 && (rj0_hit_es0 || rkd0_hit_es0)));
  wire mul1_dep_es = is_mul_1 &&
       ((es_fwd_valid_1 && (rj1_hit_es1 || rkd1_hit_es1)) ||
        (es_fwd_valid_0 && (rj1_hit_es0 || rkd1_hit_es0)));
  wire stall_0 =
       rj0_wait || rkd0_hard_wait ||
       (rkd0_late_wait && !rkd0_late_ok) || mul0_dep_es;
  wire stall_1 = rj1_wait || rkd1_wait || mul1_dep_es;

  wire raw_0_to_1 = gr_we_0 && (dest_0 != 5'b0) &&
       ((src1_rj_valid  && (dest_0 == src_raddr1_1)) ||
        (src1_rkd_valid && (dest_0 == src_raddr2_1)));  // 两条指令相互依赖

  wire src0_rj_valid_for_consume  = src0_rj_valid;
  wire src0_rkd_valid_for_consume = src0_rkd_valid;
  wire src1_rj_valid_for_consume  = src1_rj_valid;
  wire src1_rkd_valid_for_consume = src1_rkd_valid;

  // MEM 中未就绪的 load/低频结果只阻塞真正命中目的寄存器的源。
  // 使用 InstBuffer 的 hot 源寄存器字段保持 pop 控制路径窄，不再用
  // 任意一个未完成 load 全局关闭整个发射窗口。
  wire rj0_wait_es1_for_consume = src0_rj_valid_for_consume &&
       es_valid_1 && es_gr_we_1 && !es_fwd_valid_1 &&
       (es_dest_1 != 5'b0) && (es_dest_1 == src_raddr1_0);
  wire rkd0_wait_es1_for_consume = src0_rkd_valid_for_consume &&
       es_valid_1 && es_gr_we_1 && !es_fwd_valid_1 &&
       (es_dest_1 != 5'b0) && (es_dest_1 == src_raddr2_0);
  wire rj1_wait_es1_for_consume = src1_rj_valid_for_consume &&
       es_valid_1 && es_gr_we_1 && !es_fwd_valid_1 &&
       (es_dest_1 != 5'b0) && (es_dest_1 == src_raddr1_1);
  wire rkd1_wait_es1_for_consume = src1_rkd_valid_for_consume &&
       es_valid_1 && es_gr_we_1 && !es_fwd_valid_1 &&
       (es_dest_1 != 5'b0) && (es_dest_1 == src_raddr2_1);

  wire rj0_wait_ms0_for_consume = src0_rj_valid_for_consume &&
       ms_valid_0 && ms_gr_we_0 && !ms_fwd_valid_0 &&
       (ms_dest_0 != 5'b0) && (ms_dest_0 == src_raddr1_0) &&
       !load_wakeup_usable_0;
  wire rj0_wait_ms1_for_consume = src0_rj_valid_for_consume &&
       ms_valid_1 && ms_gr_we_1 && !ms_fwd_valid_1 &&
       (ms_dest_1 != 5'b0) && (ms_dest_1 == src_raddr1_0);
  wire rkd0_wait_ms0_for_consume = src0_rkd_valid_for_consume &&
       ms_valid_0 && ms_gr_we_0 && !ms_fwd_valid_0 &&
       (ms_dest_0 != 5'b0) && (ms_dest_0 == src_raddr2_0) &&
       !load_wakeup_usable_0;
  wire rkd0_wait_ms1_for_consume = src0_rkd_valid_for_consume &&
       ms_valid_1 && ms_gr_we_1 && !ms_fwd_valid_1 &&
       (ms_dest_1 != 5'b0) && (ms_dest_1 == src_raddr2_0);
  wire rj1_wait_ms0_for_consume = src1_rj_valid_for_consume &&
       ms_valid_0 && ms_gr_we_0 && !ms_fwd_valid_0 &&
       (ms_dest_0 != 5'b0) && (ms_dest_0 == src_raddr1_1);
  wire rj1_wait_ms1_for_consume = src1_rj_valid_for_consume &&
       ms_valid_1 && ms_gr_we_1 && !ms_fwd_valid_1 &&
       (ms_dest_1 != 5'b0) && (ms_dest_1 == src_raddr1_1);
  wire rkd1_wait_ms0_for_consume = src1_rkd_valid_for_consume &&
       ms_valid_0 && ms_gr_we_0 && !ms_fwd_valid_0 &&
       (ms_dest_0 != 5'b0) && (ms_dest_0 == src_raddr2_1);
  wire rkd1_wait_ms1_for_consume = src1_rkd_valid_for_consume &&
       ms_valid_1 && ms_gr_we_1 && !ms_fwd_valid_1 &&
       (ms_dest_1 != 5'b0) && (ms_dest_1 == src_raddr2_1);

  wire rj0_wait_ms_for_consume =
       rj0_wait_ms1_for_consume || rj0_wait_ms0_for_consume;
  wire rkd0_wait_ms_for_consume =
       rkd0_wait_ms1_for_consume || rkd0_wait_ms0_for_consume;
  wire rj1_wait_ms_for_consume =
       rj1_wait_ms1_for_consume || rj1_wait_ms0_for_consume;
  wire rkd1_wait_ms_for_consume =
       rkd1_wait_ms1_for_consume || rkd1_wait_ms0_for_consume;

  wire rj0_wait_ex_for_consume = src0_rj_valid_for_consume &&
       ex_wait_valid_0 && (ex_wait_dest_0 == src_raddr1_0);
  wire rj0_wait_for_consume =
       rj0_wait_es1_for_consume || rj0_wait_ex_for_consume ||
       rj0_wait_ms0_for_consume || rj0_wait_ms1_for_consume;
  wire rkd0_wait_ex_for_consume = src0_rkd_valid_for_consume &&
       ex_wait_valid_0 && (ex_wait_dest_0 == src_raddr2_0);
  wire rkd0_wait_for_consume =
       rkd0_wait_es1_for_consume || rkd0_wait_ex_for_consume ||
       rkd0_wait_ms0_for_consume || rkd0_wait_ms1_for_consume;
  wire rj1_wait_for_consume = src1_rj_valid_for_consume &&
       (rj1_wait_es1_for_consume ||
        (ex_wait_valid_0 && (ex_wait_dest_0 == src_raddr1_1)) ||
        rj1_wait_ms_for_consume);
  wire rkd1_wait_for_consume = src1_rkd_valid_for_consume &&
       (rkd1_wait_es1_for_consume ||
        (ex_wait_valid_0 && (ex_wait_dest_0 == src_raddr2_1)) ||
        rkd1_wait_ms_for_consume);

  wire rkd0_hard_wait_for_consume =
       rkd0_wait_es1_for_consume || rkd0_wait_ms1_for_consume;
  wire rkd0_late_wait_for_consume =
       rkd0_wait_ex_for_consume || rkd0_wait_ms0_for_consume;
  wire rkd0_late_ok_for_consume =
       mem_we_0 &&
       (rkd0_wait_ex_for_consume ?
        es_res_from_mem_0 : ms_res_from_mem_0);
  wire store_data_late_0_for_consume =
       !rkd0_hard_wait_for_consume &&
       rkd0_late_wait_for_consume && rkd0_late_ok_for_consume;
  wire mul0_dep_es_for_consume = is_mul_0 &&
       ((es_fwd_valid_1 &&
         ((src0_rj_valid_for_consume && rj0_hit_es1) ||
          (src0_rkd_valid_for_consume && rkd0_hit_es1))) ||
        (es_fwd_valid_0 &&
         ((src0_rj_valid_for_consume && rj0_hit_es0) ||
          (src0_rkd_valid_for_consume && rkd0_hit_es0))));
  wire mul1_dep_es_for_consume = is_mul_1 &&
       ((es_fwd_valid_1 &&
         ((src1_rj_valid_for_consume && rj1_hit_es1) ||
          (src1_rkd_valid_for_consume && rkd1_hit_es1))) ||
        (es_fwd_valid_0 &&
         ((src1_rj_valid_for_consume && rj1_hit_es0) ||
          (src1_rkd_valid_for_consume && rkd1_hit_es0))));
  (* keep = "true" *) wire stall_0_for_consume =
       rj0_wait_for_consume ||
       rkd0_hard_wait_for_consume ||
       (rkd0_late_wait_for_consume && !rkd0_late_ok_for_consume) ||
       mul0_dep_es_for_consume;
  (* keep = "true" *) wire stall_1_for_consume =
       rj1_wait_for_consume || rkd1_wait_for_consume ||
       mul1_dep_es_for_consume;
  wire ms_stall_0_for_consume =
       rj0_wait_ms_for_consume || rkd0_wait_ms_for_consume;
  wire blocking_ms_stall_0_for_consume =
       rj0_wait_ms_for_consume ||
       (rkd0_wait_ms_for_consume && !store_data_late_0_for_consume);
  wire ms_stall_1_for_consume =
       rj1_wait_ms_for_consume || rkd1_wait_ms_for_consume;
  wire raw_0_to_1_for_consume = gr_we_0 && (dest_0 != 5'b0) &&
       ((src1_rj_valid_for_consume &&
         (dest_0 == src_raddr1_1)) ||
        (src1_rkd_valid_for_consume &&
         (dest_0 == src_raddr2_1)));

  wire mem_op_0 = res_from_mem_0 || mem_we_0;
  wire mem_op_1 = res_from_mem_1 || mem_we_1;
  wire special_0 = is_csr_0 || is_cacop_0 || is_cpucfg_0;
  wire special_1 = is_csr_1 || is_cacop_1 || is_cpucfg_1;
  wire lane1_regular_alu = gr_we_1 && !is_bj_1 &&
       !mem_op_1 && !is_mul_1 && !special_1;
  wire lane1_simple_branch = is_bj_1 && !inst_jirl_1 && !inst_bl_1;
  // lane1 乘法只允许 MUL+MUL；lane0 乘法还可带一条普通 lane1 ALU。
  // 两种乘法包的等待与完成都由 lane0 的整包控制统一管理。
  wire mul_pair = is_mul_0 && is_mul_1;
  wire lane1_capable =
       mem_op_1 ||
       lane1_regular_alu ||
       (!is_mul_0 && lane1_simple_branch) ||
       mul_pair;

  wire issue_window_open = es_allowin;

  (* keep = "true", max_fanout = 16 *) wire issue0_fire_for_ex =
  issue_window_open && !br_taken && front_valid_0 && !stall_0 && !special_block;
  (* keep = "true", max_fanout = 16 *) wire issue1_fire_for_ex =
  issue_window_open && !br_taken &&
                    front_valid_0 && !stall_0 && !special_block &&
                    front_valid_1 && !stall_1 && !raw_0_to_1 &&
                    lane1_capable && !(is_bj_0 && is_bj_1) &&
                    !special_0;
  (* max_fanout = 16 *) wire issue0_fire_for_consume =
  issue_window_open && !br_taken &&
                    front_valid_0 && !stall_0_for_consume && !special_block;
  (* max_fanout = 16 *) wire issue1_fire_for_consume =
  issue_window_open && !br_taken &&
                    front_valid_0 && !stall_0_for_consume && !special_block &&
                    front_valid_1 && !stall_1_for_consume &&
                    !raw_0_to_1_for_consume &&
                    lane1_capable && !(is_bj_0 && is_bj_1) &&
                    !special_0;

  assign ds_to_es_valid_0 = issue0_fire_for_ex;
  assign ds_to_es_valid_1 = issue1_fire_for_ex;
  assign pop_0            = issue0_fire_for_consume;
  assign pop_1            = issue1_fire_for_consume;
  // CPUCFG 只需单发，但不改变机器状态，不占用全局特殊指令
  // scoreboard。CSR/CACOP 则一直阻止年轻指令直到它们的 flush。
  assign special_fire = ds_to_es_valid_0 && (is_csr_0 || is_cacop_0);

  wire capture_ex_wait_0 = ds_to_es_valid_0 && gr_we_0 &&
       (dest_0 != 5'b0) &&
       (res_from_mem_0 || is_cpucfg_0 || is_csr_0 || is_cacop_0);
  always @(posedge clk)
  begin
    if (!resetn || br_taken)
    begin
      ex_wait_valid_0 <= 1'b0;
      ex_wait_dest_0  <= 5'b0;
    end
    else if (es_allowin)
    begin
      ex_wait_valid_0 <= capture_ex_wait_0;
      ex_wait_dest_0  <= capture_ex_wait_0 ? dest_0 : 5'b0;
    end
  end

  `ifndef SYNTHESIS
          always @(posedge clk)
          begin
            if (resetn)
            begin
              if (front_valid_0 &&
                  ((front_raddr1_0_hot !== rf_raddr1_0) ||
                   (front_raddr2_0_hot !== rf_raddr2_0)))
                $fatal(1, "lane0 IBuffer hot fields lost synchronization");
              if (front_valid_1 &&
                  ((front_raddr1_1_hot !== rf_raddr1_1) ||
                   (front_raddr2_1_hot !== rf_raddr2_1)))
                $fatal(1, "lane1 IBuffer hot fields lost synchronization");
              if ((pop_0 !== ds_to_es_valid_0) ||
                  (pop_1 !== ds_to_es_valid_1))
                $fatal(1, "IBuffer consume and EX issue controls diverged");
              if (es_allowin && !br_taken &&
                  ((ex_wait_valid_0 !==
                    (es_valid_0 && es_gr_we_0 && !es_fwd_valid_0 &&
                     (es_dest_0 != 5'b0))) ||
                   (ex_wait_valid_0 && (ex_wait_dest_0 !== es_dest_0))))
                $fatal(1,
                       "ISSUE local EX wait mirror lost synchronization local=%b/%0d es=%b/%b/%b/%0d",
                       ex_wait_valid_0, ex_wait_dest_0,
                       es_valid_0, es_gr_we_0, es_fwd_valid_0, es_dest_0);
              if (ds_to_es_valid_1 && !lane1_capable)
                $fatal(1, "unsupported instruction issued on lane1");
              if (ds_to_es_valid_1 &&
                  (special_1 || inst_jirl_1 || inst_bl_1))
                $fatal(1, "lane1 issued a forbidden side-effect class");
              if (ds_to_es_valid_1 && is_mul_1 && !is_mul_0)
                $fatal(1, "lane1 multiply issued without lane0 multiply");
              if (blocking_ms_stall_0_for_consume &&
                  (ds_to_es_valid_0 || pop_0))
                $fatal(1, "unfinished MEM producer allowed dependent lane0");
              if (ms_stall_1_for_consume &&
                  (ds_to_es_valid_1 || pop_1))
                $fatal(1, "unfinished MEM producer allowed dependent lane1");
              if (ds_to_es_valid_0 && rj0_use_load_wakeup &&
                  (!load_wakeup_valid || rj0_hit_es1 ||
                   rj0_hit_es0 || rj0_hit_ms1))
                $fatal(1, "lane0 rj selected an invalid/older load wakeup");
              if (ds_to_es_valid_0 && rkd0_use_load_wakeup &&
                  (!load_wakeup_valid || rkd0_hit_es1 ||
                   rkd0_hit_es0 || rkd0_hit_ms1))
                $fatal(1, "lane0 rkd selected an invalid/older load wakeup");
            end
          end
`endif

          wire [31:0] ds_alu_src1_0 = src1_is_pc_0  ? ds_pc_0 : rj_value_0;
  wire [31:0] ds_alu_src2_0 = src2_is_imm_0 ? imm_0   : rkd_value_0;
  wire [31:0] ds_rkd_value_0 = inst_jirl_0 ? rj_value_0 : rkd_value_0;

  wire [31:0] ds_alu_src1_1 = src1_is_pc_1  ? ds_pc_1 : rj_value_1;
  wire [31:0] ds_alu_src2_1 = src2_is_imm_1 ? imm_1   : rkd_value_1;
  wire [31:0] ds_rkd_value_1 = inst_jirl_1 ? rj_value_1 : rkd_value_1;

  function [3:0] make_br_op;
    input inst_beq;
    input inst_bne;
    input inst_blt;
    input inst_bge;
    input inst_bltu;
    input inst_bgeu;
    input inst_jirl;
    input inst_bl;
    input inst_b;
    begin
      make_br_op =
        inst_beq  ? `BR_BEQ  :
        inst_bne  ? `BR_BNE  :
        inst_blt  ? `BR_BLT  :
        inst_bge  ? `BR_BGE  :
        inst_bltu ? `BR_BLTU :
        inst_bgeu ? `BR_BGEU :
        inst_jirl ? `BR_JIRL :
        inst_bl   ? `BR_BL   :
        inst_b    ? `BR_B    :
        `BR_NONE;
    end
  endfunction

  wire [ 3:0] ds_br_op_0   = make_br_op(inst_beq_0, inst_bne_0, inst_blt_0, inst_bge_0,
                                        inst_bltu_0, inst_bgeu_0, inst_jirl_0, inst_bl_0, inst_b_0);
  wire [31:0] ds_br_offs_0 = inst_jirl_0 ? jirl_offs_0 : br_offs_0;

  wire [ 3:0] ds_br_op_1   = make_br_op(inst_beq_1, inst_bne_1, inst_blt_1, inst_bge_1,
                                        inst_bltu_1, inst_bgeu_1, inst_jirl_1, inst_bl_1, inst_b_1);
  wire [31:0] ds_br_offs_1 = inst_jirl_1 ? jirl_offs_1 : br_offs_1;

  assign ds_to_es_bus_0 = {store_data_late_0,
                           src_raddr2_0,
                           ds_pc_0,
                           alu_op_0,
                           ds_alu_src1_0,
                           ds_alu_src2_0,
                           ds_rkd_value_0,
                           res_from_mem_0,
                           gr_we_0,
                           mem_we_0,
                           dest_0,
                           is_mul_0,
                           ld_byte_0,
                           ld_half_0,
                           ld_sign_ext_0,
                           st_byte_0,
                           st_half_0,
                           ds_pred_taken_0,
                           ds_pred_target_0,
                           ds_br_op_0,
                           ds_br_offs_0,
                           is_cpucfg_0,
                           is_cacop_0,
                           cacop_code_0,
                           is_csr_0,
                           is_csrxchg_0,
                           csr_num_0,
                           rj0_use_load_wakeup,
                           rkd0_use_load_wakeup
                          };

  assign ds_to_es_bus_1 = {ds_pc_1,
                           alu_op_1,
                           ds_alu_src1_1,
                           ds_alu_src2_1,
                           ds_rkd_value_1,
                           res_from_mem_1,
                           gr_we_1,
                           mem_we_1,
                           dest_1,
                           is_mul_1,
                           ld_byte_1,
                           ld_half_1,
                           ld_sign_ext_1,
                           st_byte_1,
                           st_half_1,
                           ds_pred_taken_1,
                           ds_pred_target_1,
                           ds_br_op_1,
                           ds_br_offs_1
                          };

endmodule
