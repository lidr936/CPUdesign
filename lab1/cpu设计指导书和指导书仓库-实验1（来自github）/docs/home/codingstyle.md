## 1. 命名规范

### 1.1 文件命名规范

- 仿真文件应使用后缀`_sim`，如`modulename_sim`；

- 测试文件应使用后缀`_tb`，如`modulename_tb`。

### 1.2 模块命名规范

- 一个文件只定义一个`module`；

- `module`名应与文件名一致。


### 1.3 信号命名规范

- 用小写字母定义`wire`、`reg`和`input`、`inout`、`output`信号；

- 用大写字母定义`parameter`、`localparam`和宏定义；

- 信号名应反映信号的含义/用途，不要随意命名，更不能使用单个字母命名；

- 变量名若含有多个单词，用下划线分开，如`ram_addr`，或使用驼峰命名法；

- 输入信号应使用后缀`_i`，如`addr_i`；

- 输出信号应使用后缀`_o`，如`data_o`；

- 时钟信号应使用前缀`clk`，如`clk_i`、`cpu_clk`；

- 复位信号应使用前缀`rst`，如`rstn_i`；

- 低电平有效的信号应带`n`后缀，如`rstn_i`；

- 使用降序排列定义向量有效位顺序，最低位为0。

## 2. 代码编写规范
	
### 2.1 模块定义规范

- 每个模块加``` `timescale ```，Vivado默认为``timescale 1ns / 1ps`；

- 出于方便考虑，推荐使用如以下代码所示的模块定义写法。

``` Verilog linenums="1"
`timescale 1ns / 1ps

module some_module (
    input  wire         clk_i  ,
    input  wire         rstn_i ,
    input  wire [1:0]   sel_i  ,        // 输入信号均为wire型
    input  wire [7:0]   addr_i ,
    output reg  [7:0]   data_o          // 输出信号根据需要，可声明为reg或wire型
);

    // 模块代码
    ......

endmodule
```


### 2.2 参数规范

- 不需在模块实例化时设置的参数，应将其定义为局部参数（`localparam`）；

- 全局参数建议放在I/O端口前面，如图3所示。

``` Verilog linenums="1"
module some_module #(
    parameter PARAM1 = 8,   // 参数默认值
    parameter PARAM2 = 2
)(
    input  wire         clk_i ,
    input  wire         rstn_i,
    ......
);
```


### 2.3 模块实例化规范

- 模块实例应用`U_xx_x`表示（多次例化用序号0、1、2等表示）；

- 实例化模块时，推荐采用以下写法。

``` Verilog linenums="1"
some_module #(
    .PARAM1     (`WIDTH),
    .PARAM2     (`DEPTH)    // 参数
) U_some_module_0 (         // 实例名
    .clk_i      (clk_fpga  ),
    .rstn_i     (rst_fpga_n),
    ......
);
```

### 2.4 通用规范

- 尽量采用参数化设计；

- 所有的`if`语句应有与之对应的`else`，特别是组合逻辑；

- `case`语句应考虑`default`情况，特别是组合逻辑；

- `if`-`else`语句尽量不要嵌套太多；

- 在RTL级代码中不能含有`initial`结构，也不可对任何信号进行初始化赋值。若需要初始化，应采用复位的方式：

``` Verilog linenums="1"
// 错误的初始化
initial begin
    data1   = 8'h12;
    signal2 = 12'hABC;
end

// 错误的初始化
reg [ 7:0] data1   = 8'h12;
reg [11:0] signal2 = 12'hABC;

// 正确的初始化
always @ (posedge clk or posedge rst) begin
    if (rst) begin
        data1   <= 8'h12;
        signal2 <= 12'hABC;
    end else begin
        ......
    end
end
```

- 尽量不产生未连接的端口；

- 信号赋值或实例化时，应保证数据位宽匹配；

- 顶层模块的输出信号必须被寄存；

- 常量应标注其位宽，如`1’b0`；

- 不建议使用`for`、`repeat`、`while`等语句；

- 如非必要，不使用`integer`类型；

- 尽量不使用复杂的表达式，可以使用三目运算符`?:`。

### 2.5 组合逻辑规范

- 如果需要使用`always`语句实现组合逻辑，则敏感信号列表应为`*`，即：

``` Verilog linenums="1"
always @(*) begin
    ......
end
```

- 组合逻辑always块使用阻塞赋值`=`。

### 2.6 时序逻辑规范

- 采用同步设计，避免使用异步逻辑（全局信号复位除外）；

- 同步时序逻辑的`always`块中有且只有一个时钟信号，并且在同一个沿动作（如上升沿），一般不使用下降沿；

- 在时序`always`块的敏感信号列表中必须都是边沿触发，不允许出现电平触发；

- 敏感信号列表中不允许出现表达式；

- 除异步复位之外，敏感信号列表中不允许同时出现`posedge`和`negedge`；

- 时序逻辑语句块中统一使用非阻塞型赋值`<=`；

- 一个`always`块只对一个变量赋值，或只对有关系的一组信号赋值；

- 建议多使用中间变量。
