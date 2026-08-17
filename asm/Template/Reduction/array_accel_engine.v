`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// Array Streaming Accelerator Engine
//
// 【固定框架】
// 一般比赛现场不要修改本文件。
//
// 功能：
//   1. 接收 start
//   2. 请求接管数据 SRAM / ExtRAM 总线
//   3. 从 ARRAY_BEGIN 开始按 32-bit word 顺序遍历
//   4. 第一个 word 通过 first_valid 送给 accelerator_logic
//   5. 后续 word 通过 data_valid 送给 accelerator_logic
//   6. 最终把 accelerator_logic.result 写入 RESULT_ADDR
//   7. 产生 done
//
// 当前假设：
//   - 数组元素宽度 32 bit
//   - 单次只允许一个 outstanding transaction
//   - SRAM-like: req / addr_ok / data_ok
// ============================================================================

module array_accel_engine #(
    // ========================================================================
    // CONFIGURATION
    //
    // 如果 Accelerator 直接接到 thinpad_sram_uart_bridge 前，
    // 这里应该填写【物理地址】。
    //
    // 0x80400000 -> 0x1c400000
    // 0x80700000 -> 0x1c700000
    //
    // 如果 Accelerator 接在地址翻译之前，则使用 0x80400000 等虚地址。
    // ========================================================================

    parameter [31:0] ARRAY_BEGIN = 32'h1c40_0000,
    parameter [31:0] ARRAY_END   = 32'h1c70_0000, // exclusive
    parameter [31:0] RESULT_ADDR = 32'h1c70_0000

)(
    input  wire        clk,
    input  wire        resetn,

    // ========================================================================
    // CPU control interface
    // ========================================================================

    // 特殊 DIV 指令触发，一拍脉冲
    input  wire        start,

    // Accelerator 从 start 到最终写回完成一直为 1
    output reg         busy,

    // 完成脉冲，一拍
    output reg         done,

    // ========================================================================
    // Bus ownership interface
    // ========================================================================

    // 请求独占 CPU data SRAM / ExtRAM 接口
    output wire        takeover_req,

    // 仲裁器确认：
    //   1. 旧 CPU 访存已全部结束
    //   2. 总线已经切换给 Accelerator
    input  wire        takeover_grant,

    // ========================================================================
    // SRAM-like master interface
    // ========================================================================

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


    // ========================================================================
    // FIXED STATE MACHINE
    // 比赛现场不要修改
    // ========================================================================

    localparam [3:0]
        S_IDLE        = 4'd0,
        S_WAIT_BUS    = 4'd1,

        S_FIRST_REQ   = 4'd2,
        S_FIRST_WAIT  = 4'd3,

        S_SCAN_REQ    = 4'd4,
        S_SCAN_WAIT   = 4'd5,

        S_WRITE_REQ   = 4'd6,
        S_WRITE_WAIT  = 4'd7;


    reg [3:0] state;


    // ========================================================================
    // FIXED ADDRESS GENERATOR
    // 比赛现场不要修改
    // ========================================================================

    reg [31:0] scan_addr;


    // ========================================================================
    // Algorithm interface
    // ========================================================================

    wire        algo_run_start;
    wire        algo_first_valid;
    wire        algo_data_valid;
    wire [31:0] algo_data;
    wire [31:0] algo_result;


    // 每次新的 Accelerator 任务开始
    assign algo_run_start =
        (state == S_IDLE) && start;


    // 数组第一个元素返回
    assign algo_first_valid =
        (state == S_FIRST_WAIT) && mem_data_ok;


    // 后续数组元素返回
    assign algo_data_valid =
        (state == S_SCAN_WAIT) && mem_data_ok;


    assign algo_data = mem_rdata;


    // ========================================================================
    // USER ALGORITHM MODULE
    //
    // 比赛现场只修改 accelerator_logic.v
    // ========================================================================

    accelerator_logic u_accelerator_logic (
        .clk         (clk),
        .resetn      (resetn),

        .run_start   (algo_run_start),

        .first_valid (algo_first_valid),
        .data_valid  (algo_data_valid),

        .data        (algo_data),

        .result      (algo_result)
    );


    // ========================================================================
    // Bus ownership
    // ========================================================================

    assign takeover_req = busy;


    // ========================================================================
    // FIXED SRAM REQUEST GENERATION
    // 比赛现场不要修改
    // ========================================================================

    always @(*) begin

        mem_req   = 1'b0;
        mem_wr    = 1'b0;

        // 32-bit word
        mem_size  = 2'b10;

        mem_wstrb = 4'b0000;

        mem_addr  = 32'b0;
        mem_wdata = 32'b0;


        case (state)

            // ----------------------------------------------------------------
            // A[0]
            // ----------------------------------------------------------------

            S_FIRST_REQ: begin

                if (takeover_grant) begin
                    mem_req  = 1'b1;
                    mem_wr   = 1'b0;
                    mem_addr = ARRAY_BEGIN;
                end

            end


            // ----------------------------------------------------------------
            // A[1], A[2], ...
            // ----------------------------------------------------------------

            S_SCAN_REQ: begin

                if (takeover_grant) begin
                    mem_req  = 1'b1;
                    mem_wr   = 1'b0;
                    mem_addr = scan_addr;
                end

            end


            // ----------------------------------------------------------------
            // result writeback
            // ----------------------------------------------------------------

            S_WRITE_REQ: begin

                if (takeover_grant) begin

                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;

                    mem_size  = 2'b10;
                    mem_wstrb = 4'b1111;

                    mem_addr  = RESULT_ADDR;
                    mem_wdata = algo_result;

                end

            end


            default: begin
            end

        endcase

    end


    // ========================================================================
    // FIXED MAIN FSM
    //
    // 这个状态机只负责：
    //     遍历
    //     handshake
    //     地址递增
    //     写回
    //
    // 与题目计算内容完全无关。
    // ========================================================================

    always @(posedge clk) begin

        if (!resetn) begin

            state     <= S_IDLE;

            busy      <= 1'b0;
            done      <= 1'b0;

            scan_addr <= ARRAY_BEGIN;

        end
        else begin

            // done 只维持一拍
            done <= 1'b0;


            case (state)

                // ============================================================
                // IDLE
                // ============================================================

                S_IDLE: begin

                    busy <= 1'b0;

                    if (start) begin

                        busy <= 1'b1;

                        scan_addr <= ARRAY_BEGIN;

                        state <= S_WAIT_BUS;

                    end

                end


                // ============================================================
                // 等待 CPU 旧访存结束并获得总线
                // ============================================================

                S_WAIT_BUS: begin

                    if (takeover_grant) begin
                        state <= S_FIRST_REQ;
                    end

                end


                // ============================================================
                // 发起 A[0]
                // ============================================================

                S_FIRST_REQ: begin

                    if (mem_addr_ok) begin
                        state <= S_FIRST_WAIT;
                    end

                end


                // ============================================================
                // 等待 A[0]
                //
                // 注意：
                // 对 A[0] 的处理完全在 accelerator_logic 中进行。
                // =================================================================

                S_FIRST_WAIT: begin

                    if (mem_data_ok) begin

                        scan_addr <= ARRAY_BEGIN + 32'd4;


                        // 如果数组只有一个元素
                        if ((ARRAY_BEGIN + 32'd4) >= ARRAY_END)
                            state <= S_WRITE_REQ;

                        else
                            state <= S_SCAN_REQ;

                    end

                end


                // ============================================================
                // 发起后续数组读取
                // ============================================================

                S_SCAN_REQ: begin

                    if (mem_addr_ok) begin
                        state <= S_SCAN_WAIT;
                    end

                end


                // ============================================================
                // 后续数据返回
                //
                // 注意：
                // 这里完全不关心最大值、计数、求和等。
                //
                // accelerator_logic 通过 data_valid 自动得到 mem_rdata。
                // ============================================================

                S_SCAN_WAIT: begin

                    if (mem_data_ok) begin

                        // ----------------------------------------------------
                        // FIXED ARRAY WALK LOGIC
                        // 永远不要在这里放题目算法
                        // ----------------------------------------------------

                        if ((scan_addr + 32'd4) >= ARRAY_END) begin

                            // 当前已经是最后一个元素
                            state <= S_WRITE_REQ;

                        end
                        else begin

                            scan_addr <= scan_addr + 32'd4;

                            state <= S_SCAN_REQ;

                        end

                    end

                end


                // ============================================================
                // 写结果
                // ============================================================

                S_WRITE_REQ: begin

                    if (mem_addr_ok) begin
                        state <= S_WRITE_WAIT;
                    end

                end


                // ============================================================
                // 等待写操作真正完成
                // ============================================================

                S_WRITE_WAIT: begin

                    if (mem_data_ok) begin

                        busy <= 1'b0;
                        done <= 1'b1;

                        state <= S_IDLE;

                    end

                end


                // ============================================================
                // safety
                // ============================================================

                default: begin

                    state <= S_IDLE;

                    busy <= 1'b0;
                    done <= 1'b0;

                    scan_addr <= ARRAY_BEGIN;

                end

            endcase

        end

    end

endmodule

`default_nettype wire