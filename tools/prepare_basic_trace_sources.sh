#!/usr/bin/env bash
set -euo pipefail

trace_root="${1:-cdp-tests}"

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
workspace="$(cd -- "${script_dir}/.." && pwd)"
rtl_src="${workspace}/lab1/miniRV_basic_ego1/miniRV_basic/src/rtl"

if [[ "${trace_root}" != /* ]]; then
    trace_root="${workspace}/${trace_root}"
fi

my_soc="${trace_root}/mySoC"

if [[ ! -d "${trace_root}" ]]; then
    echo "Trace root not found: ${trace_root}" >&2
    exit 1
fi

if [[ ! -d "${my_soc}" ]]; then
    echo "Trace mySoC directory not found: ${my_soc}" >&2
    exit 1
fi

if [[ ! -d "${rtl_src}" ]]; then
    echo "RTL source directory not found: ${rtl_src}" >&2
    exit 1
fi

find "${rtl_src}" -maxdepth 1 -type f \( -name '*.v' -o -name '*.vh' \) -print0 |
    sort -z |
    while IFS= read -r -d '' file; do
        cp -f -- "${file}" "${my_soc}/"
    done

echo "Copied RTL files to Basic Trace mySoC:"
echo "${my_soc}"
echo
echo "Files:"
find "${rtl_src}" -maxdepth 1 -type f \( -name '*.v' -o -name '*.vh' \) -printf '  %f\n' | sort
echo
echo "Excluded by design:"
echo "  src/rtl/ip"
echo "  Vivado generated files"
