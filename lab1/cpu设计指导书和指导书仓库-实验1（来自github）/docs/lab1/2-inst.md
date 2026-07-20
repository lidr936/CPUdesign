&emsp;&emsp;本实验要求同学们基于miniRV指令集实现单周期CPU。miniRV是RV32I的子集，因而兼容RISC-V。

&emsp;&emsp;miniRV指令集共包含32个通用寄存器和37条指令 (含R型10条、I型15条、S型3条、B型6条、U型2条、J型1条)。



## 1. miniRV通用寄存器

&emsp;&emsp;miniRV具有32个32位通用寄存器，与RV32I完全相同，如表2-1所示。

<center>表2-1 miniRV通用寄存器</center>

<center>

| 寄存器 | 助记符 | 释义 |
| :-: | :-: | :- |
| x0 | zero | 常数0，永远只返回0 (硬件0，只读不可写) |
| x1 | ra | 存放调用子程序(函数)时的返回地址 (Return Address) |
| x2 | sp | 堆栈指针。对它的调整必须显式地通过指令来实现，硬件不支持堆栈指针的调整 (Stack Pointer) |
| x3 | gp | 全局指针。某些运行时系统用来为static或extern变量提供简单的访问方式 (Global Pointer) |
| x4 | tp | 线程指针。多线程应用程序通过该寄存器来访问某个线程的本地数据 (Thread Pointer) |
| x5~x7 | t0~t2 | 存放临时变量，子程序(函数)使用时不自动保存这些寄存器的值，因此调用后它们的值可能被破坏 |
| x8 | s0/fp | 子程序用该寄存器做堆栈帧指针。子程序(函数)必须在返回前恢复这些寄存器的值以保证其没有变化 (Saved Register / Frame Pointer) |
| x9 | s1 | 子程序用寄存器。子程序(函数)必须在返回前恢复这些寄存器的值以保证其没有变化 (Saved Register) |
| x10~x11 | a0~a1 | 存放子程序(函数)调用时的整型参数或返回值 |
| x12~x17 | a2~a7 | 存放子程序(函数)调用时的整型参数 |
| x18~x27 | s2~s11 | 子程序用寄存器。子程序(函数)必须在返回前恢复这些寄存器的值以保证其没有变化 (Saved Register) |
| x28~x31 | t3~t6 | 存放临时变量，子程序(函数)使用时不自动保存这些寄存器的值，因此调用后它们的值可能被破坏 |

</center>

&emsp;&emsp;在汇编语言中，既可以通过寄存器号也可以通过助记符来引用一个寄存器。例如，汇编中的“x0”和“zero”均表示第0个寄存器；“x8”、“s0”和“fp”均表示第8个寄存器。



## 2. miniRV指令格式

&emsp;&emsp;miniRV指令集的指令格式与RISC-V完全相同，如图2-1所示。

<center><img src = "../assets/2-1.png" width = 650></center>
<center>图2-1 miniRV指令格式</center>

## 3. miniRV指令速查表

&emsp;&emsp;miniRV指令的格式、功能、语法及解释汇总如表2-2所示。其中，浅蓝色背景的是A组指令，浅橙色的则是B组指令，而绿色字体的指令则是demo工程已经实现的指令。

<center>表2-2 miniRV指令速查表</center>
<center><img src = "../assets/t2-2.png"></center>

&emsp;&emsp;下面对每条指令的格式、功能等给出详细解释，所使用的符号约定如表2-3所示。

<center>表2-3 符号释义</center>

<center>

| 符号 | 释义 |
| :-: | :- |
| rs1、rs2、rd | 32位通用寄存器的编号 (rs1、rs2存放源操作数，rd存放目的操作数) |
| shamt | 5位移位位数 |
| imm | 12位立即数 |
| offset | 12位偏移量 |
| PC | 赋值符号右侧的PC表示当前指令的地址 |
| (rs1) | 寄存器rs1的值 (其他同理) |
| Mem[addr] | 地址为addr的存储单元的值 |
| sext(a) | a的符号扩展 |

</center>



## 4. 指令详解

### 4.1 R型指令

#### add  
- 指令名：加法  
- 使用语法：`add rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`加上寄存器`rs2`，结果写入寄存器`rd`。忽略算术溢出。  
- 汇编例子：
<center>
``` asm
add x4, x2, x3    # (x4) ← (x2) + (x3), (PC) ← (PC) + 4
```
</center>

