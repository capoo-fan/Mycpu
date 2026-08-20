`timescale 1ns / 1ps
`default_nettype none
`include "la32_function_ops.vh"

module tb_arithmetic_accelerator_logic;

    localparam INTEGER_OPERATION_COUNT = 37;

    reg clk;
    reg resetn;
    reg  [INTEGER_OPERATION_COUNT-1:0] in_valid;
    reg  [31:0] in_data [0:INTEGER_OPERATION_COUNT-1];
    wire [INTEGER_OPERATION_COUNT-1:0] in_ready;
    wire [INTEGER_OPERATION_COUNT-1:0] out_valid;
    wire [31:0] out_data [0:INTEGER_OPERATION_COUNT-1];

`define CONNECT_OPERATION(INDEX, OPERATION_VALUE, OPERAND_B_VALUE, LSB_VALUE, MSB_VALUE, AUX_VALUE) \
    accelerator_logic #( \
        .OPERATION     (OPERATION_VALUE), \
        .OPERAND_B     (OPERAND_B_VALUE), \
        .CONTROL_LSB   (LSB_VALUE), \
        .CONTROL_MSB   (MSB_VALUE), \
        .USE_AUXILIARY (AUX_VALUE) \
    ) u_operation_``INDEX ( \
        .clk       (clk), \
        .resetn    (resetn), \
        .in_valid  (in_valid[INDEX]), \
        .in_ready  (in_ready[INDEX]), \
        .in_data   (in_data[INDEX]), \
        .out_valid (out_valid[INDEX]), \
        .out_data  (out_data[INDEX]) \
    );

    `CONNECT_OPERATION(0,  `LA32_FUNC_OP_UDIV,       32'd7,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(1,  `LA32_FUNC_OP_SDIV,       -32'sd7,        5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(2,  `LA32_FUNC_OP_UMOD,       32'd13,         5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(3,  `LA32_FUNC_OP_SMOD,       32'd7,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(4,  `LA32_FUNC_OP_ISQRT,      32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(5,  `LA32_FUNC_OP_GCD,        32'd48,         5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(6,  `LA32_FUNC_OP_CLZ,        32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(7,  `LA32_FUNC_OP_CLO,        32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(8,  `LA32_FUNC_OP_CTZ,        32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(9,  `LA32_FUNC_OP_CTO,        32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(10, `LA32_FUNC_OP_POPCOUNT,   32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(11, `LA32_FUNC_OP_ROTR,       32'd0,          5'd8,  5'd0,  1'b0)
    `CONNECT_OPERATION(12, `LA32_FUNC_OP_BITREV_W,   32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(13, `LA32_FUNC_OP_BITREV_4B,  32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(14, `LA32_FUNC_OP_REVB_2H,    32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(15, `LA32_FUNC_OP_BYTEPICK_W, 32'haabb_ccdd,  5'd2,  5'd0,  1'b0)
    `CONNECT_OPERATION(16, `LA32_FUNC_OP_BSTRPICK_W, 32'd0,          5'd8,  5'd15, 1'b0)
    `CONNECT_OPERATION(17, `LA32_FUNC_OP_BSTRINS_W,  32'h1234_5678,  5'd8,  5'd15, 1'b0)
    `CONNECT_OPERATION(18, `LA32_FUNC_OP_MULU_FULL,  32'hffff_ffff,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(19, `LA32_FUNC_OP_MULS_FULL,  32'hffff_ffff,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(20, `LA32_FUNC_OP_CRC32_B,    32'h89ab_cdef,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(21, `LA32_FUNC_OP_CRC32_H,    32'h89ab_cdef,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(22, `LA32_FUNC_OP_CRC32_W,    32'h89ab_cdef,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(23, `LA32_FUNC_OP_CRC32C_B,   32'h89ab_cdef,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(24, `LA32_FUNC_OP_CRC32C_H,   32'h89ab_cdef,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(25, `LA32_FUNC_OP_CRC32C_W,   32'h89ab_cdef,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(26, `LA32_FUNC_OP_ANDN,       32'h0f0f_0f0f,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(27, `LA32_FUNC_OP_ORN,        32'h0f0f_0f0f,  5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(28, `LA32_FUNC_OP_MASKEQZ,    32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(29, `LA32_FUNC_OP_MASKNEZ,    32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(30, `LA32_FUNC_OP_ALSL,       32'd5,          5'd3,  5'd0,  1'b0)
    `CONNECT_OPERATION(31, `LA32_FUNC_OP_EXT_W_B,    32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(32, `LA32_FUNC_OP_EXT_W_H,    32'd0,          5'd0,  5'd0,  1'b0)
    `CONNECT_OPERATION(33, `LA32_FUNC_OP_UDIV,       32'd7,          5'd0,  5'd0,  1'b1)
    `CONNECT_OPERATION(34, `LA32_FUNC_OP_ISQRT,      32'd0,          5'd0,  5'd0,  1'b1)
    `CONNECT_OPERATION(35, `LA32_FUNC_OP_MULU_FULL,  32'hffff_ffff,  5'd0,  5'd0,  1'b1)
    `CONNECT_OPERATION(36, 8'hff,                    32'd0,          5'd0,  5'd0,  1'b0)

`undef CONNECT_OPERATION

    always #5 clk = ~clk;

    function [31:0] crc_reference;
        input [31:0] message;
        input [31:0] seed;
        input [5:0]  bit_count;
        input [31:0] polynomial;
        reg [31:0] work;
        integer bit_index;
        begin
            case (bit_count)
                6'd8:  work = seed ^ {24'b0, message[7:0]};
                6'd16: work = seed ^ {16'b0, message[15:0]};
                default: work = seed ^ message;
            endcase

            for (bit_index = 0; bit_index < bit_count;
                 bit_index = bit_index + 1) begin
                if (work[0])
                    work = (work >> 1) ^ polynomial;
                else
                    work = work >> 1;
            end

            crc_reference = work;
        end
    endfunction

    task check_result;
        input integer which;
        input [31:0] input_value;
        input [31:0] expected_value;
        integer cycles;
        begin
            @(negedge clk);
            while (!in_ready[which])
                @(negedge clk);

            in_data[which] = input_value;
            in_valid[which] = 1'b1;
            @(negedge clk);
            in_valid[which] = 1'b0;

            cycles = 0;
            while (!out_valid[which] && (cycles < 200)) begin
                @(negedge clk);
                cycles = cycles + 1;
            end

            if (!out_valid[which])
                $fatal(1, "operation index %0d timed out", which);
            if (out_data[which] !== expected_value)
                $fatal(1, "operation index %0d input=%h expected=%h actual=%h",
                       which, input_value, expected_value, out_data[which]);
        end
    endtask

    integer index;
    reg [31:0] crc_message;
    initial begin
        clk = 1'b0;
        resetn = 1'b0;
        in_valid = {INTEGER_OPERATION_COUNT{1'b0}};
        crc_message = 32'h1234_5678;

        for (index = 0; index < INTEGER_OPERATION_COUNT; index = index + 1)
            in_data[index] = 32'b0;

        repeat (3) @(negedge clk);
        resetn = 1'b1;

        check_result(0,  32'd100,       32'd14);
        check_result(1,  -32'sd100,     32'd14);
        check_result(2,  32'd100,       32'd9);
        check_result(3,  -32'sd100,     -32'sd2);
        check_result(4,  32'hffff_ffff, 32'd65535);
        check_result(5,  32'd18,        32'd6);
        check_result(6,  32'h0000_0010, 32'd27);
        check_result(7,  32'hffff_0fff, 32'd16);
        check_result(8,  32'h0000_0100, 32'd8);
        check_result(9,  32'h0000_0007, 32'd3);
        check_result(10, 32'hf0f0_5555, 32'd16);
        check_result(11, 32'h1234_5678, 32'h7812_3456);
        check_result(12, 32'h0000_0001, 32'h8000_0000);
        check_result(13, 32'h0123_4567, 32'h80c4_a2e6);
        check_result(14, 32'h1122_3344, 32'h2211_4433);
        check_result(15, 32'h1122_3344, 32'hccdd_1122);
        check_result(16, 32'hdead_beef, 32'h0000_00be);
        check_result(17, 32'hdead_beef, 32'hdead_78ef);
        check_result(18, 32'hffff_ffff, 32'h0000_0001);
        check_result(19, 32'h8000_0000, 32'h8000_0000);
        check_result(20, crc_message,
                     crc_reference(crc_message, 32'h89ab_cdef, 6'd8,
                                   32'hedb8_8320));
        check_result(21, crc_message,
                     crc_reference(crc_message, 32'h89ab_cdef, 6'd16,
                                   32'hedb8_8320));
        check_result(22, crc_message,
                     crc_reference(crc_message, 32'h89ab_cdef, 6'd32,
                                   32'hedb8_8320));
        check_result(23, crc_message,
                     crc_reference(crc_message, 32'h89ab_cdef, 6'd8,
                                   32'h82f6_3b78));
        check_result(24, crc_message,
                     crc_reference(crc_message, 32'h89ab_cdef, 6'd16,
                                   32'h82f6_3b78));
        check_result(25, crc_message,
                     crc_reference(crc_message, 32'h89ab_cdef, 6'd32,
                                   32'h82f6_3b78));
        check_result(26, 32'hffff_00ff, 32'hf0f0_00f0);
        check_result(27, 32'h0000_00ff, 32'hf0f0_f0ff);
        check_result(28, 32'h1234_5678, 32'b0);
        check_result(29, 32'h1234_5678, 32'h1234_5678);
        check_result(30, 32'h0000_0010, 32'h0000_0105);
        check_result(31, 32'h0000_0080, 32'hffff_ff80);
        check_result(32, 32'h0000_8000, 32'hffff_8000);
        check_result(33, 32'd100,       32'd2);
        check_result(34, 32'hffff_ffff, 32'h0001_fffe);
        check_result(35, 32'hffff_ffff, 32'hffff_fffe);
        check_result(36, 32'h1234_5678, 32'b0);

        $display("PASS unified accelerator_logic operations=%0d",
                 INTEGER_OPERATION_COUNT);
        $finish;
    end

endmodule

`default_nettype wire
