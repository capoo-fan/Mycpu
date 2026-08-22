`timescale 1ns / 1ps
`default_nettype none

// Map 模板的单文件接入层。CASTAGNOLI 选择 CRC-32C；WIDTH 的 0/1/2 分别表示
// 处理 in_data 的低 8/16/32 位，SEED 是综合期固定的旧 CRC。
`ifndef LA32_CORE_ONLY
module accelerator_logic #(
    parameter        CASTAGNOLI = 1'b0,
    parameter [1:0]  WIDTH      = 2'd2,
    parameter [31:0] SEED       = 32'b0
) (
    input  wire        clk,
    input  wire        resetn,

    input  wire        in_valid,
    output wire        in_ready,
    input  wire [31:0] in_data,

    output wire        out_valid,
    output wire [31:0] out_data
);

    wire unused_invalid_width;

    la32_crc32 u_selected_operation (
        .clk               (clk),
        .resetn            (resetn),
        .req_valid         (in_valid),
        .req_ready         (in_ready),
        .req_castagnoli    (CASTAGNOLI),
        .req_width         (WIDTH),
        .req_message       (in_data),
        .req_seed          (SEED),
        .rsp_valid         (out_valid),
        .rsp_ready         (1'b1),
        .rsp_checksum      (out_data),
        .rsp_invalid_width (unused_invalid_width)
    );

endmodule
`endif

// 符合 LoongArch CRC 语义、最低位优先的迭代式 CRC-32/CRC-32C 核心。
// req_castagnoli=0 对应 CRC32.{B/H/W}，使用 IEEE 802.3 多项式；
// req_castagnoli=1 对应 CRC32C.{B/H/W}，使用 Castagnoli 多项式。
// req_width：0=.B，仅处理 req_message[7:0]；1=.H，仅处理 req_message[15:0]；
//            2=.W，处理完整的 req_message[31:0]。
// 初始工作值为 req_seed 与零扩展消息的异或结果。
module la32_crc32 (
    input  wire        clk,
    input  wire        resetn,

    input  wire        req_valid,
    output wire        req_ready,
    input  wire        req_castagnoli,
    input  wire [1:0]  req_width,
    input  wire [31:0] req_message,
    input  wire [31:0] req_seed,

    output reg         rsp_valid,
    input  wire        rsp_ready,
    output reg  [31:0] rsp_checksum,
    output reg         rsp_invalid_width
);

    localparam [31:0] POLY_IEEE       = 32'hedb8_8320;
    localparam [31:0] POLY_CASTAGNOLI = 32'h82f6_3b78;

    reg        running;
    reg [5:0]  bits_remaining;
    reg [31:0] checksum_work;
    reg [31:0] polynomial;

    wire [31:0] next_checksum = checksum_work[0] ?
        ((checksum_work >> 1) ^ polynomial) : (checksum_work >> 1);

    assign req_ready = !running && !rsp_valid;

    always @(posedge clk) begin
        if (!resetn) begin
            running           <= 1'b0;
            bits_remaining    <= 6'b0;
            checksum_work     <= 32'b0;
            polynomial        <= POLY_IEEE;
            rsp_valid         <= 1'b0;
            rsp_checksum      <= 32'b0;
            rsp_invalid_width <= 1'b0;
        end
        else begin
            if (rsp_valid && rsp_ready)
                rsp_valid <= 1'b0;

            if (req_valid && req_ready) begin
                rsp_invalid_width <= 1'b0;
                polynomial <= req_castagnoli ?
                    POLY_CASTAGNOLI : POLY_IEEE;

                case (req_width)
                    2'd0: begin
                        checksum_work  <= req_seed ^
                                          {24'b0, req_message[7:0]};
                        bits_remaining <= 6'd8;
                        running        <= 1'b1;
                    end
                    2'd1: begin
                        checksum_work  <= req_seed ^
                                          {16'b0, req_message[15:0]};
                        bits_remaining <= 6'd16;
                        running        <= 1'b1;
                    end
                    2'd2: begin
                        checksum_work  <= req_seed ^ req_message;
                        bits_remaining <= 6'd32;
                        running        <= 1'b1;
                    end
                    default: begin
                        rsp_checksum      <= 32'b0;
                        rsp_invalid_width <= 1'b1;
                        rsp_valid         <= 1'b1;
                    end
                endcase
            end
            else if (running) begin
                checksum_work <= next_checksum;

                if (bits_remaining == 6'd1) begin
                    running      <= 1'b0;
                    rsp_checksum <= next_checksum;
                    rsp_valid    <= 1'b1;
                end
                else begin
                    bits_remaining <= bits_remaining - 6'd1;
                end
            end
        end
    end

endmodule

`default_nettype wire
