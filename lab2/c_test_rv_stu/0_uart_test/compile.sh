#!/bin/sh

# main=$1
main=$(grep -l "main[[:space:]]*(" *.c 2>/dev/null)
base=$(basename "$main" .c)

cat > startup.h << 'EOF'
#ifndef STARTUP_H
#define STARTUP_H

__attribute__((naked)) void _start() {
    asm volatile (
        "lui sp, %hi(_stack_top)\n"  // 设置堆栈指针到 RAM 顶部
        "addi sp, sp, %lo(_stack_top)\n"
        "call main\n"
        "1: j 1b\n"  // 无限循环
    );
}

#ifndef C_TEST
#include <stddef.h>
extern char _heap_start;
extern char _stack_top[];
void* _sbrk(ptrdiff_t incr)
{
    static char* heap_end = &_heap_start;
    char* prev_heap_end = heap_end;
    char* stack_pointer;

    // 检查堆栈是否碰撞
    asm volatile ("mv %0, sp" : "=r"(stack_pointer));
    if (heap_end + incr > stack_pointer) return (void*)-1;

    heap_end += incr;
    return (void*)prev_heap_end;
}
#endif
#endif
EOF

echo '#include "startup.h"' > temp_main.c
cat "$main" >> temp_main.c

cat << EOF > link.ld
MEMORY
{
    rom  : ORIGIN = 0x00000000, LENGTH = 50K   /* IROM: .text */
    ram1 : ORIGIN = 0x0000C800, LENGTH = 50K   /* DRAM: .data, .rodata, etc. */
    ram2 : ORIGIN = 0x00019000, LENGTH = 50K   /* DRAM: HEAP and STACK */
}

SECTIONS
{
    /* 代码段：放置在 ROM 开头 */
    .text : {
        *(.text)
        *(.text.*)
        _etext = .;     /* 代码段结束标记，用于复制 .data */
    } > rom

    /* 只读数据段：放在 RAM */
    .rodata : {
        *(.rodata)
        *(.rodata.*)
    } > ram1

    /* 数据段 */
    .data : {
        _data_start = .;
        *(.data)
        *(.data.*)
        _data_end = .;
    } > ram1

    /* BSS 段：零初始化，在 RAM 中 */
    .bss : {
        _bss_start = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        _bss_end = .;
    } > ram1

    _end = .; /* 标记初始数据的结束 */
    _heap_start = ORIGIN(ram2); /* 堆的起始地址 */
    _stack_top = ORIGIN(ram2) + LENGTH(ram2); /* 栈底 */
}
EOF

riscv32-unknown-elf-gcc -T link.ld \
                        -nostartfiles -fno-builtin -mabi=ilp32 -march=rv32im \
                        -o "$base" temp_main.c
rm startup.h temp_main.c link.ld

if [ ! -e "$base" ]; then
    echo "Compile Failed"
    exit 1
fi

riscv32-unknown-elf-objdump -d -M no-aliases -j .text -j .data -j .rodata -j .sdata "$base" > "$base.s"
riscv32-unknown-elf-objcopy -O verilog "$base" "$base.hex"
rm "$base"

awk -v base="$base" '
# 处理一个已收集的字节数据块
# - bytes: 包含连续十六进制数字的字符串
# - sec: "A" 表示代码段，"B" 表示数据段
function process_block(bytes, sec) {
    for (i = 1; i <= length(bytes); i += 8) {
        chunk = substr(bytes, i, 8)
        if (length(chunk) < 8) continue

        b1 = substr(chunk, 1, 2)
        b2 = substr(chunk, 3, 2)
        b3 = substr(chunk, 5, 2)
        b4 = substr(chunk, 7, 2)

        # 小端顺序输出（与原来一致）
        word = b4 b3 b2 b1

        if (sec == "A") {
            num_text++
            text_lines[num_text] = word
        } else if (sec == "B") {
            num_data++
            data_lines[num_data] = word
        }
    }
}

# 初始化
BEGIN {
    current_addr = -1
    section = "none"
    collected_bytes = ""
    num_text = 0
    num_data = 0
}

# 主处理逻辑
{
    if ($0 ~ /^@/) {
        # 处理上一个地址块
        if (current_addr != -1 && length(collected_bytes) > 0) {
            if (section == "B") {
                next_addr = strtonum("0x" substr($0, 2))
                addr_diff_bytes = next_addr - current_addr
                collected_bytes_count = length(collected_bytes) / 2

                if (addr_diff_bytes > collected_bytes_count) {
                    pad_bytes = addr_diff_bytes - collected_bytes_count
                    for (i = 1; i <= pad_bytes; i++) {
                        collected_bytes = collected_bytes "00"
                    }
                }
            }

            if (section == "A") process_block(collected_bytes, "A")
            if (section == "B") process_block(collected_bytes, "B")
        }

        # 更新当前地址块
        current_addr = strtonum("0x" substr($0, 2))
        collected_bytes = ""

        if (current_addr == 0) {
            section = "A"
        } else if (current_addr >= 0x0000C800) {
            section = "B"
        } else {
            section = "none"
        }
    } else {
        gsub(/[[:space:]]+/, "")
        if (section != "none") {
            collected_bytes = collected_bytes $0
        }
    }
}

# 文件结束处理
END {
    # 处理最后一个地址块
    if (current_addr != -1 && length(collected_bytes) > 0) {
        if (section == "B") {
            collected_bytes_count = length(collected_bytes) / 2
            remainder = collected_bytes_count % 4
            if (remainder != 0) {
                pad_bytes = 4 - remainder
                for (i = 1; i <= pad_bytes; i++) {
                    collected_bytes = collected_bytes "00"
                }
            }
        }
        if (section == "A") process_block(collected_bytes, "A")
        if (section == "B") process_block(collected_bytes, "B")
    }

    # 生成合并的 .coe 文件
    merged = base ".coe"
    print "memory_initialization_radix=16;" > merged
    print "memory_initialization_vector=" >> merged

    # .text (0x0 ~ )
    for (i = 1; i <= num_text; i++) {
        print text_lines[i] >> merged
    }

    # .text 0 padding
    target_data_word = 50*1024/4
    pad_needed = target_data_word - num_text
    if (pad_needed > 0) {
        for (i = 1; i <= pad_needed; i++) {
            print "00000000" >> merged
        }
    }

    # .data (0x0000C800 ~ )
    for (i = 1; i <= num_data; i++) {
        print data_lines[i] >> merged
    }

    close(merged)
}
' "$base.hex"

rm "$base.hex"

count=$(tail -n +3 "$base.coe" | grep -c -E '[0-9a-fA-F]{8}')
printf "%08X\n" "$count" > "$base.txt"
tail -n +3 "$base.coe" | grep -o -E '[0-9a-fA-F]{8}' >> "$base.txt"
python3 -c "import sys; sys.stdout.buffer.write(bytes.fromhex(''.join(sys.stdin.read().split())))" < "$base.txt" > "$base.bin"
rm "$base.txt"