#### sub  
- 指令名：减法  
- 使用语法：`sub rd, rs1, rs2`  
- 功能描述：从寄存器`rs1`减去寄存器`rs2`，结果写入寄存器`rd`。忽略算术溢出。  
- 汇编例子：
<center>
``` asm
sub x7, x5, x9    # (x7) ← (x5) - (x9), (PC) ← (PC) + 4
```
</center>

#### and  
- 指令名：逻辑与  
- 使用语法：`and rd, rs1, rs2`  
- 功能描述：将寄存器`rs1`和寄存器`rs2`进行按位与，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
and x6, x1, x0    # (x6) ← (x1) & (x0), (PC) ← (PC) + 4
```
</center>

#### or  
- 指令名：逻辑或  
- 使用语法：`or rd, rs1, rs2`  
- 功能描述：将寄存器`rs1`和寄存器`rs2`进行按位或，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
or x12, x13, x1    # (x12) ← (x13) | (x1), (PC) ← (PC) + 4
```
</center>

#### xor  
- 指令名：逻辑异或  
- 使用语法：`xor rd, rs1, rs2`  
- 功能描述：将寄存器`rs1`和寄存器`rs2`进行按位异或，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
xor t0, t0, t0    # (t0) ← (t0) ^ (t0), (PC) ← (PC) + 4
```
</center>

#### sll  
- 指令名: 逻辑左移  
- 使用语法：`sll rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`左移`rs2`位，低位补0，结果写入寄存器`rd`。`rs2[4:0]`表示左移位数，高位忽略。  
- 汇编例子：
<center>
``` asm
sll t1, t6, t2    # (t1) ← (t6) << (t2), (PC) ← (PC) + 4
```
</center>

#### srl  
- 指令名: 逻辑右移  
- 使用语法：`srl rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`右移`rs2`位，高位补0，结果写入寄存器`rd`。`rs2[4:0]`表示右移位数，高位忽略。  
- 汇编例子：
<center>
``` asm
srl t5, t3, t4    # (t5) ← (t3) >> (t4), (PC) ← (PC) + 4
```
</center>

#### sra  
- 指令名: 算术右移  
- 使用语法：`sra rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`右移`rs2`位，高位补`rs1[31]`，结果写入寄存器`rd`。`rs2[4:0]`表示右移位数，高位忽略。  
- 汇编例子：
<center>
``` asm
sra t3, t4, t7    # (t3) ← (t4) >> (t7), (PC) ← (PC) + 4
```
</center>

#### slt  
- 指令名: 小于则置位  
- 使用语法：`slt rd, rs1, rs2`  
- 功能描述：比较寄存器`rs1`和寄存器`rs2`，比较时视为有符号数。如果`rs1`更小，向寄存器`rd`写入1，否则写入0。  
- 汇编例子：
<center>
``` asm
slt t1, t2, t0    # (t1) ← ((t2) < (t0)), (PC) ← (PC) + 4
```
</center>

#### sltu  
- 指令名: 无符号小于则置位  
- 使用语法：`sltu rd, rs1, rs2`  
- 功能描述：比较寄存器`rs1`和寄存器`rs2`，比较时视为无符号数。如果`rs1`更小，向寄存器`rd`写入1，否则写入0。  
- 汇编例子：
<center>
``` asm
sltu s5, t1, s1    # (s5) ← ((t1) < (s1)), (PC) ← (PC) + 4
```
</center>

#### mul  
- 指令名: 乘法取低32位  
- 使用语法：`mul rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`和寄存器`rs2`相乘，乘积的低32位写入`rd`。  
- 汇编例子：
<center>
``` asm
mul s5, t1, s1    # (s5) ← ((t1) × (s1))[31:0], (PC) ← (PC) + 4
```
</center>

#### mulh  
- 指令名: 有符号乘法取高32位  
- 使用语法：`mulh rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`和寄存器`rs2`作有符号乘法，乘积的高32位写入`rd`。  
- 汇编例子：
<center>
``` asm
mulh s5, t1, s1    # (s5) ← ((t1) × (s1))[63:32], (PC) ← (PC) + 4
```
</center>

#### mulhu  
- 指令名: 无符号乘法取高32位  
- 使用语法：`mulhu rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`和寄存器`rs2`作无符号乘法，乘积的高32位写入`rd`。  
- 汇编例子：
<center>
``` asm
mulhu s5, t1, s1    # (s5) ← ((t1) × (s1))[63:32], (PC) ← (PC) + 4
```
</center>

#### div  
- 指令名: 有符号除法  
- 使用语法：`div rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`和寄存器`rs2`视为有符号数，并计算`rs1` ÷ `rs2`，商写入`rd`。  
- 汇编例子：
<center>
``` asm
div s5, t1, s1    # (s5) ← (t1) / (s1), (PC) ← (PC) + 4
```
</center>

#### divu  
- 指令名: 无符号除法  
- 使用语法：`divu rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`和寄存器`rs2`视为无符号数，并计算`rs1` ÷ `rs2`，商写入`rd`。  
- 汇编例子：
<center>
``` asm
divu s5, t1, s1    # (s5) ← (t1) / (s1), (PC) ← (PC) + 4
```
</center>

#### rem  
- 指令名: 有符号求余  
- 使用语法：`rem rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`和寄存器`rs2`视为有符号数，并计算`rs1` ÷ `rs2`，余数写入`rd`。  
- 汇编例子：
<center>
``` asm
rem s5, t1, s1    # (s5) ← (t1) % (s1), (PC) ← (PC) + 4
```
</center>

#### remu  
- 指令名: 无符号求余 
- 使用语法：`remu rd, rs1, rs2`  
- 功能描述：把寄存器`rs1`和寄存器`rs2`视为无符号数，并计算`rs1` ÷ `rs2`，余数写入`rd`。  
- 汇编例子：
<center>
``` asm
remu s5, t1, s1    # (s5) ← (t1) % (s1), (PC) ← (PC) + 4
```
</center>


### 4.2 I型指令
#### addi  
- 指令名：立即数加法  
- 使用语法：`addi rd, rs1, imm`  
- 功能描述：把符号扩展的立即数加到寄存器`rs1`上，结果写入寄存器`rd`。忽略算术溢出。  
- 汇编例子：
<center>
``` asm
addi sp, sp, 4    # (sp) ← (sp) + 4, (PC) ← (PC) + 4
```
</center>

#### andi  
- 指令名：立即数逻辑与  
- 使用语法：`andi rd, rs1, imm`  
- 功能描述：把符号扩展的立即数与寄存器`rs1`的值进行按位与，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
andi t1, t3, 0xFFE    # (t1) ← (t3) & 0xFFE, (PC) ← (PC) + 4
```
</center>

