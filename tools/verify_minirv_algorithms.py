MASK32 = (1 << 32) - 1
MASK64 = (1 << 64) - 1


def u32(x):
    return x & MASK32


def s32(x):
    x &= MASK32
    return x - (1 << 32) if x & (1 << 31) else x


def sext(value, width):
    mask = (1 << width) - 1
    value &= mask
    return value - (1 << width) if value & (1 << (width - 1)) else value


def mask(width):
    return (1 << width) - 1


def booth_model(x, y, width):
    o_wid = width << 1
    p_wid = o_wid + 2
    product = ((y & mask(width)) << 1) & mask(p_wid)
    x_ext = x & mask(width)
    if x_ext & (1 << (width - 1)):
        x_ext |= 1 << width
    for _ in range(width):
        pair = product & 0b11
        high = (product >> (width + 1)) & mask(width + 1)
        high_s = sext(high, width + 1)
        x_s = sext(x_ext, width + 1)
        if pair == 0b01:
            high_s += x_s
        elif pair == 0b10:
            high_s -= x_s
        high = high_s & mask(width + 1)
        product = ((high << (width + 1)) | (product & mask(width + 1))) & mask(p_wid)
        product = sext(product, p_wid) >> 1
        product &= mask(p_wid)
    return (product >> 1) & mask(o_wid)


def divider_model(x, y, width):
    x &= mask(width)
    y &= mask(width)
    if y == 0:
        return mask(width), x
    quotient = 0
    dividend = x
    divisor = y
    remainder = 0
    for _ in range(width):
        remainder_shift = ((remainder & mask(width)) << 1) | ((dividend >> (width - 1)) & 1)
        ge_divisor = remainder_shift >= divisor
        if ge_divisor:
            remainder = remainder_shift - divisor
        else:
            remainder = remainder_shift
        quotient = ((quotient << 1) | int(ge_divisor)) & mask(width)
        dividend = (dividend << 1) & mask(width)
    return quotient, remainder & mask(width)


def trunc_div(a, b):
    q = abs(a) // abs(b)
    return -q if (a < 0) ^ (b < 0) else q


def rtl_div(a, b):
    a_s, b_s = s32(a), s32(b)
    if b_s == 0:
        return MASK32
    if a_s == -(1 << 31) and b_s == -1:
        return 1 << 31
    q, _ = divider_model(abs(a_s), abs(b_s), 32)
    return u32(-q if (a_s < 0) ^ (b_s < 0) else q)


def rtl_rem(a, b):
    a_s, b_s = s32(a), s32(b)
    if b_s == 0:
        return u32(a_s)
    if a_s == -(1 << 31) and b_s == -1:
        return 0
    _, r = divider_model(abs(a_s), abs(b_s), 32)
    return u32(-r if a_s < 0 else r)


def ref_div(a, b):
    a_s, b_s = s32(a), s32(b)
    if b_s == 0:
        return MASK32
    if a_s == -(1 << 31) and b_s == -1:
        return 1 << 31
    return u32(trunc_div(a_s, b_s))


def ref_rem(a, b):
    a_s, b_s = s32(a), s32(b)
    if b_s == 0:
        return u32(a_s)
    if a_s == -(1 << 31) and b_s == -1:
        return 0
    q = trunc_div(a_s, b_s)
    return u32(a_s - q * b_s)


def main():
    cases = [
        (0, 0),
        (1, 1),
        (-1, 1),
        (-1, -1),
        (-2, 3),
        (0x7fffffff, 2),
        (0x80000000, 1),
        (0x80000000, 0xffffffff),
        (0xffffffff, 0xffffffff),
        (0x12345678, 0x10203),
        (0xffffffff, 2),
        (7, 3),
        (-7, 3),
        (7, -3),
        (-7, -3),
        (5, 0),
    ]
    for a, b in cases:
        signed_product = booth_model(a, b, 32)
        unsigned_product = booth_model(u32(a), u32(b), 33)
        ref_signed = (s32(a) * s32(b)) & MASK64
        ref_unsigned = (u32(a) * u32(b)) & MASK64
        assert (signed_product & MASK64) == ref_signed, (a, b, signed_product, ref_signed)
        assert ((unsigned_product & MASK64) >> 32) == (ref_unsigned >> 32), (a, b)
        assert rtl_div(a, b) == ref_div(a, b), (a, b, rtl_div(a, b), ref_div(a, b))
        assert rtl_rem(a, b) == ref_rem(a, b), (a, b, rtl_rem(a, b), ref_rem(a, b))
        q_u, r_u = divider_model(u32(a), u32(b), 32)
        if u32(b) == 0:
            assert q_u == MASK32 and r_u == u32(a)
        else:
            assert q_u == u32(a) // u32(b), (a, b, q_u)
            assert r_u == u32(a) % u32(b), (a, b, r_u)
    print(f"ALGORITHM CHECK PASSED ({len(cases)} cases)")


if __name__ == "__main__":
    main()
