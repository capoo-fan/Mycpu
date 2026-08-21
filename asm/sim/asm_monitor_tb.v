`timescale 1ns / 1ps

// Monitor-driven LA32R assembly testbench for the serialized accelerator CPU.
// Performance counters observe the local PC/state only; no debug path is added
// to the CPU RTL.
module asm_monitor_tb;
  localparam integer BOOT_LEN = 38;
  localparam integer BASE_DEPTH = 1048576;
  localparam integer EXT_DEPTH = 1048576;
  localparam integer PROGRAM_DEPTH = 1048576;
  localparam integer WRITE_LOG_LIMIT = 8;
  localparam [3:0] CPU_ST_EX = 4'd2;
  localparam [BOOT_LEN*8-1:0] BOOT_MESSAGE =
      "MONITOR for Loongarch32 - initialized.";

  reg clk;
  reg resetn;
  wire inst_req, inst_wr;
  wire [1:0] inst_size;
  wire [3:0] inst_wstrb;
  wire [31:0] inst_addr, inst_wdata;
  wire inst_addr_ok, inst_data_ok;
  wire [31:0] inst_rdata;
  wire data_req, data_wr;
  wire [1:0] data_size;
  wire [3:0] data_wstrb;
  wire [31:0] data_addr, data_wdata;
  wire data_addr_ok, data_data_ok;
  wire [31:0] data_rdata;

  wire [19:0] base_addr, ext_addr;
  wire [31:0] base_wdata, ext_wdata;
  wire [3:0] base_be_n, ext_be_n;
  wire base_ce_n, base_oe_n, base_we_n;
  wire ext_ce_n, ext_oe_n, ext_we_n;
  reg uart_rx_ready;
  reg [7:0] uart_rx_data;
  wire uart_rx_clear, uart_tx_start;
  wire [7:0] uart_tx_data;

  reg [31:0] base_mem [0:BASE_DEPTH-1];
  reg [31:0] ext_mem [0:EXT_DEPTH-1];
  wire [31:0] base_rdata = base_mem[base_addr];
  wire [31:0] ext_rdata = ext_mem[ext_addr];

  // Reused for program upload and, after upload, optional expected data.
  reg [31:0] program_mem [0:PROGRAM_DEPTH-1];
  reg [7:0] tx_bytes [0:2047];
  integer tx_count, i;
  integer base_words, program_words, watch_words, watch_words_2;
  integer data_words, expect_words;
  integer write_log_count;
  integer init_fd, init_status, init_line_status;
  reg [31:0] entry_addr, program_addr, watch_addr, watch_addr_2;
  reg [31:0] data_load_addr, expect_addr, expect_value;
  reg [31:0] init_addr, init_value;
  reg [1023:0] base_file, program_file, data_file;
  reg [1023:0] expect_file, init_file, init_line, wave_file;
  reg data_enabled, expect_file_enabled, expect_value_enabled;
  reg [63:0] cycle_count, max_cycles;
  reg [63:0] wait_cycles;
  reg command_counting, command_done;
  reg user_counting, user_done;
  reg [63:0] command_cycles, command_instr;
  reg [63:0] user_cycles, user_instr, write_count;
  reg [31:0] write_addr_log [0:WRITE_LOG_LIMIT-1];
  reg [31:0] write_data_log [0:WRITE_LOG_LIMIT-1];

  function address_is_valid;
    input [31:0] addr;
    begin
      address_is_valid = ((addr[31:24] == 8'h80) ||
                          (addr[31:24] == 8'h1c)) && !addr[23];
    end
  endfunction

  function address_is_ext;
    input [31:0] addr;
    begin
      address_is_ext = addr[22];
    end
  endfunction

  function [31:0] memory_word;
    input [31:0] addr;
    begin
      memory_word = address_is_ext(addr) ? ext_mem[addr[21:2]] :
                                           base_mem[addr[21:2]];
    end
  endfunction

  function pc_is_user;
    input [31:0] pc;
    begin
      pc_is_user = (pc >= program_addr) &&
                   (pc < program_addr + program_words * 4);
    end
  endfunction

  // The reduced core has exactly one instruction in flight. ST_EX is reached
  // once per instruction, so it is the single architectural instruction event
  // for cycle/IPC accounting. With no speculation, a PC outside the uploaded
  // image after an EX event means the user program has returned to the monitor.
  wire cpu_exec_valid = (cpu.state == CPU_ST_EX);
  wire user_exec_valid = cpu_exec_valid && pc_is_user(cpu.pc_out);

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
    .debug_wb_pc(), .debug_wb_rf_we(), .debug_wb_rf_wnum(),
    .debug_wb_rf_wdata());

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
    .uart_tx_start(uart_tx_start), .uart_tx_data(uart_tx_data));

  always #5 clk = ~clk;

  always @(posedge clk) begin
    cycle_count <= cycle_count + 1;

    if (command_counting) begin
      command_cycles <= command_cycles + 1;
      command_instr <= command_instr + {63'b0, cpu_exec_valid};
      if (uart_tx_start && uart_tx_data == 8'h07) begin
        command_counting <= 1'b0;
        command_done <= 1'b1;
      end
    end

    if (user_counting) begin
      user_cycles <= user_cycles + 1;
      user_instr <= user_instr + {63'b0, user_exec_valid};
      if (!pc_is_user(cpu.pc_out)) begin
        user_counting <= 1'b0;
        user_done <= 1'b1;
      end
    end

    if (!base_we_n) begin
      if (!base_be_n[0]) base_mem[base_addr][7:0] <= base_wdata[7:0];
      if (!base_be_n[1]) base_mem[base_addr][15:8] <= base_wdata[15:8];
      if (!base_be_n[2]) base_mem[base_addr][23:16] <= base_wdata[23:16];
      if (!base_be_n[3]) base_mem[base_addr][31:24] <= base_wdata[31:24];
      if (user_counting) begin
        write_count <= write_count + 1;
        if (write_log_count < WRITE_LOG_LIMIT) begin
          write_addr_log[write_log_count] <= 32'h1c000000 +
                                             {10'b0, base_addr, 2'b0};
          write_data_log[write_log_count] <= base_wdata;
          write_log_count <= write_log_count + 1;
        end
      end
    end
    if (!ext_we_n) begin
      if (!ext_be_n[0]) ext_mem[ext_addr][7:0] <= ext_wdata[7:0];
      if (!ext_be_n[1]) ext_mem[ext_addr][15:8] <= ext_wdata[15:8];
      if (!ext_be_n[2]) ext_mem[ext_addr][23:16] <= ext_wdata[23:16];
      if (!ext_be_n[3]) ext_mem[ext_addr][31:24] <= ext_wdata[31:24];
      if (user_counting) begin
        write_count <= write_count + 1;
        if (write_log_count < WRITE_LOG_LIMIT) begin
          write_addr_log[write_log_count] <= 32'h1c400000 +
                                             {10'b0, ext_addr, 2'b0};
          write_data_log[write_log_count] <= ext_wdata;
          write_log_count <= write_log_count + 1;
        end
      end
    end
    if (uart_tx_start) begin
      if (tx_count >= 2048) $fatal(1, "UART transmit log overflow");
      tx_bytes[tx_count] = uart_tx_data;
      tx_count = tx_count + 1;
    end
    if (cycle_count > max_cycles)
      $fatal(1, "asm monitor timeout pc=%h state=%0d inst=%h cycles=%0d",
             cpu.pc_out, cpu.state, cpu.inst, cycle_count);
  end

  task fail;
    input [511:0] message;
    begin
      $display("FAIL: %0s pc=%h cycle=%0d", message, cpu.pc_out, cycle_count);
      $fatal(1, "asm monitor test failed");
    end
  endtask

  task validate_region;
    input [31:0] addr;
    input integer words;
    begin
      if (!address_is_valid(addr) || addr[1:0] != 2'b0)
        fail("memory region address is invalid or unaligned");
      if (words <= 0 || words > (BASE_DEPTH - {12'b0, addr[21:2]}))
        fail("memory region exceeds one SRAM bank");
    end
  endtask

  task send_rx_byte;
    input [7:0] value;
    begin
      @(negedge clk);
      uart_rx_data = value;
      uart_rx_ready = 1'b1;
      wait_cycles = 0;
      while (!uart_rx_clear) begin
        @(posedge clk);
        wait_cycles = wait_cycles + 1;
        if (wait_cycles > 30000) fail("UART receive timeout");
      end
      @(negedge clk);
      uart_rx_ready = 1'b0;
      while (uart_rx_clear) @(posedge clk);
    end
  endtask

  task send_g_byte;
    begin
      // The first following rising edge is cycle 1 of the requested G interval.
      @(negedge clk);
      command_counting = 1'b1;
      uart_rx_data = 8'h47;
      uart_rx_ready = 1'b1;
      wait_cycles = 0;
      while (!uart_rx_clear) begin
        @(posedge clk);
        wait_cycles = wait_cycles + 1;
        if (wait_cycles > 30000) fail("UART receive timeout");
      end
      @(negedge clk);
      uart_rx_ready = 1'b0;
      while (uart_rx_clear) @(posedge clk);
    end
  endtask

  task send_word_le;
    input [31:0] value;
    begin
      send_rx_byte(value[7:0]);
      send_rx_byte(value[15:8]);
      send_rx_byte(value[23:16]);
      send_rx_byte(value[31:24]);
    end
  endtask

  task wait_tx;
    input integer wanted;
    begin
      wait_cycles = 0;
      while (tx_count < wanted) begin
        @(posedge clk);
        wait_cycles = wait_cycles + 1;
        if (wait_cycles > max_cycles) fail("UART transmit timeout");
      end
    end
  endtask

  task load_program;
    integer n;
    begin
      send_rx_byte(8'h41); // A: monitor memory-write command
      send_word_le(program_addr);
      send_word_le(program_words * 4);
      for (n = 0; n < program_words; n = n + 1)
        send_word_le(program_mem[n]);
    end
  endtask

  task load_sparse_init;
    begin
      init_fd = $fopen(init_file, "r");
      if (init_fd == 0) fail("cannot open INIT_FILE");
      while (!$feof(init_fd)) begin
        init_line = 0;
        init_line_status = $fgets(init_line, init_fd);
        init_status = $sscanf(init_line, "%h %h", init_addr, init_value);
        if (init_status == 2) begin
          validate_region(init_addr, 1);
          if (address_is_ext(init_addr))
            ext_mem[init_addr[21:2]] = init_value;
          else
            base_mem[init_addr[21:2]] = init_value;
        end
      end
      $fclose(init_fd);
    end
  endtask

  task compare_results;
    integer n;
    integer mismatch_count;
    reg [31:0] addr;
    reg [31:0] actual;
    begin
      mismatch_count = 0;
      if (expect_file_enabled) begin
        validate_region(expect_addr, expect_words);
        $readmemb(expect_file, program_mem, 0, expect_words - 1);
        for (n = 0; n < expect_words; n = n + 1) begin
          addr = expect_addr + n * 4;
          actual = memory_word(addr);
          if (actual !== program_mem[n]) begin
            if (mismatch_count < 16)
              $display("MISMATCH addr=%h expected=%h actual=%h",
                       addr, program_mem[n], actual);
            mismatch_count = mismatch_count + 1;
          end
        end
        if (mismatch_count != 0) begin
          $display("FAIL: result mismatches=%0d", mismatch_count);
          $fatal(1, "expected memory comparison failed");
        end
        $display("CHECK memory PASS addr=%h words=%0d",
                 expect_addr, expect_words);
      end
      if (expect_value_enabled) begin
        validate_region(expect_addr, 1);
        actual = memory_word(expect_addr);
        if (actual !== expect_value) begin
          $display("MISMATCH addr=%h expected=%h actual=%h",
                   expect_addr, expect_value, actual);
          $fatal(1, "expected word comparison failed");
        end
        $display("CHECK word PASS addr=%h value=%h", expect_addr, actual);
      end
    end
  endtask

  task print_report;
    integer n;
    reg [31:0] addr;
    begin
      $display("RESULT entry=%h program_bytes=%0d", entry_addr,
               program_words * 4);
      if ($test$plusargs("TOTAL_PERF_TABLE")) begin
        $display("+----------+--------------+--------------+----------+----------+");
        $display("| SCOPE    | CYCLES       | INST         | IPC      | CPI      |");
        $display("+----------+--------------+--------------+----------+----------+");
        $display("| G_TO_07  | %12d | %12d | %8.6f | %8.6f |",
                 command_cycles, command_instr,
                 (command_cycles != 0) ?
                   (command_instr * 1.0 / command_cycles) : 0.0,
                 (command_instr != 0) ?
                   (command_cycles * 1.0 / command_instr) : 0.0);
        $display("+----------+--------------+--------------+----------+----------+");
      end else begin
        $display("========== PERFORMANCE SUMMARY ==========");
        $display("SIM_PERF scope=G_TO_07 cycles=%0d instructions=%0d IPC=%.6f CPI=%.6f",
                 command_cycles, command_instr,
                 (command_cycles != 0) ?
                   (command_instr * 1.0 / command_cycles) : 0.0,
                 (command_instr != 0) ?
                   (command_cycles * 1.0 / command_instr) : 0.0);
        $display("USER_PERF scope=PROGRAM_ONLY cycles=%0d instructions=%0d IPC=%.6f CPI=%.6f",
                 user_cycles, user_instr,
                 (user_cycles != 0) ? (user_instr * 1.0 / user_cycles) : 0.0,
                 (user_instr != 0) ? (user_cycles * 1.0 / user_instr) : 0.0);
        $display("=========================================");
      end
      $display("MEM_WRITES count=%0d logged=%0d", write_count, write_log_count);
      for (n = 0; n < write_log_count; n = n + 1)
        $display("WRITE addr=%h data=%h", write_addr_log[n], write_data_log[n]);
      if (watch_words > 0) begin
        validate_region(watch_addr, watch_words);
        $display("MEMORY addr=%h words=%0d", watch_addr, watch_words);
        for (n = 0; n < watch_words; n = n + 1) begin
          addr = watch_addr + n * 4;
          $display("MEM addr=%h data=%h", addr, memory_word(addr));
        end
      end
      if (watch_words_2 > 0) begin
        validate_region(watch_addr_2, watch_words_2);
        $display("MEMORY addr=%h words=%0d", watch_addr_2, watch_words_2);
        for (n = 0; n < watch_words_2; n = n + 1) begin
          addr = watch_addr_2 + n * 4;
          $display("MEM addr=%h data=%h", addr, memory_word(addr));
        end
      end
      $display("PASS asm monitor test");
    end
  endtask

  initial begin
    if (!$value$plusargs("BASE_MIF=%s", base_file) ||
        !$value$plusargs("BASE_WORDS=%d", base_words) ||
        !$value$plusargs("PROGRAM_MIF=%s", program_file) ||
        !$value$plusargs("PROGRAM_WORDS=%d", program_words) ||
        !$value$plusargs("PROGRAM_ADDR=%h", program_addr))
      $fatal(1, "required plusargs: BASE_MIF BASE_WORDS PROGRAM_MIF PROGRAM_WORDS PROGRAM_ADDR");
    if (!$value$plusargs("MAX_CYCLES=%d", max_cycles))
      max_cycles = 64'd300000000;
    if (!$value$plusargs("ENTRY_ADDR=%h", entry_addr))
      entry_addr = program_addr;
    if (!$value$plusargs("WATCH_ADDR=%h", watch_addr)) watch_addr = 32'b0;
    if (!$value$plusargs("WATCH_WORDS=%d", watch_words)) watch_words = 0;
    if (!$value$plusargs("WATCH_ADDR_2=%h", watch_addr_2)) watch_addr_2 = 32'b0;
    if (!$value$plusargs("WATCH_WORDS_2=%d", watch_words_2)) watch_words_2 = 0;
    data_enabled = $value$plusargs("DATA_MIF=%s", data_file);
    if (data_enabled &&
        (!$value$plusargs("DATA_WORDS=%d", data_words) ||
         !$value$plusargs("DATA_ADDR=%h", data_load_addr)))
      $fatal(1, "DATA_MIF requires DATA_WORDS and DATA_ADDR");
    expect_file_enabled = $value$plusargs("EXPECT_MIF=%s", expect_file);
    if (expect_file_enabled &&
        (!$value$plusargs("EXPECT_WORDS=%d", expect_words) ||
         !$value$plusargs("EXPECT_ADDR=%h", expect_addr)))
      $fatal(1, "EXPECT_MIF requires EXPECT_WORDS and EXPECT_ADDR");
    expect_value_enabled = $value$plusargs("EXPECT_VALUE=%h", expect_value);
    if (expect_value_enabled && !$value$plusargs("EXPECT_ADDR=%h", expect_addr))
      $fatal(1, "EXPECT_VALUE requires EXPECT_ADDR");
    if (expect_file_enabled && expect_value_enabled)
      $fatal(1, "EXPECT_MIF and EXPECT_VALUE are mutually exclusive");

    if ($test$plusargs("wave")) begin
      if (!$value$plusargs("WAVE_FILE=%s", wave_file))
        wave_file = "asm_wave.vcd";
      $dumpfile(wave_file);
      $dumpvars(0, cpu);
      $dumpvars(0, bridge);
    end

    validate_region(program_addr, program_words);
    if (program_words > PROGRAM_DEPTH)
      fail("program image exceeds PROGRAM_DEPTH");
    if (!pc_is_user(entry_addr) || entry_addr[1:0] != 2'b0)
      fail("ENTRY_ADDR is outside the program image or unaligned");
    if (base_words <= 0 || base_words > BASE_DEPTH)
      fail("BASE_MIF size is invalid");
    $readmemb(base_file, base_mem, 0, base_words - 1);
    if (data_enabled) begin
      validate_region(data_load_addr, data_words);
      if (data_words > PROGRAM_DEPTH)
        fail("data image exceeds PROGRAM_DEPTH");
      $readmemb(data_file, program_mem, 0, data_words - 1);
      for (i = 0; i < data_words; i = i + 1) begin
        if (address_is_ext(data_load_addr))
          ext_mem[{12'b0, data_load_addr[21:2]} + i] = program_mem[i];
        else
          base_mem[{12'b0, data_load_addr[21:2]} + i] = program_mem[i];
      end
    end
    if ($value$plusargs("INIT_FILE=%s", init_file)) load_sparse_init();
    // Program upload consumes program_mem later, so restore it after preloads.
    $readmemb(program_file, program_mem, 0, program_words - 1);

    clk = 1'b0;
    resetn = 1'b0;
    uart_rx_ready = 1'b0;
    uart_rx_data = 0;
    tx_count = 0;
    cycle_count = 0;
    command_counting = 1'b0;
    command_done = 1'b0;
    user_counting = 1'b0;
    user_done = 1'b0;
    command_cycles = 0;
    command_instr = 0;
    user_cycles = 0;
    user_instr = 0;
    write_count = 0;
    write_log_count = 0;

    repeat (8) @(posedge clk);
    resetn = 1'b1;
    wait_tx(BOOT_LEN);
    for (i = 0; i < BOOT_LEN; i = i + 1)
      if (tx_bytes[i] !== BOOT_MESSAGE[(BOOT_LEN-i)*8-1 -: 8])
        fail("monitor banner mismatch");

    load_program();
    send_g_byte();
    send_word_le(entry_addr);
    while (cpu.pc_out !== entry_addr) @(negedge clk);
    user_counting = 1'b1;
    wait_tx(BOOT_LEN + 2);
    @(negedge clk);
    if (!user_done) fail("user program exit was not observed");
    if (!command_done) fail("G-to-0x07 interval did not complete");
    if (tx_bytes[BOOT_LEN] !== 8'h06 || tx_bytes[BOOT_LEN + 1] !== 8'h07)
      fail("monitor timing markers mismatch");
    compare_results();
    print_report();
    $finish;
  end
endmodule

// The RTL instantiates the Xilinx multiplier IP by this name. A pipelined
// behavioral model keeps the standalone Verilator framework self-contained.
module mult_gen_0(input wire CLK, input wire [31:0] A, input wire [31:0] B,
                  output wire [31:0] P);
  reg [31:0] p0, p1, p2;
  always @(posedge CLK) begin p0 <= A * B; p1 <= p0; p2 <= p1; end
  assign P = p2;
endmodule
