`timescale 1ns / 1ps
`include "defines.vh"
module mem_branch_judge(
    input  wire         is_branch_i,         // 是否是分支指令
    input  wire [31:0]  pc_i,                // 分支指令自身的PC
    input  wire         actual_taken_i,      // EX阶段计算出的实际跳转方向
    input  wire [31:0]  actual_target_pc_i,  // EX阶段计算出的实际目标PC
    input  wire         pred_taken_i,        // IF阶段预测的跳转方向
    input  wire [31:0]  pred_target_i,       // IF阶段预测的目标PC

    output wire         flush_o,             // 冲刷流水线信号
    output wire [31:0]  flush_pc_o,          // 正确的下一条指令PC
    output wire         real_taken_o         // 最终的实际跳转方向 (用于BPU更新)
);

    wire [31:0] next_pc = pc_i + 4;
    wire mispredict_direction = (actual_taken_i != pred_taken_i);
    wire mispredict_target    = actual_taken_i && pred_taken_i && (actual_target_pc_i != pred_target_i);
    wire mispredicted = mispredict_direction || mispredict_target;

    assign flush_o = mispredicted ;
    assign flush_pc_o = actual_taken_i ? actual_target_pc_i : next_pc;
    assign real_taken_o = is_branch_i && actual_taken_i;

endmodule
