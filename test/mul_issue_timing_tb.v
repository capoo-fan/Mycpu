`timescale 1ns / 1ps
`include "mycpu.vh"

module mul_issue_timing_tb;
  reg clk;
  reg resetn;
  reg flush;
  reg ms_allowin;
  reg front_valid_0;
  reg front_valid_1;
  reg [31:0] inst_0;
  reg [31:0] inst_1;

  wire [`DS_DEC_BUS_WD-1:0] dec_0;
  wire [`DS_DEC_BUS_WD-1:0] dec_1;
  wire [`FS_TO_DS_BUS_WD-1:0] fs_0 = {32'h1c00_0000, inst_0, 1'b0, 32'b0};
  wire [`FS_TO_DS_BUS_WD-1:0] fs_1 = {32'h1c00_0004, inst_1, 1'b0, 32'b0};
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_0 = {dec_0, fs_0};
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_1 = {dec_1, fs_1};
  wire [4:0] front_raddr1_0_hot =
       front_bus_0[`FS_TO_DS_BUS_WD + 56 +: 5];
  wire [4:0] front_raddr2_0_hot =
       front_bus_0[`FS_TO_DS_BUS_WD + 51 +: 5];
  wire [4:0] front_raddr1_1_hot =
       front_bus_1[`FS_TO_DS_BUS_WD + 56 +: 5];
  wire [4:0] front_raddr2_1_hot =
       front_bus_1[`FS_TO_DS_BUS_WD + 51 +: 5];

  wire pop_0;
  wire pop_1;
  wire ds_to_es_valid_0;
  wire ds_to_es_valid_1;
  wire [`DS_TO_ES_BUS_WD-1:0] ds_to_es_bus_0;
  wire [`DS_TO_ES_BUS_1_WD-1:0] ds_to_es_bus_1;
  wire es_allowin;
  wire es_to_ms_valid_0;
  wire es_to_ms_valid_1;
  wire [`ES_TO_MS_BUS_WD-1:0] es_to_ms_bus_0;
  wire [`ES_TO_MS_BUS_1_WD-1:0] es_to_ms_bus_1;
  wire [`ES_FWD_BUS_WD-1:0] es_fwd_bus_0;
  wire [`ES_FWD_BUS_1_WD-1:0] es_fwd_bus_1;

  function [31:0] make_mul;
    input [4:0] rd;
    input [4:0] rj;
    input [4:0] rk;
    begin
      make_mul = 32'h001c_0000 | {17'b0, rk, rj, rd};
    end
  endfunction

  function [31:0] make_mulh;
    input [4:0] rd;
    input [4:0] rj;
    input [4:0] rk;
    begin
      make_mulh = 32'h001c_8000 | {17'b0, rk, rj, rd};
    end
  endfunction

  function [31:0] make_mulhu;
    input [4:0] rd;
    input [4:0] rj;
    input [4:0] rk;
    begin
      make_mulhu = 32'h001d_0000 | {17'b0, rk, rj, rd};
    end
  endfunction

  function [31:0] make_addi;
    input [4:0] rd;
    input [4:0] rj;
    begin
      make_addi = 32'h0280_0400 | {22'b0, rj, rd};
    end
  endfunction

  inst_decoder dec0(.inst(inst_0), .dec_bus(dec_0));
  inst_decoder dec1(.inst(inst_1), .dec_bus(dec_1));

  ISSUE_stage u_issue(
    .clk(clk), .resetn(resetn),
    .front_valid_0(front_valid_0), .front_bus_0(front_bus_0),
    .front_raddr1_0_hot(front_raddr1_0_hot),
    .front_raddr2_0_hot(front_raddr2_0_hot),
    .front_valid_1(front_valid_1), .front_bus_1(front_bus_1),
    .front_raddr1_1_hot(front_raddr1_1_hot),
    .front_raddr2_1_hot(front_raddr2_1_hot),
    .pop_0(pop_0), .pop_1(pop_1), .special_fire(),
    .br_taken(flush), .special_block(1'b0), .es_allowin(es_allowin),
    .es_fwd_bus_0(es_fwd_bus_0), .es_fwd_bus_1(es_fwd_bus_1),
    .ms_fwd_bus_0({`MS_FWD_BUS_WD{1'b0}}),
    .ms_fwd_bus_1({`MS_FWD_BUS_1_WD{1'b0}}),
    .ws_to_rf_bus({`WS_TO_RF_BUS_WD{1'b0}}),
    .load_wakeup_valid(1'b0),
    .ds_to_es_valid_0(ds_to_es_valid_0),
    .ds_to_es_valid_1(ds_to_es_valid_1),
    .ds_to_es_bus_0(ds_to_es_bus_0),
    .ds_to_es_bus_1(ds_to_es_bus_1)
  );

  EXE_stage u_exe(
    .clk(clk), .resetn(resetn),
    .ds_to_es_valid_0(ds_to_es_valid_0),
    .ds_to_es_valid_1(ds_to_es_valid_1),
    .ds_to_es_bus_0(ds_to_es_bus_0),
    .ds_to_es_bus_1(ds_to_es_bus_1),
    .flush(flush), .ms_allowin(ms_allowin),
    .load_wakeup_valid(1'b0), .load_wakeup_data(32'b0),
    .es_allowin(es_allowin),
    .es_to_ms_valid_0(es_to_ms_valid_0),
    .es_to_ms_valid_1(es_to_ms_valid_1),
    .es_to_ms_bus_0(es_to_ms_bus_0), .es_to_ms_bus_1(es_to_ms_bus_1),
    .es_fwd_bus_0(es_fwd_bus_0), .es_fwd_bus_1(es_fwd_bus_1),
    .csr_busy(), .cacop_busy(), .csr_raddr(), .csr_rdata(32'b0)
  );

  always #5 clk = ~clk;

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "mul_issue_timing_tb failed");
    end
  endtask

  task reset_dut;
    begin
      @(negedge clk);
      resetn = 1'b0;
      flush = 1'b0;
      ms_allowin = 1'b1;
      front_valid_0 = 1'b0;
      front_valid_1 = 1'b0;
      repeat (3) @(posedge clk);
      @(negedge clk);
      resetn = 1'b1;
      repeat (2) @(posedge clk);
      @(negedge clk);
    end
  endtask

  task expect_pop;
    input expected_0;
    input expected_1;
    input [511:0] message;
    begin
      #1;
      if (pop_0 !== expected_0 || pop_1 !== expected_1)
        fail(message);
    end
  endtask

  task expect_blocked_cycles;
    input integer count;
    integer i;
    begin
      for (i = 0; i < count; i = i + 1)
      begin
        @(posedge clk);
        #1;
        if (pop_0 !== 1'b0 || pop_1 !== 1'b0)
          fail("dependent instruction issued before multiply completion");
        @(negedge clk);
      end
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    flush = 1'b0;
    ms_allowin = 1'b1;
    front_valid_0 = 1'b0;
    front_valid_1 = 1'b0;
    inst_0 = 32'b0;
    inst_1 = 32'b0;

    // Only mul.w remains in the supported ISA. A former mulh.w encoding must
    // decode as unknown and must not request either multiply or writeback.
    reset_dut();
    inst_0 = make_mulh(5'd2, 5'd7, 5'd8);
    #1;
    if (dec0.inst_known !== 1'b0 || dec0.is_mul !== 1'b0 ||
        dec0.gr_we !== 1'b0)
      fail("mulh.w remained in the supported multiply decode");
    inst_0 = make_mulhu(5'd2, 5'd7, 5'd8);
    #1;
    if (dec0.inst_known !== 1'b0 || dec0.is_mul !== 1'b0 ||
        dec0.gr_we !== 1'b0)
      fail("mulh.wu remained in the supported multiply decode");

    // A same-packet RAW dependency issues lane0 only.  Lane1 payload may be
    // sampled, but its valid and every architectural side-effect control must
    // remain clear.
    reset_dut();
    inst_0 = make_addi(5'd5, 5'd0);
    inst_1 = make_addi(5'd6, 5'd5);
    front_valid_0 = 1'b1;
    front_valid_1 = 1'b1;
    expect_pop(1'b1, 1'b0, "same-packet RAW did not reduce issue to lane0");
    @(posedge clk);
    #1;
    if (u_exe.es_valid_1 !== 1'b0 || es_to_ms_valid_1 !== 1'b0 ||
        u_exe.es_gr_we_1 !== 1'b0)
      fail("invalid lane1 retained an architectural side effect");

    // Backpressure must hold both valid and payload even though the ISSUE
    // inputs continue to change while EX cannot accept a new packet.
    reset_dut();
    inst_0 = make_addi(5'd10, 5'd0);
    inst_1 = make_addi(5'd11, 5'd0);
    front_valid_0 = 1'b1;
    front_valid_1 = 1'b1;
    expect_pop(1'b1, 1'b1, "ordinary pair did not issue before backpressure");
    @(posedge clk);
    #1;
    if (u_exe.es_valid_1 !== 1'b1 || u_exe.es_dest_1 !== 5'd11)
      fail("lane1 payload was not captured before backpressure");
    @(negedge clk);
    inst_0 = make_addi(5'd12, 5'd0);
    inst_1 = make_addi(5'd13, 5'd0);
    ms_allowin = 1'b0;
    expect_pop(1'b0, 1'b0, "MEM backpressure did not stop ISSUE");
    @(posedge clk);
    #1;
    if (u_exe.es_valid_1 !== 1'b1 || u_exe.es_dest_1 !== 5'd11)
      fail("EX payload changed while es_allowin was low");

    // Lane0 multiply followed immediately by a RAW consumer. The consumer
    // must issue when the three-cycle multiplier result becomes ready. Since
    // the IP samples ISSUE operands on the EX-entry edge, EX waits two more
    // edges rather than adding an input-register cycle.
    reset_dut();
    u_issue.u_regfile.rf[7] = 32'hffff_fffe;
    u_issue.u_regfile.rf[8] = 32'h0000_0003;
    inst_0 = make_mul(5'd2, 5'd7, 5'd8);
    front_valid_0 = 1'b1;
    expect_pop(1'b1, 1'b0, "lane0 multiply did not issue");
    @(posedge clk);
    @(negedge clk);
    inst_0 = make_addi(5'd4, 5'd2);
    expect_pop(1'b0, 1'b0, "lane0 RAW consumer issued immediately");
    expect_blocked_cycles(1);
    @(posedge clk);
    #1;
    if (u_exe.es_mul_result_0 !== 32'hffff_fffa)
      fail("mul.w result did not use ISSUE operands on the launch edge");
    if (!es_fwd_bus_0[38] || !pop_0 || pop_1)
      fail("lane0 RAW consumer did not issue on multiply completion");

    // A multiply in slot1 cannot pair with an ALU and remains queued while
    // the independent lane0 ALU instruction issues.
    reset_dut();
    inst_0 = make_addi(5'd10, 5'd0);
    inst_1 = make_mul(5'd5, 5'd0, 5'd0);
    front_valid_0 = 1'b1;
    front_valid_1 = 1'b1;
    expect_pop(1'b1, 1'b0, "lane1 multiply was not held for lane0");
    @(posedge clk);
    #1;
    if (u_exe.es_valid_1 || es_to_ms_valid_1)
      fail("unpaired lane1 multiply entered EX");

    // A lane0 multiply may pair with an independent lane1 ALU. The ordinary
    // ALU result remains in the packet until the multiply finishes two edges
    // later, and both results then become forwardable together.
    reset_dut();
    u_issue.u_regfile.rf[7] = 32'hffff_fffe;
    u_issue.u_regfile.rf[8] = 32'h0000_0003;
    inst_0 = make_mul(5'd2, 5'd7, 5'd8);
    inst_1 = make_addi(5'd3, 5'd0);
    front_valid_0 = 1'b1;
    front_valid_1 = 1'b1;
    expect_pop(1'b1, 1'b1, "MUL+ALU pair did not issue together");
    @(posedge clk);
    @(negedge clk);
    inst_0 = make_addi(5'd4, 5'd2);
    inst_1 = make_addi(5'd5, 5'd3);
    ms_allowin = 1'b0;
    expect_blocked_cycles(1);
    @(posedge clk);
    #1;
    if (u_exe.es_mul_result_0 !== 32'hffff_fffa ||
        u_exe.es_exec_result_1 !== 32'h0000_0001)
      fail("MUL+ALU packet results were not aligned");
    if (u_exe.mul_pending_0)
      fail("MUL+ALU packet did not complete after the existing two-edge wait");
    if (!es_fwd_bus_0[38] || !es_fwd_bus_1[38] || pop_0 || pop_1)
      fail("MUL+ALU completion under MEM backpressure is incorrect");
    @(negedge clk);
    ms_allowin = 1'b1;
    expect_pop(1'b1, 1'b1,
               "MEM release did not enable MUL+ALU consumers");

    // Two independent multiplies start together, share the existing two-edge
    // packet wait, and become forwardable together. MEM backpressure after
    // completion must hold both results without changing their alignment.
    reset_dut();
    u_issue.u_regfile.rf[7] = 32'hffff_fffe;
    u_issue.u_regfile.rf[8] = 32'h0000_0003;
    u_issue.u_regfile.rf[9] = 32'h0000_0007;
    u_issue.u_regfile.rf[10] = 32'hffff_fffc;
    inst_0 = make_mul(5'd2, 5'd7, 5'd8);
    inst_1 = make_mul(5'd3, 5'd9, 5'd10);
    front_valid_0 = 1'b1;
    front_valid_1 = 1'b1;
    expect_pop(1'b1, 1'b1, "MUL+MUL pair did not issue together");
    if (!u_exe.mul_launch_0 || !u_exe.mul_launch_1)
      fail("paired multipliers did not start on the same issue edge");
    @(posedge clk);
    @(negedge clk);
    inst_0 = make_addi(5'd4, 5'd2);
    inst_1 = make_addi(5'd5, 5'd3);
    ms_allowin = 1'b0;
    expect_blocked_cycles(1);
    @(posedge clk);
    #1;
    if (u_exe.es_mul_result_0 !== 32'hffff_fffa ||
        u_exe.mul_product_1 !== 32'hffff_ffe4)
      fail("paired multiply results were not aligned");
    if (u_exe.mul_pending_0)
      fail("paired multiplies did not complete together");
    if (!es_fwd_bus_0[38] || !es_fwd_bus_1[38] || pop_0 || pop_1)
      fail("paired multiply completion under MEM backpressure is incorrect");
    @(negedge clk);
    ms_allowin = 1'b1;
    expect_pop(1'b1, 1'b1,
               "MEM release did not enable paired-multiply consumers");

    // Flush has priority over a pending multiply and removes its hazard state.
    reset_dut();
    inst_0 = make_mul(5'd2, 5'd0, 5'd0);
    front_valid_0 = 1'b1;
    expect_pop(1'b1, 1'b0, "multiply before flush did not issue");
    @(posedge clk);
    @(negedge clk);
    inst_0 = make_addi(5'd4, 5'd2);
    flush = 1'b1;
    expect_pop(1'b0, 1'b0, "flush did not block ISSUE");
    @(posedge clk);
    #1;
    if (u_exe.mul_pending_0 !== 1'b0 || es_fwd_bus_0[40] !== 1'b0)
      fail("flush did not clear multiply pending state");
    @(negedge clk);
    flush = 1'b0;
    expect_pop(1'b1, 1'b0, "instruction remained blocked after multiply flush");

    $display("PASS mul_issue_timing_tb");
    $finish;
  end
endmodule

// Three-cycle behavioral model matching the synthesis multiplier latency.
module mult_gen_0(
    input  wire        CLK,
    input  wire [31:0] A,
    input  wire [31:0] B,
    output wire [63:0] P
  );
  reg [63:0] pipe_0;
  reg [63:0] pipe_1;
  reg [63:0] pipe_2;

  always @(posedge CLK)
  begin
    pipe_0 <= $signed(A) * $signed(B);
    pipe_1 <= pipe_0;
    pipe_2 <= pipe_1;
  end

  assign P = pipe_2;
endmodule
