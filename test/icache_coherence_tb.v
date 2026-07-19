`timescale 1ns / 1ps
`include "mycpu.vh"

module icache_coherence_tb;
  reg         clk;
  reg         resetn;
  reg         pc_inst_req;
  reg  [31:0] pc;
  reg  [31:0] pc_paddr;
  reg         br_taken;
  reg         icacop_req_valid;
  reg  [4:0]  icacop_req_code;
  reg  [31:0] icacop_req_addr;
  wire        icacop_req_ready;
  wire        icacop_done;
  reg         store_inv_valid;
  reg  [31:0] store_inv_addr;
  reg         txn_accept;
  reg         txn_store;
  reg  [31:0] txn_paddr;
  reg         txn_data_ok;
  wire        txn_store_inv_valid;
  wire [31:0] txn_store_inv_addr;
  wire        combined_store_inv_valid = store_inv_valid || txn_store_inv_valid;
  wire [31:0] combined_store_inv_addr = txn_store_inv_valid ?
       txn_store_inv_addr : store_inv_addr;
  reg         ibuf_allowin;
  wire        fs_valid_0;
  wire        fs_valid_1;
  wire [`FS_TO_DS_BUS_WD-1:0] fs_bus_0;
  wire [`FS_TO_DS_BUS_WD-1:0] fs_bus_1;
  wire        if_suspend;
  wire        rd_req;
  wire [31:0] rd_addr;
  reg         rd_rdy;
  reg         ret_valid;
  reg  [1:0]  ret_last;
  reg  [31:0] ret_data;

  integer refill_request_count;
  integer output_count;
  integer cycles;
  reg [31:0] first_output_inst;
  reg        refill_drained;

  IF_stage dut(
    .clk(clk), .resetn(resetn),
    .pc_inst_req(pc_inst_req), .pc(pc), .pc_paddr(pc_paddr),
    .bpu_pred_taken_0(1'b0), .bpu_pred_target_0(32'b0),
    .bpu_pred_taken_1(1'b0), .bpu_pred_target_1(32'b0),
    .br_taken(br_taken),
    .icacop_req_valid(icacop_req_valid),
    .icacop_req_code(icacop_req_code),
    .icacop_req_addr(icacop_req_addr),
    .icacop_req_ready(icacop_req_ready), .icacop_done(icacop_done),
    .store_inv_valid(combined_store_inv_valid),
    .store_inv_addr(combined_store_inv_addr),
    .ibuf_allowin(ibuf_allowin),
    .fs_to_ds_valid_0(fs_valid_0), .fs_to_ds_valid_1(fs_valid_1),
    .fs_to_ds_bus_0(fs_bus_0), .fs_to_ds_bus_1(fs_bus_1),
    .if_suspend(if_suspend),
    .rd_req(rd_req), .rd_addr(rd_addr), .rd_rdy(rd_rdy),
    .ret_valid(ret_valid), .ret_last(ret_last), .ret_data(ret_data)
  );

  data_txn_tracker txn_tracker(
    .clk(clk), .resetn(resetn),
    .txn_accept(txn_accept), .txn_store(txn_store),
    .txn_paddr(txn_paddr), .txn_data_ok(txn_data_ok),
    .store_inv_valid(txn_store_inv_valid),
    .store_inv_addr(txn_store_inv_addr)
  );

  always #5 clk = ~clk;

  always @(posedge clk) begin
    if (rd_req && rd_rdy)
      refill_request_count = refill_request_count + 1;
    if (fs_valid_0) begin
      if (output_count == 0)
        first_output_inst = fs_bus_0[`FS_TO_DS_BUS_WD-33 -: 32];
      output_count = output_count + 1;
    end
  end

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "icache_coherence_tb failed");
    end
  endtask

  task pulse_store_invalidate;
    input [31:0] addr_value;
    begin
      @(negedge clk);
      store_inv_addr  = addr_value;
      store_inv_valid = 1'b1;
      @(posedge clk);
      #1;
      @(negedge clk);
      store_inv_valid = 1'b0;
    end
  endtask

  task pulse_cacop;
    input [4:0] code_value;
    input [31:0] addr_value;
    begin
      while (!icacop_req_ready)
        @(posedge clk);
      @(negedge clk);
      icacop_req_code  = code_value;
      icacop_req_addr  = addr_value;
      icacop_req_valid = 1'b1;
      @(posedge clk);
      #1;
      @(negedge clk);
      icacop_req_valid = 1'b0;
      while (!icacop_done)
        @(posedge clk);
      #1;
    end
  endtask

  task send_refill;
    input [31:0] word0;
    input [31:0] word1;
    input [31:0] word2;
    input [31:0] word3;
    input        invalidate_on_first_beat;
    integer beat;
    begin
      for (beat = 0; beat < 4; beat = beat + 1) begin
        @(negedge clk);
        ret_valid = 1'b1;
        ret_last  = (beat == 3) ? 2'b01 : 2'b00;
        case (beat)
          0: ret_data = word0;
          1: ret_data = word1;
          2: ret_data = word2;
          default: ret_data = word3;
        endcase
        if (invalidate_on_first_beat && beat == 0) begin
          store_inv_valid = 1'b1;
          store_inv_addr  = 32'h1c00_0000;
        end else begin
          store_inv_valid = 1'b0;
        end
        @(posedge clk);
        #1;
      end
      @(negedge clk);
      ret_valid        = 1'b0;
      ret_last         = 2'b0;
      ret_data         = 32'b0;
      store_inv_valid  = 1'b0;
    end
  endtask

  initial begin
    clk                  = 1'b0;
    resetn               = 1'b0;
    pc_inst_req          = 1'b0;
    pc                   = 32'h1c00_0000;
    pc_paddr             = 32'h1c00_0000;
    br_taken             = 1'b0;
    icacop_req_valid     = 1'b0;
    icacop_req_code      = 5'b0;
    icacop_req_addr      = 32'b0;
    store_inv_valid      = 1'b0;
    store_inv_addr       = 32'b0;
    txn_accept            = 1'b0;
    txn_store             = 1'b0;
    txn_paddr             = 32'b0;
    txn_data_ok           = 1'b0;
    ibuf_allowin         = 1'b1;
    rd_rdy               = 1'b1;
    ret_valid            = 1'b0;
    ret_last             = 2'b0;
    ret_data             = 32'b0;
    refill_request_count = 0;
    output_count         = 0;
    first_output_inst    = 32'b0;

    repeat (4) @(posedge clk);
    resetn = 1'b1;
    repeat (3) @(posedge clk);

    // A completed BaseRAM store invalidates only the matching physical line.
    @(negedge clk);
    dut.cache_valid[0][3] = 1'b1;
    dut.cache_tag_way0[3] = 32'h1c00_0030 >> 7;
    dut.cache_valid[1][3] = 1'b1;
    dut.cache_tag_way1[3] = 32'h1d00_0030 >> 7;
    pulse_store_invalidate(32'h1c00_0034);
    if (dut.cache_valid[0][3] !== 1'b0 || dut.cache_valid[1][3] !== 1'b1)
      fail("store invalidation did not select the matching I-cache line");

    // The production tracker must use the accepted store line even when the
    // live MEM/translation outputs change before data_ok returns.
    @(negedge clk);
    dut.cache_valid[0][1] = 1'b1;
    dut.cache_tag_way0[1] = 32'h1c00_0010 >> 7;
    dut.cache_valid[1][2] = 1'b1;
    dut.cache_tag_way1[2] = 32'h1c00_0020 >> 7;
    txn_accept = 1'b1;
    txn_store  = 1'b1;
    txn_paddr  = 32'h1c00_0014;
    @(posedge clk);
    #1;
    @(negedge clk);
    txn_accept  = 1'b0;
    txn_store   = 1'b0;
    txn_paddr   = 32'h1c00_0024;
    txn_data_ok = 1'b1;
    @(posedge clk);
    #1;
    @(negedge clk);
    txn_data_ok      = 1'b0;
    if (dut.cache_valid[0][1] !== 1'b0 || dut.cache_valid[1][2] !== 1'b1)
      fail("store response used the changed live MEM address");

    // cacop 0x00 uses address bit 0 as way and bits 6:4 as index.
    @(negedge clk);
    dut.cache_valid[1][4] = 1'b1;
    dut.cache_tag_way1[4] = 25'h12345;
    pulse_cacop(5'h00, 32'h0000_0041);
    if (dut.cache_valid[1][4] !== 1'b0)
      fail("cacop 0x00 did not invalidate the selected way/index");

    // cacop 0x08 has the same way/index addressing mode for I-cache.
    @(negedge clk);
    dut.cache_valid[0][6] = 1'b1;
    dut.cache_tag_way0[6] = 25'h23456;
    pulse_cacop(5'h08, 32'h0000_0060);
    if (dut.cache_valid[0][6] !== 1'b0)
      fail("cacop 0x08 did not invalidate the selected way/index");

    // cacop 0x10 invalidates the way whose physical tag hits.
    @(negedge clk);
    dut.cache_valid[0][2] = 1'b1;
    dut.cache_tag_way0[2] = 32'h1c00_0020 >> 7;
    dut.cache_valid[1][2] = 1'b1;
    dut.cache_tag_way1[2] = 32'h1d00_0020 >> 7;
    pulse_cacop(5'h10, 32'h1c00_0024);
    if (dut.cache_valid[0][2] !== 1'b0 || dut.cache_valid[1][2] !== 1'b1)
      fail("cacop 0x10 did not invalidate only the matching physical tag");

    // D-cache cacop encodings legally retire but must not alter I-cache state.
    @(negedge clk);
    dut.cache_valid[0][5] = 1'b1;
    dut.cache_tag_way0[5] = 25'h54321;
    pulse_cacop(5'h01, 32'h0000_0050);
    pulse_cacop(5'h09, 32'h0000_0050);
    if (dut.cache_valid[0][5] !== 1'b1)
      fail("D-cache cacop encoding modified I-cache state");

    // Reset, start a miss, then write the same BaseRAM line during refill.
    resetn = 1'b0;
    repeat (4) @(posedge clk);
    resetn = 1'b1;
    repeat (3) @(posedge clk);
    refill_request_count = 0;
    output_count         = 0;
    first_output_inst    = 32'b0;
    pc_inst_req          = 1'b1;

    cycles = 0;
    while (refill_request_count < 1) begin
      @(posedge clk);
      #1;
      cycles = cycles + 1;
      if (cycles > 30)
        fail("first refill request timeout");
    end

    send_refill(32'h1111_1111, 32'h2222_2222,
                32'h3333_3333, 32'h4444_4444, 1'b1);

    cycles = 0;
    while (refill_request_count < 2) begin
      @(posedge clk);
      #1;
      cycles = cycles + 1;
      if (cycles > 30)
        fail("poisoned refill was not retried");
    end
    if (output_count != 0)
      fail("poisoned refill exposed stale instruction data");
    if (dut.cache_valid[0][0] || dut.cache_valid[1][0])
      fail("poisoned refill installed a cache line");

    send_refill(32'hdead_beef, 32'h1234_5678,
                32'h89ab_cdef, 32'h0bad_f00d, 1'b0);

    cycles = 0;
    while (output_count < 1) begin
      @(posedge clk);
      #1;
      cycles = cycles + 1;
      if (cycles > 30)
        fail("replacement refill did not produce an instruction");
    end
    if (first_output_inst !== 32'hdead_beef)
      fail("replacement refill returned stale data");
    if (!(dut.cache_valid[0][0] || dut.cache_valid[1][0]))
      fail("replacement refill was not installed");
    if (refill_request_count != 2)
      fail("unexpected extra refill request");

    // A CACOP accepted during MISS_REFILL must not finish until every refill
    // beat has drained, and its later APPLY must invalidate the installed line.
    resetn = 1'b0;
    repeat (4) @(posedge clk);
    resetn = 1'b1;
    repeat (3) @(posedge clk);
    refill_request_count = 0;
    output_count         = 0;
    refill_drained       = 1'b0;
    pc_inst_req          = 1'b1;

    cycles = 0;
    while (refill_request_count < 1) begin
      @(posedge clk);
      #1;
      cycles = cycles + 1;
      if (cycles > 30)
        fail("CACOP/refill overlap request timeout");
    end

    fork
      begin
        pulse_cacop(5'h10, 32'h1c00_0000);
        if (!refill_drained)
          fail("CACOP completed before the outstanding refill drained");
      end
      begin
        send_refill(32'haaaa_0000, 32'haaaa_0001,
                    32'haaaa_0002, 32'haaaa_0003, 1'b0);
        refill_drained = 1'b1;
      end
    join

    if (dut.cache_valid[0][0] || dut.cache_valid[1][0])
      fail("CACOP arriving during refill left the target line valid");

    $display("PASS icache_coherence_tb");
    $finish;
  end
endmodule
