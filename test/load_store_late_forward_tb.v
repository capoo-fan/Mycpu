`timescale 1ns / 1ps
`include "mycpu.vh"

module load_store_late_forward_tb;
  reg clk;
  reg resetn;
  reg front_valid_0;
  reg [31:0] inst_0;
  reg data_addr_ok;
  reg data_data_ok;
  reg [31:0] data_rdata;

  wire [`DS_DEC_BUS_WD-1:0] dec_0;
  wire [`FS_TO_DS_BUS_WD-1:0] fs_0 =
       {32'h1c00_0000, inst_0, 1'b0, 32'b0};
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_0 = {dec_0, fs_0};
  wire [4:0] front_raddr1_0_hot =
       front_bus_0[`FS_TO_DS_BUS_WD + 58 +: 5];
  wire [4:0] front_raddr2_0_hot =
       front_bus_0[`FS_TO_DS_BUS_WD + 53 +: 5];

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
  wire ms_allowin;
  wire ms_to_ws_valid_0;
  wire ms_to_ws_valid_1;
  wire [`MS_TO_WS_BUS_WD-1:0] ms_to_ws_bus_0;
  wire [`MS_TO_WS_BUS_1_WD-1:0] ms_to_ws_bus_1;
  wire [`MS_FWD_BUS_WD-1:0] ms_fwd_bus_0;
  wire [`MS_FWD_BUS_1_WD-1:0] ms_fwd_bus_1;
  wire ws_allowin;
  wire [`WS_TO_RF_BUS_WD-1:0] ws_to_rf_bus;
  wire data_req;
  wire data_wr;
  wire [31:0] data_addr;
  wire [31:0] data_wdata;

  function [31:0] make_load;
    input [4:0] rd;
    input [4:0] rj;
    begin
      make_load = 32'h2880_0000 | {22'b0, rj, rd};
    end
  endfunction

  function [31:0] make_store;
    input [4:0] rd;
    input [4:0] rj;
    begin
      make_store = 32'h2980_0000 | {22'b0, rj, rd};
    end
  endfunction

  inst_decoder dec0(.inst(inst_0), .dec_bus(dec_0));

  ISSUE_stage u_issue(
    .clk(clk), .resetn(resetn),
    .front_valid_0(front_valid_0), .front_bus_0(front_bus_0),
    .front_raddr1_0_hot(front_raddr1_0_hot),
    .front_raddr2_0_hot(front_raddr2_0_hot),
    .front_valid_1(1'b0), .front_bus_1({`IBUF_ENTRY_BUS_WD{1'b0}}),
    .front_raddr1_1_hot(5'b0), .front_raddr2_1_hot(5'b0),
    .pop_0(pop_0), .pop_1(pop_1), .special_fire(),
    .br_taken(1'b0), .special_block(1'b0), .es_allowin(es_allowin),
    .es_fwd_bus_0(es_fwd_bus_0), .es_fwd_bus_1(es_fwd_bus_1),
    .ms_fwd_bus_0(ms_fwd_bus_0), .ms_fwd_bus_1(ms_fwd_bus_1),
    .ws_to_rf_bus(ws_to_rf_bus),
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
    .flush(1'b0), .ms_allowin(ms_allowin), .es_allowin(es_allowin),
    .es_to_ms_valid_0(es_to_ms_valid_0),
    .es_to_ms_valid_1(es_to_ms_valid_1),
    .es_to_ms_bus_0(es_to_ms_bus_0), .es_to_ms_bus_1(es_to_ms_bus_1),
    .es_fwd_bus_0(es_fwd_bus_0), .es_fwd_bus_1(es_fwd_bus_1),
    .csr_busy(), .cacop_busy(), .csr_raddr(), .csr_rdata(32'b0)
  );

  MEM_stage u_mem(
    .clk(clk), .resetn(resetn),
    .es_to_ms_valid_0(es_to_ms_valid_0),
    .es_to_ms_valid_1(es_to_ms_valid_1),
    .es_to_ms_bus_0(es_to_ms_bus_0),
    .es_to_ms_bus_1(es_to_ms_bus_1),
    .ws_allowin(ws_allowin), .ws_to_rf_bus(ws_to_rf_bus),
    .ms_allowin(ms_allowin),
    .ms_to_ws_valid_0(ms_to_ws_valid_0),
    .ms_to_ws_valid_1(ms_to_ws_valid_1),
    .ms_to_ws_bus_0(ms_to_ws_bus_0), .ms_to_ws_bus_1(ms_to_ws_bus_1),
    .ms_fwd_bus_0(ms_fwd_bus_0), .ms_fwd_bus_1(ms_fwd_bus_1),
    .csr_busy(), .cacop_busy(), .br_taken(), .br_target(),
    .bpu_valid(), .bpu_is_bj(), .bpu_pc(),
    .bpu_real_taken(), .bpu_real_target(),
    .icacop_req_valid(), .icacop_req_code(), .icacop_req_addr(),
    .icacop_req_ready(1'b1), .icacop_done(1'b0),
    .cacop_flush(), .cacop_flush_target(),
    .data_sram_req(data_req), .data_sram_wr(data_wr),
    .data_sram_size(), .data_sram_wstrb(),
    .data_sram_addr(data_addr), .data_sram_wdata(data_wdata),
    .data_sram_addr_is_sram(1'b1),
    .data_sram_addr_ok(data_addr_ok),
    .data_sram_data_ok(data_data_ok), .data_sram_rdata(data_rdata)
  );

  WB_stage u_wb(
    .clk(clk), .resetn(resetn),
    .ms_to_ws_valid_0(ms_to_ws_valid_0),
    .ms_to_ws_valid_1(ms_to_ws_valid_1),
    .ms_to_ws_bus_0(ms_to_ws_bus_0),
    .ms_to_ws_bus_1(ms_to_ws_bus_1),
    .ws_allowin(ws_allowin), .ws_to_rf_bus(ws_to_rf_bus),
    .csr_busy(), .csr_we(), .csr_waddr(), .csr_wmask(), .csr_wdata(),
    .csr_ctx_update(), .csr_flush(), .csr_flush_target()
  );

  always #5 clk = ~clk;

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "load_store_late_forward_tb failed");
    end
  endtask

  task reset_dut;
    begin
      @(negedge clk);
      resetn = 1'b0;
      front_valid_0 = 1'b0;
      inst_0 = 32'b0;
      data_addr_ok = 1'b0;
      data_data_ok = 1'b0;
      data_rdata = 32'b0;
      repeat (5) @(posedge clk);
      @(negedge clk);
      resetn = 1'b1;
      repeat (3) @(posedge clk);
      @(negedge clk);
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    front_valid_0 = 1'b0;
    inst_0 = 32'b0;
    data_addr_ok = 1'b0;
    data_data_ok = 1'b0;
    data_rdata = 32'b0;

    // ld.w r12, r0, 0; st.w r12, r0, 0
    // Store data may leave ISSUE while the load is still in EX.
    reset_dut();
    inst_0 = make_load(5'd12, 5'd0);
    front_valid_0 = 1'b1;
    #1;
    if (!pop_0 || pop_1)
      fail("load did not issue");
    @(posedge clk);
    @(negedge clk);
    inst_0 = make_store(5'd12, 5'd0);
    #1;
    if (!pop_0 || pop_1)
      fail("load-dependent store data was not issued early");
    if (!ds_to_es_bus_0[`DS_TO_ES_BUS_WD-1] ||
        ds_to_es_bus_0[`DS_TO_ES_BUS_WD-2:`DS_TO_ES_BUS_WD-6] !== 5'd12)
      fail("late store data tag was not carried into EX");

    @(posedge clk);
    #1;
    if (!data_req || data_wr || data_addr !== 32'b0)
      fail("load did not enter MEM before the early store");
    @(negedge clk);
    front_valid_0 = 1'b0;
    data_addr_ok = 1'b1;
    @(posedge clk);
    @(negedge clk);
    data_addr_ok = 1'b0;
    data_rdata = 32'h1234_5678;
    data_data_ok = 1'b1;
    @(posedge clk);
    #1;
    if (!ms_fwd_bus_0[38] || !es_to_ms_valid_0)
      fail("load completion did not release the held store");
    @(negedge clk);
    data_data_ok = 1'b0;
    @(posedge clk);
    #1;
    if (!data_req || !data_wr || data_addr !== 32'b0 ||
        data_wdata !== 32'h1234_5678)
      fail("MEM did not late-forward load data into the store");

    @(negedge clk);
    data_addr_ok = 1'b1;
    @(posedge clk);
    @(negedge clk);
    data_addr_ok = 1'b0;
    data_data_ok = 1'b1;
    @(posedge clk);
    @(negedge clk);
    data_data_ok = 1'b0;

    // ld.w r12, r0, 0; st.w r7, r12, 0
    // The same load used as the address must still block ISSUE.
    reset_dut();
    inst_0 = make_load(5'd12, 5'd0);
    front_valid_0 = 1'b1;
    #1;
    if (!pop_0)
      fail("address-dependency setup load did not issue");
    @(posedge clk);
    @(negedge clk);
    inst_0 = make_store(5'd7, 5'd12);
    #1;
    if (pop_0 || pop_1)
      fail("load-dependent store address issued before the address was ready");

    $display("PASS load_store_late_forward_tb");
    $finish;
  end
endmodule

module mult_gen_0(
  input  wire        CLK,
  input  wire [31:0] A,
  input  wire [31:0] B,
  output wire [63:0] P
);
  assign P = 64'b0;
endmodule
