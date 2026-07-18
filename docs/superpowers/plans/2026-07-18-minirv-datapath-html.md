# miniRV Datapath HTML Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build a standalone interactive HTML datapath diagram for the current miniRV RTL.

**Architecture:** A single static `datapath.html` contains semantic HTML, embedded CSS, an SVG diagram, and small JavaScript data objects for hover details. The diagram is source-backed: component and signal explanations map directly to the modules and wires found in `lab1/miniRV_basic_ego1/miniRV_basic/src/rtl`.

**Tech Stack:** HTML5, CSS3, inline SVG, vanilla JavaScript. No third-party dependencies.

## Global Constraints

- Do not modify RTL, Vivado generated files, Trace scripts, or existing experiment documents.
- The first screen must be the usable datapath diagram, not a marketing or landing page.
- Use Chinese explanations and source names/signals matching the Verilog files.
- The file must work by directly opening `datapath.html` in a browser.

---

### Task 1: Static Interactive Datapath Page

**Files:**
- Create: `datapath.html`

**Interfaces:**
- Consumes: RTL source files under `lab1/miniRV_basic_ego1/miniRV_basic/src/rtl`.
- Produces: A browser-openable HTML file with hoverable `data-info` elements and source-backed explanation sections.

- [ ] **Step 1: Add a minimal standalone HTML skeleton**

Create `datapath.html` with `<!doctype html>`, `<style>`, a root `.app`, an SVG area, a `.detail-panel`, and a `.source-notes` section.

- [ ] **Step 2: Draw source-backed datapath components**

Add SVG nodes for `PC`、`NPC`、`Inst_ROM`、`Controller`、`RF`、`SEXT`、`ALU`、`MREQ`、`MEXT`、`Data_RAM`、`WB MUX` and external CPU interfaces.

- [ ] **Step 3: Draw hoverable signal lines**

Add SVG paths for `pc`、`npc`、`pc4`、`ifetch_req/addr/valid/inst`、`inst[6:0]/funct3/funct7`、`rf_rd1/rf_rd2`、`ext`、`alu_a/alu_b/alu_c/br/busy`、`daccess_*`、`ram_ext`、`rf_wD/rf_we1` and `inst_finished` related control flow.

- [ ] **Step 4: Add hover details**

Implement a JavaScript map keyed by element id. On `mouseenter` and keyboard focus, update the detail panel title, type, source files, signal names, and explanation.

- [ ] **Step 5: Add source implementation notes**

Write concise Chinese sections for IF、ID、EX、MEM、WB、多周期控制, including concrete references to `cpu_core.v` assignments and instantiated modules.

- [ ] **Step 6: Verify static content**

Run:

```bash
rg -n "PC|NPC|Controller|RF|SEXT|ALU|MREQ|MEXT|Inst_ROM|Data_RAM|ifetch_req|daccess_|inst_finished|mul_div_flag|ld_st_flag" datapath.html
```

Expected: each key module and signal appears at least once.

- [ ] **Step 7: Commit**

Commit only the new spec, plan, and `datapath.html` if the repository state allows a narrow commit:

```bash
git add docs/superpowers/specs/2026-07-18-minirv-datapath-html-design.md docs/superpowers/plans/2026-07-18-minirv-datapath-html.md datapath.html
git commit -m "docs: add interactive minirv datapath diagram"
```
