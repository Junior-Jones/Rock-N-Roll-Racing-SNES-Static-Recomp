#include "v05c_static_cpu.h"

static uint16_t js_mask(unsigned bits) { return bits == 8u ? 0x00FFu : 0xFFFFu; }
static uint16_t js_sign(unsigned bits) { return bits == 8u ? 0x0080u : 0x8000u; }
static void js_flag(JSCPU *cpu, uint8_t mask, int set) {
    cpu->p = (uint8_t)(set ? (cpu->p | mask) : (cpu->p & (uint8_t)~mask));
}

void js_cpu_normalize(JSCPU *cpu) {
    cpu->e = cpu->e ? 1u : 0u;
    if (cpu->e) {
        cpu->p = (uint8_t)(cpu->p | JS_P_M | JS_P_X);
        cpu->s = (uint16_t)(0x0100u | (cpu->s & 0x00FFu));
    }
    if (cpu->p & JS_P_X) {
        cpu->x &= 0x00FFu;
        cpu->y &= 0x00FFu;
    }
}

unsigned js_cpu_m8(const JSCPU *cpu) { return (cpu->e || (cpu->p & JS_P_M)) ? 1u : 0u; }
unsigned js_cpu_x8(const JSCPU *cpu) { return (cpu->e || (cpu->p & JS_P_X)) ? 1u : 0u; }
uint32_t js_cpu_context_key(const JSCPU *cpu) {
    uint32_t address = ((uint32_t)cpu->pbr << 16) | cpu->pc;
    return (address << 3) | ((uint32_t)(cpu->e ? 1u : 0u) << 2) |
           ((uint32_t)js_cpu_m8(cpu) << 1) | (uint32_t)js_cpu_x8(cpu);
}

void js_stop_clear(JSStop *stop) {
    if (stop) {
        stop->reason = JS_STOP_NONE;
        stop->source_key = 0u;
        stop->observed_key = 0u;
        stop->address = 0u;
        stop->value = 0u;
    }
}

JSExecResult js_stop_now(JSStop *stop, JSStopReason reason, uint32_t source_key, uint32_t observed_key) {
    if (stop) {
        stop->reason = reason;
        stop->source_key = source_key;
        stop->observed_key = observed_key;
    }
    return JS_EXEC_STOP;
}

static uint32_t js_bank_increment(uint32_t address) {
    return (address & 0xFF0000u) | ((address + 1u) & 0x00FFFFu);
}

int js_bus_read8(const JSBus *bus, uint32_t address, uint8_t *out, JSStop *stop, uint32_t source_key) {
    int ok = 0;
    uint8_t value;
    address &= 0xFFFFFFu;
    if (!bus || !bus->read8 || !out) {
        if (stop) { stop->address = address; }
        (void)js_stop_now(stop, JS_STOP_BUS_UNAVAILABLE, source_key, 0u);
        return 0;
    }
    value = bus->read8(bus->opaque, address, &ok);
    if (!ok) {
        if (stop) { stop->address = address; }
        (void)js_stop_now(stop, JS_STOP_BUS_UNAVAILABLE, source_key, 0u);
        return 0;
    }
    *out = value;
    return 1;
}

int js_bus_write8(const JSBus *bus, uint32_t address, uint8_t value, JSStop *stop, uint32_t source_key) {
    int ok = 0;
    address &= 0xFFFFFFu;
    if (!bus || !bus->write8) {
        if (stop) { stop->address = address; stop->value = value; }
        (void)js_stop_now(stop, JS_STOP_BUS_UNAVAILABLE, source_key, 0u);
        return 0;
    }
    bus->write8(bus->opaque, address, value, &ok);
    if (!ok) {
        if (stop) { stop->address = address; stop->value = value; }
        (void)js_stop_now(stop, JS_STOP_BUS_UNAVAILABLE, source_key, 0u);
        return 0;
    }
    return 1;
}

