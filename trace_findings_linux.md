# Linux Basic Trace 测试现象记录

日期：2026-07-14

## 环境

- 平台：Ubuntu 26.04
- 编译器：g++ 15.2.0
- 构建工具：GNU Make 4.4.1
- 仿真器：Verilator 5.032
- 测试框架：cdp-tests (gitee.com/hitsz-cslab/cdp-tests.git, miniRV)

## 总体结果

首次批量测试：43/45 通过，2 个失败。

## 失败项

### 1. sb (store byte)

#### 第一处错误（Memory-Write Failed）

对比差异：
```
SIGNAL NAME       REFERENCE     MYCPU
debug_mem_pc      0x00000010    0x00000010
debug_mem_we                1             1
debug_mem_waddr    0x00002000    0x00002000
debug_mem_wdata    0xffffffaa    0x000000aa
```

现象：
- PC、写使能、写地址一致
- 写数据不一致：参考模型输出 0xffffffaa（原始寄存器值的全部 32 位），MyCPU 输出 0x000000aa（只取低字节并零扩展到 32 位）
- 该测试用例：sb 向地址 0x2000 写入偏移 0 字节，寄存器值为 -86 (0xFFFFFFAA)

MREQ.v 中 RAM_WE_B 的原始实现将 da_wdata 设为 {24'h0, ram_wdata[7:0]}，丢失了高位数据。

#### 尝试过的修复路径及对应现象

**尝试 1**：将 da_wdata 改为 {24{ram_wdata[7]}, ram_wdata[7:0]}（符号扩展字节值），并移位到 offset 对应位置

- Verilator 编译报错：`syntax error, unexpected ',', expecting '}'`，不支持 `{24{bit_expression}}` 这种复制语法嵌套在拼接中

**尝试 2**：改用三元运算符 `ram_wdata[7] ? 24'hffffff : 24'h0` 做符号扩展，并移位

- Memory-Write 对比通过
- 但出现新的 Register-Write 错误（第二个测试点 test_4：sb offset=2 后执行 lh 读回）
  ```
  debug_wb_pc     0x00000058    0x00000058
  debug_wb_rf_we            1             1
  debug_wb_rf_wR           14            14
  debug_wb_rf_wD   0xffffefa0    0xffffefff
  ```
  参考模型读回 0xFFFFEFA0，MyCPU 读回 0xFFFFEFFF

**尝试 3**：不做符号扩展，直接将 da_wdata 设为 ram_wdata（原始寄存器值），只设置 da_wen

- Memory-Write 对比失败，出现在偏移非零的测试点（test_10）
  ```
  debug_mem_waddr  0x00002008    0x00002008
  debug_mem_wdata  0x12345678    0x00000078
  ```
  参考模型写 0x12345678（原始寄存器值），MyCPU 未做移位致 DRAM 写入了错误字节

**尝试 4**：将 debug_mem_wdata 从 daccess_wdata 改为 rf_rd2，同时 MREQ 恢复原始零扩展移位
- Memory-Write 对比失败
  ```
  debug_mem_wdata  0xffffffaa    0x00000000
  ```
  rf_rd2 在写使能采样时刻为 0

#### 已确认的事实

- 参考模型（golden_model/MEM.c）中：
  - `mem_wdata`（用于 Trace 对比）设为 `ex_info.store_val`，即原始完整寄存器值
  - 实际写入内存时使用 `(value & 0xFF) << bit_off`，即将低字节移位到目标位置
- DRAM 模块（vsrc/ram.v）的字节写入方式：`wea[0]` 写 `dina[7:0]`，`wea[1]` 写 `dina[15:8]`，以此类推
- 因此 daccess_wdata 同时承担两个角色（Trace 对比 + DRAM 写入数据），两者在非零偏移时需求矛盾

### 2. start (综合测试)

错误信息：
```
Memory access out of bound
VminiRV_SoC: ../golden_model/stage/MEM.c:62: void mem_store(uint32_t, AccessMode, uint32_t): Assertion `addr < (1 << 16)' failed.
```

现象：
- 参考模型执行到某条访存指令时断言失败
- 断言条件为内存地址必须小于 64KB（1<<16 = 0x10000）
- 表明 MyCPU 产生的访存地址超出了测试框架内存范围

## 已通过的 43 项测试

lui, lw, mul, mulh, mulhu, or, ori, rem, remu, sh, sll, slli, slt, slti, sltiu, sltu, sra, srai, srl, srli, sub, sw, xor, xori, add, addi, and, andi, auipc, beq, bge, bgeu, blt, bltu, bne, div, divu, jal, jalr, lb, lbu, lh, lhu

## 核对点

1. sw 测试通过 —— 说明 RAM_WE_W（偏移=0，da_wdata=ram_wdata）逻辑正确
2. sh 测试通过 —— 说明 RAM_WE_H（偏移 00/10，da_wdata 移位半字）逻辑正确
3. sb 测试失败 —— 是唯一需要同时满足"Trace 对比用完整寄存器值"和"DRAM 写入用移位字节值"的冲突场景
4. lb/lbu/lh/lhu 全部通过 —— 说明 MREQ 读使能、MEXT 字节选取和符号/零扩展正确
