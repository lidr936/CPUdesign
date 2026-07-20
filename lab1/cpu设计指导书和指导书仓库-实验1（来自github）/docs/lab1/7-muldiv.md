&emsp;&emsp;实现乘除法指令时，**要求自行实现硬件乘/除法器**，不能使用运算符或现成的IP核。

&emsp;&emsp;我们在计算机组成原理实验中，已经完成了基于Booth算法的硬件补码乘法器设计。因此，我们可以将其集成到ALU当中。

&emsp;&emsp;在demo工程中，**乘/除法器的接口信号及时序完全相同**，具体请参考<a href="https://organ.p.cs-lab.top/lab2/1-theory/#22" target=_blank>乘法器的接口信号时序</a>。该时序可概括为：（1）启动信号`start`有效一个时钟周期表示开始运算；（2）运算过程中忙标志位`busy`有效；（3）当`busy`从有效变成无效时，运算完成并输出结果。

&emsp;&emsp;由上一节可知，指令机器码信号`inst`只有效一个时钟周期。控制器是组合逻辑，因此指令译码产生的`alu_op`信号也只有效一个时钟周期。ALU内部可通过组合逻辑判断`alu_op`的值，从而产生乘除法运算的相应标志位：

```verilog title="ALU.v" linenums="43"
assign mul_flag  = 1'b0;    // TODO: 根据op的值判断当前执行的是否是mul、mulh指令
assign mulu_flag = 1'b0;    // TODO: 根据op的值判断当前执行的是否是mulhu指令
assign div_flag  = 1'b0;    // TODO: 根据op的值判断当前执行的是否是div、rem指令
assign divu_flag = 1'b0;    // TODO: 根据op的值判断当前执行的是否是divu、remu指令
```

&emsp;&emsp;显然，`mul_flag`等标志位只有效一个时钟周期，因此这些标志位信号可用作乘/除法器的`start`启动信号。

&emsp;&emsp;类似地，当标志位有效时，把ALU的`op`信号寄存起来：

```verilog title="ALU.v" linenums="50" hl_lines="2 3"
always @(posedge clk) begin
    if (mul_flag | mulu_flag | div_flag | divu_flag)
        op_r <= op;
    else if (!busy)
        op_r <= 4'h0;
end
```

&emsp;&emsp;在乘除法运算过程中，使用寄存起来的`op_r`信号来产生ALU的运算结果：

```verilog title="ALU.v" linenums="26" hl_lines="2"
always @(*) begin
    case (op_r != 4'h0 ? op_r : op)
        ......
    endcase
end
```

&emsp;&emsp;另外，还需要注意乘除法运算的符号问题。我们前面实现的是补码乘法器，而补码是用来表示有符号数的。如果使用补码乘法器来实现无符号运算，则需要在源数据的最高位额外再补一位0，从而令乘法器把数据当成正数来处理：

```verilog title="ALU.v" linenums="67" hl_lines="1 4 5"
multiplier #(33) U_mulu (   // 无符号乘法器的数据位宽是33bit
    .clk    (clk),
    .rst    (rst),
    .x      ({1'b0, a}),
    .y      ({1'b0, b}),
    .start  (mulu_flag),
    .z      (mulu_res),
    .busy   (mulu_busy)
);
```

&emsp;&emsp;对于除法器，此处以原码除法器为例，介绍除法运算的实现方法。无符号运算的处理方法与乘法器相同，而对于有符号运算，则需要根据符号位判断：如果是正数，则无需特殊处理；如果是负数，则需要使用“扫描法”求出其原码再进行运算：

```verilog title="ALU.v" linenums="67" hl_lines="4 5"
divider #(32) U_div (
    .clk    (clk),
    .rst    (rst),
    .x      (a[31] ? {1'b1, ~a[30:0] + 31'h1} : a),
    .y      (b[31] ? {1'b1, ~b[30:0] + 31'h1} : b),
    .start  (div_flag),
    .z      (div_quo),
    .r      (div_rem),
    .busy   (div_busy)
);
```
