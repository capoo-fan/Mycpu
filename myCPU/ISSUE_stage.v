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
    input  wire                           ms_result_unready,
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

  // ISSUE-local mirror of the EX producer metadata required by the RAW
  // interlock.  Keeping this narrow state beside ISSUE prevents the
  // timing-critical InstBuffer consume cone from reading the physically
  // remote EX destination registers.
  //
  // Pending multiplies already hold es_allowin low and become forwardable on
  // the completion cycle, so only loads and explicitly non-forwardable
  // low-frequency operations need to occupy this scoreboard.
  (* keep = "true", equivalent_register_removal = "no" *)
  reg        ex_wait_valid_0;
  (* keep = "true", equivalent_register_removal = "no" *)
  reg [4:0]  ex_wait_dest_0;
  (* keep = "true", equivalent_register_removal = "no" *)
  reg        ex_wait_valid_1;
  (* keep = "true", equivalent_register_removal = "no" *)
  reg [4:0]  ex_wait_dest_1;

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

  wire rj0_wait = src0_rj_valid &&
       ((ex_wait_valid_0 && (ex_wait_dest_0 == rf_raddr1_0)) ||
        (ex_wait_valid_1 && (ex_wait_dest_1 == rf_raddr1_0)));

  // 保守地对所有 EX load-use 相关插入气泡，包括 Load->Store 写数据。
  // 这避免把 Store 类型和生产者类型接入 pop 控制，缩短
  // InstBuffer hot tag -> ISSUE pop -> InstBuffer payload 的组合路径。
  wire rkd0_wait = src0_rkd_valid &&
       ((ex_wait_valid_0 && (ex_wait_dest_0 == rf_raddr2_0)) ||
        (ex_wait_valid_1 && (ex_wait_dest_1 == rf_raddr2_0)));

  wire rj1_wait = src1_rj_valid &&
       ((ex_wait_valid_0 && (ex_wait_dest_0 == rf_raddr1_1)) ||
        (ex_wait_valid_1 && (ex_wait_dest_1 == rf_raddr1_1)));
  wire rkd1_wait = src1_rkd_valid &&
       ((ex_wait_valid_0 && (ex_wait_dest_0 == rf_raddr2_1)) ||
        (ex_wait_valid_1 && (ex_wait_dest_1 == rf_raddr2_1)));

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
       ((ex_wait_valid_0 && (ex_wait_dest_0 == front_raddr1_0_hot)) ||
        (ex_wait_valid_1 && (ex_wait_dest_1 == front_raddr1_0_hot)));
  wire rkd0_wait_for_consume = src0_rkd_valid_for_consume &&
       ((ex_wait_valid_0 && (ex_wait_dest_0 == front_raddr2_0_hot)) ||
        (ex_wait_valid_1 && (ex_wait_dest_1 == front_raddr2_0_hot)));
  wire rj1_wait_for_consume = src1_rj_valid_for_consume &&
       ((ex_wait_valid_0 && (ex_wait_dest_0 == front_raddr1_1_hot)) ||
        (ex_wait_valid_1 && (ex_wait_dest_1 == front_raddr1_1_hot)));
  wire rkd1_wait_for_consume = src1_rkd_valid_for_consume &&
       ((ex_wait_valid_0 && (ex_wait_dest_0 == front_raddr2_1_hot)) ||
        (ex_wait_valid_1 && (ex_wait_dest_1 == front_raddr2_1_hot)));

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

  wire issue_window_open = es_allowin && !ms_result_unready;

  (* keep = "true", max_fanout = 16 *) wire issue0_fire_for_ex =
  issue_window_open && !br_taken && front_valid_0 && !stall_0 && !special_block;
  (* keep = "true", max_fanout = 16 *) wire issue1_fire_for_ex =
  issue_window_open && !br_taken &&
                    front_valid_0 && !stall_0 && !special_block &&
                    front_valid_1 && !stall_1 && !raw_0_to_1 &&
                    !(mem_op_0 && mem_op_1) && !(is_bj_0 && is_bj_1) &&
                    !special_0 && !special_1;
  (* max_fanout = 16 *) wire issue0_fire_for_consume =
  issue_window_open && !br_taken &&
                    front_valid_0 && !stall_0_for_consume && !special_block;
  (* max_fanout = 16 *) wire issue1_fire_for_consume =
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

  wire capture_ex_wait_0 = ds_to_es_valid_0 && gr_we_0 &&
       (dest_0 != 5'b0) &&
       (res_from_mem_0 || is_cpucfg_0 || is_csr_0 || is_cacop_0);
  wire capture_ex_wait_1 = ds_to_es_valid_1 && gr_we_1 &&
       (dest_1 != 5'b0) &&
       (res_from_mem_1 || is_cpucfg_1 || is_csr_1 || is_cacop_1);

  always @(posedge clk)
  begin
    if (!resetn || br_taken)
    begin
      ex_wait_valid_0 <= 1'b0;
      ex_wait_dest_0  <= 5'b0;
      ex_wait_valid_1 <= 1'b0;
      ex_wait_dest_1  <= 5'b0;
    end
    else if (es_allowin)
    begin
      ex_wait_valid_0 <= capture_ex_wait_0;
      ex_wait_dest_0  <= capture_ex_wait_0 ? dest_0 : 5'b0;
      ex_wait_valid_1 <= capture_ex_wait_1;
      ex_wait_dest_1  <= capture_ex_wait_1 ? dest_1 : 5'b0;
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
              if (ms_result_unready &&
                  (ds_to_es_valid_0 || ds_to_es_valid_1 || pop_0 || pop_1))
                $fatal(1, "unfinished MEM load allowed a younger issue");
            end
          end
`endif

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
                           rf_rdata1_0,
                           rf_rdata2_0,
                           rf_raddr1_0,
                           rf_raddr2_0,
                           imm_0,
                           src1_is_pc_0,
                           src2_is_imm_0,
                           need_rj_0,
                           need_rkd_0,
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
                           is_csrxchg_0,
                           csr_num_0
                          };

  assign ds_to_es_bus_1 = {ds_pc_1,
                           alu_op_1,
                           rf_rdata1_1,
                           rf_rdata2_1,
                           rf_raddr1_1,
                           rf_raddr2_1,
                           imm_1,
                           src1_is_pc_1,
                           src2_is_imm_1,
                           need_rj_1,
                           need_rkd_1,
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
                           is_cpucfg_1,
                           is_cacop_1,
                           cacop_code_1,
                           is_csr_1,
                           is_csrxchg_1,
                           csr_num_1
                          };

endmodule
