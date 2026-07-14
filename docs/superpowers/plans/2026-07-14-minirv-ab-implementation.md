# miniRV A/B 指令实现 Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** 在 `lab1/miniRV_basic_ego1/miniRV_basic` 模板工程中实现 A/B 组 36 条 miniRV 指令，并保持 8 条模板指令回归路径。

**Architecture:** 沿用模板的 `miniRV_SoC -> cpu_top -> cpu_core` 层级与 `ld_st_flag/mul_div_flag/inst_finished` 多周期提交机制。扩展既有 `Controller/ALU/SEXT/NPC/MREQ/MEXT/cpu_core`，乘除器继续由 `ALU.v` 内部实例化，`cpu_core` 只等待 `busy`。

**Tech Stack:** Verilog HDL, Vivado template RTL, PowerShell/Python static and algorithm validation. Current machine has no `iverilog` or `verilator`; Vivado GUI simulation/synthesis is user-side verification.

## Global Constraints

- Do not modify `RUN_TRACE`, `/* verilator public */`, debug signal names, or the external module hierarchy expected by Trace.
- Do not use Verilog `*` or `/` operators, or IP cores, for `multiplier.v` and `divider.v`.
- Keep `Data_RAM` byte-address interface semantics: CPU emits byte address, `Data_RAM` uses `data_addr[31:2]` internally.
- For unaligned half/word load/store, follow the guidebook: do not issue memory request; do not add CSR/trap behavior in this phase.
- Use `apply_patch` for file edits.

---

### Task 1: Static Validation Harness

**Files:**
- Create: `tools/check_minirv_static.py`
- Create: `tools/verify_minirv_algorithms.py`

**Interfaces:**
- Consumes: RTL files under `lab1/miniRV_basic_ego1/miniRV_basic/src/rtl`
- Produces: command `python tools/check_minirv_static.py` with nonzero exit on missing required implementation markers or forbidden operators.

- [x] **Step 1: Write failing static checks**

Create checks for:
- all required macro names in `defines.vh`
- controller decode names for all A/B target instructions
- no `*` or `/` operators in `multiplier.v` and `divider.v`
- `NPC_JALR`, `EXT_S`, byte/half MREQ/MEXT logic markers
- `cpu_core` store data uses `rf_rd2`, not `32'h0`

- [x] **Step 2: Run check to verify it fails**

Run: `python tools/check_minirv_static.py`

Expected now: FAIL, because macros/decoder/logic are incomplete in template.

### Task 2: Control Encoding and Decode

**Files:**
- Modify: `src/rtl/defines.vh`
- Modify: `src/rtl/Controller.v`

**Interfaces:**
- Produces new `ALU_*`, `NPC_JALR`, `EXT_S`, `ram_r_op`, `ram_w_op`, `is_mul`, `is_div` mappings.

- [x] **Step 1: Extend macros**
- [x] **Step 2: Decode R/I/Load/Store/Branch/U/J/M instructions**
- [x] **Step 3: Run static check**

### Task 3: Immediate, NPC, and Core Wiring

**Files:**
- Modify: `src/rtl/SEXT.v`
- Modify: `src/rtl/NPC.v`
- Modify: `src/rtl/cpu_core.v`

**Interfaces:**
- `SEXT` supports `EXT_S`
- `NPC` accepts `base` for `jalr`
- `cpu_core` passes `rf_rd1` to NPC and `rf_rd2` to MREQ

- [x] **Step 1: Add S immediate**
- [x] **Step 2: Add JALR target calculation**
- [x] **Step 3: Connect store write data and jalr base**
- [x] **Step 4: Run static check**

### Task 4: Memory Request and Extension

**Files:**
- Modify: `src/rtl/MREQ.v`
- Modify: `src/rtl/MEXT.v`

**Interfaces:**
- `MREQ` emits aligned `da_wen/da_wdata` for `sb/sh/sw`
- `MREQ` emits `da_ren=4'hF` only for aligned legal load
- `MEXT` extracts and sign/zero extends byte/half/word data

- [x] **Step 1: Implement store mask and shifted write data**
- [x] **Step 2: Implement load alignment request generation**
- [x] **Step 3: Implement MEXT byte/half extraction**
- [x] **Step 4: Run static check**

### Task 5: ALU Operations and Mul/Div Integration

**Files:**
- Modify: `src/rtl/ALU.v`
- Modify: `src/rtl/multiplier.v`
- Modify: `src/rtl/divider.v`

**Interfaces:**
- `ALU` implements all pure ops and branches
- `multiplier`/`divider` implement start/busy/result protocol
- no `*` or `/` operators in multiplier/divider

- [x] **Step 1: Implement pure ALU ops**
- [x] **Step 2: Implement sequential Booth signed/unsigned multiplication without `*`**
- [x] **Step 3: Implement sequential restoring division without `/`**
- [x] **Step 4: Wire ALU result selection and busy**
- [x] **Step 5: Run static check**
- [x] **Step 6: Run algorithm boundary check**

### Task 6: Documentation and Verification Handoff

**Files:**
- Modify: `lab1/A_B组模块化Verilog实现落地方案.md`
- Modify: `findings.md`
- Modify: `progress.md`

**Interfaces:**
- Documentation records implemented status, static check result, and Vivado/Trace user-side verification steps.

- [x] **Step 1: Update status in landing document**
- [x] **Step 2: Run final static check**
- [x] **Step 3: Record verification limitations**
