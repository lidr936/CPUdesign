`timescale 1ns / 1ps

`include "defines.vh"

module MEXT (
    input  wire [ 2:0]  op,
    input  wire [31:0]  din,
    input  wire [ 1:0]  byte_offs,
    output reg  [31:0]  ext
);

    reg [31:0] real_din;
    always @(*) begin
        case (byte_offs)
            2'b01  : real_din = { 8'h0, din[31: 8]};
            2'b10  : real_din = {16'h0, din[31:16]};
            2'b11  : real_din = {24'h0, din[31:24]};
            default: real_din = din;
        endcase
    end

    // 根据访存指令的功能要求，对 从主存读取回来的数据 进行扩展.
    // 即根据op，使用real_din产生ext
    always @(*) begin
        case (op)
            `RAM_EXT_B : ext = {{24{real_din[7]}}, real_din[7:0]};
            `RAM_EXT_BU: ext = {24'h0, real_din[7:0]};
            `RAM_EXT_H : ext = {{16{real_din[15]}}, real_din[15:0]};
            `RAM_EXT_HU: ext = {16'h0, real_din[15:0]};
            default    : ext = real_din;
        endcase
    end

endmodule
