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
    output wire                          front_valid_1,
    output wire [`IBUF_ENTRY_BUS_WD-1:0] front_bus_1
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
  reg [`IBUF_ENTRY_BUS_WD-1:0] front_bus_0_r;
  reg [`IBUF_ENTRY_BUS_WD-1:0] front_bus_1_r;

  assign front_valid_0 = front_valid_0_r;
  assign front_valid_1 = front_valid_1_r;
  assign front_bus_0   = front_bus_0_r;
  assign front_bus_1   = front_bus_1_r;

  // 记录 front 发射后的状态，作为 refill 的依据
  wire                          temp_front_valid_0;
  wire                          temp_front_valid_1;
  wire [`IBUF_ENTRY_BUS_WD-1:0] temp_front_bus_0;
  wire [`IBUF_ENTRY_BUS_WD-1:0] temp_front_bus_1;

  // next=>front_vaild_*_r  
  wire                          next_front_valid_0;
  wire                          next_front_valid_1;
  wire [`IBUF_ENTRY_BUS_WD-1:0] next_front_bus_0;
  wire [`IBUF_ENTRY_BUS_WD-1:0] next_front_bus_1;

  wire                          refill_0;
  wire                          refill_1;
  wire [1:0]                    refill_count;


  // pop_shift 只消耗一条指令，pop_clear 消耗两条指令
  wire                          pop_shift = pop_0 && !pop_1;
  wire                          pop_clear = pop_1;
  assign temp_front_valid_0 = pop_shift ? front_valid_1_r :
         pop_clear ? 1'b0 :
         front_valid_0_r;
  assign temp_front_bus_0   = pop_shift ? front_bus_1_r :
         pop_clear ? {`IBUF_ENTRY_BUS_WD{1'b0}} :
         front_bus_0_r;
  assign temp_front_valid_1 = (pop_0 || pop_1) ? 1'b0 : front_valid_1_r;
  assign temp_front_bus_1   = (pop_0 || pop_1) ? {`IBUF_ENTRY_BUS_WD{1'b0}} :
         front_bus_1_r;

  // 判断指令是否需要从fifo中补充到front
  assign refill_0 = !temp_front_valid_0 && (cnt != CNT_ZERO);
  assign refill_1 = !temp_front_valid_1 &&
         ((!temp_front_valid_0 && (cnt > CNT_ONE)) ||
          ( temp_front_valid_0 && (cnt != CNT_ZERO)));
  assign refill_count = {1'b0, refill_0} + {1'b0, refill_1};

  assign next_front_valid_0 = refill_0 ? 1'b1 : temp_front_valid_0;
  assign next_front_bus_0   = refill_0 ? fifo_front_0 : temp_front_bus_0;
  assign next_front_valid_1 = refill_1 ? 1'b1 : temp_front_valid_1;
  assign next_front_bus_1   = refill_1 ? (refill_0 ? fifo_front_1 : fifo_front_0) :temp_front_bus_1;

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      head <= {pointer_width{1'b0}};
      tail <= {pointer_width{1'b0}};
      cnt  <= CNT_ZERO;
      front_valid_0_r <= 1'b0;
      front_valid_1_r <= 1'b0;
      front_bus_0_r   <= {`IBUF_ENTRY_BUS_WD{1'b0}};
      front_bus_1_r   <= {`IBUF_ENTRY_BUS_WD{1'b0}};
    end
    else if (flush)
    begin
      head <= {pointer_width{1'b0}};
      tail <= {pointer_width{1'b0}};
      cnt  <= CNT_ZERO;
      front_valid_0_r <= 1'b0;
      front_valid_1_r <= 1'b0;
      front_bus_0_r   <= {`IBUF_ENTRY_BUS_WD{1'b0}};
      front_bus_1_r   <= {`IBUF_ENTRY_BUS_WD{1'b0}};
    end
    else
    begin
      case (refill_count)
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

      cnt <= cnt + {1'b0, push_count} - {1'b0, refill_count};
      front_valid_0_r <= next_front_valid_0;
      front_valid_1_r <= next_front_valid_1;
      front_bus_0_r   <= next_front_bus_0;
      front_bus_1_r   <= next_front_bus_1;
    end
  end

  // fifo 更新
  assign push_ready = (cnt <= CNT_ONE);
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
