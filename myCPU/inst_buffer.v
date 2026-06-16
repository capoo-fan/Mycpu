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

  localparam DEPTH = 4;
  localparam PTR_W = 2;
  localparam [PTR_W:0] CNT_ZERO = {(PTR_W+1){1'b0}};
  localparam [PTR_W:0] CNT_ONE  = {{PTR_W{1'b0}}, 1'b1};

  reg [`IBUF_ENTRY_BUS_WD-1:0] fifo [0:DEPTH-1];
  reg [PTR_W-1:0] head;
  reg [PTR_W-1:0] tail;
  reg [PTR_W:0]   cnt;

  reg                          front_valid_0_r;
  reg                          front_valid_1_r;
  reg [`IBUF_ENTRY_BUS_WD-1:0] front_bus_0_r;
  reg [`IBUF_ENTRY_BUS_WD-1:0] front_bus_1_r;

  wire [`DS_DEC_BUS_WD-1:0] dec_bus_0;
  wire [`DS_DEC_BUS_WD-1:0] dec_bus_1;
  wire [`IBUF_ENTRY_BUS_WD-1:0] fifo_front_0;
  wire [`IBUF_ENTRY_BUS_WD-1:0] fifo_front_1;

  wire [PTR_W-1:0] head_next = head + {{(PTR_W-1){1'b0}}, 1'b1};
  wire [PTR_W-1:0] tail_next = tail + {{(PTR_W-1){1'b0}}, 1'b1};

  assign fifo_front_0 = fifo[head];
  assign fifo_front_1 = fifo[head_next];

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

  reg                          temp_front_valid_0;
  reg                          temp_front_valid_1;
  reg [`IBUF_ENTRY_BUS_WD-1:0] temp_front_bus_0;
  reg [`IBUF_ENTRY_BUS_WD-1:0] temp_front_bus_1;
  reg                          next_front_valid_0;
  reg                          next_front_valid_1;
  reg [`IBUF_ENTRY_BUS_WD-1:0] next_front_bus_0;
  reg [`IBUF_ENTRY_BUS_WD-1:0] next_front_bus_1;
  reg                          refill_0;
  reg                          refill_1;
  reg [1:0]                    refill_count;

  wire push_fire_0 = push_valid_0 && push_ready;
  wire push_fire_1 = push_valid_1 && push_ready;
  wire [1:0] push_num = push_fire_1 ? 2'd2 : (push_fire_0 ? 2'd1 : 2'd0);

  assign front_valid_0 = front_valid_0_r;
  assign front_valid_1 = front_valid_1_r;
  assign front_bus_0   = front_bus_0_r;
  assign front_bus_1   = front_bus_1_r;

  assign push_ready = (cnt <= CNT_ONE);
  assign full       = !push_ready;

  always @(*)
  begin
    case ({pop_1, pop_0})
      2'b01:
      begin
        temp_front_valid_0 = front_valid_1_r;
        temp_front_bus_0   = front_bus_1_r;
        temp_front_valid_1 = 1'b0;
        temp_front_bus_1   = {`IBUF_ENTRY_BUS_WD{1'b0}};
      end
      2'b10,
      2'b11:
      begin
        temp_front_valid_0 = 1'b0;
        temp_front_bus_0   = {`IBUF_ENTRY_BUS_WD{1'b0}};
        temp_front_valid_1 = 1'b0;
        temp_front_bus_1   = {`IBUF_ENTRY_BUS_WD{1'b0}};
      end
      default:
      begin
        temp_front_valid_0 = front_valid_0_r;
        temp_front_bus_0   = front_bus_0_r;
        temp_front_valid_1 = front_valid_1_r;
        temp_front_bus_1   = front_bus_1_r;
      end
    endcase

    refill_0 = !temp_front_valid_0 && (cnt != CNT_ZERO);
    refill_1 = !temp_front_valid_1 &&
               ((!temp_front_valid_0 && (cnt > CNT_ONE)) ||
                ( temp_front_valid_0 && (cnt != CNT_ZERO)));
    refill_count = {1'b0, refill_0} + {1'b0, refill_1};

    next_front_valid_0 = temp_front_valid_0;
    next_front_bus_0   = temp_front_bus_0;
    next_front_valid_1 = temp_front_valid_1;
    next_front_bus_1   = temp_front_bus_1;

    if (refill_0)
    begin
      next_front_valid_0 = 1'b1;
      next_front_bus_0   = fifo_front_0;
      if (refill_1)
      begin
        next_front_valid_1 = 1'b1;
        next_front_bus_1   = fifo_front_1;
      end
    end
    else if (refill_1)
    begin
      next_front_valid_1 = 1'b1;
      next_front_bus_1   = fifo_front_0;
    end
  end

  always @(posedge clk)
  begin
    if (push_fire_0)
      fifo[tail] <= push_entry_0;
    if (push_fire_1)
      fifo[tail_next] <= push_entry_1;
  end

  always @(posedge clk)
  begin
    if (!resetn)
    begin
      head <= {PTR_W{1'b0}};
      tail <= {PTR_W{1'b0}};
      cnt  <= CNT_ZERO;
      front_valid_0_r <= 1'b0;
      front_valid_1_r <= 1'b0;
      front_bus_0_r   <= {`IBUF_ENTRY_BUS_WD{1'b0}};
      front_bus_1_r   <= {`IBUF_ENTRY_BUS_WD{1'b0}};
    end
    else if (flush)
    begin
      head <= {PTR_W{1'b0}};
      tail <= {PTR_W{1'b0}};
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
          head <= head + {{(PTR_W-1){1'b0}}, 1'b1};
        2'd2:
          head <= head + 2'd2;
        default:
          head <= head;
      endcase

      case (push_num)
        2'd1:
          tail <= tail + {{(PTR_W-1){1'b0}}, 1'b1};
        2'd2:
          tail <= tail + 2'd2;
        default:
          tail <= tail;
      endcase

      cnt <= cnt + {1'b0, push_num} - {1'b0, refill_count};
      front_valid_0_r <= next_front_valid_0;
      front_valid_1_r <= next_front_valid_1;
      front_bus_0_r   <= next_front_bus_0;
      front_bus_1_r   <= next_front_bus_1;
    end
  end

endmodule
