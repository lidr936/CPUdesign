param(
    [string]$OutDir = ""
)

$ErrorActionPreference = "Stop"

$workspace = Split-Path -Parent $PSScriptRoot
$projectRoot = Join-Path $workspace "lab1\miniRV_basic_ego1\miniRV_basic"
$srcRoot = Join-Path $projectRoot "src"
$rtlSrc = Join-Path $srcRoot "rtl"
$coeSrc = Join-Path $srcRoot "coe"

if (-not (Test-Path -LiteralPath $rtlSrc)) {
    throw "RTL source directory not found: $rtlSrc"
}

if ([string]::IsNullOrWhiteSpace($OutDir)) {
    $stamp = Get-Date -Format "yyyyMMdd_HHmmss"
    $OutDir = Join-Path $workspace "dist\single_cycle_$stamp"
} elseif (-not [System.IO.Path]::IsPathRooted($OutDir)) {
    $OutDir = Join-Path $workspace $OutDir
}

$rtlOut = Join-Path $OutDir "rtl"
$coeOut = Join-Path $OutDir "coe"
New-Item -ItemType Directory -Force -Path $rtlOut | Out-Null
New-Item -ItemType Directory -Force -Path $coeOut | Out-Null

$rtlFiles = Get-ChildItem -LiteralPath $rtlSrc -File |
    Where-Object { $_.Extension -in @(".v", ".vh") } |
    Sort-Object Name

foreach ($file in $rtlFiles) {
    Copy-Item -LiteralPath $file.FullName -Destination (Join-Path $rtlOut $file.Name) -Force
}

$coeFiles = @()
if (Test-Path -LiteralPath $coeSrc) {
    $coeFiles = Get-ChildItem -LiteralPath $coeSrc -File |
        Where-Object { $_.Extension -in @(".asm", ".coe") } |
        Sort-Object Name

    foreach ($file in $coeFiles) {
        Copy-Item -LiteralPath $file.FullName -Destination (Join-Path $coeOut $file.Name) -Force
    }
}

$manifest = @()
$manifest += "miniRV single_cycle source package"
$manifest += "Generated: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
$manifest += "Source project: $projectRoot"
$manifest += ""
$manifest += "RTL files:"
$manifest += ($rtlFiles | ForEach-Object { "  rtl/$($_.Name)" })
$manifest += ""
$manifest += "COE/ASM files:"
if ($coeFiles.Count -gt 0) {
    $manifest += ($coeFiles | ForEach-Object { "  coe/$($_.Name)" })
} else {
    $manifest += "  (none)"
}
$manifest += ""
$manifest += "Excluded by design:"
$manifest += "  src/rtl/ip"
$manifest += "  Vivado generated directories such as .cache/.runs/.sim/.hw/ip_user_files"

$manifestPath = Join-Path $OutDir "manifest.txt"
$manifest | Set-Content -LiteralPath $manifestPath -Encoding UTF8

Write-Host "Single-cycle source package prepared:"
Write-Host $OutDir
Write-Host ""
Write-Host "Files:"
Get-ChildItem -LiteralPath $OutDir -Recurse -File |
    Sort-Object FullName |
    ForEach-Object {
        $relative = $_.FullName.Substring($OutDir.Length + 1)
        Write-Host ("  " + $relative)
    }
