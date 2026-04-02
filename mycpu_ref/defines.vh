`define ENABLE_ICACHE
`define ENABLE_DCACHE

`define CACHE_BLK_LEN  4
`define CACHE_BLK_SIZE (`CACHE_BLK_LEN*32)

// PC澶嶄綅鍒濆锟??
`define PC_INIT_VAL     32'h80000000

// NPC op
`define NPC_PC4 2'b00
`define NPC_BRANCH 2'b01

// 绔嬪嵆鏁版墿灞昽p
`define EXT_26   3'b100
`define EXT_20   3'b110
`define EXT_12   3'b111
`define EXT_U12   3'b001
`define EXT_5    3'b010
`define EXT_NONE 3'b000
`define EXT_16   3'b011

// Load鎸囦护璇绘暟鎹悗鐨勬墿灞昽p
`define RAM_EXT_H  3'b001
`define RAM_EXT_B  3'b010
`define RAM_EXT_W  3'b011
`define RAM_EXT_N  3'b000
`define RAM_EXT_HU 3'b100
`define RAM_EXT_BU 3'b101

// Store鎸囦护鍐欐暟鎹畂p
`define RAM_WE_H 4'b0001
`define RAM_WE_B 4'b0010
`define RAM_WE_W 4'b0011
`define RAM_WE_N 4'b0000

// ALU op
`define ALU_ADD    5'b00000
`define ALU_AND    5'b00001
`define ALU_OR     5'b00010
`define ALU_XOR    5'b00011
`define ALU_NOR    5'b00100
`define ALU_SUB    5'b00101
`define ALU_LUI12  5'b00110
`define ALU_SLTU   5'b00111
`define ALU_SLT    5'b01000
`define ALU_SLL    5'b01001
`define ALU_SRL    5'b01010
`define ALU_SRA    5'b01011
`define ALU_BNE    5'b01100
`define ALU_BEQ    5'b01101
`define ALU_BLT    5'b01110
`define ALU_BLTU   5'b01111
`define ALU_BGE    5'b10000
`define ALU_BGEU   5'b10001
`define ALU_JIRL   5'b10010
`define ALU_B      5'b10011
`define ALU_BL     5'b10100
`define ALU_MUL    5'b10101
`define ALU_MULH   5'B10110
`define ALU_MULHU  5'b10111
`define ALU_DIV    5'b11000
`define ALU_DIVU   5'b11001
`define ALU_MOD    5'b11010
`define ALU_MODU   5'b11011
// 鎸囦护璇戠爜鐩稿叧
`define FR5_ADD  5'b00000

// 婧愭搷浣滄暟2鐨勶拷?锟芥嫨锛氾拷?锟芥嫨rk鎴杛d
`define R2_RK  1'b1
`define R2_RD  1'b0

// 鐩殑鎿嶄綔鏁扮殑閫夋嫨锛氾拷?锟芥嫨rd鎴杛1
`define WR_RD  1'b1
`define WR_Rr1  1'b0

// 鍐欐暟鎹拷?锟芥嫨锛氾拷?锟芥嫨灏咥LU鏁版嵁鎴栧皢璇讳富瀛樼殑鏁版嵁鍐欏洖瀵勫瓨鍣ㄥ爢
`define WD_ALU  2'b11
`define WD_RAM  2'b01

// ALU鎿嶄綔鏁癆鐨勶拷?锟芥嫨锛氾拷?锟芥嫨婧愬瘎瀛樺櫒1鎴朠C锟??
`define ALUA_R1  1'b1
`define ALUA_PC  1'b0

// ALU鎿嶄綔鏁癇鐨勶拷?锟芥嫨锛氾拷?锟芥嫨婧愬瘎瀛樺櫒2鎴栫珛鍗虫暟
`define ALUB_R2  1'b1
`define ALUB_EXT 1'b0

`define IS_BRANCH  1'b1
`define NOT_BRANCH 1'b0

`define DECODED_PACKET_WIDTH 123
// -- 字段在包内的位置定义 (从高位到低位) --
// CU控制信号部分 (25 bits)
`define DEC_ALUB_SEL_RANGE      121:121
`define DEC_ALUA_SEL_RANGE      120:120
`define DEC_RR2_RE_RANGE        119:119
`define DEC_RR1_RE_RANGE        118:118
`define DEC_WD_SEL_RANGE        117:116
`define DEC_WR_SEL_RANGE        115:115
`define DEC_R2_SEL_RANGE        114:114
`define DEC_RAM_WE_RANGE        113:110
`define DEC_RF_WE_RANGE         109:109
`define DEC_ALU_OP_RANGE        108:104
`define DEC_RAM_EXT_OP_RANGE    103:101
`define DEC_EXT_OP_RANGE        100:98
`define DEC_BRANCH_FLAG_RANGE   97
// 原始指令信息部分 (97 bits)
`define DEC_PRED_TAKEN_RANGE    96:96
`define DEC_PRED_TARGET_RANGE   95:64
`define DEC_PC_RANGE            63:32
`define DEC_INST_RANGE          31:0