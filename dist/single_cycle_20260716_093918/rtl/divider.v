`timescale 1ns / 1ps

module divider #(
    parameter WIDTH = 32
)(
    input  wire       clk,
    input  wire       rst,
    input  wire [WIDTH-1:0] x,
    input  wire [WIDTH-1:0] y,
    input  wire       start,
    output wire [WIDTH-1:0] z,
    output reg  [WIDTH-1:0] r,
    output reg        busy     
);

    reg [WIDTH-1:0] quotient;
    reg [WIDTH-1:0] quotient_out;
    reg [WIDTH-1:0] dividend;
    reg [WIDTH-1:0] divisor;
    reg [WIDTH:0]   remainder;
    reg [7:0]       count;

    wire [WIDTH:0] divisor_ext = {1'b0, divisor};
    wire [WIDTH:0] remainder_shift = {remainder[WIDTH-1:0], dividend[WIDTH-1]};
    wire [WIDTH:0] remainder_sub = remainder_shift - divisor_ext;
    wire           ge_divisor = remainder_shift >= divisor_ext;
    wire [WIDTH:0] remainder_next = ge_divisor ? remainder_sub : remainder_shift;
    wire [WIDTH-1:0] quotient_next = {quotient[WIDTH-2:0], ge_divisor};

    assign z = quotient_out;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            quotient     <= {WIDTH{1'b0}};
            quotient_out <= {WIDTH{1'b0}};
            dividend     <= {WIDTH{1'b0}};
            divisor      <= {WIDTH{1'b0}};
            remainder    <= {(WIDTH+1){1'b0}};
            r            <= {WIDTH{1'b0}};
            count        <= 8'h0;
            busy         <= 1'b0;
        end else if (start & !busy) begin
            if (y == {WIDTH{1'b0}}) begin
                quotient_out <= {WIDTH{1'b1}};
                r            <= x;
                busy         <= 1'b0;
            end else begin
                quotient     <= {WIDTH{1'b0}};
                quotient_out <= {WIDTH{1'b0}};
                dividend     <= x;
                divisor      <= y;
                remainder    <= {(WIDTH+1){1'b0}};
                r            <= {WIDTH{1'b0}};
                count        <= 8'h0;
                busy         <= 1'b1;
            end
        end else if (busy) begin
            quotient  <= quotient_next;
            dividend  <= {dividend[WIDTH-2:0], 1'b0};
            remainder <= remainder_next;
            if (count == WIDTH - 1) begin
                quotient_out <= quotient_next;
                r            <= remainder_next[WIDTH-1:0];
                busy         <= 1'b0;
            end else begin
                count        <= count + 8'h1;
            end
        end
    end

endmodule
