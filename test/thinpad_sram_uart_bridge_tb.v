`timescale 1ns / 1ps

module thinpad_sram_uart_bridge_tb;
  reg         clk;
  reg         resetn;

  reg         inst_req;
  reg         inst_wr;
  reg  [1:0]  inst_size;
  reg  [3:0]  inst_wstrb;
  reg  [31:0] inst_addr;
  reg  [31:0] inst_wdata;
  wire        inst_addr_ok;
  wire        inst_data_ok;
  wire [31:0] inst_rdata;

  reg         data_req;
  reg         data_wr;
  reg  [1:0]  data_size;
  reg  [3:0]  data_wstrb;
  reg  [31:0] data_addr;
  reg  [31:0] data_wdata;
  wire        data_addr_ok;
  wire        data_data_ok;
  wire [31:0] data_rdata;

  wire [19:0] base_addr;
  wire [31:0] base_wdata;
  wire [3:0]  base_be_n;
  wire        base_ce_n;
  wire        base_oe_n;
  wire        base_we_n;
  wire [31:0] base_rdata = 32'ha5a5_0000 | {16'b0, base_addr[15:0]};

  wire [19:0] ext_addr;
  wire [31:0] ext_wdata;
  wire [3:0]  ext_be_n;
  wire        ext_ce_n;
  wire        ext_oe_n;
  wire        ext_we_n;
  wire [31:0] ext_rdata = 32'h5a5a_0000 | {16'b0, ext_addr[15:0]};

  reg         uart_rx_ready;
  reg  [7:0]  uart_rx_data;
  reg         uart_tx_busy;
  wire        uart_rx_clear;
  wire        uart_tx_start;
  wire [7:0]  uart_tx_data;

  integer tx_start_count;
  integer rx_clear_count;
  integer base_active_count;
  integer ext_active_count;
  integer cycles;
  reg [31:0] read_value;
  integer base_snapshot;
  integer ext_snapshot;

  thinpad_sram_uart_bridge dut(
    .clk(clk), .resetn(resetn),
    .inst_sram_req(inst_req), .inst_sram_wr(inst_wr),
    .inst_sram_size(inst_size), .inst_sram_wstrb(inst_wstrb),
    .inst_sram_addr(inst_addr), .inst_sram_wdata(inst_wdata),
    .inst_sram_addr_ok(inst_addr_ok), .inst_sram_data_ok(inst_data_ok),
    .inst_sram_rdata(inst_rdata),
    .data_sram_req(data_req), .data_sram_wr(data_wr),
    .data_sram_size(data_size), .data_sram_wstrb(data_wstrb),
    .data_sram_addr(data_addr), .data_sram_wdata(data_wdata),
    .data_sram_addr_ok(data_addr_ok), .data_sram_data_ok(data_data_ok),
    .data_sram_rdata(data_rdata),
    .base_ram_addr(base_addr), .base_ram_wdata(base_wdata),
    .base_ram_be_n(base_be_n), .base_ram_ce_n(base_ce_n),
    .base_ram_oe_n(base_oe_n), .base_ram_we_n(base_we_n),
    .base_ram_rdata(base_rdata),
    .ext_ram_addr(ext_addr), .ext_ram_wdata(ext_wdata),
    .ext_ram_be_n(ext_be_n), .ext_ram_ce_n(ext_ce_n),
    .ext_ram_oe_n(ext_oe_n), .ext_ram_we_n(ext_we_n),
    .ext_ram_rdata(ext_rdata),
    .uart_rx_ready(uart_rx_ready), .uart_rx_data(uart_rx_data),
    .uart_tx_busy(uart_tx_busy), .uart_rx_clear(uart_rx_clear),
    .uart_tx_start(uart_tx_start), .uart_tx_data(uart_tx_data)
  );

  always #5 clk = ~clk;

  always @(posedge clk) begin
    if (uart_tx_start)
      tx_start_count = tx_start_count + 1;
    if (uart_rx_clear)
      rx_clear_count = rx_clear_count + 1;
    if (!base_ce_n)
      base_active_count = base_active_count + 1;
    if (!ext_ce_n)
      ext_active_count = ext_active_count + 1;
  end

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s", message);
      $fatal(1, "thinpad_sram_uart_bridge_tb failed");
    end
  endtask

  task data_access;
    input        wr_value;
    input [31:0] addr_value;
    input [31:0] wdata_value;
    input [3:0]  wstrb_value;
    output [31:0] rdata_value;
    begin
      @(negedge clk);
      data_req   = 1'b1;
      data_wr    = wr_value;
      data_addr  = addr_value;
      data_wdata = wdata_value;
      data_wstrb = wstrb_value;

      cycles = 0;
      begin : wait_addr
        while (1) begin
          @(posedge clk);
          cycles = cycles + 1;
          if (data_addr_ok)
            disable wait_addr;
          if (cycles > 30)
            fail("data address handshake timeout");
        end
      end

      @(negedge clk);
      data_req = 1'b0;
      cycles = 0;
      while (!data_data_ok) begin
        @(posedge clk);
        cycles = cycles + 1;
        if (cycles > 30) begin
          $display("response timeout addr=%h wr=%b", addr_value, wr_value);
          fail("data response timeout");
        end
      end
      rdata_value = data_rdata;
      @(negedge clk);
      data_wr    = 1'b0;
      data_addr  = 32'b0;
      data_wdata = 32'b0;
      data_wstrb = 4'b0;
    end
  endtask

  task uart_write;
    input [2:0] offset;
    input [7:0] byte_value;
    reg [3:0] strobe;
    begin
      strobe = 4'b0001 << offset[1:0];
      data_access(1'b1, 32'h1f00_0000 + offset,
                  {4{byte_value}}, strobe, read_value);
    end
  endtask

  task inst_read;
    input [31:0] addr_value;
    output [31:0] rdata_value;
    begin
      @(negedge clk);
      inst_req  = 1'b1;
      inst_addr = addr_value;
      cycles = 0;
      begin : wait_inst_addr
        while (1) begin
          @(posedge clk);
          cycles = cycles + 1;
          if (inst_addr_ok)
            disable wait_inst_addr;
          if (cycles > 30)
            fail("instruction address handshake timeout");
        end
      end
      @(negedge clk);
      inst_req = 1'b0;
      cycles = 0;
      while (!inst_data_ok) begin
        @(posedge clk);
        cycles = cycles + 1;
        if (cycles > 30)
          fail("instruction response timeout");
      end
      rdata_value = inst_rdata;
      @(negedge clk);
      inst_addr = 32'b0;
    end
  endtask

  initial begin
    clk               = 1'b0;
    resetn            = 1'b0;
    inst_req          = 1'b0;
    inst_wr           = 1'b0;
    inst_size         = 2'b10;
    inst_wstrb        = 4'b0;
    inst_addr         = 32'b0;
    inst_wdata        = 32'b0;
    data_req          = 1'b0;
    data_wr           = 1'b0;
    data_size         = 2'b10;
    data_wstrb        = 4'b0;
    data_addr         = 32'b0;
    data_wdata        = 32'b0;
    uart_rx_ready     = 1'b0;
    uart_rx_data      = 8'b0;
    uart_tx_busy      = 1'b0;
    tx_start_count    = 0;
    rx_clear_count    = 0;
    base_active_count = 0;
    ext_active_count  = 0;

    repeat (4) @(posedge clk);
    resetn = 1'b1;

    data_access(1'b0, 32'h1c00_0004, 32'b0, 4'b0, read_value);
    if (read_value !== 32'ha5a5_0001)
      fail("BaseRAM range or read data is incorrect");
    data_access(1'b0, 32'h1c3f_fffc, 32'b0, 4'b0, read_value);
    if (read_value !== 32'ha5a5_ffff)
      fail("BaseRAM upper boundary is incorrect");

    data_access(1'b0, 32'h1c40_0008, 32'b0, 4'b0, read_value);
    if (read_value !== 32'h5a5a_0002)
      fail("ExtRAM range or read data is incorrect");
    data_access(1'b0, 32'h1c7f_fffc, 32'b0, 4'b0, read_value);
    if (read_value !== 32'h5a5a_ffff)
      fail("ExtRAM upper boundary is incorrect");

    inst_read(32'h1c00_000c, read_value);
    if (read_value !== 32'ha5a5_0003)
      fail("BaseRAM instruction read is incorrect");
    inst_read(32'h1c3f_fffc, read_value);
    if (read_value !== 32'ha5a5_ffff)
      fail("BaseRAM instruction upper boundary is incorrect");
    inst_read(32'h1c40_0000, read_value);
    if (read_value !== 32'b0)
      fail("unsupported instruction range must return zero");

    base_snapshot = base_active_count;
    ext_snapshot  = ext_active_count;
    data_access(1'b0, 32'h1bff_fffc, 32'b0, 4'b0, read_value);
    if (read_value !== 32'b0)
      fail("address below BaseRAM must be unmapped");
    data_access(1'b0, 32'h1c80_0000, 32'b0, 4'b0, read_value);
    if (read_value !== 32'b0)
      fail("address above ExtRAM must be unmapped");
    data_access(1'b0, 32'h1f10_0000, 32'b0, 4'b0, read_value);
    if (read_value !== 32'b0)
      fail("unmapped peripheral read must return zero");
    if (base_active_count != base_snapshot || ext_active_count != ext_snapshot)
      fail("unmapped peripheral access aliased SRAM");

    // Fixed-baud 16550-compatible initialization must not transmit divisor
    // or control bytes.
    uart_write(3'd2, 8'h07);
    uart_write(3'd3, 8'h80);
    uart_write(3'd1, 8'h00);
    uart_write(3'd0, 8'h0e);
    uart_write(3'd3, 8'h03);
    uart_write(3'd4, 8'h00);
    repeat (2) @(posedge clk);
    if (tx_start_count != 0)
      fail("UART initialization emitted spurious data");

    // The full 1 MiB UART window must decode, including its upper boundary.
    data_access(1'b0, 32'h1f0f_fffd, 32'b0, 4'b0, read_value);
    if (read_value !== 32'h0000_2000)
      fail("UART upper boundary or status lane is incorrect");

    uart_rx_ready = 1'b1;
    uart_rx_data  = 8'h5a;
    data_access(1'b0, 32'h1f00_0005, 32'b0, 4'b0, read_value);
    if (read_value !== 32'h0000_2100)
      fail("UART status bits or byte lane are incorrect");

    data_access(1'b0, 32'h1f00_0000, 32'b0, 4'b0, read_value);
    if (read_value !== 32'h0000_005a)
      fail("UART receive data is incorrect");
    @(posedge clk);
    #1;
    if (rx_clear_count != 1)
      fail("UART data read did not clear RX ready exactly once");

    // A real THR write is back-pressured while the transmitter is busy.
    uart_rx_ready = 1'b0;
    uart_tx_busy  = 1'b1;
    @(negedge clk);
    data_req   = 1'b1;
    data_wr    = 1'b1;
    data_addr  = 32'h1f00_0000;
    data_wdata = 32'h4141_4141;
    data_wstrb = 4'b0001;
    repeat (3) begin
      @(posedge clk);
      #1;
      if (data_addr_ok)
        fail("UART accepted transmit data while busy");
    end
    @(negedge clk);
    uart_tx_busy = 1'b0;
    begin : wait_uart_accept
      while (1) begin
        @(posedge clk);
        #1;
        if (data_addr_ok)
          disable wait_uart_accept;
      end
    end
    @(negedge clk);
    data_req = 1'b0;
    while (!data_data_ok) begin
      @(posedge clk);
      #1;
    end
    @(negedge clk);
    data_wr    = 1'b0;
    data_addr  = 32'b0;
    data_wdata = 32'b0;
    data_wstrb = 4'b0;
    @(posedge clk);
    #1;
    if (tx_start_count != 1 || uart_tx_data !== 8'h41)
      fail("UART transmit pulse or byte is incorrect");

    if (base_active_count != base_snapshot || ext_active_count != ext_snapshot)
      fail("UART access aliased SRAM");

    $display("PASS thinpad_sram_uart_bridge_tb");
    $finish;
  end
endmodule
