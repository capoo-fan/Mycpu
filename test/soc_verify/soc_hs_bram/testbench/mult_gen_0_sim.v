module mult_gen_0(
  input  wire        CLK,
  input  wire [31:0] A,
  input  wire [31:0] B,
  output wire [63:0] P
);
  reg signed [63:0] pipe0;
  reg signed [63:0] pipe1;
  reg signed [63:0] pipe2;

  always @(posedge CLK) begin
    pipe0 <= $signed(A) * $signed(B);
    pipe1 <= pipe0;
    pipe2 <= pipe1;
  end

  assign P = pipe2;
endmodule
