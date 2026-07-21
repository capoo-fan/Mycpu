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
    input  wire [`ES_FWD_BUS_WD-1  :  0]  es_fwd_bus_1,
    input  wire [`MS_FWD_BUS_WD-1  :  0]  ms_fwd_bus_0,
    input  wire [`MS_FWD_BUS_WD-1  :  0]  ms_fwd_bus_1,
    input  wire [`WS_TO_RF_BUS_WD-1:  0]  ws_to_rf_bus,
    // 送到 ES 阶段的信息
    output wire                           ds_to_es_valid_0,
    output wire                           ds_to_es_valid_1,
    output wire [`DS_TO_ES_BUS_WD-1:  0]  ds_to_es_bus_0,
    output wire [`DS_TO_ES_BUS_WD-1:  0]  ds_to_es_bus_1
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
  wire        mul_signed_0;
  wire        mul_hi_0;
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
          is_mul_0, mul_signed_0, mul_hi_0,
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
  wire        mul_signed_1;
  wire        mul_hi_1;
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
  wire [ 4:0] cacop_code_1;
  wire        is_csr_1;
  wire        is_csrxchg_1;
  wire [13:0] csr_num_1;

  assign {alu_op_1, imm_1, br_offs_1, jirl_offs_1,
          rf_raddr1_1, rf_raddr2_1, dest_1,
          src1_is_pc_1, src2_is_imm_1, res_from_mem_1, gr_we_1, mem_we_1,
          is_mul_1, mul_signed_1, mul_hi_1,
          ld_byte_1, ld_half_1, ld_sign_ext_1, st_byte_1, st_half_1,
          need_rj_1, need_rkd_1, is_bj_1,
          inst_beq_1, inst_bne_1, inst_blt_1, inst_bge_1, inst_bltu_1, inst_bgeu_1,
          inst_jirl_1, inst_bl_1, inst_b_1,
          is_cpucfg_1, is_cacop_1, cacop_code_1,
          is_csr_1, is_csrxchg_1, csr_num_1} = dec_bus_1;

  // 拆解前递总线
  wire        es_valid_0;
  wire        es_gr_we_0;
  wire        es_fwd_valid_0;
  wire        es_res_from_mem_0;
  wire [ 4:0] es_dest_0;
  wire [31:0] es_fwd_data_0;

  wire        es_valid_1;
  wire        es_gr_we_1;
  wire        es_fwd_valid_1;
  wire        es_res_from_mem_1;
  wire [ 4:0] es_dest_1;
  wire [31:0] es_fwd_data_1;

  assign {es_valid_0, es_gr_we_0, es_fwd_valid_0,
          es_res_from_mem_0, es_dest_0, es_fwd_data_0} = es_fwd_bus_0;
  assign {es_valid_1, es_gr_we_1, es_fwd_valid_1,
          es_res_from_mem_1, es_dest_1, es_fwd_data_1} = es_fwd_bus_1;

  wire        ms_valid_0;
  wire        ms_gr_we_0;
  wire        ms_fwd_valid_0;
  wire        ms_res_from_mem_0;
  wire [ 4:0] ms_dest_0;
  wire [31:0] ms_fwd_data_0;

  wire        ms_valid_1;
  wire        ms_gr_we_1;
  wire        ms_fwd_valid_1;
  wire        ms_res_from_mem_1;
  wire [ 4:0] ms_dest_1;
  wire [31:0] ms_fwd_data_1;

  assign {ms_valid_0, ms_gr_we_0, ms_fwd_valid_0,
          ms_res_from_mem_0, ms_dest_0, ms_fwd_data_0} = ms_fwd_bus_0;
  assign {ms_valid_1, ms_gr_we_1, ms_fwd_valid_1,
          ms_res_from_mem_1, ms_dest_1, ms_fwd_data_1} = ms_fwd_bus_1;

  wire ms_unready_load =
       (ms_valid_0 && ms_gr_we_0 && !ms_fwd_valid_0) ||
       (ms_valid_1 && ms_gr_we_1 && !ms_fwd_valid_1);

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
                 .raddr1 (rf_raddr1_0),
                 .rdata1 (rf_rdata1_0),
                 .raddr2 (rf_raddr2_0),
                 .rdata2 (rf_rdata2_0),
                 .raddr3 (rf_raddr1_1),
                 .rdata3 (rf_rdata1_1),
                 .raddr4 (rf_raddr2_1),
                 .rdata4 (rf_rdata2_1),
                 .we0    (ws_rf_we_0),
                 .waddr0 (ws_rf_waddr_0),
                 .wdata0 (ws_rf_wdata_0),
                 .we1    (ws_rf_we_1),
                 .waddr1 (ws_rf_waddr_1),
                 .wdata1 (ws_rf_wdata_1)
               );

  // 指令是否需要 rj/rkd
  wire src0_rj_valid  = need_rj_0  && (rf_raddr1_0 != 5'b0);
  wire src0_rkd_valid = need_rkd_0 && (rf_raddr2_0 != 5'b0);
  wire src1_rj_valid  = need_rj_1  && (rf_raddr1_1 != 5'b0);
  wire src1_rkd_valid = need_rkd_1 && (rf_raddr2_1 != 5'b0);

  function [4:0] make_fwd_sel;
    input hit_es1_ready;
    input hit_es0_ready;
    input hit_ms1_ready;
    input hit_ms0_ready;
    begin
      make_fwd_sel[4] = hit_es1_ready;
      make_fwd_sel[3] = !hit_es1_ready && hit_es0_ready;
      make_fwd_sel[2] = !(hit_es1_ready || hit_es0_ready) && hit_ms1_ready;
      make_fwd_sel[1] = !(hit_es1_ready || hit_es0_ready || hit_ms1_ready) && hit_ms0_ready;
      make_fwd_sel[0] = !(hit_es1_ready || hit_es0_ready || hit_ms1_ready || hit_ms0_ready);
    end
  endfunction

  function [31:0] select_fwd_data;
    input [4:0]  sel;
    input [31:0] es1_data;
    input [31:0] es0_data;
    input [31:0] ms1_data;
    input [31:0] ms0_data;
    input [31:0] rf_data;
    begin
      select_fwd_data = ({32{sel[4]}} & es1_data) |
                      ({32{sel[3]}} & es0_data) |
                      ({32{sel[2]}} & ms1_data) |
                      ({32{sel[1]}} & ms0_data) |
                      ({32{sel[0]}} & rf_data);
    end
  endfunction

  // EXE MEM WB 前递数据检测
  // 第一条指令的前递检测
  wire rj0_hit_es0  = src0_rj_valid  && es_valid_0 && es_gr_we_0 && (es_dest_0 != 5'b0) && (es_dest_0 == rf_raddr1_0);
  wire rj0_hit_es1  = src0_rj_valid  && es_valid_1 && es_gr_we_1 && (es_dest_1 != 5'b0) && (es_dest_1 == rf_raddr1_0);

  wire rj0_hit_ms0  = src0_rj_valid  && ms_valid_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) && (ms_dest_0 == rf_raddr1_0);
  wire rj0_hit_ms1  = src0_rj_valid  && ms_valid_1 && ms_gr_we_1 && (ms_dest_1 != 5'b0) && (ms_dest_1 == rf_raddr1_0);

  wire rj0_wait = (rj0_hit_es1 && !es_fwd_valid_1) ||
       (rj0_hit_es0 && !es_fwd_valid_0);

  wire [4:0] rj0_fwd_sel = make_fwd_sel(rj0_hit_es1 && es_fwd_valid_1,
                                        rj0_hit_es0 && es_fwd_valid_0,
                                        rj0_hit_ms1 && ms_fwd_valid_1,
                                        rj0_hit_ms0 && ms_fwd_valid_0);
  wire [31:0] rj_value_0 = select_fwd_data(rj0_fwd_sel,
       es_fwd_data_1, es_fwd_data_0,
       ms_fwd_data_1, ms_fwd_data_0,
       rf_rdata1_0);

  wire rkd0_hit_es0 = src0_rkd_valid && es_valid_0 && es_gr_we_0 && (es_dest_0 != 5'b0) && (es_dest_0 == rf_raddr2_0);
  wire rkd0_hit_es1 = src0_rkd_valid && es_valid_1 && es_gr_we_1 && (es_dest_1 != 5'b0) && (es_dest_1 == rf_raddr2_0);

  wire rkd0_hit_ms0 = src0_rkd_valid && ms_valid_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) && (ms_dest_0 == rf_raddr2_0);
  wire rkd0_hit_ms1 = src0_rkd_valid && ms_valid_1 && ms_gr_we_1 && (ms_dest_1 != 5'b0) && (ms_dest_1 == rf_raddr2_0);

  // 保守地对所有 EX load-use 相关插入气泡，包括 Load->Store 写数据。
  // 这避免把 Store 类型和生产者类型接入 pop 控制，缩短
  // InstBuffer hot tag -> ISSUE pop -> InstBuffer payload 的组合路径。
  wire rkd0_wait = (rkd0_hit_es1 && !es_fwd_valid_1) ||
       (rkd0_hit_es0 && !es_fwd_valid_0);

  wire [4:0] rkd0_fwd_sel = make_fwd_sel(rkd0_hit_es1 && es_fwd_valid_1,
                                         rkd0_hit_es0 && es_fwd_valid_0,
                                         rkd0_hit_ms1 && ms_fwd_valid_1,
                                         rkd0_hit_ms0 && ms_fwd_valid_0);
  wire [31:0] rkd_value_0 = select_fwd_data(rkd0_fwd_sel,
       es_fwd_data_1, es_fwd_data_0,
       ms_fwd_data_1, ms_fwd_data_0,
       rf_rdata2_0);

  // 第二条指令的前递检测
  wire rj1_hit_es0  = src1_rj_valid  && es_valid_0 && es_gr_we_0 && (es_dest_0 != 5'b0) && (es_dest_0 == rf_raddr1_1);
  wire rj1_hit_es1  = src1_rj_valid  && es_valid_1 && es_gr_we_1 && (es_dest_1 != 5'b0) && (es_dest_1 == rf_raddr1_1);

  wire rj1_hit_ms0  = src1_rj_valid  && ms_valid_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) && (ms_dest_0 == rf_raddr1_1);
  wire rj1_hit_ms1  = src1_rj_valid  && ms_valid_1 && ms_gr_we_1 && (ms_dest_1 != 5'b0) && (ms_dest_1 == rf_raddr1_1);

  wire rj1_wait = (rj1_hit_es1 && !es_fwd_valid_1) ||
       (rj1_hit_es0 && !es_fwd_valid_0);
  wire [4:0] rj1_fwd_sel = make_fwd_sel(rj1_hit_es1 && es_fwd_valid_1,
                                        rj1_hit_es0 && es_fwd_valid_0,
                                        rj1_hit_ms1 && ms_fwd_valid_1,
                                        rj1_hit_ms0 && ms_fwd_valid_0);
  wire [31:0] rj_value_1 = select_fwd_data(rj1_fwd_sel,
       es_fwd_data_1, es_fwd_data_0,
       ms_fwd_data_1, ms_fwd_data_0,
       rf_rdata1_1);

  wire rkd1_hit_es0 = src1_rkd_valid && es_valid_0 && es_gr_we_0 && (es_dest_0 != 5'b0) && (es_dest_0 == rf_raddr2_1);
  wire rkd1_hit_es1 = src1_rkd_valid && es_valid_1 && es_gr_we_1 && (es_dest_1 != 5'b0) && (es_dest_1 == rf_raddr2_1);
  wire rkd1_hit_ms0 = src1_rkd_valid && ms_valid_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) && (ms_dest_0 == rf_raddr2_1);
  wire rkd1_hit_ms1 = src1_rkd_valid && ms_valid_1 && ms_gr_we_1 && (ms_dest_1 != 5'b0) && (ms_dest_1 == rf_raddr2_1);
  wire rkd1_wait = (rkd1_hit_es1 && !es_fwd_valid_1) ||
       (rkd1_hit_es0 && !es_fwd_valid_0);

  wire [4:0] rkd1_fwd_sel = make_fwd_sel(rkd1_hit_es1 && es_fwd_valid_1,
                                         rkd1_hit_es0 && es_fwd_valid_0,
                                         rkd1_hit_ms1 && ms_fwd_valid_1,
                                         rkd1_hit_ms0 && ms_fwd_valid_0);
  wire [31:0] rkd_value_1 = select_fwd_data(rkd1_fwd_sel,
       es_fwd_data_1, es_fwd_data_0,
       ms_fwd_data_1, ms_fwd_data_0,
       rf_rdata2_1);

  wire stall_0 = rj0_wait || rkd0_wait;
  wire stall_1 = rj1_wait || rkd1_wait;

  wire raw_0_to_1 = gr_we_0 && (dest_0 != 5'b0) &&
       ((src1_rj_valid  && (dest_0 == rf_raddr1_1)) ||
        (src1_rkd_valid && (dest_0 == rf_raddr2_1)));  // 两条指令相互依赖

  wire src0_rj_valid_for_consume =
       need_rj_0 && (front_raddr1_0_hot != 5'b0);
  wire src0_rkd_valid_for_consume =
       need_rkd_0 && (front_raddr2_0_hot != 5'b0);
  wire src1_rj_valid_for_consume =
       need_rj_1 && (front_raddr1_1_hot != 5'b0);
  wire src1_rkd_valid_for_consume =
       need_rkd_1 && (front_raddr2_1_hot != 5'b0);

  wire rj0_wait_for_consume = src0_rj_valid_for_consume &&
       ((es_valid_0 && es_gr_we_0 && !es_fwd_valid_0 &&
         (es_dest_0 == front_raddr1_0_hot)) ||
        (es_valid_1 && es_gr_we_1 && !es_fwd_valid_1 &&
         (es_dest_1 == front_raddr1_0_hot)));
  wire rkd0_wait_for_consume = src0_rkd_valid_for_consume &&
       ((es_valid_0 && es_gr_we_0 && !es_fwd_valid_0 &&
         (es_dest_0 == front_raddr2_0_hot)) ||
        (es_valid_1 && es_gr_we_1 && !es_fwd_valid_1 &&
         (es_dest_1 == front_raddr2_0_hot)));
  wire rj1_wait_for_consume = src1_rj_valid_for_consume &&
       ((es_valid_0 && es_gr_we_0 && !es_fwd_valid_0 &&
         (es_dest_0 == front_raddr1_1_hot)) ||
        (es_valid_1 && es_gr_we_1 && !es_fwd_valid_1 &&
         (es_dest_1 == front_raddr1_1_hot)));
  wire rkd1_wait_for_consume = src1_rkd_valid_for_consume &&
       ((es_valid_0 && es_gr_we_0 && !es_fwd_valid_0 &&
         (es_dest_0 == front_raddr2_1_hot)) ||
        (es_valid_1 && es_gr_we_1 && !es_fwd_valid_1 &&
         (es_dest_1 == front_raddr2_1_hot)));

  (* keep = "true" *) wire stall_0_for_consume =
  rj0_wait_for_consume || rkd0_wait_for_consume;
  (* keep = "true" *) wire stall_1_for_consume =
  rj1_wait_for_consume || rkd1_wait_for_consume;
  wire raw_0_to_1_for_consume = gr_we_0 && (dest_0 != 5'b0) &&
       ((src1_rj_valid_for_consume &&
         (dest_0 == front_raddr1_1_hot)) ||
        (src1_rkd_valid_for_consume &&
         (dest_0 == front_raddr2_1_hot)));

  wire mem_op_0 = res_from_mem_0 || mem_we_0;
  wire mem_op_1 = res_from_mem_1 || mem_we_1;
  wire special_0 = is_csr_0 || is_cacop_0 || is_cpucfg_0;
  wire special_1 = is_csr_1 || is_cacop_1 || is_cpucfg_1;

  wire issue_window_open = es_allowin && !ms_unready_load;

  (* keep = "true", max_fanout = 16 *) wire issue0_fire_for_ex =
  issue_window_open && !br_taken && front_valid_0 && !stall_0 && !special_block;
  (* keep = "true", max_fanout = 16 *) wire issue1_fire_for_ex =
  issue_window_open && !br_taken &&
                    front_valid_0 && !stall_0 && !special_block &&
                    front_valid_1 && !stall_1 && !raw_0_to_1 &&
                    !(mem_op_0 && mem_op_1) && !(is_bj_0 && is_bj_1) &&
                    !special_0 && !special_1;
  (* keep = "true", max_fanout = 16 *) wire issue0_fire_for_consume =
  issue_window_open && !br_taken &&
                    front_valid_0 && !stall_0_for_consume && !special_block;
  (* keep = "true", max_fanout = 16 *) wire issue1_fire_for_consume =
  issue_window_open && !br_taken &&
                    front_valid_0 && !stall_0_for_consume && !special_block &&
                    front_valid_1 && !stall_1_for_consume &&
                    !raw_0_to_1_for_consume &&
                    !(mem_op_0 && mem_op_1) && !(is_bj_0 && is_bj_1) &&
                    !special_0 && !special_1;

  assign ds_to_es_valid_0 = issue0_fire_for_ex;
  assign ds_to_es_valid_1 = issue1_fire_for_ex;
  assign pop_0            = issue0_fire_for_consume;
  assign pop_1            = issue1_fire_for_consume;
  // CPUCFG 只需单发，但不改变机器状态，不占用全局特殊指令
  // scoreboard。CSR/CACOP 则一直阻止年轻指令直到它们的 flush。
  assign special_fire = ds_to_es_valid_0 && (is_csr_0 || is_cacop_0);

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
              if (ms_unready_load &&
                  (ds_to_es_valid_0 || ds_to_es_valid_1 || pop_0 || pop_1))
                $fatal(1, "unfinished MEM load allowed a younger issue");
            end
          end
`endif

          wire [31:0] ds_alu_src1_0 = src1_is_pc_0  ? ds_pc_0 : rj_value_0;
  wire [31:0] ds_alu_src2_0 = src2_is_imm_0 ? imm_0   : rkd_value_0;
  wire [31:0] ds_rkd_value_0 = inst_jirl_0 ? rj_value_0 : rkd_value_0;

  wire [31:0] ds_alu_src1_1 = src1_is_pc_1  ? ds_pc_1 : rj_value_1;
  wire [31:0] ds_alu_src2_1 = src2_is_imm_1 ? imm_1   : rkd_value_1;
  wire [31:0] ds_rkd_value_1 = inst_jirl_1 ? rj_value_1 : rkd_value_1;

  wire [31:0] csr_wmask_0  = is_csrxchg_0 ? rj_value_0 : 32'hffff_ffff;
  wire [31:0] csr_wvalue_0 = rkd_value_0;
  wire [31:0] csr_wmask_1  = is_csrxchg_1 ? rj_value_1 : 32'hffff_ffff;
  wire [31:0] csr_wvalue_1 = rkd_value_1;

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

  assign ds_to_es_bus_0 = {ds_pc_0,
                           alu_op_0,
                           ds_alu_src1_0,
                           ds_alu_src2_0,
                           ds_rkd_value_0,
                           res_from_mem_0,
                           gr_we_0,
                           mem_we_0,
                           dest_0,
                           is_mul_0,
                           mul_signed_0,
                           mul_hi_0,
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
                           csr_num_0,
                           csr_wmask_0,
                           csr_wvalue_0
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
                           mul_signed_1,
                           mul_hi_1,
                           ld_byte_1,
                           ld_half_1,
                           ld_sign_ext_1,
                           st_byte_1,
                           st_half_1,
                           ds_pred_taken_1,
                           ds_pred_target_1,
                           ds_br_op_1,
                           ds_br_offs_1,
                           1'b0,
                           1'b0,
                           5'b0,
                           1'b0,
                           14'b0,
                           32'b0,
                           32'b0
                          };

endmodule