int js_bus_read16(const JSBus *bus, uint32_t address, int linear24, uint16_t *out, JSStop *stop, uint32_t source_key) {
    uint8_t lo = 0, hi = 0;
    uint32_t a1 = linear24 ? ((address + 1u) & 0xFFFFFFu) : js_bank_increment(address);
    if (!js_bus_read8(bus, address, &lo, stop, source_key)) return 0;
    if (!js_bus_read8(bus, a1, &hi, stop, source_key)) return 0;
    *out = (uint16_t)(lo | ((uint16_t)hi << 8));
    return 1;
}

int js_bus_write16(const JSBus *bus, uint32_t address, int linear24, uint16_t value, JSStop *stop, uint32_t source_key) {
    uint32_t a1 = linear24 ? ((address + 1u) & 0xFFFFFFu) : js_bank_increment(address);
    if (!js_bus_write8(bus, address, (uint8_t)value, stop, source_key)) return 0;
    if (!js_bus_write8(bus, a1, (uint8_t)(value >> 8), stop, source_key)) return 0;
    return 1;
}

int js_bus_rmw_write(const JSBus *bus, uint32_t address, int linear24, unsigned bits, unsigned emulation,
                     uint16_t original, uint16_t value, JSStop *stop, uint32_t source_key) {
    uint32_t a1;
    if (bits == 8u) {
        if (emulation && !js_bus_write8(bus, address, (uint8_t)original, stop, source_key)) return 0;
        return js_bus_write8(bus, address, (uint8_t)value, stop, source_key);
    }
    a1 = linear24 ? ((address + 1u) & 0xFFFFFFu) : js_bank_increment(address);
    /* 65C816 16-bit memory RMW writes the high byte first, then the low byte. */
    if (!js_bus_write8(bus, a1, (uint8_t)(value >> 8), stop, source_key)) return 0;
    if (!js_bus_write8(bus, address, (uint8_t)value, stop, source_key)) return 0;
    return 1;
}

uint32_t js_addr_abs(const JSCPU *cpu, uint16_t operand) { return ((uint32_t)cpu->dbr << 16) | operand; }
uint32_t js_addr_abs_x(const JSCPU *cpu, uint16_t operand) { return (js_addr_abs(cpu, operand) + cpu->x) & 0xFFFFFFu; }
uint32_t js_addr_abs_y(const JSCPU *cpu, uint16_t operand) { return (js_addr_abs(cpu, operand) + cpu->y) & 0xFFFFFFu; }
uint32_t js_addr_abs_long(uint32_t operand) { return operand & 0xFFFFFFu; }
uint32_t js_addr_abs_long_x(const JSCPU *cpu, uint32_t operand) { return (operand + cpu->x) & 0xFFFFFFu; }

static uint16_t js_direct_address(const JSCPU *cpu, uint16_t offset, int emulation_page_wrap) {
    if (emulation_page_wrap && cpu->e && (cpu->d & 0x00FFu) == 0u) {
        return (uint16_t)((cpu->d & 0xFF00u) | (offset & 0x00FFu));
    }
    return (uint16_t)(cpu->d + offset);
}
uint32_t js_addr_dp(const JSCPU *cpu, uint8_t operand) { return js_direct_address(cpu, operand, 1); }
uint32_t js_addr_dp_x(const JSCPU *cpu, uint8_t operand) {
    return js_direct_address(cpu, (uint16_t)(operand + cpu->x), 1);
}
uint32_t js_addr_stack_rel(const JSCPU *cpu, uint8_t operand) { return (uint16_t)(cpu->s + operand); }

static int js_read_dp_word(const JSCPU *cpu, const JSBus *bus, uint16_t offset, uint16_t *out, JSStop *stop, uint32_t source_key) {
    uint16_t a0 = js_direct_address(cpu, offset, 1);
    uint16_t a1 = js_direct_address(cpu, (uint16_t)(offset + 1u), 1);
    uint8_t lo = 0, hi = 0;
    if (!js_bus_read8(bus, a0, &lo, stop, source_key)) return 0;
    if (!js_bus_read8(bus, a1, &hi, stop, source_key)) return 0;
    *out = (uint16_t)(lo | ((uint16_t)hi << 8));
    return 1;
}

