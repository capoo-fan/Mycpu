`include "mycpu.vh"

module WB_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         ms_to_ws_valid_0,
    input  wire                         ms_to_ws_valid_1,
    input  wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus_0,
    input  wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus_1,

    output wire                         ws_allowin,
    output wire [`WS_FWD_BUS_WD-1:0]    ws_fwd_bus_0,
    output wire [`WS_FWD_BUS_WD-1:0]    ws_fwd_bus_1,
    output wire [`WS_TO_RF_BUS_WD-1:0]  ws_to_rf_bus,

    output reg  [31:0]                  debug_wb_pc,
    output reg  [ 3:0]                  debug_wb_rf_we,
    output reg  [ 4:0]                  debug_wb_rf_wnum,
    output reg  [31:0]                  debug_wb_rf_wdata
  );

  reg reset;
  always @(posedge clk) reset <= ~resetn;

  reg         ws_valid_0;
  reg  [31:0] ws_pc_0;
  reg  [31:0] ws_alu_result_0;
  reg  [31:0] ws_mem_result_0;
  reg         ws_res_from_mem_0;
  reg         ws_gr_we_0;
  reg  [ 4:0] ws_dest_0;
  reg         ws_ld_byte_0;
  reg         ws_ld_half_0;
  reg         ws_ld_sign_ext_0;

  reg         ws_valid_1;
  reg  [31:0] ws_pc_1;
  reg  [31:0] ws_alu_result_1;
  reg  [31:0] ws_mem_result_1;
  reg         ws_res_from_mem_1;
  reg         ws_gr_we_1;
  reg  [ 4:0] ws_dest_1;
  reg         ws_ld_byte_1;
  reg         ws_ld_half_1;
  reg         ws_ld_sign_ext_1;

  wire [31:0] ms_pc_0;
  wire [31:0] ms_alu_result_0;
  wire        ms_res_from_mem_0;
  wire        ms_gr_we_0;
  wire [ 4:0] ms_dest_0;
  wire        ms_ld_byte_0;
  wire        ms_ld_half_0;
  wire        ms_ld_sign_ext_0;
  wire [31:0] ms_mem_rdata_0;

  assign {ms_pc_0, ms_alu_result_0, ms_res_from_mem_0, ms_gr_we_0, ms_dest_0,
          ms_ld_byte_0, ms_ld_half_0, ms_ld_sign_ext_0,
          ms_mem_rdata_0} = ms_to_ws_bus_0;

  wire [31:0] ms_pc_1;
  wire [31:0] ms_alu_result_1;
  wire        ms_res_from_mem_1;
  wire        ms_gr_we_1;
  wire [ 4:0] ms_dest_1;
  wire        ms_ld_byte_1;
  wire        ms_ld_half_1;
  wire        ms_ld_sign_ext_1;
  wire [31:0] ms_mem_rdata_1;

  assign {ms_pc_1, ms_alu_result_1, ms_res_from_mem_1, ms_gr_we_1, ms_dest_1,
          ms_ld_byte_1, ms_ld_half_1, ms_ld_sign_ext_1,
          ms_mem_rdata_1} = ms_to_ws_bus_1;

  // 加载数据的函数
  function [31:0] load_result;
    input [31:0] alu_result;
    input [31:0] mem_result;
    input        ld_byte;
    input        ld_half;
    input        ld_sign_ext;
    reg [7:0]    load_byte;
    reg [15:0]   load_half;
    begin
      load_byte = alu_result[1] ? (alu_result[0] ? mem_result[31:24] : mem_result[23:16]) :
                (alu_result[0] ? mem_result[15:8]  : mem_result[7:0]);
      load_half = alu_result[1] ? mem_result[31:16] : mem_result[15:0];
      load_result = ld_byte ? (ld_sign_ext ? {{24{load_byte[7]}}, load_byte} :
                               {24'b0, load_byte}) :
                  ld_half ? (ld_sign_ext ? {{16{load_half[15]}}, load_half} :
                             {16'b0, load_half}) :
                  mem_result;
    end
  endfunction

  wire [31:0] ws_load_result_0 = load_result(ws_alu_result_0, ws_mem_result_0,
       ws_ld_byte_0, ws_ld_half_0, ws_ld_sign_ext_0);
  wire [31:0] ws_load_result_1 = load_result(ws_alu_result_1, ws_mem_result_1,
       ws_ld_byte_1, ws_ld_half_1, ws_ld_sign_ext_1);

  wire [31:0] final_result_0 = ws_res_from_mem_0 ? ws_load_result_0 : ws_alu_result_0;
  wire [31:0] final_result_1 = ws_res_from_mem_1 ? ws_load_result_1 : ws_alu_result_1;

  wire packet_valid = ws_valid_0 || ws_valid_1;

  localparam DBG_DEPTH = 4;
  reg [68:0] dbg_queue [0:DBG_DEPTH-1];
  reg [2:0]  dbg_cnt;

  wire dbg_pop = (dbg_cnt != 3'd0);
  wire [2:0] dbg_cnt_after_pop = dbg_cnt - {2'b0, dbg_pop};

  wire commit_dbg_0 = packet_valid && ws_valid_0 && ws_gr_we_0 && (ws_dest_0 != 5'b0);
  wire commit_dbg_1 = packet_valid && ws_valid_1 && ws_gr_we_1 && (ws_dest_1 != 5'b0);
  wire [1:0] commit_dbg_num = {1'b0, commit_dbg_0} + {1'b0, commit_dbg_1};
  wire [2:0] dbg_free_after_pop = DBG_DEPTH - dbg_cnt + {2'b0, dbg_pop};
  wire dbg_commit_ready = (dbg_free_after_pop >= {1'b0, commit_dbg_num});

  wire ws_fire = packet_valid && dbg_commit_ready;
  assign ws_allowin = !packet_valid || ws_fire;

  wire ws_rf_we_0    = ws_fire && ws_valid_0 && ws_gr_we_0;
  wire [ 4:0] ws_rf_waddr_0 = ws_dest_0;
  wire [31:0] ws_rf_wdata_0 = final_result_0;

  wire ws_rf_we_1    = ws_fire && ws_valid_1 && ws_gr_we_1;
  wire [ 4:0] ws_rf_waddr_1 = ws_dest_1;
  wire [31:0] ws_rf_wdata_1 = final_result_1;

  // WB_stage 的转发逻辑
  assign ws_fwd_bus_0 = {ws_valid_0, ws_gr_we_0, ws_dest_0, final_result_0};
  assign ws_fwd_bus_1 = {ws_valid_1, ws_gr_we_1, ws_dest_1, final_result_1};

  assign ws_to_rf_bus = {ws_rf_we_0, ws_rf_waddr_0, ws_rf_wdata_0,
                         ws_rf_we_1, ws_rf_waddr_1, ws_rf_wdata_1};

  wire [68:0] dbg_event_0 = {ws_pc_0, ws_dest_0, final_result_0};
  wire [68:0] dbg_event_1 = {ws_pc_1, ws_dest_1, final_result_1};

  always @(posedge clk)
  begin
    if (reset)
    begin
      debug_wb_pc       <= 32'b0;
      debug_wb_rf_we    <= 4'b0;
      debug_wb_rf_wnum  <= 5'b0;
      debug_wb_rf_wdata <= 32'b0;
      dbg_cnt           <= 3'b0;
    end
    else
    begin
      if (dbg_pop)
      begin
        debug_wb_pc       <= dbg_queue[0][68:37];
        debug_wb_rf_wnum  <= dbg_queue[0][36:32];
        debug_wb_rf_wdata <= dbg_queue[0][31:0];
        debug_wb_rf_we    <= 4'b1111;
        dbg_queue[0]      <= dbg_queue[1];
        dbg_queue[1]      <= dbg_queue[2];
        dbg_queue[2]      <= dbg_queue[3];
      end
      else
      begin
        debug_wb_pc       <= 32'b0;
        debug_wb_rf_we    <= 4'b0;
        debug_wb_rf_wnum  <= 5'b0;
        debug_wb_rf_wdata <= 32'b0;
      end

      if (ws_fire)
      begin
        if (commit_dbg_0)
        begin
          case (dbg_cnt_after_pop)
            3'd0:
              dbg_queue[0] <= dbg_event_0;
            3'd1:
              dbg_queue[1] <= dbg_event_0;
            3'd2:
              dbg_queue[2] <= dbg_event_0;
            default:
              dbg_queue[3] <= dbg_event_0;
          endcase

          if (commit_dbg_1)
          begin
            case (dbg_cnt_after_pop + 3'd1)
              3'd0:
                dbg_queue[0] <= dbg_event_1;
              3'd1:
                dbg_queue[1] <= dbg_event_1;
              3'd2:
                dbg_queue[2] <= dbg_event_1;
              default:
                dbg_queue[3] <= dbg_event_1;
            endcase
          end
        end
        else if (commit_dbg_1)
        begin
          case (dbg_cnt_after_pop)
            3'd0:
              dbg_queue[0] <= dbg_event_1;
            3'd1:
              dbg_queue[1] <= dbg_event_1;
            3'd2:
              dbg_queue[2] <= dbg_event_1;
            default:
              dbg_queue[3] <= dbg_event_1;
          endcase
        end
      end

      dbg_cnt <= dbg_cnt_after_pop + {1'b0, (ws_fire ? commit_dbg_num : 2'b0)};
    end
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      ws_valid_0 <= 1'b0;
      ws_valid_1 <= 1'b0;
    end
    else if (ws_allowin)
    begin
      ws_valid_0 <= ms_to_ws_valid_0;
      ws_valid_1 <= ms_to_ws_valid_1;
    end
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      ws_pc_0           <= 32'b0;
      ws_gr_we_0        <= 1'b0;
      ws_res_from_mem_0 <= 1'b0;
      ws_dest_0         <= 5'b0;
      ws_alu_result_0   <= 32'b0;
      ws_mem_result_0   <= 32'b0;
      ws_ld_byte_0      <= 1'b0;
      ws_ld_half_0      <= 1'b0;
      ws_ld_sign_ext_0  <= 1'b0;

      ws_pc_1           <= 32'b0;
      ws_gr_we_1        <= 1'b0;
      ws_res_from_mem_1 <= 1'b0;
      ws_dest_1         <= 5'b0;
      ws_alu_result_1   <= 32'b0;
      ws_mem_result_1   <= 32'b0;
      ws_ld_byte_1      <= 1'b0;
      ws_ld_half_1      <= 1'b0;
      ws_ld_sign_ext_1  <= 1'b0;
    end
    else if (ws_allowin)
    begin
      if (ms_to_ws_valid_0)
      begin
        ws_pc_0           <= ms_pc_0;
        ws_alu_result_0   <= ms_alu_result_0;
        ws_mem_result_0   <= ms_mem_rdata_0;
        ws_res_from_mem_0 <= ms_res_from_mem_0;
        ws_gr_we_0        <= ms_gr_we_0;
        ws_dest_0         <= ms_dest_0;
        ws_ld_byte_0      <= ms_ld_byte_0;
        ws_ld_half_0      <= ms_ld_half_0;
        ws_ld_sign_ext_0  <= ms_ld_sign_ext_0;
      end
      else
      begin
        ws_gr_we_0        <= 1'b0;
        ws_res_from_mem_0 <= 1'b0;
      end

      if (ms_to_ws_valid_1)
      begin
        ws_pc_1           <= ms_pc_1;
        ws_alu_result_1   <= ms_alu_result_1;
        ws_mem_result_1   <= ms_mem_rdata_1;
        ws_res_from_mem_1 <= ms_res_from_mem_1;
        ws_gr_we_1        <= ms_gr_we_1;
        ws_dest_1         <= ms_dest_1;
        ws_ld_byte_1      <= ms_ld_byte_1;
        ws_ld_half_1      <= ms_ld_half_1;
        ws_ld_sign_ext_1  <= ms_ld_sign_ext_1;
      end
      else
      begin
        ws_gr_we_1        <= 1'b0;
        ws_res_from_mem_1 <= 1'b0;
      end
    end
  end

endmodule
