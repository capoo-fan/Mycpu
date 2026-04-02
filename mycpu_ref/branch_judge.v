`timescale 1ns / 1ps
`include "defines.vh"
module branch_judge (
    // --- 输入---
    input  wire [31:0]  rD1_in,
    input  wire [31:0]  rD2_in,
    input  wire [31:0]  ext_i,
    input  wire         branch_flag_i,
    input  wire [4:0]   aluop_i,
    input  wire [31:0]  pc_i,
    // --- 输出 ---
    output wire         actual_taken_o,      // 该分支指令实际是否跳转
    output wire [31:0]  actual_target_pc_o // 该分支指令实际的目标PC

);

    wire is_eq  = (rD1_in == rD2_in);
    wire is_slt = $signed(rD1_in) < $signed(rD2_in);
    wire is_ult = (rD1_in < rD2_in);
    wire is_sge = !is_slt;
    wire is_uge = !is_ult;
    wire [31:0] target_pc_imm  = pc_i + ext_i ;    // B-type, B, BL 的目标地址
    wire [31:0] target_reg_imm = rD1_in + ext_i;      // JIRL 的目标地址

    reg taken_result;
    reg [31:0] target_result;
    always @(*) begin
        case(aluop_i)
            `ALU_BEQ:  begin taken_result = is_eq;      target_result = target_pc_imm;  end
            `ALU_BNE:  begin taken_result = !is_eq;     target_result = target_pc_imm;  end
            `ALU_BLT:  begin taken_result = is_slt;     target_result = target_pc_imm;  end
            `ALU_BGE:  begin taken_result = is_sge;     target_result = target_pc_imm;  end
            `ALU_BLTU: begin taken_result = is_ult;     target_result = target_pc_imm;  end
            `ALU_BGEU: begin taken_result = is_uge;     target_result = target_pc_imm;  end
            `ALU_JIRL: begin taken_result = 1'b1;       target_result = target_reg_imm; end
            `ALU_B:    begin taken_result = 1'b1;       target_result = target_pc_imm;  end
            `ALU_BL:   begin taken_result = 1'b1;       target_result = target_pc_imm;  end
            default:   begin taken_result = 1'b0;       target_result = 32'h0;          end
        endcase
    end

    assign actual_taken_o     = branch_flag_i && taken_result;
    assign actual_target_pc_o = target_result;
endmodule
