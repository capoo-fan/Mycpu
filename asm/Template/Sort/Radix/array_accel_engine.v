`timescale 1ns / 1ps
`default_nettype none

// Stable LSD radix sort for 32-bit unsigned words.
//
// RESULT_ADDR is an equally-sized, non-overlapping scratch array.  Each digit
// pass first counts buckets and forms exclusive prefix positions, then scatters
// the source in original order.  Source and scratch swap roles after each pass.
module array_accel_engine #(
    parameter [31:0] ARRAY_BEGIN = 32'h1c40_0000,
    parameter [31:0] ARRAY_END   = 32'h1c50_0000,
    parameter [31:0] RESULT_ADDR = 32'h1c50_0000,
    parameter [4:0]  RADIX_BITS  = 5'd4
)(
    input  wire        clk,
    input  wire        resetn,

    input  wire        start,
    output reg         busy,
    output reg         done,

    output wire        takeover_req,
    input  wire        takeover_grant,

    output reg         mem_req,
    output reg         mem_wr,
    output reg  [1:0]  mem_size,
    output reg  [3:0]  mem_wstrb,
    output reg  [31:0] mem_addr,
    output reg  [31:0] mem_wdata,

    input  wire        mem_addr_ok,
    input  wire        mem_data_ok,
    input  wire [31:0] mem_rdata
);

    localparam integer RADIX_SIZE = (1 << RADIX_BITS);
    localparam [RADIX_BITS-1:0] LAST_BUCKET = {RADIX_BITS{1'b1}};
    localparam [31:0] WORD_COUNT = (ARRAY_END - ARRAY_BEGIN) >> 2;
    // In 5-bit arithmetic, 0-RADIX_BITS is exactly 32-RADIX_BITS.
    localparam [4:0] LAST_PASS_SHIFT = 5'b0 - RADIX_BITS;

    localparam [3:0]
        S_IDLE          = 4'd0,
        S_WAIT_BUS      = 4'd1,
        S_CLEAR         = 4'd2,
        S_COUNT_REQ     = 4'd3,
        S_COUNT_WAIT    = 4'd4,
        S_PREFIX        = 4'd5,
        S_SCATTER_REQ   = 4'd6,
        S_SCATTER_WAIT  = 4'd7,
        S_WRITE_REQ     = 4'd8,
        S_WRITE_WAIT    = 4'd9,
        S_COPY_REQ      = 4'd10,
        S_COPY_WAIT     = 4'd11,
        S_COPY_WREQ     = 4'd12,
        S_COPY_WWAIT    = 4'd13;

    reg [3:0] state;
    reg [4:0] pass_shift;
    reg [RADIX_BITS-1:0] bucket_index;
    reg [31:0] element_index;
    reg [31:0] prefix_sum;
    reg [31:0] source_base;
    reg [31:0] dest_base;
    reg [31:0] element_data;
    reg [31:0] scatter_addr;
    reg [RADIX_BITS-1:0] element_digit;

    reg [31:0] bucket_count [0:RADIX_SIZE-1];
    reg [31:0] bucket_position [0:RADIX_SIZE-1];

    wire [RADIX_BITS-1:0] response_digit =
        mem_rdata[pass_shift +: RADIX_BITS];
    wire current_pass_is_last = (pass_shift == LAST_PASS_SHIFT);
    wire current_element_is_last = ((element_index + 32'd1) >= WORD_COUNT);
    wire request_fire = mem_req && mem_addr_ok;

    assign takeover_req = busy;

    always @(*) begin
        mem_req   = 1'b0;
        mem_wr    = 1'b0;
        mem_size  = 2'b10;
        mem_wstrb = 4'b0000;
        mem_addr  = 32'b0;
        mem_wdata = 32'b0;

        if (takeover_grant) begin
            case (state)
                S_COUNT_REQ,
                S_SCATTER_REQ: begin
                    mem_req  = 1'b1;
                    mem_addr = source_base + (element_index << 2);
                end

                S_WRITE_REQ: begin
                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;
                    mem_wstrb = 4'b1111;
                    mem_addr  = scatter_addr;
                    mem_wdata = element_data;
                end

                S_COPY_REQ: begin
                    mem_req  = 1'b1;
                    mem_addr = source_base + (element_index << 2);
                end

                S_COPY_WREQ: begin
                    mem_req   = 1'b1;
                    mem_wr    = 1'b1;
                    mem_wstrb = 4'b1111;
                    mem_addr  = ARRAY_BEGIN + (element_index << 2);
                    mem_wdata = element_data;
                end

                default: begin
                end
            endcase
        end
    end

    always @(posedge clk) begin
        if (!resetn) begin
            state         <= S_IDLE;
            busy          <= 1'b0;
            done          <= 1'b0;
            pass_shift    <= 5'b0;
            bucket_index  <= {RADIX_BITS{1'b0}};
            element_index <= 32'b0;
            prefix_sum    <= 32'b0;
            source_base   <= ARRAY_BEGIN;
            dest_base     <= RESULT_ADDR;
            element_data  <= 32'b0;
            scatter_addr  <= 32'b0;
            element_digit <= {RADIX_BITS{1'b0}};
        end
        else begin
            done <= 1'b0;

            case (state)
                S_IDLE: begin
                    busy <= 1'b0;
                    if (start) begin
                        busy          <= 1'b1;
                        pass_shift    <= 5'b0;
                        bucket_index  <= {RADIX_BITS{1'b0}};
                        element_index <= 32'b0;
                        source_base   <= ARRAY_BEGIN;
                        dest_base     <= RESULT_ADDR;
                        state         <= S_WAIT_BUS;
                    end
                end

                S_WAIT_BUS: begin
                    if (takeover_grant) begin
                        if (WORD_COUNT < 32'd2) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            bucket_index <= {RADIX_BITS{1'b0}};
                            state        <= S_CLEAR;
                        end
                    end
                end

                S_CLEAR: begin
                    bucket_count[bucket_index]    <= 32'b0;
                    bucket_position[bucket_index] <= 32'b0;
                    if (bucket_index == LAST_BUCKET) begin
                        bucket_index  <= {RADIX_BITS{1'b0}};
                        element_index <= 32'b0;
                        state         <= S_COUNT_REQ;
                    end
                    else begin
                        bucket_index <= bucket_index + 1'b1;
                    end
                end

                S_COUNT_REQ: begin
                    if (request_fire) begin
                        if (mem_data_ok) begin
                            bucket_count[response_digit] <=
                                bucket_count[response_digit] + 32'd1;
                            if (current_element_is_last) begin
                                bucket_index <= {RADIX_BITS{1'b0}};
                                prefix_sum   <= 32'b0;
                                state        <= S_PREFIX;
                            end
                            else begin
                                element_index <= element_index + 32'd1;
                            end
                        end
                        else begin
                            state <= S_COUNT_WAIT;
                        end
                    end
                end

                S_COUNT_WAIT: begin
                    if (mem_data_ok) begin
                        bucket_count[response_digit] <=
                            bucket_count[response_digit] + 32'd1;
                        if (current_element_is_last) begin
                            bucket_index <= {RADIX_BITS{1'b0}};
                            prefix_sum   <= 32'b0;
                            state        <= S_PREFIX;
                        end
                        else begin
                            element_index <= element_index + 32'd1;
                            state         <= S_COUNT_REQ;
                        end
                    end
                end

                S_PREFIX: begin
                    bucket_position[bucket_index] <= prefix_sum;
                    prefix_sum <= prefix_sum + bucket_count[bucket_index];
                    if (bucket_index == LAST_BUCKET) begin
                        bucket_index  <= {RADIX_BITS{1'b0}};
                        element_index <= 32'b0;
                        state         <= S_SCATTER_REQ;
                    end
                    else begin
                        bucket_index <= bucket_index + 1'b1;
                    end
                end

                S_SCATTER_REQ: begin
                    if (request_fire) begin
                        if (mem_data_ok) begin
                            element_data  <= mem_rdata;
                            element_digit <= response_digit;
                            scatter_addr  <= dest_base +
                                (bucket_position[response_digit] << 2);
                            state <= S_WRITE_REQ;
                        end
                        else begin
                            state <= S_SCATTER_WAIT;
                        end
                    end
                end

                S_SCATTER_WAIT: begin
                    if (mem_data_ok) begin
                        element_data  <= mem_rdata;
                        element_digit <= response_digit;
                        scatter_addr  <= dest_base +
                            (bucket_position[response_digit] << 2);
                        state <= S_WRITE_REQ;
                    end
                end

                S_WRITE_REQ: begin
                    if (request_fire) begin
                        if (mem_data_ok) begin
                            bucket_position[element_digit] <=
                                bucket_position[element_digit] + 32'd1;
                            if (current_element_is_last) begin
                                if (current_pass_is_last) begin
                                    if (dest_base == ARRAY_BEGIN) begin
                                        busy  <= 1'b0;
                                        done  <= 1'b1;
                                        state <= S_IDLE;
                                    end
                                    else begin
                                        source_base   <= dest_base;
                                        element_index <= 32'b0;
                                        state         <= S_COPY_REQ;
                                    end
                                end
                                else begin
                                    source_base  <= dest_base;
                                    dest_base    <= source_base;
                                    pass_shift   <= pass_shift + RADIX_BITS;
                                    bucket_index <= {RADIX_BITS{1'b0}};
                                    state        <= S_CLEAR;
                                end
                            end
                            else begin
                                element_index <= element_index + 32'd1;
                                state         <= S_SCATTER_REQ;
                            end
                        end
                        else begin
                            state <= S_WRITE_WAIT;
                        end
                    end
                end

                S_WRITE_WAIT: begin
                    if (mem_data_ok) begin
                        bucket_position[element_digit] <=
                            bucket_position[element_digit] + 32'd1;
                        if (current_element_is_last) begin
                            if (current_pass_is_last) begin
                                if (dest_base == ARRAY_BEGIN) begin
                                    busy  <= 1'b0;
                                    done  <= 1'b1;
                                    state <= S_IDLE;
                                end
                                else begin
                                    source_base   <= dest_base;
                                    element_index <= 32'b0;
                                    state         <= S_COPY_REQ;
                                end
                            end
                            else begin
                                source_base  <= dest_base;
                                dest_base    <= source_base;
                                pass_shift   <= pass_shift + RADIX_BITS;
                                bucket_index <= {RADIX_BITS{1'b0}};
                                state        <= S_CLEAR;
                            end
                        end
                        else begin
                            element_index <= element_index + 32'd1;
                            state         <= S_SCATTER_REQ;
                        end
                    end
                end

                S_COPY_REQ: begin
                    if (request_fire) begin
                        if (mem_data_ok) begin
                            element_data <= mem_rdata;
                            state        <= S_COPY_WREQ;
                        end
                        else begin
                            state <= S_COPY_WAIT;
                        end
                    end
                end

                S_COPY_WAIT: begin
                    if (mem_data_ok) begin
                        element_data <= mem_rdata;
                        state        <= S_COPY_WREQ;
                    end
                end

                S_COPY_WREQ: begin
                    if (request_fire) begin
                        if (mem_data_ok) begin
                            if (current_element_is_last) begin
                                busy  <= 1'b0;
                                done  <= 1'b1;
                                state <= S_IDLE;
                            end
                            else begin
                                element_index <= element_index + 32'd1;
                                state         <= S_COPY_REQ;
                            end
                        end
                        else begin
                            state <= S_COPY_WWAIT;
                        end
                    end
                end

                S_COPY_WWAIT: begin
                    if (mem_data_ok) begin
                        if (current_element_is_last) begin
                            busy  <= 1'b0;
                            done  <= 1'b1;
                            state <= S_IDLE;
                        end
                        else begin
                            element_index <= element_index + 32'd1;
                            state         <= S_COPY_REQ;
                        end
                    end
                end

                default: begin
                    state <= S_IDLE;
                    busy  <= 1'b0;
                end
            endcase
        end
    end

`ifndef SYNTHESIS
    localparam [31:0] SCRATCH_END =
        RESULT_ADDR + (ARRAY_END - ARRAY_BEGIN);

    initial begin
        if (ARRAY_BEGIN[1:0] != 2'b00)
            $error("Radix ARRAY_BEGIN must be word aligned");
        if (ARRAY_END[1:0] != 2'b00)
            $error("Radix ARRAY_END must be word aligned");
        if (RESULT_ADDR[1:0] != 2'b00)
            $error("Radix RESULT_ADDR must be word aligned");
        if (ARRAY_END < ARRAY_BEGIN)
            $error("Radix ARRAY_END must not precede ARRAY_BEGIN");
        if ((RADIX_BITS != 5'd1) && (RADIX_BITS != 5'd2) &&
            (RADIX_BITS != 5'd4) && (RADIX_BITS != 5'd8))
            $error("RADIX_BITS must be 1, 2, 4, or 8");
        if ((ARRAY_BEGIN < ARRAY_END) &&
            (RESULT_ADDR < ARRAY_END) && (SCRATCH_END > ARRAY_BEGIN))
            $error("Radix source and scratch ranges must not overlap");
    end
`endif

endmodule

`default_nettype wire