#### ori  
- 指令名：立即数逻辑或  
- 使用语法：`ori rd, rs1, imm`  
- 功能描述：把符号扩展的立即数与寄存器`rs1`的值进行按位或，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
ori t6, t2, 0x001    # (t6) ← (t2) | 0x001, (PC) ← (PC) + 4
```
</center>

#### xori  
- 指令名：立即数逻辑异或  
- 使用语法：`xori rd, rs1, imm`  
- 功能描述：把符号扩展的立即数与寄存器`rs1`的值进行按位异或，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
xori s4, t0, 0x002    # (s4) ← (t0) ^ 0x002, (PC) ← (PC) + 4
```
</center>

#### slli  
- 指令名：立即数逻辑左移  
- 使用语法：`slli rd, rs1, shamt`  
- 功能描述：把寄存器`rs1`左移`shamt`位，低位补0，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
slli a5, t3, 3    # (a5) ← (t3) << 3, (PC) ← (PC) + 4
```
</center>

#### srli  
- 指令名：立即数逻辑右移  
- 使用语法：`srli rd, rs1, shamt`  
- 功能描述：把寄存器`rs1`右移`shamt`位，高位补0，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
srli a1, t2, 1    # (a1) ← (t2) >> 1, (PC) ← (PC) + 4
```
</center>

