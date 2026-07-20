&emsp;&emsp;不管是使用高级语言进行软件开发，还是使用HDL进行硬件设计，都要尽量遵循代码可配置的原则。对于常量或参数，应当在代码中使用宏定义的方式来引用。使用宏定义，不仅可以保证代码具有良好的可配置性，还能提高代码的规范性和可读性。

&emsp;&emsp;我们在“控制单元设计”的一节中，设计了如表5-2所示的控制信号取值表。应该注意到，明明是控制信号的取值表，表中的npc_op和alu_op却用字符串作为信号取值，显得“格格不入”。事实上，npc_op和alu_op的取值就是以宏定义的方式来表示的。将npc_op、alu_op与其他控制信号相比，可以发现宏定义的表达方式不仅更方便阅读、更容易为人所理解，而且有利于代码维护。

&emsp;&emsp;Verilog HDL中使用宏定义的方法是：

&emsp;&emsp;（1）新建`.vh`头文件 (如`param.vh`或`defines.vh`)，用来编写宏定义；

&emsp;&emsp;（2）使用``define`关键字定义宏参数，如图10-1所示。

``` Verilog title="param.vh" linenums="1"
`ifndef PARAM_VH
`define PARAM_VH

// syntax: `define <macro name> <parameter>
`define ADD     3'b000
`define SUB     3'b001
`define OR      3'b010
`define AND     3'b011
......

`define STATE_IDLE 4'b0001
`define STATE_WRIT 4'b0010
`define STATE_WORK 4'b0100
`define STATE_RETU 4'b1000
......

`endif
```
<center>图10-1 Verilog HDL定义宏参数（示例）</center>

&emsp;&emsp;（3）在需要使用宏定义的设计文件中，使用``include`语句包含头文件，并通过``` ` ```符号使用宏定义，如图10-2所示。

``` Verilog linenums="1"
`include "param.vh"         // 包含头文件

module SOME_MODULE (
    input  wire         cpu_clk,
    input  wire         cpu_rst,
    output reg  [ 2:0]  out
);

    always @ (posedge cpu_clk or posedge cpu_rst) begin
        if (rst) begin
            out <= `ADD;    // 使用宏定义
        end else begin
            ......
        end
    end

endmodule
```

<center>图10-2 包含头文件并使用宏定义</center>
