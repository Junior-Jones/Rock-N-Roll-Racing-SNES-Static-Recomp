#ifndef ROCKNROLL_V05C_DISPATCH_H
#define ROCKNROLL_V05C_DISPATCH_H

#include "v05c_static_cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

JSExecResult js_v05c_step(JSCPU *cpu, const JSBus *bus, JSStop *stop);

#ifdef __cplusplus
}
#endif
#endif
