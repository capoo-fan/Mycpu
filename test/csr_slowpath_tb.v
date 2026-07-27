`timescale 1ns / 1ps
`include "mycpu.vh"

module csr_slowpath_tb;
  reg         clk;
  reg         resetn;
  reg         ms_valid;
  reg  [`MS_TO_WS_BUS_WD-1:0] ms_bus;
  wire        ws_allowin;
  wire        csr_busy;
  wire        csr_we;
  wire [13:0] csr_waddr;
  wire [31:0] csr_wmask;
  wire [31:0] csr_wdata;
  wire        csr_ctx_update;
  wire        csr_flush;
  wire [31:0] csr_flush_target;
  wire [31:0] crmd;
  wire [31:0] dmw0;
  wire [31:0] dmw1;
  wire [`TRANS_CTX_WD-1:0] trans_ctx;
  reg  [31:0] vaddr;
  wire [31:0] inst_paddr;
  wire [31:0] data_paddr;
  wire [31:0] cacop_paddr;
  integer cycles;

  WB_stage wb(
    .clk(clk), .resetn(resetn),
    .ms_to_ws_valid_0(ms_valid), .ms_to_ws_valid_1(1'b0),
    .ms_to_ws_bus_0(ms_bus),
    .ms_to_ws_bus_1({`MS_TO_WS_BUS_1_WD{1'b0}}),
    .ws_allowin(ws_allowin), .ws_to_rf_bus(), .csr_busy(csr_busy),
    .csr_we(csr_we), .csr_waddr(csr_waddr),
    .csr_wmask(csr_wmask), .csr_wdata(csr_wdata),
    .csr_ctx_update(csr_ctx_update), .csr_flush(csr_flush),
    .csr_flush_target(csr_flush_target)
  );

  csr csr_file(
    .clk(clk), .resetn(resetn), .raddr(14'b0), .rdata(),
    .we(csr_we), .waddr(csr_waddr), .wmask(csr_wmask), .wdata(csr_wdata),
    .crmd(crmd), .dmw0(dmw0), .dmw1(dmw1), .trans_ctx(trans_ctx)
  );

  addr_translate inst_translate(
    .clk(clk), .resetn(resetn), .ctx_update(csr_ctx_update),
    .ctx_in(trans_ctx), .vaddr(vaddr), .paddr(inst_paddr)
  );
  addr_translate data_translate(
    .clk(clk), .resetn(resetn), .ctx_update(csr_ctx_update),
    .ctx_in(trans_ctx), .vaddr(vaddr), .paddr(data_paddr)
  );
  addr_translate cacop_translate(
    .clk(clk), .resetn(resetn), .ctx_update(csr_ctx_update),
    .ctx_in(trans_ctx), .vaddr(vaddr), .paddr(cacop_paddr)
  );

  always #5 clk = ~clk;

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "csr_slowpath_tb failed");
    end
  endtask

  task submit_csr;
    input [13:0] addr;
    input [31:0] value;
    input [31:0] pc;
    begin
      @(negedge clk);
      ms_bus = {pc, 32'b0, 1'b0, 1'b0, 5'b0,
                1'b0, 1'b0, 1'b0, 32'b0,
                1'b1, addr, 32'hffff_ffff, value};
      ms_valid = 1'b1;
      @(posedge clk);
      #1;
      @(negedge clk);
      ms_valid = 1'b0;
      ms_bus = {`MS_TO_WS_BUS_WD{1'b0}};

      cycles = 0;
      while (!csr_flush) begin
        @(posedge clk);
        #1;
        cycles = cycles + 1;
        if (!ws_allowin)
          fail("WB backpressured during CSR slow-path commit");
        if (cycles > 12)
          fail("CSR slow-path flush timeout");
      end
      if (csr_flush_target !== pc + 32'd4)
        fail("CSR flush target is not PC+4");
      @(posedge clk);
      #1;
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    ms_valid = 1'b0;
    ms_bus = {`MS_TO_WS_BUS_WD{1'b0}};
    vaddr = 32'he123_4567;
    repeat (5) @(posedge clk);
    resetn = 1'b1;
    repeat (3) @(posedge clk);

    // Program DMW0 first; direct mode keeps the distributed local contexts
    // inactive even though the DMW fields themselves have changed.
    submit_csr(14'h0180, 32'hec00_0001, 32'h1c00_0100);
    if (inst_paddr !== vaddr || data_paddr !== vaddr || cacop_paddr !== vaddr)
      fail("DMW became active while CRMD remained in direct mode");

    // Enable mapped mode.  Every local translator must still show the old
    // context before FLUSH and all three must show the new context at FLUSH.
    @(negedge clk);
    ms_bus = {32'h1c00_0104, 32'b0, 1'b0, 1'b0, 5'b0,
              1'b0, 1'b0, 1'b0, 32'b0,
              1'b1, 14'h0000, 32'hffff_ffff, 32'h0000_0010};
    ms_valid = 1'b1;
    @(posedge clk);
    #1;
    @(negedge clk);
    ms_valid = 1'b0;
    ms_bus = {`MS_TO_WS_BUS_WD{1'b0}};

    cycles = 0;
    while (!csr_flush) begin
      if (inst_paddr !== vaddr || data_paddr !== vaddr || cacop_paddr !== vaddr)
        fail("a local translation context changed before CSR flush");
      @(posedge clk);
      #1;
      cycles = cycles + 1;
      if (cycles > 12)
        fail("mapped-mode CSR flush timeout");
    end
    if (inst_paddr !== 32'hc123_4567 ||
        data_paddr !== 32'hc123_4567 ||
        cacop_paddr !== 32'hc123_4567)
      fail("CSR flush occurred before all three local contexts updated");
    if (csr_flush_target !== 32'h1c00_0108)
      fail("mapped-mode CSR flush target mismatch");

    $display("PASS csr_slowpath_tb");
    $finish;
  end
endmodule