int js_read_dp16(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint16_t *out, JSStop *stop, uint32_t source_key) {
    return js_read_dp_word(cpu, bus, operand, out, stop, source_key);
}

static int js_read_dp_long(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key) {
    uint16_t a0 = js_direct_address(cpu, operand, 0);
    uint16_t a1 = (uint16_t)(a0 + 1u);
    uint16_t a2 = (uint16_t)(a0 + 2u);
    uint8_t b0 = 0, b1 = 0, b2 = 0;
    if (!js_bus_read8(bus, a0, &b0, stop, source_key)) return 0;
    if (!js_bus_read8(bus, a1, &b1, stop, source_key)) return 0;
    if (!js_bus_read8(bus, a2, &b2, stop, source_key)) return 0;
    *out = (uint32_t)b0 | ((uint32_t)b1 << 8) | ((uint32_t)b2 << 16);
    return 1;
}

int js_addr_dp_ind_y(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key) {
    uint16_t ptr = 0;
    if (!js_read_dp_word(cpu, bus, operand, &ptr, stop, source_key)) return 0;
    *out = ((((uint32_t)cpu->dbr << 16) | ptr) + cpu->y) & 0xFFFFFFu;
    return 1;
}
int js_addr_dp_ind(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key) {
    uint16_t ptr = 0;
    if (!js_read_dp_word(cpu, bus, operand, &ptr, stop, source_key)) return 0;
    *out = ((uint32_t)cpu->dbr << 16) | ptr;
    return 1;
}
int js_addr_dp_ind_long(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key) {
    return js_read_dp_long(cpu, bus, operand, out, stop, source_key);
}
int js_addr_dp_ind_long_y(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key) {
    uint32_t ptr = 0;
    if (!js_read_dp_long(cpu, bus, operand, &ptr, stop, source_key)) return 0;
    *out = (ptr + cpu->y) & 0xFFFFFFu;
    return 1;
}
int js_addr_stack_rel_ind_y(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key) {
    uint16_t base = (uint16_t)(cpu->s + operand), ptr = 0;
    if (!js_bus_read16(bus, base, 0, &ptr, stop, source_key)) return 0;
    *out = ((((uint32_t)cpu->dbr << 16) | ptr) + cpu->y) & 0xFFFFFFu;
    return 1;
}

void js_op_set_nz(JSCPU *cpu, uint16_t value, unsigned bits) {
    uint16_t mask = js_mask(bits), sign = js_sign(bits);
    value &= mask;
    js_flag(cpu, JS_P_Z, value == 0u);
    js_flag(cpu, JS_P_N, (value & sign) != 0u);
}

static uint16_t js_bcd_add(uint16_t a, uint16_t b, unsigned cin, unsigned bits, unsigned *carry, uint32_t *probe) {
    uint32_t lower = 0u, pre = 0u;
    unsigned c = cin ? 1u : 0u;
    unsigned shift;
    for (shift = 0u; shift < bits; shift += 4u) {
        unsigned raw = ((a >> shift) & 0xFu) + ((b >> shift) & 0xFu) + c;
        if (shift == bits - 4u) pre = lower | ((uint32_t)raw << shift);
        if (raw > 9u) raw += 6u;
        c = raw > 0xFu ? 1u : 0u;
        lower |= (uint32_t)(raw & 0xFu) << shift;
    }
    *carry = c;
    *probe = pre;
    return (uint16_t)(lower & js_mask(bits));
}

static uint16_t js_bcd_sub(uint16_t a, uint16_t b, unsigned cin, unsigned bits, unsigned *carry, uint32_t *probe) {
    uint32_t lower = 0u, pre = 0u;
    int borrow = cin ? 0 : 1;
    unsigned shift;
    for (shift = 0u; shift < bits; shift += 4u) {
        int raw = (int)((a >> shift) & 0xFu) - (int)((b >> shift) & 0xFu) - borrow;
        if (shift == bits - 4u) pre = lower | ((uint32_t)(raw & 0x1F) << shift);
        if (raw < 0) { raw -= 6; borrow = 1; } else { borrow = 0; }
        lower |= (uint32_t)(raw & 0xFu) << shift;
    }
    *carry = borrow ? 0u : 1u;
    *probe = pre;
    return (uint16_t)(lower & js_mask(bits));
}

