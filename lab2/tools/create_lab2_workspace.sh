#!/usr/bin/env bash
set -euo pipefail

LAB2_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd -P)
REPO_DIR=$(cd "$LAB2_DIR/.." && pwd -P)
BASELINE_DIR="$REPO_DIR/lab1/miniRV_basic_ego1/miniRV_basic"
CACHE_ARCHIVE="$LAB2_DIR/实验3_2026-06-07T15_26_00Z.zip"

PROJECTS=(
    "pipeline_cpu/miniRV_pipeline"
    "axi_soc/miniRV_axi"
    "integrated_soc/miniRV_pipeline_axi"
)

verify_workspace() {
    local project
    for project in "${PROJECTS[@]}"; do
        test -f "$LAB2_DIR/$project/src/rtl/cpu_core.v"
        test -f "$LAB2_DIR/$project/src/rtl/defines.vh"
        test -f "$LAB2_DIR/$project/src/coe/lw.coe"
    done
    test -f "$LAB2_DIR/assets/cache_reference/ICache.v"
    test -f "$LAB2_DIR/assets/cache_reference/DCache.v"
}

if [[ "${1:-}" == "--verify" ]]; then
    verify_workspace
    printf 'Lab2 workspace verified.\n'
    exit 0
fi

test -d "$BASELINE_DIR"
test -f "$CACHE_ARCHIVE"

for project in "${PROJECTS[@]}"; do
    target="$LAB2_DIR/$project"
    if [[ -d "$target" ]] && [[ -n "$(find "$target" -mindepth 1 -print -quit)" ]]; then
        printf 'Refusing to overwrite non-empty project: %s\n' "$target" >&2
        exit 1
    fi

    mkdir -p "$target/src/rtl" "$target/src/coe" "$target/src/sim" "$target/src/xdc"
    cp "$BASELINE_DIR"/src/rtl/*.v "$target/src/rtl/"
    cp "$BASELINE_DIR"/src/rtl/*.vh "$target/src/rtl/"
    cp "$BASELINE_DIR"/src/coe/* "$target/src/coe/"
    cp "$BASELINE_DIR"/src/sim/* "$target/src/sim/"
    cp "$BASELINE_DIR"/src/xdc/* "$target/src/xdc/"
    printf '%s\n' "$BASELINE_DIR" > "$target/BASELINE_SOURCE.txt"
done

mkdir -p "$LAB2_DIR/assets/cache_reference" "$LAB2_DIR/notes"
unzip -p "$CACHE_ARCHIVE" '计组实验3/ICache.v' > "$LAB2_DIR/assets/cache_reference/ICache.v"
unzip -p "$CACHE_ARCHIVE" '计组实验3/DCache.v' > "$LAB2_DIR/assets/cache_reference/DCache.v"

verify_workspace
printf 'Lab2 workspace created under %s.\n' "$LAB2_DIR"
