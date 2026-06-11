`include "mycpu.vh"

module IF_stage(
    input  wire        clk,
    input  wire        resetn,
    // PC 接口
    input  wire        pc_inst_req,
    input  wire [31:0] pc,
    // BPU 预测
    input  wire        bpu_pred_taken_0,
    input  wire [31:0] bpu_pred_target_0,
    input  wire        bpu_pred_taken_1,
    input  wire [31:0] bpu_pred_target_1,
    // 分支冲刷
    input  wire        br_taken,
    // IBUF 接收握手
    input  wire        ibuf_allowin,
    output wire        fs_to_ds_valid_0,
    output wire        fs_to_ds_valid_1,
    output wire [`FS_TO_DS_BUS_WD-1:0] fs_to_ds_bus_0,
    output wire [`FS_TO_DS_BUS_WD-1:0] fs_to_ds_bus_1,
    output wire        if_suspend,
    // ICache miss refill 接口
    output wire        rd_req,
    output wire [31:0] rd_addr,
    input  wire        rd_rdy,
    input  wire        ret_valid,
    input  wire [1:0]  ret_last,
    input  wire [31:0] ret_data
  );

  reg reset;
  always @(posedge clk)
    reset <= ~resetn;

  // IF0 分支预测并取指
  wire        s0_valid          = pc_inst_req;
  wire [31:0] s0_addr           = pc;
  wire        s0_pred_taken_0   = bpu_pred_taken_0;
  wire [31:0] s0_pred_target_0  = bpu_pred_target_0;
  wire        s0_pred_taken_1   = bpu_pred_taken_1;
  wire [31:0] s0_pred_target_1  = bpu_pred_target_1;
  wire [2:0]  s0_index          = s0_addr[6:4];
  wire [24:0] s0_tag            = s0_addr[31:7];
  wire [1:0]  s0_offset_word    = s0_addr[3:2];

  // S1 本周期返回缓存行数据和存储的 Tag 并判断是否命中
  reg         s1_valid;
  reg [31:0]  s1_addr;
  reg         s1_pred_taken_0;
  reg [31:0]  s1_pred_target_0;
  reg         s1_pred_taken_1;
  reg [31:0]  s1_pred_target_1;
  reg [2:0]   s1_index;
  reg [24:0]  s1_tag;
  reg [1:0]   s1_offset_word;

  // Cache 存储 (2-way 组相联, 8 组, 128-bit 行, 256B 总容量)
  reg         cache_valid [0:1][0:7];
  reg [24:0]  cache_tag   [0:1][0:7];
  reg [127:0] cache_data  [0:1][0:7];

  // Tag 比较
  wire        s1_tag_match_way0 = cache_valid[0][s1_index] && (cache_tag[0][s1_index] == s1_tag);
  wire        s1_tag_match_way1 = cache_valid[1][s1_index] && (cache_tag[1][s1_index] == s1_tag);
  wire        s1_hit            = s1_tag_match_way0 || s1_tag_match_way1;
  wire        s1_hit_way        = s1_tag_match_way1;
  wire [127:0] s1_hit_line      = s1_hit_way ? cache_data[1][s1_index] : cache_data[0][s1_index];

  // S2 Cache miss 发读请求，Cache hit 则将数据和控制信号发送下一级
  reg         s2_valid;
  reg         s2_hit;
  reg         s2_hit_way;
  reg [127:0] s2_line_data;
  reg [31:0]  s2_addr;
  reg         s2_pred_taken_0;
  reg [31:0]  s2_pred_target_0;
  reg         s2_pred_taken_1;
  reg [31:0]  s2_pred_target_1;
  reg [1:0]   s2_offset_word;

  wire [2:0]  s2_index = s2_addr[6:4];
  wire [24:0] s2_tag   = s2_addr[31:7];

  // 从 128bit 行中提取 32bit 字
  function [31:0] extract_word;
    input [127:0] line;
    input [1:0]   word_sel;
    begin
      case (word_sel)
        2'b00:
          extract_word = line[31:0];
        2'b01:
          extract_word = line[63:32];
        2'b10:
          extract_word = line[95:64];
        default:
          extract_word = line[127:96];
      endcase
    end
  endfunction

  // Miss FSM
  localparam FSM_IDLE        = 3'd0;
  localparam FSM_MISS_REQ    = 3'd1;
  localparam FSM_MISS_REFILL = 3'd2;
  localparam FSM_RECOVERY    = 3'd3;
  localparam FSM_DONE        = 3'd4;

  reg [2:0] state;
  reg [2:0] next_state;

  reg [127:0] refill_data_reg;
  reg [127:0] refill_line;
  reg [1:0]   refill_beat;

  reg [7:0] lfsr;

  wire [127:0] s2_effective_line   = (state == FSM_DONE) ? refill_data_reg : s2_line_data;
  wire [31:0]  s2_effective_inst_0 = extract_word(s2_effective_line, s2_offset_word);
  wire [31:0]  s2_effective_inst_1 = extract_word(s2_effective_line, s2_offset_word + 2'b01);
  wire [31:0]  s2_pc_1             = s2_addr + 32'h4;
  wire         s2_can_take_two     = (s2_offset_word != 2'b11) && !s2_pred_taken_0; //跨 cache line 或 slot0预测跳转的时候不取第二条

  // S3 缓存行数据对齐后发送给 IBUF
  reg         s3_valid_0;
  reg         s3_valid_1;
  reg [31:0]  s3_inst_0;
  reg [31:0]  s3_inst_1;
  reg [31:0]  s3_pc_0;
  reg [31:0]  s3_pc_1;
  reg         s3_pred_taken_0;
  reg [31:0]  s3_pred_target_0;
  reg         s3_pred_taken_1;
  reg [31:0]  s3_pred_target_1;

  assign fs_to_ds_valid_0 = s3_valid_0;
  assign fs_to_ds_valid_1 = s3_valid_1;
  assign fs_to_ds_bus_0   = {s3_pc_0, s3_inst_0, s3_pred_taken_0, s3_pred_target_0};
  assign fs_to_ds_bus_1   = {s3_pc_1, s3_inst_1, s3_pred_taken_1, s3_pred_target_1};

  reg miss_replace_way;

  always @(posedge clk)
  begin
    if (!resetn)
      miss_replace_way <= 1'b0;
    else if (s2_valid && !s2_hit && state == FSM_IDLE)
    begin
      if (!cache_valid[0][s2_index])
        miss_replace_way <= 1'b0;
      else if (!cache_valid[1][s2_index])
        miss_replace_way <= 1'b1;
      else
        miss_replace_way <= lfsr[0];
    end
  end

  wire s3_hold   = (s3_valid_0 || s3_valid_1) && !ibuf_allowin;
  wire miss_hold = s2_valid && !s2_hit && state != FSM_DONE;
  wire s2_stall  = s3_hold || miss_hold;
  wire s1_stall  = s2_stall;
  assign if_suspend = s3_hold || miss_hold;

  wire trigger_miss = s2_valid && !s2_hit && (state == FSM_IDLE);

  always @(*)
  begin
    next_state = state;
    case (state)
      FSM_IDLE:
        next_state = trigger_miss ? FSM_MISS_REQ : FSM_IDLE;
      FSM_MISS_REQ:
        next_state = rd_rdy ? FSM_MISS_REFILL : FSM_MISS_REQ;
      FSM_MISS_REFILL:
        next_state = (ret_valid && ret_last[0]) ? FSM_RECOVERY : FSM_MISS_REFILL;
      FSM_RECOVERY:
        next_state = FSM_DONE;
      FSM_DONE:
        next_state = s3_hold ? FSM_DONE : FSM_IDLE;
      default:
        next_state = FSM_IDLE;
    endcase
  end

  always @(posedge clk)
  begin
    if (reset)
      s1_valid <= 1'b0;
    else if (br_taken)
      s1_valid <= 1'b0;
    else if (!s1_stall)
      s1_valid <= s0_valid;
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      s1_addr          <= 32'b0;
      s1_pred_taken_0  <= 1'b0;
      s1_pred_target_0 <= 32'b0;
      s1_pred_taken_1  <= 1'b0;
      s1_pred_target_1 <= 32'b0;
      s1_index         <= 3'b0;
      s1_tag           <= 25'b0;
      s1_offset_word   <= 2'b0;
    end
    else if (!s1_stall)
    begin
      s1_addr          <= s0_addr;
      s1_pred_taken_0  <= s0_pred_taken_0;
      s1_pred_target_0 <= s0_pred_target_0;
      s1_pred_taken_1  <= s0_pred_taken_1;
      s1_pred_target_1 <= s0_pred_target_1;
      s1_index         <= s0_index;
      s1_tag           <= s0_tag;
      s1_offset_word   <= s0_offset_word;
    end
  end

  always @(posedge clk)
  begin
    if (reset)
      s2_valid <= 1'b0;
    else if (br_taken)
      s2_valid <= 1'b0;
    else if (!s2_stall)
      s2_valid <= s1_valid;
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      s2_hit           <= 1'b0;
      s2_hit_way       <= 1'b0;
      s2_line_data     <= 128'b0;
      s2_addr          <= 32'b0;
      s2_pred_taken_0  <= 1'b0;
      s2_pred_target_0 <= 32'b0;
      s2_pred_taken_1  <= 1'b0;
      s2_pred_target_1 <= 32'b0;
      s2_offset_word   <= 2'b0;
    end
    else if (!s2_stall)
    begin
      s2_hit           <= s1_hit;
      s2_hit_way       <= s1_hit_way;
      s2_line_data     <= s1_hit_line;
      s2_addr          <= s1_addr;
      s2_pred_taken_0  <= s1_pred_taken_0;
      s2_pred_target_0 <= s1_pred_target_0;
      s2_pred_taken_1  <= s1_pred_taken_1;
      s2_pred_target_1 <= s1_pred_target_1;
      s2_offset_word   <= s1_offset_word;
    end
  end

  wire s2_data_ready = s2_hit || (state == FSM_DONE);

  always @(posedge clk)
  begin
    if (reset)
    begin
      s3_valid_0 <= 1'b0;
      s3_valid_1 <= 1'b0;
    end
    else if (br_taken)
    begin
      s3_valid_0 <= 1'b0;
      s3_valid_1 <= 1'b0;
    end
    else if (!s3_hold)
    begin
      s3_valid_0 <= s2_valid && s2_data_ready;
      s3_valid_1 <= s2_valid && s2_data_ready && s2_can_take_two;
    end
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      s3_inst_0        <= 32'b0;
      s3_inst_1        <= 32'b0;
      s3_pc_0          <= 32'b0;
      s3_pc_1          <= 32'b0;
      s3_pred_taken_0  <= 1'b0;
      s3_pred_target_0 <= 32'b0;
      s3_pred_taken_1  <= 1'b0;
      s3_pred_target_1 <= 32'b0;
    end
    else if (!s3_hold)
    begin
      s3_inst_0        <= s2_effective_inst_0;
      s3_inst_1        <= s2_effective_inst_1;
      s3_pc_0          <= s2_addr;
      s3_pc_1          <= s2_pc_1;
      s3_pred_taken_0  <= s2_pred_taken_0;
      s3_pred_target_0 <= s2_pred_target_0;
      s3_pred_taken_1  <= s2_pred_taken_1;
      s3_pred_target_1 <= s2_pred_target_1;
    end
  end

  assign rd_req  = (state == FSM_MISS_REQ);
  assign rd_addr = {s2_addr[31:4], 4'b0000};

  wire lfsr_feedback = lfsr[7] ^ lfsr[5] ^ lfsr[4] ^ lfsr[3];

  // Miss FSM 与 Cache 管理
  always @(posedge clk)
  begin
    if (!resetn)
      state <= FSM_IDLE;
    else if (br_taken)
      state <= FSM_IDLE;
    else
      state <= next_state;
  end

  integer i, j;
  always @(posedge clk)
  begin
    if (!resetn)
    begin
      lfsr            <= 8'hFF;
      refill_data_reg <= 128'b0;
      refill_line     <= 128'b0;
      refill_beat     <= 2'b0;
      for (i = 0; i < 2; i = i + 1)
      begin
        for (j = 0; j < 8; j = j + 1)
        begin
          cache_valid[i][j] <= 1'b0;
          cache_tag[i][j]   <= 25'b0;
          cache_data[i][j]  <= 128'b0;
        end
      end
    end
    else
    begin
      lfsr <= {lfsr[6:0], lfsr_feedback};

      // MISS_REQ -> MISS_REFILL: 初始化重填
      if (state == FSM_MISS_REQ && rd_rdy)
      begin
        refill_beat <= 2'b0;
        refill_line <= 128'b0;
      end

      // MISS_REFILL: 收集重填数据
      if (state == FSM_MISS_REFILL && ret_valid)
      begin
        case (refill_beat)
          2'd0:
            refill_line[31:0]   <= ret_data;
          2'd1:
            refill_line[63:32]  <= ret_data;
          2'd2:
            refill_line[95:64]  <= ret_data;
          2'd3:
            refill_line[127:96] <= ret_data;
        endcase
        refill_beat <= refill_beat + 2'd1;
      end

      // RECOVERY: 写入 Cache + 锁存 refill_data_reg
      if (state == FSM_RECOVERY)
      begin
        cache_valid[miss_replace_way][s2_index] <= 1'b1;
        cache_tag[miss_replace_way][s2_index]   <= s2_tag;
        cache_data[miss_replace_way][s2_index]  <= refill_line;
        refill_data_reg <= refill_line;
      end
    end
  end

endmodule
