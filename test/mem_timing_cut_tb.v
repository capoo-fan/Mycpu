`timescale 1ns / 1ps
`include "mycpu.vh"

module mem_timing_cut_tb;
  reg clk;
  reg resetn;
  reg es_valid_0;
  reg es_valid_1;
  reg [`ES_TO_MS_BUS_WD-1:0] es_bus_0;
  reg [`ES_TO_MS_BUS_1_WD-1:0] es_bus_1;
  reg data_addr_ok;
  reg data_data_ok;
  reg data_addr_is_sram;
  reg [31:0] data_rdata;
  reg icacop_ready;
  reg icacop_done;
  reg [`WS_TO_RF_BUS_WD-1:0] ws_to_rf_bus;

  wire ms_allowin;
  wire ms_to_ws_valid_0;
  wire ms_to_ws_valid_1;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus_0;
  wire [`MS_TO_WS_BUS_1_WD-1:0] ms_to_ws_bus_1;
  wire [`MS_FWD_BUS_WD-1:0] ms_fwd_bus_0;
  wire [`MS_FWD_BUS_1_WD-1:0] ms_fwd_bus_1;
  wire load_wakeup_valid;
  wire [31:0] load_wakeup_data;
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
    .ws_allowin(1'b1), .ws_to_rf_bus(ws_to_rf_bus),
    .ms_allowin(ms_allowin),
    .ms_to_ws_valid_0(ms_to_ws_valid_0),
    .ms_to_ws_valid_1(ms_to_ws_valid_1),
    .ms_to_ws_bus_0(ms_to_ws_bus_0), .ms_to_ws_bus_1(ms_to_ws_bus_1),
    .ms_fwd_bus_0(ms_fwd_bus_0), .ms_fwd_bus_1(ms_fwd_bus_1),
    .load_wakeup_valid(load_wakeup_valid),
    .load_wakeup_data(load_wakeup_data),
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
    .data_sram_store_ready(1'b1),
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
        1'b0, 5'b0,
        1'b1,
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

  function [`ES_TO_MS_BUS_WD-1:0] make_late_store_packet;
    input [31:0] pc;
    input [31:0] addr;
    input [31:0] stale_data;
    input [4:0] data_src;
    reg [`ES_TO_MS_BUS_WD-1:0] packet;
    begin
      packet = make_packet(pc, addr, stale_data,
                           1'b0, 1'b0, 1'b1, 5'b0,
                           1'b0, 1'b0, 32'b0, pc + 32'd4,
                           1'b0, 1'b0, 5'b0);
      packet[`ES_TO_MS_BUS_WD-1] = 1'b1;
      packet[`ES_TO_MS_BUS_WD-2:`ES_TO_MS_BUS_WD-6] = data_src;
      make_late_store_packet = packet;
    end
  endfunction

  function [`ES_TO_MS_BUS_1_WD-1:0] make_packet_1;
    input [31:0] pc;
    input [31:0] result;
    input gr_we;
    input [4:0] dest;
    input is_bj;
    input real_taken;
    input [31:0] real_target;
    input [31:0] next_pc;
    input redirect_miss;
    begin
      make_packet_1 = {
        pc, result, 32'b0,
        1'b0, gr_we, 1'b0, dest,
        1'b0, 1'b0, 1'b0, 1'b0, 1'b0,
        1'b0, 32'b0,
        is_bj, real_taken, real_target, next_pc, redirect_miss
      };
    end
  endfunction

  function [`ES_TO_MS_BUS_1_WD-1:0] make_mem_packet_1;
    input [31:0] pc;
    input [31:0] addr;
    input [31:0] rkd;
    input res_from_mem;
    input gr_we;
    input mem_we;
    input [4:0] dest;
    input ld_byte;
    input ld_half;
    input ld_sign_ext;
    input st_byte;
    input st_half;
    begin
      make_mem_packet_1 = {
        pc, addr, rkd,
        res_from_mem, gr_we, mem_we, dest,
        ld_byte, ld_half, ld_sign_ext, st_byte, st_half,
        1'b0, 32'b0,
        1'b0, 1'b0, 32'b0, pc + 32'd4, 1'b0
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
    input [`ES_TO_MS_BUS_1_WD-1:0] packet_1;
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
      es_bus_1 = {`ES_TO_MS_BUS_1_WD{1'b0}};
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
      #1;
      if (ms_fwd_bus_0[37] && ms_fwd_bus_0[38])
        fail("external SRAM response forwarded before the register boundary");
      if (ms_fwd_bus_0[31:0] !== dut.ms_rdata_buf)
        fail("SRAM response still drives generic MEM forwarding data");
      if (!ms_allowin || !ms_to_ws_valid_0)
        fail("load did not take the data_ok-to-WB completion path");
      if (ms_to_ws_bus_0[110:79] !== response)
        fail("load completion path did not carry the SRAM response to WB");
      if (!load_wakeup_valid || load_wakeup_data !== response)
        fail("SRAM load response did not produce the controlled wakeup");
      @(posedge clk);
      #1;
      if (ms_fwd_bus_0[40])
        fail("retired load remained as a stale MEM producer");
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
    es_bus_1 = {`ES_TO_MS_BUS_1_WD{1'b0}};
    data_addr_ok = 1'b0;
    data_data_ok = 1'b0;
    data_addr_is_sram = 1'b1;
    data_rdata = 32'b0;
    icacop_ready = 1'b0;
    icacop_done = 1'b0;
    ws_to_rf_bus = {`WS_TO_RF_BUS_WD{1'b0}};
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
      1'b1, make_packet_1(32'h1c00_0004, 32'h22,
                        1'b1, 5'd3,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0008,
                        1'b0));
    if (!ms_allowin || !ms_to_ws_valid_0 || !ms_to_ws_valid_1)
      fail("ordinary dual packet did not pass MEM immediately");
    if (!ms_fwd_bus_0[38] || ms_fwd_bus_0[31:0] !== 32'h11)
      fail("ordinary ALU result lost MEM forwarding");
    @(posedge clk);
    #1;

    // A special result remains a visible producer but is never selected as
    // MEM forwarding data. Its dependent consumer must wait for WB/RF bypass.
    es_bus_0 = make_packet(32'h1c00_0008, 32'hc001_c0de, 32'b0,
                           1'b0, 1'b1, 1'b0, 5'd12,
                           1'b0, 1'b0, 32'b0, 32'h1c00_000c,
                           1'b0, 1'b0, 5'b0);
    es_bus_0[`ES_TO_MS_BUS_WD-7] = 1'b0;
    submit_pair(1'b1, es_bus_0, 1'b0, {`ES_TO_MS_BUS_1_WD{1'b0}});
    if (!ms_fwd_bus_0[40] || !ms_fwd_bus_0[39] || ms_fwd_bus_0[38] ||
        ms_fwd_bus_0[36:32] !== 5'd12 || ms_fwd_bus_0[31:0] !== 32'b0)
      fail("special result was not isolated from MEM forwarding");
    @(posedge clk);
    #1;

    // A lane0 load may pair with lane1 ALU. data_ok retires both lanes directly
    // into WB, while the external response remains isolated from MEM forwarding.
    submit_pair(
      1'b1, make_packet(32'h1c00_0010, 32'h1c40_0100, 32'b0,
                        1'b1, 1'b1, 1'b0, 5'd5,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0014,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_packet_1(32'h1c00_0014, 32'h33,
                        1'b1, 5'd4,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0018,
                        1'b0));
    if (!data_req || data_wr || data_addr !== 32'h1c40_0100 || ms_allowin)
      fail("lane0 load control was not registered correctly");
    accept_memory_response(32'h1234_5678);
    if (dut.ms_valid_0 || dut.ms_valid_1)
      fail("lane0 load pair remained in MEM after fast completion");

    // A lane0 misprediction is detected and retired in this cycle, then emits
    // exactly one registered flush pulse in the next cycle. A younger lane1
    // ALU operation in the same packet and a younger EX packet are discarded.
    submit_pair(
      1'b1, make_packet(32'h1c00_0020, 32'h1c00_0024, 32'b0,
                        1'b0, 1'b1, 1'b0, 5'd1,
                        1'b1, 1'b1, 32'h1c00_1000, 32'h1c00_0024,
                        1'b1, 1'b0, 5'b0),
      1'b1, make_packet_1(32'h1c00_0024, 32'ha5a5_5a5a,
                        1'b1, 5'd10,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0028,
                        1'b0));
    if (br_taken || br_target !== 32'b0)
      fail("lane0 redirect was not delayed by one cycle");
    if (data_req || data_wr || ms_to_ws_valid_1)
      fail("wrong-path lane1 ALU reached MEM retirement");
    if (!bpu_valid || bpu_pc !== 32'h1c00_0020)
      fail("lane0 branch update was lost");
    if (!ms_to_ws_valid_0 || !ms_to_ws_bus_0[119] ||
        ms_to_ws_bus_0[118:114] !== 5'd1 ||
        ms_to_ws_bus_0[152:121] !== 32'h1c00_0024)
      fail("mispredicted branch/link writeback was lost");

    // Present a younger store at the misprediction detection edge. MEM must
    // not capture it even though the old combinational allowin chain is open.
    es_valid_0 = 1'b1;
    es_bus_0 = make_packet(32'h1c00_0028, 32'h1c40_0220,
                           32'h55aa_aa55,
                           1'b0, 1'b0, 1'b1, 5'b0,
                           1'b0, 1'b0, 32'b0, 32'h1c00_002c,
                           1'b0, 1'b0, 5'b0);
    @(posedge clk);
    #1;
    if (!br_taken || br_target !== 32'h1c00_1000)
      fail("lane0 registered redirect was not generated one cycle later");
    if (data_req || dut.ms_valid_0 || dut.ms_valid_1 || dut.ms_mem_we_0)
      fail("younger EX store survived the registered redirect boundary");
    @(negedge clk);
    es_valid_0 = 1'b0;
    es_bus_0 = {`ES_TO_MS_BUS_WD{1'b0}};
    @(posedge clk);
    #1;
    if (br_taken)
      fail("lane0 registered redirect pulse lasted more than one cycle");

    // A correctly predicted lane0 branch retains a younger lane1 ALU result.
    submit_pair(
      1'b1, make_packet(32'h1c00_0030, 32'b0, 32'b0,
                        1'b0, 1'b0, 1'b0, 5'b0,
                        1'b1, 1'b0, 32'b0, 32'h1c00_0034,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_packet_1(32'h1c00_0034, 32'h66,
                        1'b1, 5'd8,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0038,
                        1'b0));
    if (data_req || br_taken || !ms_to_ws_valid_0 || !ms_to_ws_valid_1)
      fail("correct-path lane1 ALU was not retained");

    // Stores are lane0-only and may still pair with an independent lane1 ALU.
    submit_pair(
      1'b1, make_packet(32'h1c00_0038, 32'h1c40_0300,
                        32'hcafe_babe,
                        1'b0, 1'b0, 1'b1, 5'b0,
                        1'b0, 1'b0, 32'b0, 32'h1c00_003c,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_packet_1(32'h1c00_003c, 32'h77,
                        1'b1, 5'd9,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0040,
                        1'b0));
    if (!data_req || !data_wr || data_addr !== 32'h1c40_0300 ||
        data_wdata !== 32'hcafe_babe || br_taken)
      fail("lane0 store plus lane1 ALU was not retained");
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
      1'b1, make_packet_1(32'h1c00_003c, 32'h66,
                        1'b1, 5'd8,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0040,
                        1'b0));
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
      1'b0, {`ES_TO_MS_BUS_1_WD{1'b0}});
    if (data_req || ms_allowin)
      fail("younger load bypassed a pending posted store");
    complete_memory_response(32'b0);
    if (!data_req || data_wr || data_addr !== 32'h1c40_0400)
      fail("younger load did not issue after posted store completion");
    accept_memory_response(32'h89ab_cdef);
    if (dut.ms_valid_0)
      fail("younger load remained in MEM after its own response");
    if (accepted_data_requests != 3)
      fail("unexpected number of accepted memory requests");

    // MMIO/non-SRAM stores retain the original data_ok retirement contract.
    data_addr_is_sram = 1'b0;
    submit_pair(
      1'b1, make_packet(32'h1c00_0040, 32'h1f00_03f8, 32'h0000_0047,
                        1'b0, 1'b0, 1'b1, 5'b0,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0044,
                        1'b0, 1'b0, 5'b0),
      1'b0, {`ES_TO_MS_BUS_1_WD{1'b0}});
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

    // A late store data tag may also be resolved by the registered WB bus.
    // Lane1 has the same priority as the register file's write-through bypass.
    ws_to_rf_bus = {1'b0, 5'b0, 32'b0,
                    1'b1, 5'd13, 32'h7654_3210};
    submit_pair(
      1'b1, make_late_store_packet(32'h1c00_0048, 32'h1c40_0500,
                                   32'hdead_beef, 5'd13),
      1'b0, {`ES_TO_MS_BUS_1_WD{1'b0}});
    if (!data_req || !data_wr || data_addr !== 32'h1c40_0500 ||
        data_wdata !== 32'h7654_3210)
      fail("late store data was not captured from WB");
    accept_memory_address();
    complete_memory_response(32'b0);
    ws_to_rf_bus = {`WS_TO_RF_BUS_WD{1'b0}};

    // A lane1-only byte load reuses the single memory port and returns its
    // already-extended value through the existing 32-bit lane1 WB payload.
    submit_pair(
      1'b1, make_packet(32'h1c00_0050, 32'h1234_5678, 32'b0,
                        1'b0, 1'b1, 1'b0, 5'd14,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0054,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_mem_packet_1(32'h1c00_0054, 32'h1c40_0603, 32'b0,
                              1'b1, 1'b1, 1'b0, 5'd15,
                              1'b1, 1'b0, 1'b1, 1'b0, 1'b0));
    if (!data_req || data_wr || data_size !== 2'b00 ||
        data_addr !== 32'h1c40_0603 || ms_allowin)
      fail("lane1 byte load did not select the shared memory port");
    @(negedge clk);
    data_addr_ok = 1'b1;
    @(posedge clk);
    #1;
    @(negedge clk);
    data_addr_ok = 1'b0;
    data_rdata = 32'h80aa_bbcc;
    data_data_ok = 1'b1;
    #1;
    if (!ms_allowin || !ms_to_ws_valid_0 || !ms_to_ws_valid_1 ||
        ms_to_ws_bus_1[37:6] !== 32'hffff_ff80)
      fail("lane1 signed byte load result did not reach WB");
    @(posedge clk);
    #1;
    @(negedge clk);
    data_data_ok = 1'b0;

    // Dual memory packets retire lane0 first, then reuse the same request
    // state for lane1. The second request must not overlap the first response.
    submit_pair(
      1'b1, make_packet(32'h1c00_0058, 32'h1c40_0700, 32'b0,
                        1'b1, 1'b1, 1'b0, 5'd16,
                        1'b0, 1'b0, 32'b0, 32'h1c00_005c,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_mem_packet_1(32'h1c00_005c, 32'h1c40_0802,
                              32'h0000_a55a,
                              1'b0, 1'b0, 1'b1, 5'b0,
                              1'b0, 1'b0, 1'b0, 1'b0, 1'b1));
    if (!data_req || data_wr || data_addr !== 32'h1c40_0700)
      fail("dual load/store packet did not issue lane0 first");
    accept_memory_address();
    @(negedge clk);
    data_rdata = 32'h1357_9bdf;
    data_data_ok = 1'b1;
    #1;
    if (ms_allowin || !ms_to_ws_valid_0 || ms_to_ws_valid_1)
      fail("dual memory packet did not retire only lane0 first");
    @(posedge clk);
    #1;
    @(negedge clk);
    data_data_ok = 1'b0;
    if (!data_req || !data_wr || data_addr !== 32'h1c40_0802 ||
        data_size !== 2'b01 || data_wstrb !== 4'b1100 ||
        data_wdata !== 32'ha55a_a55a)
      fail("lane1 halfword store did not follow lane0 load");
    accept_memory_address();
    if (!ms_allowin || ms_to_ws_valid_0 || !ms_to_ws_valid_1)
      fail("final lane1 posted store did not retire the packet");
    @(posedge clk);
    #1;
    complete_memory_response(32'b0);

    // A posted lane0 store may retire early, but lane1 load cannot issue until
    // the store's data_ok has released the single outstanding transaction.
    submit_pair(
      1'b1, make_packet(32'h1c00_0060, 32'h1c40_0900, 32'hcafe_babe,
                        1'b0, 1'b0, 1'b1, 5'b0,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0064,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_mem_packet_1(32'h1c00_0064, 32'h1c40_0a00, 32'b0,
                              1'b1, 1'b1, 1'b0, 5'd17,
                              1'b0, 1'b0, 1'b0, 1'b0, 1'b0));
    if (!data_req || !data_wr || data_addr !== 32'h1c40_0900)
      fail("dual store/load packet did not issue lane0 store first");
    accept_memory_address();
    if (!ms_to_ws_valid_0 || ms_to_ws_valid_1 || ms_allowin)
      fail("lane0 posted store phase retirement was incorrect");
    @(posedge clk);
    #1;
    if (data_req)
      fail("lane1 load overlapped pending lane0 posted store");
    complete_memory_response(32'b0);
    if (!data_req || data_wr || data_addr !== 32'h1c40_0a00)
      fail("lane1 load did not start after lane0 store data_ok");
    @(negedge clk);
    data_addr_ok = 1'b1;
    @(posedge clk);
    #1;
    @(negedge clk);
    data_addr_ok = 1'b0;
    data_rdata = 32'h2468_ace0;
    data_data_ok = 1'b1;
    #1;
    if (!ms_allowin || ms_to_ws_valid_0 || !ms_to_ws_valid_1 ||
        ms_to_ws_bus_1[37:6] !== 32'h2468_ace0 || load_wakeup_valid)
      fail("final lane1 load did not retire without lane0 wakeup");
    @(posedge clk);
    #1;
    @(negedge clk);
    data_data_ok = 1'b0;

    // Load/load uses the same two phases and returns each result on its
    // architectural writeback lane.
    submit_pair(
      1'b1, make_packet(32'h1c00_0068, 32'h1c40_0b00, 32'b0,
                        1'b1, 1'b1, 1'b0, 5'd18,
                        1'b0, 1'b0, 32'b0, 32'h1c00_006c,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_mem_packet_1(32'h1c00_006c, 32'h1c40_0c00, 32'b0,
                              1'b1, 1'b1, 1'b0, 5'd19,
                              1'b0, 1'b0, 1'b0, 1'b0, 1'b0));
    if (!data_req || data_wr || data_addr !== 32'h1c40_0b00)
      fail("dual load/load packet did not issue lane0 first");
    accept_memory_address();
    @(negedge clk);
    data_rdata = 32'h1111_2222;
    data_data_ok = 1'b1;
    #1;
    if (!ms_to_ws_valid_0 || ms_to_ws_valid_1 || ms_allowin)
      fail("dual load/load packet did not retire lane0 alone");
    @(posedge clk);
    #1;
    @(negedge clk);
    data_data_ok = 1'b0;
    if (!data_req || data_wr || data_addr !== 32'h1c40_0c00)
      fail("dual load/load packet did not issue lane1 second");
    @(negedge clk);
    data_addr_ok = 1'b1;
    @(posedge clk);
    #1;
    @(negedge clk);
    data_addr_ok = 1'b0;
    data_rdata = 32'h3333_4444;
    data_data_ok = 1'b1;
    #1;
    if (ms_to_ws_valid_0 || !ms_to_ws_valid_1 || !ms_allowin ||
        ms_to_ws_bus_1[37:6] !== 32'h3333_4444)
      fail("dual load/load packet did not retire lane1 result");
    @(posedge clk);
    #1;
    @(negedge clk);
    data_data_ok = 1'b0;

    // Store/store also waits for lane0 data_ok before exposing lane1's address.
    submit_pair(
      1'b1, make_packet(32'h1c00_0070, 32'h1c40_0d00, 32'h5555_aaaa,
                        1'b0, 1'b0, 1'b1, 5'b0,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0074,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_mem_packet_1(32'h1c00_0074, 32'h1c40_0e01,
                              32'h0000_00c3,
                              1'b0, 1'b0, 1'b1, 5'b0,
                              1'b0, 1'b0, 1'b0, 1'b1, 1'b0));
    if (!data_req || !data_wr || data_addr !== 32'h1c40_0d00)
      fail("dual store/store packet did not issue lane0 first");
    accept_memory_address();
    if (!ms_to_ws_valid_0 || ms_to_ws_valid_1 || ms_allowin)
      fail("dual store/store lane0 posted retirement was incorrect");
    @(posedge clk);
    #1;
    if (data_req)
      fail("lane1 store overlapped pending lane0 store");
    complete_memory_response(32'b0);
    if (!data_req || !data_wr || data_addr !== 32'h1c40_0e01 ||
        data_size !== 2'b00 || data_wstrb !== 4'b0010 ||
        data_wdata !== 32'hc3c3_c3c3)
      fail("dual store/store packet did not issue lane1 byte store");
    accept_memory_address();
    if (ms_to_ws_valid_0 || !ms_to_ws_valid_1 || !ms_allowin)
      fail("dual store/store packet did not retire lane1 last");
    @(posedge clk);
    #1;
    complete_memory_response(32'b0);

    // A lane1 branch follows the same one-cycle redirect contract and trains
    // using lane1 PC while both instructions still retire on the detect cycle.
    submit_pair(
      1'b1, make_packet(32'h1c00_0040, 32'h44, 32'b0,
                        1'b0, 1'b1, 1'b0, 5'd6,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0044,
                        1'b0, 1'b0, 5'b0),
      1'b1, make_packet_1(32'h1c00_0044, 32'b0,
                        1'b0, 5'b0,
                        1'b1, 1'b1, 32'h1c00_2000, 32'h1c00_0048,
                        1'b1));
    if (br_taken || !bpu_valid || bpu_pc !== 32'h1c00_0044 ||
        !ms_to_ws_valid_0 || !ms_to_ws_valid_1)
      fail("lane1 branch detect/update/retirement failed");
    @(posedge clk);
    #1;
    if (!br_taken || br_target !== 32'h1c00_2000)
      fail("lane1 registered redirect target failed");
    @(posedge clk);
    #1;
    if (br_taken)
      fail("lane1 registered redirect pulse lasted more than one cycle");

    // CACOP uses the registered cold wait state, requests once, and flushes at PC+4.
    submit_pair(
      1'b1, make_packet(32'h1c00_0050, 32'h1c00_0080, 32'b0,
                        1'b0, 1'b0, 1'b0, 5'b0,
                        1'b0, 1'b0, 32'b0, 32'h1c00_0054,
                        1'b0, 1'b1, 5'h10),
      1'b0, {`ES_TO_MS_BUS_1_WD{1'b0}});
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
