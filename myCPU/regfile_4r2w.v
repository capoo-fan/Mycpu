module regfile_4r2w(
    input  wire        clk,
    input  wire [ 4:0] raddr1,
    output wire [31:0] rdata1,
    input  wire [ 4:0] raddr2,
    output wire [31:0] rdata2,
    input  wire [ 4:0] raddr3,
    output wire [31:0] rdata3,
    input  wire [ 4:0] raddr4,
    output wire [31:0] rdata4,
    input  wire        we0,
    input  wire [ 4:0] waddr0,
    input  wire [31:0] wdata0,
    input  wire        we1,
    input  wire [ 4:0] waddr1,
    input  wire [31:0] wdata1
  );

  reg [31:0] rf[31:0];

  always @(posedge clk)
  begin
    if (we0 && (waddr0 != 5'b0))
      rf[waddr0] <= wdata0;
    if (we1 && (waddr1 != 5'b0))
      rf[waddr1] <= wdata1;
  end

  assign rdata1 = (raddr1 == 5'b0) ? 32'b0 :
                  (we1 && (waddr1 == raddr1)) ? wdata1 :
                  (we0 && (waddr0 == raddr1)) ? wdata0 :
                  rf[raddr1];

  assign rdata2 = (raddr2 == 5'b0) ? 32'b0 :
                  (we1 && (waddr1 == raddr2)) ? wdata1 :
                  (we0 && (waddr0 == raddr2)) ? wdata0 :
                  rf[raddr2];

  assign rdata3 = (raddr3 == 5'b0) ? 32'b0 :
                  (we1 && (waddr1 == raddr3)) ? wdata1 :
                  (we0 && (waddr0 == raddr3)) ? wdata0 :
                  rf[raddr3];

  assign rdata4 = (raddr4 == 5'b0) ? 32'b0 :
                  (we1 && (waddr1 == raddr4)) ? wdata1 :
                  (we0 && (waddr0 == raddr4)) ? wdata0 :
                  rf[raddr4];

endmodule
