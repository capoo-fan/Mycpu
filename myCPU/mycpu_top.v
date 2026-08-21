`timescale 1ns / 1ps
`default_nettype none

// Accelerator-oriented LoongArch32 core.
// Exactly one instruction is in flight. The architectural stages are
// serialized, so every RAW dependency waits until the producer reaches WB.
module mycpu_top #(
    parameter [31:0] ACCEL_ARRAY_BEGIN = 32'h8040_0000,
    parameter [31:0] ACCEL_ARRAY_END   = 32'h8050_0000,
    parameter [31:0] ACCEL_RESULT_ADDR = 32'h8050_0000
)(
    input  wire        clk,
    input  wire        resetn,
    output wire        inst_sram_req,
    output wire        inst_sram_wr,
    output wire [ 1:0] inst_sram_size,
    output wire [ 3:0] inst_sram_wstrb,
    output wire [31:0] inst_sram_addr,
    output wire [31:0] inst_sram_wdata,
    input  wire        inst_sram_addr_ok,
    input  wire        inst_sram_data_ok,
    input  wire [31:0] inst_sram_rdata,
    output wire        data_sram_req,
    output wire        data_sram_wr,
    output wire [ 1:0] data_sram_size,
    output wire [ 3:0] data_sram_wstrb,
    output wire [31:0] data_sram_addr,
    output wire [31:0] data_sram_wdata,
    input  wire        data_sram_addr_ok,
    input  wire        data_sram_data_ok,
    input  wire [31:0] data_sram_rdata,
    output wire [31:0] debug_wb_pc,
    output wire [ 3:0] debug_wb_rf_we,
    output wire [ 4:0] debug_wb_rf_wnum,
    output wire [31:0] debug_wb_rf_wdata
);

    localparam [3:0]
        ST_IF_REQ     = 4'd0,
        ST_IF_WAIT    = 4'd1,
        ST_EX         = 4'd2,
        ST_MUL_WAIT   = 4'd3,
        ST_MEM_REQ    = 4'd4,
        ST_MEM_WAIT   = 4'd5,
        ST_WB         = 4'd6,
        ST_ACCEL_WAIT = 4'd7,
        ST_RF         = 4'd8;

    reg [3:0]  state;
    reg [31:0] pc;
    reg [31:0] inst;
    reg [31:0] src1_value;
    reg [31:0] src2_value;
    // Kept as a local simulation-observation alias; top-level debug ports stay
    // constant and no PC route leaves the CPU.
    wire [31:0] pc_out = pc;
    reg [ 4:0] wb_dest;
    reg [31:0] wb_data;
    reg        mem_is_load;
    reg [ 1:0] mem_size;
    reg [ 3:0] mem_wstrb;
    reg [31:0] mem_addr;
    reg [31:0] mem_wdata;
    reg        mem_ld_byte;
    reg        mem_ld_half;
    reg        mem_ld_sign;
    reg [ 1:0] mul_wait_count;

    wire [ 5:0] op_31_26 = inst[31:26];
    wire [ 3:0] op_25_22 = inst[25:22];
    wire [ 1:0] op_21_20 = inst[21:20];
    wire [ 4:0] op_19_15 = inst[19:15];
    wire [ 4:0] rd       = inst[ 4: 0];
    wire [ 4:0] rj       = inst[ 9: 5];
    wire [ 4:0] rk       = inst[14:10];
    wire [11:0] i12      = inst[21:10];
    wire [19:0] i20      = inst[24: 5];
    wire [15:0] i16      = inst[25:10];
    wire [25:0] i26      = {inst[9:0], inst[25:10]};

    wire inst_add_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h00);
    wire inst_sub_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h02);
    wire inst_slt   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h04);
    wire inst_sltu  = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h05);
    wire inst_nor   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h08);
    wire inst_and   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h09);
    wire inst_or    = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h0a);
    wire inst_xor   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h0b);
    wire inst_sll_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h0e);
    wire inst_srl_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h0f);
    wire inst_sra_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h10);
    wire inst_mul_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                      (op_21_20 == 2'h1) && (op_19_15 == 5'h18);
    wire inst_slli_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) &&
                       (op_21_20 == 2'h0) && (op_19_15 == 5'h01);
    wire inst_srli_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) &&
                       (op_21_20 == 2'h0) && (op_19_15 == 5'h09);
    wire inst_srai_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) &&
                       (op_21_20 == 2'h0) && (op_19_15 == 5'h11);
    wire inst_slti   = (op_31_26 == 6'h00) && (op_25_22 == 4'h8);
    wire inst_sltui  = (op_31_26 == 6'h00) && (op_25_22 == 4'h9);
    wire inst_addi_w = (op_31_26 == 6'h00) && (op_25_22 == 4'ha);
    wire inst_andi   = (op_31_26 == 6'h00) && (op_25_22 == 4'hd);
    wire inst_ori    = (op_31_26 == 6'h00) && (op_25_22 == 4'he);
    wire inst_xori   = (op_31_26 == 6'h00) && (op_25_22 == 4'hf);

    wire inst_ld_b  = (op_31_26 == 6'h0a) && (op_25_22 == 4'h0);
    wire inst_ld_h  = (op_31_26 == 6'h0a) && (op_25_22 == 4'h1);
    wire inst_ld_w  = (op_31_26 == 6'h0a) && (op_25_22 == 4'h2);
    wire inst_st_b  = (op_31_26 == 6'h0a) && (op_25_22 == 4'h4);
    wire inst_st_h  = (op_31_26 == 6'h0a) && (op_25_22 == 4'h5);
    wire inst_st_w  = (op_31_26 == 6'h0a) && (op_25_22 == 4'h6);
    wire inst_ld_bu = (op_31_26 == 6'h0a) && (op_25_22 == 4'h8);
    wire inst_ld_hu = (op_31_26 == 6'h0a) && (op_25_22 == 4'h9);

    wire inst_lu12i_w   = (op_31_26 == 6'h05) && !inst[25];
    wire inst_pcaddu12i = (op_31_26 == 6'h07) && !inst[25];
    wire inst_jirl = (op_31_26 == 6'h13);
    wire inst_b    = (op_31_26 == 6'h14);
    wire inst_bl   = (op_31_26 == 6'h15);
    wire inst_beq  = (op_31_26 == 6'h16);
    wire inst_bne  = (op_31_26 == 6'h17);
    wire inst_blt  = (op_31_26 == 6'h18);
    wire inst_bge  = (op_31_26 == 6'h19);
    wire inst_bltu = (op_31_26 == 6'h1a);
    wire inst_bgeu = (op_31_26 == 6'h1b);

    // Read-only compatibility behavior: zero advertises no cache/MMU, so the
    // supervisor takes its direct-address uncached path without CSR/CACOP.
    wire inst_cpucfg = (inst[31:15] == 17'b0) && (rk == 5'h1b);
    wire inst_accel  = (inst == 32'h0020_0000);

    wire src2_is_rd = inst_beq | inst_bne | inst_blt | inst_bge |
                      inst_bltu | inst_bgeu | inst_st_b | inst_st_h | inst_st_w;
    wire [31:0] rf_rdata1;
    wire [31:0] rf_rdata2;
    wire        rf_we = (state == ST_WB);

    regfile_2r1w u_regfile(
        .clk(clk), .raddr1(rj), .rdata1(rf_rdata1),
        .raddr2(src2_is_rd ? rd : rk), .rdata2(rf_rdata2),
        .we(rf_we), .waddr(wb_dest), .wdata(wb_data)
    );

    // The only multiplier in the CPU. The existing three-cycle IP remains;
    // MULH/DIV/MOD and the complete lane1 multiplier are absent.
    wire [31:0] mul_result;
    mult_gen_0 u_mul(
        .CLK(clk), .A(src1_value), .B(src2_value), .P(mul_result)
    );

    wire [31:0] imm_si12 = {{20{i12[11]}}, i12};
    wire [31:0] imm_ui12 = {20'b0, i12};
    wire [31:0] branch_offs_16 = {{14{i16[15]}}, i16, 2'b0};
    wire [31:0] branch_offs_26 = {{4{i26[25]}}, i26, 2'b0};
    wire [31:0] effective_addr = src1_value + imm_si12;
    wire branch_cond =
        (inst_beq  && (src1_value == src2_value)) ||
        (inst_bne  && (src1_value != src2_value)) ||
        (inst_blt  && ($signed(src1_value) <  $signed(src2_value))) ||
        (inst_bge  && ($signed(src1_value) >= $signed(src2_value))) ||
        (inst_bltu && (src1_value <  src2_value)) ||
        (inst_bgeu && (src1_value >= src2_value));

    function [31:0] load_result;
        input [31:0] raw;
        input [ 1:0] addr_low;
        input        byte_load;
        input        half_load;
        input        sign_ext;
        reg   [ 7:0] byte_value;
        reg   [15:0] half_value;
        begin
            case (addr_low)
                2'd0: byte_value = raw[7:0];
                2'd1: byte_value = raw[15:8];
                2'd2: byte_value = raw[23:16];
                default: byte_value = raw[31:24];
            endcase
            half_value = addr_low[1] ? raw[31:16] : raw[15:0];
            if (byte_load)
                load_result = sign_ext ? {{24{byte_value[7]}}, byte_value} :
                                         {24'b0, byte_value};
            else if (half_load)
                load_result = sign_ext ? {{16{half_value[15]}}, half_value} :
                                         {16'b0, half_value};
            else
                load_result = raw;
        end
    endfunction

    wire cpu_data_req = (state == ST_MEM_REQ);
    wire accel_start;
    wire accel_busy;
    wire accel_done;
    wire accel_takeover_req;
    wire accel_takeover_grant;
    wire accel_mem_req;
    wire accel_mem_wr;
    wire [ 1:0] accel_mem_size;
    wire [ 3:0] accel_mem_wstrb;
    wire [31:0] accel_mem_addr;
    wire [31:0] accel_mem_wdata;
    wire accel_mem_addr_ok;
    wire accel_mem_data_ok;
    wire [31:0] accel_mem_rdata;

    assign accel_start = (state == ST_EX) && inst_accel;
    assign accel_takeover_grant = (state == ST_ACCEL_WAIT) && accel_takeover_req;

    array_accel_engine #(
        .ARRAY_BEGIN(ACCEL_ARRAY_BEGIN),
        .ARRAY_END(ACCEL_ARRAY_END),
        .RESULT_ADDR(ACCEL_RESULT_ADDR)
    ) u_array_accel(
        .clk(clk), .resetn(resetn), .start(accel_start),
        .busy(accel_busy), .done(accel_done),
        .takeover_req(accel_takeover_req),
        .takeover_grant(accel_takeover_grant),
        .mem_req(accel_mem_req), .mem_wr(accel_mem_wr),
        .mem_size(accel_mem_size), .mem_wstrb(accel_mem_wstrb),
        .mem_addr(accel_mem_addr), .mem_wdata(accel_mem_wdata),
        .mem_addr_ok(accel_mem_addr_ok), .mem_data_ok(accel_mem_data_ok),
        .mem_rdata(accel_mem_rdata)
    );

    wire accel_owns_data = (state == ST_ACCEL_WAIT);

    assign inst_sram_req   = (state == ST_IF_REQ);
    assign inst_sram_wr    = 1'b0;
    assign inst_sram_size  = 2'b10;
    assign inst_sram_wstrb = 4'b0000;
    assign inst_sram_addr  = pc;
    assign inst_sram_wdata = 32'b0;
    assign data_sram_req   = accel_owns_data ? accel_mem_req   : cpu_data_req;
    assign data_sram_wr    = accel_owns_data ? accel_mem_wr    :
                                                   (cpu_data_req && ~mem_is_load);
    assign data_sram_size  = accel_owns_data ? accel_mem_size  : mem_size;
    assign data_sram_wstrb = accel_owns_data ? accel_mem_wstrb : mem_wstrb;
    assign data_sram_addr  = accel_owns_data ? accel_mem_addr  : mem_addr;
    assign data_sram_wdata = accel_owns_data ? accel_mem_wdata : mem_wdata;
    assign accel_mem_addr_ok = accel_owns_data && data_sram_addr_ok;
    assign accel_mem_data_ok = accel_owns_data && data_sram_data_ok;
    assign accel_mem_rdata   = data_sram_rdata;

    assign debug_wb_pc       = 32'b0;
    assign debug_wb_rf_we    = 4'b0;
    assign debug_wb_rf_wnum  = 5'b0;
    assign debug_wb_rf_wdata = 32'b0;

    always @(posedge clk) begin
        if (!resetn) begin
            state <= ST_IF_REQ;
            pc <= 32'h1c00_0000;
            inst <= 32'b0;
            src1_value <= 32'b0;
            src2_value <= 32'b0;
            wb_dest <= 5'b0;
            wb_data <= 32'b0;
            mem_is_load <= 1'b0;
            mem_size <= 2'b10;
            mem_wstrb <= 4'b0;
            mem_addr <= 32'b0;
            mem_wdata <= 32'b0;
            mem_ld_byte <= 1'b0;
            mem_ld_half <= 1'b0;
            mem_ld_sign <= 1'b0;
            mul_wait_count <= 2'b0;
        end else begin
            case (state)
                ST_IF_REQ: begin
                    if (inst_sram_addr_ok) begin
                        if (inst_sram_data_ok) begin
                            inst <= inst_sram_rdata;
                            state <= ST_RF;
                        end else begin
                            state <= ST_IF_WAIT;
                        end
                    end
                end
                ST_IF_WAIT: begin
                    if (inst_sram_data_ok) begin
                        inst <= inst_sram_rdata;
                        state <= ST_RF;
                    end
                end
                ST_RF: begin
                    // Register-file lookup is isolated from branch/ALU logic.
                    // This is a real timing cut, while the one-in-flight rule
                    // still makes every dependency wait for prior WB.
                    src1_value <= rf_rdata1;
                    src2_value <= rf_rdata2;
                    state <= ST_EX;
                end
                ST_EX: begin
                    pc <= pc + 32'd4;
                    if (inst_accel) begin
                        state <= ST_ACCEL_WAIT;
                    end else if (inst_mul_w) begin
                        wb_dest <= rd;
                        mul_wait_count <= 2'b0;
                        state <= ST_MUL_WAIT;
                    end else if (inst_ld_b | inst_ld_h | inst_ld_w |
                                 inst_ld_bu | inst_ld_hu |
                                 inst_st_b | inst_st_h | inst_st_w) begin
                        mem_is_load <= inst_ld_b | inst_ld_h | inst_ld_w |
                                       inst_ld_bu | inst_ld_hu;
                        mem_addr <= effective_addr;
                        mem_ld_byte <= inst_ld_b | inst_ld_bu;
                        mem_ld_half <= inst_ld_h | inst_ld_hu;
                        mem_ld_sign <= inst_ld_b | inst_ld_h;
                        wb_dest <= rd;
                        if (inst_ld_b | inst_ld_bu | inst_st_b) begin
                            mem_size <= 2'b00;
                            mem_wstrb <= 4'b0001 << effective_addr[1:0];
                            mem_wdata <= {4{src2_value[7:0]}};
                        end else if (inst_ld_h | inst_ld_hu | inst_st_h) begin
                            mem_size <= 2'b01;
                            mem_wstrb <= effective_addr[1] ? 4'b1100 : 4'b0011;
                            mem_wdata <= {2{src2_value[15:0]}};
                        end else begin
                            mem_size <= 2'b10;
                            mem_wstrb <= 4'b1111;
                            mem_wdata <= src2_value;
                        end
                        state <= ST_MEM_REQ;
                    end else if (inst_jirl) begin
                        wb_dest <= rd;
                        wb_data <= pc + 32'd4;
                        pc <= src1_value + branch_offs_16;
                        state <= ST_WB;
                    end else if (inst_bl) begin
                        wb_dest <= 5'd1;
                        wb_data <= pc + 32'd4;
                        pc <= pc + branch_offs_26;
                        state <= ST_WB;
                    end else if (inst_b) begin
                        pc <= pc + branch_offs_26;
                        state <= ST_IF_REQ;
                    end else if (inst_beq | inst_bne | inst_blt | inst_bge |
                                 inst_bltu | inst_bgeu) begin
                        if (branch_cond)
                            pc <= pc + branch_offs_16;
                        state <= ST_IF_REQ;
                    end else begin
                        wb_dest <= rd;
                        state <= ST_WB;
                        if (inst_add_w) wb_data <= src1_value + src2_value;
                        else if (inst_sub_w) wb_data <= src1_value - src2_value;
                        else if (inst_slt) wb_data <= {31'b0, $signed(src1_value) < $signed(src2_value)};
                        else if (inst_sltu) wb_data <= {31'b0, src1_value < src2_value};
                        else if (inst_nor) wb_data <= ~(src1_value | src2_value);
                        else if (inst_and) wb_data <= src1_value & src2_value;
                        else if (inst_or) wb_data <= src1_value | src2_value;
                        else if (inst_xor) wb_data <= src1_value ^ src2_value;
                        else if (inst_sll_w) wb_data <= src1_value << src2_value[4:0];
                        else if (inst_srl_w) wb_data <= src1_value >> src2_value[4:0];
                        else if (inst_sra_w) wb_data <= $signed(src1_value) >>> src2_value[4:0];
                        else if (inst_slli_w) wb_data <= src1_value << rk;
                        else if (inst_srli_w) wb_data <= src1_value >> rk;
                        else if (inst_srai_w) wb_data <= $signed(src1_value) >>> rk;
                        else if (inst_slti) wb_data <= {31'b0, $signed(src1_value) < $signed(imm_si12)};
                        else if (inst_sltui) wb_data <= {31'b0, src1_value < imm_si12};
                        else if (inst_addi_w) wb_data <= src1_value + imm_si12;
                        else if (inst_andi) wb_data <= src1_value & imm_ui12;
                        else if (inst_ori) wb_data <= src1_value | imm_ui12;
                        else if (inst_xori) wb_data <= src1_value ^ imm_ui12;
                        else if (inst_lu12i_w) wb_data <= {i20, 12'b0};
                        else if (inst_pcaddu12i) wb_data <= pc + {i20, 12'b0};
                        else if (inst_cpucfg) wb_data <= 32'b0;
                        else begin
                            wb_dest <= 5'b0;
                            wb_data <= 32'b0;
                        end
                    end
                end
                ST_MUL_WAIT: begin
                    if (mul_wait_count == 2'd2) begin
                        wb_data <= mul_result;
                        state <= ST_WB;
                    end else begin
                        mul_wait_count <= mul_wait_count + 2'd1;
                    end
                end
                ST_MEM_REQ: begin
                    if (data_sram_addr_ok) begin
                        if (data_sram_data_ok) begin
                            if (mem_is_load) begin
                                wb_data <= load_result(data_sram_rdata, mem_addr[1:0],
                                                       mem_ld_byte, mem_ld_half, mem_ld_sign);
                                state <= ST_WB;
                            end else begin
                                state <= ST_IF_REQ;
                            end
                        end else begin
                            state <= ST_MEM_WAIT;
                        end
                    end
                end
                ST_MEM_WAIT: begin
                    if (data_sram_data_ok) begin
                        if (mem_is_load) begin
                            wb_data <= load_result(data_sram_rdata, mem_addr[1:0],
                                                   mem_ld_byte, mem_ld_half, mem_ld_sign);
                            state <= ST_WB;
                        end else begin
                            state <= ST_IF_REQ;
                        end
                    end
                end
                ST_WB: state <= ST_IF_REQ;
                ST_ACCEL_WAIT: if (accel_done) state <= ST_IF_REQ;
                default: state <= ST_IF_REQ;
            endcase
        end
    end

    wire unused_accel_busy = accel_busy;

endmodule

`default_nettype wire
