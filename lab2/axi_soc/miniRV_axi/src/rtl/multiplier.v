`timescale 1ns / 1ps

module multiplier #(
    parameter WIDTH = 32
)(
    input  wire        clk,
    input  wire        rst,
    input  wire [WIDTH-1:0] x,
    input  wire [WIDTH-1:0] y,
    input  wire        start,
    output reg  [(WIDTH+WIDTH)-1:0] z,
    output wire        busy 
);

    localparam O_WID = WIDTH + WIDTH;
    localparam P_WID = O_WID + 2;

    reg [P_WID-1:0] product;
    reg [WIDTH:0] x_ext_r;
    reg [7:0] count;
    reg busy_r;

    wire [WIDTH:0] x_ext = {x[WIDTH-1], x};
    wire [WIDTH:0] prod_high = product[P_WID-1:WIDTH+1];
    reg  [WIDTH:0] next_high;
    reg  [P_WID-1:0] next_product;

    assign busy = busy_r;

    always @(*) begin
        case (product[1:0])
            2'b01  : next_high = prod_high + x_ext_r;
            2'b10  : next_high = prod_high - x_ext_r;
            default: next_high = prod_high;
        endcase
        next_product = $signed({next_high, product[WIDTH:0]}) >>> 1;
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            z       <= {O_WID{1'b0}};
            product <= {P_WID{1'b0}};
            x_ext_r <= {(WIDTH+1){1'b0}};
            count   <= 8'h0;
            busy_r  <= 1'b0;
        end else if (start & !busy_r) begin
            product <= {{(WIDTH+1){1'b0}}, y, 1'b0};
            x_ext_r <= x_ext;
            count   <= 8'h0;
            busy_r  <= 1'b1;
        end else if (busy_r) begin
            product <= next_product;
            if (count == WIDTH - 1) begin
                z      <= next_product[O_WID:1];
                busy_r <= 1'b0;
            end else begin
                count  <= count + 8'h1;
            end
        end
    end

endmodule
