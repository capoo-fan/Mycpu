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
    // 调试信号
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
  wire        issue_pop_0;
  wire        issue_pop_1;

  wire        ds_to_es_valid_0;
  wire        ds_to_es_valid_1;
  wire        es_to_ms_valid_0;
  wire        es_to_ms_valid_1;
  wire        ms_to_ws_valid_0;
  wire        ms_to_ws_valid_1;

  wire [`DS_TO_ES_BUS_WD-1:0] ds_to_es_bus_0;
  wire [`DS_TO_ES_BUS_WD-1:0] ds_to_es_bus_1;
  wire [`ES_TO_MS_BUS_WD-1:0] es_to_ms_bus_0;
  wire [`ES_TO_MS_BUS_WD-1:0] es_to_ms_bus_1;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus_0;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus_1;

  // 前递总线
  wire [`ES_FWD_BUS_WD-1:0] es_fwd_bus_0;
  wire [`ES_FWD_BUS_WD-1:0] es_fwd_bus_1;
  wire [`MS_FWD_BUS_WD-1:0] ms_fwd_bus_0;
  wire [`MS_FWD_BUS_WD-1:0] ms_fwd_bus_1;
  wire [`WS_FWD_BUS_WD-1:0] ws_fwd_bus_0;
  wire [`WS_FWD_BUS_WD-1:0] ws_fwd_bus_1;

  // 写回总线
  wire [`WS_TO_RF_BUS_WD-1:0] ws_to_rf_bus;

  // 分支信号
  wire        br_taken;
  wire [31:0] br_target;

  // BPU 预测与训练信号
  wire        bpu_pred_taken_0;
  wire [31:0] bpu_pred_target_0;
  wire        bpu_pred_taken_1;
  wire [31:0] bpu_pred_target_1;

  wire        bpu_ex_valid;
  wire        bpu_ex_is_bj;
  wire [31:0] bpu_ex_pc;
  wire        bpu_ex_real_taken;
  wire [31:0] bpu_ex_real_target;

  // PC 模块信号
  wire [31:0] pc_out;
  wire        pc_inst_req;
  wire        if_suspend;
  wire        pc_cross_line = (pc_out[3:2] == 2'b11);
  wire [31:0] pc_next_seq   = pc_out + (pc_cross_line ? 32'h4 : 32'h8);
  wire [31:0] pc_next       = bpu_pred_taken_0 ? bpu_pred_target_0 :
                              (!pc_cross_line && bpu_pred_taken_1) ? bpu_pred_target_1 :
                              pc_next_seq;

  PC u_pc(
       .clk      (clk),
       .resetn   (resetn),
       .flush    (br_taken),
       .flush_pc (br_target),
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
        .pred_taken_0  (bpu_pred_taken_0),
        .pred_target_0 (bpu_pred_target_0),
        .pred_taken_1  (bpu_pred_taken_1),
        .pred_target_1 (bpu_pred_target_1),
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
             .bpu_pred_taken_0  (bpu_pred_taken_0),
             .bpu_pred_target_0 (bpu_pred_target_0),
             .bpu_pred_taken_1  (bpu_pred_taken_1),
             .bpu_pred_target_1 (bpu_pred_target_1),
             .br_taken          (br_taken),
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
                .flush         (br_taken),
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
                .front_valid_1 (ibuf_front_valid_1),
                .front_bus_1   (ibuf_front_bus_1)
              );

  ISSUE_stage u_issue(
                .clk              (clk),
                .resetn           (resetn),
                .front_valid_0    (ibuf_front_valid_0),
                .front_bus_0      (ibuf_front_bus_0),
                .front_valid_1    (ibuf_front_valid_1),
                .front_bus_1      (ibuf_front_bus_1),
                .pop_0            (issue_pop_0),
                .pop_1            (issue_pop_1),
                .br_taken         (br_taken),
                .es_allowin       (es_allowin),
                .es_fwd_bus_0     (es_fwd_bus_0),
                .es_fwd_bus_1     (es_fwd_bus_1),
                .ms_fwd_bus_0     (ms_fwd_bus_0),
                .ms_fwd_bus_1     (ms_fwd_bus_1),
                .ws_fwd_bus_0     (ws_fwd_bus_0),
                .ws_fwd_bus_1     (ws_fwd_bus_1),
                .ws_to_rf_bus     (ws_to_rf_bus),
                .ds_to_es_valid_0 (ds_to_es_valid_0),
                .ds_to_es_valid_1 (ds_to_es_valid_1),
                .ds_to_es_bus_0   (ds_to_es_bus_0),
                .ds_to_es_bus_1   (ds_to_es_bus_1)
              );

  // EX stage
  EXE_stage u_exe(
              .clk              (clk),
              .resetn           (resetn),
              .ds_to_es_valid_0 (ds_to_es_valid_0),
              .ds_to_es_valid_1 (ds_to_es_valid_1),
              .ds_to_es_bus_0   (ds_to_es_bus_0),
              .ds_to_es_bus_1   (ds_to_es_bus_1),
              .flush            (br_taken),
              .ms_allowin       (ms_allowin),
              .es_allowin       (es_allowin),
              .es_to_ms_valid_0 (es_to_ms_valid_0),
              .es_to_ms_valid_1 (es_to_ms_valid_1),
              .es_to_ms_bus_0   (es_to_ms_bus_0),
              .es_to_ms_bus_1   (es_to_ms_bus_1),
              .es_fwd_bus_0     (es_fwd_bus_0),
              .es_fwd_bus_1     (es_fwd_bus_1)
            );

  // MEM stage
  MEM_stage u_mem(
              .clk               (clk),
              .resetn            (resetn),
              .es_to_ms_valid_0  (es_to_ms_valid_0),
              .es_to_ms_valid_1  (es_to_ms_valid_1),
              .es_to_ms_bus_0    (es_to_ms_bus_0),
              .es_to_ms_bus_1    (es_to_ms_bus_1),
              .ws_allowin        (ws_allowin),
              .ms_allowin        (ms_allowin),
              .ms_to_ws_valid_0  (ms_to_ws_valid_0),
              .ms_to_ws_valid_1  (ms_to_ws_valid_1),
              .ms_to_ws_bus_0    (ms_to_ws_bus_0),
              .ms_to_ws_bus_1    (ms_to_ws_bus_1),
              .ms_fwd_bus_0      (ms_fwd_bus_0),
              .ms_fwd_bus_1      (ms_fwd_bus_1),
              .br_taken          (br_taken),
              .br_target         (br_target),
              .bpu_valid         (bpu_ex_valid),
              .bpu_is_bj         (bpu_ex_is_bj),
              .bpu_pc            (bpu_ex_pc),
              .bpu_real_taken    (bpu_ex_real_taken),
              .bpu_real_target   (bpu_ex_real_target),
              .data_sram_req     (data_sram_req),
              .data_sram_wr      (data_sram_wr),
              .data_sram_size    (data_sram_size),
              .data_sram_wstrb   (data_sram_wstrb),
              .data_sram_addr    (data_sram_addr),
              .data_sram_wdata   (data_sram_wdata),
              .data_sram_addr_ok (data_sram_addr_ok),
              .data_sram_data_ok (data_sram_data_ok),
              .data_sram_rdata   (data_sram_rdata)
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
             .ws_fwd_bus_0       (ws_fwd_bus_0),
             .ws_fwd_bus_1       (ws_fwd_bus_1),
             .ws_to_rf_bus       (ws_to_rf_bus),
             .debug_wb_pc        (debug_wb_pc),
             .debug_wb_rf_we     (debug_wb_rf_we),
             .debug_wb_rf_wnum   (debug_wb_rf_wnum),
             .debug_wb_rf_wdata  (debug_wb_rf_wdata)
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
