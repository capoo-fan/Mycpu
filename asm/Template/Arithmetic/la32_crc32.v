`timescale 1ns / 1ps
`default_nettype none

// Iterative LSB-first CRC-32 / CRC-32C core matching LoongArch CRC semantics.
// req_width: 0=8-bit message, 1=16-bit message, 2=32-bit message.
// The initial working value is req_seed XOR zero-extended message.
module la32_crc32 (
    input  wire        clk,
    input  wire        resetn,

    input  wire        req_valid,
    output wire        req_ready,
    input  wire        req_castagnoli,
    input  wire [1:0]  req_width,
    input  wire [31:0] req_message,
    input  wire [31:0] req_seed,

    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [31:0] rsp_checksum,
    output reg         rsp_invalid_width
);

    localparam [31:0] POLY_IEEE       = 32'hedb8_8320;
    localparam [31:0] POLY_CASTAGNOLI = 32'h82f6_3b78;

    reg        running;
    reg [5:0]  bits_remaining;
    reg [31:0] checksum_work;
    reg [31:0] polynomial;

    wire [31:0] next_checksum = checksum_work[0] ?
        ((checksum_work >> 1) ^ polynomial) : (checksum_work >> 1);

    assign req_ready = !running && !rsp_valid;

    always @(posedge clk) begin
        if (!resetn) begin
            running           <= 1'b0;
            bits_remaining    <= 6'b0;
            checksum_work     <= 32'b0;
            polynomial        <= POLY_IEEE;
            rsp_valid         <= 1'b0;
            rsp_checksum      <= 32'b0;
            rsp_invalid_width <= 1'b0;
        end
        else begin
            if (rsp_valid && rsp_ready)
                rsp_valid <= 1'b0;

            if (req_valid && req_ready) begin
                rsp_invalid_width <= 1'b0;
                polynomial <= req_castagnoli ?
                    POLY_CASTAGNOLI : POLY_IEEE;

                case (req_width)
                    2'd0: begin
                        checksum_work  <= req_seed ^
                                          {24'b0, req_message[7:0]};
                        bits_remaining <= 6'd8;
                        running        <= 1'b1;
                    end
                    2'd1: begin
                        checksum_work  <= req_seed ^
                                          {16'b0, req_message[15:0]};
                        bits_remaining <= 6'd16;
                        running        <= 1'b1;
                    end
                    2'd2: begin
                        checksum_work  <= req_seed ^ req_message;
                        bits_remaining <= 6'd32;
                        running        <= 1'b1;
                    end
                    default: begin
                        rsp_checksum      <= 32'b0;
                        rsp_invalid_width <= 1'b1;
                        rsp_valid         <= 1'b1;
                    end
                endcase
            end
            else if (running) begin
                checksum_work <= next_checksum;

                if (bits_remaining == 6'd1) begin
                    running      <= 1'b0;
                    rsp_checksum <= next_checksum;
                    rsp_valid    <= 1'b1;
                end
                else begin
                    bits_remaining <= bits_remaining - 6'd1;
                end
            end
        end
    end

endmodule

`default_nettype wire
