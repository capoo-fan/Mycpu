`ifndef LA32_FUNCTION_OPS_VH
`define LA32_FUNCTION_OPS_VH

// Arithmetic operations keep the same numeric values as
// la32_arithmetic_ops.vh, zero-extended to the unified 8-bit operation port.
`define LA32_FUNC_OP_UDIV       8'h00
`define LA32_FUNC_OP_SDIV       8'h01
`define LA32_FUNC_OP_UMOD       8'h02
`define LA32_FUNC_OP_SMOD       8'h03
`define LA32_FUNC_OP_ISQRT      8'h04
`define LA32_FUNC_OP_GCD        8'h05

// LA32S count and contest-oriented population count operations.
`define LA32_FUNC_OP_CLZ        8'h08
`define LA32_FUNC_OP_CLO        8'h09
`define LA32_FUNC_OP_CTZ        8'h0a
`define LA32_FUNC_OP_CTO        8'h0b
`define LA32_FUNC_OP_POPCOUNT   8'h0c

// Shift and permutation operations.
`define LA32_FUNC_OP_ROTR       8'h10
`define LA32_FUNC_OP_BITREV_W   8'h11
`define LA32_FUNC_OP_BITREV_4B  8'h12
`define LA32_FUNC_OP_REVB_2H    8'h13
`define LA32_FUNC_OP_BYTEPICK_W 8'h14

// Bit-field operations.
`define LA32_FUNC_OP_BSTRPICK_W 8'h18
`define LA32_FUNC_OP_BSTRINS_W  8'h19

// Full 32x32 -> 64-bit products.
`define LA32_FUNC_OP_MULU_FULL  8'h20
`define LA32_FUNC_OP_MULS_FULL  8'h21

// IEEE 802.3 CRC-32 and CRC-32C (Castagnoli), LSB-first.
`define LA32_FUNC_OP_CRC32_B    8'h28
`define LA32_FUNC_OP_CRC32_H    8'h29
`define LA32_FUNC_OP_CRC32_W    8'h2a
`define LA32_FUNC_OP_CRC32C_B   8'h2c
`define LA32_FUNC_OP_CRC32C_H   8'h2d
`define LA32_FUNC_OP_CRC32C_W   8'h2e

// Small LA32S logic/address-generation helpers.
`define LA32_FUNC_OP_ANDN       8'h30
`define LA32_FUNC_OP_ORN        8'h31
`define LA32_FUNC_OP_MASKEQZ    8'h32
`define LA32_FUNC_OP_MASKNEZ    8'h33
`define LA32_FUNC_OP_ALSL       8'h34
`define LA32_FUNC_OP_EXT_W_B    8'h35
`define LA32_FUNC_OP_EXT_W_H    8'h36

`endif
