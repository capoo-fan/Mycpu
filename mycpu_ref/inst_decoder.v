`timescale 1ns / 1ps
`include "defines.vh"
module inst_decoder (
    input wire [96:0] raw_inst_pack,
    output wire [`DECODED_PACKET_WIDTH-1:0] decoded_pack
);

    wire [31:0] inst = raw_inst_pack[31:0];

    wire        branch_inst_flag;
    wire [2:0]  ext_op;
    wire [2:0]  ram_ext_op;
    wire [4:0]  alu_op;
    wire        rf_we;
    wire [3:0]  ram_we;
    wire        r2_sel;
    wire        wr_sel;
    wire [1:0]  wd_sel;
    wire        rR1_re;
    wire        rR2_re;
    wire        alua_sel;
    wire        alub_sel;
    wire        is_store;

    CU u_CU (
        .din                (inst[31:15]),
        .branch_inst_flag   (branch_inst_flag),
        .ext_op             (ext_op),
        .ram_ext_op         (ram_ext_op),
        .alu_op             (alu_op),
        .rf_we              (rf_we),
        .ram_we             (ram_we),
        .r2_sel             (r2_sel),
        .wr_sel             (wr_sel),
        .wd_sel             (wd_sel),
        .rR1_re             (rR1_re),
        .rR2_re             (rR2_re),
        .alua_sel           (alua_sel),
        .alub_sel           (alub_sel),
        .is_store             (is_store)
    );

    assign decoded_pack = {
        is_store,alub_sel, alua_sel, rR2_re, rR1_re, wd_sel, wr_sel, r2_sel, ram_we,
        rf_we, alu_op, ram_ext_op, ext_op, branch_inst_flag,
        raw_inst_pack[96:0] 
    };

endmodule