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
    output wire         pred_lane,
    // 更新接口
    input  wire         ex_valid,
    input  wire         ex_is_bj,
    input  wire [31:0]  ex_pc,
    input  wire         real_taken,
    input  wire [31:0]  real_target
  );
  localparam BPU_ROW_W     = 2;
  localparam BPU_BANKS     = 2;
  localparam BPU_ROWS      = (1 << BPU_ROW_W);
  localparam BPU_TAG_W     = 18;

  (* keep = "true", equivalent_register_removal = "no" *) reg reset;
  always @(posedge clk)
    reset <= ~resetn;

  function [BPU_TAG_W-1:0] btb_tag;
    input [31:0] pc;
    begin
      btb_tag = pc[22:5];
    end
  endfunction

  // 将相邻热点循环在 PC 高位上的差异折叠进 2-bit 行索引。
  // 表容量和命中比较路径保持不变，但可避免 MATRIX 中 0x...2074
  // 与 0x...20d4 长期争用同一 bank/row。
  function [BPU_ROW_W-1:0] btb_row;
    input [31:0] pc;
    begin
      btb_row = pc[4:3] ^ pc[7:6];
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

  reg                 btb_valid   [0:BPU_BANKS-1][0:BPU_ROWS-1];
  reg [BPU_TAG_W-1:0] btb_tag_mem [0:BPU_BANKS-1][0:BPU_ROWS-1];
  reg [1:0]           btb_counter [0:BPU_BANKS-1][0:BPU_ROWS-1];
  reg [31:0]          btb_target  [0:BPU_BANKS-1][0:BPU_ROWS-1];

  wire [BPU_TAG_W-1:0]   pred_tag  = btb_tag(if_pc);
  wire [BPU_ROW_W-1:0]   pred_row  = btb_row(if_pc);
  wire                   pred_bank = if_pc[2];

  wire pred_hit_bank0 = btb_valid[1'b0][pred_row] &&
                        (btb_tag_mem[1'b0][pred_row] == pred_tag);
  wire pred_hit_bank1 = btb_valid[1'b1][pred_row] &&
                        (btb_tag_mem[1'b1][pred_row] == pred_tag);

  wire pred_valid_bank0 = pred_hit_bank0 && btb_counter[1'b0][pred_row][1];
  wire pred_valid_bank1 = pred_hit_bank1 && btb_counter[1'b1][pred_row][1];

  wire lane0_taken = pred_bank ? pred_valid_bank1 : pred_valid_bank0;
  wire lane1_taken = !pred_bank && pred_valid_bank1;
  wire raw_pred_taken = lane0_taken || lane1_taken;
  wire raw_pred_lane  = !lane0_taken && lane1_taken;
  wire [31:0] raw_pred_target = raw_pred_lane ? btb_target[1'b1][pred_row] :
                                                (pred_bank ? btb_target[1'b1][pred_row] :
                                                             btb_target[1'b0][pred_row]);

  assign pred_taken = if_valid && raw_pred_taken;
  assign pred_target = pred_taken ? raw_pred_target : 32'b0;
  assign pred_lane = pred_taken ? raw_pred_lane : 1'b0;

  wire                   update_valid_s1 = ex_valid && ex_is_bj;
  wire [BPU_TAG_W-1:0]   update_tag_s1   = btb_tag(ex_pc);
  wire                   update_bank_s1  = ex_pc[2];
  wire [BPU_ROW_W-1:0]   update_row_s1   = btb_row(ex_pc);

  wire                 read_valid_s1;
  wire [BPU_TAG_W-1:0] read_tag_s1;
  wire [1:0]           read_counter_s1;
  wire [31:0]          read_target_s1;

  assign read_valid_s1  = btb_valid[update_bank_s1][update_row_s1];
  assign read_tag_s1    = btb_tag_mem[update_bank_s1][update_row_s1];
  assign read_counter_s1 = btb_counter[update_bank_s1][update_row_s1];
  assign read_target_s1 = btb_target[update_bank_s1][update_row_s1];

  reg                   update_valid_s2;
  reg [BPU_TAG_W-1:0]   update_tag_s2;
  reg                   update_bank_s2;
  reg [BPU_ROW_W-1:0]   update_row_s2;

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
      update_bank_s2  <= 1'b0;
      update_row_s2   <= {BPU_ROW_W{1'b0}};
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
        update_bank_s2  <= update_bank_s1;
        update_row_s2   <= update_row_s1;
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

  integer i, j;
  always @(posedge clk)
  begin
    if (reset)
    begin
      for (i = 0; i < BPU_BANKS; i = i + 1)
      begin
        for (j = 0; j < BPU_ROWS; j = j + 1)
        begin
          btb_valid[i][j]   <= 1'b0;
          btb_tag_mem[i][j] <= {BPU_TAG_W{1'b0}};
          btb_counter[i][j] <= 2'b01;
          btb_target[i][j]  <= 32'b0;
        end
      end
    end
    else if (update_valid_s2)
    begin
      if (update_hit_s2)
      begin
        btb_valid[update_bank_s2][update_row_s2]   <= 1'b1;
        btb_tag_mem[update_bank_s2][update_row_s2] <= update_tag_s2;
        btb_counter[update_bank_s2][update_row_s2] <= next_counter_s2;
        btb_target[update_bank_s2][update_row_s2]  <= real_taken_s2 ? real_target_s2 : read_target_s2;
      end
      else if (real_taken_s2)
      begin
        btb_valid[update_bank_s2][update_row_s2]   <= 1'b1;
        btb_tag_mem[update_bank_s2][update_row_s2] <= update_tag_s2;
        btb_counter[update_bank_s2][update_row_s2] <= 2'b10;
        btb_target[update_bank_s2][update_row_s2]  <= real_target_s2;
      end
    end
  end
endmodule
