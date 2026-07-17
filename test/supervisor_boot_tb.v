`timescale 1ns / 1ps

module supervisor_boot_tb;
  localparam integer BOOT_LEN = 38;
  localparam [BOOT_LEN*8-1:0] BOOT_MESSAGE =
      "MONITOR for Loongarch32 - initialized.";
  localparam [31:0] USER_ADDR = 32'h1c00_3000;

  reg clk;
  reg resetn;

  wire        inst_req;
  wire        inst_wr;
  wire [1:0]  inst_size;
  wire [3:0]  inst_wstrb;
  wire [31:0] inst_addr;
  wire [31:0] inst_wdata;
  wire        inst_addr_ok;
  wire        inst_data_ok;
  wire [31:0] inst_rdata;

  wire        data_req;
  wire        data_wr;
  wire [1:0]  data_size;
  wire [3:0]  data_wstrb;
  wire [31:0] data_addr;
  wire [31:0] data_wdata;
  wire        data_addr_ok;
  wire        data_data_ok;
  wire [31:0] data_rdata;

  wire [31:0] debug_pc;
  wire [3:0]  debug_we;
  wire [4:0]  debug_wnum;
  wire [31:0] debug_wdata;

  wire [19:0] base_addr;
  wire [31:0] base_wdata;
  wire [3:0]  base_be_n;
  wire        base_ce_n;
  wire        base_oe_n;
  wire        base_we_n;
  wire [19:0] ext_addr;
  wire [31:0] ext_wdata;
  wire [3:0]  ext_be_n;
  wire        ext_ce_n;
  wire        ext_oe_n;
  wire        ext_we_n;

  reg         uart_rx_ready;
  reg  [7:0]  uart_rx_data;
  wire        uart_rx_clear;
  wire        uart_tx_start;
  wire [7:0]  uart_tx_data;

  reg [31:0] base_mem [0:1048575];
  reg [31:0] ext_mem  [0:1048575];
  wire [31:0] base_rdata = base_mem[base_addr];
  wire [31:0] ext_rdata  = ext_mem[ext_addr];

  reg [7:0] tx_bytes [0:511];
  integer tx_count;
  integer cycle_count;
  integer cycles;
  integer i;
  integer tx_base;

  mycpu_top cpu(
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
    .debug_wb_pc(debug_pc), .debug_wb_rf_we(debug_we),
    .debug_wb_rf_wnum(debug_wnum), .debug_wb_rf_wdata(debug_wdata)
  );

  thinpad_sram_uart_bridge bridge(
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
    .uart_tx_busy(1'b0), .uart_rx_clear(uart_rx_clear),
    .uart_tx_start(uart_tx_start), .uart_tx_data(uart_tx_data)
  );

  always #5 clk = ~clk;

  always @(posedge clk) begin
    cycle_count = cycle_count + 1;
    if (!base_we_n) begin
      if (!base_be_n[0]) base_mem[base_addr][ 7: 0] <= base_wdata[ 7: 0];
      if (!base_be_n[1]) base_mem[base_addr][15: 8] <= base_wdata[15: 8];
      if (!base_be_n[2]) base_mem[base_addr][23:16] <= base_wdata[23:16];
      if (!base_be_n[3]) base_mem[base_addr][31:24] <= base_wdata[31:24];
    end
    if (!ext_we_n) begin
      if (!ext_be_n[0]) ext_mem[ext_addr][ 7: 0] <= ext_wdata[ 7: 0];
      if (!ext_be_n[1]) ext_mem[ext_addr][15: 8] <= ext_wdata[15: 8];
      if (!ext_be_n[2]) ext_mem[ext_addr][23:16] <= ext_wdata[23:16];
      if (!ext_be_n[3]) ext_mem[ext_addr][31:24] <= ext_wdata[31:24];
    end
    if (uart_tx_start) begin
      tx_bytes[tx_count] = uart_tx_data;
      tx_count = tx_count + 1;
    end
    if (cycle_count > 2000000) begin
      $display("FAIL: global timeout pc=%h tx_count=%0d", debug_pc, tx_count);
      $fatal(1, "supervisor_boot_tb timeout");
    end
  end

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s pc=%h cycle=%0d", message, debug_pc, cycle_count);
      $fatal(1, "supervisor_boot_tb failed");
    end
  endtask

  task wait_tx_count;
    input integer wanted;
    begin
      cycles = 0;
      while (tx_count < wanted) begin
        @(posedge clk);
        #1;
        cycles = cycles + 1;
        if (cycles > 300000)
          fail("UART transmit wait timeout");
      end
    end
  endtask

  task send_rx_byte;
    input [7:0] byte_value;
    begin
      @(negedge clk);
      uart_rx_data  = byte_value;
      uart_rx_ready = 1'b1;
      cycles = 0;
      while (!uart_rx_clear) begin
        @(posedge clk);
        #1;
        cycles = cycles + 1;
        if (cycles > 30000)
          fail("supervisor did not consume UART byte");
      end
      @(negedge clk);
      uart_rx_ready = 1'b0;
      while (uart_rx_clear) begin
        @(posedge clk);
        #1;
      end
    end
  endtask

  task send_word_le;
    input [31:0] word_value;
    begin
      send_rx_byte(word_value[ 7: 0]);
      send_rx_byte(word_value[15: 8]);
      send_rx_byte(word_value[23:16]);
      send_rx_byte(word_value[31:24]);
    end
  endtask

  task command_a;
    input [31:0] first_inst;
    begin
      send_rx_byte(8'h41);
      send_word_le(USER_ADDR);
      send_word_le(32'd8);
      send_word_le(first_inst);
      send_word_le(32'h4c00_0020);
    end
  endtask

  task command_g;
    begin
      tx_base = tx_count;
      send_rx_byte(8'h47);
      send_word_le(USER_ADDR);
      wait_tx_count(tx_base + 2);
      if (tx_bytes[tx_base] !== 8'h06 || tx_bytes[tx_base + 1] !== 8'h07)
        fail("G command did not emit 0x06/0x07 markers");
    end
  endtask

  task command_r_check_a0;
    input [7:0] expected_a0;
    begin
      tx_base = tx_count;
      send_rx_byte(8'h52);
      wait_tx_count(tx_base + 124);
      if (tx_bytes[tx_base + 12] !== expected_a0 ||
          tx_bytes[tx_base + 13] !== 8'h00 ||
          tx_bytes[tx_base + 14] !== 8'h00 ||
          tx_bytes[tx_base + 15] !== 8'h00)
        fail("R command returned an unexpected saved a0 value");
    end
  endtask

  initial begin
    $readmemb("supervisor/kernel/axi_ram.mif", base_mem, 0, 2264);
    clk           = 1'b0;
    resetn        = 1'b0;
    uart_rx_ready = 1'b0;
    uart_rx_data  = 8'b0;
    tx_count      = 0;
    cycle_count   = 0;

    repeat (8) @(posedge clk);
    resetn = 1'b1;

    wait_tx_count(BOOT_LEN);
    for (i = 0; i < BOOT_LEN; i = i + 1) begin
      if (tx_bytes[i] !== BOOT_MESSAGE[(BOOT_LEN-i)*8-1 -: 8]) begin
        $display("boot mismatch index=%0d actual=%h expected=%h",
                 i, tx_bytes[i], BOOT_MESSAGE[(BOOT_LEN-i)*8-1 -: 8]);
        fail("boot banner mismatch or spurious UART initialization byte");
      end
    end

    // Load, read back and execute a small program in BaseRAM.
    command_a(32'h0280_0484); // addi.w a0,a0,1
    tx_base = tx_count;
    send_rx_byte(8'h44);
    send_word_le(USER_ADDR);
    send_word_le(32'd8);
    wait_tx_count(tx_base + 8);
    if (tx_bytes[tx_base + 0] !== 8'h84 ||
        tx_bytes[tx_base + 1] !== 8'h04 ||
        tx_bytes[tx_base + 2] !== 8'h80 ||
        tx_bytes[tx_base + 3] !== 8'h02 ||
        tx_bytes[tx_base + 4] !== 8'h20 ||
        tx_bytes[tx_base + 5] !== 8'h00 ||
        tx_bytes[tx_base + 6] !== 8'h00 ||
        tx_bytes[tx_base + 7] !== 8'h4c)
      fail("A/D command data mismatch");

    command_g();
    command_r_check_a0(8'h01);

    // Rewrite an already cached instruction line.  The next G must observe
    // the new addi immediate rather than the old I-cache contents.
    command_a(32'h0280_0884); // addi.w a0,a0,2
    command_g();
    command_r_check_a0(8'h03);

    $display("PASS supervisor_boot_tb cycles=%0d", cycle_count);
    $finish;
  end
endmodule

// Three-cycle simulation stand-in for the Xilinx multiplier IP.  The boot and
// command-flow checks do not execute mul.w, but defining the model keeps this
// integration test self-contained.
module mult_gen_0(
  input  wire        CLK,
  input  wire [31:0] A,
  input  wire [31:0] B,
  output wire [63:0] P
);
  reg signed [63:0] pipe0;
  reg signed [63:0] pipe1;
  reg signed [63:0] pipe2;
  always @(posedge CLK) begin
    pipe0 <= $signed(A) * $signed(B);
    pipe1 <= pipe0;
    pipe2 <= pipe1;
  end
  assign P = pipe2;
endmodule