void js_op_adc(JSCPU *cpu, uint16_t value, unsigned bits) {
    uint16_t mask = js_mask(bits), sign = js_sign(bits), a = cpu->a & mask, b = value & mask, result;
    unsigned cin = (cpu->p & JS_P_C) ? 1u : 0u, carry = 0u;
    uint32_t probe = 0u;
    if (cpu->p & JS_P_D) result = js_bcd_add(a, b, cin, bits, &carry, &probe);
    else {
        uint32_t wide = (uint32_t)a + b + cin;
        result = (uint16_t)(wide & mask); carry = wide > mask; probe = wide;
    }
    js_flag(cpu, JS_P_V, ((~(a ^ b) & (a ^ (uint16_t)probe) & sign) & mask) != 0u);
    js_flag(cpu, JS_P_C, carry != 0u);
    cpu->a = bits == 8u ? (uint16_t)((cpu->a & 0xFF00u) | result) : result;
    js_op_set_nz(cpu, result, bits);
}

void js_op_sbc(JSCPU *cpu, uint16_t value, unsigned bits) {
    uint16_t mask = js_mask(bits), sign = js_sign(bits), a = cpu->a & mask, b = value & mask, result;
    unsigned cin = (cpu->p & JS_P_C) ? 1u : 0u, carry = 0u;
    uint32_t probe = 0u;
    if (cpu->p & JS_P_D) result = js_bcd_sub(a, b, cin, bits, &carry, &probe);
    else {
        int32_t wide = (int32_t)a - (int32_t)b - (int32_t)(1u - cin);
        result = (uint16_t)((uint32_t)wide & mask); carry = wide >= 0; probe = result;
    }
    js_flag(cpu, JS_P_V, ((a ^ b) & (a ^ (uint16_t)probe) & sign) != 0u);
    js_flag(cpu, JS_P_C, carry != 0u);
    cpu->a = bits == 8u ? (uint16_t)((cpu->a & 0xFF00u) | result) : result;
    js_op_set_nz(cpu, result, bits);
}

static void js_logic_write_a(JSCPU *cpu, uint16_t value, unsigned bits) {
    value &= js_mask(bits);
    cpu->a = bits == 8u ? (uint16_t)((cpu->a & 0xFF00u) | value) : value;
    js_op_set_nz(cpu, value, bits);
}
void js_op_and(JSCPU *cpu, uint16_t value, unsigned bits) { js_logic_write_a(cpu, (uint16_t)(cpu->a & value), bits); }
void js_op_eor(JSCPU *cpu, uint16_t value, unsigned bits) { js_logic_write_a(cpu, (uint16_t)(cpu->a ^ value), bits); }
void js_op_ora(JSCPU *cpu, uint16_t value, unsigned bits) { js_logic_write_a(cpu, (uint16_t)(cpu->a | value), bits); }

