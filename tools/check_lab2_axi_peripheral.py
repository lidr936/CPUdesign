from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
RTL = ROOT / "lab2" / "miniRV_pipeline_axi" / "src" / "rtl"


def require(text: str, needle: str, label: str) -> None:
    if needle not in text:
        raise AssertionError(f"missing {label}: {needle}")


def main() -> None:
    top = (RTL / "miniRV_SoC.v").read_text(encoding="utf-8")
    subsystem = (RTL / "axi_peripheral_subsystem.v").read_text(encoding="utf-8")
    wrapper = (RTL / "axi4lite_peripheral_wrap.v").read_text(encoding="utf-8")
    project = (RTL.parents[1] / "miniRV.xpr").read_text(encoding="utf-8")

    for base in (
        "0x0000000000000000",
        "0x00000000FFFF0000",
        "0x00000000FFFF1000",
        "0x00000000FFFF2000",
        "0x00000000FFFF3000",
        "0x00000000FFFF4000",
    ):
        require((RTL / "ip" / "axi_crossbar_0" / "axi_crossbar_0.xci").read_text(encoding="utf-8"), base, "Crossbar address")

    for name in ("axi_crossbar_0", "bram_axi", "Switch", "LED", "Dig", "Timer", "axi_uartlite_0"):
        require(subsystem if name in ("axi_crossbar_0", "bram_axi") else wrapper, name, "IP instance")
    for name in tuple(f"axi_protocol_converter_{index}" for index in range(5)):
        require(wrapper, name, "protocol converter mapping")

    require(top, "`ifdef RUN_TRACE", "Trace branch")
    require(top, "assign tx       = 1'b1;", "Trace UART idle drive")
    require(top, "axi_peripheral_subsystem U_peripheral_subsystem", "hardware subsystem")
    require(top, "wire sys_clk = pll_clk1;", "ungated PLL system clock")
    require(top, "reset_sync", "synchronous system reset")
    if "assign axi_arready = 1'b0;" in top:
        raise AssertionError("hardware AXI zero-response stub remains")
    if "pll_lock & pll_clk1" in top:
        raise AssertionError("PLL lock must not gate the system clock")
    for source in ("axi4lite_peripheral_wrap.v", "axi_peripheral_subsystem.v"):
        require(project, source, "Vivado design source")
    for index in range(1, 5):
        disabled = (
            f'axi_protocol_converter_{index}/axi_protocol_converter_{index}.xci">\n'
            '        <FileInfo>\n'
            '          <Attr Name="AutoDisabled" Val="1"/>'
        )
        if disabled in project:
            raise AssertionError(f"axi_protocol_converter_{index} is disabled in miniRV.xpr")
    if '`include "axi4lite_peripheral_wrap.v"' in top:
        raise AssertionError("peripheral wrapper must be a design source, not included by top")
    for signal in ("timer[31:0]", "timer[63:32]", "dig_en", "dig_seg", "dig_seg1"):
        require(subsystem, signal, "peripheral wiring")

    print("PASS: Cache-off AXI peripheral static contract")


if __name__ == "__main__":
    main()
