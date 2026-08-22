`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// array_accel_engine.v
//
// 通用 Reduction 加速器：顺序读取数组，由 accelerator_logic 逐项归约，
// 最后只写一个 32-bit 结果。
//
// 算法侧使用 ready/valid 握手：
//   - in_valid && in_ready：当前元素被算法接收；
//   - out_valid：当前元素处理完成，归约状态已经可以处理下一项；
//   - 上一项未完成时，下一项最多停在 input_data 缓冲，不会进入算法；
//   - out_valid 与下一项输入握手允许同拍发生，单拍算法不会产生空拍。
//
// 访存侧最多保留一笔未返回的读请求，并带一个输入缓冲。算法接收当前项
// 的同拍会预取下一项；若算法是多周期的，预取结果会稳定保存在缓冲中。
// mem_data_ok 最早应在请求被接受后的下一拍返回，响应必须严格有序。
// ============================================================================

module array_accel_engine #(
    parameter [31:0] ARRAY_BEGIN = 32'h1c40_0000,
    parameter [31:0] ARRAY_END   = 32'h1c70_0000, // exclusive
    parameter [31:0] RESULT_ADDR = 32'h1c70_0000
)(
    input  wire        clk,
    input  wire        resetn,

    input  wire        start,
    output reg         busy,
    output reg         done,

    output wire        takeover_req,
    input  wire        takeover_grant,

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

    localparam [2:0]
        S_IDLE       = 3'd0,
        S_WAIT_BUS   = 3'd1,
        S_SCAN       = 3'd2,
        S_WRITE_REQ  = 3'd3,
        S_WRITE_WAIT = 3'd4;

    reg [2:0] state;

    // 下一笔尚未被 mem_addr_ok 接受的读地址。
    reg [31:0] issue_addr;

    // addr_ok 背压期间保持读请求载荷。
    reg        held_read_req;
    reg [31:0] held_read_addr;

    // 已接受、尚未返回的唯一读请求及其元素属性。
    reg read_pending;
    reg pending_first;
    reg pending_last;

    // 算法忙时，下一项读响应保存在这个单入口缓冲中。
    reg        input_valid;
    reg [31:0] input_data;
    reg        input_first;
    reg        input_last;

    // out_valid 对应的在途元素属性。算法允许在完成旧元素的同拍接收新元素。
    reg algo_active;
    reg algo_active_last;

    wire algo_run_start = (state == S_IDLE) && start;
    wire algo_in_ready;
    wire algo_out_valid;
    wire [31:0] algo_result;

    assign takeover_req = busy;

    // 读响应只可能对应 read_pending。与 Map 模板相同，不支持请求接受同拍
    // 立即返回数据，以免组合环路破坏 ready/valid 判定。
    wire read_response = (state == S_SCAN) && mem_data_ok && read_pending;

    wire response_first = pending_first;
    wire response_last  = pending_last;

    // 空缓冲时把读响应直接旁路到算法；算法未就绪才在时钟沿写入缓冲。
    wire        algo_in_valid = input_valid || read_response;
    wire [31:0] algo_in_data  = input_valid ? input_data  : mem_rdata;
    wire        algo_in_first = input_valid ? input_first : response_first;
    wire        algo_in_last  = input_valid ? input_last  : response_last;
    wire        algo_accept   = algo_in_valid && algo_in_ready;

    accelerator_logic u_accelerator_logic (
        .clk      (clk),
        .resetn   (resetn),
        .run_start(algo_run_start),
        .in_valid (algo_in_valid),
        .in_ready (algo_in_ready),
        .in_first (algo_in_first),
        .in_data  (algo_in_data),
        .out_valid(algo_out_valid),
        .result   (algo_result)
    );

    wire have_more_requests = (issue_addr < ARRAY_END);

    // 一个输入槽由 input_valid、read_pending 或 held_read_req 三者之一占用。
    // 若本拍算法接收了该槽中的元素，时钟沿后槽会立即释放，因此可以在
    // 同拍提出下一笔读请求。这条旁路是单拍算法逐拍吞吐的关键。
    wire input_slot_available = (!input_valid && !read_pending &&
                                 !held_read_req) || algo_accept;
    wire offer_new_read = (state == S_SCAN) && takeover_grant &&
                          !held_read_req && have_more_requests &&
                          input_slot_available;

    always @(*) begin
        mem_req   = 1'b0;
        mem_wr    = 1'b0;
        mem_size  = 2'b10;
        mem_wstrb = 4'b0000;
        mem_addr  = 32'b0;
        mem_wdata = 32'b0;

        case (state)
            S_SCAN: begin
                // 请求一旦提出，即使仲裁 grant 异常撤回也必须保持到
                // addr_ok；新请求仍只在持有 grant 时产生。
                if (held_read_req) begin
                    mem_req  = 1'b1;
                    mem_addr = held_read_addr;
                end
                else if (offer_new_read) begin
                    mem_req  = 1'b1;
                    mem_addr = issue_addr;
                end
            end

            S_WRITE_REQ: begin
                if (takeover_grant) begin
                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;
                    mem_wstrb = 4'b1111;
                    mem_addr  = RESULT_ADDR;
                    mem_wdata = algo_result;
                end
            end

            default: begin
            end
        endcase
    end

    wire read_request_fire = (state == S_SCAN) && mem_req &&
                             !mem_wr && mem_addr_ok;
    wire request_is_first  = (mem_addr == ARRAY_BEGIN);
    wire request_is_last   = ((mem_addr + 32'd4) >= ARRAY_END);

    // 正常 out_valid 对应 algo_active；也允许纯组合算法在输入握手同拍
    // 给出 out_valid，此时完成属性直接取当前输入。
    wire algo_completion = algo_out_valid && (algo_active || algo_accept);
    wire completion_last = algo_active ? algo_active_last : algo_in_last;

    always @(posedge clk) begin
        if (!resetn) begin
            state             <= S_IDLE;
            busy              <= 1'b0;
            done              <= 1'b0;
            issue_addr        <= ARRAY_BEGIN;
            held_read_req     <= 1'b0;
            held_read_addr    <= 32'b0;
            read_pending      <= 1'b0;
            pending_first     <= 1'b0;
            pending_last      <= 1'b0;
            input_valid       <= 1'b0;
            input_data        <= 32'b0;
            input_first       <= 1'b0;
            input_last        <= 1'b0;
            algo_active       <= 1'b0;
            algo_active_last  <= 1'b0;
        end
        else begin
            done <= 1'b0;

            case (state)
                S_IDLE: begin
                    busy <= 1'b0;

                    if (start) begin
                        busy             <= 1'b1;
                        issue_addr       <= ARRAY_BEGIN;
                        held_read_req    <= 1'b0;
                        read_pending     <= 1'b0;
                        input_valid      <= 1'b0;
                        algo_active      <= 1'b0;
                        algo_active_last <= 1'b0;
                        state            <= S_WAIT_BUS;
                    end
                end

                S_WAIT_BUS: begin
                    if (takeover_grant) begin
                        // 空区间写回 accelerator_logic 在 run_start 后的初值。
                        if (ARRAY_BEGIN >= ARRAY_END)
                            state <= S_WRITE_REQ;
                        else
                            state <= S_SCAN;
                    end
                end

                S_SCAN: begin
                    // 首次提出但未被接受时，锁存请求以满足 SRAM-like 保持约定。
                    if (!held_read_req && mem_req && !mem_addr_ok) begin
                        held_read_req  <= 1'b1;
                        held_read_addr <= mem_addr;
                    end
                    else if (held_read_req && read_request_fire) begin
                        held_read_req <= 1'b0;
                    end

                    if (read_request_fire) begin
                        issue_addr    <= issue_addr + 32'd4;
                        pending_first <= request_is_first;
                        pending_last  <= request_is_last;
                    end

                    // 返回旧请求的同拍可以接受替代请求；否则 pending 清零。
                    if (read_response)
                        read_pending <= read_request_fire;
                    else if (read_request_fire)
                        read_pending <= 1'b1;

                    // 缓冲消费与读响应补入支持同拍替换；正常工作时不会出现
                    // input_valid 与 read_response 同时有效。
                    if (read_response) begin
                        if (!algo_accept || input_valid) begin
                            input_valid <= 1'b1;
                            input_data  <= mem_rdata;
                            input_first <= response_first;
                            input_last  <= response_last;
                        end
                    end
                    else if (input_valid && algo_accept) begin
                        input_valid <= 1'b0;
                    end

                    // 完成旧元素和接收新元素可以发生在同一个时钟沿。
                    if (algo_accept) begin
                        // 无在途元素时，纯组合算法可以在输入握手同拍完成，
                        // 这种情况下不留下伪造的 active；有旧元素时的
                        // out_valid 对应旧元素，新接收元素仍保持 active。
                        algo_active      <= algo_active || !algo_out_valid;
                        algo_active_last <= algo_in_last;
                    end
                    else if (algo_completion) begin
                        algo_active <= 1'b0;
                    end

                    if (algo_completion && completion_last)
                        state <= S_WRITE_REQ;
                end

                S_WRITE_REQ: begin
                    if (mem_req && mem_addr_ok) begin
                        if (mem_data_ok) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            state <= S_WRITE_WAIT;
                        end
                    end
                end

                S_WRITE_WAIT: begin
                    if (mem_data_ok) begin
                        busy  <= 1'b0;
                        done  <= 1'b1;
                        state <= S_IDLE;
                    end
                end

                default: begin
                    state <= S_IDLE;
                    busy  <= 1'b0;
                end
            endcase
        end
    end

`ifndef SYNTHESIS
    always @(posedge clk) begin
        if (resetn && (state == S_SCAN)) begin
            if (mem_data_ok && !read_pending)
                $error("Reduction received a read response without a pending request");
            if (input_valid && read_response && !algo_accept)
                $error("Reduction input buffer overflow");
            if (algo_out_valid && !algo_active && !algo_accept)
                $error("Reduction accelerator_logic completed without an active input");
            if (algo_accept && algo_active && !algo_out_valid)
                $error("Reduction accelerator_logic accepted a new input before completion");
        end
    end
`endif

endmodule

`default_nettype wire
