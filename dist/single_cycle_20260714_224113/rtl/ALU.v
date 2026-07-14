`timescale 1ns / 1ps

`include "defines.vh"

module ALU (
    input  wire         rst,
    input  wire         clk,
    input  wire [ 4:0]  op,
    input  wire [31:0]  a,
    input  wire [31:0]  b,
    
    output reg  [31:0]  c,
    output reg          br,
    output wire         busy
);

    wire        mul_flag, mulu_flag;
    wire [63:0] mul_res;
    wire [65:0] mulu_res;
    wire        mul_busy, mulu_busy;
    wire        div_flag, divu_flag;
    wire [31:0] div_quo , divu_quo;
    wire [31:0] div_rem , divu_rem;
    wire        div_busy, divu_busy;
    reg  [ 4:0] op_r;
    reg  [31:0] a_r;
    reg         div_neg_r;
    reg         rem_neg_r;
    reg         div_zero_r;
    reg         div_overflow_r;

    wire [ 4:0] op_eff = (op_r != `ALU_NOP) ? op_r : op;
    wire [31:0] div_quo_signed = div_neg_r ? (~div_quo + 32'h1) : div_quo;
    wire [31:0] div_rem_signed = rem_neg_r ? (~div_rem + 32'h1) : div_rem;
    wire [31:0] a_abs = a[31] ? (~a + 32'h1) : a;
    wire [31:0] b_abs = b[31] ? (~b + 32'h1) : b;

    always @(*) begin
        case (op_eff)
            `ALU_ADD  : c = a + b;
            `ALU_SUB  : c = a - b;
            `ALU_AND  : c = a & b;
            `ALU_OR   : c = a | b;
            `ALU_XOR  : c = a ^ b;
            `ALU_SLL  : c = a << b[4:0];
            `ALU_SRL  : c = a >> b[4:0];
            `ALU_SRA  : c = $signed(a) >>> b[4:0];
            `ALU_SLT  : c = ($signed(a) < $signed(b)) ? 32'h1 : 32'h0;
            `ALU_SLTU : c = (a < b) ? 32'h1 : 32'h0;
            `ALU_MUL  : c = mul_res[31:0];
            `ALU_MULH : c = mul_res[63:32];
            `ALU_MULHU: c = mulu_res[63:32];
            `ALU_DIV  : c = div_zero_r ? 32'hffff_ffff :
                             div_overflow_r ? 32'h8000_0000 : div_quo_signed;
            `ALU_DIVU : c = div_zero_r ? 32'hffff_ffff : divu_quo;
            `ALU_REM  : c = div_zero_r ? a_r :
                             div_overflow_r ? 32'h0 : div_rem_signed;
            `ALU_REMU : c = div_zero_r ? a_r : divu_rem;
            default   : c = 32'h0;
        endcase
    end

    always @(*) begin
        case (op)
            `ALU_EQ : br = a == b;
            `ALU_NE : br = a != b;
            `ALU_LT : br = $signed(a) < $signed(b);
            `ALU_GE : br = $signed(a) >= $signed(b);
            `ALU_LTU: br = a < b;
            `ALU_GEU: br = a >= b;
            default : br = 1'b0;
        endcase
    end

    assign mul_flag  = (op == `ALU_MUL) | (op == `ALU_MULH);
    assign mulu_flag = (op == `ALU_MULHU);
    assign div_flag  = (op == `ALU_DIV) | (op == `ALU_REM);
    assign divu_flag = (op == `ALU_DIVU) | (op == `ALU_REMU);
    assign busy      = mul_busy | mulu_busy | div_busy | divu_busy;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            op_r           <= `ALU_NOP;
            a_r            <= 32'h0;
            div_neg_r      <= 1'b0;
            rem_neg_r      <= 1'b0;
            div_zero_r     <= 1'b0;
            div_overflow_r <= 1'b0;
        end else if (mul_flag | mulu_flag | div_flag | divu_flag) begin
            op_r           <= op;
            a_r            <= a;
            div_neg_r      <= a[31] ^ b[31];
            rem_neg_r      <= a[31];
            div_zero_r     <= b == 32'h0;
            div_overflow_r <= (a == 32'h8000_0000) & (b == 32'hffff_ffff);
        end else if (!busy) begin
            op_r           <= `ALU_NOP;
        end
    end

    multiplier #(32) U_mul (
        .clk    (clk),
        .rst    (rst),
        .x      (a),
        .y      (b),
        .start  (mul_flag),
        .z      (mul_res),
        .busy   (mul_busy)
    );

    multiplier #(33) U_mulu (
        .clk    (clk),
        .rst    (rst),
        .x      ({1'b0, a}),
        .y      ({1'b0, b}),
        .start  (mulu_flag),
        .z      (mulu_res),
        .busy   (mulu_busy)
    );

    divider #(32) U_div (
        .clk    (clk),
        .rst    (rst),
        .x      (a_abs),
        .y      (b_abs),
        .start  (div_flag),
        .z      (div_quo),
        .r      (div_rem),
        .busy   (div_busy)
    );

    divider #(32) U_divu (
        .clk    (clk),
        .rst    (rst),
        .x      (a),
        .y      (b),
        .start  (divu_flag),
        .z      (divu_quo),
        .r      (divu_rem),
        .busy   (divu_busy)
    );

endmodule
