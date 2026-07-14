from pathlib import Path
import re
import sys


ROOT = Path(__file__).resolve().parents[1]
RTL = ROOT / "lab1" / "miniRV_basic_ego1" / "miniRV_basic" / "src" / "rtl"


def read(name: str) -> str:
    path = RTL / name
    if not path.exists():
        raise AssertionError(f"missing RTL file: {path}")
    return path.read_text(encoding="utf-8", errors="ignore")


def strip_comments(text: str) -> str:
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    text = re.sub(r"//.*", "", text)
    return text


def require(text: str, needle: str, label: str) -> None:
    if needle not in text:
        raise AssertionError(f"missing {label}: {needle}")


def require_regex(text: str, pattern: str, label: str) -> None:
    if not re.search(pattern, text, flags=re.S):
        raise AssertionError(f"missing {label}: /{pattern}/")


def module_ports(text: str, module_name: str) -> set[str]:
    text = strip_comments(text)
    m = re.search(rf"\bmodule\s+{module_name}\b", text)
    if not m:
        raise AssertionError(f"module not found: {module_name}")
    start = text.find("(", m.end())
    if start < 0:
        raise AssertionError(f"module header not found: {module_name}")
    depth = 0
    end = None
    for idx in range(start, len(text)):
        ch = text[idx]
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
            if depth == 0:
                semi = text.find(";", idx)
                if semi >= 0:
                    end = semi
                break
    if end is None:
        raise AssertionError(f"module header end not found: {module_name}")
    header = text[start:end]
    return set(re.findall(r"\b(?:input|output|inout)\s+(?:wire|reg\s+|reg|wire\s+)?(?:\[[^\]]+\]\s*)?([A-Za-z_]\w*)", header))


def instance_ports(text: str, module_name: str, instance_name: str) -> set[str]:
    text = strip_comments(text)
    m = re.search(rf"\b{module_name}\b\s*(?:#\s*\(.*?\)\s*)?\b{instance_name}\b\s*\(", text, flags=re.S)
    if not m:
        raise AssertionError(f"instance not found: {module_name} {instance_name}")
    start = text.rfind("(", 0, m.end())
    depth = 0
    end = None
    for idx in range(start, len(text)):
        ch = text[idx]
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
            if depth == 0:
                end = idx
                break
    if end is None:
        raise AssertionError(f"instance end not found: {module_name} {instance_name}")
    body = text[start:end]
    return set(re.findall(r"\.([A-Za-z_]\w*)\s*\(", body))


def check_defines() -> None:
    text = read("defines.vh")
    required = [
        "ALU_SUB", "ALU_AND", "ALU_XOR", "ALU_SRL", "ALU_SRA",
        "ALU_LT", "ALU_GE", "ALU_LTU", "ALU_GEU", "ALU_SLT", "ALU_SLTU",
        "ALU_MUL", "ALU_MULH", "ALU_MULHU", "ALU_DIV", "ALU_DIVU",
        "ALU_REM", "ALU_REMU", "NPC_JALR", "EXT_S",
    ]
    for macro in required:
        require(text, f"`define {macro}", f"macro {macro}")


def check_macro_includes() -> None:
    macro_users = [
        "ALU.v",
        "Controller.v",
        "MREQ.v",
        "MEXT.v",
        "NPC.v",
        "SEXT.v",
        "cpu_core.v",
    ]
    for name in macro_users:
        text = read(name)
        require(text, '`include "defines.vh"', f"{name} includes defines.vh")


def check_controller() -> None:
    text = read("Controller.v")
    for inst in [
        "ADD", "SUB", "AND", "XOR", "SLL", "SRL", "SRA", "SLT", "SLTU",
        "XORI", "ANDI", "SRLI", "SRAI", "SLTI", "SLTIU",
        "LB", "LBU", "LH", "LHU", "SB", "SH", "SW",
        "BLT", "BGE", "BLTU", "BGEU", "AUIPC", "JALR",
        "MUL", "MULH", "MULHU", "DIV", "DIVU", "REM", "REMU",
    ]:
        require_regex(text, rf"\bwire\s+{inst}\b", f"decode wire {inst}")
    for signal in ["RAM_EXT_B", "RAM_EXT_BU", "RAM_EXT_H", "RAM_EXT_HU", "RAM_W_B", "RAM_W_H", "RAM_W_W"]:
        match = re.search(rf"\bwire\s+{signal}\b\s*=\s*(.*?);", text)
        if not match:
            raise AssertionError(f"missing control wire {signal}")
        if match.group(1).strip() == "1'b0":
            raise AssertionError(f"{signal} is still stubbed to 1'b0")
    require_regex(text, r"\bwire\s+ALU_OP_OR\b\s*=.*\bOR\b.*\bORI\b", "R-type OR maps to ALU_OR")


def check_core_wiring() -> None:
    text = read("cpu_core.v")
    require(text, ".ram_wdata  (rf_rd2)", "store write data from rs2")
    require(text, ".base", "NPC jalr base port")
    require(text, "pc_r", "multi-cycle PC cache")
    require(text, "assign inst = ifetch_valid ? ifetch_inst : 32'h13", "NOP held when no fetched instruction is valid")
    require(text, "assign debug_wb_pc    = ld_st_flag | mul_div_flag ? pc_r : pc", "debug_wb_pc uses cached multi-cycle PC")
    require_regex(text, r"assign\s+rf_we1\s*=.*mul_div_flag\s*&\s*!mul_div_busy", "mul/div writes back only after busy deasserts")
    require_regex(text, r"assign\s+inst_finished\s*=.*mul_div_flag\s*&\s*!mul_div_busy", "mul/div instruction finishes only after busy deasserts")


