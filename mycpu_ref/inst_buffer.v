`timescale 1ns/1ps
`include "defines.vh" 

`define ORIG_WIDTH 97              
`define DEPTH 4            
`define PTR_W  2
module inst_buffer (
    input  wire               clk,
    input  wire               rstn,
    input  wire               flush,

    input  wire               push1_valid,
    input  wire [`ORIG_WIDTH-1:0]   push1_inst,
    input  wire               push2_valid,
    input  wire [`ORIG_WIDTH-1:0]   push2_inst,

    input  wire               pop1,
    input  wire               pop2,
                                        
    // ---------- 输出译码后的指令包 ----------
    output reg                front1_valid,
    output reg  [`DECODED_PACKET_WIDTH-1:0]   front1_inst,
    output reg                front2_valid,
    output reg  [`DECODED_PACKET_WIDTH-1:0]   front2_inst, 

    output wire               full
);


reg  [`ORIG_WIDTH-1:0] fifo_mem [`DEPTH-1:0];
reg  [`PTR_W-1:0] head;
reg  [`PTR_W-1:0] tail;
reg  [`PTR_W  :0] cnt;

wire [1:0] push_num = push1_valid + push2_valid;
assign full = cnt > (`DEPTH - 2);


wire [`DECODED_PACKET_WIDTH-1:0] decoded_pack1, decoded_pack2;

inst_decoder decoder1 (
    .raw_inst_pack(fifo_mem[head]),
    .decoded_pack(decoded_pack1)
);

inst_decoder decoder2 (
    .raw_inst_pack(fifo_mem[head + 1'b1]),
    .decoded_pack(decoded_pack2)
);


wire [1:0]       refill_count; 
reg              next_front1_valid, next_front2_valid;
reg [`DECODED_PACKET_WIDTH-1:0] next_front1_inst, next_front2_inst;
reg              temp_front1_valid, temp_front2_valid;
reg [`DECODED_PACKET_WIDTH-1:0] temp_front1_inst, temp_front2_inst;

always @(*) begin
    case ({pop2, pop1})
        2'b00: begin // 无消耗
            temp_front1_valid = front1_valid; temp_front1_inst = front1_inst;
            temp_front2_valid = front2_valid; temp_front2_inst = front2_inst;
        end
        2'b01: begin // 消耗1条，左移
            temp_front1_valid = front2_valid; temp_front1_inst = front2_inst;
            temp_front2_valid = 1'b0;         temp_front2_inst = 'b0;
        end
        2'b11: begin // 消耗2条，清空
            temp_front1_valid = 1'b0;         temp_front1_inst = 'b0;
            temp_front2_valid = 1'b0;         temp_front2_inst = 'b0;
        end
        default: begin 
            temp_front1_valid = front1_valid; temp_front1_inst = front1_inst;
            temp_front2_valid = front2_valid; temp_front2_inst = front2_inst;
        end
    endcase

    next_front1_valid = temp_front1_valid; next_front1_inst = temp_front1_inst;
    next_front2_valid = temp_front2_valid; next_front2_inst = temp_front2_inst;

    if (!temp_front1_valid && (cnt > 0)) begin
        next_front1_valid = 1'b1;
        next_front1_inst  = decoded_pack1;
        if (!temp_front2_valid && (cnt > 1)) begin
            next_front2_valid = 1'b1;
            next_front2_inst  = decoded_pack2;
        end
    end 
    else if (!temp_front2_valid && (cnt > 0)) begin
        next_front2_valid = 1'b1;
        next_front2_inst  = decoded_pack1; 
    end
end

assign refill_count = (next_front1_valid & !temp_front1_valid) + 
                      (next_front2_valid & !temp_front2_valid);


always @(posedge clk or negedge rstn) begin
    if (!rstn) begin
        head <= 0;
        tail <= 0;
        cnt  <= 0;
        front1_valid <= 1'b0;
        front2_valid <= 1'b0;
        front1_inst  <= 'b0;
        front2_inst  <= 'b0;
    end else if(flush) begin
        head <= 0;
        tail <= 0;
        cnt  <= 0;
        front1_valid <= 1'b0;
        front2_valid <= 1'b0;
        front1_inst  <= 'b0;
        front2_inst  <= 'b0;    
    end else begin
        head <= head + refill_count; 
        tail <= tail + push_num;
        cnt  <= cnt + push_num - refill_count; 
        

        if (push1_valid) begin
            fifo_mem[tail] <= push1_inst;
        end
        if (push2_valid) begin
            fifo_mem[tail + 1'b1] <= push2_inst;
        end

        front1_valid <= next_front1_valid;
        front1_inst  <= next_front1_inst;
        front2_valid <= next_front2_valid;
        front2_inst  <= next_front2_inst;
    end
end

endmodule