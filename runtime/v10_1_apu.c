#include "v10_1_apu.h"
#include <string.h>

/* V10.1 models only the immutable SNES IPL upload protocol. It deliberately
 * contains no SPC700 opcode fetch/decode/dispatch path. Exact uploaded-program
 * execution begins at the source-proved $0400 frontier in V10.2. */
static void jsv10_1_ipl_restart(JSV10_1Apu *a, int initial) {
    uint32_t i;
    for(i=0x0001u;i<0x00F0u;i++){ a->aram[i]=0u; a->known[i]=1u; }
    a->phase=JSV10_1_IPL_WAIT_CC;
    a->destination=0u; a->expected_counter=0u; a->bytes_written=0u; a->entry_pc=0xFFC0u;
    a->smp_to_cpu[0]=0xAAu; a->smp_to_cpu[1]=0xBBu;
    if(initial){ a->smp_to_cpu[2]=0u; a->smp_to_cpu[3]=0u; }
}
void js_v10_1_apu_power_on(JSV10_1Apu *a){ if(!a)return; memset(a,0,sizeof(*a)); jsv10_1_ipl_restart(a,1); }
void js_v10_1_apu_reset(JSV10_1Apu *a){ uint64_t cycle;if(!a)return;cycle=a->last_smp_target_cycle;memset(a->cpu_to_smp,0,sizeof(a->cpu_to_smp));memset(a->smp_to_cpu,0,sizeof(a->smp_to_cpu));a->last_smp_target_cycle=cycle;jsv10_1_ipl_restart(a,1); }
JSV10_1ApuResult js_v10_1_apu_sync(JSV10_1Apu *a,uint64_t cycle){if(!a)return JSV10_1_APU_PROTOCOL_ERROR;if(cycle<a->last_smp_target_cycle)return JSV10_1_APU_PROTOCOL_ERROR;a->last_smp_target_cycle=cycle;return a->phase==JSV10_1_IPL_AOT_REQUIRED?JSV10_1_APU_AOT_REQUIRED:JSV10_1_APU_OK;}
JSV10_1ApuResult js_v10_1_apu_cpu_read(JSV10_1Apu *a,uint8_t port,uint8_t *value){if(!a||!value)return JSV10_1_APU_PROTOCOL_ERROR;port&=3u;*value=a->smp_to_cpu[port];if(port==0u&&a->phase==JSV10_1_IPL_RESTART_ACK)jsv10_1_ipl_restart(a,0);return a->phase==JSV10_1_IPL_AOT_REQUIRED?JSV10_1_APU_AOT_REQUIRED:JSV10_1_APU_OK;}
JSV10_1ApuResult js_v10_1_apu_cpu_write(JSV10_1Apu *a,uint8_t port,uint8_t value){uint8_t term;if(!a)return JSV10_1_APU_PROTOCOL_ERROR;port&=3u;a->cpu_to_smp[port]=value;if(port!=0u)return JSV10_1_APU_OK;
    if(a->phase==JSV10_1_IPL_WAIT_CC){if(value==0xCCu){a->destination=(uint16_t)(a->cpu_to_smp[2]|((uint16_t)a->cpu_to_smp[3]<<8));a->expected_counter=0u;a->bytes_written=0u;a->smp_to_cpu[0]=0xCCu;a->phase=JSV10_1_IPL_TRANSFER;}return JSV10_1_APU_OK;}
    if(a->phase!=JSV10_1_IPL_TRANSFER)return a->phase==JSV10_1_IPL_AOT_REQUIRED?JSV10_1_APU_AOT_REQUIRED:JSV10_1_APU_PROTOCOL_ERROR;
    if(value==a->expected_counter){a->aram[a->destination]=a->cpu_to_smp[1];a->known[a->destination]=1u;a->destination=(uint16_t)(a->destination+1u);a->bytes_written++;a->smp_to_cpu[0]=value;a->expected_counter=(uint8_t)(a->expected_counter+1u);return JSV10_1_APU_OK;}
    term=(uint8_t)(a->expected_counter+3u);if(value!=term)return JSV10_1_APU_PROTOCOL_ERROR;
    a->entry_pc=(uint16_t)(a->cpu_to_smp[2]|((uint16_t)a->cpu_to_smp[3]<<8));a->smp_to_cpu[0]=value;
    if(a->entry_pc==0xFFC0u){a->phase=JSV10_1_IPL_RESTART_ACK;return JSV10_1_APU_OK;}
    a->phase=JSV10_1_IPL_AOT_REQUIRED;return JSV10_1_APU_AOT_REQUIRED;
}
