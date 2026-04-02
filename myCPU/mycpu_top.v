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

  // IF 与 ICache 之间的类SRAM接口
  wire        if_inst_sram_req;
  wire [31:0] if_inst_sram_addr;
  wire        if_inst_sram_addr_ok;
  wire        if_inst_sram_data_ok;
  wire [31:0] if_inst_sram_rdata;

  // Icache 与 SRAM 之间的接口
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
  wire [`DS_TO_ES_BUS_WD-1:0] ds_to_es_bus;
  wire [`ES_TO_MS_BUS_WD-1:0] es_to_ms_bus;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus;

  wire [31:0] bpu_if_pc;

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
  wire [31:0] bpu_pred_target;
  wire        bpu_pred_error;
  wire        bpu_pl_suspend;
  wire        bpu_if_valid;

  wire        bpu_id_valid;
  wire        bpu_id_is_bj;
  wire [31:0] bpu_id_pc;
  wire        bpu_id_real_taken;
  wire [31:0] bpu_id_real_target;

  reg         bpu_ex_valid;
  reg         bpu_ex_is_bj;
  reg  [31:0] bpu_ex_pc;
  reg         bpu_ex_real_taken;
  reg  [31:0] bpu_ex_real_target;

  // 异常冲刷信号
  wire        ws_flush;
  wire [31:0] ws_flush_pc;

  BPU u_bpu(
        .clk        (clk              ),
        .resetn     (resetn            ),
        .if_pc      (if_inst_sram_addr         ),
        .if_valid   (if_inst_sram_req && if_inst_sram_addr_ok),
        .id_valid   (bpu_id_valid       ),
        .pl_suspend (!ds_allowin     ),
        .pred_target(bpu_pred_target    ),
        .pred_error (bpu_pred_error     ),
        .ex_valid   (bpu_ex_valid       ),
        .ex_is_bj   (bpu_ex_is_bj       ),
        .ex_pc      (bpu_ex_pc          ),
        .real_taken (bpu_ex_real_taken  ),
        .real_target(bpu_ex_real_target )
      );

  // IF stage
  IF_stage u_if(
             .clk              (clk             ),
             .resetn           (resetn           ),
             .ds_allowin       (ds_allowin       ),
             .br_taken         (br_taken         ),
             .br_target        (br_target        ),
             .ws_flush         (ws_flush         ),
             .ws_flush_pc      (ws_flush_pc      ),
             .pred_target      (bpu_pred_target  ),
             .fs_to_ds_valid   (fs_to_ds_valid   ),
             .fs_to_ds_bus     (fs_to_ds_bus     ),
             .inst_sram_req    (if_inst_sram_req    ),
             .inst_sram_addr   (if_inst_sram_addr   ),
             .inst_sram_addr_ok(if_inst_sram_addr_ok),
             .inst_sram_data_ok(if_inst_sram_data_ok),
             .inst_sram_rdata  (if_inst_sram_rdata  )
           );

  // ID stage
  ID_stage u_id(
             .clk            (clk           ),
             .resetn         (resetn         ),
             .fs_to_ds_valid (fs_to_ds_valid ),
             .fs_to_ds_bus   (fs_to_ds_bus   ),
             .ds_allowin     (ds_allowin     ),
             .br_taken       (br_taken       ),
             .br_target      (br_target      ),
             .bpu_valid      (bpu_id_valid   ),
             .bpu_is_bj      (bpu_id_is_bj   ),
             .bpu_pc         (bpu_id_pc      ),
             .bpu_real_taken (bpu_id_real_taken),
             .bpu_real_target(bpu_id_real_target),
             .es_allowin     (es_allowin     ),
             .es_fwd_bus     (es_fwd_bus     ),
             .ms_fwd_bus     (ms_fwd_bus     ),
             .ws_fwd_bus     (ws_fwd_bus     ),
             .ws_to_rf_bus   (ws_to_rf_bus   ),
             .ws_flush       (ws_flush       ),
             .ds_to_es_valid (ds_to_es_valid ),
             .ds_to_es_bus   (ds_to_es_bus   )
           );


  // EX stage
  EXE_stage u_exe(
              .clk            (clk           ),
              .resetn         (resetn         ),
              .ds_to_es_valid (ds_to_es_valid ),
              .ds_to_es_bus   (ds_to_es_bus   ),
              .ms_allowin     (ms_allowin     ),
              .ws_flush       (ws_flush       ),
              .es_allowin     (es_allowin     ),
              .es_to_ms_valid (es_to_ms_valid ),
              .es_to_ms_bus   (es_to_ms_bus   ),
              .es_fwd_bus     (es_fwd_bus     )
            );

  // MEM stage
  MEM_stage u_mem(
              .clk              (clk             ),
              .resetn           (resetn           ),
              .es_to_ms_valid   (es_to_ms_valid   ),
              .es_to_ms_bus     (es_to_ms_bus     ),
              .ws_allowin       (ws_allowin       ),
              .ws_flush         (ws_flush         ),
              .ms_allowin       (ms_allowin       ),
              .ms_to_ws_valid   (ms_to_ws_valid   ),
              .ms_to_ws_bus     (ms_to_ws_bus     ),
              .ms_fwd_bus       (ms_fwd_bus       ),
              .data_sram_req    (data_sram_req    ),
              .data_sram_wr     (data_sram_wr     ),
              .data_sram_size   (data_sram_size   ),
              .data_sram_wstrb  (data_sram_wstrb  ),
              .data_sram_addr   (data_sram_addr   ),
              .data_sram_wdata  (data_sram_wdata  ),
              .data_sram_addr_ok(data_sram_addr_ok),
              .data_sram_data_ok(data_sram_data_ok),
              .data_sram_rdata  (data_sram_rdata  )
            );

  // WB stage
  WB_stage u_wb(
             .clk             (clk            ),
             .resetn          (resetn          ),
             .ms_to_ws_valid  (ms_to_ws_valid  ),
             .ms_to_ws_bus    (ms_to_ws_bus    ),
             .ws_allowin      (ws_allowin      ),
             .ws_fwd_bus      (ws_fwd_bus      ),
             .ws_to_rf_bus    (ws_to_rf_bus    ),
             .ws_flush        (ws_flush        ),
             .ws_flush_pc     (ws_flush_pc     ),
             .debug_wb_pc     (debug_wb_pc     ),
             .debug_wb_rf_we  (debug_wb_rf_we  ),
             .debug_wb_rf_wnum(debug_wb_rf_wnum),
             .debug_wb_rf_wdata(debug_wb_rf_wdata)
           );

  icache u_icache(
           .clk      (clk             ),
           .resetn   (resetn          ),
           .valid    (if_inst_sram_req    ),
           .index    (if_inst_sram_addr[11:4]),
           .tag      (if_inst_sram_addr[31:12]),
           .offset   (if_inst_sram_addr[3:0]),
           .addr_ok  (if_inst_sram_addr_ok),
           .data_ok  (if_inst_sram_data_ok),
           .rdata    (if_inst_sram_rdata  ),
           .rd_req   (icache_rd_req    ),
           .rd_addr  (icache_rd_addr   ),
           .rd_rdy   (icache_rd_rdy    ),
           .ret_valid(icache_ret_valid ),
           .ret_last (icache_ret_last  ),
           .ret_data (icache_ret_data  )
         );

  icache_refill u_icache_refill(
                  .clk             (clk             ),
                  .resetn          (resetn          ),
                  .icache_rd_req   (icache_rd_req   ),
                  .icache_rd_addr  (icache_rd_addr  ),
                  .icache_rd_rdy   (icache_rd_rdy   ),
                  .icache_ret_valid(icache_ret_valid),
                  .icache_ret_last (icache_ret_last ),
                  .icache_ret_data (icache_ret_data ),
                  .inst_sram_req   (inst_sram_req   ),
                  .inst_sram_wr    (inst_sram_wr    ),
                  .inst_sram_size  (inst_sram_size  ),
                  .inst_sram_wstrb (inst_sram_wstrb ),
                  .inst_sram_addr  (inst_sram_addr  ),
                  .inst_sram_wdata (inst_sram_wdata ),
                  .inst_sram_addr_ok(inst_sram_addr_ok),
                  .inst_sram_data_ok(inst_sram_data_ok),
                  .inst_sram_rdata (inst_sram_rdata )
                );



endmodule
