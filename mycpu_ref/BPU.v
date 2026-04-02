`timescale 1ns / 1ps
`define BHT_IDX_W   2                    // 行索引位宽 (2^2 4行)
`define BHT_ENTRY   (1 << `BHT_IDX_W)     // 每个Bank的条目数 (4)
`define BHT_TAG_W   18              // tag位宽，使用 PC[22:5]

module BPU ( 
    input  wire         cpu_clk,
    input  wire         cpu_rstn,
    //-- 预测接口  --//
    input  wire [31:0]  if_pc,
    input  wire         if_valid,
    output wire         bj_offset,        
    output wire         pred_taken,
    output wire [31:0]  pred_target,
    //-- 更新接口 --//
    input  wire         update_valid,
    input  wire         target_error,
    input  wire [31:0]  real_pc,
    input  wire         real_taken,
    input  wire [31:0]  real_target
);


reg  [`BHT_TAG_W-1:0]   tag      [1:0][`BHT_ENTRY-1:0];
reg                     valid    [1:0][`BHT_ENTRY-1:0];
reg  [1:0]              counter  [1:0][`BHT_ENTRY-1:0];
reg  [31:0]             target   [1:0][`BHT_ENTRY-1:0];

wire [`BHT_TAG_W-1:0] pred_tag  = if_pc[22:5];
wire [`BHT_IDX_W-1:0] row_index = if_pc[4:3];

//-- 两路并行查找BTB --//
wire hit_s0 = valid[1'b0][row_index] && (tag[1'b0][row_index] == pred_tag);
wire hit_s1 = valid[1'b1][row_index] && (tag[1'b1][row_index] == pred_tag);

wire [31:0] tgt_out_s0 = target[1'b0][row_index];
wire [31:0] tgt_out_s1 = target[1'b1][row_index];

wire [1:0]  counter_s0 = counter[1'b0][row_index];
wire [1:0]  counter_s1 = counter[1'b1][row_index];

wire if_offset = if_pc[2]; 

wire pred_valid_s0 = hit_s0 && counter_s0[1] && !if_offset;
wire pred_valid_s1 = hit_s1 && counter_s1[1];

wire final_pred_taken = pred_valid_s0 | pred_valid_s1;
assign pred_taken = final_pred_taken;

assign bj_offset = pred_valid_s0 ? 1'b0 : 1'b1; 


wire [31:0] npc_block = {if_pc[31:3]+1, 3'b000} ;

assign pred_target = final_pred_taken ? 
                     (pred_valid_s0 ? tgt_out_s0 : tgt_out_s1)
                     : npc_block;

// 根据新的地址映射计算更新地址和Tag
wire [`BHT_TAG_W-1:0] update_tag_s1       = real_pc[22:5];
wire                  update_bank_sel_s1  = real_pc[2]; 
wire [`BHT_IDX_W-1:0] update_row_index_s1 = real_pc[4:3];

// 从存储阵列中读出旧数据
wire                  read_valid_s1       = valid[update_bank_sel_s1][update_row_index_s1];
wire [`BHT_TAG_W-1:0] read_tag_s1         = tag[update_bank_sel_s1][update_row_index_s1];
wire [1:0]            read_counter_s1     = counter[update_bank_sel_s1][update_row_index_s1];


reg                     update_valid_s2;
reg [`BHT_TAG_W-1:0]    update_tag_s2;
reg                     update_bank_sel_s2; 
reg [`BHT_IDX_W-1:0]    update_row_index_s2;
reg                     real_taken_s2;
reg [31:0]              real_target_s2;
reg                     target_error_s2;
reg                     read_valid_s2;
reg [`BHT_TAG_W-1:0]    read_tag_s2;
reg [1:0]               read_counter_s2;

always @(posedge cpu_clk or negedge cpu_rstn) begin
    if (!cpu_rstn) begin
        update_valid_s2 <= 1'b0;
    end else begin
        update_valid_s2 <= update_valid; 
        if (update_valid) begin
            update_tag_s2       <= update_tag_s1;
            update_bank_sel_s2  <= update_bank_sel_s1;
            update_row_index_s2 <= update_row_index_s1;
            real_taken_s2       <= real_taken;
            real_target_s2      <= real_target;
            target_error_s2     <= target_error;
            read_valid_s2       <= read_valid_s1;
            read_tag_s2         <= read_tag_s1;
            read_counter_s2     <= read_counter_s1;
        end
    end
end


wire update_hit_s2 = read_valid_s2 && (read_tag_s2 == update_tag_s2);
wire [1:0] next_counter_s2;
assign next_counter_s2 = 
    (read_counter_s2 == 2'b00) ? (real_taken_s2 ? 2'b01 : 2'b00) :
    (read_counter_s2 == 2'b01) ? (real_taken_s2 ? 2'b10 : 2'b00) :
    (read_counter_s2 == 2'b10) ? (real_taken_s2 ? 2'b11 : 2'b01) :
                                 (real_taken_s2 ? 2'b11 : 2'b10);


integer i, j;
always @(posedge cpu_clk or negedge cpu_rstn) begin
    if (!cpu_rstn) begin
        for (i = 0; i < 2; i = i + 1) begin
            for (j = 0; j < `BHT_ENTRY; j = j + 1) begin
                valid[i][j]   <= 1'b0;
                tag[i][j]     <= 0;
                target[i][j]  <= 0;
                counter[i][j] <= 2'b01; // 初始化为弱不跳转
            end
        end
    end 
    else if (update_valid_s2) begin
        if (update_hit_s2) begin
            counter[update_bank_sel_s2][update_row_index_s2] <= next_counter_s2;          
            if (target_error_s2) begin
                target[update_bank_sel_s2][update_row_index_s2] <= real_target_s2;
            end
        end
        else if (real_taken_s2) begin
            valid[update_bank_sel_s2][update_row_index_s2]   <= 1'b1;
            tag[update_bank_sel_s2][update_row_index_s2]     <= update_tag_s2;
            target[update_bank_sel_s2][update_row_index_s2]  <= real_target_s2;
            counter[update_bank_sel_s2][update_row_index_s2] <= 2'b10;
        end
    end
end

endmodule
