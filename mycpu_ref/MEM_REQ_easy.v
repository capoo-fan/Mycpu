`timescale 1ns / 1ps
`include "defines.vh"
module MEM_REQ_easy (
    input  wire         clk,
    input  wire         rstn,

    // --- 输入: 来自 EX/MEM 寄存器 ---
    input  wire         is_load,
    input  wire         is_store,
    input  wire         ex_valid,           // 流水线该阶段指令是否有效
    input  wire [31:0]  mem_ram_addr,       
    input  wire [ 3:0]  mem_ram_we,        
    input  wire [ 2:0]  mem_ram_ext_op,     
    input  wire [ 1:0]  mem_wd_sel,         

    // --- 输入: 来自主存的状态和数据 ---
    input  wire         dcache_read_valid,  // D-Cache 读数据有效信号
    input  wire [31:0]  dcache_read_data,   // D-Cache 读出的原始数据
    input  wire         dcache_write_valid, // D-Cache/Memory 写操作完成信号

    output wire         suspend,            // 流水线暂停信号

    output wire [3:0]   dcache_read_en,     // D-Cache 读使能
    output wire [ 3:0]  dcache_write_we,    // D-Cache 写字节掩码
    output wire [31:0]  dcache_addr,        // D-Cache 访问地址 (读写共用)
    output wire [31:0]  dcache_waddr,
  
    output wire [31:0]  final_load_data     // 处理后的、送往MEM/WB寄存器的数据
);


    wire [1:0] offset = mem_ram_addr[1:0];
    wire is_word_access = (is_load && mem_ram_ext_op == `RAM_EXT_W) || 
                          (is_store && mem_ram_we == `RAM_WE_W);
                          
    wire is_halfword_access = (is_load && (mem_ram_ext_op == `RAM_EXT_H || mem_ram_ext_op == `RAM_EXT_HU)) ||
                              (is_store && mem_ram_we == `RAM_WE_H);


    assign dcache_read_en  = {4{is_load}};
    assign dcache_addr     = {mem_ram_addr[31:2], 2'b0}; 
    assign dcache_waddr    = {mem_ram_addr[31:2], 2'b0};
    reg [3:0] store_mask_reg;
    always @(*) begin
        case (mem_ram_we)
            `RAM_WE_B: store_mask_reg = 4'b0001 << offset;
            `RAM_WE_H: store_mask_reg = (offset == 2'b0) ? 4'b0011 : 4'b1100;
            `RAM_WE_W: store_mask_reg = 4'b1111;
            default:   store_mask_reg = 4'b0000;
        endcase
    end
    assign dcache_write_we = (is_store) ? store_mask_reg : 4'b0;

    wire suspend_for_load  = is_load  && !dcache_read_valid;
    wire suspend_for_store = is_store  && !dcache_write_valid;

    assign suspend = suspend_for_load || suspend_for_store ;

    reg [31:0] real_din;
    reg [31:0] extended_dcache_data;

    always @(*) begin
        case (offset)
            2'b01:   real_din = { 8'h0, dcache_read_data[31: 8]};
            2'b10:   real_din = {16'h0, dcache_read_data[31:16]};
            2'b11:   real_din = {24'h0, dcache_read_data[31:24]};
            default: real_din = dcache_read_data; // 2'b00
        endcase
    end

    always @(*) begin
        case (mem_ram_ext_op)
            `RAM_EXT_H:  extended_dcache_data = {{16{real_din[15]}}, real_din[15:0]};
            `RAM_EXT_W:  extended_dcache_data = real_din;
            `RAM_EXT_B:  extended_dcache_data = {{24{real_din[7]}},  real_din[7:0]};
            `RAM_EXT_HU: extended_dcache_data = {16'b0, real_din[15:0]};
            `RAM_EXT_BU: extended_dcache_data = {24'b0, real_din[7:0]};
            default:     extended_dcache_data = 32'hdeadbeef; 
        endcase
    end


    assign final_load_data = extended_dcache_data;

endmodule