void js_op_compare(JSCPU *cpu, uint16_t lhs, uint16_t rhs, unsigned bits) {
    uint16_t mask = js_mask(bits), a = lhs & mask, b = rhs & mask, result = (uint16_t)((a - b) & mask);
    js_flag(cpu, JS_P_C, a >= b); js_op_set_nz(cpu, result, bits);
}
uint16_t js_op_asl(JSCPU *cpu, uint16_t value, unsigned bits) {
    uint16_t mask = js_mask(bits), sign = js_sign(bits), r;
    value &= mask; js_flag(cpu, JS_P_C, (value & sign) != 0u); r = (uint16_t)((value << 1) & mask); js_op_set_nz(cpu, r, bits); return r;
}
uint16_t js_op_lsr(JSCPU *cpu, uint16_t value, unsigned bits) {
    uint16_t r; value &= js_mask(bits); js_flag(cpu, JS_P_C, (value & 1u) != 0u); r = (uint16_t)(value >> 1); js_op_set_nz(cpu, r, bits); return r;
}
uint16_t js_op_rol(JSCPU *cpu, uint16_t value, unsigned bits) {
    uint16_t mask = js_mask(bits), sign = js_sign(bits), r; unsigned cin = (cpu->p & JS_P_C) ? 1u : 0u;
    value &= mask; js_flag(cpu, JS_P_C, (value & sign) != 0u); r = (uint16_t)(((value << 1) | cin) & mask); js_op_set_nz(cpu, r, bits); return r;
}
uint16_t js_op_ror(JSCPU *cpu, uint16_t value, unsigned bits) {
    uint16_t mask = js_mask(bits), sign = js_sign(bits), r;
    unsigned cin = (cpu->p & JS_P_C) ? 1u : 0u;
    value &= mask;
    js_flag(cpu, JS_P_C, (value & 1u) != 0u);
    r = (uint16_t)((value >> 1) | (cin ? sign : 0u));
    r &= mask;
    js_op_set_nz(cpu, r, bits);
    return r;
}
void js_op_bit(JSCPU *cpu, uint16_t value, unsigned bits, int immediate) {
    uint16_t mask = js_mask(bits), sign = js_sign(bits), vbit = (uint16_t)(sign >> 1);
    value &= mask; js_flag(cpu, JS_P_Z, ((cpu->a & mask) & value) == 0u);
    if (!immediate) { js_flag(cpu, JS_P_N, (value & sign) != 0u); js_flag(cpu, JS_P_V, (value & vbit) != 0u); }
}
uint16_t js_op_incdec(JSCPU *cpu, uint16_t value, int delta, unsigned bits) {
    uint16_t r = (uint16_t)(((int32_t)(value & js_mask(bits)) + delta) & js_mask(bits)); js_op_set_nz(cpu, r, bits); return r;
}

static void js_load_reg(JSCPU *cpu, uint16_t *reg, uint16_t value, unsigned bits, int preserve_high) {
    if (bits == 8u) *reg = preserve_high ? (uint16_t)((*reg & 0xFF00u) | (value & 0xFFu)) : (uint16_t)(value & 0xFFu);
    else *reg = value;
    js_op_set_nz(cpu, *reg, bits);
}
void js_op_load_a(JSCPU *cpu, uint16_t value, unsigned bits) { js_load_reg(cpu, &cpu->a, value, bits, 1); }
void js_op_load_x(JSCPU *cpu, uint16_t value, unsigned bits) { js_load_reg(cpu, &cpu->x, value, bits, 0); }
void js_op_load_y(JSCPU *cpu, uint16_t value, unsigned bits) { js_load_reg(cpu, &cpu->y, value, bits, 0); }
uint16_t js_op_store_a(const JSCPU *cpu, unsigned bits) { return cpu->a & js_mask(bits); }
uint16_t js_op_store_x(const JSCPU *cpu, unsigned bits) { return cpu->x & js_mask(bits); }
uint16_t js_op_store_y(const JSCPU *cpu, unsigned bits) { return cpu->y & js_mask(bits); }

int js_stack_push8(JSCPU *cpu, const JSBus *bus, uint8_t value, int emulation_wrap, JSStop *stop, uint32_t source_key) {
    if (!js_bus_write8(bus, cpu->s, value, stop, source_key)) return 0;
    cpu->s = (uint16_t)(cpu->s - 1u);
    if (emulation_wrap && cpu->e) cpu->s = (uint16_t)(0x0100u | (cpu->s & 0xFFu));
    return 1;
}
int js_stack_push16(JSCPU *cpu, const JSBus *bus, uint16_t value, int emulation_wrap, JSStop *stop, uint32_t source_key) {
    if (!js_stack_push8(cpu, bus, (uint8_t)(value >> 8), emulation_wrap, stop, source_key)) return 0;
    return js_stack_push8(cpu, bus, (uint8_t)value, emulation_wrap, stop, source_key);
}
int js_stack_pop8(JSCPU *cpu, const JSBus *bus, uint8_t *value, int emulation_wrap, JSStop *stop, uint32_t source_key) {
    cpu->s = (uint16_t)(cpu->s + 1u);
    if (emulation_wrap && cpu->e) cpu->s = (uint16_t)(0x0100u | (cpu->s & 0xFFu));
    return js_bus_read8(bus, cpu->s, value, stop, source_key);
}
int js_stack_pop16(JSCPU *cpu, const JSBus *bus, uint16_t *value, int emulation_wrap, JSStop *stop, uint32_t source_key) {
    uint8_t lo = 0, hi = 0;
    if (!js_stack_pop8(cpu, bus, &lo, emulation_wrap, stop, source_key)) return 0;
    if (!js_stack_pop8(cpu, bus, &hi, emulation_wrap, stop, source_key)) return 0;
    *value = (uint16_t)(lo | ((uint16_t)hi << 8)); return 1;
}

