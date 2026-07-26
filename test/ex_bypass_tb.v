`timescale 1ns / 1ps
`include "mycpu.vh"

module ex_bypass_tb;
  reg clk;
  reg resetn;
  reg flush;
  reg ms_allowin;
  reg ds_valid_0;
  reg ds_valid_1;
  reg [`DS_TO_ES_BUS_WD-1:0] ds_bus_0;
  reg [`DS_TO_ES_BUS_WD-1:0] ds_bus_1;
  reg [`MS_FWD_BUS_WD-1:0] ms_bus_0;
  reg [`MS_FWD_BUS_WD-1:0] ms_bus_1;
  reg [`WS_TO_RF_BUS_WD-1:0] ws_bus;
  reg [31:0] csr_rdata;

  wire es_allowin;
  wire es_to_ms_valid_0;
  wire es_to_ms_valid_1;
  wire [`ES_TO_MS_BUS_WD-1:0] es_to_ms_bus_0;
  wire [`ES_TO_MS_BUS_WD-1:0] es_to_ms_bus_1;

  EXE_stage dut(
    .clk(clk), .resetn(resetn),
    .ds_to_es_valid_0(ds_valid_0), .ds_to_es_valid_1(ds_valid_1),
    .ds_to_es_bus_0(ds_bus_0), .ds_to_es_bus_1(ds_bus_1),
    .flush(flush), .ms_allowin(ms_allowin), .es_allowin(es_allowin),
    .es_to_ms_valid_0(es_to_ms_valid_0),
    .es_to_ms_valid_1(es_to_ms_valid_1),
    .es_to_ms_bus_0(es_to_ms_bus_0), .es_to_ms_bus_1(es_to_ms_bus_1),
    .ms_fwd_bus_0(ms_bus_0), .ms_fwd_bus_1(ms_bus_1),
    .ws_to_rf_bus(ws_bus),
    .csr_busy(), .cacop_busy(), .csr_raddr(), .csr_rdata(csr_rdata)
  );

  always #5 clk = ~clk;

  function [`DS_TO_ES_BUS_WD-1:0] make_ds;
    input [31:0] pc;
    input [11:0] alu_op;
    input [31:0] rf_rj;
    input [31:0] rf_rkd;
    input [ 4:0] rj;
    input [ 4:0] rkd;
    input [31:0] imm;
    input        src1_is_pc;
    input        src2_is_imm;
    input        need_rj;
    input        need_rkd;
    input        gr_we;
    input        mem_we;
    input [ 4:0] dest;
    input        is_mul;
    input [ 3:0] br_op;
    input [31:0] br_offs;
    input        is_cpucfg;
    input        is_csr;
    input        is_csrxchg;
    begin
      make_ds = {
        pc, alu_op, rf_rj, rf_rkd, rj, rkd, imm,
        src1_is_pc, src2_is_imm, need_rj, need_rkd,
        1'b0, gr_we, mem_we, dest,
        is_mul, 1'b1, 1'b0,
        1'b0, 1'b0, 1'b0, 1'b0, 1'b0,
        1'b0, 32'b0, br_op, br_offs,
        is_cpucfg, 1'b0, 5'b0,
        is_csr, is_csrxchg, 14'h0180
      };
    end
  endfunction

  function [`MS_FWD_BUS_WD-1:0] make_ms;
    input valid;
    input ready;
    input [4:0] dest;
    input [31:0] data;
    begin
      make_ms = {valid, 1'b1, ready, 1'b0, dest, data};
    end
  endfunction

  function [`WS_TO_RF_BUS_WD-1:0] make_ws;
    input we0;
    input [4:0] addr0;
    input [31:0] data0;
    input we1;
    input [4:0] addr1;
    input [31:0] data1;
    begin
      make_ws = {we0, addr0, data0, we1, addr1, data1};
    end
  endfunction

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "ex_bypass_tb failed");
    end
  endtask

  task reset_dut;
    begin
      @(negedge clk);
      resetn = 1'b0;
      flush = 1'b0;
      ms_allowin = 1'b1;
      ds_valid_0 = 1'b0;
      ds_valid_1 = 1'b0;
      ds_bus_0 = {`DS_TO_ES_BUS_WD{1'b0}};
      ds_bus_1 = {`DS_TO_ES_BUS_WD{1'b0}};
      ms_bus_0 = {`MS_FWD_BUS_WD{1'b0}};
      ms_bus_1 = {`MS_FWD_BUS_WD{1'b0}};
      ws_bus = {`WS_TO_RF_BUS_WD{1'b0}};
      csr_rdata = 32'h1234_5678;
      repeat (3) @(posedge clk);
      @(negedge clk);
      resetn = 1'b1;
      repeat (2) @(posedge clk);
      @(negedge clk);
    end
  endtask

  task launch_lane0;
    input [`DS_TO_ES_BUS_WD-1:0] bus;
    begin
      ds_bus_0 = bus;
      ds_valid_0 = 1'b1;
      ds_valid_1 = 1'b0;
      @(posedge clk);
      #1;
      ds_valid_0 = 1'b0;
    end
  endtask

  task launch_lane1;
    input [`DS_TO_ES_BUS_WD-1:0] bus;
    begin
      ds_bus_1 = bus;
      ds_valid_0 = 1'b0;
      ds_valid_1 = 1'b1;
      @(posedge clk);
      #1;
      ds_valid_1 = 1'b0;
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    flush = 1'b0;
    ms_allowin = 1'b1;
    ds_valid_0 = 1'b0;
    ds_valid_1 = 1'b0;
    ds_bus_0 = {`DS_TO_ES_BUS_WD{1'b0}};
    ds_bus_1 = {`DS_TO_ES_BUS_WD{1'b0}};
    ms_bus_0 = {`MS_FWD_BUS_WD{1'b0}};
    ms_bus_1 = {`MS_FWD_BUS_WD{1'b0}};
    ws_bus = {`WS_TO_RF_BUS_WD{1'b0}};
    csr_rdata = 32'h1234_5678;

    reset_dut();

    // RF fallback and independent MEM/WB selection for the two sources.
    launch_lane0(make_ds(32'h1c00_0000, 12'b1,
                         32'd10, 32'd20, 5'd2, 5'd3, 32'b0,
                         1'b0, 1'b0, 1'b1, 1'b1,
                         1'b1, 1'b0, 5'd8, 1'b0,
                         `BR_NONE, 32'b0, 1'b0, 1'b0, 1'b0));
    if (dut.es_rj_value_0 !== 32'd10 ||
        dut.es_rkd_value_raw_0 !== 32'd20 ||
        dut.alu_result_0 !== 32'd30)
      fail("RF fallback failed");

    ms_bus_0 = make_ms(1'b1, 1'b1, 5'd2, 32'd100);
    ws_bus = make_ws(1'b1, 5'd3, 32'd7, 1'b0, 5'b0, 32'b0);
    #1;
    if (dut.es_rj_value_0 !== 32'd100 ||
        dut.es_rkd_value_raw_0 !== 32'd7 ||
        dut.alu_result_0 !== 32'd107)
      fail("MEM0/WB0 source selection failed");

    // All producers match: MEM lane1 is youngest and must win.
    ms_bus_0 = make_ms(1'b1, 1'b1, 5'd4, 32'h1111_1111);
    ms_bus_1 = make_ms(1'b1, 1'b1, 5'd4, 32'h2222_2222);
    ws_bus = make_ws(1'b1, 5'd4, 32'h3333_3333,
                     1'b1, 5'd4, 32'h4444_4444);
    launch_lane0(make_ds(32'h1c00_0004, 12'b1,
                         32'h5555_5555, 32'h5555_5555, 5'd4, 5'd4, 32'b0,
                         1'b0, 1'b0, 1'b1, 1'b1,
                         1'b1, 1'b0, 5'd9, 1'b0,
                         `BR_NONE, 32'b0, 1'b0, 1'b0, 1'b0));
    if (dut.es_rj_value_0 !== 32'h2222_2222 ||
        dut.es_rkd_value_raw_0 !== 32'h2222_2222)
      fail("MEM1 priority over MEM0/WB/RF failed");

    // An unready MEM lane is not a bypass source; the ready older lane wins.
    ms_bus_1 = make_ms(1'b1, 1'b0, 5'd4, 32'haaaa_aaaa);
    #1;
    if (dut.es_rj_value_0 !== 32'h1111_1111)
      fail("unready MEM source was selected");

    // Lane1 uses the same network, with WB lane1 preferred over WB lane0.
    ms_bus_0 = {`MS_FWD_BUS_WD{1'b0}};
    ms_bus_1 = {`MS_FWD_BUS_WD{1'b0}};
    ws_bus = make_ws(1'b1, 5'd6, 32'd12, 1'b1, 5'd6, 32'd21);
    launch_lane1(make_ds(32'h1c00_0008, 12'b1,
                         32'd1, 32'd2, 5'd6, 5'd6, 32'b0,
                         1'b0, 1'b0, 1'b1, 1'b1,
                         1'b1, 1'b0, 5'd10, 1'b0,
                         `BR_NONE, 32'b0, 1'b0, 1'b0, 1'b0));
    if (dut.es_rj_value_1 !== 32'd21 ||
        dut.es_rkd_value_raw_1 !== 32'd21 ||
        dut.alu_result_1 !== 32'd42)
      fail("lane1 WB priority failed");

    // PC/immediate controls are applied after register bypass selection.
    ms_bus_0 = make_ms(1'b1, 1'b1, 5'd7, 32'h2000_0000);
    ws_bus = make_ws(1'b0, 5'b0, 32'b0, 1'b1, 5'd8, 32'h0000_0040);
    launch_lane0(make_ds(32'h1c00_0100, 12'b1,
                         32'b0, 32'b0, 5'd7, 5'd8, 32'd4,
                         1'b1, 1'b1, 1'b1, 1'b1,
                         1'b1, 1'b0, 5'd1, 1'b0,
                         `BR_JIRL, 32'd16, 1'b0, 1'b0, 1'b0));
    if (dut.es_alu_src1_0 !== 32'h1c00_0100 ||
        dut.es_alu_src2_0 !== 32'd4 ||
        dut.es_rkd_value_0 !== 32'h2000_0000 ||
        dut.es_real_target_0 !== 32'h2000_0010)
      fail("JIRL/PC/immediate operand construction failed");

    // CSR xchg mask/value and CPUCFG index both consume bypassed RF operands.
    launch_lane0(make_ds(32'h1c00_0104, 12'b0,
                         32'b0, 32'b0, 5'd7, 5'd8, 32'b0,
                         1'b0, 1'b0, 1'b1, 1'b1,
                         1'b1, 1'b0, 5'd11, 1'b0,
                         `BR_NONE, 32'b0, 1'b0, 1'b1, 1'b1));
    if (dut.es_csr_wmask_0 !== 32'h2000_0000 ||
        dut.es_csr_wvalue_0 !== 32'h0000_0040 ||
        dut.es_final_result_0 !== csr_rdata)
      fail("CSR bypass operands failed");

    ms_bus_0 = make_ms(1'b1, 1'b1, 5'd7, 32'd1);
    ws_bus = {`WS_TO_RF_BUS_WD{1'b0}};
    launch_lane0(make_ds(32'h1c00_0108, 12'b0,
                         32'b0, 32'b0, 5'd7, 5'd0, 32'b0,
                         1'b0, 1'b0, 1'b1, 1'b0,
                         1'b1, 1'b0, 5'd12, 1'b0,
                         `BR_NONE, 32'b0, 1'b1, 1'b0, 1'b0));
    if (dut.es_final_result_0 !== 32'h0001_f1f0)
      fail("CPUCFG bypassed index failed");

    // Store data uses the selected rkd value.
    ms_bus_0 = {`MS_FWD_BUS_WD{1'b0}};
    ws_bus = make_ws(1'b0, 5'b0, 32'b0, 1'b1, 5'd9, 32'hdead_beef);
    launch_lane0(make_ds(32'h1c00_010c, 12'b1,
                         32'h1000_0000, 32'b0, 5'd2, 5'd9, 32'd8,
                         1'b0, 1'b1, 1'b1, 1'b1,
                         1'b0, 1'b1, 5'd0, 1'b0,
                         `BR_NONE, 32'b0, 1'b0, 1'b0, 1'b0));
    if (dut.es_rkd_value_0 !== 32'hdead_beef ||
        dut.es_alu_src2_0 !== 32'd8)
      fail("Store data bypass failed");

    // A multiply holds the whole EX packet. Both lanes must retain resolved
    // operands after their original MEM sources have advanced and disappeared.
    ms_bus_0 = make_ms(1'b1, 1'b1, 5'd2, 32'd6);
    ms_bus_1 = make_ms(1'b1, 1'b1, 5'd3, 32'd7);
    ws_bus = {`WS_TO_RF_BUS_WD{1'b0}};
    ds_bus_0 = make_ds(32'h1c00_0110, 12'b0,
                       32'b0, 32'b0, 5'd2, 5'd3, 32'b0,
                       1'b0, 1'b0, 1'b1, 1'b1,
                       1'b1, 1'b0, 5'd13, 1'b1,
                       `BR_NONE, 32'b0, 1'b0, 1'b0, 1'b0);
    ds_bus_1 = make_ds(32'h1c00_0114, 12'b1,
                       32'b0, 32'b0, 5'd2, 5'd3, 32'b0,
                       1'b0, 1'b0, 1'b1, 1'b1,
                       1'b1, 1'b0, 5'd14, 1'b0,
                       `BR_NONE, 32'b0, 1'b0, 1'b0, 1'b0);
    ds_valid_0 = 1'b1;
    ds_valid_1 = 1'b1;
    @(posedge clk);
    #1;
    ds_valid_0 = 1'b0;
    ds_valid_1 = 1'b0;
    @(posedge clk);
    #1;
    ms_bus_0 = {`MS_FWD_BUS_WD{1'b0}};
    ms_bus_1 = {`MS_FWD_BUS_WD{1'b0}};
    repeat (2) @(posedge clk);
    #1;
    if (dut.es_exec_result_0 !== 32'd42 || dut.alu_result_1 !== 32'd13)
      fail("held EX packet lost bypassed operands");

    $display("PASS ex_bypass_tb");
    $finish;
  end
endmodule

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
