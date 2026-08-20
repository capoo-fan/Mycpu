`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// array_map_engine.v
//
// 通用 Map 加速器：dst[i] = F(src[i])。
//
// 性能设计：
//   - 一个输入缓冲允许在算法计算当前元素时预取下一个元素；
//   - 算法结果的写请求一旦被 addr_ok 接受，输出缓冲即可立即复用；
//   - 算法、已接受的写事务和下一次读请求可以重叠；
//   - 总线上仍最多只有一个未完成事务，兼容普通 SRAM-like bridge。
//
// 接口约束：
//   - mem_req 在 mem_addr_ok 前保持，地址、方向和写数据保持稳定；
//   - mem_data_ok 必须与已接受事务一一对应；
//   - accelerator_logic 每接受一个输入，必须按顺序返回一个结果。
// ============================================================================

module array_map_engine #(
    // 数组起止地址，必须 4 字节对齐；SRC_END 为独占上界。
    // DST 为结果起始地址
    parameter [31:0] SRC_BEGIN       = 32'h8040_0000,
    parameter [31:0] SRC_END         = 32'h8050_0000,  // exclusive
    parameter [31:0] DST_BEGIN       = 32'h8050_0000,
    parameter        ENABLE_PREFETCH = 1'b1
) (
    input  wire        clk,
    input  wire        resetn,

    input  wire        start,
    output reg         busy,
    output reg         done,

    output wire        takeover_req,
    input  wire        takeover_grant,

    output reg         mem_req,
    output reg         mem_wr,
    output reg  [ 1:0] mem_size,
    output reg  [ 3:0] mem_wstrb,
    output reg  [31:0] mem_addr,
    output reg  [31:0] mem_wdata,
    
    input  wire        mem_addr_ok,
    input  wire        mem_data_ok,
    input  wire [31:0] mem_rdata
);

  localparam [ 1:0] M_IDLE  = 2'd0, M_REQ = 2'd1, M_WAIT = 2'd2;

  localparam [31:0] DST_END = DST_BEGIN + (SRC_END - SRC_BEGIN);

  reg  [ 1:0] mem_state;

  // 下一笔尚未发出的读/写地址。
  reg  [31:0] read_addr;
  reg  [31:0] write_addr;

  // 单入口输入、输出缓冲。输出在写地址握手后即可释放，因为下游此时
  // 已经锁存地址和写数据；写完成仍由 M_WAIT 等待 data_ok。
  reg         input_valid;
  reg  [31:0] input_data;
  reg         output_valid;
  reg  [31:0] output_data;
  reg         algo_busy;

  // addr_ok 不能立即给出时锁存请求，保证请求载荷稳定。
  reg         held_wr;
  reg  [31:0] held_addr;
  reg  [31:0] held_wdata;

  // 已接受、正在等待 data_ok 的事务属性。
  reg         pending_wr;
  reg         pending_last;

  wire        algo_in_valid;
  wire        algo_in_ready;
  wire [31:0] algo_in_data;
  wire        algo_out_valid;
  wire [31:0] algo_out_data;

  // 输出缓冲占用时不再启动新算法，避免无 out_ready 接口下结果溢出。
  assign algo_in_valid = input_valid && !output_valid;
  assign algo_in_data  = input_data;
  wire algo_accept = algo_in_valid && algo_in_ready;

  accelerator_logic u_accelerator_logic (
      .clk      (clk),
      .resetn   (resetn),
      .in_valid (algo_in_valid),
      .in_ready (algo_in_ready),
      .in_data  (algo_in_data),
      .out_valid(algo_out_valid),
      .out_data (algo_out_data)
  );

  assign takeover_req = busy;

  // 若本拍输入会被算法取走，则输入槽在同一个时钟沿可视为可用；这样
  // SRAM bridge 从 DONE 回到 IDLE 后能立即接受下一次预取。
  wire input_slot_available = !input_valid || algo_accept;
  wire have_more_reads = (read_addr < SRC_END);
  wire current_write_last = ((write_addr + 32'd4) >= DST_END);

  // dst 从 src 内部更高地址开始时，提前读取会改变有意重叠复制的逐项
  // 语义，因此自动关闭预取；其它情况可由参数显式关闭以便调试。
  localparam PREFETCH_SAFE = ENABLE_PREFETCH && !((DST_BEGIN > SRC_BEGIN) && (DST_BEGIN < SRC_END));
  wire read_buffer_available = PREFETCH_SAFE ? input_slot_available :
    (!input_valid && !algo_busy &&
      !output_valid);

  // ------------------------------------------------------------------------
  // Memory request scheduler
  //
  // 写优先可限制输出等待时间；没有待写结果时尽早预取。M_REQ 中只使
  // 用锁存载荷，因此算法和缓冲状态变化不会破坏 SRAM-like 稳定性。
  // ------------------------------------------------------------------------
  always @(*) begin
    mem_req   = 1'b0;
    mem_wr    = 1'b0;
    mem_size  = 2'b10;
    mem_wstrb = 4'b0000;
    mem_addr  = 32'b0;
    mem_wdata = 32'b0;

    if (busy && takeover_grant) begin
      case (mem_state)
        M_IDLE: begin
          if (output_valid) begin
            mem_req   = 1'b1;
            mem_wr    = 1'b1;
            mem_wstrb = 4'b1111;
            mem_addr  = write_addr;
            mem_wdata = output_data;
          end else if (have_more_reads && read_buffer_available) begin
            mem_req  = 1'b1;
            mem_wr   = 1'b0;
            mem_addr = read_addr;
          end
        end

        M_REQ: begin
          mem_req   = 1'b1;
          mem_wr    = held_wr;
          mem_wstrb = held_wr ? 4'b1111 : 4'b0000;
          mem_addr  = held_addr;
          mem_wdata = held_wdata;
        end

        default: begin
        end
      endcase
    end
  end

  wire request_fire = mem_req && mem_addr_ok;

  always @(posedge clk) begin
    if (!resetn) begin
      busy         <= 1'b0;
      done         <= 1'b0;
      mem_state    <= M_IDLE;
      read_addr    <= SRC_BEGIN;
      write_addr   <= DST_BEGIN;
      input_valid  <= 1'b0;
      input_data   <= 32'b0;
      output_valid <= 1'b0;
      output_data  <= 32'b0;
      algo_busy    <= 1'b0;
      held_wr      <= 1'b0;
      held_addr    <= 32'b0;
      held_wdata   <= 32'b0;
      pending_wr   <= 1'b0;
      pending_last <= 1'b0;
    end else begin
      done <= 1'b0;

      // 算法接口与访存控制相互独立，允许两者同拍前进。
      if (algo_accept) begin
        input_valid <= 1'b0;
        algo_busy   <= 1'b1;
      end

      if (algo_out_valid) begin
        output_valid <= 1'b1;
        output_data  <= algo_out_data;
        // 同拍返回旧结果并接受新输入时，新输入仍在运算中。
        if (!algo_accept) algo_busy <= 1'b0;
      end

      if (!busy) begin
        mem_state <= M_IDLE;

        if (start) begin
          read_addr    <= SRC_BEGIN;
          write_addr   <= DST_BEGIN;
          input_valid  <= 1'b0;
          output_valid <= 1'b0;
          algo_busy    <= 1'b0;

          // 空区间不访问总线，也不产生伪造的一个元素。
          if (SRC_BEGIN >= SRC_END) begin
            busy <= 1'b0;
            done <= 1'b1;
          end else begin
            busy <= 1'b1;
          end
        end
      end else begin
        case (mem_state)
          M_IDLE: begin
            if (mem_req) begin
              if (request_fire) begin
                pending_wr <= mem_wr;
                mem_state  <= M_WAIT;

                if (mem_wr) begin
                  pending_last <= current_write_last;
                  output_valid <= 1'b0;
                  write_addr   <= write_addr + 32'd4;
                end else begin
                  pending_last <= 1'b0;
                  read_addr    <= read_addr + 32'd4;
                end
              end else begin
                held_wr    <= mem_wr;
                held_addr  <= mem_addr;
                held_wdata <= mem_wdata;
                mem_state  <= M_REQ;
              end
            end
          end

          M_REQ: begin
            if (request_fire) begin
              pending_wr <= held_wr;
              mem_state  <= M_WAIT;

              if (held_wr) begin
                pending_last <= current_write_last;
                output_valid <= 1'b0;
                write_addr   <= write_addr + 32'd4;
              end else begin
                pending_last <= 1'b0;
                read_addr    <= read_addr + 32'd4;
              end
            end
          end

          M_WAIT: begin
            if (mem_data_ok) begin
              mem_state <= M_IDLE;

              if (pending_wr) begin
                if (pending_last) begin
                  busy <= 1'b0;
                  done <= 1'b1;
                end
              end else begin
                // 若算法恰好同拍取走旧输入，新返回值直接补入。
                input_valid <= 1'b1;
                input_data  <= mem_rdata;
              end
            end
          end

          default: begin
            mem_state <= M_IDLE;
          end
        endcase
      end
    end
  end

endmodule

`default_nettype wire
