`timescale 1ns / 1ps

module seven_segment_hex_tb;
    reg clk = 1'b0;
    reg reset = 1'b1;
    reg [31:0] value = 32'h0123_4567;
    wire [7:0] dig_en;
    wire [7:0] dig_seg;
    wire [7:0] dig_seg1;

    seven_segment_hex #(.SCAN_COUNTER_BITS(1)) dut (
        .clk(clk), .reset(reset), .value(value),
        .dig_en(dig_en), .dig_seg(dig_seg), .dig_seg1(dig_seg1)
    );

    always #1 clk = ~clk;

    initial begin
        #3;
        reset = 1'b0;
        #1;

        // EGO1 digit-enable bits [7:4] select the dig_seg display bank.
        // The leftmost display position is the most-significant hexadecimal nibble.
        if (dig_en !== 8'b10000000 || dig_seg !== 8'b11111100 || dig_seg1 !== 8'b0)
            $fatal(1, "digit 0 did not display hexadecimal 0 on bank 0");

        // With SCAN_COUNTER_BITS=1, two clocks select the next digit.
        repeat (2) @(posedge clk);
        #1;
        if (dig_en !== 8'b01000000 || dig_seg !== 8'b01100000 || dig_seg1 !== 8'b0)
            $fatal(1, "digit 1 did not display hexadecimal 1 on bank 0");

        // Four more digit advances reaches digit 5, on the second display bank.
        repeat (8) @(posedge clk);
        #1;
        if (dig_en !== 8'b00000100 || dig_seg !== 8'b0 || dig_seg1 !== 8'b10110110)
            $fatal(1, "digit 5 did not display hexadecimal 5 on bank 1");

        $display("PASS: seven_segment_hex display protocol");
        $finish;
    end
endmodule
