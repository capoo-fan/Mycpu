`ifndef MYCPU_H
`define MYCPU_H

// BPU 相关定义

`define BHT_IDX_W 10                    // 表索引位宽
`define BHT_ENTRY (1 << `BHT_IDX_W)     // 表项个数
`define BHT_TAG_W 8                     // tag字段位宽
`define RAS_DEPTH 8                     // 返回地址栈深度
`define RAS_PTR_W 3                     // 返回地址栈指针位宽
`define RAS_CNT_W 4                     // 返回地址栈计数位宽

        // 级间总线宽度定义

`define FS_TO_DS_BUS_WD 97

`define DS_TO_ES_BUS_WD 159

`define ES_TO_MS_BUS_WD 109

`define MS_TO_WS_BUS_WD 106

`define WS_TO_RF_BUS_WD 38

`define ES_FWD_BUS_WD   41

`define MS_FWD_BUS_WD   40

`define WS_FWD_BUS_WD   39

`endif