#### srai  
- 指令名：立即数算术右移  
- 使用语法：`srai rd, rs1, shamt`  
- 功能描述：把寄存器`rs1`右移`shamt`位，高位补`rs1[31]`，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
srai t3, t1, 7    # (t3) ← (t1) >> 7, (PC) ← (PC) + 4
```
</center>

#### slti  
- 指令名: 小于立即数则置位  
- 使用语法：`slti rd, rs1, imm`  
- 功能描述：比较寄存器`rs1`和符号扩展的立即数，比较时视为有符号数。如果`rs1`更小，向寄存器`rd`写入1，否则写入0。  
- 汇编例子：
<center>
``` asm
slti t0, t5, 0    # (t0) ← ((t5) < 0), (PC) ← (PC) + 4
```
</center>

#### sltiu  
- 指令名: 无符号小于立即数则置位  
- 使用语法：`sltiu rd, rs1, imm`  
- 功能描述：比较寄存器`rs1`和符号扩展的立即数，比较时视为无符号数。如果`rs1`更小，向寄存器`rd`写入1，否则写入0。  
- 汇编例子：
<center>
``` asm
sltiu t3, t1, -1024    # (t3) ← ((t1) < 0xC00), (PC) ← (PC) + 4
```
</center>

#### lb  
- 指令名：字节加载  
- 使用语法：`lb rd, offset(rs1)`  
- 功能描述：从字节地址`(rs1)+sext(offset)`处读取一个字节，经符号扩展后写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
lb t0, -3(fp)    # (t0) ← sext(Mem[(fp) - 3][7:0]), (PC) ← (PC) + 4
```
</center>

#### lbu  
- 指令名：无符号字节加载  
- 使用语法：`lbu rd, offset(rs1)`  
- 功能描述：从字节地址`(rs1)+sext(offset)`处读取一个字节，并写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
lbu t0, -3(fp)    # (t0) ← Mem[(fp) - 3][7:0], (PC) ← (PC) + 4
```
</center>

#### lh  
- 指令名：半字加载  
- 使用语法：`lh rd, offset(rs1)`  
- 功能描述：从半字地址`(rs1)+sext(offset)`处读取2个字节，经符号扩展后写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
lh t5, 6(fp)    # (t5) ← sext(Mem[(fp) + 6][15:0]), (PC) ← (PC) + 4
```
</center>

#### lhu  
- 指令名：无符号半字加载  
- 使用语法：`lhu rd, offset(rs1)`  
- 功能描述：从半字地址`(rs1)+sext(offset)`处读取2个字节，并写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
lhu t5, 6(fp)    # (t5) ← Mem[(fp) + 6][15:0], (PC) ← (PC) + 4
```
</center>

#### lw  
- 指令名：字加载  
- 使用语法：`lw rd, offset(rs1)`  
- 功能描述：从字地址`(rs1)+sext(offset)`处读取4个字节，并写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
lw t3, 8(fp)    # (t3) ← Mem[(fp) + 8], (PC) ← (PC) + 4
```
</center>

#### jalr  
- 指令名：跳转并寄存器链接  
- 使用语法：`jalr rd, offset(rs1)`  
- 功能描述：将`PC`设置为`(rs1)+sext(offset)`，把计算出的地址的最低位设为0，并将原`PC+4`的值写入寄存器`rd`。`rd`默认为1。  
- 汇编例子：
<center>
``` asm
jalr ra, -4(t0)    # t ← (PC) + 4, (PC) ← ((t0) - 4) & ~1, (ra) ← t
```
</center>

### 4.3 S型指令
#### sb  
- 指令名：存字节  
- 使用语法：`sb rs2, offset(rs1)`  
- 功能描述：将寄存器`rs2`的最低字节存入内存的字节地址`(rs1)+sext(offset)`处。  
- 汇编例子：
<center>
``` asm
sb t1, 5(fp)    # Mem[(fp) + 3] ← (t1)[7:0], (PC) ← (PC) + 4
```
</center>

#### sh  
- 指令名：存半字  
- 使用语法：`sh rs2, offset(rs1)`  
- 功能描述：将寄存器`rs2`的最低2个字节存入内存的半字地址`(rs1)+sext(offset)`处。  
- 汇编例子：
<center>
``` asm
sh t3, 10(fp)    # Mem[(fp) + 10] ← (t3)[15:0], (PC) ← (PC) + 4
```
</center>

#### sw  
- 指令名：存字  
- 使用语法：`sw rs2, offset(rs1)`  
- 功能描述：将寄存器`rs2`存入内存的字地址`(rs1)+sext(offset)`处。  
- 汇编例子：
<center>
``` asm
sw t5, 4(fp)    # Mem[(fp) + 4] ← (t5), (PC) ← (PC) + 4
```
</center>


### 4.4 B型指令

#### beq  
- 指令名：相等时分支  
- 使用语法：`beq rs1, rs2, offset`  
- 功能描述：若寄存器`rs1`和寄存器`rs2`的值相等，则跳转。跳转的目标地址是当前PC值加上偏移量`offset = sext(offs12 << 1)`。其中，`offs12`是指令码中的12位立即数。  
- 汇编例子：
<center>
``` asm
beq t0, t1, -4    # PC ← ((t0) == (t1)) ? PC - 4 : PC + 4
```
</center>

