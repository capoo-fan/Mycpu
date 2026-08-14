`timescale 1ns / 1ps

module dmem_prefetch_tb;
  reg clk;
  reg resetn;
  reg invalidate_all;
  reg cpu_req;
  reg cpu_wr;
  reg [1:0] cpu_size;
  reg [3:0] cpu_wstrb;
  reg [31:0] cpu_addr;
  reg [31:0] cpu_wdata;
  reg [31:0] cpu_pc;
  reg        cpu_lookup_valid;
  reg [31:0] cpu_lookup_addr;

  wire cpu_addr_ok;
  wire cpu_data_ok;
  wire [31:0] cpu_rdata;
  wire cpu_fast_ready;
  wire cpu_fast_data_ok;
  wire [31:0] cpu_fast_rdata;
  wire cpu_store_ready;
  wire mem_req;
  wire mem_wr;
  wire [1:0] mem_size;
  wire [3:0] mem_wstrb;
  wire [31:0] mem_addr;
  wire [31:0] mem_wdata;
  wire mem_store_is_ext;
  wire mem_addr_ok;
  reg mem_data_ok;
  reg [31:0] mem_rdata;
  reg mem_fast_ready;
  reg mem_fast_data_ok;
  reg [31:0] mem_fast_rdata;

  reg lower_pending;
  reg [1:0] lower_delay;
  reg [31:0] lower_addr;
  integer index;

  assign mem_addr_ok = mem_req && !lower_pending;

  dmem_prefetch dut(
    .clk(clk), .resetn(resetn), .invalidate_all(invalidate_all),
    .lookup_cancel(1'b0),
    .cpu_req(cpu_req), .cpu_wr(cpu_wr), .cpu_size(cpu_size),
    .cpu_wstrb(cpu_wstrb), .cpu_addr(cpu_addr), .cpu_wdata(cpu_wdata),
    .cpu_pc(cpu_pc), .cpu_store_is_ext(cpu_addr[22]),
    .cpu_lookup_valid(cpu_lookup_valid),
    .cpu_lookup_addr(cpu_lookup_addr),
    .cpu_addr_ok(cpu_addr_ok), .cpu_data_ok(cpu_data_ok),
    .cpu_rdata(cpu_rdata), .cpu_fast_ready(cpu_fast_ready),
    .cpu_fast_data_ok(cpu_fast_data_ok),
    .cpu_fast_rdata(cpu_fast_rdata), .cpu_store_ready(cpu_store_ready),
    .mem_req(mem_req), .mem_wr(mem_wr), .mem_size(mem_size),
    .mem_wstrb(mem_wstrb), .mem_addr(mem_addr), .mem_wdata(mem_wdata),
    .mem_store_is_ext(mem_store_is_ext), .mem_addr_ok(mem_addr_ok),
    .mem_data_ok(mem_data_ok), .mem_rdata(mem_rdata),
    .mem_fast_ready(mem_fast_ready),
    .mem_fast_data_ok(mem_fast_data_ok),
    .mem_fast_rdata(mem_fast_rdata), .mem_store_ready(1'b1)
  );

  always #5 clk = ~clk;

  function [31:0] memory_value;
    input [31:0] address;
    begin
      memory_value = address ^ 32'h5a5a_a5a5;
    end
  endfunction

  always @(posedge clk)
  begin
    mem_data_ok <= 1'b0;
    mem_fast_ready <= 1'b0;
    mem_fast_data_ok <= 1'b0;
    if (!resetn)
    begin
      lower_pending <= 1'b0;
      lower_delay <= 2'b0;
      lower_addr <= 32'b0;
      mem_rdata <= 32'b0;
      mem_fast_rdata <= 32'b0;
    end
    else if (mem_addr_ok)
    begin
      lower_pending <= 1'b1;
      lower_delay <= 2'd1;
      lower_addr <= mem_addr;
    end
    else if (lower_pending && (lower_delay != 2'b0))
      lower_delay <= lower_delay - 2'd1;
    else if (lower_pending)
    begin
      lower_pending <= 1'b0;
      mem_data_ok <= 1'b1;
      mem_fast_ready <= 1'b1;
      mem_fast_data_ok <= 1'b1;
      mem_rdata <= memory_value(lower_addr);
      mem_fast_rdata <= memory_value(lower_addr);
    end
  end

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "dmem_prefetch_tb failed");
    end
  endtask

  task reset_dut;
    begin
      @(negedge clk);
      resetn = 1'b0;
      invalidate_all = 1'b0;
      cpu_req = 1'b0;
      cpu_wr = 1'b0;
      cpu_lookup_valid = 1'b0;
      repeat (4) @(posedge clk);
      @(negedge clk);
      resetn = 1'b1;
      repeat (2) @(posedge clk);
    end
  endtask

  task issue_load;
    input [31:0] address;
    input [31:0] pc;
    integer timeout;
    begin
      @(negedge clk);
      cpu_lookup_valid = 1'b1;
      cpu_lookup_addr = address;
      @(posedge clk);
      @(negedge clk);
      cpu_lookup_valid = 1'b0;
      cpu_req = 1'b1;
      cpu_wr = 1'b0;
      cpu_addr = address;
      cpu_pc = pc;
      timeout = 0;
      #1;
      while (!cpu_addr_ok)
      begin
        @(negedge clk);
        timeout = timeout + 1;
        if (timeout > 30)
          fail("load address handshake timed out");
      end
      @(posedge clk);
      @(negedge clk);
      cpu_req = 1'b0;
      timeout = 0;
      while (!cpu_data_ok)
      begin
        @(negedge clk);
        timeout = timeout + 1;
        if (timeout > 30)
          fail("load response timed out");
      end
      if (cpu_fast_rdata !== memory_value(address))
        fail("load returned incorrect prefetched data");
      @(posedge clk);
      @(posedge clk);
    end
  endtask

  initial begin
    clk = 1'b0;
    resetn = 1'b0;
    invalidate_all = 1'b0;
    cpu_req = 1'b0;
    cpu_wr = 1'b0;
    cpu_size = 2'b10;
    cpu_wstrb = 4'b0;
    cpu_addr = 32'b0;
    cpu_wdata = 32'b0;
    cpu_pc = 32'b0;
    cpu_lookup_valid = 1'b0;
    cpu_lookup_addr = 32'b0;
    mem_data_ok = 1'b0;
    mem_rdata = 32'b0;
    mem_fast_ready = 1'b0;
    mem_fast_data_ok = 1'b0;
    mem_fast_rdata = 32'b0;
    lower_pending = 1'b0;
    lower_delay = 2'b0;
    lower_addr = 32'b0;

    reset_dut();
    for (index = 0; index < 20; index = index + 1)
      issue_load(32'h1c10_0000 + index * 4, 32'h1c00_2018);
    if (dut.pf_issue_count == 0)
      fail("sequential stream did not issue prefetches");
    if (dut.pf_hit_count == 0)
      fail("sequential stream produced no useful prefetch hit");

    reset_dut();
    issue_load(32'h1c40_0000, 32'h1c00_213c);
    issue_load(32'h1c41_1020, 32'h1c00_213c);
    issue_load(32'h1c47_0040, 32'h1c00_213c);
    issue_load(32'h1c42_2000, 32'h1c00_213c);
    issue_load(32'h1c46_0010, 32'h1c00_213c);
    issue_load(32'h1c40_8000, 32'h1c00_213c);
    if (dut.pf_issue_count != 0)
      fail("irregular stream incorrectly enabled prefetching");

    reset_dut();
    for (index = 0; index < 8; index = index + 1)
      issue_load(32'h1f00_0000 + index * 4, 32'h1c00_3000);
    if (dut.pf_issue_count != 0)
      fail("MMIO accesses trained or issued a prefetch");

    $display("PASS dmem_prefetch_tb issued=%0d hit=%0d late=%0d",
             dut.pf_issue_count, dut.pf_hit_count, dut.pf_late_count);
    $finish;
  end
endmodule
