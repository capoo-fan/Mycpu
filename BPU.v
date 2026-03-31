`timescale 1ns / 1ps

`include "mycpu.vh"

module BPU (
    input  wire         clk    ,
    input  wire         resetn   ,
    input  wire [31:0]  if_pc      ,    // IF阶段的PC值
    input  wire         if_valid   ,    // IF阶段的有效信号
    input  wire         id_valid   ,    // ID阶段的有效信号
    input  wire         pl_suspend ,    // 流水线暂停信号
    // predict branch direction and target
    output wire [31:0]  pred_target,    // 预测的下一条指令地址
    output wire         pred_error ,    // 预测是否错误
    // signals to correct BHT
    input  wire         ex_valid   ,    // EX阶段的有效信号
    input  wire         ex_is_bj   ,    // EX阶段是否是条件分支或直接跳转指令
    input  wire [31:0]  ex_pc      ,    // EX阶段的PC值
    input  wire         real_taken ,    // EX阶段指令实际是否发生跳转
    input  wire [31:0]  real_target     // EX阶段指令发生跳转时的目标地址
  );
  reg         reset;
  always @(posedge clk)
    reset <= ~resetn;
  // 仅保留跳转次数大于2的指令
  localparam [31:0] B_VALID_PC0 = 32'h1c01025c;
  localparam [31:0] B_VALID_PC1 = 32'h1c010264;
  localparam [31:0] J_VALID_PC0 = 32'h1c010268;

  wire if_pc_in_valid = (if_pc == B_VALID_PC0) ||
       (if_pc == B_VALID_PC1) ||
       (if_pc == J_VALID_PC0);

  wire ex_pc_in_valid = (ex_pc == B_VALID_PC0) ||
       (ex_pc == B_VALID_PC1) ||
       (ex_pc == J_VALID_PC0);

`ifdef ENABLE_BPU

  // BHT
  reg  [`BHT_TAG_W-1:0] tag     [`BHT_ENTRY-1:0];
  reg  [`BHT_ENTRY-1:0] valid;
  reg  [           1:0] history [`BHT_ENTRY-1:0];
  reg  [          31:0] target  [`BHT_ENTRY-1:0];

  wire [`BHT_TAG_W-1:0] if_tag = if_pc[`BHT_IDX_W + `BHT_TAG_W + 1 : `BHT_IDX_W + 2];      // IF阶段指令地址标签
  wire [`BHT_TAG_W-1:0] ex_tag = ex_pc[`BHT_IDX_W + `BHT_TAG_W + 1 : `BHT_IDX_W + 2];      // EX阶段指令地址标签

  // 增强地址折叠，让更多 if_pc 位参与异或，降低索引冲突概率
  wire [31:0] pc_hash = if_pc ^ (if_pc >> 2) ^ (if_pc >> 10)^ (if_pc >> 16) ^ (if_pc >> 24);
  wire [`BHT_IDX_W-1:0] index   = pc_hash[`BHT_IDX_W+1:2];    // 表索引

  wire   pred_taken  = if_pc_in_valid && valid[index] && (tag[index] == if_tag) && history[index][1];        // 生成预测跳转方向
  assign pred_target = pred_taken ? target[index] : (if_pc + 32'h4);        // 生成预测跳转的目标地址

  // EX阶段才能判断分支跳转是否错误，故需把IF阶段的预测信号传递到EX阶段
  reg  [`BHT_IDX_W-1:0] id_index      , ex_index      ;
  reg                   id_pred_taken , ex_pred_taken ;
  reg  [          31:0] id_pred_target, ex_pred_target;

  always @(posedge clk)
  begin
    if (reset)
    begin
      id_index       <= 'h0;
      id_pred_taken  <= 1'b0;
      id_pred_target <= 32'b0;
      ex_index       <= 'h0;
      ex_pred_taken  <= 1'b0;
      ex_pred_target <= 32'b0;
    end
    else
    begin
      if (if_valid && !pl_suspend)
      begin
        id_index       <= index;
        id_pred_taken  <= pred_taken;
        id_pred_target <= pred_target;
      end

      if (id_valid && !pl_suspend)
      begin
        ex_index       <= id_index;
        ex_pred_taken  <= id_pred_taken;
        ex_pred_target <= id_pred_target;
      end
    end
  end

  wire ex_is_bj_valid = ex_is_bj & ex_pc_in_valid;
  wire taken_error  = ex_is_bj_valid & (ex_pred_taken ^ !real_taken);       // 检测分支跳转方向是否预测错误
  wire target_error = ex_is_bj_valid & real_taken & ex_pred_taken & (ex_pred_target != real_target);                 // 检测目标地址是否预测错误
  assign pred_error = ex_valid & (taken_error | target_error);

  wire add_entry     = ex_valid & ex_is_bj_valid & !valid[ex_index];     // 判断何种情形需要在BHT和BTB中新增表项
  wire update_entry  = ex_valid & ex_is_bj_valid & valid[ex_index] & (tag[ex_index] == ex_tag);     // 判断何种情形需要更新BHT和BTB的现有表项
  wire replace_entry = ex_valid & ex_is_bj_valid & valid[ex_index] & (tag[ex_index] != ex_tag);     // 判断何种情形需要替换BHT和BTB的现有表项

  // Update BHT and BTB
  integer i;
  always @(posedge clk)
  begin
    if (reset)
    begin
      valid <= {`BHT_ENTRY{1'b0}};
      for (i = 0; i < `BHT_ENTRY; i = i + 1)
        history[i] <= 2'b10;
    end
    else
    begin
      if (add_entry || replace_entry)
      begin
        valid[ex_index]  <= 1'b1;
        tag[ex_index]    <= ex_tag;
        if (real_taken)
        begin
          target[ex_index] <= real_target;
        end
        history[ex_index] <= real_taken ? 2'b10 : 2'b01;//跳了就是弱跳转，不跳就是弱不跳
      end
      else if (update_entry)
      begin
        if (real_taken)
        begin
          target[ex_index] <= real_target;
        end
        if (real_taken)
        begin
          if (history[ex_index] == 2'b00)
            history[ex_index] <= 2'b01;
          else if (history[ex_index] == 2'b01)
            history[ex_index] <= 2'b10;
          else if (history[ex_index] == 2'b10)
            history[ex_index] <= 2'b11;
          else
            history[ex_index] <= 2'b11;
        end
        else
        begin
          if (history[ex_index] == 2'b11)
            history[ex_index] <= 2'b10;
          else if (history[ex_index] == 2'b10)
            history[ex_index] <= 2'b01;
          else if (history[ex_index] == 2'b01)
            history[ex_index] <= 2'b00;
          else
            history[ex_index] <= 2'b00;
        end

      end
    end
  end
`else

  assign pred_target = if_pc + 32'h4;

  wire taken_error  = ex_is_bj & ex_pc_in_valid & real_taken;
  wire target_error = 1'b0;
  assign pred_error = ex_valid & (taken_error | target_error);

`endif

endmodule
