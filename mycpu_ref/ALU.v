`timescale 1ns / 1ps
`include "defines.vh"
module ALU (
    input  wire          cpu_clk,
    input  wire          cpu_rstn,
    input  wire [31:0]   A,
    input  wire [31:0]   B,
    input  wire [31:0]   PC,
    input  wire [ 4:0]   alu_op,
    input  wire          mem_suspend,
    output reg  [31:0]   C,
    output wire          suspend,
    input  wire          is_mult
);
wire [31:0] PC4 = PC + 4;

wire [63:0] mul_res;
localparam S_IDLE = 1'b0; 
localparam S_BUSY = 1'b1; 
reg [1:0] mult_cnt;
reg state; // ×´Ì¬¼Ä´æÆ÷
wire mul_suspend = ((state == S_IDLE)&&is_mult)||((state == S_BUSY)&&mult_cnt!=2'b10);    
always @(posedge cpu_clk or negedge cpu_rstn) begin
    if (!cpu_rstn) begin
        state <= S_IDLE;
        mult_cnt <= 2'b00;
    end else begin
        case (state)
            S_IDLE: begin
                if (is_mult) begin
                    state <= S_BUSY;  
                    mult_cnt <= 2'b00;              // ¼ÆÊýÆ÷ÇåÁã
                end 
            end
            S_BUSY: begin
                    if( mult_cnt == 2'b10)begin
                        if(!mem_suspend)begin
                            state <= S_IDLE; 
                            mult_cnt <= 2'b00;
                        end
                    end else begin
                        mult_cnt<= mult_cnt +1'b1;
                    end       
            end
        endcase
    end
end

mult_gen_0 u_mult(  
    .CLK(cpu_clk),
    .A(A),
    .B(B),
    .P(mul_res)
);

wire[31:0] sub; 
assign sub =A - B;
always @(*) begin
    case (alu_op)
        `ALU_ADD: C = A + B;
        `ALU_SUB: C = sub;
        `ALU_OR : C = A | B;
        `ALU_AND: C = A & B;
        `ALU_NOR: C = ~(A | B);
        `ALU_XOR: C= A ^ B;
        `ALU_LUI12: C = B;
        `ALU_SLTU: C = A < B;
        `ALU_SLT: C =(( A[31]&&!B[31])||
                      (!A[31]&&!B[31]&&sub[31])||
                      ( A[31]&& B[31]&&sub[31]));
        `ALU_SLL: C = A << B[4:0];
        `ALU_SRL: C = A >> B[4:0];
        `ALU_SRA: C = ({32{A[31]}}<<(6'd32-{1'b0,B[4:0]}))| (A>>B[4:0]);
        `ALU_JIRL:C = PC4;
        `ALU_BL:  C = PC4;
        `ALU_MUL: C = mul_res[31:0];
        `ALU_MULH: C =  mul_res[63:32];
        default : C = A + B;
    endcase
end
assign suspend = mul_suspend;
endmodule
