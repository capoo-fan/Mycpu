`ifndef MYCPU_H
`define MYCPU_H

// 级间总线宽度定义

`define FS_TO_DS_BUS_WD 65

`define DS_TO_ES_BUS_WD 215

`define ES_TO_MS_BUS_WD 165

`define MS_TO_WS_BUS_WD 195

`define WS_TO_RF_BUS_WD 38

`define ES_FWD_BUS_WD   41

`define MS_FWD_BUS_WD   40

`define WS_FWD_BUS_WD   39

// CSR 寄存器编号
`define CSR_CRMD   14'h0000
`define CSR_PRMD   14'h0001
`define CSR_ECFG   14'h0004
`define CSR_ESTAT  14'h0005
`define CSR_ERA    14'h0006
`define CSR_BADV   14'h0007
`define CSR_EENTRY 14'h000c
`define CSR_SAVE0  14'h0030
`define CSR_SAVE1  14'h0031
`define CSR_SAVE2  14'h0032
`define CSR_SAVE3  14'h0033
`define CSR_TID    14'h0040
`define CSR_TCFG   14'h0041
`define CSR_TVAL   14'h0042
`define CSR_TICLR  14'h0044

// 异常码
`define ECODE_INT  6'h00
`define ECODE_ADEF 6'h08
`define ECODE_ALE  6'h09
`define ECODE_SYS  6'h0b
`define ECODE_BRK  6'h0c
`define ECODE_INE  6'h0d

`endif
