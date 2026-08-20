`ifndef LA32_FUNCTION_OPS_VH
`define LA32_FUNCTION_OPS_VH

// 算术操作保持与 la32_arithmetic_ops.vh 相同的数值，并零扩展到统一的 8 位操作端口。
`define LA32_FUNC_OP_UDIV       8'h00 // 无符号除法，结果为商，辅助结果为余数。
`define LA32_FUNC_OP_SDIV       8'h01 // 有符号除法，结果为商，辅助结果为余数。
`define LA32_FUNC_OP_UMOD       8'h02 // 无符号取余，结果为余数，辅助结果为商。
`define LA32_FUNC_OP_SMOD       8'h03 // 有符号取余，结果为余数，辅助结果为商。
`define LA32_FUNC_OP_ISQRT      8'h04 // 无符号整数平方根，结果向下取整。
`define LA32_FUNC_OP_GCD        8'h05 // 计算两个无符号 32 位数的最大公约数。

// LA32S 计数操作和面向竞赛的置位计数操作。
`define LA32_FUNC_OP_CLZ        8'h08 // 从最高位起统计连续 0 的个数。
`define LA32_FUNC_OP_CLO        8'h09 // 从最高位起统计连续 1 的个数。
`define LA32_FUNC_OP_CTZ        8'h0a // 从最低位起统计连续 0 的个数。
`define LA32_FUNC_OP_CTO        8'h0b // 从最低位起统计连续 1 的个数。
`define LA32_FUNC_OP_POPCOUNT   8'h0c // 统计 32 位操作数中 1 的总数。

// 移位与重排操作。
`define LA32_FUNC_OP_ROTR       8'h10 // 32 位循环右移。
`define LA32_FUNC_OP_BITREV_W   8'h11 // 反转完整字的 32 位位序。
`define LA32_FUNC_OP_BITREV_4B  8'h12 // 分别反转四个字节内部的位序。
`define LA32_FUNC_OP_REVB_2H    8'h13 // 分别交换两个半字内部的字节。
`define LA32_FUNC_OP_BYTEPICK_W 8'h14 // 从两个字的拼接值中选取四字节窗口。

// 位域操作。
`define LA32_FUNC_OP_BSTRPICK_W 8'h18 // 提取并右对齐指定的连续位域。
`define LA32_FUNC_OP_BSTRINS_W  8'h19 // 将低位数据插入指定的连续位域。

// 完整的 32x32→64 位乘积。
`define LA32_FUNC_OP_MULU_FULL  8'h20 // 计算无符号 32x32 位完整乘积。
`define LA32_FUNC_OP_MULS_FULL  8'h21 // 计算有符号 32x32 位完整乘积。

// IEEE 802.3 CRC-32 和 CRC-32C（Castagnoli），最低位优先。
`define LA32_FUNC_OP_CRC32_B    8'h28 // IEEE CRC-32，处理消息低 8 位。
`define LA32_FUNC_OP_CRC32_H    8'h29 // IEEE CRC-32，处理消息低 16 位。
`define LA32_FUNC_OP_CRC32_W    8'h2a // IEEE CRC-32，处理消息完整 32 位。
`define LA32_FUNC_OP_CRC32C_B   8'h2c // CRC-32C，处理消息低 8 位。
`define LA32_FUNC_OP_CRC32C_H   8'h2d // CRC-32C，处理消息低 16 位。
`define LA32_FUNC_OP_CRC32C_W   8'h2e // CRC-32C，处理消息完整 32 位。

// 小型 LA32S 逻辑/地址生成辅助操作。
`define LA32_FUNC_OP_ANDN       8'h30 // a & ~b。
`define LA32_FUNC_OP_ORN        8'h31 // a | ~b。
`define LA32_FUNC_OP_MASKEQZ    8'h32 // b=0 时清零，否则返回 a。
`define LA32_FUNC_OP_MASKNEZ    8'h33 // b!=0 时清零，否则返回 a。
`define LA32_FUNC_OP_ALSL       8'h34 // (a << (sa+1)) + b，sa 范围为 0～3。
`define LA32_FUNC_OP_EXT_W_B    8'h35 // 将 a[7:0] 符号扩展为 32 位。
`define LA32_FUNC_OP_EXT_W_H    8'h36 // 将 a[15:0] 符号扩展为 32 位。

`endif
