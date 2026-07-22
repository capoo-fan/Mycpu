`timescale 1ns / 1ps

module csr_pipeline_tb;
  reg clk;
  reg resetn;

  wire        inst_req;
  wire [31:0] inst_addr;
  reg         inst_addr_ok;
  reg         inst_data_ok;
  reg  [31:0] inst_rdata;
  reg  [31:0] pending_inst_addr;

  wire        data_req;
  wire [31:0] data_addr;
  reg  [31:0] lane1_wb_pc;

  reg [31:0] expected_pc [0:11];
  reg [ 4:0] expected_reg[0:11];
  reg [31:0] expected_data[0:11];
  integer event_count;
  integer cycle_count;
  reg saw_mapped_fetch;

  mycpu_top dut(
              .clk(clk), .resetn(resetn),
              .inst_sram_req(inst_req), .inst_sram_wr(),
              .inst_sram_size(), .inst_sram_wstrb(),
              .inst_sram_addr(inst_addr), .inst_sram_wdata(),
              .inst_sram_addr_ok(inst_addr_ok),
              .inst_sram_data_ok(inst_data_ok),
              .inst_sram_rdata(inst_rdata),
              .data_sram_req(data_req), .data_sram_wr(),
              .data_sram_size(), .data_sram_wstrb(),
              .data_sram_addr(data_addr), .data_sram_wdata(),
              .data_sram_addr_ok(1'b1), .data_sram_data_ok(1'b1),
              .data_sram_rdata(32'b0),
              .debug_wb_pc(), .debug_wb_rf_we(),
              .debug_wb_rf_wnum(), .debug_wb_rf_wdata()
            );

  task check_commit;
    input [31:0] commit_pc;
    input [ 4:0] commit_reg;
    input [31:0] commit_data;
    begin
      if (event_count > 11 || commit_pc !== expected_pc[event_count] ||
          commit_reg !== expected_reg[event_count] ||
          commit_data !== expected_data[event_count])
      begin
        $display("FAIL event %0d: pc=%h reg=%0d data=%h",
                 event_count, commit_pc, commit_reg, commit_data);
        $fatal(1, "csr_pipeline_tb failed");
      end
      event_count = event_count + 1;
      if (commit_reg == 5'd6)
      begin
        if (!saw_mapped_fetch || dut.csr_crmd !== 32'h0000_0008 ||
            dut.csr_dmw0 !== 32'h0200_0001 || data_req)
          $fatal(1, "CSR state, mapped fetch, or data request check failed");
        $display("PASS csr_pipeline_tb");
        $finish;
      end
    end
  endtask

  function [31:0] rom_word;
    input [31:0] addr;
    begin
      case (addr[5:2])
        4'd0: rom_word = 32'h0280_040a; // addi.w  r10, r0, 1
        4'd1: rom_word = 32'h0000_6d4b; // cpucfg  r11, r10
        4'd2: rom_word = 32'h0280_056c; // addi.w  r12, r11, 1
        4'd3: rom_word = 32'h1404_0002;
        4'd4: rom_word = 32'h0380_0442;
        4'd5: rom_word = 32'h0406_0022;
        4'd6: rom_word = 32'h0280_4003;
        4'd7: rom_word = 32'h0400_0023;
        4'd8: rom_word = 32'h0280_2004;
        4'd9: rom_word = 32'h0280_6005;
        4'd10: rom_word = 32'h0400_00a4;
        4'd11: rom_word = 32'h0281_5406;
        default: rom_word = 32'h5000_0000;
      endcase
    end
  endfunction

  always #5 clk = ~clk;

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      inst_addr_ok      <= 1'b0;
      inst_data_ok      <= 1'b0;
      inst_rdata        <= 32'b0;
      pending_inst_addr <= 32'b0;
    end
    else
    begin
      inst_addr_ok <= inst_req;
      inst_data_ok <= inst_addr_ok;
      if (inst_req)
        pending_inst_addr <= inst_addr;
      if (inst_addr_ok)
        inst_rdata <= rom_word(pending_inst_addr);
    end
  end

  always @(posedge clk)
  begin
    // The SoC-compatible debug outputs intentionally stay tied to constants.
    // Capture lane1's PC at the MEM-to-WB boundary only inside the testbench;
    // lane0's PC is already retained by WB for CSR sequencing.
    if (!resetn)
      lane1_wb_pc <= 32'b0;
    else if (dut.ms_to_ws_valid_1)
      lane1_wb_pc <= dut.ms_to_ws_bus_1[184:153];

    if (resetn && inst_req && (inst_addr[31:29] == 3'b001))
      saw_mapped_fetch <= 1'b1;

    if (resetn && dut.u_wb.ws_rf_we_0 &&
        (dut.u_wb.ws_rf_waddr_0 != 5'b0))
      check_commit(dut.u_wb.ws_pc_0, dut.u_wb.ws_rf_waddr_0,
                   dut.u_wb.ws_rf_wdata_0);

    if (resetn && dut.u_wb.ws_rf_we_1 &&
        (dut.u_wb.ws_rf_waddr_1 != 5'b0))
      check_commit(lane1_wb_pc, dut.u_wb.ws_rf_waddr_1,
                   dut.u_wb.ws_rf_wdata_1);

    cycle_count = cycle_count + 1;
    if (cycle_count > 3000)
      $fatal(1, "csr_pipeline_tb timeout");
  end

  initial
  begin
    clk              = 1'b0;
    resetn           = 1'b0;
    inst_addr_ok      = 1'b0;
    inst_data_ok      = 1'b0;
    inst_rdata        = 32'b0;
    pending_inst_addr = 32'b0;
    lane1_wb_pc       = 32'b0;
    event_count       = 0;
    cycle_count       = 0;
    saw_mapped_fetch  = 1'b0;

    expected_pc[0] = 32'h1c00_0000; expected_reg[0] = 5'd10; expected_data[0] = 32'h0000_0001;
    expected_pc[1] = 32'h1c00_0004; expected_reg[1] = 5'd11; expected_data[1] = 32'h0001_f1f0;
    expected_pc[2] = 32'h1c00_0008; expected_reg[2] = 5'd12; expected_data[2] = 32'h0001_f1f1;
    expected_pc[3] = 32'h1c00_000c; expected_reg[3] = 5'd2; expected_data[3] = 32'h0200_0000;
    expected_pc[4] = 32'h1c00_0010; expected_reg[4] = 5'd2; expected_data[4] = 32'h0200_0001;
    expected_pc[5] = 32'h1c00_0014; expected_reg[5] = 5'd2; expected_data[5] = 32'h0000_0000;
    expected_pc[6] = 32'h1c00_0018; expected_reg[6] = 5'd3; expected_data[6] = 32'h0000_0010;
    expected_pc[7] = 32'h1c00_001c; expected_reg[7] = 5'd3; expected_data[7] = 32'h0000_0008;
    expected_pc[8] = 32'h1c00_0020; expected_reg[8] = 5'd4; expected_data[8] = 32'h0000_0008;
    expected_pc[9] = 32'h1c00_0024; expected_reg[9] = 5'd5; expected_data[9] = 32'h0000_0018;
    expected_pc[10] = 32'h1c00_0028; expected_reg[10] = 5'd4; expected_data[10] = 32'h0000_0010;
    expected_pc[11] = 32'h1c00_002c; expected_reg[11] = 5'd6; expected_data[11] = 32'h0000_0055;

    repeat (6) @(posedge clk);
    resetn = 1'b1;
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
