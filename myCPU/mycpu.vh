`ifndef MYCPU_H
`define MYCPU_H

        // 级间总线宽度定义

`define FS_TO_DS_BUS_WD 97

`define DS_DEC_BUS_WD   169

`define IBUF_ENTRY_BUS_WD (`FS_TO_DS_BUS_WD + `DS_DEC_BUS_WD)

`define DS_TO_ES_BUS_WD 254
`define DS_TO_ES_BUS_1_WD 215

`define ES_TO_MS_BUS_WD 301
`define ES_TO_MS_BUS_1_WD 170

`define MS_TO_WS_BUS_WD 185
`define MS_TO_WS_BUS_1_WD 38

`define WS_TO_RF_BUS_WD 76

`define ES_FWD_BUS_WD   41
`define ES_FWD_BUS_1_WD 39

`define MS_FWD_BUS_WD   41
`define MS_FWD_BUS_1_WD 39

`define TRANS_CTX_WD    14

`define BR_NONE 4'd0
`define BR_BEQ  4'd1
`define BR_BNE  4'd2
`define BR_BLT  4'd3
`define BR_BGE  4'd4
`define BR_BLTU 4'd5
`define BR_BGEU 4'd6
`define BR_JIRL 4'd7
`define BR_BL   4'd8
`define BR_B    4'd9

`endif
