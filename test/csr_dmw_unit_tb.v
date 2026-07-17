`timescale 1ns / 1ps
`include "mycpu.vh"

module csr_dmw_unit_tb;
  reg         clk;
  reg         resetn;
  reg  [13:0] raddr;
  wire [31:0] rdata;
  reg         we;
  reg  [13:0] waddr;
  reg  [31:0] wmask;
  reg  [31:0] wdata;
  wire [31:0] crmd;
  wire [31:0] dmw0;
  wire [31:0] dmw1;

  reg  [31:0] vaddr;
  wire [31:0] paddr;

  reg  [31:0] inst;
  wire [`DS_DEC_BUS_WD-1:0] dec_bus;

  csr u_csr(
        .clk(clk), .resetn(resetn), .raddr(raddr), .rdata(rdata),
        .we(we), .waddr(waddr), .wmask(wmask), .wdata(wdata),
        .crmd(crmd), .dmw0(dmw0), .dmw1(dmw1)
      );

  addr_translate u_addr_translate(
                   .vaddr(vaddr), .crmd(crmd), .dmw0(dmw0),
                   .dmw1(dmw1), .paddr(paddr)
                 );

  inst_decoder u_inst_decoder(.inst(inst), .dec_bus(dec_bus));

  always #5 clk = ~clk;

  task check32;
    input [31:0] actual;
    input [31:0] expected;
    input [255:0] name;
    begin
      if (actual !== expected)
      begin
        $display("FAIL %0s: actual=%h expected=%h", name, actual, expected);
        $fatal(1, "csr_dmw_unit_tb failed");
      end
    end
  endtask

  task csr_write;
    input [13:0] addr;
    input [31:0] mask;
    input [31:0] value;
    begin
      @(negedge clk);
      we    = 1'b1;
      waddr = addr;
      wmask = mask;
      wdata = value;
      @(posedge clk);
      #1;
      we = 1'b0;
    end
  endtask

  initial
  begin
    clk    = 1'b0;
    resetn = 1'b0;
    raddr  = 14'b0;
    we     = 1'b0;
    waddr  = 14'b0;
    wmask  = 32'b0;
    wdata  = 32'b0;
    vaddr  = 32'h8123_4567;
    inst   = 32'b0;

    repeat (2) @(posedge clk);
    #1;
    check32(crmd, 32'h0000_0008, "CRMD reset");
    check32(dmw0, 32'h0000_0000, "DMW0 reset");
    check32(paddr, 32'h8123_4567, "direct address");
    resetn = 1'b1;

    inst = {8'h04, 14'h0180, 5'd1, 5'd7};
    #1;
    if (dec_bus[15:0] !== {1'b1, 1'b0, 14'h0180})
    begin
      $display("FAIL CSRWR decode: %h", dec_bus[15:0]);
      $fatal(1, "csr_dmw_unit_tb failed");
    end
    inst = {8'h04, 14'h0181, 5'd2, 5'd8};
    #1;
    if (dec_bus[15:0] !== {1'b1, 1'b1, 14'h0181})
    begin
      $display("FAIL CSRXCHG decode: %h", dec_bus[15:0]);
      $fatal(1, "csr_dmw_unit_tb failed");
    end
    inst = {8'h04, 14'h0000, 5'd0, 5'd9};
    #1;
    if (dec_bus[15] !== 1'b0)
    begin
      $display("FAIL CSRRD must remain unsupported");
      $fatal(1, "csr_dmw_unit_tb failed");
    end

    csr_write(14'h0180, 32'hffff_ffff, 32'hecff_ffff);
    check32(dmw0, 32'hec00_0039, "DMW0 writable fields");
    csr_write(14'h0181, 32'hffff_ffff, 32'he400_0009);
    csr_write(14'h0000, 32'hffff_ffff, 32'h0000_0010);
    vaddr = 32'he123_4567;
    #1;
    check32(paddr, 32'hc123_4567, "DMW0 priority PLV0");

    csr_write(14'h0181, 32'hffff_ffff, 32'he400_0008);
    csr_write(14'h0180, 32'h0000_0008, 32'h0000_0000);
    csr_write(14'h0000, 32'h0000_0003, 32'h0000_0003);
    #1;
    check32(paddr, 32'h4123_4567, "DMW1 PLV3");

    csr_write(14'h0000, 32'h0000_0018, 32'h0000_0008);
    #1;
    check32(crmd, 32'h0000_000b, "CRMD masked exchange");
    check32(paddr, 32'he123_4567, "return to direct mode");

    // Exact supervisor mapping: low 512 MiB cacheable DMW0 plus the
    // 0xa0000000 uncached alias in DMW1.
    csr_write(14'h0180, 32'hffff_ffff, 32'h0000_0019);
    csr_write(14'h0181, 32'hffff_ffff, 32'ha000_0009);
    csr_write(14'h0000, 32'h0000_001b, 32'h0000_0010);
    vaddr = 32'h1c00_1234;
    #1;
    check32(paddr, 32'h1c00_1234, "supervisor DMW0 identity map");
    vaddr = 32'hbf00_0000;
    #1;
    check32(paddr, 32'h1f00_0000, "supervisor UART DMW1 map");

    raddr = 14'h0123;
    #1;
    check32(rdata, 32'h0000_0000, "unsupported CSR read");

    $display("PASS csr_dmw_unit_tb");
    $finish;
  end
endmodule
