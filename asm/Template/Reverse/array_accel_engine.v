`timescale 1ns / 1ps
`default_nettype none

// ============================================================================
// array_accel_engine.v -- 32-bit word array in-place reverse accelerator
//
// Reverses the word order in [ARRAY_BEGIN, ARRAY_END):
//
//   before: A[0], A[1], ... A[n-2], A[n-1]
//   after : A[n-1], A[n-2], ... A[1], A[0]
//
// Each pair is processed in the only overwrite-safe order:
//   read left -> read right -> write right_data to left
//             -> write left_data to right
//
// The engine allows at most one outstanding memory transaction.  A request and
// all of its payload remain stable until mem_addr_ok.  Both normal delayed
// responses and an addr_ok/data_ok response in the request cycle are supported.
// ARRAY_BEGIN/ARRAY_END are physical, word-aligned byte addresses; ARRAY_END is
// exclusive.  RESULT_ADDR is retained for drop-in compatibility with the Map
// and Reduction templates and must equal ARRAY_BEGIN.
// ============================================================================

module array_accel_engine #(
    parameter [31:0] ARRAY_BEGIN = 32'h1c40_0000,
    parameter [31:0] ARRAY_END   = 32'h1c50_0000,
    parameter [31:0] RESULT_ADDR = ARRAY_BEGIN
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

    localparam [3:0]
        S_IDLE             = 4'd0,
        S_WAIT_BUS         = 4'd1,
        S_READ_LEFT_REQ    = 4'd2,
        S_READ_LEFT_WAIT   = 4'd3,
        S_READ_RIGHT_REQ   = 4'd4,
        S_READ_RIGHT_WAIT  = 4'd5,
        S_WRITE_LEFT_REQ   = 4'd6,
        S_WRITE_LEFT_WAIT  = 4'd7,
        S_WRITE_RIGHT_REQ  = 4'd8,
        S_WRITE_RIGHT_WAIT = 4'd9;

    reg [3:0]  state;
    reg [31:0] left_addr;
    reg [31:0] right_addr;
    reg [31:0] left_data;
    reg [31:0] right_data;

    assign takeover_req = busy;

    always @(*) begin
        mem_req   = 1'b0;
        mem_wr    = 1'b0;
        mem_size  = 2'b10;
        mem_wstrb = 4'b0000;
        mem_addr  = 32'b0;
        mem_wdata = 32'b0;

        if (takeover_grant) begin
            case (state)
                S_READ_LEFT_REQ: begin
                    mem_req  = 1'b1;
                    mem_addr = left_addr;
                end

                S_READ_RIGHT_REQ: begin
                    mem_req  = 1'b1;
                    mem_addr = right_addr;
                end

                S_WRITE_LEFT_REQ: begin
                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;
                    mem_wstrb = 4'b1111;
                    mem_addr  = left_addr;
                    mem_wdata = right_data;
                end

                S_WRITE_RIGHT_REQ: begin
                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;
                    mem_wstrb = 4'b1111;
                    mem_addr  = right_addr;
                    mem_wdata = left_data;
                end

                default: begin
                end
            endcase
        end
    end

    wire request_fire = mem_req && mem_addr_ok;

    // After the current pair is written, another pair exists exactly when
    // (left_addr + 4) < (right_addr - 4), i.e. current distance > 8 bytes.
    wire current_is_last_pair = ((right_addr - left_addr) <= 32'd8);

    always @(posedge clk) begin
        if (!resetn) begin
            state      <= S_IDLE;
            busy       <= 1'b0;
            done       <= 1'b0;
            left_addr  <= ARRAY_BEGIN;
            right_addr <= ARRAY_BEGIN;
            left_data  <= 32'b0;
            right_data <= 32'b0;
        end
        else begin
            done <= 1'b0;

            case (state)
                S_IDLE: begin
                    busy <= 1'b0;
                    if (start) begin
                        busy       <= 1'b1;
                        left_addr  <= ARRAY_BEGIN;
                        right_addr <= ARRAY_BEGIN;
                        state      <= S_WAIT_BUS;
                    end
                end

                S_WAIT_BUS: begin
                    if (takeover_grant) begin
                        // Empty and one-word arrays are already reversed.
                        if ((ARRAY_END <= ARRAY_BEGIN) ||
                            ((ARRAY_END - ARRAY_BEGIN) < 32'd8)) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            left_addr  <= ARRAY_BEGIN;
                            right_addr <= ARRAY_END - 32'd4;
                            state      <= S_READ_LEFT_REQ;
                        end
                    end
                end

                S_READ_LEFT_REQ: begin
                    if (request_fire) begin
                        if (mem_data_ok) begin
                            left_data <= mem_rdata;
                            state     <= S_READ_RIGHT_REQ;
                        end
                        else begin
                            state <= S_READ_LEFT_WAIT;
                        end
                    end
                end

                S_READ_LEFT_WAIT: begin
                    if (mem_data_ok) begin
                        left_data <= mem_rdata;
                        state     <= S_READ_RIGHT_REQ;
                    end
                end

                S_READ_RIGHT_REQ: begin
                    if (request_fire) begin
                        if (mem_data_ok) begin
                            right_data <= mem_rdata;
                            state      <= S_WRITE_LEFT_REQ;
                        end
                        else begin
                            state <= S_READ_RIGHT_WAIT;
                        end
                    end
                end

                S_READ_RIGHT_WAIT: begin
                    if (mem_data_ok) begin
                        right_data <= mem_rdata;
                        state      <= S_WRITE_LEFT_REQ;
                    end
                end

                S_WRITE_LEFT_REQ: begin
                    if (request_fire) begin
                        state <= mem_data_ok ? S_WRITE_RIGHT_REQ :
                                              S_WRITE_LEFT_WAIT;
                    end
                end

                S_WRITE_LEFT_WAIT: begin
                    if (mem_data_ok)
                        state <= S_WRITE_RIGHT_REQ;
                end

                S_WRITE_RIGHT_REQ: begin
                    if (request_fire) begin
                        if (mem_data_ok) begin
                            if (current_is_last_pair) begin
                                busy  <= 1'b0;
                                done  <= 1'b1;
                                state <= S_IDLE;
                            end
                            else begin
                                left_addr  <= left_addr + 32'd4;
                                right_addr <= right_addr - 32'd4;
                                state      <= S_READ_LEFT_REQ;
                            end
                        end
                        else begin
                            state <= S_WRITE_RIGHT_WAIT;
                        end
                    end
                end

                S_WRITE_RIGHT_WAIT: begin
                    if (mem_data_ok) begin
                        if (current_is_last_pair) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            left_addr  <= left_addr + 32'd4;
                            right_addr <= right_addr - 32'd4;
                            state      <= S_READ_LEFT_REQ;
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

`ifndef SYNTHESIS
    initial begin
        if (ARRAY_BEGIN[1:0] != 2'b00)
            $error("Reverse ARRAY_BEGIN must be word aligned");
        if (ARRAY_END[1:0] != 2'b00)
            $error("Reverse ARRAY_END must be word aligned");
        if (ARRAY_END < ARRAY_BEGIN)
            $error("Reverse ARRAY_END must not precede ARRAY_BEGIN");
        if (RESULT_ADDR != ARRAY_BEGIN)
            $error("Reverse is in-place: RESULT_ADDR must equal ARRAY_BEGIN");
    end
`endif

endmodule

`default_nettype wire