#### bne  
- 指令名：不相等时分支  
- 使用语法：`bne rs1, rs2, offset`  
- 功能描述：若寄存器`rs1`和寄存器`rs2`的值不相等，则跳转。跳转的目标地址是当前PC值加上偏移量`offset = sext(offs12 << 1)`。其中，`offs12`是指令码中的12位立即数。  
- 汇编例子：
<center>
``` asm
bne t0, t1, 8    # PC ← ((t0) != (t1)) ? PC + 8 : PC + 4
```
</center>

#### blt  
- 指令名：小于时分支  
- 使用语法：`blt rs1, rs2, offset`  
- 功能描述：若寄存器`rs1`的值小于寄存器`rs2`的值 (比较时视为有符号数)，则跳转。跳转的目标地址是当前PC值加上偏移量`offset = sext(offs12 << 1)`。其中，`offs12`是指令码中的12位立即数。  
- 汇编例子：
<center>
``` asm
blt t0, t1, -4    # PC ← ((t0) < (t1)) ? PC - 4 : PC + 4
```
</center>

#### bltu  
- 指令名：无符号小于时分支  
- 使用语法：`bltu rs1, rs2, offset`  
- 功能描述：若寄存器`rs1`的值小于寄存器`rs2`的值 (比较时视为无符号数)，则跳转。跳转的目标地址是当前PC值加上偏移量`offset = sext(offs12 << 1)`。其中，`offs12`是指令码中的12位立即数。  
- 汇编例子：
<center>
``` asm
bltu t0, t1, 8    # PC ← ((t0) < (t1)) ? PC + 8 : PC + 4
```
</center>

#### bge  
- 指令名：大于等于时分支  
- 使用语法：`bge rs1, rs2, offset`  
- 功能描述：若寄存器`rs1`的值大于等于寄存器`rs2`的值 (比较时视为有符号数)，则跳转。跳转的目标地址是当前PC值加上偏移量`offset = sext(offs12 << 1)`。其中，`offs12`是指令码中的12位立即数。  
- 汇编例子：
<center>
``` asm
bge t0, t1, -4    # PC ← ((t0) >= (t1)) ? PC - 4 : PC + 4
```
</center>

#### bgeu  
- 指令名：无符号大于等于时分支  
- 使用语法：`bgeu rs1, rs2, offset`  
- 功能描述：若寄存器`rs1`的值大于等于寄存器`rs2`的值 (比较时视为无符号数)，则跳转。跳转的目标地址是当前PC值加上偏移量`offset = sext(offs12 << 1)`。其中，`offs12`是指令码中的12位立即数。  
- 汇编例子：
<center>
``` asm
bgeu t0, t1, 8    # PC ← ((t0) >= (t1)) ? PC + 8 : PC + 4
```
</center>


### 4.5 U型指令
#### lui  
- 指令名：高位立即数加载  
- 使用语法：`lui rd, imm`  
- 功能描述：将符号扩展的20位立即数逻辑左移12位，结果写入寄存器`rd`。  
- 汇编例子：  
<center>
``` asm
lui t0, 0xABCDE    # (t0) ← 0xABCDE000, (PC) ← (PC) + 4
```
</center>

#### auipc  
- 指令名：PC加立即数  
- 使用语法：`auipc rd, imm`  
- 功能描述：把符号扩展的20位立即数逻辑左移12位，再与`PC`相加，结果写入寄存器`rd`。  
- 汇编例子：  
<center>
``` asm
auipc t3, 0x2468A    # (t3) ← (PC) + 0x2468A000, (PC) ← (PC) + 4
```
</center>


### 4.6 J型指令
#### jal  
- 指令名：跳转并链接  
- 使用语法：`jal rd, offset`  
- 功能描述：将`PC+4`的值写入寄存器`rd`（`rd`默认为1），然后无条件跳转。跳转的目标地址是当前`PC`值加上偏移量`offset = sext(offs20 << 1)`。其中，`offs20`是指令码中的20位立即数。  
- 汇编例子：
<center>
``` asm
jal ra, -4    # (ra) ← (PC) + 4, (PC) ← (PC) - 4
```
</center>
