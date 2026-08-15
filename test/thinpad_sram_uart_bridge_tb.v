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
  integer data_addr_ok_count;
  integer data_data_ok_count;
  integer base_active_count;
  integer ext_active_count;
  integer cycles;
  reg [31:0] read_value;
  integer base_snapshot;
  integer ext_snapshot;
  integer data_addr_snapshot;
  integer data_resp_snapshot;

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
    if (data_req && data_addr_ok)
      data_addr_ok_count = data_addr_ok_count + 1;
    if (data_data_ok)
      data_data_ok_count = data_data_ok_count + 1;
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

  task check_base_pins;
    input        wr_value;
    input [31:0] addr_value;
    input [31:0] wdata_value;
    input [3:0]  wstrb_value;
    begin
      if (base_addr !== addr_value[21:2])
        fail("BaseRAM address changed during active window");
      if (wr_value && base_wdata !== wdata_value)
        fail("BaseRAM write data changed during active window");
      if (wr_value) begin
        if (base_be_n !== ~wstrb_value)
          fail("BaseRAM byte enable changed during write window");
        if (base_we_n !== 1'b0 || base_oe_n !== 1'b1)
          fail("BaseRAM write control pins are incorrect");
      end else begin
        if (base_be_n !== 4'b0000)
          fail("BaseRAM byte enable changed during read window");
        if (base_we_n !== 1'b1 || base_oe_n !== 1'b0)
          fail("BaseRAM read control pins are incorrect");
      end
    end
  endtask

  task check_ext_pins;
    input        wr_value;
    input [31:0] addr_value;
    input [31:0] wdata_value;
    input [3:0]  wstrb_value;
    begin
      if (ext_addr !== addr_value[21:2])
        fail("ExtRAM address changed during active window");
      if (wr_value && ext_wdata !== wdata_value)
        fail("ExtRAM write data changed during active window");
      if (wr_value) begin
        if (ext_be_n !== ~wstrb_value)
          fail("ExtRAM byte enable changed during write window");
        if (ext_we_n !== 1'b0 || ext_oe_n !== 1'b1)
          fail("ExtRAM write control pins are incorrect");
      end else begin
        if (ext_be_n !== 4'b0000)
          fail("ExtRAM byte enable changed during read window");
        if (ext_we_n !== 1'b1 || ext_oe_n !== 1'b0)
          fail("ExtRAM read control pins are incorrect");
      end
    end
  endtask

  task sram_data_access;
    input        wr_value;
    input        base_target;
    input [31:0] addr_value;
    input [31:0] wdata_value;
    input [3:0]  wstrb_value;
    output [31:0] rdata_value;
    integer addr_ok_count_local;
    integer data_ok_count_local;
    integer active_count_local;
    integer cycle_count_local;
    integer expected_active_count;
    reg     request_dropped;
    reg     saw_active;
    reg [31:0] active_wdata_sample;
    begin
      @(negedge clk);
      data_req   = 1'b1;
      data_wr    = wr_value;
      data_addr  = addr_value;
      data_wdata = wdata_value;
      data_wstrb = wstrb_value;

      addr_ok_count_local = 0;
      data_ok_count_local = 0;
      active_count_local  = 0;
      cycle_count_local   = 0;
      request_dropped     = 1'b0;
      saw_active          = 1'b0;
      active_wdata_sample = 32'b0;

      begin : wait_sram_data_done
        while (1) begin
          @(posedge clk);
          cycle_count_local = cycle_count_local + 1;

          if (data_addr_ok)
            addr_ok_count_local = addr_ok_count_local + 1;
          if (data_data_ok)
            data_ok_count_local = data_ok_count_local + 1;

          if (base_target) begin
            if (!base_ce_n) begin
              active_count_local = active_count_local + 1;
              if (!saw_active) begin
                saw_active = 1'b1;
                active_wdata_sample = base_wdata;
              end else if (base_wdata !== active_wdata_sample) begin
                fail("BaseRAM write data did not stay stable");
              end
              check_base_pins(wr_value, addr_value, wdata_value, wstrb_value);
            end
            if (!ext_ce_n)
              fail("ExtRAM active during BaseRAM data access");
          end else begin
            if (!ext_ce_n) begin
              active_count_local = active_count_local + 1;
              if (!saw_active) begin
                saw_active = 1'b1;
                active_wdata_sample = ext_wdata;
              end else if (ext_wdata !== active_wdata_sample) begin
                fail("ExtRAM write data did not stay stable");
              end
              check_ext_pins(wr_value, addr_value, wdata_value, wstrb_value);
            end
            if (!base_ce_n)
              fail("BaseRAM active during ExtRAM data access");
          end

          if (data_addr_ok && !request_dropped) begin
            @(negedge clk);
            data_req = 1'b0;
            request_dropped = 1'b1;
          end

          if (data_data_ok) begin
            // A posted response may rise after the address-handshake edge
            // (during the intervening half cycle where the task drops req).
            if (data_ok_count_local == 0)
              data_ok_count_local = 1;
            rdata_value = data_rdata;
            if (cycle_count_local != (wr_value ? 1 : 4))
              fail("SRAM data response timing is incorrect");
            if (wr_value) begin
              // Posted store is acknowledged while the registered entry is
              // being drained to SRAM.  Address/data/BE have therefore been
              // stable for the complete response cycle.
              if (base_target && base_ce_n)
                fail("BaseRAM posted write was inactive during response");
              if (!base_target && ext_ce_n)
                fail("ExtRAM posted write was inactive during response");
            end else begin
              if (base_target && base_ce_n)
                fail("BaseRAM read was inactive during response");
              if (!base_target && ext_ce_n)
                fail("ExtRAM read was inactive during response");
            end
            disable wait_sram_data_done;
          end

          if (cycle_count_local > 12)
            fail("SRAM data response timeout");
        end
      end

      // The posted write becomes active immediately after its handshake edge;
      // this task samples the edge before NBA updates, then observes the write
      // at the following negedge response check above.
      expected_active_count = wr_value ? 0 : 4;
      if (addr_ok_count_local != 1)
        fail("SRAM data address handshake count is incorrect");
      if (data_ok_count_local != 1)
        fail("SRAM data response count is incorrect");
      if (active_count_local != expected_active_count)
        fail("SRAM data active cycle count is incorrect");

      @(negedge clk);
      data_wr    = 1'b0;
      data_addr  = 32'b0;
      data_wdata = 32'b0;
      data_wstrb = 4'b0;

      @(posedge clk);
      if (data_data_ok)
        fail("SRAM data response repeated");
      if (!base_ce_n || !ext_ce_n)
        fail("SRAM data access did not return idle");
    end
  endtask

  task uart_write;
    input [2:0] offset;
    input [7:0] byte_value;
    reg [3:0] strobe;
    reg [31:0] payload;
    begin
      strobe = 4'b0001 << offset[1:0];
      payload = 32'h3322_1100;
      case (offset[1:0])
        2'd0: payload[ 7: 0] = byte_value;
        2'd1: payload[15: 8] = byte_value;
        2'd2: payload[23:16] = byte_value;
        default: payload[31:24] = byte_value;
      endcase
      data_access(1'b1, 32'h1f00_0000 + offset,
                  payload, strobe, read_value);
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

  task inst_read_timed;
    input [31:0] addr_value;
    output [31:0] rdata_value;
    integer addr_ok_count_local;
    integer data_ok_count_local;
    integer active_count_local;
    integer cycle_count_local;
    reg     request_dropped;
    reg     saw_active;
    reg [31:0] active_wdata_sample;
    begin
      @(negedge clk);
      inst_req  = 1'b1;
      inst_addr = addr_value;

      addr_ok_count_local = 0;
      data_ok_count_local = 0;
      active_count_local  = 0;
      cycle_count_local   = 0;
      request_dropped     = 1'b0;
      saw_active          = 1'b0;
      active_wdata_sample = 32'b0;

      begin : wait_sram_inst_done
        while (1) begin
          @(posedge clk);
          cycle_count_local = cycle_count_local + 1;

          if (inst_addr_ok)
            addr_ok_count_local = addr_ok_count_local + 1;
          if (inst_data_ok)
            data_ok_count_local = data_ok_count_local + 1;

          if (!base_ce_n) begin
            active_count_local = active_count_local + 1;
            if (!saw_active) begin
              saw_active = 1'b1;
              active_wdata_sample = base_wdata;
            end else if (base_wdata !== active_wdata_sample) begin
              fail("BaseRAM instruction write data did not stay stable");
            end
            check_base_pins(1'b0, addr_value, 32'b0, 4'b0);
          end
          if (!ext_ce_n)
            fail("ExtRAM active during instruction access");

          if (inst_addr_ok && !request_dropped) begin
            @(negedge clk);
            inst_req = 1'b0;
            request_dropped = 1'b1;
          end

          if (inst_data_ok) begin
            rdata_value = inst_rdata;
            if (cycle_count_local != 4)
              fail("SRAM instruction response timing is incorrect");
            if (base_ce_n)
              fail("BaseRAM instruction read was inactive during response");
            disable wait_sram_inst_done;
          end

          if (cycle_count_local > 12)
            fail("SRAM instruction response timeout");
        end
      end

      if (addr_ok_count_local != 1)
        fail("SRAM instruction address handshake count is incorrect");
      if (data_ok_count_local != 1)
        fail("SRAM instruction response count is incorrect");
      if (active_count_local != 4)
        fail("SRAM instruction active cycle count is incorrect");

      @(negedge clk);
      inst_addr = 32'b0;

      @(posedge clk);
      if (inst_data_ok)
        fail("SRAM instruction response repeated");
      if (!base_ce_n || !ext_ce_n)
        fail("SRAM instruction access did not return idle");
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
    data_addr_ok_count = 0;
    data_data_ok_count = 0;
    base_active_count = 0;
    ext_active_count  = 0;

    repeat (4) @(posedge clk);
    resetn = 1'b1;

    sram_data_access(1'b0, 1'b1, 32'h1c00_0004, 32'b0, 4'b0, read_value);
    if (read_value !== 32'ha5a5_0001)
      fail("BaseRAM range or read data is incorrect");
    sram_data_access(1'b0, 1'b1, 32'h1c3f_fffc, 32'b0, 4'b0, read_value);
    if (read_value !== 32'ha5a5_ffff)
      fail("BaseRAM upper boundary is incorrect");
    sram_data_access(1'b1, 1'b1, 32'h1c00_0010,
                     32'h1122_3344, 4'b0101, read_value);

    sram_data_access(1'b0, 1'b0, 32'h1c40_0008, 32'b0, 4'b0, read_value);
    if (read_value !== 32'h5a5a_0002)
      fail("ExtRAM range or read data is incorrect");
    sram_data_access(1'b0, 1'b0, 32'h1c7f_fffc, 32'b0, 4'b0, read_value);
    if (read_value !== 32'h5a5a_ffff)
      fail("ExtRAM upper boundary is incorrect");
    sram_data_access(1'b1, 1'b0, 32'h1c40_0014,
                     32'h5566_7788, 4'b1010, read_value);

    inst_read_timed(32'h1c00_000c, read_value);
    if (read_value !== 32'ha5a5_0003)
      fail("BaseRAM instruction read is incorrect");
    inst_read_timed(32'h1c3f_fffc, read_value);
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
    data_addr_snapshot = data_addr_ok_count;
    data_resp_snapshot = data_data_ok_count;
    @(negedge clk);
    data_req   = 1'b1;
    data_wr    = 1'b1;
    data_addr  = 32'h1f00_0000;
    data_wdata = 32'hddcc_bb41;
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
        if (data_addr_ok)
          disable wait_uart_accept;
      end
    end

    // addr_ok 表示入口寄存器已经捕获请求。立即撤销并破坏上游负载，
    // 下一拍的 UART 副作用仍必须使用原始请求，且本拍不能提前响应。
    @(negedge clk);
    data_req   = 1'b0;
    data_wr    = 1'b0;
    data_addr  = 32'h1c40_1234;
    data_wdata = 32'hdeaf_beef;
    data_wstrb = 4'b1000;
    if (data_data_ok || uart_tx_start)
      fail("UART request executed in its capture cycle");

    @(posedge clk);
    #1;
    if (!data_data_ok || !uart_tx_start || uart_tx_data !== 8'h41)
      fail("UART registered execute stage lost the captured transmit request");

    @(negedge clk);
    data_addr  = 32'b0;
    data_wdata = 32'b0;
    data_wstrb = 4'b0;
    @(posedge clk);
    #1;
    if (data_data_ok || uart_tx_start)
      fail("UART response or transmit pulse repeated");
    if (tx_start_count != 1 || uart_tx_data !== 8'h41)
      fail("UART transmit pulse or byte is incorrect");
    if (data_addr_ok_count - data_addr_snapshot != 1 ||
        data_data_ok_count - data_resp_snapshot != 1)
      fail("UART request did not produce exactly one address and data handshake");

    if (base_active_count != base_snapshot || ext_active_count != ext_snapshot)
      fail("UART access aliased SRAM");

    $display("PASS thinpad_sram_uart_bridge_tb");
    $finish;
  end
endmodule
