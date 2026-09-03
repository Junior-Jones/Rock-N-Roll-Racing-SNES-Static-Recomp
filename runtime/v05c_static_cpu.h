#ifndef ROCKNROLL_V05C_STATIC_CPU_H
#define ROCKNROLL_V05C_STATIC_CPU_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    JS_P_C = 0x01u,
    JS_P_Z = 0x02u,
    JS_P_I = 0x04u,
    JS_P_D = 0x08u,
    JS_P_X = 0x10u,
    JS_P_M = 0x20u,
    JS_P_V = 0x40u,
    JS_P_N = 0x80u
};

typedef enum JSExecResult {
    JS_EXEC_OK = 0,
    JS_EXEC_NOT_MINE = 1,
    JS_EXEC_STOP = 2
} JSExecResult;

typedef enum JSStopReason {
    JS_STOP_NONE = 0,
    JS_STOP_UNKNOWN_CONTEXT = 1,
    JS_STOP_BUS_UNAVAILABLE = 2,
    JS_STOP_UNPROVED_SUCCESSOR = 3,
    JS_STOP_UNPROVED_DYNAMIC_TARGET = 4,
    JS_STOP_UNPROVED_INTERRUPT_REENTRY = 5,
    JS_STOP_UNPROVED_RETURN = 6,
    JS_STOP_INVALID_CPU_STATE = 7,
    JS_STOP_STATIC_TERMINAL = 8
} JSStopReason;

typedef struct JSCPU {
    uint16_t a;
    uint16_t x;
    uint16_t y;
    uint16_t d;
    uint16_t s;
    uint16_t pc;
    uint8_t dbr;
    uint8_t pbr;
    uint8_t p;
    uint8_t e;
} JSCPU;

typedef uint8_t (*JSBusRead8Fn)(void *opaque, uint32_t address, int *ok);
typedef void (*JSBusWrite8Fn)(void *opaque, uint32_t address, uint8_t value, int *ok);

typedef struct JSBus {
    void *opaque;
    JSBusRead8Fn read8;
    JSBusWrite8Fn write8;
} JSBus;

typedef struct JSStop {
    JSStopReason reason;
    uint32_t source_key;
    uint32_t observed_key;
    uint32_t address;
    uint8_t value;
} JSStop;

void js_cpu_normalize(JSCPU *cpu);
unsigned js_cpu_m8(const JSCPU *cpu);
unsigned js_cpu_x8(const JSCPU *cpu);
uint32_t js_cpu_context_key(const JSCPU *cpu);
void js_stop_clear(JSStop *stop);
JSExecResult js_stop_now(JSStop *stop, JSStopReason reason, uint32_t source_key, uint32_t observed_key);

int js_bus_read8(const JSBus *bus, uint32_t address, uint8_t *out, JSStop *stop, uint32_t source_key);
int js_bus_write8(const JSBus *bus, uint32_t address, uint8_t value, JSStop *stop, uint32_t source_key);
int js_bus_read16(const JSBus *bus, uint32_t address, int linear24, uint16_t *out, JSStop *stop, uint32_t source_key);
int js_bus_write16(const JSBus *bus, uint32_t address, int linear24, uint16_t value, JSStop *stop, uint32_t source_key);
int js_bus_rmw_write(const JSBus *bus, uint32_t address, int linear24, unsigned bits, unsigned emulation,
                     uint16_t original, uint16_t value, JSStop *stop, uint32_t source_key);

uint32_t js_addr_abs(const JSCPU *cpu, uint16_t operand);
uint32_t js_addr_abs_x(const JSCPU *cpu, uint16_t operand);
uint32_t js_addr_abs_y(const JSCPU *cpu, uint16_t operand);
uint32_t js_addr_abs_long(uint32_t operand);
uint32_t js_addr_abs_long_x(const JSCPU *cpu, uint32_t operand);
uint32_t js_addr_dp(const JSCPU *cpu, uint8_t operand);
uint32_t js_addr_dp_x(const JSCPU *cpu, uint8_t operand);
uint32_t js_addr_stack_rel(const JSCPU *cpu, uint8_t operand);
int js_read_dp16(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint16_t *out, JSStop *stop, uint32_t source_key);
int js_addr_dp_ind(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key);
int js_addr_dp_ind_y(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key);
int js_addr_dp_ind_long(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key);
int js_addr_dp_ind_long_y(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key);
int js_addr_stack_rel_ind_y(const JSCPU *cpu, const JSBus *bus, uint8_t operand, uint32_t *out, JSStop *stop, uint32_t source_key);

void js_op_set_nz(JSCPU *cpu, uint16_t value, unsigned bits);
void js_op_adc(JSCPU *cpu, uint16_t value, unsigned bits);
void js_op_sbc(JSCPU *cpu, uint16_t value, unsigned bits);
void js_op_and(JSCPU *cpu, uint16_t value, unsigned bits);
void js_op_eor(JSCPU *cpu, uint16_t value, unsigned bits);
void js_op_ora(JSCPU *cpu, uint16_t value, unsigned bits);
void js_op_compare(JSCPU *cpu, uint16_t lhs, uint16_t rhs, unsigned bits);
uint16_t js_op_asl(JSCPU *cpu, uint16_t value, unsigned bits);
uint16_t js_op_lsr(JSCPU *cpu, uint16_t value, unsigned bits);
uint16_t js_op_rol(JSCPU *cpu, uint16_t value, unsigned bits);
uint16_t js_op_ror(JSCPU *cpu, uint16_t value, unsigned bits);
void js_op_bit(JSCPU *cpu, uint16_t value, unsigned bits, int immediate);
uint16_t js_op_incdec(JSCPU *cpu, uint16_t value, int delta, unsigned bits);
void js_op_load_a(JSCPU *cpu, uint16_t value, unsigned bits);
void js_op_load_x(JSCPU *cpu, uint16_t value, unsigned bits);
void js_op_load_y(JSCPU *cpu, uint16_t value, unsigned bits);
uint16_t js_op_store_a(const JSCPU *cpu, unsigned bits);
uint16_t js_op_store_x(const JSCPU *cpu, unsigned bits);
uint16_t js_op_store_y(const JSCPU *cpu, unsigned bits);

int js_stack_push8(JSCPU *cpu, const JSBus *bus, uint8_t value, int emulation_wrap, JSStop *stop, uint32_t source_key);
int js_stack_push16(JSCPU *cpu, const JSBus *bus, uint16_t value, int emulation_wrap, JSStop *stop, uint32_t source_key);
int js_stack_pop8(JSCPU *cpu, const JSBus *bus, uint8_t *value, int emulation_wrap, JSStop *stop, uint32_t source_key);
int js_stack_pop16(JSCPU *cpu, const JSBus *bus, uint16_t *value, int emulation_wrap, JSStop *stop, uint32_t source_key);

void js_op_rep(JSCPU *cpu, uint8_t mask);
void js_op_sep(JSCPU *cpu, uint8_t mask);
void js_op_xce(JSCPU *cpu);
void js_op_xba(JSCPU *cpu);
void js_op_transfer(JSCPU *cpu, char code);
int js_branch_condition(const JSCPU *cpu, char code);

JSExecResult js_v05c_guard_successor(const JSCPU *cpu, JSStop *stop, uint32_t source_key,
                                     const uint32_t *allowed, size_t allowed_count,
                                     JSStopReason rejected_reason);

#ifdef __cplusplus
}
#endif
#endif
