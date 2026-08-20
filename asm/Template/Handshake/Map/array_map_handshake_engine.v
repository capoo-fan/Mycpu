`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// 严格串行的多周期 Map engine：dst[i] = F(src[i])
//
// 只有当前元素已读回、算法 out_valid 已到达、结果已写完，
// 才会读取下一个元素。无预取，总线最多一笔 outstanding 事务。
// ============================================================================

module array_map_handshake_engine #(
    parameter [31:0] SRC_BEGIN = 32'h1c40_0000,
    parameter [31:0] SRC_END   = 32'h1c50_0000, // exclusive
    parameter [31:0] DST_BEGIN = 32'h1c50_0000
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
    reg [31:0] src_addr;
    reg [31:0] dst_addr;
    reg [31:0] input_data;
    reg [31:0] output_data;

    wire        algo_in_valid = (state == S_ALGO_SEND);
    wire        algo_in_ready;
    wire [31:0] algo_out_data;
    wire        algo_out_valid;

    map_handshake_logic u_map_handshake_logic (
        .clk      (clk),
        .resetn   (resetn),
        .in_valid (algo_in_valid),
        .in_ready (algo_in_ready),
        .in_data  (input_data),
        .out_valid(algo_out_valid),
        .out_data (algo_out_data)
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
                    mem_addr = src_addr;
                end
            end

            S_WRITE_REQ: begin
                if (takeover_grant) begin
                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;
                    mem_wstrb = 4'b1111;
                    mem_addr  = dst_addr;
                    mem_wdata = output_data;
                end
            end

            default: begin
            end
        endcase
    end

    wire read_request_fire  = (state == S_READ_REQ) && mem_req && mem_addr_ok;
    wire write_request_fire = (state == S_WRITE_REQ) && mem_req && mem_addr_ok;
    wire current_is_last    = ((src_addr + 32'd4) >= SRC_END);

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
            done <= 1'b0;

            case (state)
                S_IDLE: begin
                    busy <= 1'b0;
                    if (start) begin
                        busy     <= 1'b1;
                        src_addr <= SRC_BEGIN;
                        dst_addr <= DST_BEGIN;
                        state    <= S_WAIT_BUS;
                    end
                end

                S_WAIT_BUS: begin
                    if (takeover_grant) begin
                        if (SRC_BEGIN >= SRC_END) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            state <= S_READ_REQ;
                        end
                    end
                end

                S_READ_REQ: begin
                    if (read_request_fire) begin
                        // 兼容 addr_ok/data_ok 同拍的零等待读。
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
                        output_data <= algo_out_data;
                        state       <= S_WRITE_REQ;
                    end
                end

                S_WRITE_REQ: begin
                    if (write_request_fire) begin
                        // 兼容 addr_ok/data_ok 同拍的零等待写。
                        if (mem_data_ok) begin
                            if (current_is_last) begin
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
                        else begin
                            state <= S_WRITE_WAIT;
                        end
                    end
                end

                S_WRITE_WAIT: begin
                    if (mem_data_ok) begin
                        if (current_is_last) begin
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
                    state <= S_IDLE;
                    busy  <= 1'b0;
                end
            endcase
        end
    end

endmodule

`default_nettype wire
