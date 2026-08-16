`include "mycpu.vh"

module inst_buffer(
    input  wire                          clk,
    input  wire                          resetn,
    input  wire                          flush,

    input  wire                          push_valid_0,
    input  wire [`FS_TO_DS_BUS_WD-1:0]   push_bus_0,
    input  wire                          push_valid_1,
    input  wire [`FS_TO_DS_BUS_WD-1:0]   push_bus_1,
    output wire                          push_ready,
    output wire                          full,

    input  wire                          pop_0,
    input  wire                          pop_1,
    output wire                          front_valid_0,
    output wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_0,
    output wire [4:0]                    front_raddr1_0_hot,
    output wire [4:0]                    front_raddr2_0_hot,
    output wire                          front_valid_1,
    output wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_1,
    output wire [4:0]                    front_raddr1_1_hot,
    output wire [4:0]                    front_raddr2_1_hot
  );
  localparam pointer_width = 2;
  localparam [pointer_width:0] CNT_ZERO = {(pointer_width+1){1'b0}};
  localparam [pointer_width:0] CNT_ONE  = {{pointer_width{1'b0}}, 1'b1};
  wire [pointer_width-1:0] head_next = head + {{(pointer_width-1){1'b0}}, 1'b1};
  wire [pointer_width-1:0] tail_next = tail + {{(pointer_width-1){1'b0}}, 1'b1};

  reg [`IBUF_ENTRY_BUS_WD-1:0] fifo [0:3];
  reg [pointer_width-1:0] head;
  reg [pointer_width-1:0] tail;
  reg [pointer_width:0]   cnt;

  wire [`IBUF_ENTRY_BUS_WD-1:0] fifo_front_0;
  wire [`IBUF_ENTRY_BUS_WD-1:0] fifo_front_1;
  assign fifo_front_0 = fifo[head];
  assign fifo_front_1 = fifo[head_next];

  reg                          front_valid_0_r;
  reg                          front_valid_1_r;

  // 提升主频所做的拆分
  reg [44:0] front_bus_0_g0;
  reg [44:0] front_bus_0_g1;
  reg [44:0] front_bus_0_g2;
  reg [44:0] front_bus_0_g3;
  reg [44:0] front_bus_0_g4;
  reg [40:0] front_bus_0_g5;
  reg [44:0] front_bus_1_g0;
  reg [44:0] front_bus_1_g1;
  reg [44:0] front_bus_1_g2;
  reg [44:0] front_bus_1_g3;
  reg [44:0] front_bus_1_g4;
  reg [40:0] front_bus_1_g5;

  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg [4:0] front_raddr1_0_hot_r;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 8 *)
  reg [4:0] front_raddr2_0_hot_r;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 8 *)
  reg front_raddr2_0_hot_bit1_r;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 8 *)
  reg front_raddr2_0_hot_bit0_r;
  // lane1 raddr1[0] drives the widest consume/RAW compare cone.  Keep just
  // this bit as a local physical source instead of duplicating the complete
  // lane1 address buses (which increases routing pressure around the FIFO).
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg front_raddr1_1_hot_bit0_r;
  localparam integer HOT_RADDR1_LSB = `FS_TO_DS_BUS_WD + 56;
  localparam integer HOT_RADDR2_LSB = `FS_TO_DS_BUS_WD + 51;

  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_0_r;
  wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_1_r;
  assign front_bus_0_r = {front_bus_0_g5, front_bus_0_g4,
                          front_bus_0_g3, front_bus_0_g2,
                          front_bus_0_g1, front_bus_0_g0};
  assign front_bus_1_r = {front_bus_1_g5, front_bus_1_g4,
                          front_bus_1_g3, front_bus_1_g2,
                          front_bus_1_g1, front_bus_1_g0};

  assign front_valid_0 = front_valid_0_r;
  assign front_valid_1 = front_valid_1_r;
  assign front_bus_0   = front_bus_0_r;
  assign front_bus_1   = front_bus_1_r;
  assign front_raddr1_0_hot = front_raddr1_0_hot_r;
  assign front_raddr2_0_hot = {front_raddr2_0_hot_r[4:2],
                               front_raddr2_0_hot_bit1_r,
                               front_raddr2_0_hot_bit0_r};
  assign front_raddr1_1_hot = {
      front_bus_1_r[HOT_RADDR1_LSB+4:HOT_RADDR1_LSB+1],
      front_raddr1_1_hot_bit0_r};
  assign front_raddr2_1_hot = front_bus_1_r[HOT_RADDR2_LSB +: 5];

  reg                           next_front_valid_0;
  reg                           next_front_valid_1;

  reg [1:0] head_step;

  always @(*)
  begin
    head_step = 2'd0;
    if (pop_1)
      head_step = (cnt > CNT_ONE) ? 2'd2 :
                (cnt != CNT_ZERO) ? 2'd1 : 2'd0;
    else if (pop_0)
    begin
      if (front_valid_1_r)
        head_step = (cnt != CNT_ZERO) ? 2'd1 : 2'd0;
      else
        head_step = (cnt > CNT_ONE) ? 2'd2 :
                  (cnt != CNT_ZERO) ? 2'd1 : 2'd0;
    end
    else if (!front_valid_0_r)
      head_step = (cnt > CNT_ONE) ? 2'd2 :
                (cnt != CNT_ZERO) ? 2'd1 : 2'd0;
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
      head_step = 2'd1;
  end

  // valid 和 payload 分开推导。特别是双 pop 时直接从 FIFO 头两项
  // 装载，不再经过 temp_valid -> refill -> 宽总线 mux 级联。
  always @(*)
  begin
    next_front_valid_0 = front_valid_0_r;
    next_front_valid_1 = front_valid_1_r;

    if (pop_1)
    begin
      next_front_valid_0 = (cnt != CNT_ZERO);
      next_front_valid_1 = (cnt > CNT_ONE);
    end
    else if (pop_0)
    begin
      if (front_valid_1_r)
      begin
        next_front_valid_0 = 1'b1;
        if (cnt != CNT_ZERO)
        begin
          next_front_valid_1 = 1'b1;
        end
        else
          next_front_valid_1 = 1'b0;
      end
      else
      begin
        next_front_valid_0 = (cnt != CNT_ZERO);
        next_front_valid_1 = (cnt > CNT_ONE);
      end
    end
    else if (!front_valid_0_r)
    begin
      next_front_valid_0 = (cnt != CNT_ZERO);
      next_front_valid_1 = (cnt > CNT_ONE);
    end
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
    begin
      next_front_valid_1 = 1'b1;
    end
  end

  // lane1 只可能从 FIFO 的头两项之一装载。把“装载来源”和 CE
  // 分开后，无更新时由寄存器自身保持，pop 回环不再穿过 payload
  // 的 hold mux。每个 45-bit 组再拆成三个约 15-bit 的本地 CE，
  // 避免工具在共享 CE 后插入一层高扇出缓冲 LUT。
  `define FRONT1_LOAD_CONTROLS(SFX) \
    (* keep = "true", max_fanout = 48 *) wire front1_load_fifo1_``SFX = \
         pop_1 || (pop_0 && !front_valid_1_r) || \
         (!pop_0 && !front_valid_0_r); \
    (* keep = "true", max_fanout = 16 *) wire front1_we_``SFX``_a = \
         pop_1 || \
         (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) || \
         (!pop_0 && (!front_valid_0_r || \
                     (!front_valid_1_r && (cnt != CNT_ZERO)))); \
    (* keep = "true", max_fanout = 16 *) wire front1_we_``SFX``_b = \
         pop_1 || \
         (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) || \
         (!pop_0 && (!front_valid_0_r || \
                     (!front_valid_1_r && (cnt != CNT_ZERO)))); \
    (* keep = "true", max_fanout = 16 *) wire front1_we_``SFX``_c = \
         pop_1 || \
         (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) || \
         (!pop_0 && (!front_valid_0_r || \
                     (!front_valid_1_r && (cnt != CNT_ZERO))))

  `FRONT1_LOAD_CONTROLS(g0);
  `FRONT1_LOAD_CONTROLS(g1);
  `FRONT1_LOAD_CONTROLS(g2);
  `FRONT1_LOAD_CONTROLS(g3);
  `FRONT1_LOAD_CONTROLS(g4);
  `FRONT1_LOAD_CONTROLS(g5);
  `undef FRONT1_LOAD_CONTROLS

  wire [44:0] next_front_bus_1_g0 = front1_load_fifo1_g0 ?
       fifo_front_1[44:0] : fifo_front_0[44:0];
  wire [44:0] next_front_bus_1_g1 = front1_load_fifo1_g1 ?
       fifo_front_1[89:45] : fifo_front_0[89:45];
  wire [44:0] next_front_bus_1_g2 = front1_load_fifo1_g2 ?
       fifo_front_1[134:90] : fifo_front_0[134:90];
  wire [44:0] next_front_bus_1_g3 = front1_load_fifo1_g3 ?
       fifo_front_1[179:135] : fifo_front_0[179:135];
  wire [44:0] next_front_bus_1_g4 = front1_load_fifo1_g4 ?
       fifo_front_1[224:180] : fifo_front_0[224:180];
  wire [40:0] next_front_bus_1_g5 = front1_load_fifo1_g5 ?
       fifo_front_1[265:225] : fifo_front_0[265:225];


  (* keep = "true", max_fanout = 48 *) wire front0_we_g0 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g1 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g2 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g3 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g4 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g5 = pop_0 || !front_valid_0_r;

  // Four independent final enables keep the hot address flops local to the
  // consume cone instead of extending a wide payload CE net.
  (* keep = "true", max_fanout = 8 *) wire front0_hot_raddr1_we =
        pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 8 *) wire front0_hot_raddr2_we =
        pop_0 || !front_valid_0_r;

  // front_valid_1 -> front_valid_0 且 pop_1 -> pop_0。因而在 front0 的
  // CE 有效时，只有“单 pop 且 lane1 有效”需要把 lane1 下移；双 pop
  // 或空槽回填都直接取 FIFO0。让 pop_0 只驱动 CE，不再同时穿过宽
  // payload 数据 mux，可缩短 ISSUE -> IBuffer 的反馈路径。
  wire [`IBUF_ENTRY_BUS_WD-1:0] front0_hot_bus_next =
        (!pop_1 && front_valid_1_r) ? front_bus_1_r : fifo_front_0;
  // hot 地址使用独立的 5-bit 数据选择锥，避免其 D 端共享 266-bit
  // payload mux 的高扇出选择节点。选择条件和 payload 完全相同。
  (* keep = "true", max_fanout = 8 *)
  wire [4:0] front0_hot_raddr1_next =
        (!pop_1 && front_valid_1_r) ? front_raddr1_1_hot :
        fifo_front_0[HOT_RADDR1_LSB +: 5];
  (* keep = "true", max_fanout = 8 *)
  wire [4:0] front0_hot_raddr2_next =
        (!pop_1 && front_valid_1_r) ? front_raddr2_1_hot :
        fifo_front_0[HOT_RADDR2_LSB +: 5];

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      head <= {pointer_width{1'b0}};
      tail <= {pointer_width{1'b0}};
      cnt  <= CNT_ZERO;
      front_valid_0_r <= 1'b0;
      front_valid_1_r <= 1'b0;
    end
    else if (flush)
    begin
      head <= {pointer_width{1'b0}};
      tail <= {pointer_width{1'b0}};
      cnt  <= CNT_ZERO;
      front_valid_0_r <= 1'b0;
      front_valid_1_r <= 1'b0;
    end
    else
    begin
      case (head_step)
        2'd1:
          head <= head + {{(pointer_width-1){1'b0}}, 1'b1};
        2'd2:
          head <= head + 2'd2;
        default:
          head <= head;
      endcase

      case (push_count)
        2'd1:
          tail <= tail + {{(pointer_width-1){1'b0}}, 1'b1};
        2'd2:
          tail <= tail + 2'd2;
        default:
          tail <= tail;
      endcase

      cnt <= cnt + {1'b0, push_count} - {1'b0, head_step};
      front_valid_0_r <= next_front_valid_0;
      front_valid_1_r <= next_front_valid_1;
      if (front0_we_g0)
        front_bus_0_g0 <= front0_hot_bus_next[44:0];
      if (front0_we_g1)
        front_bus_0_g1 <= front0_hot_bus_next[89:45];
      if (front0_we_g2)
        front_bus_0_g2 <= front0_hot_bus_next[134:90];
      if (front0_we_g3)
        front_bus_0_g3 <= front0_hot_bus_next[179:135];
      if (front0_we_g4)
        front_bus_0_g4 <= front0_hot_bus_next[224:180];
      if (front0_we_g5)
        front_bus_0_g5 <= front0_hot_bus_next[265:225];
      if (front1_we_g0_a)
        front_bus_1_g0[14:0] <= next_front_bus_1_g0[14:0];
      if (front1_we_g0_b)
        front_bus_1_g0[29:15] <= next_front_bus_1_g0[29:15];
      if (front1_we_g0_c)
        front_bus_1_g0[44:30] <= next_front_bus_1_g0[44:30];
      if (front1_we_g1_a)
        front_bus_1_g1[14:0] <= next_front_bus_1_g1[14:0];
      if (front1_we_g1_b)
        front_bus_1_g1[29:15] <= next_front_bus_1_g1[29:15];
      if (front1_we_g1_c)
        front_bus_1_g1[44:30] <= next_front_bus_1_g1[44:30];
      if (front1_we_g2_a)
        front_bus_1_g2[14:0] <= next_front_bus_1_g2[14:0];
      if (front1_we_g2_b)
        front_bus_1_g2[29:15] <= next_front_bus_1_g2[29:15];
      if (front1_we_g2_c)
        front_bus_1_g2[44:30] <= next_front_bus_1_g2[44:30];
      if (front1_we_g3_a)
        front_bus_1_g3[14:0] <= next_front_bus_1_g3[14:0];
      if (front1_we_g3_b)
      begin
        front_bus_1_g3[29:15] <= next_front_bus_1_g3[29:15];
        front_raddr1_1_hot_bit0_r <= next_front_bus_1_g3[18];
      end
      if (front1_we_g3_c)
        front_bus_1_g3[44:30] <= next_front_bus_1_g3[44:30];
      if (front1_we_g4_a)
        front_bus_1_g4[14:0] <= next_front_bus_1_g4[14:0];
      if (front1_we_g4_b)
        front_bus_1_g4[29:15] <= next_front_bus_1_g4[29:15];
      if (front1_we_g4_c)
        front_bus_1_g4[44:30] <= next_front_bus_1_g4[44:30];
      if (front1_we_g5_a)
        front_bus_1_g5[13:0] <= next_front_bus_1_g5[13:0];
      if (front1_we_g5_b)
        front_bus_1_g5[27:14] <= next_front_bus_1_g5[27:14];
      if (front1_we_g5_c)
        front_bus_1_g5[40:28] <= next_front_bus_1_g5[40:28];
      if (front0_hot_raddr1_we)
        front_raddr1_0_hot_r <=
             front0_hot_raddr1_next;
      if (front0_hot_raddr2_we)
      begin
        front_raddr2_0_hot_r[4:2] <=
             front0_hot_raddr2_next[4:2];
        front_raddr2_0_hot_bit1_r <=
             front0_hot_raddr2_next[1];
        front_raddr2_0_hot_bit0_r <=
             front0_hot_raddr2_next[0];
      end
    end
  end

  // fifo 更新
  // FIFO 有 4 项；最坏一次 push 两项，因此 cnt==2 时仍可安全接收。
  // 只依据本地计数给 ready，避免重新引入 pop/ISSUE 到 IF 的组合链。
  assign push_ready = (cnt <= 3'd2);
  assign full       = !push_ready;

  wire push_fire_0 = push_valid_0 && push_ready;
  wire push_fire_1 = push_valid_1 && push_ready;
  wire [1:0] push_count = push_fire_1 ? 2'd2 : (push_fire_0 ? 2'd1 : 2'd0);

  wire [`DS_DEC_BUS_WD-1:0] dec_bus_0;
  wire [`DS_DEC_BUS_WD-1:0] dec_bus_1;

  inst_decoder u_decoder_0(
                 .inst    (push_bus_0[64:33]),
                 .dec_bus (dec_bus_0)
               );

  inst_decoder u_decoder_1(
                 .inst    (push_bus_1[64:33]),
                 .dec_bus (dec_bus_1)
               );

  wire [`IBUF_ENTRY_BUS_WD-1:0] push_entry_0 = {dec_bus_0, push_bus_0};
  wire [`IBUF_ENTRY_BUS_WD-1:0] push_entry_1 = {dec_bus_1, push_bus_1};

  always @(posedge clk)
  begin
    if (push_fire_0)
      fifo[tail] <= push_entry_0;
    if (push_fire_1)
      fifo[tail_next] <= push_entry_1;
  end
endmodule
