`timescale 1ns / 1ps
`include "mycpu.vh"

module mem_timing_cut_tb;
  reg clk;
  reg resetn;
  reg es_valid_0;
  reg es_valid_1;
  reg [`ES_TO_MS_BUS_WD-1:0] es_bus_0;
  reg [`ES_TO_MS_BUS_WD-1:0] es_bus_1;
  reg data_addr_ok;
  reg data_data_ok;
  reg data_addr_is_sram;
  reg [31:0] data_rdata;
  reg icacop_ready;
  reg icacop_done;

  wire ms_allowin;
  wire ms_to_ws_valid_0;
  wire ms_to_ws_valid_1;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus_0;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus_1;
  wire br_taken;
  wire [31:0] br_target;
  wire bpu_valid;
  wire [31:0] bpu_pc;
  wire data_req;
  wire data_wr;
  wire [1:0] data_size;
  wire [3:0] data_wstrb;
  wire [31:0] data_addr;
  wire [31:0] data_wdata;
  wire icacop_req_valid;
  wire [4:0] icacop_req_code;
  wire [31:0] icacop_req_addr;
  wire cacop_flush;
  wire [31:0] cacop_flush_target;
  integer accepted_data_requests;

  MEM_stage dut(
    .clk(clk), .resetn(resetn),
    .es_to_ms_valid_0(es_valid_0), .es_to_ms_valid_1(es_valid_1),
    .es_to_ms_bus_0(es_bus_0), .es_to_ms_bus_1(es_bus_1),
    .ws_allowin(1'b1), .ms_allowin(ms_allowin),
    .ms_to_ws_valid_0(ms_to_ws_valid_0),
    .ms_to_ws_valid_1(ms_to_ws_valid_1),
    .ms_to_ws_bus_0(ms_to_ws_bus_0), .ms_to_ws_bus_1(ms_to_ws_bus_1),
    .ms_fwd_bus_0(), .ms_fwd_bus_1(),
    .csr_busy(), .cacop_busy(),
    .br_taken(br_taken), .br_target(br_target),
    .bpu_valid(bpu_valid), .bpu_is_bj(), .bpu_pc(bpu_pc),
    .bpu_real_taken(), .bpu_real_target(),
    .icacop_req_valid(icacop_req_valid),
    .icacop_req_code(icacop_req_code),
    .icacop_req_addr(icacop_req_addr),
    .icacop_req_ready(icacop_ready), .icacop_done(icacop_done),
    .cacop_flush(cacop_flush), .cacop_flush_target(cacop_flush_target),
    .data_sram_req(data_req), .data_sram_wr(data_wr),
    .data_sram_size(data_size), .data_sram_wstrb(data_wstrb),
    .data_sram_addr(data_addr), .data_sram_wdata(data_wdata),
    .data_sram_addr_is_sram(data_addr_is_sram),
    .data_sram_addr_ok(data_addr_ok), .data_sram_data_ok(data_data_ok),
    .data_sram_rdata(data_rdata)
  );

  always #5 clk = ~clk;
  always @(posedge clk)
    if (data_req && data_addr_ok)
      accepted_data_requests = accepted_data_requests + 1;

  function [`ES_TO_MS_BUS_WD-1:0] make_packet;
    input [31:0] pc;
    input [31:0] result;
    input [31:0] rkd;
    input res_from_mem;
    input gr_we;
    input mem_we;
    input [4:0] dest;
    input is_bj;
    input real_taken;
    input [31:0] real_target;
    input [31:0] next_pc;
    input redirect_miss;
    input is_cacop;
    input [4:0] cacop_code;
    begin
      make_packet = {
        pc, result, rkd,
        res_from_mem, gr_we, mem_we, dest,
        1'b0, 1'b0, 1'b0, 1'b0, 1'b0,
        1'b0, 32'b0,
        is_bj, real_taken, real_target, next_pc, redirect_miss,
        is_cacop, cacop_code,
        1'b0, 14'b0, 32'b0, 32'b0
      };
    end
  endfunction

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "mem_timing_cut_tb failed");
    end
  endtask

  task submit_pair;
    input valid_0;
    input [`ES_TO_MS_BUS_WD-1:0] packet_0;
    input valid_1;
    input [`ES_TO_MS_BUS_WD-1:0] packet_1;
    begin
      while (!ms_allowin)
        @(posedge clk);
      @(negedge clk);
      es_valid_0 = valid_0;
      es_valid_1 = valid_1;
      es_bus_0 = packet_0;
      es_bus_1 = packet_1;
      @(posedge clk);
      #1;
      @(negedge clk);
      es_valid_0 = 1'b0;
      es_valid_1 = 1'b0;
      es_bus_0 = {`ES_TO_MS_BUS_WD{1'b0}};
      es_bus_1 = {`ES_TO_MS_BUS_WD{1'b0}};
    end
  endtask

  task accept_memory_response;
    input [31:0] response;
    begin
      if (!data_req)
        fail("memory request missing before address acceptance");
      @(negedge clk);
      data_addr_ok = 1'b1;
      @(posedge clk);
      #1;
      @(negedge clk);
      data_addr_ok = 1'b0;
      data_rdata = response;
      data_data_ok = 1'b1;
      @(posedge clk);
      #1;
      @(negedge clk);
      data_data_ok = 1'b0;
    end
  endtask

  task accept_memory_address;
    begin
      if (!data_req)
        fail("memory request missing before address acceptance");
      @(negedge clk);
      data_addr_ok = 1'b1;
      @(posedge clk);
      #1;
      @(negedge clk);
      data_addr_ok = 1'b0;
    end
  endtask

  task complete_memory_response;
    input [31:0] response;
    begin
      @(negedge clk);
      data_rdata = response;
      data_data_ok = 1'b1;
      @(posedge clk);
      #1;
      @(negedge clk);
      data_data_ok = 1'b0;
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    es_valid_0 = 1'b0;
    es_valid_1 = 1'b0;
    es_bus_0 = {`ES_TO_MS_BUS_WD{1'b0}};
    es_bus_1 = {`ES_TO_MS_BUS_WD{1'b0}};
    data_addr_ok = 1'b0;
    data_data_ok = 1'b0;
    data_addr_is_sram = 1'b1;
    data_rdata = 32'b0;
    icacop_ready = 1'b0;
    icacop_done = 1'b0;
    accepted_data_requests = 0;

    repeat (4) @(posedge clk);
    @(negedge clk);
    resetn = 1'b1;
    repeat (3) @(posedge clk);
    #1;
    if (!ms_allowin)
      fail("MEM did not become ready after reset");

    // Ordinary dual issue remains a one-cycle pass-through packet.
    submit_pair(
      1'b1, make_packet(32'h1c00_0000, 32'h11, 32'b0,
                        1'b0, 1'b1, 1'b0, 5'd2,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0004,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_packet(32'h1c00_0004, 32'h22, 32'b0,
                        1'b0, 1'b1, 1'b0, 5'd3,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0008,
                        1'b0, 1'b0, 5'b0));
    if (!ms_allowin || !ms_to_ws_valid_0 || !ms_to_ws_valid_1)
      fail("ordinary dual packet did not pass MEM immediately");
    @(posedge clk);
    #1;

    // A lane1 load selects lane1 address and blocks until data completion.
    submit_pair(
      1'b1, make_packet(32'h1c00_0010, 32'h33, 32'b0,
                        1'b0, 1'b1, 1'b0, 5'd4,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0014,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_packet(32'h1c00_0014, 32'h1c40_0100, 32'b0,
                        1'b1, 1'b1, 1'b0, 5'd5,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0018,
                        1'b0, 1'b0, 5'b0));
    if (!data_req || data_wr || data_addr !== 32'h1c40_0100 || ms_allowin)
      fail("lane1 load control was not registered correctly");
    accept_memory_response(32'h1234_5678);
    if (!ms_allowin || !ms_to_ws_valid_0 || !ms_to_ws_valid_1)
      fail("lane1 load did not release both lanes after data completion");
    @(posedge clk);
    #1;

    // A lane0 misprediction must kill a younger lane1 store before it can request SRAM.
    submit_pair(
      1'b1, make_packet(32'h1c00_0020, 32'b0, 32'b0,
                        1'b0, 1'b0, 1'b0, 5'b0,
                        1'b1, 1'b1, 32'h1c00_1000, 32'h1c00_0024,
                        1'b1, 1'b0, 5'b0),
      1'b1, make_packet(32'h1c00_0024, 32'h1c40_0200, 32'ha5a5_5a5a,
                        1'b0, 1'b0, 1'b1, 5'b0,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0028,
                        1'b0, 1'b0, 5'b0));
    if (!br_taken || br_target !== 32'h1c00_1000)
      fail("lane0 redirect was not generated");
    if (data_req || data_wr || ms_to_ws_valid_1)
      fail("wrong-path lane1 store reached MEM side effects");
    if (!bpu_valid || bpu_pc !== 32'h1c00_0020)
      fail("lane0 branch update was lost");
    @(posedge clk);
    #1;

    // A correctly predicted lane0 branch may retain a younger lane1 store.
    submit_pair(
      1'b1, make_packet(32'h1c00_0030, 32'b0, 32'b0,
                        1'b0, 1'b0, 1'b0, 5'b0,
                        1'b1, 1'b0, 32'b0, 32'h1c00_0034,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_packet(32'h1c00_0034, 32'h1c40_0300, 32'hcafe_babe,
                        1'b0, 1'b0, 1'b1, 5'b0,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0038,
                        1'b0, 1'b0, 5'b0));
    if (!data_req || !data_wr || data_addr !== 32'h1c40_0300 ||
        data_wdata !== 32'hcafe_babe || br_taken)
      fail("correct-path lane1 store was not retained");
    accept_memory_address();
    if (!ms_allowin || !ms_to_ws_valid_0 || !ms_to_ws_valid_1)
      fail("accepted SRAM store did not retire before data completion");
    if (!dut.ms_data_pending || data_data_ok)
      fail("posted SRAM store lost its pending response state");

    // A non-memory packet may pass while the posted store response is pending.
    submit_pair(
      1'b1, make_packet(32'h1c00_0038, 32'h55, 32'b0,
                        1'b0, 1'b1, 1'b0, 5'd7,
                        1'b0, 1'b0, 32'b0, 32'h1c00_003c,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_packet(32'h1c00_003c, 32'h66, 32'b0,
                        1'b0, 1'b1, 1'b0, 5'd8,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0040,
                        1'b0, 1'b0, 5'b0));
    if (!ms_allowin || !ms_to_ws_valid_0 || !ms_to_ws_valid_1 ||
        !dut.ms_data_pending)
      fail("posted store response blocked an independent ALU packet");

    // A younger memory packet may enter MEM, but it must not issue its request
    // until the posted store response has completed.
    submit_pair(
      1'b1, make_packet(32'h1c00_0040, 32'h1c40_0400, 32'b0,
                        1'b1, 1'b1, 1'b0, 5'd9,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0044,
                        1'b0, 1'b0, 5'b0),
      1'b0, {`ES_TO_MS_BUS_WD{1'b0}});
    if (data_req || ms_allowin)
      fail("younger load bypassed a pending posted store");
    complete_memory_response(32'b0);
    if (!data_req || data_wr || data_addr !== 32'h1c40_0400)
      fail("younger load did not issue after posted store completion");
    accept_memory_response(32'h89ab_cdef);
    if (!ms_allowin || !ms_to_ws_valid_0)
      fail("younger load did not retire after its own response");
    if (accepted_data_requests != 3)
      fail("unexpected number of accepted memory requests");
    @(posedge clk);
    #1;

    // MMIO/non-SRAM stores retain the original data_ok retirement contract.
    data_addr_is_sram = 1'b0;
    submit_pair(
      1'b1, make_packet(32'h1c00_0040, 32'h1f00_03f8, 32'h0000_0047,
                        1'b0, 1'b0, 1'b1, 5'b0,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0044,
                        1'b0, 1'b0, 5'b0),
      1'b0, {`ES_TO_MS_BUS_WD{1'b0}});
    if (!data_req || !data_wr || ms_allowin)
      fail("non-SRAM store request did not wait for address acceptance");
    accept_memory_address();
    if (ms_allowin || ms_to_ws_valid_0)
      fail("non-SRAM store retired before data completion");
    complete_memory_response(32'b0);
    if (!ms_allowin || !ms_to_ws_valid_0)
      fail("non-SRAM store did not retire after data completion");
    data_addr_is_sram = 1'b1;
    if (accepted_data_requests != 4)
      fail("unexpected request count after non-SRAM store");
    @(posedge clk);
    #1;

    // A lane1 branch still redirects and trains using lane1 PC.
    submit_pair(
      1'b1, make_packet(32'h1c00_0040, 32'h44, 32'b0,
                        1'b0, 1'b1, 1'b0, 5'd6,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0044,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_packet(32'h1c00_0044, 32'b0, 32'b0,
                        1'b0, 1'b0, 1'b0, 5'b0,
                        1'b1, 1'b1, 32'h1c00_2000, 32'h1c00_0048,
                        1'b1, 1'b0, 5'b0));
    if (!br_taken || br_target !== 32'h1c00_2000 ||
        !bpu_valid || bpu_pc !== 32'h1c00_0044)
      fail("lane1 branch redirect/update failed");
    @(posedge clk);
    #1;

    // CACOP uses the registered cold wait state, requests once, and flushes at PC+4.
    submit_pair(
      1'b1, make_packet(32'h1c00_0050, 32'h1c00_0080, 32'b0,
                        1'b0, 1'b0, 1'b0, 5'b0,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0054,
                        1'b0, 1'b1, 5'h10),
      1'b0, {`ES_TO_MS_BUS_WD{1'b0}});
    if (!icacop_req_valid || icacop_req_code !== 5'h10 ||
        icacop_req_addr !== 32'h1c00_0080 || ms_allowin)
      fail("CACOP request state was not registered correctly");
    @(negedge clk);
    icacop_ready = 1'b1;
    @(posedge clk);
    #1;
    @(negedge clk);
    icacop_ready = 1'b0;
    if (icacop_req_valid)
      fail("CACOP request was issued more than once");
    icacop_done = 1'b1;
    #1;
    if (!cacop_flush || cacop_flush_target !== 32'h1c00_0054 || !ms_allowin)
      fail("CACOP completion did not release and flush MEM");
    @(posedge clk);
    #1;
    @(negedge clk);
    icacop_done = 1'b0;

    $display("PASS mem_timing_cut_tb");
    $finish;
  end
endmodule
