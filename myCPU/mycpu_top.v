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
  wire        ds_allowin;
  wire        es_allowin;
  wire        ms_allowin;
  wire        ws_allowin;

  wire        fs_to_ds_valid;
  wire        ds_to_es_valid;
  wire        es_to_ms_valid;
  wire        ms_to_ws_valid;

  wire [`FS_TO_DS_BUS_WD-1:0] fs_to_ds_bus;
  wire        if_to_ibuf_valid;
  wire [`FS_TO_DS_BUS_WD-1:0] if_to_ibuf_bus;
  wire        ibuf_push_ready;
  wire        ibuf_full;
  wire [`DS_TO_ES_BUS_WD-1:0] ds_to_es_bus;
  wire [`ES_TO_MS_BUS_WD-1:0] es_to_ms_bus;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus;

  // 前递总线
  wire [`ES_FWD_BUS_WD-1:0] es_fwd_bus;
  wire [`MS_FWD_BUS_WD-1:0] ms_fwd_bus;
  wire [`WS_FWD_BUS_WD-1:0] ws_fwd_bus;

  // 写回总线
  wire [`WS_TO_RF_BUS_WD-1:0] ws_to_rf_bus;

  // 分支信号
  wire        br_taken;
  wire [31:0] br_target;

  // BPU 预测与训练信号
  wire        bpu_pred_taken;
  wire [31:0] bpu_pred_target;

  wire        bpu_id_valid;
  wire        bpu_id_is_bj;
  wire [31:0] bpu_id_pc;
  wire        bpu_id_real_taken;
  wire [31:0] bpu_id_real_target;
  wire        bpu_id_is_call;
  wire        bpu_id_is_ret;
  wire [31:0] bpu_id_ret_addr;

  // PC 模块信号
  wire [31:0] pc_out;
  wire        pc_inst_req;
  wire        if_suspend;

  // PC 实例
  PC u_pc(
       .clk      (clk),
       .resetn   (resetn),
       .flush    (br_taken),
       .flush_pc (br_target),
       .suspend  (if_suspend),
       .din      (bpu_pred_target),
       .pc       (pc_out),
       .inst_req (pc_inst_req)
     );

  BPU u_bpu(
        .clk         (clk),
        .resetn      (resetn),
        .if_pc       (pc_out),
        .if_valid    (pc_inst_req && !if_suspend),
        .id_valid    (bpu_id_valid),
        .pl_suspend  (if_suspend),
        .pred_taken  (bpu_pred_taken),
        .pred_target (bpu_pred_target),
        .ex_valid    (bpu_id_valid),
        .ex_is_bj    (bpu_id_is_bj),
        .ex_pc       (bpu_id_pc),
        .real_taken  (bpu_id_real_taken),
        .real_target (bpu_id_real_target),
        .ex_is_call  (bpu_id_is_call),
        .ex_is_ret   (bpu_id_is_ret),
        .ex_ret_addr (bpu_id_ret_addr)
      );

  // IF stage (四级流水线 + 集成 ICache)
  IF_stage u_if(
             .clk              (clk),
             .resetn           (resetn),
             .pc_inst_req      (pc_inst_req),
             .pc               (pc_out),
             .bpu_pred_taken   (bpu_pred_taken),
             .bpu_pred_target  (bpu_pred_target),
             .br_taken         (br_taken),
             .ibuf_allowin     (ibuf_push_ready),
             .fs_to_ds_valid   (if_to_ibuf_valid),
             .fs_to_ds_bus     (if_to_ibuf_bus),
             .if_suspend       (if_suspend),
             .rd_req           (icache_rd_req),
             .rd_addr          (icache_rd_addr),
             .rd_rdy           (icache_rd_rdy),
             .ret_valid        (icache_ret_valid),
             .ret_last         (icache_ret_last),
             .ret_data         (icache_ret_data)
           );

  inst_buffer u_inst_buffer(
                .clk         (clk),
                .resetn      (resetn),
                .flush       (br_taken),
                .push_valid  (if_to_ibuf_valid),
                .push_bus    (if_to_ibuf_bus),
                .push_ready  (ibuf_push_ready),
                .full        (ibuf_full),
                .pop_ready   (ds_allowin),
                .front_valid (fs_to_ds_valid),
                .front_bus   (fs_to_ds_bus)
              );

  // ID stage
  ID_stage u_id(
             .clk            (clk),
             .resetn         (resetn),
             .fs_to_ds_valid (fs_to_ds_valid),
             .fs_to_ds_bus   (fs_to_ds_bus),
             .ds_allowin     (ds_allowin),
             .br_taken       (br_taken),
             .br_target      (br_target),
             .bpu_valid      (bpu_id_valid),
             .bpu_is_bj      (bpu_id_is_bj),
             .bpu_pc         (bpu_id_pc),
             .bpu_real_taken (bpu_id_real_taken),
             .bpu_real_target(bpu_id_real_target),
             .bpu_is_call    (bpu_id_is_call),
             .bpu_is_ret     (bpu_id_is_ret),
             .bpu_ret_addr   (bpu_id_ret_addr),
             .es_allowin     (es_allowin),
             .es_fwd_bus     (es_fwd_bus),
             .ms_fwd_bus     (ms_fwd_bus),
             .ws_fwd_bus     (ws_fwd_bus),
             .ws_to_rf_bus   (ws_to_rf_bus),
             .ds_to_es_valid (ds_to_es_valid),
             .ds_to_es_bus   (ds_to_es_bus)
           );

  // EX stage
  EXE_stage u_exe(
              .clk            (clk),
              .resetn         (resetn),
              .ds_to_es_valid (ds_to_es_valid),
              .ds_to_es_bus   (ds_to_es_bus),
              .ms_allowin     (ms_allowin),
              .es_allowin     (es_allowin),
              .es_to_ms_valid (es_to_ms_valid),
              .es_to_ms_bus   (es_to_ms_bus),
              .es_fwd_bus     (es_fwd_bus)
            );

  // MEM stage
  MEM_stage u_mem(
              .clk              (clk),
              .resetn           (resetn),
              .es_to_ms_valid   (es_to_ms_valid),
              .es_to_ms_bus     (es_to_ms_bus),
              .ws_allowin       (ws_allowin),
              .ms_allowin       (ms_allowin),
              .ms_to_ws_valid   (ms_to_ws_valid),
              .ms_to_ws_bus     (ms_to_ws_bus),
              .ms_fwd_bus       (ms_fwd_bus),
              .data_sram_req    (data_sram_req),
              .data_sram_wr     (data_sram_wr),
              .data_sram_size   (data_sram_size),
              .data_sram_wstrb  (data_sram_wstrb),
              .data_sram_addr   (data_sram_addr),
              .data_sram_wdata  (data_sram_wdata),
              .data_sram_addr_ok(data_sram_addr_ok),
              .data_sram_data_ok(data_sram_data_ok),
              .data_sram_rdata  (data_sram_rdata)
            );

  // WB stage
  WB_stage u_wb(
             .clk             (clk),
             .resetn          (resetn),
             .ms_to_ws_valid  (ms_to_ws_valid),
             .ms_to_ws_bus    (ms_to_ws_bus),
             .ws_allowin      (ws_allowin),
             .ws_fwd_bus      (ws_fwd_bus),
             .ws_to_rf_bus    (ws_to_rf_bus),
             .debug_wb_pc     (debug_wb_pc),
             .debug_wb_rf_we  (debug_wb_rf_we),
             .debug_wb_rf_wnum(debug_wb_rf_wnum),
             .debug_wb_rf_wdata(debug_wb_rf_wdata)
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
