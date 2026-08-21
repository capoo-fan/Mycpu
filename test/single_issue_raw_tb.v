`timescale 1ns / 1ps

// Back-to-back dependencies must work without any forwarding path. The core
// may issue only one memory transaction, and LD.W -> ST.W waits for load WB.
module single_issue_raw_tb;
  reg clk;
  reg resetn;

  wire        inst_req;
  wire [31:0] inst_addr;
  reg         inst_pending;
  reg  [31:0] inst_pending_addr;
  reg         inst_data_ok;
  reg  [31:0] inst_rdata;
  wire        inst_addr_ok = inst_req && !inst_pending;

  wire        data_req;
  wire        data_wr;
  wire [3:0]  data_wstrb;
  wire [31:0] data_addr;
  wire [31:0] data_wdata;
  reg         data_pending;
  reg         data_pending_wr;
  reg  [31:0] data_pending_addr;
  reg  [31:0] data_pending_wdata;
  reg  [3:0]  data_pending_wstrb;
  reg         data_data_ok;
  reg  [31:0] data_rdata;
  wire        data_addr_ok = data_req && !data_pending;

  reg [31:0] data_mem [0:3];
  integer cycles;
  integer write_count;
  integer i;

  mycpu_top dut(
    .clk(clk), .resetn(resetn),
    .inst_sram_req(inst_req), .inst_sram_wr(), .inst_sram_size(),
    .inst_sram_wstrb(), .inst_sram_addr(inst_addr), .inst_sram_wdata(),
    .inst_sram_addr_ok(inst_addr_ok), .inst_sram_data_ok(inst_data_ok),
    .inst_sram_rdata(inst_rdata),
    .data_sram_req(data_req), .data_sram_wr(data_wr), .data_sram_size(),
    .data_sram_wstrb(data_wstrb), .data_sram_addr(data_addr),
    .data_sram_wdata(data_wdata), .data_sram_addr_ok(data_addr_ok),
    .data_sram_data_ok(data_data_ok), .data_sram_rdata(data_rdata),
    .debug_wb_pc(), .debug_wb_rf_we(), .debug_wb_rf_wnum(),
    .debug_wb_rf_wdata()
  );

  always #5 clk = ~clk;

  always @(posedge clk) begin
    if (!resetn) begin
      inst_pending <= 1'b0;
      inst_data_ok <= 1'b0;
      data_pending <= 1'b0;
      data_data_ok <= 1'b0;
    end else begin
      inst_data_ok <= inst_pending;
      if (inst_pending) begin
        case (inst_pending_addr)
          32'h1c00_0000: inst_rdata <= 32'h0280_1404; // addi.w r4,r0,5
          32'h1c00_0004: inst_rdata <= 32'h0280_1c85; // addi.w r5,r4,7
          32'h1c00_0008: inst_rdata <= 32'h0010_10a6; // add.w  r6,r5,r4
          32'h1c00_000c: inst_rdata <= 32'h2980_0006; // st.w   r6,r0,0
          32'h1c00_0010: inst_rdata <= 32'h2880_0007; // ld.w   r7,r0,0
          32'h1c00_0014: inst_rdata <= 32'h2980_1007; // st.w   r7,r0,4
          default:       inst_rdata <= 32'h5000_0000; // b      0
        endcase
      end
      inst_pending <= inst_addr_ok;
      if (inst_addr_ok)
        inst_pending_addr <= inst_addr;

      data_data_ok <= data_pending;
      if (data_pending) begin
        data_rdata <= data_mem[data_pending_addr[3:2]];
        if (data_pending_wr) begin
          if (data_pending_wstrb[0]) data_mem[data_pending_addr[3:2]][7:0] <= data_pending_wdata[7:0];
          if (data_pending_wstrb[1]) data_mem[data_pending_addr[3:2]][15:8] <= data_pending_wdata[15:8];
          if (data_pending_wstrb[2]) data_mem[data_pending_addr[3:2]][23:16] <= data_pending_wdata[23:16];
          if (data_pending_wstrb[3]) data_mem[data_pending_addr[3:2]][31:24] <= data_pending_wdata[31:24];
          write_count <= write_count + 1;
        end
      end
      data_pending <= data_addr_ok;
      if (data_addr_ok) begin
        data_pending_wr <= data_wr;
        data_pending_addr <= data_addr;
        data_pending_wdata <= data_wdata;
        data_pending_wstrb <= data_wstrb;
      end

      if (data_req && data_pending)
        $fatal(1, "overlapping CPU memory requests");
    end

    cycles <= cycles + 1;
    if (cycles > 300)
      $fatal(1, "single_issue_raw_tb timeout");
  end

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    inst_pending = 1'b0;
    inst_pending_addr = 32'b0;
    inst_data_ok = 1'b0;
    inst_rdata = 32'b0;
    data_pending = 1'b0;
    data_pending_wr = 1'b0;
    data_pending_addr = 32'b0;
    data_pending_wdata = 32'b0;
    data_pending_wstrb = 4'b0;
    data_data_ok = 1'b0;
    data_rdata = 32'b0;
    cycles = 0;
    write_count = 0;
    for (i = 0; i < 4; i = i + 1)
      data_mem[i] = 32'b0;

    repeat (4) @(posedge clk);
    resetn = 1'b1;

    wait (write_count == 2);
    @(posedge clk);
    #1;
    if (data_mem[0] !== 32'd17 || data_mem[1] !== 32'd17)
      $fatal(1, "RAW or LD.W-to-ST.W serialization failed");
    if (dut.u_regfile.rf[4] !== 32'd5 || dut.u_regfile.rf[5] !== 32'd12 ||
        dut.u_regfile.rf[6] !== 32'd17 || dut.u_regfile.rf[7] !== 32'd17)
      $fatal(1, "serialized register results are incorrect");

    $display("PASS single_issue_raw_tb cycles=%0d", cycles);
    $finish;
  end
endmodule

module mult_gen_0(
  input  wire        CLK,
  input  wire [31:0] A,
  input  wire [31:0] B,
  output wire [31:0] P
);
  reg [31:0] p0, p1, p2;
  always @(posedge CLK) begin
    p0 <= A * B;
    p1 <= p0;
    p2 <= p1;
  end
  assign P = p2;
endmodule
