`timescale 1ns / 1ps

// EGO1 has two four-digit, common-cathode display banks. Both the digit
// select and segment outputs are active high, so one digit is refreshed at a
// time while the 32-bit memory-mapped display value is shown in hexadecimal.
module seven_segment_hex #(
    parameter integer SCAN_COUNTER_BITS = 16
)(
    input  wire        clk,
    input  wire        reset,
    input  wire [31:0] value,
    output reg  [7:0]  dig_en,
    output reg  [7:0]  dig_seg,
    output reg  [7:0]  dig_seg1
);
    localparam integer SCAN_COUNTER_WIDTH = SCAN_COUNTER_BITS + 3;
    reg [SCAN_COUNTER_WIDTH - 1:0] scan_counter;
    wire [2:0] active_digit = scan_counter[SCAN_COUNTER_BITS + 2:SCAN_COUNTER_BITS];

    function automatic [7:0] hex_to_segment(input [3:0] hex);
        begin
            case (hex)
                4'h0: hex_to_segment = 8'b11111100;
                4'h1: hex_to_segment = 8'b01100000;
                4'h2: hex_to_segment = 8'b11011010;
                4'h3: hex_to_segment = 8'b11110010;
                4'h4: hex_to_segment = 8'b01100110;
                4'h5: hex_to_segment = 8'b10110110;
                4'h6: hex_to_segment = 8'b10111110;
                4'h7: hex_to_segment = 8'b11100000;
                4'h8: hex_to_segment = 8'b11111110;
                4'h9: hex_to_segment = 8'b11110110;
                4'ha: hex_to_segment = 8'b11101110;
                4'hb: hex_to_segment = 8'b00111110;
                4'hc: hex_to_segment = 8'b10011100;
                4'hd: hex_to_segment = 8'b01111010;
                4'he: hex_to_segment = 8'b10011110;
                default: hex_to_segment = 8'b10001110;
            endcase
        end
    endfunction

    always @(posedge clk) begin
        if (reset) scan_counter <= {SCAN_COUNTER_WIDTH{1'b0}};
        else scan_counter <= scan_counter + {{SCAN_COUNTER_WIDTH - 1{1'b0}}, 1'b1};
    end

    always @(*) begin
        dig_en = 8'b00000001 << active_digit;
        dig_seg = 8'b0;
        dig_seg1 = 8'b0;
        if (active_digit < 3'd4)
            dig_seg = hex_to_segment(value[active_digit * 4 +: 4]);
        else
            dig_seg1 = hex_to_segment(value[active_digit * 4 +: 4]);
    end
endmodule
