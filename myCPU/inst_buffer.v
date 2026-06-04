`include "mycpu.vh"

module inst_buffer(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         flush,

    input  wire                         push_valid,
    input  wire [`FS_TO_DS_BUS_WD-1:0]  push_bus,
    output wire                         push_ready,
    output wire                         full,

    input  wire                         pop_ready,
    output wire                         front_valid,
    output wire [`FS_TO_DS_BUS_WD-1:0]  front_bus
  );

  localparam DEPTH = 4;
  localparam PTR_W = 2;
  localparam [PTR_W:0] CNT_ZERO = {(PTR_W+1){1'b0}};
  localparam [PTR_W:0] CNT_FULL = DEPTH;

  reg [`FS_TO_DS_BUS_WD-1:0] fifo_mem [0:DEPTH-1];  // 指令 Buffer
  reg [PTR_W-1:0] head;
  reg [PTR_W-1:0] tail;
  reg [PTR_W:0]   cnt;

  assign front_valid = (cnt != CNT_ZERO);
  assign full        = (cnt == CNT_FULL);

  wire pop_fire  = pop_ready && front_valid;
  assign push_ready = !full;
  wire push_fire = push_valid && push_ready;

  assign front_bus = front_valid ? fifo_mem[head] : {`FS_TO_DS_BUS_WD{1'b0}};

  always @(posedge clk)
  begin
    if (push_fire)
      fifo_mem[tail] <= push_bus;
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
      if (pop_fire)
        head <= head + {{(PTR_W-1){1'b0}}, 1'b1};

      if (push_fire)
        tail <= tail + {{(PTR_W-1){1'b0}}, 1'b1};

      case ({push_fire, pop_fire})
        2'b10: cnt <= cnt + {{PTR_W{1'b0}}, 1'b1};
        2'b01: cnt <= cnt - {{PTR_W{1'b0}}, 1'b1};
        default: cnt <= cnt;
      endcase
    end
  end

endmodule
