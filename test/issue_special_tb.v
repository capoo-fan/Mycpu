`timescale 1ns / 1ps
`include "mycpu.vh"

module issue_special_tb;
  reg         clk;
  reg         resetn;
  reg         front_valid_0;
  reg         front_valid_1;
  reg  [31:0] inst_0;
  reg  [31:0] inst_1;
  reg         special_inflight;
  wire [`DS_DEC_BUS_WD-1:0] dec_0;
  wire [`DS_DEC_BUS_WD-1:0] dec_1;
  wire [`FS_TO_DS_BUS_WD-1:0] fs_0 = {32'h1c00_0000, inst_0, 1'b0, 32'b0};
  wire [`FS_TO_DS_BUS_WD-1:0] fs_1 = {32'h1c00_0004, inst_1, 1'b0, 32'b0};
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_0 = {dec_0, fs_0};
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_1 = {dec_1, fs_1};
  wire pop_0;
  wire pop_1;
  wire issue_0;
  wire issue_1;

  localparam [31:0] INST_ADDI_R2 = 32'h0280_0402;
  localparam [31:0] INST_ADDI_R3 = 32'h0280_0803;
  localparam [31:0] INST_CSRWR = {8'h04, 14'h0180, 5'd1, 5'd7};
  localparam [31:0] INST_CACOP = {6'h01, 4'h8, 12'h000, 5'd0, 5'h10};

  inst_decoder dec0(.inst(inst_0), .dec_bus(dec_0));
  inst_decoder dec1(.inst(inst_1), .dec_bus(dec_1));

  ISSUE_stage dut(
    .clk(clk), .resetn(resetn),
    .front_valid_0(front_valid_0), .front_bus_0(front_bus_0),
    .front_valid_1(front_valid_1), .front_bus_1(front_bus_1),
    .pop_0(pop_0), .pop_1(pop_1), .br_taken(1'b0),
    .special_inflight(special_inflight), .es_allowin(1'b1),
    .es_fwd_bus_0({`ES_FWD_BUS_WD{1'b0}}),
    .es_fwd_bus_1({`ES_FWD_BUS_WD{1'b0}}),
    .ms_fwd_bus_0({`MS_FWD_BUS_WD{1'b0}}),
    .ms_fwd_bus_1({`MS_FWD_BUS_WD{1'b0}}),
    .es_wait_valid_0(1'b0), .es_wait_dest_0(5'b0),
    .es_wait_valid_1(1'b0), .es_wait_dest_1(5'b0),
    .ms_wait_valid_0(1'b0), .ms_wait_dest_0(5'b0),
    .ms_wait_valid_1(1'b0), .ms_wait_dest_1(5'b0),
    .ws_to_rf_bus({`WS_TO_RF_BUS_WD{1'b0}}),
    .ds_to_es_valid_0(issue_0), .ds_to_es_valid_1(issue_1),
    .ds_to_es_bus_0(), .ds_to_es_bus_1()
  );

  always #5 clk = ~clk;

  task check_issue;
    input expected_0;
    input expected_1;
    input [255:0] name;
    begin
      #1;
      if (issue_0 !== expected_0 || issue_1 !== expected_1 ||
          pop_0 !== expected_0 || pop_1 !== expected_1) begin
        $display("FAIL %0s issue=%b%b pop=%b%b", name,
                 issue_0, issue_1, pop_0, pop_1);
        $fatal(1, "issue_special_tb failed");
      end
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    front_valid_0 = 1'b1;
    front_valid_1 = 1'b1;
    special_inflight = 1'b0;
    inst_0 = INST_ADDI_R2;
    inst_1 = INST_ADDI_R3;
    #1;
    resetn = 1'b1;

    check_issue(1'b1, 1'b1, "ordinary dual issue");

    inst_1 = INST_CSRWR;
    check_issue(1'b1, 1'b0, "front1 CSR remains in IBUF");

    inst_0 = INST_CSRWR;
    inst_1 = INST_ADDI_R3;
    check_issue(1'b1, 1'b0, "lane0 CSR issues alone");

    inst_0 = INST_CACOP;
    check_issue(1'b1, 1'b0, "lane0 CACOP issues alone");

    inst_0 = INST_ADDI_R2;
    special_inflight = 1'b1;
    check_issue(1'b0, 1'b0, "special busy blocks younger issue");

    $display("PASS issue_special_tb");
    $finish;
  end
endmodule
