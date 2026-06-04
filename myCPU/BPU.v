`include "mycpu.vh"

module BPU (
    input  wire         clk,
    input  wire         resetn,
    // 预测接口
    input  wire [31:0]  if_pc,
    input  wire         if_valid,
    input  wire         id_valid,
    input  wire         pl_suspend,
    output wire         pred_taken,
    output wire [31:0]  pred_target,
    // 更新接口
    input  wire         ex_valid,
    input  wire         ex_is_bj,
    input  wire [31:0]  ex_pc,
    input  wire         real_taken,
    input  wire [31:0]  real_target
  );
  localparam BPU_ROW_W     = 2;   // bank 行数
  localparam BPU_BANKS     = 2;   // 两个 banke
  localparam BPU_ENTRY_NUM = BPU_BANKS * (1 << BPU_ROW_W); //总项数 8项
  localparam BPU_INDEX_W   = BPU_ROW_W + 1;     // 索引宽度
  localparam BPU_TAG_W     = 18;                // tag 位宽

  localparam BTB_ENTRY_W   = 1 + BPU_TAG_W + 2 + 32; // {valid, tag, counter, target}

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

  // BTB 表
  reg [BTB_ENTRY_W-1:0] btb_entry [0:BPU_ENTRY_NUM-1]; //  valid | tag | counter | target -> 有效 | tag | counter | 目标地址

  wire [BPU_TAG_W-1:0]   if_tag       = btb_tag(if_pc);
  wire [BPU_INDEX_W-1:0] if_index     = btb_index(if_pc);
  wire [BTB_ENTRY_W-1:0] if_btb_entry = btb_entry[if_index];

  wire                 if_entry_valid;
  wire [BPU_TAG_W-1:0] if_entry_tag;
  wire [1:0]           if_entry_counter;
  wire [31:0]          if_entry_target;

  assign {if_entry_valid,
          if_entry_tag,
          if_entry_counter,
          if_entry_target} = if_btb_entry;

  wire   pred_btb_hit = if_entry_valid && (if_entry_tag == if_tag);   // BTB 命中
  assign pred_taken   = pred_btb_hit && if_entry_counter[1];
  assign pred_target  = pred_taken ? if_entry_target : (if_pc + 32'h4);

  // 第一个周期读，第二个周期更新
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

  // 第二个周期的寄存器
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
        // 真实分支结果和相关信息
        real_taken_s2   <= real_taken;
        real_target_s2  <= real_target;

        read_valid_s2   <= read_valid_s1;
        read_tag_s2     <= read_tag_s1;
        read_counter_s2 <= read_counter_s1;
        read_target_s2  <= read_target_s1;
      end
    end
  end

  // BTB表 更新
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
      else if (real_taken_s2)  // 未命中且分支被执行，更新表项
      begin
        btb_entry[update_index_s2] <= make_btb_entry(1'b1,
                 update_tag_s2,
                 2'b10,
                 real_target_s2);
      end
    end
  end
endmodule
