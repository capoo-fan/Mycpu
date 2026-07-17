`timescale 1ns / 1ps

module supervisor_perf_tb;
  localparam integer BOOT_LEN = 38;
  localparam integer STREAM_WORDS = 32'h0030_0000 / 4;
  localparam integer MATRIX_WORDS = 128 * 128;
  localparam integer CRYPTO_WORDS = 32'h0020_0000 / 4;
  localparam integer MIXED_SIG_WORD = 32'h0012_0000 / 4;

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
  reg [31:0] ref_mem  [0:524287];
  wire [31:0] base_rdata = base_mem[base_addr];
  wire [31:0] ext_rdata  = ext_mem[ext_addr];

  reg [7:0] tx_bytes [0:255];
  integer tx_count;
  integer cycles;
  integer i;
  integer test_id;
  integer base_words;
  integer ext_words;
  integer ref_words;
  reg [31:0] entry_addr;
  reg [63:0] cycle_count;
  reg [63:0] max_cycles;
  reg [1023:0] base_file;
  reg [1023:0] ext_file;
  reg [1023:0] ref_file;

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
    .debug_wb_pc(), .debug_wb_rf_we(),
    .debug_wb_rf_wnum(), .debug_wb_rf_wdata()
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
    cycle_count <= cycle_count + 1;
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
    if (cycle_count > max_cycles) begin
      $display("FAIL supervisor performance timeout: test=%0d cycles=%0d", test_id, cycle_count);
      $fatal(1);
    end
  end

  task wait_tx_count;
    input integer wanted;
    begin
      cycles = 0;
      while (tx_count < wanted) begin
        @(posedge clk);
        cycles = cycles + 1;
        if (wanted <= BOOT_LEN && cycles > 300000) begin
          $display("UART wait timeout: wanted=%0d got=%0d pc=%h if_suspend=%b",
                   wanted, tx_count, cpu.pc_out, cpu.if_suspend);
          $fatal(1, "UART wait timeout");
        end
      end
    end
  endtask

  task send_rx_byte;
    input [7:0] byte_value;
    begin
      @(negedge clk);
      uart_rx_data  = byte_value;
      uart_rx_ready = 1'b1;
      while (!uart_rx_clear) @(posedge clk);
      @(negedge clk);
      uart_rx_ready = 1'b0;
      while (uart_rx_clear) @(posedge clk);
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

  task compare_results;
    integer mismatch;
    integer word_count;
    integer actual_base;
    integer expected_base;
    begin
      mismatch = 0;
      case (test_id)
        1: begin
          word_count = STREAM_WORDS;
          actual_base = 0;
          expected_base = 32'h0010_0000 / 4;
          for (i = 0; i < word_count; i = i + 1)
            if (ext_mem[actual_base + i] !== base_mem[expected_base + i]) begin
              if (mismatch < 8)
                $display("STREAM mismatch word=%0d actual=%h expected=%h",
                         i, ext_mem[actual_base + i], base_mem[expected_base + i]);
              mismatch = mismatch + 1;
            end
        end
        2: begin
          word_count = MATRIX_WORDS;
          actual_base = 32'h0002_0000 / 4;
          expected_base = 32'h0003_0000 / 4;
          for (i = 0; i < word_count; i = i + 1)
            if (ext_mem[actual_base + i] !== ext_mem[expected_base + i]) begin
              if (mismatch < 8)
                $display("MATRIX mismatch word=%0d actual=%h expected=%h",
                         i, ext_mem[actual_base + i], ext_mem[expected_base + i]);
              mismatch = mismatch + 1;
            end
        end
        3: begin
          word_count = CRYPTO_WORDS;
          for (i = 0; i < word_count; i = i + 1)
            if (ext_mem[i] !== ref_mem[i]) begin
              if (mismatch < 8)
                $display("CRYPTONIGHT mismatch word=%0d actual=%h expected=%h",
                         i, ext_mem[i], ref_mem[i]);
              mismatch = mismatch + 1;
            end
        end
        4: begin
          word_count = 5;
          for (i = 0; i < word_count; i = i + 1)
            if (ext_mem[MIXED_SIG_WORD + i] !== ref_mem[i]) begin
              if (mismatch < 8)
                $display("MIXED mismatch word=%0d actual=%h expected=%h",
                         i, ext_mem[MIXED_SIG_WORD + i], ref_mem[i]);
              mismatch = mismatch + 1;
            end
        end
        default: $fatal(1, "invalid TEST_ID");
      endcase

      if (mismatch != 0)
        $fatal(1, "supervisor result mismatch count=%0d", mismatch);
      $display("PASS supervisor performance test=%0d cycles=%0d", test_id, cycle_count);
    end
  endtask

  initial begin
    if (!$value$plusargs("TEST_ID=%d", test_id) ||
        !$value$plusargs("ENTRY_ADDR=%h", entry_addr) ||
        !$value$plusargs("BASE_MIF=%s", base_file) ||
        !$value$plusargs("BASE_WORDS=%d", base_words))
      $fatal(1, "missing required plusarg");
    if (!$value$plusargs("MAX_CYCLES=%d", max_cycles))
      max_cycles = 64'd300000000;

    if ($value$plusargs("EXT_MIF=%s", ext_file) &&
        $value$plusargs("EXT_WORDS=%d", ext_words))
      $readmemb(ext_file, ext_mem, 0, ext_words - 1);
    if ($value$plusargs("REF_MIF=%s", ref_file) &&
        $value$plusargs("REF_WORDS=%d", ref_words))
      $readmemb(ref_file, ref_mem, 0, ref_words - 1);
    $readmemb(base_file, base_mem, 0, base_words - 1);

    clk           = 1'b0;
    resetn        = 1'b0;
    uart_rx_ready = 1'b0;
    uart_rx_data  = 8'b0;
    tx_count      = 0;
    cycle_count   = 0;

    repeat (8) @(posedge clk);
    resetn = 1'b1;
    wait_tx_count(BOOT_LEN);

    send_rx_byte(8'h47);
    send_word_le(entry_addr);
    wait_tx_count(BOOT_LEN + 2);
    if (tx_bytes[BOOT_LEN] !== 8'h06 || tx_bytes[BOOT_LEN + 1] !== 8'h07)
      $fatal(1, "G command markers are invalid");

    compare_results();
    $finish;
  end
endmodule

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
