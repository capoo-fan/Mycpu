`timescale 1ns / 1ps
`include "mycpu.vh"

module asymmetric_issue_tb;
  reg clk;
  reg resetn;
  reg push_valid_0;
  reg push_valid_1;
  reg [`FS_TO_DS_BUS_WD-1:0] push_bus_0;
  reg [`FS_TO_DS_BUS_WD-1:0] push_bus_1;

  wire push_ready;
  wire front_valid_0;
  wire front_valid_1;
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_0;
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_1;
  wire [4:0] front_raddr1_0_hot;
  wire [4:0] front_raddr2_0_hot;
  wire [4:0] front_raddr1_1_hot;
  wire [4:0] front_raddr2_1_hot;
  wire pop_0;
  wire pop_1;
  wire ds_to_es_valid_0;
  wire ds_to_es_valid_1;

  wire [31:0] front_pc_0 =
       front_bus_0[`FS_TO_DS_BUS_WD-1 -: 32];
  wire [31:0] front_pc_1 =
       front_bus_1[`FS_TO_DS_BUS_WD-1 -: 32];

  inst_buffer u_ibuf(
    .clk(clk), .resetn(resetn), .flush(1'b0),
    .push_valid_0(push_valid_0), .push_bus_0(push_bus_0),
    .push_valid_1(push_valid_1), .push_bus_1(push_bus_1),
    .push_ready(push_ready), .full(),
    .pop_0(pop_0), .pop_1(pop_1),
    .front_valid_0(front_valid_0), .front_bus_0(front_bus_0),
    .front_raddr1_0_hot(front_raddr1_0_hot),
    .front_raddr2_0_hot(front_raddr2_0_hot),
    .front_valid_1(front_valid_1), .front_bus_1(front_bus_1),
    .front_raddr1_1_hot(front_raddr1_1_hot),
    .front_raddr2_1_hot(front_raddr2_1_hot)
  );

  ISSUE_stage u_issue(
    .clk(clk), .resetn(resetn),
    .front_valid_0(front_valid_0), .front_bus_0(front_bus_0),
    .front_raddr1_0_hot(front_raddr1_0_hot),
    .front_raddr2_0_hot(front_raddr2_0_hot),
    .front_valid_1(front_valid_1), .front_bus_1(front_bus_1),
    .front_raddr1_1_hot(front_raddr1_1_hot),
    .front_raddr2_1_hot(front_raddr2_1_hot),
    .pop_0(pop_0), .pop_1(pop_1), .special_fire(),
    .br_taken(1'b0), .special_block(1'b0), .es_allowin(1'b1),
    .es_fwd_bus_0({`ES_FWD_BUS_WD{1'b0}}),
    .es_fwd_bus_1({`ES_FWD_BUS_1_WD{1'b0}}),
    .ms_fwd_bus_0({`MS_FWD_BUS_WD{1'b0}}),
    .ms_fwd_bus_1({`MS_FWD_BUS_1_WD{1'b0}}),
    .ws_to_rf_bus({`WS_TO_RF_BUS_WD{1'b0}}),
    .ds_to_es_valid_0(ds_to_es_valid_0),
    .ds_to_es_valid_1(ds_to_es_valid_1),
    .ds_to_es_bus_0(), .ds_to_es_bus_1()
  );

  always #5 clk = ~clk;

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "asymmetric_issue_tb failed");
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    push_valid_0 = 1'b0;
    push_valid_1 = 1'b0;
    push_bus_0 = {`FS_TO_DS_BUS_WD{1'b0}};
    push_bus_1 = {`FS_TO_DS_BUS_WD{1'b0}};

    repeat (3) @(posedge clk);
    @(negedge clk);
    resetn = 1'b1;
    if (!push_ready)
      fail("InstBuffer not ready after reset");

    // slot0 is an ADDI.W; slot1 is an LD.W, which is forbidden on lane1.
    push_bus_0 = {32'h1c00_0000, 32'h0280_0402, 1'b0, 32'b0};
    push_bus_1 = {32'h1c00_0004, 32'h2880_0005, 1'b0, 32'b0};
    push_valid_0 = 1'b1;
    push_valid_1 = 1'b1;
    @(posedge clk);
    @(negedge clk);
    push_valid_0 = 1'b0;
    push_valid_1 = 1'b0;
    @(posedge clk);
    #1;

    if (!front_valid_0 || !front_valid_1 ||
        front_pc_0 !== 32'h1c00_0000 ||
        front_pc_1 !== 32'h1c00_0004)
      fail("two-entry issue window was not filled in program order");
    if (!pop_0 || pop_1 || !ds_to_es_valid_0 || ds_to_es_valid_1)
      fail("forbidden slot1 load did not reduce issue to lane0");

    @(posedge clk);
    #1;
    if (!front_valid_0 || front_valid_1 ||
        front_pc_0 !== 32'h1c00_0004)
      fail("forbidden slot1 instruction was not promoted to lane0");
    if (!pop_0 || pop_1 || !ds_to_es_valid_0 || ds_to_es_valid_1)
      fail("promoted load did not issue through full-capability lane0");

    $display("PASS asymmetric_issue_tb");
    $finish;
  end
endmodule
