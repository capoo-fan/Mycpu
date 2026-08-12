`timescale 1ns / 1ps
`include "mycpu.vh"

module ex_early_load_tb;
  reg clk;
  reg resetn;
  reg es_valid_0;
  reg es_valid_1;
  reg [`ES_TO_MS_BUS_WD-1:0] es_bus_0;
  reg [`ES_TO_MS_BUS_1_WD-1:0] es_bus_1;
  reg data_addr_ok;
  reg data_data_ok;
  reg data_fast_ready;
  reg data_fast_data_ok;
  reg [31:0] data_rdata;
  reg [31:0] data_fast_rdata;
  reg data_addr_is_sram;
  reg data_early_read_accept;
  reg [31:0] es_load_addr_fast_0;
  reg [31:0] es_load_addr_fast_1;

  wire ms_allowin;
  wire ms_to_ws_valid_0;
  wire ms_to_ws_valid_1;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus_0;
  wire [`MS_TO_WS_BUS_1_WD-1:0] ms_to_ws_bus_1;
  wire data_req;
  wire data_wr;
  wire [1:0] data_size;
  wire [3:0] data_wstrb;
  wire [31:0] data_addr;
  wire [31:0] data_wdata;
  wire early_load_req;
  wire [22:0] early_load_addr;
  wire load_wakeup_valid;
  wire [31:0] load_wakeup_data;
  integer accepted_requests;

  MEM_stage dut(
    .clk(clk), .resetn(resetn),
    .es_to_ms_valid_0(es_valid_0),
    .es_to_ms_valid_1(es_valid_1),
    .es_to_ms_bus_0(es_bus_0),
    .es_to_ms_bus_1(es_bus_1),
    .es_load_addr_fast_0(es_load_addr_fast_0),
    .es_load_addr_fast_1(es_load_addr_fast_1),
    .trans_ctx({`TRANS_CTX_WD{1'b0}}),
    .ws_allowin(1'b1),
    .ws_to_rf_bus({`WS_TO_RF_BUS_WD{1'b0}}),
    .ms_allowin(ms_allowin),
    .ms_to_ws_valid_0(ms_to_ws_valid_0),
    .ms_to_ws_valid_1(ms_to_ws_valid_1),
    .ms_to_ws_bus_0(ms_to_ws_bus_0),
    .ms_to_ws_bus_1(ms_to_ws_bus_1),
    .ms_fwd_bus_0(), .ms_fwd_bus_1(),
    .load_wakeup_valid(load_wakeup_valid),
    .load_wakeup_data(load_wakeup_data),
    .csr_busy(), .cacop_busy(),
    .br_taken(), .br_target(),
    .bpu_valid(), .bpu_is_bj(), .bpu_pc(),
    .bpu_real_taken(), .bpu_real_target(),
    .icacop_req_valid(), .icacop_req_code(), .icacop_req_addr(),
    .icacop_req_ready(1'b1), .icacop_done(1'b0),
    .cacop_flush(), .cacop_flush_target(),
    .data_sram_req(data_req), .data_sram_wr(data_wr),
    .data_sram_size(data_size), .data_sram_wstrb(data_wstrb),
    .data_sram_addr(data_addr), .data_sram_wdata(data_wdata),
    .data_sram_store_bank(),
    .early_sram_load_req(early_load_req),
    .early_sram_load_addr(early_load_addr),
    .data_sram_addr_is_sram(data_addr_is_sram),
    .data_sram_store_ready(1'b1),
    .data_sram_early_read_accept(data_early_read_accept),
    .data_sram_addr_ok(data_addr_ok),
    .data_sram_data_ok(data_data_ok),
    .data_sram_rdata(data_rdata),
    .data_sram_fast_ready(data_fast_ready),
    .data_sram_fast_data_ok(data_fast_data_ok),
    .data_sram_fast_rdata(data_fast_rdata)
  );

  always #5 clk = ~clk;
  always @(posedge clk)
    if ((data_req && data_addr_ok) || early_load_req)
      accepted_requests = accepted_requests + 1;

  function [`ES_TO_MS_BUS_WD-1:0] packet0;
    input [31:0] pc;
    input [31:0] addr;
    input res_from_mem;
    input mem_we;
    begin
      packet0 = {
        1'b0, 5'b0, 1'b1,
        pc, addr, 32'h55aa_aa55,
        res_from_mem, res_from_mem, mem_we, 5'd20,
        1'b0, 1'b0, 1'b0, 1'b0, 1'b0,
        1'b0, 32'b0,
        1'b0, 1'b0, 32'b0, pc + 32'd4, 1'b0,
        1'b0, 5'b0,
        1'b0, 14'b0, 32'b0, 32'b0
      };
    end
  endfunction

  function [`ES_TO_MS_BUS_1_WD-1:0] lane1_load;
    input [31:0] pc;
    input [31:0] addr;
    begin
      lane1_load = {
        pc, addr, 32'b0,
        1'b1, 1'b1, 1'b0, 5'd21,
        1'b0, 1'b0, 1'b0, 1'b0, 1'b0,
        1'b0, 32'b0,
        1'b0, 1'b0, 32'b0, pc + 32'd4, 1'b0
      };
    end
  endfunction

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "ex_early_load_tb failed");
    end
  endtask

  task reset_dut;
    begin
      @(negedge clk);
      resetn = 1'b0;
      es_valid_0 = 1'b0;
      es_valid_1 = 1'b0;
      es_bus_0 = {`ES_TO_MS_BUS_WD{1'b0}};
      es_bus_1 = {`ES_TO_MS_BUS_1_WD{1'b0}};
      data_addr_ok = 1'b0;
      data_data_ok = 1'b0;
      data_fast_ready = 1'b0;
      data_fast_data_ok = 1'b0;
      data_early_read_accept = 1'b0;
      es_load_addr_fast_0 = 32'b0;
      es_load_addr_fast_1 = 32'b0;
      repeat (3) @(posedge clk);
      @(negedge clk);
      resetn = 1'b1;
      repeat (2) @(posedge clk);
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    es_valid_0 = 1'b0;
    es_valid_1 = 1'b0;
    es_bus_0 = {`ES_TO_MS_BUS_WD{1'b0}};
    es_bus_1 = {`ES_TO_MS_BUS_1_WD{1'b0}};
    data_addr_ok = 1'b0;
    data_data_ok = 1'b0;
    data_fast_ready = 1'b0;
    data_fast_data_ok = 1'b0;
    data_rdata = 32'b0;
    data_fast_rdata = 32'b0;
    data_addr_is_sram = 1'b1;
    data_early_read_accept = 1'b0;
    es_load_addr_fast_0 = 32'b0;
    es_load_addr_fast_1 = 32'b0;
    accepted_requests = 0;

    repeat (3) @(posedge clk);
    @(negedge clk);
    resetn = 1'b1;
    repeat (2) @(posedge clk);

    // lane0 SRAM load: dedicated early request happens before the MEM edge;
    // normal addr_ok remains low because the bridge is servicing that request.
    @(negedge clk);
    es_valid_0 = 1'b1;
    es_bus_0 = packet0(32'h1c00_1000, 32'h1c40_0080, 1'b1, 1'b0);
    es_load_addr_fast_0 = 32'h1c40_0080;
    data_addr_ok = 1'b0;
    #1;
    if (!early_load_req || data_req || data_wr ||
        early_load_addr !== 23'h40_0080)
      fail("lane0 SRAM load was not issued from EX");
    @(posedge clk);
    #1;
    if (!dut.ms_early_load_probe || dut.ms_data_pending || !data_req)
      fail("MEM did not hold the early-load probe");
    @(negedge clk);
    es_valid_0 = 1'b0;
    es_bus_0 = {`ES_TO_MS_BUS_WD{1'b0}};
    es_load_addr_fast_0 = 32'b0;
    data_addr_ok = 1'b0;
    data_early_read_accept = 1'b1;
    data_data_ok = 1'b1;
    data_fast_ready = 1'b1;
    data_fast_data_ok = 1'b1;
    data_rdata = 32'hfeed_2080;
    data_fast_rdata = 32'hfeed_2080;
    @(posedge clk);
    #1;
    if (!dut.ms_data_pending || !dut.ms_response_waiting)
      fail("MEM did not adopt the registered bridge acceptance");
    if (!ms_to_ws_valid_0 || ms_to_ws_bus_0[110:79] !== 32'hfeed_2080 ||
        !load_wakeup_valid || load_wakeup_data !== 32'hfeed_2080)
      fail("early lane0 load response did not retire correctly");
    @(posedge clk);
    #1;
    if (ms_to_ws_valid_0 || accepted_requests != 1)
      fail("early lane0 load was reissued or retained");

    // An MMIO load must first enter MEM and use the original request path.
    reset_dut();
    @(negedge clk);
    es_valid_0 = 1'b1;
    es_bus_0 = packet0(32'h1c00_1010, 32'h1f00_03f8, 1'b1, 1'b0);
    es_load_addr_fast_0 = 32'h1f00_03f8;
    #1;
    if (early_load_req || data_req)
      fail("MMIO load was issued speculatively from EX");
    @(posedge clk);
    #1;
    if (!data_req || data_wr || data_addr !== 32'h1f00_03f8)
      fail("MMIO load did not use the registered MEM request path");

    // An older lane0 store blocks a lane1 SRAM load from bypassing it.
    reset_dut();
    @(negedge clk);
    es_valid_0 = 1'b1;
    es_valid_1 = 1'b1;
    es_bus_0 = packet0(32'h1c00_1020, 32'h1c40_0100, 1'b0, 1'b1);
    es_bus_1 = lane1_load(32'h1c00_1024, 32'h1c40_0200);
    es_load_addr_fast_0 = 32'h1c40_0100;
    es_load_addr_fast_1 = 32'h1c40_0200;
    #1;
    if (early_load_req || data_req)
      fail("lane1 load bypassed an older lane0 store");

    // With a non-memory lane0, lane1 may use the same early-load path.
    reset_dut();
    @(negedge clk);
    es_valid_0 = 1'b1;
    es_valid_1 = 1'b1;
    es_bus_0 = packet0(32'h1c00_1030, 32'h0000_0042, 1'b0, 1'b0);
    es_bus_1 = lane1_load(32'h1c00_1034, 32'h1c40_0300);
    es_load_addr_fast_0 = 32'h0000_0042;
    es_load_addr_fast_1 = 32'h1c40_0300;
    data_addr_ok = 1'b0;
    #1;
    if (!early_load_req || !dut.early_load_select_lane1 || data_req ||
        data_wr || early_load_addr !== 23'h40_0300)
      fail("eligible lane1 SRAM load did not issue early");
    @(posedge clk);
    #1;
    if (!dut.ms_early_load_probe || dut.ms_data_pending || !data_req)
      fail("MEM did not hold the lane1 early-load probe");
    @(negedge clk);
    es_valid_0 = 1'b0;
    es_valid_1 = 1'b0;
    data_addr_ok = 1'b0;
    data_early_read_accept = 1'b1;
    @(posedge clk);
    #1;
    if (!dut.ms_data_pending)
      fail("MEM did not adopt the lane1 registered acceptance");

    $display("PASS ex_early_load_tb");
    $finish;
  end
endmodule
