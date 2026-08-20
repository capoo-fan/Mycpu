`ifndef LA32_ARITHMETIC_OPS_VH
`define LA32_ARITHMETIC_OPS_VH

// contest_arithmetic_unit 与其调用方共用的操作编码。
`define LA32_ARITH_OP_UDIV  3'd0 // 无符号除法：返回 a / b 的商。
`define LA32_ARITH_OP_SDIV  3'd1 // 有符号除法：返回 signed(a) / signed(b) 的商。
`define LA32_ARITH_OP_UMOD  3'd2 // 无符号取余：返回 a % b 的余数。
`define LA32_ARITH_OP_SMOD  3'd3 // 有符号取余：返回 signed(a) % signed(b) 的余数。
`define LA32_ARITH_OP_ISQRT 3'd4 // 无符号整数平方根：返回 floor(sqrt(a))。
`define LA32_ARITH_OP_GCD   3'd5 // 无符号最大公约数：返回 gcd(a, b)。

`endif
