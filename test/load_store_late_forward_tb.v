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
       front_bus_0[`FS_TO_DS_BUS_WD + 56 +: 5];
  wire [4:0] front_raddr2_0_hot =
       front_bus_0[`FS_TO_DS_BUS_WD + 51 +: 5];

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
  wire load_wakeup_valid;
  wire [31:0] load_wakeup_data;
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

  function [31:0] make_slli;
    input [4:0] rd;
    input [4:0] rj;
    input [4:0] shamt;
    begin
      make_slli = 32'h0040_8000 |
                  {17'b0, shamt, rj, rd};
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
    .load_wakeup_valid(load_wakeup_valid),
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
    .flush(1'b0), .ms_allowin(ms_allowin),
    .load_wakeup_valid(load_wakeup_valid),
    .load_wakeup_data(load_wakeup_data),
    .es_allowin(es_allowin),
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
    .load_wakeup_valid(load_wakeup_valid),
    .load_wakeup_data(load_wakeup_data),
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
    .data_sram_store_ready(2'b11),
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
    if (!data_req || !data_wr || data_addr !== 32'b0 ||
        data_wdata !== 32'h1234_5678)
      fail("load completion did not latch late store data into MEM");

    @(negedge clk);
    data_data_ok = 1'b0;
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

    // ld.w r12, r0, 0; slli.w r12, r12, 1
    // 普通 ALU 消费者应在 data_ok 返回拍进入 EX，而不是再等 WB。
    reset_dut();
    inst_0 = make_load(5'd12, 5'd0);
    front_valid_0 = 1'b1;
    #1;
    if (!pop_0)
      fail("ALU wakeup setup load did not issue");
    @(posedge clk);
    @(negedge clk);
    inst_0 = make_slli(5'd12, 5'd12, 5'd1);
    #1;
    if (pop_0)
      fail("ALU consumer bypassed the load before data completion");
    @(posedge clk);
    #1;
    if (!data_req || pop_0)
      fail("ALU wakeup load did not wait in MEM");
    @(negedge clk);
    data_addr_ok = 1'b1;
    @(posedge clk);
    @(negedge clk);
    data_addr_ok = 1'b0;
    data_rdata = 32'h1234_5678;
    data_data_ok = 1'b1;
    #1;
    if (!load_wakeup_valid || load_wakeup_data !== 32'h1234_5678)
      fail("ALU load response did not create the expected wakeup");
    if (!pop_0 || !ds_to_es_valid_0 || ds_to_es_bus_0[1:0] !== 2'b10)
      fail("ALU consumer did not issue on the load response cycle");
    if (u_exe.ds_alu_src1_final !== 32'h1234_5678)
      fail("ALU wakeup data did not reach the EX input mux");
    @(posedge clk);
    #1;
    if (!u_exe.es_valid_0 ||
        u_exe.es_alu_src1_0 !== 32'h1234_5678)
      fail("ALU consumer did not capture wakeup data in EX");
    @(negedge clk);
    front_valid_0 = 1'b0;
    data_data_ok = 1'b0;
    @(posedge clk);
    #1;
    if (!ms_fwd_bus_0[38] ||
        ms_fwd_bus_0[31:0] !== 32'h2468_acf0)
      fail("ALU consumer produced the wrong result after wakeup");

    // ld.w r12, r0, 0; mul.w r15, r12, r12
    // 乘法器在发射边沿采样 ISSUE 数据，因此两个 DSP 输入都必须在
    // data_ok 拍直接选择返回值。
    reset_dut();
    inst_0 = make_load(5'd12, 5'd0);
    front_valid_0 = 1'b1;
    #1;
    if (!pop_0)
      fail("multiply wakeup setup load did not issue");
    @(posedge clk);
    @(negedge clk);
    inst_0 = make_mul(5'd15, 5'd12, 5'd12);
    #1;
    if (pop_0)
      fail("multiply consumer bypassed the load before data completion");
    @(posedge clk);
    @(negedge clk);
    data_addr_ok = 1'b1;
    @(posedge clk);
    @(negedge clk);
    data_addr_ok = 1'b0;
    data_rdata = 32'h0000_1234;
    data_data_ok = 1'b1;
    #1;
    if (!load_wakeup_valid || !pop_0 || !ds_to_es_valid_0 ||
        ds_to_es_bus_0[1:0] !== 2'b11)
      fail("multiply consumer did not wake both operands");
    if (u_exe.mul_src1_0 !== 32'h0000_1234 ||
        u_exe.mul_src2_0 !== 32'h0000_1234)
      fail("load response did not reach both multiplier launch inputs");
    @(posedge clk);
    #1;
    if (!u_exe.es_valid_0 || !u_exe.mul_pending_0 ||
        u_exe.es_alu_src1_0 !== 32'h0000_1234 ||
        u_exe.es_alu_src2_0 !== 32'h0000_1234)
      fail("multiply consumer did not capture load wakeup operands");
    @(negedge clk);
    front_valid_0 = 1'b0;
    data_data_ok = 1'b0;

    $display("PASS load_store_late_forward_tb");
    $finish;
  end
endmodule

module mult_gen_0(
  input  wire        CLK,
  input  wire [31:0] A,
  input  wire [31:0] B,
  output wire [31:0] P
);
  assign P = 32'b0;
endmodule
