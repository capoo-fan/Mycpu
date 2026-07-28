`timescale 1ns / 1ps

// ============================================================================
// ES_TO_MS_BUS 位提取宏（lane 0 与 lane 1 位置相同）
// ============================================================================
`define ES_BUS_PC            293:262
`define ES_BUS_PRED_TAKEN    184
`define ES_BUS_PRED_TARGET   183:152
`define ES_BUS_IS_BJ         151
`define ES_BUS_REAL_TAKEN    150
`define ES_BUS_REAL_TARGET   149:118
`define ES_BUS_REDIRECT_MISS 85

// ============================================================================
// MS_FWD_BUS 位提取宏
// ============================================================================
`define MS_FWD_VALID     40
`define MS_FWD_GR_WE     39
`define MS_FWD_FWD_VALID 38
`define MS_FWD_RES_MEM   37
`define MS_FWD_DEST      36:32

// ============================================================================
// ES_FWD_BUS 位提取宏
// ============================================================================
`define ES_FWD_VALID     40
`define ES_FWD_GR_WE     39
`define ES_FWD_FWD_VALID 38
`define ES_FWD_RES_MEM   37

// ============================================================================
// BPU 分支历史表大小（用于 per-PC 统计）
// ============================================================================
`define BR_TABLE_SIZE 256

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
  reg [63:0] benchmark_cycle_count;
  reg [63:0] max_cycles;
  reg        counting;
  reg [1023:0] base_file;
  reg [1023:0] ext_file;
  reg [1023:0] ref_file;

  // =========================================================================
  // 性能计数器寄存器
  // =========================================================================

  // -- 基础计数器 --
  reg [63:0] commit_count;
  reg [63:0] dual_issue_cycle_count;

  // -- Frontend 停顿 --
  reg [63:0] fe_icache_miss_cycles;
  reg [63:0] fe_icache_refill_cycles;
  reg [63:0] fe_ibuf_empty_cycles;
  reg [63:0] fe_ibuf_full_cycles;
  reg [63:0] fe_redirect_flush_cycles;

  // -- Issue 停顿 --
  reg [63:0] is_no_inst_cycles;
  reg [63:0] is_backend_full_cycles;
  reg [63:0] is_raw_load_cycles;
  reg [63:0] is_raw_other_cycles;
  reg [63:0] is_pair_blocked_cycles;
  reg [63:0] ex_mul_wait_cycles;
  reg [63:0] pair_mem_conflict_cycles;
  reg [63:0] pair_raw_conflict_cycles;
  reg [63:0] pair_branch_conflict_cycles;
  reg [63:0] pair_special_conflict_cycles;
  reg [63:0] pair_slot1_stall_cycles;
  reg [63:0] pair_other_cycles;
  reg [63:0] issue_special_block_cycles;

  // -- Memory 停顿 --
  reg [63:0] mem_load_addr_wait_cycles;
  reg [63:0] mem_load_data_wait_cycles;
  reg [63:0] mem_store_addr_wait_cycles;
  reg [63:0] mem_store_data_wait_cycles;

  // -- 分支统计 --
  reg [63:0] br_total_count;
  reg [63:0] br_mispredict_count;
  reg [63:0] br_btb_miss_count;
  reg [63:0] br_dir_miss_count;
  reg [63:0] br_target_miss_count;

  // -- Per-PC 分支历史表 --
  reg [31:0] br_pc_table      [`BR_TABLE_SIZE-1:0];
  reg [31:0] br_pc_total      [`BR_TABLE_SIZE-1:0];
  reg [31:0] br_pc_mispredict [`BR_TABLE_SIZE-1:0];
  reg [31:0] br_pc_btb        [`BR_TABLE_SIZE-1:0];
  reg [31:0] br_pc_dir        [`BR_TABLE_SIZE-1:0];
  reg [31:0] br_pc_target     [`BR_TABLE_SIZE-1:0];
  integer    br_pc_count;

  // -- MEM 状态跟踪 --
  reg        mem_pending;
  reg        mem_pending_is_load;
  reg        mem_addr_sent;

  // -- ICache refill 状态跟踪 --
  reg        icache_refill_active;

  // -- 分支信息 pipeline 延迟（ES→MEM 延迟 1 周期） --
  reg        br_info_valid;
  reg [31:0] br_info_pc;
  reg        br_info_pred_taken;
  reg [31:0] br_info_pred_target;
  reg        br_info_real_taken;
  reg [31:0] br_info_real_target;
  reg        br_info_is_bj;

  // -- 重建的内部信号 --
  wire ms_unready_load_tb;
  wire es_mul_pending_tb;
  wire [31:0] es_to_ms_bus_0_flat;
  wire [31:0] es_to_ms_bus_1_flat;

  // lane0 keeps the 295-bit special-instruction payload. lane1 drops that
  // payload; append 85 zero bits so the shared branch-field indices stay put.
  wire [319:0] es_bus_0_padded = {25'b0, cpu.es_to_ms_bus_0};
  wire [319:0] es_bus_1_padded = {26'b0, cpu.es_to_ms_bus_1, 85'b0};

  // MS_FWD_BUS_WD = 41
  wire [63:0] ms_fwd_0_padded = {23'b0, cpu.ms_fwd_bus_0};
  wire [63:0] ms_fwd_1_padded = {23'b0, cpu.ms_fwd_bus_1};

  // ES_FWD_BUS_WD = 41
  wire [63:0] es_fwd_0_padded = {23'b0, cpu.es_fwd_bus_0};
  wire [63:0] es_fwd_1_padded = {23'b0, cpu.es_fwd_bus_1};

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

  // =========================================================================
  // 信号重建：从总线上提取内部信号
  // =========================================================================

  // ms_unready_load: MEM 阶段有未完成的 load，阻塞发射
  assign ms_unready_load_tb =
      (ms_fwd_0_padded[`MS_FWD_VALID] &&
       ms_fwd_0_padded[`MS_FWD_GR_WE] &&
       !ms_fwd_0_padded[`MS_FWD_FWD_VALID]) ||
      (ms_fwd_1_padded[`MS_FWD_VALID] &&
       ms_fwd_1_padded[`MS_FWD_GR_WE] &&
       !ms_fwd_1_padded[`MS_FWD_FWD_VALID]);

  // es_mul_pending: EXE 阶段有未完成的乘法
  assign es_mul_pending_tb =
      (es_fwd_0_padded[`ES_FWD_VALID] &&
       es_fwd_0_padded[`ES_FWD_GR_WE] &&
       !es_fwd_0_padded[`ES_FWD_FWD_VALID] &&
       !es_fwd_0_padded[`ES_FWD_RES_MEM]) ||
      (es_fwd_1_padded[`ES_FWD_VALID] &&
       es_fwd_1_padded[`ES_FWD_GR_WE] &&
       !es_fwd_1_padded[`ES_FWD_FWD_VALID] &&
       !es_fwd_1_padded[`ES_FWD_RES_MEM]);

  // =========================================================================
  // 主计数器逻辑
  // =========================================================================
  always @(posedge clk)
  begin
    cycle_count <= cycle_count + 1;

    // ------ MEM 状态跟踪 ------
    // 跟踪 data_sram 请求的状态，用于区分 load/store addr/data 等待
    if (!resetn || (mem_pending && data_data_ok))
    begin
      mem_pending <= 1'b0;
      mem_addr_sent <= 1'b0;
    end
    else if (data_req && data_addr_ok)
    begin
      mem_pending <= 1'b1;
      mem_pending_is_load <= !data_wr;
      mem_addr_sent <= 1'b1;
    end
    else if (data_req && !data_addr_ok)
    begin
      mem_pending <= 1'b1;
      mem_pending_is_load <= !data_wr;
    end

    // ------ ICache refill 状态跟踪 ------
    if (!resetn || inst_data_ok)
      icache_refill_active <= 1'b0;
    else if (inst_req && inst_addr_ok && !inst_wr)
      icache_refill_active <= 1'b1;

    // ------ 分支信息 pipeline ------
    // 当 EXE→MEM 握手时捕获分支预测/实际信息
    if (cpu.es_to_ms_valid_0 && cpu.ms_allowin &&
        es_bus_0_padded[`ES_BUS_IS_BJ])
    begin
      br_info_valid      <= 1'b1;
      br_info_pc         <= es_bus_0_padded[`ES_BUS_PC];
      br_info_pred_taken <= es_bus_0_padded[`ES_BUS_PRED_TAKEN];
      br_info_pred_target<= es_bus_0_padded[`ES_BUS_PRED_TARGET];
      br_info_real_taken <= es_bus_0_padded[`ES_BUS_REAL_TAKEN];
      br_info_real_target<= es_bus_0_padded[`ES_BUS_REAL_TARGET];
      br_info_is_bj      <= 1'b1;
    end
    else if (cpu.es_to_ms_valid_1 && cpu.ms_allowin &&
             es_bus_1_padded[`ES_BUS_IS_BJ])
    begin
      br_info_valid      <= 1'b1;
      br_info_pc         <= es_bus_1_padded[`ES_BUS_PC];
      br_info_pred_taken <= es_bus_1_padded[`ES_BUS_PRED_TAKEN];
      br_info_pred_target<= es_bus_1_padded[`ES_BUS_PRED_TARGET];
      br_info_real_taken <= es_bus_1_padded[`ES_BUS_REAL_TAKEN];
      br_info_real_target<= es_bus_1_padded[`ES_BUS_REAL_TARGET];
      br_info_is_bj      <= 1'b1;
    end
    else
    begin
      br_info_valid <= 1'b0;
    end

    // ------ 性能计数器累加 ------
    if (counting)
    begin
      benchmark_cycle_count <= benchmark_cycle_count + 1;
      commit_count <= commit_count + {62'b0, cpu.ms_to_ws_valid_0}
                   + {62'b0, cpu.ms_to_ws_valid_1};

      // -- 双发射 --
      if (cpu.ms_to_ws_valid_0 && cpu.ms_to_ws_valid_1)
        dual_issue_cycle_count <= dual_issue_cycle_count + 1;

      // === FRONTEND 停顿 ===
      // icache_miss: IF 停顿但不是因为 ibuf full
      if (cpu.if_suspend && !cpu.ibuf_full)
        fe_icache_miss_cycles <= fe_icache_miss_cycles + 1;

      // icache_refill: inst_sram 正在进行 refill
      if (icache_refill_active || (inst_req && inst_addr_ok && !inst_wr))
        fe_icache_refill_cycles <= fe_icache_refill_cycles + 1;

      // ibuf_empty: 发射队列无有效指令
      if (!cpu.ibuf_front_valid_0)
        fe_ibuf_empty_cycles <= fe_ibuf_empty_cycles + 1;

      // ibuf_full: inst_buffer 已满
      if (cpu.ibuf_full)
        fe_ibuf_full_cycles <= fe_ibuf_full_cycles + 1;

      // redirect_flush: 流水线冲刷（分支误预测 + CSR + CACOP）
      if (cpu.pipeline_flush)
        fe_redirect_flush_cycles <= fe_redirect_flush_cycles + 1;

      // === ISSUE 停顿 ===
      // issue_no_inst: 无可发射指令（与 ibuf_empty 等价）
      if (!cpu.ibuf_front_valid_0)
        is_no_inst_cycles <= is_no_inst_cycles + 1;

      // issue_backend_full: EXE/MEM/WB 反压
      if (!cpu.es_allowin)
        is_backend_full_cycles <= is_backend_full_cycles + 1;

      // issue_raw_load: load-use 停顿（ms_unready_load 阻塞发射窗口）
      if (ms_unready_load_tb)
        is_raw_load_cycles <= is_raw_load_cycles + 1;

      // issue_raw_other: 非 load-use 的 RAW 停顿
      // 排除：backend full, load-use, branch, special_block
      if (cpu.ibuf_front_valid_0 && !cpu.issue_pop_0 &&
          cpu.es_allowin && !ms_unready_load_tb && !cpu.br_taken &&
          !cpu.special_block)
        is_raw_other_cycles <= is_raw_other_cycles + 1;

      // issue_pair_blocked: 两槽都有效但只有 slot0 发射
      if (cpu.ibuf_front_valid_0 && cpu.ibuf_front_valid_1 &&
          cpu.issue_pop_0 && !cpu.issue_pop_1)
        is_pair_blocked_cycles <= is_pair_blocked_cycles + 1;

      if (cpu.u_exe.mul_pending_0 || cpu.u_exe.mul_pending_1)
        ex_mul_wait_cycles <= ex_mul_wait_cycles + 1;

      // --- pair_blocked 原因细分 ---
      // 条件：两槽均有效，slot0 发射但 slot1 未发射
      if (cpu.ibuf_front_valid_0 && cpu.ibuf_front_valid_1 &&
          cpu.issue_pop_0 && !cpu.issue_pop_1)
      begin
        if (cpu.u_issue.mem_op_0 && cpu.u_issue.mem_op_1)
          pair_mem_conflict_cycles <= pair_mem_conflict_cycles + 1;
        else if (cpu.u_issue.raw_0_to_1)
          pair_raw_conflict_cycles <= pair_raw_conflict_cycles + 1;
        else if (cpu.u_issue.is_bj_0 && cpu.u_issue.is_bj_1)
          pair_branch_conflict_cycles <= pair_branch_conflict_cycles + 1;
        else if (cpu.u_issue.special_0 || cpu.u_issue.special_1)
          pair_special_conflict_cycles <= pair_special_conflict_cycles + 1;
        else if (cpu.u_issue.stall_1_for_consume)
          pair_slot1_stall_cycles <= pair_slot1_stall_cycles + 1;
        else
          pair_other_cycles <= pair_other_cycles + 1;
      end

      // issue_special_block: special_block 导致的单发射
      if (cpu.ibuf_front_valid_0 && !cpu.issue_pop_0 &&
          cpu.es_allowin && !ms_unready_load_tb && !cpu.br_taken &&
          cpu.u_issue.stall_0_for_consume === 1'b0 &&
          cpu.special_block)
        issue_special_block_cycles <= issue_special_block_cycles + 1;

      // === MEMORY 停顿 ===
      // load_addr_wait: 等待 load 地址握手
      if (data_req && !data_wr && !data_addr_ok)
        mem_load_addr_wait_cycles <= mem_load_addr_wait_cycles + 1;

      // load_data_wait: load 地址已发送，等待数据
      if (mem_pending && mem_pending_is_load && mem_addr_sent && !data_data_ok)
        mem_load_data_wait_cycles <= mem_load_data_wait_cycles + 1;

      // store_addr_wait: 等待 store 地址握手
      if (data_req && data_wr && !data_addr_ok)
        mem_store_addr_wait_cycles <= mem_store_addr_wait_cycles + 1;

      // store_data_wait: store 地址已发送，等待 data_ok
      if (mem_pending && !mem_pending_is_load && mem_addr_sent && !data_data_ok)
        mem_store_data_wait_cycles <= mem_store_data_wait_cycles + 1;

      // === 分支统计 ===
      if (cpu.bpu_ex_valid)
      begin
        br_total_count <= br_total_count + 1;

        // MEM now registers the global branch flush for the following cycle.
        // Classify the branch on its retirement/detection cycle so bpu_ex_valid
        // and br_info_* still refer to the same instruction.
        if (cpu.u_mem.branch_redirect_fire)
        begin
          br_mispredict_count <= br_mispredict_count + 1;

          // 使用上一周期捕获的分支信息分类误预测类型
          if (br_info_valid)
          begin
            // BTB miss: 未预测跳转但实际跳转
            if (!br_info_pred_taken && br_info_real_taken)
              br_btb_miss_count <= br_btb_miss_count + 1;
            // Direction miss: 预测跳转但实际不跳转
            else if (br_info_pred_taken && !br_info_real_taken)
              br_dir_miss_count <= br_dir_miss_count + 1;
            // Target miss: 预测跳转且实际跳转但目标地址错误
            else if (br_info_pred_taken && br_info_real_taken)
              br_target_miss_count <= br_target_miss_count + 1;
          end

          // Per-PC 统计
          if (br_info_valid)
          begin
            per_pc_update(br_info_pc,
                          1'b1,  // mispredict
                          !br_info_pred_taken && br_info_real_taken,
                          br_info_pred_taken && !br_info_real_taken,
                          br_info_pred_taken && br_info_real_taken);
          end
        end
        else
        begin
          // 正确预测的分支也记录 per-PC
          if (br_info_valid)
            per_pc_update(br_info_pc, 1'b0, 1'b0, 1'b0, 1'b0);
        end
      end
    end // if (counting)

    if (!base_we_n)
    begin
      if (!base_be_n[0]) base_mem[base_addr][ 7: 0] <= base_wdata[ 7: 0];
      if (!base_be_n[1]) base_mem[base_addr][15: 8] <= base_wdata[15: 8];
      if (!base_be_n[2]) base_mem[base_addr][23:16] <= base_wdata[23:16];
      if (!base_be_n[3]) base_mem[base_addr][31:24] <= base_wdata[31:24];
    end
    if (!ext_we_n)
    begin
      if (!ext_be_n[0]) ext_mem[ext_addr][ 7: 0] <= ext_wdata[ 7: 0];
      if (!ext_be_n[1]) ext_mem[ext_addr][15: 8] <= ext_wdata[15: 8];
      if (!ext_be_n[2]) ext_mem[ext_addr][23:16] <= ext_wdata[23:16];
      if (!ext_be_n[3]) ext_mem[ext_addr][31:24] <= ext_wdata[31:24];
    end
    if (uart_tx_start)
    begin
      tx_bytes[tx_count] = uart_tx_data;
      tx_count = tx_count + 1;
    end
    if (cycle_count > max_cycles)
    begin
      $display("FAIL supervisor performance timeout: test=%0d cycles=%0d", test_id, cycle_count);
      $fatal(1);
    end
  end

  // =========================================================================
  // Per-PC 分支统计辅助 task
  // =========================================================================
  task per_pc_update;
    input [31:0] pc;
    input        mispredict;
    input        is_btb;
    input        is_dir;
    input        is_target;
    integer idx;
    begin
      // 查找 PC 是否已在表中
      idx = -1;
      for (i = 0; i < br_pc_count; i = i + 1)
      begin
        if (br_pc_table[i] == pc)
        begin
          idx = i;
          i = br_pc_count;  // break
        end
      end

      // PC 不在表中，添加
      if (idx == -1 && br_pc_count < `BR_TABLE_SIZE)
      begin
        idx = br_pc_count;
        br_pc_table[idx] = pc;
        br_pc_total[idx] = 0;
        br_pc_mispredict[idx] = 0;
        br_pc_btb[idx] = 0;
        br_pc_dir[idx] = 0;
        br_pc_target[idx] = 0;
        br_pc_count = br_pc_count + 1;
      end

      // 累加计数
      if (idx != -1)
      begin
        br_pc_total[idx] = br_pc_total[idx] + 1;
        if (mispredict)
        begin
          br_pc_mispredict[idx] = br_pc_mispredict[idx] + 1;
          if (is_btb)   br_pc_btb[idx]   = br_pc_btb[idx] + 1;
          if (is_dir)   br_pc_dir[idx]   = br_pc_dir[idx] + 1;
          if (is_target) br_pc_target[idx] = br_pc_target[idx] + 1;
        end
      end
    end
  endtask

  // =========================================================================
  // UART 辅助 tasks
  // =========================================================================
  task wait_tx_count;
    input integer wanted;
    begin
      cycles = 0;
      while (tx_count < wanted)
      begin
        @(posedge clk);
        cycles = cycles + 1;
        if (wanted <= BOOT_LEN && cycles > 300000)
        begin
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
      while (!uart_rx_clear)
        @(posedge clk);
      @(negedge clk);
      uart_rx_ready = 1'b0;
      while (uart_rx_clear)
        @(posedge clk);
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

  // =========================================================================
  // 结果比较与性能报告
  // =========================================================================
  task compare_results;
    integer mismatch;
    integer word_count;
    integer actual_base;
    integer expected_base;
    integer j;
    real    ratio;
    begin
      mismatch = 0;
      case (test_id)
        1:
        begin
          word_count = STREAM_WORDS;
          actual_base = 0;
          expected_base = 32'h0010_0000 / 4;
          for (i = 0; i < word_count; i = i + 1)
            if (ext_mem[actual_base + i] !== base_mem[expected_base + i])
            begin
              if (mismatch < 8)
                $display("STREAM mismatch word=%0d actual=%h expected=%h",
                         i, ext_mem[actual_base + i], base_mem[expected_base + i]);
              mismatch = mismatch + 1;
            end
        end
        2:
        begin
          word_count = MATRIX_WORDS;
          actual_base = 32'h0002_0000 / 4;
          expected_base = 32'h0003_0000 / 4;
          for (i = 0; i < word_count; i = i + 1)
            if (ext_mem[actual_base + i] !== ext_mem[expected_base + i])
            begin
              if (mismatch < 8)
                $display("MATRIX mismatch word=%0d actual=%h expected=%h",
                         i, ext_mem[actual_base + i], ext_mem[expected_base + i]);
              mismatch = mismatch + 1;
            end
        end
        3:
        begin
          word_count = CRYPTO_WORDS;
          for (i = 0; i < word_count; i = i + 1)
            if (ext_mem[i] !== ref_mem[i])
            begin
              if (mismatch < 8)
                $display("CRYPTONIGHT mismatch word=%0d actual=%h expected=%h",
                         i, ext_mem[i], ref_mem[i]);
              mismatch = mismatch + 1;
            end
        end
        4:
        begin
          word_count = 5;
          for (i = 0; i < word_count; i = i + 1)
            if (ext_mem[MIXED_SIG_WORD + i] !== ref_mem[i])
            begin
              if (mismatch < 8)
                $display("MIXED mismatch word=%0d actual=%h expected=%h",
                         i, ext_mem[MIXED_SIG_WORD + i], ref_mem[i]);
              mismatch = mismatch + 1;
            end
        end
        default:
          $fatal(1, "invalid TEST_ID");
      endcase

      if (mismatch != 0)
        $fatal(1, "supervisor result mismatch count=%0d", mismatch);

      // =====================================================================
      // 性能报告
      // =====================================================================
      $display("================================================================");
      $display("===  Supervisor Performance Counter  ===");
      $display("================================================================");
      $display("TEST=%0d  cycles=%0d  instr=%0d",
               test_id, benchmark_cycle_count, commit_count);
      $display("");

      // -- IPC --
      $display("--- IPC ---");
      $display("  IPC                         = %.4f",
               (benchmark_cycle_count > 0) ?
               (commit_count * 1.0 / benchmark_cycle_count) : 0.0);
      $display("  Dual-issue cycle ratio      = %.2f%% (%0d/%0d)",
               pct(dual_issue_cycle_count, benchmark_cycle_count),
               dual_issue_cycle_count, benchmark_cycle_count);
      $display("");

      // -- Frontend --
      $display("--- Frontend Stalls ---");
      print_stall("icache_miss",   fe_icache_miss_cycles);
      print_stall("icache_refill", fe_icache_refill_cycles);
      print_stall("ibuf_empty",    fe_ibuf_empty_cycles);
      print_stall("ibuf_full",     fe_ibuf_full_cycles);
      print_stall("redirect_flush",fe_redirect_flush_cycles);
      $display("");

      // -- Issue --
      $display("--- Issue Stalls ---");
      print_stall("issue_no_inst",        is_no_inst_cycles);
      print_stall("issue_backend_full",   is_backend_full_cycles);
      print_stall("issue_raw_load",       is_raw_load_cycles);
      print_stall("issue_raw_other",      is_raw_other_cycles);
      print_stall("issue_special_block",  issue_special_block_cycles);
      print_stall("ex_mul_wait",          ex_mul_wait_cycles);
      $display("");
      $display("--- Pair-Blocked Breakdown ---");
      print_stall("pair_blocked_total",   is_pair_blocked_cycles);
      print_stall("  mem_conflict",        pair_mem_conflict_cycles);
      print_stall("  raw_conflict",        pair_raw_conflict_cycles);
      print_stall("  branch_conflict",     pair_branch_conflict_cycles);
      print_stall("  special_conflict",    pair_special_conflict_cycles);
      print_stall("  slot1_stall",         pair_slot1_stall_cycles);
      print_stall("  other",               pair_other_cycles);
      $display("");

      // -- Memory --
      $display("--- Memory Stalls ---");
      print_stall("load_addr_wait",       mem_load_addr_wait_cycles);
      print_stall("load_data_wait",       mem_load_data_wait_cycles);
      print_stall("store_addr_wait",      mem_store_addr_wait_cycles);
      print_stall("store_data_wait",      mem_store_data_wait_cycles);
      $display("  store_buffer_full           = N/A (no store buffer)");
      $display("");

      // -- Branch --
      $display("--- Branch Prediction ---");
      $display("  branch_count                = %0d", br_total_count);
      $display("  branch_mispredict           = %0d", br_mispredict_count);
      ratio = (br_total_count > 0) ?
              (br_mispredict_count * 100.0 / br_total_count) : 0.0;
      $display("  mispredict_rate             = %.2f%%", ratio);
      $display("  btb_miss                    = %0d (%.2f%%)",
               br_btb_miss_count,
               (br_mispredict_count > 0) ?
               (br_btb_miss_count * 100.0 / br_mispredict_count) : 0.0);
      $display("  direction_miss              = %0d (%.2f%%)",
               br_dir_miss_count,
               (br_mispredict_count > 0) ?
               (br_dir_miss_count * 100.0 / br_mispredict_count) : 0.0);
      $display("  target_miss                 = %0d (%.2f%%)",
               br_target_miss_count,
               (br_mispredict_count > 0) ?
               (br_target_miss_count * 100.0 / br_mispredict_count) : 0.0);
      $display("");

      // -- Per-PC branch detail (top 20 by mispredict count) --
      if (br_pc_count > 0)
      begin
        $display("--- Branch Per-PC (top 20 by mispredicts) ---");
        $display("  %-10s %-10s %-10s %-6s %-6s %-6s %-6s",
                 "PC", "total", "mispredict", "rate", "BTB", "dir", "tgt");
        // 简单冒泡排序找出 mispredict 最多的前20个
        print_top_branches();
        $display("");
      end

      // =====================================================================
      // 双发射瓶颈诊断摘要
      // =====================================================================
      $display("--- Dual-Issue Bottleneck Analysis ---");
      $display("  Pair-blocked cycles         = %0d (%.2f%% of total)",
               is_pair_blocked_cycles,
               pct(is_pair_blocked_cycles, benchmark_cycle_count));
      $display("  Breakdown of pair-blocked (why slot1 blocked):");
      $display("    mem_conflict  (both mem ops)  = %6.2f%% (%0d)",
               pct(pair_mem_conflict_cycles,  is_pair_blocked_cycles),
               pair_mem_conflict_cycles);
      $display("    raw_conflict  (RAW 0->1)      = %6.2f%% (%0d)",
               pct(pair_raw_conflict_cycles,  is_pair_blocked_cycles),
               pair_raw_conflict_cycles);
      $display("    branch_conflict (both branch) = %6.2f%% (%0d)",
               pct(pair_branch_conflict_cycles, is_pair_blocked_cycles),
               pair_branch_conflict_cycles);
      $display("    special_conflict (CSR/CACOP)  = %6.2f%% (%0d)",
               pct(pair_special_conflict_cycles, is_pair_blocked_cycles),
               pair_special_conflict_cycles);
      $display("    slot1_stall  (slot1 RAW wait) = %6.2f%% (%0d)",
               pct(pair_slot1_stall_cycles, is_pair_blocked_cycles),
               pair_slot1_stall_cycles);
      $display("    other        (unclassified)   = %6.2f%% (%0d)",
               pct(pair_other_cycles, is_pair_blocked_cycles),
               pair_other_cycles);
      $display("");

      // =====================================================================
      // 单发射原因总览（整体瓶颈分布）
      // =====================================================================
      $display("--- Issue Bottleneck Overview (why slot0 can't fire) ---");
      $display("  %-28s = %6.2f%% (%0d)",
               "no_inst (frontend empty)",
               pct(is_no_inst_cycles, benchmark_cycle_count),
               is_no_inst_cycles);
      $display("  %-28s = %6.2f%% (%0d)",
               "backend_full (EX/MEM/WB busy)",
               pct(is_backend_full_cycles, benchmark_cycle_count),
               is_backend_full_cycles);
      $display("  %-28s = %6.2f%% (%0d)",
               "raw_load (load-use stall)",
               pct(is_raw_load_cycles, benchmark_cycle_count),
               is_raw_load_cycles);
      $display("  %-28s = %6.2f%% (%0d)",
               "raw_other (ALU/MUL RAW stall)",
               pct(is_raw_other_cycles, benchmark_cycle_count),
               is_raw_other_cycles);
      $display("  %-28s = %6.2f%% (%0d)",
               "special_block (CSR/CACOP)",
               pct(issue_special_block_cycles, benchmark_cycle_count),
               issue_special_block_cycles);
      $display("");

      $display("PASS supervisor performance test=%0d cycles=%0d instr=%0d IPC=%.4f",
               test_id, benchmark_cycle_count, commit_count,
               (benchmark_cycle_count > 0) ?
               (commit_count * 1.0 / benchmark_cycle_count) : 0.0);
    end
  endtask

  // =========================================================================
  // 辅助函数
  // =========================================================================
  function real pct;
    input [63:0] num;
    input [63:0] den;
    begin
      pct = (den > 0) ? (num * 100.0 / den) : 0.0;
    end
  endfunction

  task print_stall;
    input [8*32-1:0] name;
    input [63:0]     count;
    begin
      $display("  %-28s = %6.2f%% (%0d/%0d)",
               name,
               pct(count, benchmark_cycle_count),
               count, benchmark_cycle_count);
    end
  endtask

  task print_top_branches;
    integer k, m, best_idx;
    reg [31:0]  best_pc;
    reg [31:0]  best_total;
    reg [31:0]  best_mis;
    reg [31:0]  best_btb;
    reg [31:0]  best_dir;
    reg [31:0]  best_tgt;
    reg [255:0] printed;  // bitmask
    reg         found;
    begin
      printed = 256'b0;
      for (k = 0; k < 20 && k < br_pc_count; k = k + 1)
      begin
        best_idx = -1;
        best_mis = 0;
        found = 1'b0;
        for (m = 0; m < br_pc_count; m = m + 1)
        begin
          if (!printed[m] && br_pc_mispredict[m] >= best_mis)
          begin
            best_idx  = m;
            best_mis  = br_pc_mispredict[m];
            found = 1'b1;
          end
        end
        if (!found || best_idx == -1)
          k = br_pc_count;  // break
        else
        begin
          printed[best_idx] = 1'b1;
          $display("  %h  %-10d %-10d %5.1f%% %-6d %-6d %-6d",
                   br_pc_table[best_idx],
                   br_pc_total[best_idx],
                   br_pc_mispredict[best_idx],
                   (br_pc_total[best_idx] > 0) ?
                    (br_pc_mispredict[best_idx] * 100.0 / br_pc_total[best_idx]) : 0.0,
                   br_pc_btb[best_idx],
                   br_pc_dir[best_idx],
                   br_pc_target[best_idx]);
        end
      end
    end
  endtask

  // =========================================================================
  // 初始化与测试流程
  // =========================================================================
  initial
  begin
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
    benchmark_cycle_count     = 0;
    commit_count             = 0;
    dual_issue_cycle_count = 0;
    fe_icache_miss_cycles    = 0;
    fe_icache_refill_cycles  = 0;
    fe_ibuf_empty_cycles     = 0;
    fe_ibuf_full_cycles      = 0;
    fe_redirect_flush_cycles = 0;
    is_no_inst_cycles        = 0;
    is_backend_full_cycles   = 0;
    is_raw_load_cycles       = 0;
    is_raw_other_cycles      = 0;
    is_pair_blocked_cycles   = 0;
    ex_mul_wait_cycles       = 0;
    pair_mem_conflict_cycles   = 0;
    pair_raw_conflict_cycles   = 0;
    pair_branch_conflict_cycles = 0;
    pair_special_conflict_cycles = 0;
    pair_slot1_stall_cycles    = 0;
    pair_other_cycles          = 0;
    issue_special_block_cycles = 0;
    mem_load_addr_wait_cycles = 0;
    mem_load_data_wait_cycles = 0;
    mem_store_addr_wait_cycles = 0;
    mem_store_data_wait_cycles = 0;
    br_total_count           = 0;
    br_mispredict_count      = 0;
    br_btb_miss_count        = 0;
    br_dir_miss_count        = 0;
    br_target_miss_count     = 0;
    br_pc_count              = 0;
    mem_pending              = 1'b0;
    mem_addr_sent            = 1'b0;
    icache_refill_active     = 1'b0;
    br_info_valid            = 1'b0;
    counting                 = 1'b0;

    repeat (8) @(posedge clk);
    resetn = 1'b1;
    wait_tx_count(BOOT_LEN);

    send_rx_byte(8'h47);
    send_word_le(entry_addr);
    counting = 1'b1;
    wait_tx_count(BOOT_LEN + 2);
    counting = 1'b0;
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
  always @(posedge CLK)
  begin
    pipe0 <= $signed(A) * $signed(B);
    pipe1 <= pipe0;
    pipe2 <= pipe1;
  end
  assign P = pipe2;
endmodule
