#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_0020(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_2020(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_2021(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_2028(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_2029(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_2030(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_203E(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_2067(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_2068(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_2069(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_206B(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_206D(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_206E(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_206F(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_207D(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_207E(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_24BB(JSV06Machine *m, JSV06Stop *stop);
int js_v06c_fetch_shard_24BC(JSV06Machine *m, JSV06Stop *stop);

int js_v06c_fetch_guard(JSV06Machine *m, JSV06Stop *stop) {
    int r; uint32_t group;
    if(!m) return -1;
    group=((((uint32_t)m->cpu.pbr<<16)|m->cpu.pc)>>10);
    switch(group) {
    case 0x0020u: r=js_v06c_fetch_shard_0020(m,stop); break;
    case 0x2020u: r=js_v06c_fetch_shard_2020(m,stop); break;
    case 0x2021u: r=js_v06c_fetch_shard_2021(m,stop); break;
    case 0x2028u: r=js_v06c_fetch_shard_2028(m,stop); break;
    case 0x2029u: r=js_v06c_fetch_shard_2029(m,stop); break;
    case 0x2030u: r=js_v06c_fetch_shard_2030(m,stop); break;
    case 0x203Eu: r=js_v06c_fetch_shard_203E(m,stop); break;
    case 0x2067u: r=js_v06c_fetch_shard_2067(m,stop); break;
    case 0x2068u: r=js_v06c_fetch_shard_2068(m,stop); break;
    case 0x2069u: r=js_v06c_fetch_shard_2069(m,stop); break;
    case 0x206Bu: r=js_v06c_fetch_shard_206B(m,stop); break;
    case 0x206Du: r=js_v06c_fetch_shard_206D(m,stop); break;
    case 0x206Eu: r=js_v06c_fetch_shard_206E(m,stop); break;
    case 0x206Fu: r=js_v06c_fetch_shard_206F(m,stop); break;
    case 0x207Du: r=js_v06c_fetch_shard_207D(m,stop); break;
    case 0x207Eu: r=js_v06c_fetch_shard_207E(m,stop); break;
    case 0x24BBu: r=js_v06c_fetch_shard_24BB(m,stop); break;
    case 0x24BCu: r=js_v06c_fetch_shard_24BC(m,stop); break;
    default: r=0; break;
    }
    return r;
}
