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
  // IBUF 的 0 1 2 条指令
  localparam [PTR_W:0] CNT_ZERO = {(PTR_W+1){1'b0}};
  localparam [PTR_W:0] CNT_ONE  = {{PTR_W{1'b0}}, 1'b1};
  localparam [PTR_W:0] CNT_TWO  = {{(PTR_W-1){1'b0}}, 2'd2};
  localparam [PTR_W:0] CNT_FULL = DEPTH;

  reg [`IBUF_ENTRY_BUS_WD-1:0] fifo [0:DEPTH-1];
  reg [PTR_W-1:0] head;
  reg [PTR_W-1:0] tail;
  reg [PTR_W:0]   cnt;

  wire [`DS_DEC_BUS_WD-1:0] dec_bus_0;
  wire [`DS_DEC_BUS_WD-1:0] dec_bus_1;
  wire [31:0] push_inst_0;
  wire [31:0] push_inst_1;

  assign push_inst_0 = push_bus_0[64:33];
  assign push_inst_1 = push_bus_1[64:33];

  inst_decoder u_decoder_0(
                 .inst    (push_inst_0),
                 .dec_bus (dec_bus_0)
               );

  inst_decoder u_decoder_1(
                 .inst    (push_inst_1),
                 .dec_bus (dec_bus_1)
               );

  wire [`IBUF_ENTRY_BUS_WD-1:0] push_entry_0 = {dec_bus_0, push_bus_0}; // inst_decoder 的信号+IF_stage 的信号
  wire [`IBUF_ENTRY_BUS_WD-1:0] push_entry_1 = {dec_bus_1, push_bus_1};

  wire [PTR_W-1:0] head_next = head + {{(PTR_W-1){1'b0}}, 1'b1};
  wire [PTR_W-1:0] tail_next = tail + {{(PTR_W-1){1'b0}}, 1'b1};

  wire push_fire_0 = push_valid_0 && push_ready;
  wire push_fire_1 = push_valid_1 && push_ready;
  wire [1:0] pop_num  = pop_1 ? 2'd2 : (pop_0 ? 2'd1 : 2'd0);
  wire [1:0] push_num = push_fire_1 ? 2'd2 : (push_fire_0 ? 2'd1 : 2'd0);

  // cnt 判断是否可以取出
  assign front_valid_0 = (cnt != CNT_ZERO);
  assign front_valid_1 = (cnt >  CNT_ONE );

  assign front_bus_0 = front_valid_0 ? fifo[head]      : {`IBUF_ENTRY_BUS_WD{1'b0}};
  assign front_bus_1 = front_valid_1 ? fifo[head_next] : {`IBUF_ENTRY_BUS_WD{1'b0}};

  // 只有在缺少两条指令的时候才 push 两条指令
  assign push_ready = (cnt <= (CNT_FULL - CNT_TWO));
  assign full       = !push_ready;

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
    end
    else if (flush)
    begin
      head <= {PTR_W{1'b0}};
      tail <= {PTR_W{1'b0}};
      cnt  <= CNT_ZERO;
    end
    else
    begin
      case (pop_num)
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
      cnt <= cnt + {1'b0, push_num} - {1'b0, pop_num};
    end
  end

endmodule
