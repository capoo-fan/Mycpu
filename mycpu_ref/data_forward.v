`timescale 1ns / 1ps
`include "defines.vh"
module data_forward(
    input  wire [ 4:0] id0_rR1,
    input  wire [ 4:0] id0_rR2,
    input  wire        id0_rR1_re,
    input  wire        id0_rR2_re,
    
    input  wire [ 4:0] id1_rR1,
    input  wire [ 4:0] id1_rR2,
    input  wire        id1_rR1_re,
    input  wire        id1_rR2_re,


    input  wire [31:0] ex0_wd,
    input  wire [ 4:0] ex0_wr,
    input  wire        ex0_we,
    input  wire        ex0_is_load, 
    input  wire [31:0] mem0_wd,
    input  wire [ 4:0] mem0_wr,
    input  wire        mem0_we,

    input  wire [31:0] ex1_wd,
    input  wire [ 4:0] ex1_wr,
    input  wire        ex1_we,
    input  wire        ex1_is_load,
    input  wire [31:0] mem1_wd,
    input  wire [ 4:0] mem1_wr,
    input  wire        mem1_we,

    output wire        load_use_stall_0,
    output wire        load_use_stall_1,
    
    output wire [31:0] fd0_rD1,
    output wire        fd0_rD1_sel,
    output wire [31:0] fd0_rD2,
    output wire        fd0_rD2_sel,

    output wire [31:0] fd1_rD1,
    output wire        fd1_rD1_sel,
    output wire [31:0] fd1_rD2,
    output wire        fd1_rD2_sel,
    
    output wire        load_use0_rd0,
    output wire        load_use0_rd1,
    output wire        load_use1_rd0,
    output wire        load_use1_rd1
);