def check_memory() -> None:
    mreq = read("MREQ.v")
    mext = read("MEXT.v")
    for pattern, label in [
        (r"RAM_WE_B.*offset", "byte store offset handling"),
        (r"RAM_WE_H.*offset", "half store offset handling"),
        (r"RAM_EXT_B", "lb request handling"),
        (r"RAM_EXT_H", "lh request handling"),
    ]:
        require_regex(mreq, pattern, label)
    for pattern, label in [
        (r"RAM_EXT_B\s*:\s*ext\s*=\s*\{\{24\{real_din\[7\]\}\}", "lb sign extension"),
        (r"RAM_EXT_BU\s*:\s*ext\s*=\s*\{24'h0,\s*real_din\[7:0\]\}", "lbu zero extension"),
        (r"RAM_EXT_H\s*:\s*ext\s*=\s*\{\{16\{real_din\[15\]\}\}", "lh sign extension"),
        (r"RAM_EXT_HU\s*:\s*ext\s*=\s*\{16'h0,\s*real_din\[15:0\]\}", "lhu zero extension"),
    ]:
        require_regex(mext, pattern, label)


def check_alu_mul_div() -> None:
    alu = read("ALU.v")
    for op in ["ALU_SUB", "ALU_AND", "ALU_XOR", "ALU_SRL", "ALU_SRA", "ALU_SLTU", "ALU_MUL", "ALU_DIV", "ALU_REMU"]:
        require(alu, f"`{op}", f"ALU handles {op}")
    require(alu, "assign busy      = mul_busy | mulu_busy | div_busy | divu_busy", "combined mul/div busy")
    require(alu, "wire [ 4:0] op_eff = (op_r != `ALU_NOP) ? op_r : op", "ALU result selected by latched multi-cycle op")
    require(alu, "div_zero_r ? 32'hffff_ffff", "division by zero quotient semantics")
    require(alu, "div_overflow_r ? 32'h8000_0000", "signed division overflow quotient semantics")
    require(alu, "div_overflow_r ? 32'h0", "signed remainder overflow semantics")
    multiplier = read("multiplier.v")
    require(multiplier, "x_ext_r", "multiplier latches multiplicand")
    require(multiplier, "start & !busy_r", "multiplier ignores start while busy")
    divider = read("divider.v")
    require(divider, "start & !busy", "divider ignores start while busy")


def check_no_forbidden_mul_div() -> None:
    for name in ["multiplier.v", "divider.v"]:
        text = strip_comments(read(name))
        bad = []
        for i, line in enumerate(text.splitlines(), 1):
            if line.strip().startswith("`timescale"):
                continue
            if re.search(r"\blocalparam\b|\bparameter\b", line):
                continue
            if "@(*)" in line:
                continue
            cleaned = re.sub(r"\(\s*[*#]\s*\d+\s*\)", "", line)
            if "*" in cleaned or "/" in cleaned:
                bad.append(f"{name}:{i}:{line.strip()}")
        if bad:
            raise AssertionError("forbidden operator in arithmetic unit:\n" + "\n".join(bad))


def check_instance_ports() -> None:
    files = {name: read(name) for name in [
        "cpu_core.v", "Controller.v", "RF.v", "SEXT.v", "NPC.v", "PC.v",
        "ALU.v", "MREQ.v", "MEXT.v", "multiplier.v", "divider.v",
    ]}
    instances = [
        ("cpu_core.v", "NPC", "U_NPC", "NPC.v"),
        ("cpu_core.v", "PC", "U_PC", "PC.v"),
        ("cpu_core.v", "Controller", "U_CU", "Controller.v"),
        ("cpu_core.v", "RF", "U_RF", "RF.v"),
        ("cpu_core.v", "SEXT", "U_SEXT", "SEXT.v"),
        ("cpu_core.v", "ALU", "U_ALU", "ALU.v"),
        ("cpu_core.v", "MREQ", "U_MEM_REQ", "MREQ.v"),
        ("cpu_core.v", "MEXT", "U_MEM_EXT", "MEXT.v"),
        ("ALU.v", "multiplier", "U_mul", "multiplier.v"),
        ("ALU.v", "multiplier", "U_mulu", "multiplier.v"),
        ("ALU.v", "divider", "U_div", "divider.v"),
        ("ALU.v", "divider", "U_divu", "divider.v"),
    ]
    for owner, module, instance, module_file in instances:
        defined = module_ports(files[module_file], module)
        connected = instance_ports(files[owner], module, instance)
        unknown = connected - defined
        missing = defined - connected
        if unknown:
            raise AssertionError(f"{owner}:{instance} connects unknown ports {sorted(unknown)}")
        if missing:
            raise AssertionError(f"{owner}:{instance} missing ports {sorted(missing)}")


def main() -> int:
    checks = [
        check_defines,
        check_macro_includes,
        check_controller,
        check_core_wiring,
        check_memory,
        check_alu_mul_div,
        check_no_forbidden_mul_div,
        check_instance_ports,
    ]
    failures = []
    for check in checks:
        try:
            check()
        except AssertionError as exc:
            failures.append(f"{check.__name__}: {exc}")
    if failures:
        print("STATIC CHECK FAILED")
        for failure in failures:
            print(f"- {failure}")
        return 1
    print("STATIC CHECK PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
