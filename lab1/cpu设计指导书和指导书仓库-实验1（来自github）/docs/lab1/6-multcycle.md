&emsp;&emsp;在本课程的单周期CPU中，大部分指令能够在一个时钟周期内完成，但有两类特殊指令：访存指令和乘除法指令。

&emsp;&emsp;对于访存指令而言，发出访存请求后，CPU需要等待总线访问Cache或主存，而总线和主存通常需要多个时钟周期才能完成数据的读/写操作。

&emsp;&emsp;对于乘除法指令而言，乘除法操作需要多个时钟周期才能完成（比如Booth补码乘法、恢复余数或加减交替的原码除法都需要N个时钟周期才能完成N位数的运算）。

&emsp;&emsp;下面以miniRV为例，介绍访存指令、乘除法指令的实现要点，miniLA同理，不再赘述。

&emsp;&emsp;demo工程实现的是单周期CPU，每条指令只会在数据通路中停留一个时钟周期，如下列代码所示。

```verilog title="cpu_core.v" linenums="107"
// 按照约定的时序，ifetch_inst只在ifetch_valid有效时有效，且它们仅有效1个时钟.
// 此处是为了避免ifetch_valid撤销后，ifetch_inst发生变化从而导致指令执行出错.
assign inst = ifetch_valid ? ifetch_inst : 32'h13 /* NOP */ ;
```

&emsp;&emsp;指令只在数据通路中停留一个时钟周期，则指令译码产生的控制信号、寄存器操作数、立即数等信号也会只有效一个时钟周期。

&emsp;&emsp;为了保证访存指令和乘除法指令的正确运行，demo工程的单周期CPU在检测到当前正在执行这两类指令时，使用专门的寄存器把相应信号寄存起来。例如，对于访存指令，有下列代码：

```verilog title="cpu_core.v" linenums="147"
// 遇到访存指令时, 拉高ld_st_flag标志位，表示正在执行访存指令
assign is_ld_st = (ram_rop != `RAM_EXT_N) | (ram_wop != `RAM_WE_N);
always @(posedge cpu_clk or posedge cpu_rst) begin
    if      (cpu_rst)    ld_st_flag <= 1'b0;
    else if (is_ld_st)   ld_st_flag <= 1'b1;
    else if (ld_st_done) ld_st_flag <= 1'b0;
end
```

```verilog title="cpu_core.v" linenums="163"
// 访存、乘除法指令无法在1个时钟内执行完，故先把指令的目标寄存器缓存起来
always @(posedge cpu_clk) begin
    if (is_ld_st | is_mul_div) rf_wR_r <= inst[11:7];
end
```

```verilog title="cpu_core.v" linenums="203"
// 缓存访存地址和读访存的op信号，用于在主存返回数据后，对数据进行扩展操作
always @(posedge cpu_clk) if (is_ld_st) alu_c_r   <= alu_c;
always @(posedge cpu_clk) if (is_ld_st) ram_rop_r <= ram_rop;
```

&emsp;&emsp;当CPU的输入信号`daccess_rvalid`有效时，主存返回数据，此时读访存结束。因此有：

```verilog title="cpu_core.v" linenums="220"
assign ld_st_done = daccess_rvalid | daccess_wresp;
```

&emsp;&emsp;主存返回数据后，MEXT立即通过组合逻辑对数据进行扩展，而扩展操作完成后，读访存指令（如LW）即可进行写回操作：

```verilog title="cpu_core.v" linenums="223" hl_lines="1 5 12"
assign rf_we1 = ld_st_flag   & daccess_rvalid |                 // Load指令在读取到数据时写回
                mul_div_flag & !mul_div_busy  |                 // 乘除法指令在运算完成时写回
                ifetch_valid & rf_we & !is_ld_st & !is_mul_div; // 其他指令在取到指令时写回

assign rf_wR  = ld_st_flag | mul_div_flag ? rf_wR_r : inst[11:7];

always @(*) begin
    casex ({ld_st_flag, rf_wsel})
        {1'b0, `WB_ALU}: rf_wD = alu_c;
        {1'b0, `WB_PC4}: rf_wD = pc4;
        {1'b0, `WB_EXT}: rf_wD = ext;
        {1'b1, 2'b??  }: rf_wD = ram_ext;   // 读访存指令的写回值是MEXT.ext
        default        : rf_wD = 32'h0;
    endcase
end
```
