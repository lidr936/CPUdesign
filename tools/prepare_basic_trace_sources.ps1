param(
    [string]$TraceRoot = "cdp-tests"
)

$ErrorActionPreference = "Stop"

$workspace = Split-Path -Parent $PSScriptRoot
$rtlSrc = Join-Path $workspace "lab1\miniRV_basic_ego1\miniRV_basic\src\rtl"

if (-not [System.IO.Path]::IsPathRooted($TraceRoot)) {
    $TraceRoot = Join-Path $workspace $TraceRoot
}

$mySoc = Join-Path $TraceRoot "mySoC"

if (-not (Test-Path -LiteralPath $TraceRoot)) {
    throw "Trace root not found: $TraceRoot"
}

if (-not (Test-Path -LiteralPath $mySoc)) {
    throw "Trace mySoC directory not found: $mySoc"
}

if (-not (Test-Path -LiteralPath $rtlSrc)) {
    throw "RTL source directory not found: $rtlSrc"
}

$rtlFiles = Get-ChildItem -LiteralPath $rtlSrc -File |
    Where-Object { $_.Extension -in @(".v", ".vh") } |
    Sort-Object Name

foreach ($file in $rtlFiles) {
    Copy-Item -LiteralPath $file.FullName -Destination (Join-Path $mySoc $file.Name) -Force
}

Write-Host "Copied RTL files to Basic Trace mySoC:"
Write-Host $mySoc
Write-Host ""
Write-Host "Files:"
$rtlFiles | ForEach-Object {
    Write-Host ("  " + $_.Name)
}
Write-Host ""
Write-Host "Excluded by design:"
Write-Host "  src/rtl/ip"
Write-Host "  Vivado generated files"
