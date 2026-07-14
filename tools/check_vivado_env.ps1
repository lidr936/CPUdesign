$ErrorActionPreference = "Continue"

$root = Split-Path -Parent $PSScriptRoot
$project = Join-Path $root "lab1\miniRV_basic_ego1\miniRV_basic\miniRV.xpr"
$tcl = Join-Path $root "tools\vivado_lab1_check.tcl"

Write-Host "Workspace: $root"
Write-Host "Project : $project"
Write-Host "Tcl     : $tcl"
Write-Host ""

foreach ($cmd in @("vivado", "xvlog", "iverilog", "verilator")) {
    $found = Get-Command $cmd -ErrorAction SilentlyContinue
    if ($found) {
        Write-Host ("{0,-8}: FOUND  {1}" -f $cmd, $found.Source)
    } else {
        Write-Host ("{0,-8}: MISSING" -f $cmd)
    }
}

Write-Host ""
if (Test-Path -LiteralPath $project) {
    Write-Host "miniRV.xpr: FOUND"
} else {
    Write-Host "miniRV.xpr: MISSING"
}

if (Test-Path -LiteralPath $tcl) {
    Write-Host "Vivado Tcl: FOUND"
} else {
    Write-Host "Vivado Tcl: MISSING"
}

Write-Host ""
Write-Host "If Vivado is installed, open Vivado Tcl Console and run:"
Write-Host "  cd $root"
Write-Host "  source tools/vivado_lab1_check.tcl"
