`timescale 1ns / 1ps
`include "defines.vh"

module EX_MEM (
    input  wire         cpu_clk,
    input  wire         cpu_rstn,
    input  wire         flush,
    input  wire         suspend,
    input  wire         ex_suspend,     
    input  wire         valid_in,

    input  wire[4:0]    wR_in,
    input  wire[31:0]   pc_in,
    input  wire[31:0]   alu_C_in,
    input  wire[31:0]   rD2_in,

    input  wire         rf_we_in,
    input  wire[1:0]    wd_sel_in,
    input  wire[3:0]    ram_we_in,
    input  wire[2:0]    ram_ext_op_in,

    output reg          valid_out,
    output reg [4:0]    wR_out,
    output reg [31:0]   pc_out,
    output reg [31:0]   alu_C_out,
    output reg [31:0]   rD2_out,

    output reg          rf_we_out,
    output reg [1:0]    wd_sel_out,
    output reg [3:0]    ram_we_out,
    output reg [2:0]    ram_ext_op_out,
    
    input  wire         is_load,
    input  wire         is_store,
    output reg          is_load_out,
    output reg          is_store_out,
    
    input  wire         is_branch_in,
    input  wire         actual_taken_in,
    input  wire [31:0]  actual_target_pc_in,
    input  wire         pred_taken_in,
    input  wire [31:0]  pred_target_in,    
    
    output reg          is_branch_out,
    output reg          actual_taken_out,
    output reg [31:0]   actual_target_pc_out,
    output reg          pred_taken_out,
    output reg [31:0]   pred_target_out
);

always @(posedge cpu_clk) begin
    // 逻辑优先级: 1. 复位 -> 2. 全局暂停 -> 3. EX阶段暂停(插入气泡) -> 4. 正常传递
    valid_out      <= !cpu_rstn ?  1'h0 : suspend ? valid_out      : (ex_suspend || flush) ? 1'h0 : valid_in;
    wR_out         <= !cpu_rstn ?  5'h0 : suspend ? wR_out         : (ex_suspend || flush) ? 5'h0 : wR_in;
    pc_out         <= !cpu_rstn ? 32'h0 : suspend ? pc_out         : (ex_suspend || flush) ? 32'h0 : pc_in;
    alu_C_out      <= !cpu_rstn ? 32'h0 : suspend ? alu_C_out      : (ex_suspend || flush) ? 32'h0 : alu_C_in;
    rD2_out        <= !cpu_rstn ? 32'h0 : suspend ? rD2_out        : (ex_suspend || flush) ? 32'h0 : rD2_in;
    rf_we_out      <= !cpu_rstn ?  1'h0 : suspend ? rf_we_out      : (ex_suspend || flush) ? 1'h0 : rf_we_in;
    wd_sel_out     <= !cpu_rstn ?  2'h0 : suspend ? wd_sel_out     : (ex_suspend || flush) ? 2'h0 : wd_sel_in;
    ram_we_out     <= !cpu_rstn ?  4'h0 : suspend ? ram_we_out     : (ex_suspend || flush) ? 4'h0 : ram_we_in;
    ram_ext_op_out <= !cpu_rstn ?  3'h0 : suspend ? ram_ext_op_out : (ex_suspend || flush) ? 3'h0 : ram_ext_op_in;
    is_load_out      <= !cpu_rstn ?  1'h0 : suspend ? is_load_out      : (ex_suspend || flush) ? 1'h0 : is_load;    
    is_store_out      <= !cpu_rstn ?  1'h0 : suspend ? is_store_out      : (ex_suspend || flush) ? 1'h0 : is_store;   

    is_branch_out          <= !cpu_rstn ? 1'b0  : suspend ? is_branch_out          : (ex_suspend || flush) ? 1'b0  : is_branch_in;
    actual_taken_out       <= !cpu_rstn ? 1'b0  : suspend ? actual_taken_out       : (ex_suspend || flush) ? 1'b0  : actual_taken_in;
    actual_target_pc_out   <= !cpu_rstn ? 32'b0 : suspend ? actual_target_pc_out   : (ex_suspend || flush) ? 32'b0 : actual_target_pc_in;
    pred_taken_out         <= !cpu_rstn ? 1'b0  : suspend ? pred_taken_out         : (ex_suspend || flush) ? 1'b0  : pred_taken_in;
    pred_target_out        <= !cpu_rstn ? 32'b0 : suspend ? pred_target_out        : (ex_suspend || flush) ? 32'b0 : pred_target_in;  
end

endmodule
