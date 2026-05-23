`include "mycpu.vh"

module BPU (
    input  wire         clk        ,
    input  wire         resetn     ,
    input  wire [31:0]  if_pc      ,    // IF阶段的PC值
    input  wire         if_valid   ,    // IF阶段的有效信号
    input  wire         id_valid   ,    // ID阶段的有效信号
    input  wire         pl_suspend ,    // 流水线暂停信号
    output wire         pred_taken ,    // 预测是否跳转
    output wire [31:0]  pred_target,    // 预测的下一条指令地址
    input  wire         ex_valid   ,    // EX阶段的有效信号
    input  wire         ex_is_bj   ,    // EX阶段是否是条件分支或直接跳转指令
    input  wire [31:0]  ex_pc      ,    // EX阶段的PC值
    input  wire         real_taken ,    // EX阶段指令实际是否发生跳转
    input  wire [31:0]  real_target,    // EX阶段指令发生跳转时的目标地址
    input  wire         ex_is_call ,    // EX阶段是否为调用函数指令
    input  wire         ex_is_ret  ,    // EX阶段是否为返回指令
    input  wire [31:0]  ex_ret_addr     // 调用指令的返回地址
  );
  reg         reset;
  always @(posedge clk)
    reset <= ~resetn;

  // BHT
  reg  [`BHT_TAG_W-1:0] tag     [`BHT_ENTRY-1:0];
  reg  [`BHT_ENTRY-1:0] valid;
  reg  [           1:0] history [`BHT_ENTRY-1:0];
  reg  [          31:0] target  [`BHT_ENTRY-1:0];
  reg  [`BHT_ENTRY-1:0] is_ret_entry;

  reg [31:0]           ras_stack [0:`RAS_DEPTH-1]; // 返回地址栈
  reg [`RAS_PTR_W-1:0] ras_sp;
  reg [`RAS_CNT_W-1:0] ras_cnt;

  reg         ex_valid_r;
  reg         ex_is_bj_r;
  reg  [31:0] ex_pc_r;
  reg         real_taken_r;
  reg  [31:0] real_target_r;
  reg         ex_is_call_r;
  reg         ex_is_ret_r;
  reg  [31:0] ex_ret_addr_r;

  wire [`BHT_TAG_W-1:0] if_tag = if_pc[`BHT_IDX_W + `BHT_TAG_W + 1 : `BHT_IDX_W + 2];      // IF阶段指令地址标签
  wire [`BHT_TAG_W-1:0] ex_tag = ex_pc_r[`BHT_IDX_W + `BHT_TAG_W + 1 : `BHT_IDX_W + 2];      // EX阶段指令地址标签

  // 从 EX 阶段 PC 重新计算 BHT 索引, 避免使用被后续指令覆盖的 ex_index
  wire [31:0] ex_pc_hash = ex_pc_r ^ (ex_pc_r >> 2) ^ (ex_pc_r >> 10) ^ (ex_pc_r >> 16) ^ (ex_pc_r >> 24);
  wire [`BHT_IDX_W-1:0] ex_bht_idx = ex_pc_hash[`BHT_IDX_W+1:2];

  // 增强地址折叠，让更多 if_pc 位参与异或，降低索引冲突概率
  wire [31:0] pc_hash = if_pc ^ (if_pc >> 2) ^ (if_pc >> 10)^ (if_pc >> 16) ^ (if_pc >> 24);
  wire [`BHT_IDX_W-1:0] index   = pc_hash[`BHT_IDX_W+1:2];    // 表索引

  wire ras_empty = (ras_cnt == {`RAS_CNT_W{1'b0}});
  wire [`RAS_PTR_W-1:0] ras_top_ptr = (ras_sp == {`RAS_PTR_W{1'b0}}) ? (`RAS_DEPTH - 1) : (ras_sp - {{(`RAS_PTR_W-1){1'b0}}, 1'b1});
  wire [31:0] ras_top = ras_stack[ras_top_ptr];

  wire pred_btb_hit  = valid[index] && (tag[index] == if_tag);
  assign pred_taken  = pred_btb_hit && history[index][1];        // 生成预测跳转方向
  wire pred_use_ras  = pred_taken && is_ret_entry[index] && !ras_empty;
  assign pred_target = pred_taken ? (pred_use_ras ? ras_top : target[index]) : (if_pc + 32'h4);        // 生成预测跳转的目标地址

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

  always @(posedge clk)
  begin
    if (reset)
    begin
      ex_valid_r    <= 1'b0;
      ex_is_bj_r    <= 1'b0;
      ex_pc_r       <= 32'b0;
      real_taken_r  <= 1'b0;
      real_target_r <= 32'b0;
      ex_is_call_r  <= 1'b0;
      ex_is_ret_r   <= 1'b0;
      ex_ret_addr_r <= 32'b0;
    end
    else
    begin
      ex_valid_r    <= ex_valid;
      ex_is_bj_r    <= ex_is_bj;
      ex_pc_r       <= ex_pc;
      real_taken_r  <= real_taken;
      real_target_r <= real_target;
      ex_is_call_r  <= ex_is_call;
      ex_is_ret_r   <= ex_is_ret;
      ex_ret_addr_r <= ex_ret_addr;
    end
  end

  wire ex_is_bj_valid = ex_is_bj_r;

  wire add_entry     = ex_valid_r & ex_is_bj_valid & !valid[ex_bht_idx];     // 判断何种情形需要在BHT和BTB中新增表项
  wire update_entry  = ex_valid_r & ex_is_bj_valid & valid[ex_bht_idx] & (tag[ex_bht_idx] == ex_tag);     // 判断何种情形需要更新BHT和BTB的现有表项
  wire replace_entry = ex_valid_r & ex_is_bj_valid & valid[ex_bht_idx] & (tag[ex_bht_idx] != ex_tag);     // 判断何种情形需要替换BHT和BTB的现有表项

  integer i;
  integer j;
  always @(posedge clk)
  begin
    if (reset)
    begin
      valid <= {`BHT_ENTRY{1'b0}};
      is_ret_entry <= {`BHT_ENTRY{1'b0}};
      ras_sp <= {`RAS_PTR_W{1'b0}};
      ras_cnt <= {`RAS_CNT_W{1'b0}};
      for (i = 0; i < `BHT_ENTRY; i = i + 1)
        history[i] <= 2'b10;
      for (j = 0; j < `RAS_DEPTH; j = j + 1)
        ras_stack[j] <= 32'b0;
    end
    else
    begin
      if (add_entry || replace_entry)
      begin
        valid[ex_bht_idx]  <= 1'b1;
        tag[ex_bht_idx]    <= ex_tag;
        is_ret_entry[ex_bht_idx] <= ex_is_ret_r;
        if (real_taken_r)
        begin
          target[ex_bht_idx] <= real_target_r;
        end
        // 00代表强不跳转，10代表弱不跳转，11代表弱跳转，11代表强跳转
        history[ex_bht_idx] <= real_taken_r ? 2'b10 : 2'b01;//跳了就是弱跳转，不跳就是弱不跳
      end
      else if (update_entry)
      begin
        is_ret_entry[ex_bht_idx] <= ex_is_ret_r;
        if (real_taken_r)
        begin
          target[ex_bht_idx] <= real_target_r;
        end
        if (real_taken_r)
        begin
          if (history[ex_bht_idx] == 2'b00)
            history[ex_bht_idx] <= 2'b01;
          else if (history[ex_bht_idx] == 2'b01)
            history[ex_bht_idx] <= 2'b10;
          else if (history[ex_bht_idx] == 2'b10)
            history[ex_bht_idx] <= 2'b11;
          else
            history[ex_bht_idx] <= 2'b11;
        end
        else
        begin
          if (history[ex_bht_idx] == 2'b11)
            history[ex_bht_idx] <= 2'b10;
          else if (history[ex_bht_idx] == 2'b10)
            history[ex_bht_idx] <= 2'b01;
          else if (history[ex_bht_idx] == 2'b01)
            history[ex_bht_idx] <= 2'b00;
          else
            history[ex_bht_idx] <= 2'b00;
        end

      end

      if (ex_valid_r && ex_is_bj_valid && real_taken_r)
      begin
        if (ex_is_call_r)
        begin
          ras_stack[ras_sp] <= ex_ret_addr_r;

          if (ras_sp == (`RAS_DEPTH - 1))
            ras_sp <= {`RAS_PTR_W{1'b0}};
          else
            ras_sp <= ras_sp + {{(`RAS_PTR_W-1){1'b0}}, 1'b1};

          if (ras_cnt != `RAS_DEPTH)
            ras_cnt <= ras_cnt + {{(`RAS_CNT_W-1){1'b0}}, 1'b1};
        end
        else if (ex_is_ret_r)
        begin
          if (!ras_empty)
          begin
            if (ras_sp == {`RAS_PTR_W{1'b0}})
              ras_sp <= (`RAS_DEPTH - 1);
            else
              ras_sp <= ras_sp - {{(`RAS_PTR_W-1){1'b0}}, 1'b1};
            ras_cnt <= ras_cnt - {{(`RAS_CNT_W-1){1'b0}}, 1'b1};
          end
        end
      end
    end
  end
endmodule
