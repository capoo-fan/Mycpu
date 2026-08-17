`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// array_map_engine.v
//
// 通用“逐元素处理后写回”Map 型硬件加速器固定框架
//
// 处理模型：
//     dst[i] = F(src[i])
//
// 本文件负责：
//   1. start / busy / done
//   2. 等待并独占数据存储总线
//   3. 顺序遍历源数组
//   4. 每次读取一个 32-bit 元素
//   5. 将元素送给 accelerator_logic
//   6. 等待 accelerator_logic 返回结果
//   7. 将结果写到目标数组
//   8. 地址自动 +4，直到 SRC_END
//
// 比赛现场原则：
//   - 本文件尽量不要修改。
//   - 只有题目地址范围变化时，修改 SRC_BEGIN/SRC_END/DST_BEGIN 参数。
//   - 题目算法只修改 accelerator_logic.v。
//
// 地址空间注意：
//   参数必须和本模块 mem_addr 接入位置使用同一种地址。
//   如果接在地址翻译之前，可使用 0x8040_0000 这类 CPU 地址；
//   如果接在地址翻译之后，则填写相应物理地址，例如 0x1c40_0000。
// ============================================================================

module array_map_engine #(
    parameter [31:0] SRC_BEGIN = 32'h8040_0000,
    parameter [31:0] SRC_END   = 32'h8050_0000, // exclusive
    parameter [31:0] DST_BEGIN = 32'h8050_0000
)(
    input  wire        clk,
    input  wire        resetn,

    // ------------------------------------------------------------------------
    // CPU / Accelerator control
    // ------------------------------------------------------------------------
    input  wire        start,       // 1-cycle pulse
    output reg         busy,
    output reg         done,        // 1-cycle pulse

    // ------------------------------------------------------------------------
    // Bus ownership
    //
    // 仲裁器应保证：
    // takeover_req=1 后，先排空 CPU 旧访存，再拉高 takeover_grant；
    // 一旦 grant 给出，在 takeover_req 释放前应保持所有权。
    // ------------------------------------------------------------------------
    output wire        takeover_req,
    input  wire        takeover_grant,

    // ------------------------------------------------------------------------
    // SRAM-like master interface
    //
    // req/addr_ok：请求被接受
    // data_ok：读数据返回或写事务完成
    // ------------------------------------------------------------------------
    output reg         mem_req,
    output reg         mem_wr,
    output reg  [1:0]  mem_size,
    output reg  [3:0]  mem_wstrb,
    output reg  [31:0] mem_addr,
    output reg  [31:0] mem_wdata,

    input  wire        mem_addr_ok,
    input  wire        mem_data_ok,
    input  wire [31:0] mem_rdata
);

    // =========================================================================
    // FIXED STATE MACHINE
    // 比赛现场不要改
    // =========================================================================

    localparam [3:0]
        S_IDLE        = 4'd0,
        S_WAIT_BUS    = 4'd1,
        S_READ_REQ    = 4'd2,
        S_READ_WAIT   = 4'd3,
        S_ALGO_START  = 4'd4,
        S_ALGO_WAIT   = 4'd5,
        S_WRITE_REQ   = 4'd6,
        S_WRITE_WAIT  = 4'd7;

    reg [3:0] state;

    // =========================================================================
    // FIXED ADDRESS GENERATOR
    // 比赛现场不要改
    // =========================================================================

    reg [31:0] src_addr;
    reg [31:0] dst_addr;

    // 当前输入和输出寄存器
    reg [31:0] input_data;
    reg [31:0] output_data;

    // =========================================================================
    // Algorithm interface
    //
    // engine 只知道：
    //   给算法一个 input
    //   等算法给一个 output
    //
    // 完全不知道算法是 sqrt / abs / crc / 除法 / 查表 / 其它变换。
    // =========================================================================

    wire        algo_in_valid;
    wire        algo_in_ready;
    wire [31:0] algo_in_data;

    wire        algo_out_valid;
    wire [31:0] algo_out_data;

    assign algo_in_valid = (state == S_ALGO_START);
    assign algo_in_data  = input_data;

    accelerator_logic u_accelerator_logic (
        .clk       (clk),
        .resetn    (resetn),

        .in_valid  (algo_in_valid),
        .in_ready  (algo_in_ready),
        .in_data   (algo_in_data),

        .out_valid (algo_out_valid),
        .out_data  (algo_out_data)
    );

    // =========================================================================
    // Bus ownership
    // =========================================================================

    assign takeover_req = busy;

    // =========================================================================
    // FIXED MEMORY REQUEST GENERATION
    // 比赛现场不要改
    // =========================================================================

    always @(*) begin
        mem_req   = 1'b0;
        mem_wr    = 1'b0;
        mem_size  = 2'b10;       // 32-bit word
        mem_wstrb = 4'b0000;
        mem_addr  = 32'b0;
        mem_wdata = 32'b0;

        case (state)

            // -----------------------------------------------------------------
            // Read src[i]
            // -----------------------------------------------------------------
            S_READ_REQ: begin
                if (takeover_grant) begin
                    mem_req  = 1'b1;
                    mem_wr   = 1'b0;
                    mem_addr = src_addr;
                end
            end

            // -----------------------------------------------------------------
            // Write dst[i]
            // -----------------------------------------------------------------
            S_WRITE_REQ: begin
                if (takeover_grant) begin
                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;
                    mem_size  = 2'b10;
                    mem_wstrb = 4'b1111;
                    mem_addr  = dst_addr;
                    mem_wdata = output_data;
                end
            end

            default: begin
            end

        endcase
    end

    // =========================================================================
    // FIXED MAIN FSM
    // 比赛现场不要改
    // =========================================================================

    always @(posedge clk) begin
        if (!resetn) begin
            state       <= S_IDLE;
            busy        <= 1'b0;
            done        <= 1'b0;

            src_addr    <= SRC_BEGIN;
            dst_addr    <= DST_BEGIN;

            input_data  <= 32'b0;
            output_data <= 32'b0;
        end
        else begin
            // done only pulses for one cycle
            done <= 1'b0;

            case (state)

                // -------------------------------------------------------------
                // Wait for accelerator start
                // -------------------------------------------------------------
                S_IDLE: begin
                    busy <= 1'b0;

                    if (start) begin
                        busy        <= 1'b1;
                        src_addr    <= SRC_BEGIN;
                        dst_addr    <= DST_BEGIN;
                        input_data  <= 32'b0;
                        output_data <= 32'b0;

                        state <= S_WAIT_BUS;
                    end
                end

                // -------------------------------------------------------------
                // Wait until CPU old memory transactions are drained
                // -------------------------------------------------------------
                S_WAIT_BUS: begin
                    if (takeover_grant)
                        state <= S_READ_REQ;
                end

                // -------------------------------------------------------------
                // Submit read request
                // -------------------------------------------------------------
                S_READ_REQ: begin
                    if (mem_addr_ok)
                        state <= S_READ_WAIT;
                end

                // -------------------------------------------------------------
                // Capture src[i]
                // -------------------------------------------------------------
                S_READ_WAIT: begin
                    if (mem_data_ok) begin
                        input_data <= mem_rdata;
                        state      <= S_ALGO_START;
                    end
                end

                // -------------------------------------------------------------
                // Hand current element to algorithm
                //
                // algo_in_valid remains high until algo_in_ready=1.
                // -------------------------------------------------------------
                S_ALGO_START: begin
                    if (algo_in_ready)
                        state <= S_ALGO_WAIT;
                end

                // -------------------------------------------------------------
                // Wait for transformed result
                // -------------------------------------------------------------
                S_ALGO_WAIT: begin
                    if (algo_out_valid) begin
                        output_data <= algo_out_data;
                        state       <= S_WRITE_REQ;
                    end
                end

                // -------------------------------------------------------------
                // Submit write request
                // -------------------------------------------------------------
                S_WRITE_REQ: begin
                    if (mem_addr_ok)
                        state <= S_WRITE_WAIT;
                end

                // -------------------------------------------------------------
                // Write finished:
                //   last element -> done
                //   otherwise    -> src/dst + 4 and continue
                // -------------------------------------------------------------
                S_WRITE_WAIT: begin
                    if (mem_data_ok) begin

                        if ((src_addr + 32'd4) >= SRC_END) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            src_addr <= src_addr + 32'd4;
                            dst_addr <= dst_addr + 32'd4;
                            state    <= S_READ_REQ;
                        end

                    end
                end

                default: begin
                    state       <= S_IDLE;
                    busy        <= 1'b0;
                    done        <= 1'b0;
                    src_addr    <= SRC_BEGIN;
                    dst_addr    <= DST_BEGIN;
                    input_data  <= 32'b0;
                    output_data <= 32'b0;
                end

            endcase
        end
    end

endmodule

`default_nettype wire
