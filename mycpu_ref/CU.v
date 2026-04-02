`timescale 1ns / 1ps
`include "defines.vh"
module CU (
    input  wire [16:0]  din,            
    output reg    branch_inst_flag,         
    output reg  [ 2:0]  ext_op,         
    output reg  [ 2:0]  ram_ext_op,     
    output reg  [ 4:0]  alu_op,        
    output reg          rf_we,          
    output reg  [ 3:0]  ram_we,         
    output reg         r2_sel,         
    output wire         wr_sel,         
    output reg  [ 1:0]  wd_sel,         
    output reg          rR1_re,         
    output reg          rR2_re,         
    output reg         alua_sel,       
    output reg          alub_sel,
    output reg          is_store        
);


wire [5:0] op = din[16:11];    
wire [6:0] func7   = din[6:0];      

always @(*) begin 
    ext_op     = `EXT_NONE;      
    ram_ext_op = `RAM_EXT_N;      
    alu_op     = `ALU_ADD;       
    rf_we      = 1'b0;           
    ram_we     = `RAM_WE_N;       
    wd_sel     = `WD_ALU;         
    rR1_re     = 1'b0;           
    rR2_re     = 1'b0;
    alua_sel   = `ALUA_R1;            
    alub_sel   = `ALUB_R2;        
    branch_inst_flag = `NOT_BRANCH; 
    r2_sel  = `R2_RK ;
    is_store = 1'b0;
    case(op)
      
        6'b000000: begin
            if(din[10]==0)begin
                case(func7)
                    7'b0100000:begin//add.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                    end
                    7'b0100010:begin//sub.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_SUB;
                    end
                    7'b0101001:begin//and
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_AND;
                    end
                    7'b0101010:begin//or
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_OR;
                    end
                    7'b0101011:begin//xor
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_XOR;
                    end

                    7'b0101000:begin//nor
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_NOR;
                    end
                    7'b0100100:begin//slt
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_SLT;
                    end

                    7'b0100101:begin//sltu
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_SLTU;
                    end
                    7'b0101110:begin//sll.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_SLL;                   
                    end
                    7'b0101111:begin//srl.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_SRL;
                    end
                    7'b0110000:begin//sra.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we = 1'b1;
                        alu_op     = `ALU_SRA;
                    end
                    7'b0000001:begin//slli.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b0;
                        rf_we      = 1'b1;
                        alub_sel   = `ALUB_EXT;
                        ext_op=`EXT_5;
                        alu_op     = `ALU_SLL;                  
                    end
                    7'b0001001:begin//srli.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b0;
                        rf_we      = 1'b1;
                        alub_sel   = `ALUB_EXT;
                        ext_op=`EXT_5;
                        alu_op     = `ALU_SRL;                      
                    end
                    7'b0010001:begin//sra.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b0;
                        rf_we      = 1'b1;
                        alub_sel   = `ALUB_EXT;
                        ext_op=`EXT_5;
                        alu_op     = `ALU_SRA;
                    end
                    7'b0111000:begin//mul.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we      = 1'b1;
                        alu_op     = `ALU_MUL;
                    end
                    7'b0111001:begin//mulh.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we      = 1'b1;
                        alu_op     = `ALU_MULH;  
                    end
                    7'b0111010:begin//mulh.wu
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we      = 1'b1;
                        alu_op     = `ALU_MULHU;                
                    end
                    7'b1000000:begin//div.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we      = 1'b1;
                        alu_op     = `ALU_DIV;
                    end
                    7'b1000010:begin//divu.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we      = 1'b1;
                        alu_op     = `ALU_DIVU;
                    end
                    7'b1000001:begin//mod.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we      = 1'b1;
                        alu_op     = `ALU_MOD;                
                    end
                    7'b1000011:begin//modu.w
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b1;
                        rf_we      = 1'b1;
                        alu_op     = `ALU_MODU;    
                    end
                    default:begin
                    end
                endcase
            end else begin
                case(din[9:7])
                    3'b010:begin//addi
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b0;
                        rf_we      = 1'b1;
                        alub_sel   = `ALUB_EXT;
                        ext_op=`EXT_12;    
                    end
                    3'b101:begin//andi
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b0;
                        rf_we      = 1'b1;
                        alub_sel   = `ALUB_EXT;
                        ext_op=`EXT_U12;
                        alu_op     = `ALU_AND;
                    end
                    3'b110:begin//ori
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b0;
                        rf_we      = 1'b1;
                        alub_sel   = `ALUB_EXT;
                        ext_op=`EXT_U12;
                        alu_op     = `ALU_OR;
                    end
                    3'b111:begin//xori
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b0;
                        rf_we      = 1'b1;
                        alub_sel   = `ALUB_EXT;
                        ext_op=`EXT_U12;
                        alu_op     = `ALU_XOR;
                    end
                    3'b000:begin//slti
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b0;
                        rf_we      = 1'b1;
                        alub_sel   = `ALUB_EXT;
                        ext_op=`EXT_12; 
                        alu_op     = `ALU_SLT;                        
                    end  
                    3'b001:begin//sltui
                        rR1_re     = 1'b1;            
                        rR2_re     = 1'b0;
                        rf_we      = 1'b1;
                        alub_sel   = `ALUB_EXT;
                        ext_op=`EXT_12; 
                        alu_op     = `ALU_SLTU;                  
                    end              
                    default:begin
                    end
                endcase    
            end       
        end
        6'b001010:begin
            case(din[10:7])
                4'b0000:begin//LD.B
                    rR1_re     = 1'b1;            
                    rR2_re     = 1'b0;
                    rf_we      = 1'b1;
                    wd_sel = `WD_RAM;
                    alub_sel   = `ALUB_EXT;
                    ram_ext_op = `RAM_EXT_B;
                    ext_op=`EXT_12;
                end
                4'b1000:begin//LD.BU
                    rR1_re     = 1'b1;            
                    rR2_re     = 1'b0;
                    rf_we      = 1'b1;
                    wd_sel = `WD_RAM;
                    alub_sel   = `ALUB_EXT;
                    ram_ext_op = `RAM_EXT_BU;
                    ext_op=`EXT_12;
                end
                4'b0001:begin//LD.H
                    rR1_re     = 1'b1;            
                    rR2_re     = 1'b0;
                    rf_we      = 1'b1;
                    wd_sel = `WD_RAM;
                    alub_sel   = `ALUB_EXT;
                    ram_ext_op = `RAM_EXT_H;
                    ext_op=`EXT_12; 
                end
                4'b1001:begin//LD.HU
                    rR1_re     = 1'b1;            
                    rR2_re     = 1'b0;
                    rf_we      = 1'b1;
                    wd_sel = `WD_RAM;
                    alub_sel   = `ALUB_EXT;
                    ram_ext_op = `RAM_EXT_HU;
                    ext_op=`EXT_12;
                end
                4'b0010:begin//LD.W
                    rR1_re     = 1'b1;            
                    rR2_re     = 1'b0;
                    rf_we      = 1'b1;
                    wd_sel = `WD_RAM;
                    alub_sel   = `ALUB_EXT;
                    ram_ext_op = `RAM_EXT_W;
                    ext_op=`EXT_12;
                end
                4'b0100:begin//st.b
                    rR1_re     = 1'b1;            
                    rR2_re     = 1'b1;
                    r2_sel  = `R2_RD ;
                    wd_sel = `WD_RAM;
                    alub_sel   = `ALUB_EXT;
                    ram_we     = `RAM_WE_B;
                    ext_op=`EXT_12;   
                    is_store = 1'b1; 
                end
                4'b0101:begin//st.h
                    rR1_re     = 1'b1;            
                    rR2_re     = 1'b1;
                    r2_sel  = `R2_RD ;
                    wd_sel = `WD_RAM;
                    alub_sel   = `ALUB_EXT;
                    ram_we     = `RAM_WE_H;
                    ext_op=`EXT_12;    
                    is_store = 1'b1; 
                end
                4'b0110:begin//st.w
                    rR1_re     = 1'b1;            
                    rR2_re     = 1'b1;
                    r2_sel  = `R2_RD ;
                    wd_sel = `WD_RAM;
                    alub_sel   = `ALUB_EXT;
                    ram_we     = `RAM_WE_W;
                    ext_op=`EXT_12; 
                    is_store = 1'b1;    
                end          
            endcase
        end
        6'b000111:begin//pcaddu12i
            rR1_re=1'b0;
            rR2_re=1'b0;
            alub_sel   = `ALUB_EXT;
            rf_we      = 1'b1;
            ext_op=`EXT_20;
            alua_sel = `ALUA_PC ; 
        end
        6'b000101:begin //lui12
            rR1_re=1'b0;
            rR2_re=1'b0;
            alub_sel =`ALUB_EXT;
            rf_we =1'b1;
            ext_op=`EXT_20;
            alu_op     = `ALU_LUI12;
        end
        6'b010111:begin//bne
            rR1_re=1'b1;
            rR2_re=1'b1;
            ext_op =`EXT_16 ;
            r2_sel  = `R2_RD ;
            branch_inst_flag = `IS_BRANCH;
            alu_op   = `ALU_BNE;
        end
        6'b010110:begin//beq
            rR1_re=1'b1;
            rR2_re=1'b1;
            ext_op =`EXT_16 ;
            r2_sel  = `R2_RD ;
            branch_inst_flag = `IS_BRANCH;
            alu_op   = `ALU_BEQ;
        end
        6'b011000:begin//blt
            rR1_re=1'b1;
            rR2_re=1'b1;
            ext_op =`EXT_16 ;
            r2_sel  = `R2_RD ;
            branch_inst_flag = `IS_BRANCH;
            alu_op   = `ALU_BLT;
        end
        6'b011010:begin//bltu
            rR1_re=1'b1;
            rR2_re=1'b1;
            ext_op =`EXT_16 ;
            r2_sel  = `R2_RD ;
            branch_inst_flag = `IS_BRANCH;
            alu_op   = `ALU_BLTU;
        end
        6'b011001:begin//bge
            rR1_re=1'b1;
            rR2_re=1'b1;
            ext_op =`EXT_16 ;
            r2_sel  = `R2_RD ;
            branch_inst_flag = `IS_BRANCH;
            alu_op   = `ALU_BGE;           
        end
        6'b011011:begin//bgeu
            rR1_re=1'b1;
            rR2_re=1'b1;
            ext_op =`EXT_16 ;
            r2_sel  = `R2_RD ;
            branch_inst_flag = `IS_BRANCH;
            alu_op   = `ALU_BGEU;           
        end
        6'b010011:begin//jirl
            rR1_re=1'b1;
            rR2_re=1'b0;
            ext_op =`EXT_16 ;
            rf_we      = 1'b1;
            branch_inst_flag = `IS_BRANCH;
            alu_op   = `ALU_JIRL;
        end
        6'b010100:begin//b
            ext_op =`EXT_26 ;
            branch_inst_flag = `IS_BRANCH;
            alu_op   = `ALU_B;    
        end
        6'b010101:begin//bl
            ext_op =`EXT_26 ;
            rf_we    = 1'b1;
            branch_inst_flag = `IS_BRANCH;
            alu_op   = `ALU_BL;
        end
        default: begin
          
        end
    endcase
end


assign wr_sel = (op==6'b010101)? `WR_Rr1:`WR_RD;          


endmodule
