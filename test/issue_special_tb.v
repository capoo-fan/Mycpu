`timescale 1ns / 1ps
`include "mycpu.vh"

module issue_special_tb;
  reg         clk;
  reg         resetn;
  reg         front_valid_0;
  reg         front_valid_1;
  reg         br_taken;
  reg         es_allowin;
  reg  [31:0] inst_0;
  reg  [31:0] inst_1;
  reg         special_block;
  reg  [`ES_FWD_BUS_WD-1:0] es_fwd_bus_0;
  reg  [`ES_FWD_BUS_1_WD-1:0] es_fwd_bus_1;
  reg  [`MS_FWD_BUS_WD-1:0] ms_fwd_bus_0;
  reg  [`MS_FWD_BUS_1_WD-1:0] ms_fwd_bus_1;
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

  function [31:0] make_ld_w;
    input [4:0] rd;
    input [4:0] rj;
    begin
      make_ld_w = 32'h2880_0000 | {22'b0, rj, rd};
    end
  endfunction

  function [31:0] make_st_w;
    input [4:0] rd;
    input [4:0] rj;
    begin
      make_st_w = 32'h2980_0000 | {22'b0, rj, rd};
    end
  endfunction

  function [31:0] make_mul;
    input [4:0] rd;
    input [4:0] rj;
    input [4:0] rk;
    begin
      make_mul = 32'h001c_0000 | {17'b0, rk, rj, rd};
    end
  endfunction

  inst_decoder dec0(.inst(inst_0), .dec_bus(dec_0));
  inst_decoder dec1(.inst(inst_1), .dec_bus(dec_1));

  ISSUE_stage dut(
    .clk(clk), .resetn(resetn),
    .front_valid_0(front_valid_0), .front_bus_0(front_bus_0),
    .front_raddr1_0_hot(front_raddr1_0_hot),
    .front_raddr2_0_hot(front_raddr2_0_hot),
    .front_valid_1(front_valid_1), .front_bus_1(front_bus_1),
    .front_raddr1_1_hot(front_raddr1_1_hot),
    .front_raddr2_1_hot(front_raddr2_1_hot),
    .pop_0(pop_0), .pop_1(pop_1), .br_taken(br_taken),
    .special_fire(special_fire), .special_block(special_block),
    .es_allowin(es_allowin),
    .es_fwd_bus_0(es_fwd_bus_0), .es_fwd_bus_1(es_fwd_bus_1),
    .ms_fwd_bus_0(ms_fwd_bus_0), .ms_fwd_bus_1(ms_fwd_bus_1),
    .ws_to_rf_bus({`WS_TO_RF_BUS_WD{1'b0}}),
    .ds_to_es_valid_0(issue_0), .ds_to_es_valid_1(issue_1),
    .ds_to_es_bus_0(), .ds_to_es_bus_1()
  );

  task tick;
    begin
      #1 clk = 1'b1;
      #1 clk = 1'b0;
    end
  endtask

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

  task check_lane1_alu;
    input [31:0] instruction;
    input [255:0] name;
    begin
      inst_0 = INST_ADDI_R2;
      inst_1 = instruction;
      check_issue(1'b1, 1'b1, name);
    end
  endtask

  task clear_producers;
    begin
      es_fwd_bus_0 = {`ES_FWD_BUS_WD{1'b0}};
      es_fwd_bus_1 = {`ES_FWD_BUS_1_WD{1'b0}};
      ms_fwd_bus_0 = {`MS_FWD_BUS_WD{1'b0}};
      ms_fwd_bus_1 = {`MS_FWD_BUS_1_WD{1'b0}};
      dut.ex_wait_valid_0 = 1'b0;
      dut.ex_wait_dest_0 = 5'b0;
    end
  endtask

  task set_producer;
    input integer producer_slot;
    input         producer_ready;
    input [4:0]   producer_dest;
    begin
      clear_producers();
      case (producer_slot)
        0: begin
          es_fwd_bus_0 = {1'b1, 1'b1, producer_ready, 1'b0,
                          producer_dest, 32'h1000_0000};
          dut.ex_wait_valid_0 = !producer_ready &&
                                (producer_dest != 5'b0);
          dut.ex_wait_dest_0 = producer_dest;
        end
        1: begin
          es_fwd_bus_1 = {1'b1, 1'b1,
                          producer_dest, 32'h2000_0000};
        end
        2: ms_fwd_bus_0 = {1'b1, 1'b1, producer_ready, 1'b1,
                            producer_dest, 32'h3000_0000};
        3: ms_fwd_bus_1 = {1'b1, 1'b1,
                            producer_dest, 32'h4000_0000};
        default: $fatal(1, "invalid producer slot");
      endcase
    end
  endtask

  task check_local_wait;
    input expected_valid_0;
    input [4:0] expected_dest_0;
    input [255:0] name;
    begin
      if ((dut.ex_wait_valid_0 !== expected_valid_0) ||
          (expected_valid_0 &&
           (dut.ex_wait_dest_0 !== expected_dest_0))) begin
        $display("FAIL %0s local_wait=%b/%0d", name,
                 dut.ex_wait_valid_0, dut.ex_wait_dest_0);
        $fatal(1, "issue_special_tb failed");
      end
    end
  endtask

  task check_local_wait_pipeline;
    begin
      // Lane0 load metadata is captured with the same handshake as EX.
      front_valid_0 = 1'b1;
      front_valid_1 = 1'b0;
      inst_0 = make_ld_w(5'd12, 5'd4);
      clear_producers();
      check_issue(1'b1, 1'b0, "lane0 load enters EX wait mirror");
      tick();
      check_local_wait(1'b1, 5'd12,
                       "lane0 load mirror capture");
      es_fwd_bus_0 = {1'b1, 1'b1, 1'b0, 1'b1,
                      5'd12, 32'h1111_1111};
      inst_0 = make_addi(5'd10, 5'd12);
      check_issue(1'b0, 1'b0,
                  "captured lane0 load blocks dependent consumer");

      // EX backpressure freezes the local metadata exactly as it freezes EX.
      es_allowin = 1'b0;
      inst_0 = make_addi(5'd10, 5'd0);
      tick();
      check_local_wait(1'b1, 5'd12,
                       "EX backpressure holds wait mirror");

      // When EX advances, an independently issued ALU operation replaces the
      // old load metadata without adding a bubble.
      es_allowin = 1'b1;
      check_issue(1'b1, 1'b0, "independent issue replaces load mirror");
      tick();
      es_fwd_bus_0 = {`ES_FWD_BUS_WD{1'b0}};
      check_local_wait(1'b0, 5'd0,
                       "ordinary ALU clears wait mirror");

      // Lane1 has no load/store datapath. The younger load remains queued and
      // will be promoted to lane0 by the real InstBuffer.
      front_valid_1 = 1'b1;
      inst_0 = make_addi(5'd10, 5'd0);
      inst_1 = make_ld_w(5'd13, 5'd4);
      check_issue(1'b1, 1'b0, "lane1 load remains in IBuffer");
      tick();
      check_local_wait(1'b0, 5'd0,
                       "forbidden lane1 load creates no wait entry");

      // A pipeline flush has priority over the EX advance/capture path.
      br_taken = 1'b1;
      tick();
      br_taken = 1'b0;
      es_fwd_bus_1 = {`ES_FWD_BUS_1_WD{1'b0}};
      check_local_wait(1'b0, 5'd0,
                       "flush clears wait mirror");

      // CPUCFG is non-forwardable in EX and therefore uses the same mirror.
      front_valid_1 = 1'b0;
      inst_0 = INST_CPUCFG;
      check_issue(1'b1, 1'b0, "CPUCFG enters EX wait mirror");
      tick();
      check_local_wait(1'b1, 5'd3,
                       "CPUCFG mirror capture");
      br_taken = 1'b1;
      tick();
      br_taken = 1'b0;

      // A multiply is controlled by es_allowin and must not occupy the local
      // destination scoreboard.
      inst_0 = make_mul(5'd20, 5'd2, 5'd3);
      check_issue(1'b1, 1'b0, "multiply issues without wait mirror entry");
      tick();
      check_local_wait(1'b0, 5'd0,
                       "multiply excluded from wait mirror");

      // The remaining combinational matrix tests inject producer metadata
      // directly and do not advance the manual test clock.
      clear_producers();
      front_valid_0 = 1'b1;
      front_valid_1 = 1'b1;
      inst_0 = INST_ADDI_R2;
      inst_1 = INST_ADDI_R3;
    end
  endtask

  task check_raw_matrix;
    integer producer_slot;
    begin
      // Only lane0 can produce an unready result. Exercise its EX and MEM
      // positions; lane1 producers are always-forwardable ALU results.
      for (producer_slot = 0; producer_slot < 4;
           producer_slot = producer_slot + 2) begin
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

      for (producer_slot = 1; producer_slot < 4;
           producer_slot = producer_slot + 2) begin
        inst_0 = make_addi(5'd10, 5'd2);
        inst_1 = make_addi(5'd11, 5'd0);
        set_producer(producer_slot, 1'b1, 5'd2);
        check_issue(1'b1, 1'b1, "lane1 producer forwards to lane0");

        inst_0 = make_addi(5'd10, 5'd0);
        inst_1 = make_add(5'd11, 5'd0, 5'd2);
        check_issue(1'b1, 1'b1, "lane1 producer forwards to lane1");
      end
      clear_producers();
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    front_valid_0 = 1'b1;
    front_valid_1 = 1'b1;
    br_taken = 1'b0;
    es_allowin = 1'b1;
    special_block = 1'b0;
    es_fwd_bus_0 = {`ES_FWD_BUS_WD{1'b0}};
    es_fwd_bus_1 = {`ES_FWD_BUS_1_WD{1'b0}};
    ms_fwd_bus_0 = {`MS_FWD_BUS_WD{1'b0}};
    ms_fwd_bus_1 = {`MS_FWD_BUS_1_WD{1'b0}};
    inst_0 = INST_ADDI_R2;
    inst_1 = INST_ADDI_R3;
    tick();
    tick();
    resetn = 1'b1;

    check_local_wait_pipeline();

    check_issue(1'b1, 1'b1, "ordinary dual issue");

    // Cover every regular lane1 ALU family.
    check_lane1_alu(32'h0010_0007, "lane1 ADD.W");
    check_lane1_alu(32'h0011_0007, "lane1 SUB.W");
    check_lane1_alu(32'h0012_0007, "lane1 SLT");
    check_lane1_alu(32'h0012_8007, "lane1 SLTU");
    check_lane1_alu(32'h0014_0007, "lane1 NOR");
    check_lane1_alu(32'h0014_8007, "lane1 AND");
    check_lane1_alu(32'h0015_0007, "lane1 OR");
    check_lane1_alu(32'h0015_8007, "lane1 XOR");
    check_lane1_alu(32'h0017_0007, "lane1 SLL.W");
    check_lane1_alu(32'h0017_8007, "lane1 SRL.W");
    check_lane1_alu(32'h0018_0007, "lane1 SRA.W");
    check_lane1_alu(32'h0040_8007, "lane1 SLLI.W");
    check_lane1_alu(32'h0044_8007, "lane1 SRLI.W");
    check_lane1_alu(32'h0048_8007, "lane1 SRAI.W");
    check_lane1_alu(32'h0280_0007, "lane1 ADDI.W");
    check_lane1_alu(32'h0200_0007, "lane1 SLTI");
    check_lane1_alu(32'h0240_0007, "lane1 SLTUI");
    check_lane1_alu(32'h0340_0007, "lane1 ANDI");
    check_lane1_alu(32'h0380_0007, "lane1 ORI");
    check_lane1_alu(32'h03c0_0007, "lane1 XORI");
    check_lane1_alu(32'h1400_0007, "lane1 LU12I.W");
    check_lane1_alu(32'h1c00_0007, "lane1 PCADDU12I");

    // lane1 supports direct B and all six conditional branch comparisons.
    inst_0 = INST_ADDI_R2;
    inst_1 = 32'h5000_0000;
    check_issue(1'b1, 1'b1, "lane1 B");
    inst_1 = 32'h5800_0000;
    check_issue(1'b1, 1'b1, "lane1 BEQ");
    inst_1 = 32'h5c00_0000;
    check_issue(1'b1, 1'b1, "lane1 BNE");
    inst_1 = 32'h6000_0000;
    check_issue(1'b1, 1'b1, "lane1 BLT");
    inst_1 = 32'h6400_0000;
    check_issue(1'b1, 1'b1, "lane1 BGE");
    inst_1 = 32'h6800_0000;
    check_issue(1'b1, 1'b1, "lane1 BLTU");
    inst_1 = 32'h6c00_0000;
    check_issue(1'b1, 1'b1, "lane1 BGEU");

    inst_1 = 32'h4c00_0000;
    check_issue(1'b1, 1'b0, "lane1 JIRL remains in IBUF");
    inst_1 = 32'h5400_0000;
    check_issue(1'b1, 1'b0, "lane1 BL remains in IBUF");

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
    set_producer(0, 1'b0, 5'd2);
    check_issue(1'b0, 1'b0, "unready ES producer blocks lane0 and pair");
    set_producer(0, 1'b1, 5'd2);
    check_issue(1'b1, 1'b1, "ES producer forwards without extra stall");

    inst_0 = INST_ADDI_R3;
    inst_1 = INST_ADDI_R5_FROM_R2;
    es_fwd_bus_1 = {`ES_FWD_BUS_1_WD{1'b0}};
    ms_fwd_bus_0 = {1'b1, 1'b1, 1'b0, 1'b1, 5'd2, 32'h89ab_cdef};
    check_issue(1'b1, 1'b0,
                "unready MEM load blocks only dependent lane1");
    ms_fwd_bus_0 = {1'b1, 1'b1, 1'b1, 1'b1, 5'd2, 32'h89ab_cdef};
    check_issue(1'b1, 1'b1, "MEM producer forwards without extra stall");

    inst_0 = INST_ADDI_R3;
    inst_1 = make_addi(5'd5, 5'd4);
    ms_fwd_bus_0 = {1'b1, 1'b1, 1'b0, 1'b1,
                    5'd2, 32'h89ab_cdef};
    check_issue(1'b1, 1'b1,
                "unrelated MEM load does not close issue window");

    // The timing cut deliberately applies the ordinary load-use interlock to
    // Store data as well. This keeps Store/load classification out of the
    // InstBuffer consume cone at the cost of one dependency bubble.
    front_valid_0 = 1'b1;
    front_valid_1 = 1'b0;
    inst_0 = make_st_w(5'd12, 5'd5);
    set_producer(0, 1'b0, 5'd12);
    check_issue(1'b0, 1'b0, "lane0 Store data waits for lane0 EX load");

    // Store addresses and ordinary ALU consumers use the same interlock.
    set_producer(0, 1'b0, 5'd5);
    check_issue(1'b0, 1'b0, "lane0 Store address still waits for EX load");
    inst_0 = make_addi(5'd10, 5'd12);
    set_producer(0, 1'b0, 5'd12);
    check_issue(1'b0, 1'b0, "Load to ALU still inserts the normal interlock");

    // A lane1 Store is capability-blocked and still permits lane0 to issue.
    front_valid_1 = 1'b1;
    inst_0 = make_addi(5'd10, 5'd0);
    inst_1 = make_st_w(5'd12, 5'd5);
    set_producer(0, 1'b0, 5'd12);
    check_issue(1'b1, 1'b0, "lane1 Store remains in IBuffer");

    // Store/multiply ordering needs no special bypass rule after the Store is
    // interlocked in ISSUE; normal lane ordering determines what can issue.
    inst_0 = make_st_w(5'd12, 5'd5);
    inst_1 = make_mul(5'd20, 5'd0, 5'd0);
    set_producer(0, 1'b0, 5'd12);
    check_issue(1'b0, 1'b0, "blocked lane0 Store also blocks lane1 multiply");
    inst_0 = make_mul(5'd20, 5'd0, 5'd0);
    inst_1 = make_st_w(5'd12, 5'd5);
    check_issue(1'b1, 1'b0, "lane0 multiply issues while lane1 Store waits");

    // The adjacent load/store pair remains single-issued because lane1 has no
    // memory datapath (and this example also has a same-packet RAW dependency).
    inst_0 = make_ld_w(5'd12, 5'd4);
    inst_1 = make_st_w(5'd12, 5'd5);
    clear_producers();
    check_issue(1'b1, 1'b0, "adjacent load and Store do not issue in one packet");

    front_valid_0 = 1'b1;
    front_valid_1 = 1'b1;

    check_raw_matrix();

    $display("PASS issue_special_tb");
    $finish;
  end
endmodule
