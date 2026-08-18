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
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg [4:0] front_raddr1_1_hot_r;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 16 *)
  reg [4:0] front_raddr2_1_hot_r;

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
                               front_raddr2_0_hot_r[0]};
  assign front_raddr1_1_hot = front_raddr1_1_hot_r;
  assign front_raddr2_1_hot = front_raddr2_1_hot_r;

  localparam integer HOT_RADDR1_LSB = `FS_TO_DS_BUS_WD + 56;
  localparam integer HOT_RADDR2_LSB = `FS_TO_DS_BUS_WD + 51;


  reg                           next_front_valid_0;
  reg                           next_front_valid_1;
  reg  [`IBUF_ENTRY_BUS_WD-1:0] next_front_bus_0;

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
    next_front_bus_0   = front_bus_0_r;

    if (pop_1)
    begin
      next_front_valid_0 = (cnt != CNT_ZERO);
      next_front_valid_1 = (cnt > CNT_ONE);
      next_front_bus_0   = fifo_front_0;
    end
    else if (pop_0)
    begin
      if (front_valid_1_r)
      begin
        next_front_valid_0 = 1'b1;
        next_front_bus_0   = front_bus_1_r;
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
        next_front_bus_0   = fifo_front_0;
      end
    end
    else if (!front_valid_0_r)
    begin
      next_front_valid_0 = (cnt != CNT_ZERO);
      next_front_valid_1 = (cnt > CNT_ONE);
      next_front_bus_0   = fifo_front_0;
    end
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
    begin
      next_front_valid_1 = 1'b1;
    end
  end

  reg [44:0] next_front_bus_1_g0;
  reg [44:0] next_front_bus_1_g1;
  reg [44:0] next_front_bus_1_g2;
  reg [44:0] next_front_bus_1_g3;
  reg [44:0] next_front_bus_1_g4;
  reg [40:0] next_front_bus_1_g5;

  always @(*)
  begin
    next_front_bus_1_g0 = front_bus_1_g0;
    if (pop_1)
      next_front_bus_1_g0 = fifo_front_1[44:0];
    else if (pop_0)
    begin
      if (front_valid_1_r && (cnt != CNT_ZERO))
        next_front_bus_1_g0 = fifo_front_0[44:0];
      else if (!front_valid_1_r)
        next_front_bus_1_g0 = fifo_front_1[44:0];
    end
    else if (!front_valid_0_r)
      next_front_bus_1_g0 = fifo_front_1[44:0];
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
      next_front_bus_1_g0 = fifo_front_0[44:0];
  end

  always @(*)
  begin
    next_front_bus_1_g1 = front_bus_1_g1;
    if (pop_1)
      next_front_bus_1_g1 = fifo_front_1[89:45];
    else if (pop_0)
    begin
      if (front_valid_1_r && (cnt != CNT_ZERO))
        next_front_bus_1_g1 = fifo_front_0[89:45];
      else if (!front_valid_1_r)
        next_front_bus_1_g1 = fifo_front_1[89:45];
    end
    else if (!front_valid_0_r)
      next_front_bus_1_g1 = fifo_front_1[89:45];
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
      next_front_bus_1_g1 = fifo_front_0[89:45];
  end

  always @(*)
  begin
    next_front_bus_1_g2 = front_bus_1_g2;
    if (pop_1)
      next_front_bus_1_g2 = fifo_front_1[134:90];
    else if (pop_0)
    begin
      if (front_valid_1_r && (cnt != CNT_ZERO))
        next_front_bus_1_g2 = fifo_front_0[134:90];
      else if (!front_valid_1_r)
        next_front_bus_1_g2 = fifo_front_1[134:90];
    end
    else if (!front_valid_0_r)
      next_front_bus_1_g2 = fifo_front_1[134:90];
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
      next_front_bus_1_g2 = fifo_front_0[134:90];
  end

  always @(*)
  begin
    next_front_bus_1_g3 = front_bus_1_g3;
    if (pop_1)
      next_front_bus_1_g3 = fifo_front_1[179:135];
    else if (pop_0)
    begin
      if (front_valid_1_r && (cnt != CNT_ZERO))
        next_front_bus_1_g3 = fifo_front_0[179:135];
      else if (!front_valid_1_r)
        next_front_bus_1_g3 = fifo_front_1[179:135];
    end
    else if (!front_valid_0_r)
      next_front_bus_1_g3 = fifo_front_1[179:135];
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
      next_front_bus_1_g3 = fifo_front_0[179:135];
  end

  always @(*)
  begin
    next_front_bus_1_g4 = front_bus_1_g4;
    if (pop_1)
      next_front_bus_1_g4 = fifo_front_1[224:180];
    else if (pop_0)
    begin
      if (front_valid_1_r && (cnt != CNT_ZERO))
        next_front_bus_1_g4 = fifo_front_0[224:180];
      else if (!front_valid_1_r)
        next_front_bus_1_g4 = fifo_front_1[224:180];
    end
    else if (!front_valid_0_r)
      next_front_bus_1_g4 = fifo_front_1[224:180];
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
      next_front_bus_1_g4 = fifo_front_0[224:180];
  end

  always @(*)
  begin
    next_front_bus_1_g5 = front_bus_1_g5;
    if (pop_1)
      next_front_bus_1_g5 = fifo_front_1[265:225];
    else if (pop_0)
    begin
      if (front_valid_1_r && (cnt != CNT_ZERO))
        next_front_bus_1_g5 = fifo_front_0[265:225];
      else if (!front_valid_1_r)
        next_front_bus_1_g5 = fifo_front_1[265:225];
    end
    else if (!front_valid_0_r)
      next_front_bus_1_g5 = fifo_front_1[265:225];
    else if (!front_valid_1_r && (cnt != CNT_ZERO))
      next_front_bus_1_g5 = fifo_front_0[265:225];
  end


  (* keep = "true", max_fanout = 48 *) wire front0_we_g0 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g1 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g2 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g3 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g4 = pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 48 *) wire front0_we_g5 = pop_0 || !front_valid_0_r;

  // pop_1 蕴含 pop_0。若 FIFO 非空，下面的 pop_0 分支已经装入新
  // front1；若 FIFO 为空，front1 将变为 invalid，无需改写 payload。
  // 因而不让较长的 lane1 发射判定直接驱动这些宽寄存器的 CE。
  (* keep = "true", max_fanout = 48 *) wire front1_we_g0 =
        (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) ||
        (!pop_0 &&
         (!front_valid_0_r || (!front_valid_1_r && (cnt != CNT_ZERO))));
  (* keep = "true", max_fanout = 48 *) wire front1_we_g1 =
        (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) ||
        (!pop_0 &&
         (!front_valid_0_r || (!front_valid_1_r && (cnt != CNT_ZERO))));
  (* keep = "true", max_fanout = 48 *) wire front1_we_g2 =
        (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) ||
        (!pop_0 &&
         (!front_valid_0_r || (!front_valid_1_r && (cnt != CNT_ZERO))));
  (* keep = "true", max_fanout = 48 *) wire front1_we_g3 =
        (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) ||
        (!pop_0 &&
         (!front_valid_0_r || (!front_valid_1_r && (cnt != CNT_ZERO))));
  (* keep = "true", max_fanout = 48 *) wire front1_we_g4 =
        (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) ||
        (!pop_0 &&
         (!front_valid_0_r || (!front_valid_1_r && (cnt != CNT_ZERO))));
  (* keep = "true", max_fanout = 48 *) wire front1_we_g5 =
        (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) ||
        (!pop_0 &&
         (!front_valid_0_r || (!front_valid_1_r && (cnt != CNT_ZERO))));

  // Four independent final enables keep the hot address flops local to the
  // consume cone instead of extending a wide payload CE net.
  (* keep = "true", max_fanout = 8 *) wire front0_hot_raddr1_we =
        pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 8 *) wire front0_hot_raddr2_we =
        pop_0 || !front_valid_0_r;
  (* keep = "true", max_fanout = 8 *) wire front1_hot_raddr1_we =
        (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) ||
        (!pop_0 &&
         (!front_valid_0_r || (!front_valid_1_r && (cnt != CNT_ZERO))));
  (* keep = "true", max_fanout = 8 *) wire front1_hot_raddr2_we =
        (pop_0 && (!front_valid_1_r || (cnt != CNT_ZERO))) ||
        (!pop_0 &&
         (!front_valid_0_r || (!front_valid_1_r && (cnt != CNT_ZERO))));

  // hot 地址镜像直接选择将进入 front0 的窄字段，避免 ISSUE consume
  // 回环再次穿过完整 payload mux；FIFO 状态与发射条件保持不变。
  wire [`IBUF_ENTRY_BUS_WD-1:0] front0_hot_bus_next =
        pop_1 ? fifo_front_0 :
        ((pop_0 && front_valid_1_r) ? front_bus_1_r : fifo_front_0);

  // lane1 hot 地址只在 refill 时使用 FIFO 头项。直接在 10-bit 窄字段上
  // 完成选择，避免 ISSUE pop/RAW 控制先穿过 45-bit payload next mux，
  // 再到 hot 镜像寄存器。front1_hot_*_we 为 0 时该值不被采样。
  wire [9:0] fifo_front_0_hot_addrs =
        {fifo_front_0[HOT_RADDR1_LSB +: 5],
         fifo_front_0[HOT_RADDR2_LSB +: 5]};
  wire [9:0] fifo_front_1_hot_addrs =
        {fifo_front_1[HOT_RADDR1_LSB +: 5],
         fifo_front_1[HOT_RADDR2_LSB +: 5]};
  (* max_fanout = 12 *) wire [9:0] front1_hot_addrs_next =
        pop_1 ? fifo_front_1_hot_addrs :
        pop_0 ? (front_valid_1_r ? fifo_front_0_hot_addrs :
                                   fifo_front_1_hot_addrs) :
        !front_valid_0_r ? fifo_front_1_hot_addrs :
                           fifo_front_0_hot_addrs;
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
        front_bus_0_g0 <= next_front_bus_0[44:0];
      if (front0_we_g1)
        front_bus_0_g1 <= next_front_bus_0[89:45];
      if (front0_we_g2)
        front_bus_0_g2 <= next_front_bus_0[134:90];
      if (front0_we_g3)
        front_bus_0_g3 <= next_front_bus_0[179:135];
      if (front0_we_g4)
        front_bus_0_g4 <= next_front_bus_0[224:180];
      if (front0_we_g5)
        front_bus_0_g5 <= next_front_bus_0[265:225];
      if (front1_we_g0)
        front_bus_1_g0 <= next_front_bus_1_g0;
      if (front1_we_g1)
        front_bus_1_g1 <= next_front_bus_1_g1;
      if (front1_we_g2)
        front_bus_1_g2 <= next_front_bus_1_g2;
      if (front1_we_g3)
        front_bus_1_g3 <= next_front_bus_1_g3;
      if (front1_we_g4)
        front_bus_1_g4 <= next_front_bus_1_g4;
      if (front1_we_g5)
        front_bus_1_g5 <= next_front_bus_1_g5;
      if (front0_hot_raddr1_we)
        front_raddr1_0_hot_r <=
             front0_hot_bus_next[HOT_RADDR1_LSB +: 5];
      if (front0_hot_raddr2_we)
      begin
        front_raddr2_0_hot_r[4:2] <=
             front0_hot_bus_next[HOT_RADDR2_LSB+2 +: 3];
        front_raddr2_0_hot_bit1_r <=
             front0_hot_bus_next[HOT_RADDR2_LSB+1];
        front_raddr2_0_hot_r[0] <=
             front0_hot_bus_next[HOT_RADDR2_LSB];
      end
      if (front1_hot_raddr1_we)
        front_raddr1_1_hot_r <=
             front1_hot_addrs_next[9:5];
      if (front1_hot_raddr2_we)
        front_raddr2_1_hot_r <= front1_hot_addrs_next[4:0];
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
