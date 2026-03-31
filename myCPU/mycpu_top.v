`include "mycpu.vh"

module mycpu_top(
    input  wire        aclk,
    input  wire        aresetn,
    // AXI4 主接口 - AR 通道
    output wire [ 3:0] arid,
    output wire [31:0] araddr,
    output wire [ 7:0] arlen,
    output wire [ 2:0] arsize,
    output wire [ 1:0] arburst,
    output wire [ 1:0] arlock,
    output wire [ 3:0] arcache,
    output wire [ 2:0] arprot,
    output wire        arvalid,
    input  wire        arready,
    // AXI4 主接口 - R 通道
    input  wire [ 3:0] rid,
    input  wire [31:0] rdata,
    input  wire [ 1:0] rresp,
    input  wire        rlast,
    input  wire        rvalid,
    output wire        rready,
    // AXI4 主接口 - AW 通道
    output wire [ 3:0] awid,
    output wire [31:0] awaddr,
    output wire [ 7:0] awlen,
    output wire [ 2:0] awsize,
    output wire [ 1:0] awburst,
    output wire [ 1:0] awlock,
    output wire [ 3:0] awcache,
    output wire [ 2:0] awprot,
    output wire        awvalid,
    input  wire        awready,
    // AXI4 主接口 - W 通道
    output wire [ 3:0] wid,
    output wire [31:0] wdata,
    output wire [ 3:0] wstrb,
    output wire        wlast,
    output wire        wvalid,
    input  wire        wready,
    // AXI4 主接口 - B 通道
    input  wire [ 3:0] bid,
    input  wire [ 1:0] bresp,
    input  wire        bvalid,
    output wire        bready,
    // 调试信号
    output wire [31:0] debug_wb_pc,
    output wire [ 3:0] debug_wb_rf_we,
    output wire [ 4:0] debug_wb_rf_wnum,
    output wire [31:0] debug_wb_rf_wdata
  );

  // 内部类SRAM信号

  wire        inst_sram_req;
  wire        inst_sram_wr;
  wire [ 1:0] inst_sram_size;
  wire [ 3:0] inst_sram_wstrb;
  wire [31:0] inst_sram_addr;
  wire [31:0] inst_sram_wdata;
  wire        inst_sram_addr_ok;
  wire        inst_sram_data_ok;
  wire [31:0] inst_sram_rdata;

  wire        data_sram_req;
  wire        data_sram_wr;
  wire [ 1:0] data_sram_size;
  wire [ 3:0] data_sram_wstrb;
  wire [31:0] data_sram_addr;
  wire [31:0] data_sram_wdata;
  wire        data_sram_addr_ok;
  wire        data_sram_data_ok;
  wire [31:0] data_sram_rdata;

  // ICache <-> bridge
  wire        icache_rd_req;
  wire [ 2:0] icache_rd_type;
  wire [31:0] icache_rd_addr;
  wire        icache_rd_rdy;
  wire        icache_ret_valid;
  wire [ 1:0] icache_ret_last;
  wire [31:0] icache_ret_data;
  wire        icache_wr_req;
  wire [ 2:0] icache_wr_type;
  wire [31:0] icache_wr_addr;
  wire [ 3:0] icache_wr_wstrb;
  wire [127:0] icache_wr_data;
  wire        icache_wr_rdy;

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

  assign bpu_if_pc      = inst_sram_addr;
  assign bpu_if_valid   = inst_sram_req && inst_sram_addr_ok;
  assign bpu_pl_suspend = !ds_allowin;

  // 将 ID 级真实结果延后一拍，对齐 BPU 的 ex_* 校正接口
  always @(posedge aclk)
  begin
    if (!aresetn)
    begin
      bpu_ex_valid       <= 1'b0;
      bpu_ex_is_bj       <= 1'b0;
      bpu_ex_pc          <= 32'b0;
      bpu_ex_real_taken  <= 1'b0;
      bpu_ex_real_target <= 32'b0;
    end
    else
    begin
      bpu_ex_valid       <= bpu_id_valid;
      bpu_ex_is_bj       <= bpu_id_is_bj;
      bpu_ex_pc          <= bpu_id_pc;
      bpu_ex_real_taken  <= bpu_id_real_taken;
      bpu_ex_real_target <= bpu_id_real_target;
    end
  end

  BPU u_bpu(
        .clk        (aclk              ),
        .resetn     (aresetn            ),
        .if_pc      (bpu_if_pc          ),
        .if_valid   (bpu_if_valid       ),
        .id_valid   (bpu_id_valid       ),
        .pl_suspend (bpu_pl_suspend     ),
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
             .clk              (aclk             ),
             .resetn           (aresetn           ),
             .ds_allowin       (ds_allowin       ),
             .br_taken         (br_taken         ),
             .br_target        (br_target        ),
             .ws_flush         (ws_flush         ),
             .ws_flush_pc      (ws_flush_pc      ),
             .pred_target      (bpu_pred_target  ),
             .fs_to_ds_valid   (fs_to_ds_valid   ),
             .fs_to_ds_bus     (fs_to_ds_bus     ),
             .inst_sram_req    (inst_sram_req    ),
             .inst_sram_wr     (inst_sram_wr     ),
             .inst_sram_size   (inst_sram_size   ),
             .inst_sram_wstrb  (inst_sram_wstrb  ),
             .inst_sram_addr   (inst_sram_addr   ),
             .inst_sram_wdata  (inst_sram_wdata  ),
             .inst_sram_addr_ok(inst_sram_addr_ok),
             .inst_sram_data_ok(inst_sram_data_ok),
             .inst_sram_rdata  (inst_sram_rdata  )
           );

  // ID stage
  ID_stage u_id(
             .clk            (aclk           ),
             .resetn         (aresetn         ),
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
              .clk            (aclk           ),
              .resetn         (aresetn         ),
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
              .clk              (aclk             ),
              .resetn           (aresetn           ),
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
             .clk             (aclk            ),
             .resetn          (aresetn          ),
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
           .clk      (aclk             ),
           .resetn   (aresetn          ),
           .valid    (inst_sram_req    ),
           .index    (inst_sram_addr[11:4]),
           .tag      (inst_sram_addr[31:12]),
           .offset   (inst_sram_addr[3:0]),
           .addr_ok  (inst_sram_addr_ok),
           .data_ok  (inst_sram_data_ok),
           .rdata    (inst_sram_rdata  ),
           .rd_req   (icache_rd_req    ),
           .rd_type  (icache_rd_type   ),
           .rd_addr  (icache_rd_addr   ),
           .rd_rdy   (icache_rd_rdy    ),
           .ret_valid(icache_ret_valid ),
           .ret_last (icache_ret_last  ),
           .ret_data (icache_ret_data  ),
           .wr_req   (icache_wr_req    ),
           .wr_type  (icache_wr_type   ),
           .wr_addr  (icache_wr_addr   ),
           .wr_wstrb (icache_wr_wstrb  ),
           .wr_data  (icache_wr_data   ),
           .wr_rdy   (icache_wr_rdy    )
         );



  // 类SRAM - AXI 转接桥 (2x1)
  sram_axi_bridge u_bridge(
                    .aclk              (aclk              ),
                    .aresetn           (aresetn           ),
                    // ICache 接口
                    .cache_rd_req      (icache_rd_req     ),
                    .cache_rd_type     (icache_rd_type    ),
                    .cache_rd_addr     (icache_rd_addr    ),
                    .cache_rd_rdy      (icache_rd_rdy     ),
                    .cache_ret_valid   (icache_ret_valid  ),
                    .cache_ret_last    (icache_ret_last   ),
                    .cache_ret_data    (icache_ret_data   ),
                    .cache_wr_req      (icache_wr_req     ),
                    .cache_wr_type     (icache_wr_type    ),
                    .cache_wr_addr     (icache_wr_addr    ),
                    .cache_wr_wstrb    (icache_wr_wstrb   ),
                    .cache_wr_data     (icache_wr_data    ),
                    .cache_wr_rdy      (icache_wr_rdy     ),
                    // 数据接口
                    .data_sram_req     (data_sram_req     ),
                    .data_sram_wr      (data_sram_wr      ),
                    .data_sram_size    (data_sram_size    ),
                    .data_sram_wstrb   (data_sram_wstrb   ),
                    .data_sram_addr    (data_sram_addr    ),
                    .data_sram_wdata   (data_sram_wdata   ),
                    .data_sram_addr_ok (data_sram_addr_ok ),
                    .data_sram_data_ok (data_sram_data_ok ),
                    .data_sram_rdata   (data_sram_rdata   ),
                    // AXI 接口
                    .arid              (arid              ),
                    .araddr            (araddr            ),
                    .arlen             (arlen             ),
                    .arsize            (arsize            ),
                    .arburst           (arburst           ),
                    .arlock            (arlock            ),
                    .arcache           (arcache           ),
                    .arprot            (arprot            ),
                    .arvalid           (arvalid           ),
                    .arready           (arready           ),
                    .rid               (rid               ),
                    .rdata             (rdata             ),
                    .rresp             (rresp             ),
                    .rlast             (rlast             ),
                    .rvalid            (rvalid            ),
                    .rready            (rready            ),
                    .awid              (awid              ),
                    .awaddr            (awaddr            ),
                    .awlen             (awlen             ),
                    .awsize            (awsize            ),
                    .awburst           (awburst           ),
                    .awlock            (awlock            ),
                    .awcache           (awcache           ),
                    .awprot            (awprot            ),
                    .awvalid           (awvalid           ),
                    .awready           (awready           ),
                    .wid               (wid               ),
                    .wdata             (wdata             ),
                    .wstrb             (wstrb             ),
                    .wlast             (wlast             ),
                    .wvalid            (wvalid            ),
                    .wready            (wready            ),
                    .bid               (bid               ),
                    .bresp             (bresp             ),
                    .bvalid            (bvalid            ),
                    .bready            (bready            )
                  );

endmodule
