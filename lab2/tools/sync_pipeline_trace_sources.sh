#!/usr/bin/env bash
set -euo pipefail

LAB2_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd -P)
SOURCE_DIR="$LAB2_DIR/pipeline_cpu/miniRV_pipeline/src/rtl"
TRACE_ROOT=${1:-"$LAB2_DIR/../cdp-tests"}
TARGET_DIR="$TRACE_ROOT/mySoC"

test -d "$SOURCE_DIR"
test -d "$TARGET_DIR"

for source in "$SOURCE_DIR"/*.v "$SOURCE_DIR"/*.vh; do
    test -f "$source"
    install -m 0644 "$source" "$TARGET_DIR/$(basename "$source")"
done

printf 'Synchronized pipeline RTL to %s.\n' "$TARGET_DIR"
