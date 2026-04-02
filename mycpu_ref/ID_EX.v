`timescale 1ns / 1ps
`include "defines.vh"

module ID_EX (
    input  wire         cpu_clk,
    input  wire         cpu_rstn,
    input  wire         flush,           // 高优先级冲刷信号
    input  wire         suspend,         // 暂停/停顿信号
    input  wire         valid_in,
    input  wire         load_use_i,      // 低优先级气泡信号

    input  wire[4:0]    wR_in,
    input  wire[31:0]   pc_in,
    input  wire[31:0]   rD1_in,
    input  wire[31:0]   rD2_in,
    input  wire[31:0]   ext_in,

    input  wire         rf_we_in,
    input  wire[1:0]    wd_sel_in,
    input  wire[4:0]    alu_op_in,
    input  wire         alua_sel_in,
    input  wire         alub_sel_in,
    input  wire[3:0]    ram_we_in,
    input  wire[2:0]    ram_ext_op_in,
    
    output reg          valid_out,
    output reg [4:0]    wR_out,
    output reg [31:0]   pc_out,
    output reg [31:0]   rD1_out,
    output reg [31:0]   rD2_out,
    output reg [31:0]   ext_out,

    output reg          rf_we_out,
    output reg [1:0]    wd_sel_out,
    output reg [4:0]    alu_op_out,
    output reg          alua_sel_out,
    output reg          alub_sel_out,
    output reg [3:0]    ram_we_out,
    output reg [2:0]    ram_ext_op_out,
    
    input  wire         pred_taken,
    input  wire [31:0]  pred_target,
    output reg          pred_taken_o,
    output reg [31:0]  pred_target_o,
    
    input  wire         is_branch,
    output reg          is_branch_o,
    

    input  wire         is_load,
    input  wire         is_store,
    input  wire         is_mult,

    output reg          is_load_o,
    output reg          is_store_o,
    output reg          is_mult_o,
    
    input  wire         load_use_rd0_in,
    input  wire         load_use_rd1_in,
        
    output reg          load_use_rd0_out,
    output reg          load_use_rd1_out
);

always @(posedge cpu_clk) begin
    // 逻辑优先级: 1. 复位 -> 2. flush冲刷 -> 3. 暂停 -> 4. load_use插入气泡 -> 5. 正常传递
    valid_out      <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? valid_out      : load_use_i ? 1'b0 : valid_in;
    wR_out         <= !cpu_rstn ? 5'h0 : flush ? 5'h0 : suspend ? wR_out         : load_use_i ? 5'h0 : wR_in;
    pc_out         <= !cpu_rstn ? 32'h0: flush ? 32'h0: suspend ? pc_out         : load_use_i ? 32'h0: pc_in;
    rD1_out        <= !cpu_rstn ? 32'h0: flush ? 32'h0: suspend ? rD1_out        : load_use_i ? 32'h0: rD1_in;
    rD2_out        <= !cpu_rstn ? 32'h0: flush ? 32'h0: suspend ? rD2_out        : load_use_i ? 32'h0: rD2_in;
    ext_out        <= !cpu_rstn ? 32'h0: flush ? 32'h0: suspend ? ext_out        : load_use_i ? 32'h0: ext_in;
    rf_we_out      <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? rf_we_out      : load_use_i ? 1'b0 : rf_we_in;
    wd_sel_out     <= !cpu_rstn ? 2'h0 : flush ? 2'h0 : suspend ? wd_sel_out     : load_use_i ? 2'h0 : wd_sel_in;
    alu_op_out     <= !cpu_rstn ? 5'h0 : flush ? 5'h0 : suspend ? alu_op_out     : load_use_i ? 5'h0 : alu_op_in;
    alua_sel_out   <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? alua_sel_out   : load_use_i ? 1'b0 : alua_sel_in;
    alub_sel_out   <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? alub_sel_out   : load_use_i ? 1'b0 : alub_sel_in;
    ram_we_out     <= !cpu_rstn ? 4'h0 : flush ? 4'h0 : suspend ? ram_we_out     : load_use_i ? 4'h0 : ram_we_in;
    ram_ext_op_out <= !cpu_rstn ? 3'h0 : flush ? 3'h0 : suspend ? ram_ext_op_out : load_use_i ? 3'h0 : ram_ext_op_in;
    pred_taken_o   <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? pred_taken_o   : load_use_i ? 1'b0 : pred_taken;
    pred_target_o  <= !cpu_rstn ? 32'h0: flush ? 32'h0: suspend ? pred_target_o  : load_use_i ? 32'h0: pred_target;
    is_branch_o    <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? is_branch_o    : load_use_i ? 1'b0 : is_branch;
    is_load_o      <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? is_load_o      : load_use_i ? 1'b0 : is_load;
    is_store_o     <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? is_store_o     : load_use_i ? 1'b0 : is_store;
    is_mult_o      <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? is_mult_o      : load_use_i ? 1'b0 : is_mult;
    
    // 新增的 load use hazard 信号寄存
    load_use_rd0_out <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? load_use_rd0_out : load_use_i ? 1'b0 : load_use_rd0_in;
    load_use_rd1_out <= !cpu_rstn ? 1'b0 : flush ? 1'b0 : suspend ? load_use_rd1_out : load_use_i ? 1'b0 : load_use_rd1_in;
end

endmodule
