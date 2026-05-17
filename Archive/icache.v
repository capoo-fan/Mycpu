module icache(
    input                clk,
    input                resetn,

    // ICache 与 Cpu 接口
    input                valid,
    input   [7 : 0]      index,
    input   [19: 0]      tag,
    input   [3 : 0]      offset,
    output               addr_ok, //该次请求的地址传输OK
    output               data_ok, //该次请求的数据传输OK
    output  [31: 0]      rdata,   //Cache 返回结果

    // ICache 读接口
    output               rd_req,    //读请求有效
    output  [31 : 0]     rd_addr,   //读请求起始地址
    input                rd_rdy,    //读请求握手信号
    input                ret_valid, //返回数据有效
    input   [1  : 0]     ret_last,  //返回数据是一次读请求对应的最后一个返回数据
    input   [31 : 0]     ret_data   //读返回数据
    
  );

  // 主状态机 (只读 cache 没有 Write 状态机)
  localparam MAIN_IDLE    = 2'd0;
  localparam MAIN_LOOKUP  = 2'd1;
  localparam MAIN_REPLACE = 2'd2;
  localparam MAIN_REFILL  = 2'd3;

  reg [1:0] main_state;
  reg [1:0] main_next_state;

  // 2路组相连，每路256行，每行128位数据
  reg         cache_valid [0:1][0:255];
  reg [19:0]  cache_tag   [0:1][0:255];
  reg [127:0] cache_data  [0:1][0:255];

  // 锁存请求信息
  reg [7:0]   req_index;
  reg [19:0]  req_tag;
  reg [3:0]   req_offset;
  reg         miss_replace_way;

  reg [1:0]   refill_cnt;
  reg [127:0] refill_line;
  reg [127:0] refill_line_tmp;

  reg        data_ok_r;
  reg [31:0] rdata_r;

  reg [7:0] lfsr;

  wire hit0;
  wire hit1;
  wire hit;
  wire hit_way;
  wire [127:0] hit_line;
  wire [31:0]  hit_word;

  //  选择哪一个返回
  function [31:0] line_word;
    input [127:0] line;
    input [1:0] word_sel;
    begin
      case (word_sel)
        2'b00:
          line_word = line[31:0];
        2'b01:
          line_word = line[63:32];
        2'b10:
          line_word = line[95:64];
        default:
          line_word = line[127:96];
      endcase
    end
  endfunction

  // VITO Vaild->Index->Tag 证明 Cache hit
  assign hit0 = cache_valid[0][req_index] && (cache_tag[0][req_index] == req_tag);
  assign hit1 = cache_valid[1][req_index] && (cache_tag[1][req_index] == req_tag);
  assign hit = hit0 | hit1;
  assign hit_way = hit1;
  assign hit_line = hit1 ? cache_data[1][req_index] : cache_data[0][req_index];
  assign hit_word = line_word(hit_line, req_offset[3:2]);

  assign addr_ok = ((main_state == MAIN_IDLE) && valid) ||
         ((main_state == MAIN_LOOKUP) && hit && valid);
  assign data_ok = data_ok_r;
  assign rdata   = rdata_r;

  // 4次传输 每次32位
  assign rd_req  = (main_state == MAIN_REPLACE);
  assign rd_addr = {req_tag, req_index, 4'b0000};

  always @(*)
  begin
    main_next_state = main_state;
    case (main_state)
      MAIN_IDLE:
      begin
        if (valid)
          main_next_state = MAIN_LOOKUP;
        else
          main_next_state = MAIN_IDLE;
      end

      MAIN_LOOKUP:
      begin
        if (hit)
        begin
          if (valid)
            main_next_state = MAIN_LOOKUP;
          else
            main_next_state = MAIN_IDLE;
        end
        else
        begin
          main_next_state = MAIN_REPLACE;
        end
      end

      MAIN_REPLACE:
      begin
        if (rd_rdy)
          main_next_state = MAIN_REFILL;
        else
          main_next_state = MAIN_REPLACE;
      end

      MAIN_REFILL:
      begin
        if (ret_valid && ret_last[0])
          main_next_state = MAIN_IDLE;
        else
          main_next_state = MAIN_REFILL;
      end

      default:
      begin
        main_next_state = MAIN_IDLE;
      end
    endcase
  end

  integer i;
  integer j;
  always @(posedge clk)
  begin
    if (!resetn)
    begin
      main_state <= MAIN_IDLE;
      data_ok_r <= 1'b0;
      rdata_r <= 32'b0;

      req_index <= 8'b0;
      req_tag <= 20'b0;
      req_offset <= 4'b0;
      miss_replace_way <= 1'b0;

      refill_cnt <= 2'b0;
      refill_line <= 128'b0;
      refill_line_tmp <= 128'b0;

      lfsr <= 8'hFF;

      for (i = 0; i < 2; i = i + 1)
      begin
        for (j = 0; j < 256; j = j + 1)
        begin
          cache_valid[i][j] <= 1'b0;
          cache_tag[i][j] <= 20'b0;
          cache_data[i][j] <= 128'b0;
        end
      end
    end

    else
    begin
      main_state <= main_next_state;
      data_ok_r <= 1'b0;

      // 使用 LFSR 做随机替换
      lfsr <= {lfsr[6:0], lfsr[7] ^ lfsr[5] ^ lfsr[4] ^ lfsr[3]};

      // 锁存请求信息
      if (addr_ok)
      begin
        req_index <= index;
        req_tag <= tag;
        req_offset <= offset;
      end

      if (main_state == MAIN_LOOKUP)
      begin
        if (hit)
        begin
          rdata_r <= hit_word;
          data_ok_r <= 1'b1;
        end
        else
        begin
          if (!cache_valid[0][req_index])
            miss_replace_way <= 1'b0;
          else if (!cache_valid[1][req_index])
            miss_replace_way <= 1'b1;
          else
            miss_replace_way <= lfsr[0];
        end
      end

      if (main_state == MAIN_REPLACE && main_next_state == MAIN_REFILL)
      begin
        refill_cnt <= 2'b0;
        refill_line <= 128'b0;
      end

      if (main_state == MAIN_REFILL && ret_valid)
      begin
        refill_line_tmp = refill_line;
        case (refill_cnt)
          2'b00:
            refill_line_tmp[31:0] = ret_data;
          2'b01:
            refill_line_tmp[63:32] = ret_data;
          2'b10:
            refill_line_tmp[95:64] = ret_data;
          default:
            refill_line_tmp[127:96] = ret_data;
        endcase

        if (ret_last[0])
        begin
          cache_valid[miss_replace_way][req_index] <= 1'b1;
          cache_tag[miss_replace_way][req_index] <= req_tag;
          cache_data[miss_replace_way][req_index] <= refill_line_tmp;
          rdata_r <= line_word(refill_line_tmp, req_offset[3:2]);
          data_ok_r <= 1'b1;
        end
        else
        begin
          refill_line <= refill_line_tmp;
          refill_cnt <= refill_cnt + 2'b01;
        end
      end
    end
  end

endmodule