void js_op_rep(JSCPU *cpu, uint8_t mask) { cpu->p = (uint8_t)(cpu->p & (uint8_t)~mask); js_cpu_normalize(cpu); }
void js_op_sep(JSCPU *cpu, uint8_t mask) { cpu->p = (uint8_t)(cpu->p | mask); js_cpu_normalize(cpu); }
void js_op_xce(JSCPU *cpu) {
    unsigned old_c = (cpu->p & JS_P_C) ? 1u : 0u, old_e = cpu->e ? 1u : 0u;
    js_flag(cpu, JS_P_C, old_e != 0u); cpu->e = (uint8_t)old_c; js_cpu_normalize(cpu);
}
void js_op_xba(JSCPU *cpu) {
    cpu->a = (uint16_t)((cpu->a << 8) | (cpu->a >> 8)); js_op_set_nz(cpu, cpu->a & 0xFFu, 8u);
}
void js_op_transfer(JSCPU *cpu, char code) {
    unsigned mb = js_cpu_m8(cpu) ? 8u : 16u, xb = js_cpu_x8(cpu) ? 8u : 16u;
    switch (code) {
        case 'A': js_op_load_x(cpu, cpu->a, xb); break; /* TAX */
        case 'B': js_op_load_y(cpu, cpu->a, xb); break; /* TAY */
        case 'C': cpu->d = cpu->a; js_op_set_nz(cpu, cpu->d, 16u); break; /* TCD */
        case 'D': cpu->s = cpu->a; js_cpu_normalize(cpu); break; /* TCS */
        case 'E': js_op_load_x(cpu, cpu->s, xb); break; /* TSX */
        case 'F': js_op_load_a(cpu, cpu->x, mb); break; /* TXA */
        case 'G': cpu->s = cpu->x; js_cpu_normalize(cpu); break; /* TXS */
        case 'H': js_op_load_a(cpu, cpu->y, mb); break; /* TYA */
        case 'I': js_op_load_y(cpu, cpu->x, xb); break; /* TXY */
        case 'J': js_op_load_x(cpu, cpu->y, xb); break; /* TYX */
        case 'K': cpu->a = cpu->s; js_op_set_nz(cpu, cpu->a, 16u); break; /* TSC */
        default: break;
    }
}
int js_branch_condition(const JSCPU *cpu, char code) {
    switch (code) {
        case 'C': return !(cpu->p & JS_P_C); /* BCC */
        case 'D': return !!(cpu->p & JS_P_C); /* BCS */
        case 'E': return !!(cpu->p & JS_P_Z); /* BEQ */
        case 'M': return !!(cpu->p & JS_P_N); /* BMI */
        case 'N': return !(cpu->p & JS_P_Z); /* BNE */
        case 'P': return !(cpu->p & JS_P_N); /* BPL */
        case 'A': return 1; /* BRA */
        default: return 0;
    }
}

JSExecResult js_v05c_guard_successor(const JSCPU *cpu, JSStop *stop, uint32_t source_key,
                                     const uint32_t *allowed, size_t allowed_count,
                                     JSStopReason rejected_reason) {
    size_t i;
    uint32_t observed = js_cpu_context_key(cpu);
    for (i = 0; i < allowed_count; ++i) if (allowed[i] == observed) return JS_EXEC_OK;
    return js_stop_now(stop, rejected_reason, source_key, observed);
}