// --- »ù´¡Ã°ÏÕ¼ì²â for inst0.rR1 ---
wire ex0_hazard_0_1  = id0_rR1_re && ex0_we  && (ex0_wr  != 5'b0) && (id0_rR1 == ex0_wr);
wire ex1_hazard_0_1  = id0_rR1_re && ex1_we  && (ex1_wr  != 5'b0) && (id0_rR1 == ex1_wr);
wire mem0_hazard_0_1 = id0_rR1_re && mem0_we && (mem0_wr != 5'b0) && (id0_rR1 == mem0_wr);
wire mem1_hazard_0_1 = id0_rR1_re && mem1_we && (mem1_wr != 5'b0) && (id0_rR1 == mem1_wr);

// --- »ù´¡Ã°ÏÕ¼ì²â for inst0.rR2 ---
wire ex0_hazard_0_2  = id0_rR2_re && ex0_we  && (ex0_wr  != 5'b0) && (id0_rR2 == ex0_wr);
wire ex1_hazard_0_2  = id0_rR2_re && ex1_we  && (ex1_wr  != 5'b0) && (id0_rR2 == ex1_wr);
wire mem0_hazard_0_2 = id0_rR2_re && mem0_we && (mem0_wr != 5'b0) && (id0_rR2 == mem0_wr);
wire mem1_hazard_0_2 = id0_rR2_re && mem1_we && (mem1_wr != 5'b0) && (id0_rR2 == mem1_wr);

// --- »ù´¡Ã°ÏÕ¼ì²â for inst1.rR1 ---
wire ex0_hazard_1_1  = id1_rR1_re && ex0_we  && (ex0_wr  != 5'b0) && (id1_rR1 == ex0_wr);
wire ex1_hazard_1_1  = id1_rR1_re && ex1_we  && (ex1_wr  != 5'b0) && (id1_rR1 == ex1_wr);
wire mem0_hazard_1_1 = id1_rR1_re && mem0_we && (mem0_wr != 5'b0) && (id1_rR1 == mem0_wr);
wire mem1_hazard_1_1 = id1_rR1_re && mem1_we && (mem1_wr != 5'b0) && (id1_rR1 == mem1_wr);

// --- »ù´¡Ã°ÏÕ¼ì²â for inst1.rR2 ---
wire ex0_hazard_1_2  = id1_rR2_re && ex0_we  && (ex0_wr  != 5'b0) && (id1_rR2 == ex0_wr);
wire ex1_hazard_1_2  = id1_rR2_re && ex1_we  && (ex1_wr  != 5'b0) && (id1_rR2 == ex1_wr);
wire mem0_hazard_1_2 = id1_rR2_re && mem0_we && (mem0_wr != 5'b0) && (id1_rR2 == mem0_wr);
wire mem1_hazard_1_2 = id1_rR2_re && mem1_we && (mem1_wr != 5'b0) && (id1_rR2 == mem1_wr);


// Load-Use Ã°ÏÕ¼ì²â
assign load_use_stall_0 = (ex0_is_load && (ex0_hazard_0_1 || ex0_hazard_0_2)) || 
                          (ex1_is_load && (ex1_hazard_0_1 || ex1_hazard_0_2));

assign load_use_stall_1 = (ex0_is_load && (ex0_hazard_1_1 || ex0_hazard_1_2)) ||
                          (ex1_is_load && (ex1_hazard_1_1 || ex1_hazard_1_2));
                          
assign load_use0_rd0 = (ex0_is_load && ex0_hazard_0_1) || 
                       (ex1_is_load && ex1_hazard_0_1);

assign load_use0_rd1 = (ex0_is_load && ex0_hazard_0_2) ||
                       (ex1_is_load && ex1_hazard_0_2);

assign load_use1_rd0 = (ex0_is_load && ex0_hazard_1_1) ||
                       (ex1_is_load && ex1_hazard_1_1);

assign load_use1_rd1 = (ex0_is_load && ex0_hazard_1_2) ||
                       (ex1_is_load && ex1_hazard_1_2);

wire fwd_ex1_0_1  = ex1_hazard_0_1;
wire fwd_ex0_0_1  = ex0_hazard_0_1  && !ex1_hazard_0_1;
wire fwd_mem1_0_1 = mem1_hazard_0_1 && !ex1_hazard_0_1  && !ex0_hazard_0_1;
wire fwd_mem0_0_1 = mem0_hazard_0_1 && !ex1_hazard_0_1  && !ex0_hazard_0_1  && !mem1_hazard_0_1;


wire fwd_ex1_0_2  = ex1_hazard_0_2;
wire fwd_ex0_0_2  = ex0_hazard_0_2  && !ex1_hazard_0_2;
wire fwd_mem1_0_2 = mem1_hazard_0_2 && !ex1_hazard_0_2  && !ex0_hazard_0_2;
wire fwd_mem0_0_2 = mem0_hazard_0_2 && !ex1_hazard_0_2  && !ex0_hazard_0_2  && !mem1_hazard_0_2;


wire fwd_ex1_1_1  = ex1_hazard_1_1;
wire fwd_ex0_1_1  = ex0_hazard_1_1  && !ex1_hazard_1_1;
wire fwd_mem1_1_1 = mem1_hazard_1_1 && !ex1_hazard_1_1  && !ex0_hazard_1_1;
wire fwd_mem0_1_1 = mem0_hazard_1_1 && !ex1_hazard_1_1  && !ex0_hazard_1_1  && !mem1_hazard_1_1;


wire fwd_ex1_1_2  = ex1_hazard_1_2;
wire fwd_ex0_1_2  = ex0_hazard_1_2  && !ex1_hazard_1_2;
wire fwd_mem1_1_2 = mem1_hazard_1_2 && !ex1_hazard_1_2  && !ex0_hazard_1_2;
wire fwd_mem0_1_2 = mem0_hazard_1_2 && !ex1_hazard_1_2  && !ex0_hazard_1_2  && !mem1_hazard_1_2;


// --- Êä³ö for inst0 ---
assign fd0_rD1_sel = fwd_ex1_0_1 | fwd_ex0_0_1 | fwd_mem1_0_1 | fwd_mem0_0_1;
assign fd0_rD2_sel = fwd_ex1_0_2 | fwd_ex0_0_2 | fwd_mem1_0_2 | fwd_mem0_0_2;

assign fd0_rD1 = ({32{fwd_ex1_0_1}}  & ex1_wd)  | ({32{fwd_ex0_0_1}}  & ex0_wd)  |
                 ({32{fwd_mem1_0_1}} & mem1_wd) | ({32{fwd_mem0_0_1}} & mem0_wd);

assign fd0_rD2 = ({32{fwd_ex1_0_2}}  & ex1_wd)  | ({32{fwd_ex0_0_2}}  & ex0_wd)  |
                 ({32{fwd_mem1_0_2}} & mem1_wd) | ({32{fwd_mem0_0_2}} & mem0_wd);

// --- Êä³ö for inst1 ---
assign fd1_rD1_sel = fwd_ex1_1_1 | fwd_ex0_1_1 | fwd_mem1_1_1 | fwd_mem0_1_1;
assign fd1_rD2_sel = fwd_ex1_1_2 | fwd_ex0_1_2 | fwd_mem1_1_2 | fwd_mem0_1_2;

assign fd1_rD1 = ({32{fwd_ex1_1_1}}  & ex1_wd)  | ({32{fwd_ex0_1_1}}  & ex0_wd)  |
                 ({32{fwd_mem1_1_1}} & mem1_wd) | ({32{fwd_mem0_1_1}} & mem0_wd);

assign fd1_rD2 = ({32{fwd_ex1_1_2}}  & ex1_wd)  | ({32{fwd_ex0_1_2}}  & ex0_wd)  |
                 ({32{fwd_mem1_1_2}} & mem1_wd) | ({32{fwd_mem0_1_2}} & mem0_wd);

endmodule
