`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// 严格串行的多周期 Reduction engine。
//
// 每次只读一个元素；算法 out_valid 之前不发出下一笔读请求。
// 全部元素处理完成后，将一个 32-bit 归约结果写入 RESULT_ADDR。
// ============================================================================

module array_reduction_handshake_engine #(
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
        S_READ_REQ   = 3'd2,
        S_READ_WAIT  = 3'd3,
        S_ALGO_SEND  = 3'd4,
        S_ALGO_WAIT  = 3'd5,
        S_WRITE_REQ  = 3'd6,
        S_WRITE_WAIT = 3'd7;

    reg [2:0] state;
    reg [31:0] array_addr;
    reg [31:0] input_data;

    wire algo_run_start = (state == S_IDLE) && start;
    wire algo_in_valid  = (state == S_ALGO_SEND);
    wire algo_in_ready;
    wire algo_out_valid;
    wire [31:0] algo_result;

    reduction_handshake_logic u_reduction_handshake_logic (
        .clk      (clk),
        .resetn   (resetn),
        .run_start(algo_run_start),
        .in_valid (algo_in_valid),
        .in_ready (algo_in_ready),
        .in_first (array_addr == ARRAY_BEGIN),
        .in_data  (input_data),
        .out_valid(algo_out_valid),
        .result   (algo_result)
    );

    assign takeover_req = busy;

    always @(*) begin
        mem_req   = 1'b0;
        mem_wr    = 1'b0;
        mem_size  = 2'b10;
        mem_wstrb = 4'b0000;
        mem_addr  = 32'b0;
        mem_wdata = 32'b0;

        case (state)
            S_READ_REQ: begin
                if (takeover_grant) begin
                    mem_req  = 1'b1;
                    mem_addr = array_addr;
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

    wire read_request_fire  = (state == S_READ_REQ) && mem_req && mem_addr_ok;
    wire write_request_fire = (state == S_WRITE_REQ) && mem_req && mem_addr_ok;
    wire current_is_last    = ((array_addr + 32'd4) >= ARRAY_END);

    always @(posedge clk) begin
        if (!resetn) begin
            state      <= S_IDLE;
            busy       <= 1'b0;
            done       <= 1'b0;
            array_addr <= ARRAY_BEGIN;
            input_data <= 32'b0;
        end
        else begin
            done <= 1'b0;

            case (state)
                S_IDLE: begin
                    busy <= 1'b0;
                    if (start) begin
                        busy       <= 1'b1;
                        array_addr <= ARRAY_BEGIN;
                        state      <= S_WAIT_BUS;
                    end
                end

                S_WAIT_BUS: begin
                    if (takeover_grant) begin
                        if (ARRAY_BEGIN >= ARRAY_END)
                            state <= S_WRITE_REQ;
                        else
                            state <= S_READ_REQ;
                    end
                end

                S_READ_REQ: begin
                    if (read_request_fire) begin
                        if (mem_data_ok) begin
                            input_data <= mem_rdata;
                            state      <= S_ALGO_SEND;
                        end
                        else begin
                            state <= S_READ_WAIT;
                        end
                    end
                end

                S_READ_WAIT: begin
                    if (mem_data_ok) begin
                        input_data <= mem_rdata;
                        state      <= S_ALGO_SEND;
                    end
                end

                S_ALGO_SEND: begin
                    if (algo_in_valid && algo_in_ready)
                        state <= S_ALGO_WAIT;
                end

                S_ALGO_WAIT: begin
                    if (algo_out_valid) begin
                        if (current_is_last)
                            state <= S_WRITE_REQ;
                        else begin
                            array_addr <= array_addr + 32'd4;
                            state      <= S_READ_REQ;
                        end
                    end
                end

                S_WRITE_REQ: begin
                    if (write_request_fire) begin
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

endmodule

`default_nettype wire
