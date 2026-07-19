`timescale 1ns / 1ps
`include "mycpu.vh"

module issue_special_tb;
  reg         clk;
  reg         resetn;
  reg         front_valid_0;
  reg         front_valid_1;
  reg  [31:0] inst_0;
  reg  [31:0] inst_1;
  reg         special_block;
  reg  [`ES_FWD_BUS_WD-1:0] es_fwd_bus_0;
  reg  [`ES_FWD_BUS_WD-1:0] es_fwd_bus_1;
  reg  [`MS_FWD_BUS_WD-1:0] ms_fwd_bus_0;
  reg  [`MS_FWD_BUS_WD-1:0] ms_fwd_bus_1;
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
  wire special_fire;

  localparam [31:0] INST_ADDI_R2 = 32'h0280_0402;
  localparam [31:0] INST_ADDI_R3 = 32'h0280_0803;
  localparam [31:0] INST_ADDI_R3_FROM_R2 = 32'h0280_0443;
  localparam [31:0] INST_ADDI_R5_FROM_R2 = 32'h0280_0445;
  localparam [31:0] INST_CSRWR = {8'h04, 14'h0180, 5'd1, 5'd7};
  localparam [31:0] INST_CACOP = {6'h01, 4'h8, 12'h000, 5'd0, 5'h10};
  localparam [31:0] INST_CPUCFG = {17'b0, 5'h1b, 5'd2, 5'd3};

  function [31:0] make_addi;
    input [4:0] rd;
    input [4:0] rj;
    begin
      make_addi = 32'h0280_0400 | {22'b0, rj, rd};
    end
  endfunction

  function [31:0] make_add;
    input [4:0] rd;
    input [4:0] rj;
    input [4:0] rk;
    begin
      make_add = 32'h0010_0000 | {17'b0, rk, rj, rd};
    end
  endfunction

  inst_decoder dec0(.inst(inst_0), .dec_bus(dec_0));
  inst_decoder dec1(.inst(inst_1), .dec_bus(dec_1));

  ISSUE_stage dut(
    .clk(clk), .resetn(resetn),
    .front_valid_0(front_valid_0), .front_bus_0(front_bus_0),
    .front_valid_1(front_valid_1), .front_bus_1(front_bus_1),
    .pop_0(pop_0), .pop_1(pop_1), .br_taken(1'b0),
    .special_fire(special_fire), .special_block(special_block),
    .es_allowin(1'b1),
    .es_fwd_bus_0(es_fwd_bus_0), .es_fwd_bus_1(es_fwd_bus_1),
    .ms_fwd_bus_0(ms_fwd_bus_0), .ms_fwd_bus_1(ms_fwd_bus_1),
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
      if (pop_1 && !pop_0) begin
        $display("FAIL %0s pop1 asserted without pop0", name);
        $fatal(1, "issue_special_tb failed");
      end
      if (issue_0 !== expected_0 || issue_1 !== expected_1 ||
          pop_0 !== expected_0 || pop_1 !== expected_1) begin
        $display("FAIL %0s issue=%b%b pop=%b%b", name,
                 issue_0, issue_1, pop_0, pop_1);
        $fatal(1, "issue_special_tb failed");
      end
    end
  endtask

  task clear_producers;
    begin
      es_fwd_bus_0 = {`ES_FWD_BUS_WD{1'b0}};
      es_fwd_bus_1 = {`ES_FWD_BUS_WD{1'b0}};
      ms_fwd_bus_0 = {`MS_FWD_BUS_WD{1'b0}};
      ms_fwd_bus_1 = {`MS_FWD_BUS_WD{1'b0}};
    end
  endtask

  task set_producer;
    input integer producer_slot;
    input         producer_ready;
    input [4:0]   producer_dest;
    begin
      clear_producers();
      case (producer_slot)
        0: es_fwd_bus_0 = {1'b1, 1'b1, producer_ready, 1'b0,
                            producer_dest, 32'h1000_0000};
        1: es_fwd_bus_1 = {1'b1, 1'b1, producer_ready, 1'b0,
                            producer_dest, 32'h2000_0000};
        2: ms_fwd_bus_0 = {1'b1, 1'b1, producer_ready, 1'b1,
                            producer_dest, 32'h3000_0000};
        3: ms_fwd_bus_1 = {1'b1, 1'b1, producer_ready, 1'b1,
                            producer_dest, 32'h4000_0000};
        default: $fatal(1, "invalid producer slot");
      endcase
    end
  endtask

  task check_raw_matrix;
    integer producer_slot;
    begin
      for (producer_slot = 0; producer_slot < 4;
           producer_slot = producer_slot + 1) begin
        // lane0 rj
        inst_0 = make_addi(5'd10, 5'd2);
        inst_1 = make_addi(5'd11, 5'd0);
        set_producer(producer_slot, 1'b0, 5'd2);
        check_issue(1'b0, 1'b0, "lane0 rj unready RAW");
        set_producer(producer_slot, 1'b1, 5'd2);
        check_issue(1'b1, 1'b1, "lane0 rj ready RAW");

        // lane0 rkd
        inst_0 = make_add(5'd10, 5'd0, 5'd2);
        set_producer(producer_slot, 1'b0, 5'd2);
        check_issue(1'b0, 1'b0, "lane0 rkd unready RAW");
        set_producer(producer_slot, 1'b1, 5'd2);
        check_issue(1'b1, 1'b1, "lane0 rkd ready RAW");

        // lane1 rj: lane0 remains independently issuable while lane1 waits.
        inst_0 = make_addi(5'd10, 5'd0);
        inst_1 = make_addi(5'd11, 5'd2);
        set_producer(producer_slot, 1'b0, 5'd2);
        check_issue(1'b1, 1'b0, "lane1 rj unready RAW");
        set_producer(producer_slot, 1'b1, 5'd2);
        check_issue(1'b1, 1'b1, "lane1 rj ready RAW");

        // lane1 rkd
        inst_1 = make_add(5'd11, 5'd0, 5'd2);
        set_producer(producer_slot, 1'b0, 5'd2);
        check_issue(1'b1, 1'b0, "lane1 rkd unready RAW");
        set_producer(producer_slot, 1'b1, 5'd2);
        check_issue(1'b1, 1'b1, "lane1 rkd ready RAW");
      end
      clear_producers();
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    front_valid_0 = 1'b1;
    front_valid_1 = 1'b1;
    special_block = 1'b0;
    es_fwd_bus_0 = {`ES_FWD_BUS_WD{1'b0}};
    es_fwd_bus_1 = {`ES_FWD_BUS_WD{1'b0}};
    ms_fwd_bus_0 = {`MS_FWD_BUS_WD{1'b0}};
    ms_fwd_bus_1 = {`MS_FWD_BUS_WD{1'b0}};
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
    if (special_fire !== 1'b1)
      $fatal(1, "CACOP did not set special_fire");

    inst_0 = INST_ADDI_R2;
    inst_1 = INST_CPUCFG;
    check_issue(1'b1, 1'b0, "front1 CPUCFG remains in IBUF");

    inst_0 = INST_CPUCFG;
    inst_1 = INST_ADDI_R3;
    check_issue(1'b1, 1'b0, "lane0 CPUCFG issues alone");
    if (special_fire !== 1'b0)
      $fatal(1, "CPUCFG incorrectly occupied special scoreboard");

    inst_0 = INST_ADDI_R2;
    special_block = 1'b1;
    check_issue(1'b0, 1'b0, "special busy blocks younger issue");

    special_block = 1'b0;
    inst_0 = INST_ADDI_R3_FROM_R2;
    inst_1 = INST_ADDI_R3;
    es_fwd_bus_1 = {1'b1, 1'b1, 1'b0, 1'b0, 5'd2, 32'h1234_5678};
    check_issue(1'b0, 1'b0, "unready ES producer blocks lane0 and pair");
    es_fwd_bus_1 = {1'b1, 1'b1, 1'b1, 1'b0, 5'd2, 32'h1234_5678};
    check_issue(1'b1, 1'b1, "ES producer forwards without extra stall");

    inst_0 = INST_ADDI_R3;
    inst_1 = INST_ADDI_R5_FROM_R2;
    es_fwd_bus_1 = {`ES_FWD_BUS_WD{1'b0}};
    ms_fwd_bus_0 = {1'b1, 1'b1, 1'b0, 1'b1, 5'd2, 32'h89ab_cdef};
    check_issue(1'b1, 1'b0, "unready MEM producer blocks lane1 only");
    ms_fwd_bus_0 = {1'b1, 1'b1, 1'b1, 1'b1, 5'd2, 32'h89ab_cdef};
    check_issue(1'b1, 1'b1, "MEM producer forwards without extra stall");

    check_raw_matrix();

    $display("PASS issue_special_tb");
    $finish;
  end
endmodule
