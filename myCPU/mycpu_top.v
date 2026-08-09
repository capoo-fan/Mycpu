`include "mycpu.vh"

module mycpu_top(
    input  wire        clk,
    input  wire        resetn,
    // 类SRAM 指令接口
    output wire        inst_sram_req,
    output wire        inst_sram_wr,
    output wire [ 1:0] inst_sram_size,
    output wire [ 3:0] inst_sram_wstrb,
    output wire [31:0] inst_sram_addr,
    output wire [31:0] inst_sram_wdata,
    input  wire        inst_sram_addr_ok,
    input  wire        inst_sram_data_ok,
    input  wire [31:0] inst_sram_rdata,
    // 类SRAM 数据接口
    output wire        data_sram_req,
    output wire        data_sram_wr,
    output wire [ 1:0] data_sram_size,
    output wire [ 3:0] data_sram_wstrb,
    output wire [31:0] data_sram_addr,
    output wire [31:0] data_sram_wdata,
    input  wire        data_sram_addr_ok,
    input  wire        data_sram_data_ok,
    input  wire [31:0] data_sram_rdata,
    input  wire        data_sram_fast_ready,
    input  wire        data_sram_fast_data_ok,
    input  wire [31:0] data_sram_fast_rdata,
    input  wire        data_sram_store_ready,
    // SoC 兼容端口：内部 debug 状态和布线已删除。
    output wire [31:0] debug_wb_pc,
    output wire [ 3:0] debug_wb_rf_we,
    output wire [ 4:0] debug_wb_rf_wnum,
    output wire [31:0] debug_wb_rf_wdata
  );

  // Icache 与 refill 控制器之间的接口
  wire         icache_rd_req;
  wire [31:0]  icache_rd_addr;
  wire         icache_rd_rdy;
  wire         icache_ret_valid;
  wire [ 1:0]  icache_ret_last;
  wire [31:0]  icache_ret_data;

  // 级间握手 & 总线
  wire        es_allowin;
  wire        ms_allowin;
  wire        ws_allowin;

  wire        if_to_ibuf_valid_0;
  wire        if_to_ibuf_valid_1;
  wire [`FS_TO_DS_BUS_WD-1:0] if_to_ibuf_bus_0;
  wire [`FS_TO_DS_BUS_WD-1:0] if_to_ibuf_bus_1;
  wire        ibuf_push_ready;
  wire        ibuf_full;

  wire        ibuf_front_valid_0;
  wire        ibuf_front_valid_1;
  wire [`IBUF_ENTRY_BUS_WD-1:0] ibuf_front_bus_0;
  wire [`IBUF_ENTRY_BUS_WD-1:0] ibuf_front_bus_1;
  wire [4:0]  ibuf_front_raddr1_0_hot;
  wire [4:0]  ibuf_front_raddr2_0_hot;
  wire [4:0]  ibuf_front_raddr1_1_hot;
  wire [4:0]  ibuf_front_raddr1_1_consume;
  wire [4:0]  ibuf_front_raddr2_1_hot;
  wire        issue_pop_0;
  wire        issue_pop_1;

  wire        ds_to_es_valid_0;
  wire        ds_to_es_valid_1;
  wire        es_to_ms_valid_0;
  wire        es_to_ms_valid_1;
  wire        ms_to_ws_valid_0;
  wire        ms_to_ws_valid_1;

  wire [`DS_TO_ES_BUS_WD-1:0] ds_to_es_bus_0;
  wire [`DS_TO_ES_BUS_1_WD-1:0] ds_to_es_bus_1;
  wire [31:0] ds_mul_src1_0;
  wire [31:0] ds_mul_src2_0;
  wire [31:0] ds_mul_src1_1;
  wire [31:0] ds_mul_src2_1;
  wire [`ES_TO_MS_BUS_WD-1:0] es_to_ms_bus_0;
  wire [`ES_TO_MS_BUS_1_WD-1:0] es_to_ms_bus_1;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus_0;
  wire [`MS_TO_WS_BUS_1_WD-1:0] ms_to_ws_bus_1;

  // 前递总线
  wire [`ES_FWD_BUS_WD-1:0] es_fwd_bus_0;
  wire [`ES_FWD_BUS_1_WD-1:0] es_fwd_bus_1;
  wire [`MS_FWD_BUS_WD-1:0] ms_fwd_bus_0;
  wire [`MS_FWD_BUS_1_WD-1:0] ms_fwd_bus_1;
  wire        load_wakeup_valid;
  wire [31:0] load_wakeup_data;

  // 写回总线
  wire [`WS_TO_RF_BUS_WD-1:0] ws_to_rf_bus;

  // 分支信号
  wire        br_taken;
  wire [31:0] br_target;

  // CSR 提交、串行化与流水线冲刷
  wire        es_csr_busy;
  wire        ms_csr_busy;
  wire        ws_csr_busy;
  wire        es_cacop_busy;
  wire        ms_cacop_busy;
  reg         special_block;
  wire        special_fire;
  wire [13:0] csr_raddr;
  wire [31:0] csr_rdata;
  wire        csr_we;
  wire [13:0] csr_waddr;
  wire [31:0] csr_wmask;
  wire [31:0] csr_wdata;
  wire [31:0] csr_crmd;
  wire [31:0] csr_dmw0;
  wire [31:0] csr_dmw1;
  wire [`TRANS_CTX_WD-1:0] csr_trans_ctx;
  wire        csr_ctx_update;
  wire        csr_flush;
  wire [31:0] csr_flush_target;
  wire        cacop_flush;
  wire [31:0] cacop_flush_target;
  wire        pipeline_flush = csr_flush || cacop_flush || br_taken;
  wire [31:0] pipeline_flush_target = csr_flush ? csr_flush_target :
       cacop_flush ? cacop_flush_target : br_target;

  // CSR/CACOP 发射后用一个本地 scoreboard 阻止年轻指令。不再将
  // ES/MEM/WB 各级 busy 组合后跨级送回 ISSUE。
  always @(posedge clk)
  begin
    if (!resetn)
      special_block <= 1'b0;
    else if (pipeline_flush)
      special_block <= 1'b0;
    else if (special_fire)
      special_block <= 1'b1;
  end

  // BPU 预测与训练信号
  wire        bpu_pred_taken;
  wire [31:0] bpu_pred_target;
  wire        bpu_pred_lane;
  wire        bpu_pred_taken_0;
  wire [31:0] bpu_pred_target_0;
  wire        bpu_pred_taken_1;
  wire [31:0] bpu_pred_target_1;

  wire        bpu_ex_valid;
  wire        bpu_ex_is_bj;
  wire [31:0] bpu_ex_pc;
  wire        bpu_ex_real_taken;
  wire [31:0] bpu_ex_real_target;

  // ICache 维护信号
  wire        icacop_req_valid;
  wire        icacop_req_ready;
  wire [ 4:0] icacop_req_code;
  wire [31:0] icacop_req_addr;
  wire [31:0] icacop_paddr;
  wire        icacop_done;
  wire        store_inv_valid;
  wire [31:0] store_inv_addr;

  // PC 模块信号
  wire [31:0] pc_out;
  wire [31:0] pc_paddr;
  wire [31:0] data_sram_vaddr;
  wire        pc_inst_req;
  wire        if_suspend;
  wire        pc_cross_line = (pc_out[3:2] == 2'b11);
  wire [31:0] pc_next_seq   = pc_out + (pc_cross_line ? 32'h4 : 32'h8);
  wire [31:0] pc_next       = bpu_pred_taken ? bpu_pred_target : pc_next_seq;

  assign debug_wb_pc       = 32'b0;
  assign debug_wb_rf_we    = 4'b0;
  assign debug_wb_rf_wnum  = 5'b0;
  assign debug_wb_rf_wdata = 32'b0;

  assign bpu_pred_taken_0  = bpu_pred_taken && !bpu_pred_lane;
  assign bpu_pred_target_0 = bpu_pred_target;
  assign bpu_pred_taken_1  = bpu_pred_taken && bpu_pred_lane;
  assign bpu_pred_target_1 = bpu_pred_target;
  wire data_txn_accept = data_sram_req && data_sram_addr_ok;
  // BaseRAM 与 ExtRAM 合起来正好是 0x1c00_0000..0x1c7f_ffff。
  // 合并比较可减少 DMW 翻译后地址分类的逻辑级数。
  wire data_sram_addr_is_sram =
       (data_sram_addr & 32'hff80_0000) == 32'h1c00_0000;
  data_txn_tracker u_data_txn_tracker(
                     .clk            (clk),
                     .resetn         (resetn),
                     .txn_accept     (data_txn_accept),
                     .txn_store      (data_sram_wr),
                     .txn_paddr      (data_sram_addr),
                     .txn_data_ok    (data_sram_data_ok),
                     .store_inv_valid(store_inv_valid),
                     .store_inv_addr (store_inv_addr)
                   );

  csr u_csr(
        .clk    (clk),
        .resetn (resetn),
        .raddr  (csr_raddr),
        .rdata  (csr_rdata),
        .we     (csr_we),
        .waddr  (csr_waddr),
        .wmask  (csr_wmask),
        .wdata  (csr_wdata),
        .crmd   (csr_crmd),
        .dmw0   (csr_dmw0),
        .dmw1   (csr_dmw1),
        .trans_ctx(csr_trans_ctx)
      );

  addr_translate u_inst_addr_translate(
                   .clk   (clk),
                   .resetn(resetn),
                   .ctx_update(csr_ctx_update),
                   .ctx_in(csr_trans_ctx),
                   .vaddr (pc_out),
                   .paddr (pc_paddr)
                 );

  addr_translate u_icacop_addr_translate(
                   .clk   (clk),
                   .resetn(resetn),
                   .ctx_update(csr_ctx_update),
                   .ctx_in(csr_trans_ctx),
                   .vaddr (icacop_req_addr),
                   .paddr (icacop_paddr)
                 );

  addr_translate u_data_addr_translate(
                   .clk   (clk),
                   .resetn(resetn),
                   .ctx_update(csr_ctx_update),
                   .ctx_in(csr_trans_ctx),
                   .vaddr (data_sram_vaddr),
                   .paddr (data_sram_addr)
                 );

  PC u_pc(
       .clk      (clk),
       .resetn   (resetn),
       .flush    (pipeline_flush),
       .flush_pc (pipeline_flush_target),
       .suspend  (if_suspend),
       .din      (pc_next),
       .pc       (pc_out),
       .inst_req (pc_inst_req)
     );

  BPU u_bpu(
        .clk           (clk),
        .resetn        (resetn),
        .if_pc         (pc_out),
        .if_valid      (pc_inst_req && !if_suspend),
        .id_valid      (bpu_ex_valid),
        .pl_suspend    (if_suspend),
        .pred_taken    (bpu_pred_taken),
        .pred_target   (bpu_pred_target),
        .pred_lane     (bpu_pred_lane),
        .ex_valid      (bpu_ex_valid),
        .ex_is_bj      (bpu_ex_is_bj),
        .ex_pc         (bpu_ex_pc),
        .real_taken    (bpu_ex_real_taken),
        .real_target   (bpu_ex_real_target)
      );

  // IF stage (四级流水线 + 集成 ICache)
  IF_stage u_if(
             .clk               (clk),
             .resetn            (resetn),
             .pc_inst_req       (pc_inst_req),
             .pc                (pc_out),
             .pc_paddr          (pc_paddr),
             .bpu_pred_taken_0  (bpu_pred_taken_0),
             .bpu_pred_target_0 (bpu_pred_target_0),
             .bpu_pred_taken_1  (bpu_pred_taken_1),
             .bpu_pred_target_1 (bpu_pred_target_1),
             .br_taken          (pipeline_flush),
             .icacop_req_valid  (icacop_req_valid),
             .icacop_req_code   (icacop_req_code),
             .icacop_req_addr   (icacop_paddr),
             .icacop_req_ready  (icacop_req_ready),
             .icacop_done       (icacop_done),
             .store_inv_valid   (store_inv_valid),
             .store_inv_addr    (store_inv_addr),
             .ibuf_allowin      (ibuf_push_ready),
             .fs_to_ds_valid_0  (if_to_ibuf_valid_0),
             .fs_to_ds_valid_1  (if_to_ibuf_valid_1),
             .fs_to_ds_bus_0    (if_to_ibuf_bus_0),
             .fs_to_ds_bus_1    (if_to_ibuf_bus_1),
             .if_suspend        (if_suspend),
             .rd_req            (icache_rd_req),
             .rd_addr           (icache_rd_addr),
             .rd_rdy            (icache_rd_rdy),
             .ret_valid         (icache_ret_valid),
             .ret_last          (icache_ret_last),
             .ret_data          (icache_ret_data)
           );

  inst_buffer u_inst_buffer(
                .clk           (clk),
                .resetn        (resetn),
                .flush         (pipeline_flush),
                .push_valid_0  (if_to_ibuf_valid_0),
                .push_bus_0    (if_to_ibuf_bus_0),
                .push_valid_1  (if_to_ibuf_valid_1),
                .push_bus_1    (if_to_ibuf_bus_1),
                .push_ready    (ibuf_push_ready),
                .full          (ibuf_full),
                .pop_0         (issue_pop_0),
                .pop_1         (issue_pop_1),
                .front_valid_0 (ibuf_front_valid_0),
                .front_bus_0   (ibuf_front_bus_0),
                .front_raddr1_0_hot(ibuf_front_raddr1_0_hot),
                .front_raddr2_0_hot(ibuf_front_raddr2_0_hot),
                .front_valid_1 (ibuf_front_valid_1),
                .front_bus_1   (ibuf_front_bus_1),
                .front_raddr1_1_hot(ibuf_front_raddr1_1_hot),
                .front_raddr1_1_consume(ibuf_front_raddr1_1_consume),
                .front_raddr2_1_hot(ibuf_front_raddr2_1_hot)
              );

  ISSUE_stage u_issue(
                .clk              (clk),
                .resetn           (resetn),
                .front_valid_0    (ibuf_front_valid_0),
                .front_bus_0      (ibuf_front_bus_0),
                .front_raddr1_0_hot(ibuf_front_raddr1_0_hot),
                .front_raddr2_0_hot(ibuf_front_raddr2_0_hot),
                .front_valid_1    (ibuf_front_valid_1),
                .front_bus_1      (ibuf_front_bus_1),
                .front_raddr1_1_hot(ibuf_front_raddr1_1_hot),
                .front_raddr1_1_consume(ibuf_front_raddr1_1_consume),
                .front_raddr2_1_hot(ibuf_front_raddr2_1_hot),
                .pop_0            (issue_pop_0),
                .pop_1            (issue_pop_1),
                .special_fire     (special_fire),
                .br_taken         (pipeline_flush),
                .special_block    (special_block),
                .es_allowin       (es_allowin),
                .ms_allowin       (ms_allowin),
                .es_to_ms_valid_0 (es_to_ms_valid_0),
                .es_to_ms_valid_1 (es_to_ms_valid_1),
                .es_fwd_bus_0     (es_fwd_bus_0),
                .es_fwd_bus_1     (es_fwd_bus_1),
                .ms_fwd_bus_0     (ms_fwd_bus_0),
                .ms_fwd_bus_1     (ms_fwd_bus_1),
                .ws_to_rf_bus     (ws_to_rf_bus),
                .load_wakeup_valid(load_wakeup_valid),
                .ds_to_es_valid_0 (ds_to_es_valid_0),
                .ds_to_es_valid_1 (ds_to_es_valid_1),
                .ds_to_es_bus_0   (ds_to_es_bus_0),
                .ds_to_es_bus_1   (ds_to_es_bus_1),
                .ds_mul_src1_0    (ds_mul_src1_0),
                .ds_mul_src2_0    (ds_mul_src2_0),
                .ds_mul_src1_1    (ds_mul_src1_1),
                .ds_mul_src2_1    (ds_mul_src2_1)
              );

  // EX stage
  EXE_stage u_exe(
              .clk              (clk),
              .resetn           (resetn),
              .ds_to_es_valid_0 (ds_to_es_valid_0),
              .ds_to_es_valid_1 (ds_to_es_valid_1),
              .ds_to_es_bus_0   (ds_to_es_bus_0),
              .ds_to_es_bus_1   (ds_to_es_bus_1),
              .ds_mul_src1_0    (ds_mul_src1_0),
              .ds_mul_src2_0    (ds_mul_src2_0),
              .ds_mul_src1_1    (ds_mul_src1_1),
              .ds_mul_src2_1    (ds_mul_src2_1),
              .flush            (pipeline_flush),
              .ms_allowin       (ms_allowin),
              .load_wakeup_valid(load_wakeup_valid),
              .load_wakeup_data (load_wakeup_data),
              .es_allowin       (es_allowin),
              .es_to_ms_valid_0 (es_to_ms_valid_0),
              .es_to_ms_valid_1 (es_to_ms_valid_1),
              .es_to_ms_bus_0   (es_to_ms_bus_0),
              .es_to_ms_bus_1   (es_to_ms_bus_1),
              .es_fwd_bus_0     (es_fwd_bus_0),
              .es_fwd_bus_1     (es_fwd_bus_1),
              .csr_busy         (es_csr_busy),
              .cacop_busy       (es_cacop_busy),
              .csr_raddr        (csr_raddr),
              .csr_rdata        (csr_rdata)
            );

  // MEM stage
  MEM_stage u_mem(
              .clk               (clk),
              .resetn            (resetn),
              .es_to_ms_valid_0  (es_to_ms_valid_0),
              .es_to_ms_valid_1  (es_to_ms_valid_1),
              .es_to_ms_bus_0    (es_to_ms_bus_0),
              .es_to_ms_bus_1    (es_to_ms_bus_1),
              .trans_ctx         (csr_trans_ctx),
              .ws_allowin        (ws_allowin),
              .ws_to_rf_bus      (ws_to_rf_bus),
              .ms_allowin        (ms_allowin),
              .ms_to_ws_valid_0  (ms_to_ws_valid_0),
              .ms_to_ws_valid_1  (ms_to_ws_valid_1),
              .ms_to_ws_bus_0    (ms_to_ws_bus_0),
              .ms_to_ws_bus_1    (ms_to_ws_bus_1),
              .ms_fwd_bus_0      (ms_fwd_bus_0),
              .ms_fwd_bus_1      (ms_fwd_bus_1),
              .load_wakeup_valid (load_wakeup_valid),
              .load_wakeup_data  (load_wakeup_data),
              .csr_busy          (ms_csr_busy),
              .cacop_busy        (ms_cacop_busy),
              .br_taken          (br_taken),
              .br_target         (br_target),
              .bpu_valid         (bpu_ex_valid),
              .bpu_is_bj         (bpu_ex_is_bj),
              .bpu_pc            (bpu_ex_pc),
              .bpu_real_taken    (bpu_ex_real_taken),
              .bpu_real_target   (bpu_ex_real_target),
              .icacop_req_valid  (icacop_req_valid),
              .icacop_req_code   (icacop_req_code),
              .icacop_req_addr   (icacop_req_addr),
              .icacop_req_ready  (icacop_req_ready),
              .icacop_done       (icacop_done),
              .cacop_flush       (cacop_flush),
              .cacop_flush_target(cacop_flush_target),
              .data_sram_req     (data_sram_req),
              .data_sram_wr      (data_sram_wr),
              .data_sram_size    (data_sram_size),
              .data_sram_wstrb   (data_sram_wstrb),
              .data_sram_addr    (data_sram_vaddr),
              .data_sram_wdata   (data_sram_wdata),
              .data_sram_addr_is_sram(data_sram_addr_is_sram),
              .data_sram_store_ready(data_sram_store_ready),
              .data_sram_addr_ok (data_sram_addr_ok),
              .data_sram_data_ok (data_sram_data_ok),
              .data_sram_rdata   (data_sram_rdata),
              .data_sram_fast_ready(data_sram_fast_ready),
              .data_sram_fast_data_ok(data_sram_fast_data_ok),
              .data_sram_fast_rdata(data_sram_fast_rdata)
            );

  // WB stage
  WB_stage u_wb(
             .clk                (clk),
             .resetn             (resetn),
             .ms_to_ws_valid_0   (ms_to_ws_valid_0),
             .ms_to_ws_valid_1   (ms_to_ws_valid_1),
             .ms_to_ws_bus_0     (ms_to_ws_bus_0),
             .ms_to_ws_bus_1     (ms_to_ws_bus_1),
             .ws_allowin         (ws_allowin),
             .ws_to_rf_bus       (ws_to_rf_bus),
             .csr_busy           (ws_csr_busy),
             .csr_we             (csr_we),
             .csr_waddr          (csr_waddr),
             .csr_wmask          (csr_wmask),
             .csr_wdata          (csr_wdata),
             .csr_ctx_update     (csr_ctx_update),
             .csr_flush          (csr_flush),
             .csr_flush_target   (csr_flush_target)
           );

  icache_refill u_icache_refill(
                  .clk              (clk),
                  .resetn           (resetn),
                  .icache_rd_req    (icache_rd_req),
                  .icache_rd_addr   (icache_rd_addr),
                  .icache_rd_rdy    (icache_rd_rdy),
                  .icache_ret_valid (icache_ret_valid),
                  .icache_ret_last  (icache_ret_last),
                  .icache_ret_data  (icache_ret_data),
                  .inst_sram_req    (inst_sram_req),
                  .inst_sram_wr     (inst_sram_wr),
                  .inst_sram_size   (inst_sram_size),
                  .inst_sram_wstrb  (inst_sram_wstrb),
                  .inst_sram_addr   (inst_sram_addr),
                  .inst_sram_wdata  (inst_sram_wdata),
                  .inst_sram_addr_ok(inst_sram_addr_ok),
                  .inst_sram_data_ok(inst_sram_data_ok),
                  .inst_sram_rdata  (inst_sram_rdata)
                );

endmodule
