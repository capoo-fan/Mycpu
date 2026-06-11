`include "mycpu.vh"

module BPU (
    input  wire         clk,
    input  wire         resetn,
    // 预测接口
    input  wire [31:0]  if_pc,
    input  wire         if_valid,
    input  wire         id_valid,
    input  wire         pl_suspend,
    output wire         pred_taken_0,
    output wire [31:0]  pred_target_0,
    output wire         pred_taken_1,
    output wire [31:0]  pred_target_1,
    // 更新接口
    input  wire         ex_valid,
    input  wire         ex_is_bj,
    input  wire [31:0]  ex_pc,
    input  wire         real_taken,
    input  wire [31:0]  real_target
  );
  localparam BPU_ROW_W     = 2;
  localparam BPU_BANKS     = 2;
  localparam BPU_ENTRY_NUM = BPU_BANKS * (1 << BPU_ROW_W);
  localparam BPU_INDEX_W   = BPU_ROW_W + 1;
  localparam BPU_TAG_W     = 18;       // {valid, tag, counter, target}

  localparam BTB_ENTRY_W   = 1 + BPU_TAG_W + 2 + 32;

  reg reset;
  always @(posedge clk)
    reset <= ~resetn;

  function [BPU_INDEX_W-1:0] btb_index;
    input [31:0] pc;
    begin
      btb_index = {pc[2], pc[4:3]};
    end
  endfunction

  function [BPU_TAG_W-1:0] btb_tag;
    input [31:0] pc;
    begin
      btb_tag = pc[22:5];
    end
  endfunction

  // counter 更新函数
  function [1:0] train_counter;
    input [1:0] old_counter;
    input       taken;
    begin
      if (taken)
        train_counter = (old_counter == 2'b11) ? 2'b11 : old_counter + 2'b01;
      else
        train_counter = (old_counter == 2'b00) ? 2'b00 : old_counter - 2'b01;
    end
  endfunction

  // 生成 BTB 表项的函数
  function [BTB_ENTRY_W-1:0] make_btb_entry;
    input                 entry_valid;
    input [BPU_TAG_W-1:0] entry_tag;
    input [1:0]           entry_counter;
    input [31:0]          entry_target;
    begin
      make_btb_entry = {entry_valid, entry_tag, entry_counter, entry_target};
    end
  endfunction

  reg [BTB_ENTRY_W-1:0] btb_entry [0:BPU_ENTRY_NUM-1];  //  valid | tag | counter | target -> 有效 | tag | counter | 目标地址

  wire [31:0] if_pc_0 = if_pc;
  wire [31:0] if_pc_1 = if_pc + 32'h4;

  wire [BPU_TAG_W-1:0]   if_tag_0       = btb_tag(if_pc_0);
  wire [BPU_INDEX_W-1:0] if_index_0     = btb_index(if_pc_0);
  wire [BTB_ENTRY_W-1:0] if_btb_entry_0 = btb_entry[if_index_0];

  wire [BPU_TAG_W-1:0]   if_tag_1       = btb_tag(if_pc_1);
  wire [BPU_INDEX_W-1:0] if_index_1     = btb_index(if_pc_1);
  wire [BTB_ENTRY_W-1:0] if_btb_entry_1 = btb_entry[if_index_1];

  wire                 if_entry_valid_0;
  wire [BPU_TAG_W-1:0] if_entry_tag_0;
  wire [1:0]           if_entry_counter_0;
  wire [31:0]          if_entry_target_0;

  assign {if_entry_valid_0,
          if_entry_tag_0,
          if_entry_counter_0,
          if_entry_target_0} = if_btb_entry_0;

  wire                 if_entry_valid_1;
  wire [BPU_TAG_W-1:0] if_entry_tag_1;
  wire [1:0]           if_entry_counter_1;
  wire [31:0]          if_entry_target_1;

  assign {if_entry_valid_1,
          if_entry_tag_1,
          if_entry_counter_1,
          if_entry_target_1} = if_btb_entry_1;

  wire pred_btb_hit_0 = if_entry_valid_0 && (if_entry_tag_0 == if_tag_0);
  wire pred_btb_hit_1 = if_entry_valid_1 && (if_entry_tag_1 == if_tag_1);

  assign pred_taken_0  = pred_btb_hit_0 && if_entry_counter_0[1];
  assign pred_target_0 = pred_taken_0 ? if_entry_target_0 : if_pc_1;

  assign pred_taken_1  = pred_btb_hit_1 && if_entry_counter_1[1];
  assign pred_target_1 = pred_taken_1 ? if_entry_target_1 : (if_pc + 32'h8);

  wire                   update_valid_s1 = ex_valid && ex_is_bj;
  wire [BPU_TAG_W-1:0]   update_tag_s1   = btb_tag(ex_pc);
  wire [BPU_INDEX_W-1:0] update_index_s1 = btb_index(ex_pc);
  wire [BTB_ENTRY_W-1:0] update_entry_s1 = btb_entry[update_index_s1];

  wire                 read_valid_s1;
  wire [BPU_TAG_W-1:0] read_tag_s1;
  wire [1:0]           read_counter_s1;
  wire [31:0]          read_target_s1;

  assign {read_valid_s1,
          read_tag_s1,
          read_counter_s1,
          read_target_s1} = update_entry_s1;

  reg                   update_valid_s2;
  reg [BPU_TAG_W-1:0]   update_tag_s2;
  reg [BPU_INDEX_W-1:0] update_index_s2;

  reg                   real_taken_s2;
  reg [31:0]            real_target_s2;

  reg                   read_valid_s2;
  reg [BPU_TAG_W-1:0]   read_tag_s2;
  reg [1:0]             read_counter_s2;
  reg [31:0]            read_target_s2;

  always @(posedge clk)
  begin
    if (reset)
    begin
      update_valid_s2 <= 1'b0;
      update_tag_s2   <= {BPU_TAG_W{1'b0}};
      update_index_s2 <= {BPU_INDEX_W{1'b0}};
      real_taken_s2   <= 1'b0;
      real_target_s2  <= 32'b0;
      read_valid_s2   <= 1'b0;
      read_tag_s2     <= {BPU_TAG_W{1'b0}};
      read_counter_s2 <= 2'b01;
      read_target_s2  <= 32'b0;
    end
    else
    begin
      update_valid_s2 <= update_valid_s1;
      if (update_valid_s1)
      begin
        update_tag_s2   <= update_tag_s1;
        update_index_s2 <= update_index_s1;
        real_taken_s2   <= real_taken;
        real_target_s2  <= real_target;
        read_valid_s2   <= read_valid_s1;
        read_tag_s2     <= read_tag_s1;
        read_counter_s2 <= read_counter_s1;
        read_target_s2  <= read_target_s1;
      end
    end
  end

  wire update_hit_s2 = read_valid_s2 && (read_tag_s2 == update_tag_s2);
  wire [1:0] next_counter_s2 = train_counter(read_counter_s2, real_taken_s2);

  integer i;
  always @(posedge clk)
  begin
    if (reset)
    begin
      for (i = 0; i < BPU_ENTRY_NUM; i = i + 1)
        btb_entry[i] <= make_btb_entry(1'b0, {BPU_TAG_W{1'b0}}, 2'b01, 32'b0);
    end
    else if (update_valid_s2)
    begin
      if (update_hit_s2)
      begin
        btb_entry[update_index_s2] <= make_btb_entry(1'b1,
                 update_tag_s2,
                 next_counter_s2,
                 real_taken_s2 ? real_target_s2 : read_target_s2);
      end
      else if (real_taken_s2)
      begin
        btb_entry[update_index_s2] <= make_btb_entry(1'b1,
                 update_tag_s2,
                 2'b10,
                 real_target_s2);
      end
    end
  end
endmodule
