#include "v05c_static_cpu.h"
#include "js_v05c_dispatch.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMSIZE (1u<<24)
#define MAXLOG 64
#define F_MASK (JS_P_C|JS_P_Z|JS_P_V|JS_P_N)

typedef struct Access { char kind; uint32_t addr; uint8_t value; } Access;
typedef struct TestBus { uint8_t *mem; Access log[MAXLOG]; size_t count; } TestBus;
static int fails=0;
#define CHECK(x) do { if(!(x)){ fprintf(stderr,"FAIL %s:%d: %s\n",__FILE__,__LINE__,#x); ++fails; } } while(0)

static uint8_t rd(void *opaque,uint32_t a,int *ok){ TestBus *b=(TestBus*)opaque; uint8_t v=b->mem[a&0xffffffu]; if(b->count<MAXLOG)b->log[b->count++]=(Access){'R',a&0xffffffu,v}; *ok=1; return v; }
static void wr(void *opaque,uint32_t a,uint8_t v,int *ok){ TestBus *b=(TestBus*)opaque; b->mem[a&0xffffffu]=v; if(b->count<MAXLOG)b->log[b->count++]=(Access){'W',a&0xffffffu,v}; *ok=1; }
static void reset_bus(TestBus *b){ memset(b->mem,0,MEMSIZE); b->count=0; }
static JSCPU cpu_for(uint8_t pbr,uint16_t pc,uint8_t e,uint8_t m,uint8_t x){ JSCPU c; memset(&c,0,sizeof c); c.pbr=pbr;c.pc=pc;c.e=e;c.s=0x01ff; if(m)c.p|=JS_P_M;if(x)c.p|=JS_P_X; return c; }

static uint16_t ref_add16(uint16_t a,uint16_t b,unsigned c,int dec,uint8_t *flags){ uint32_t r; int ov;
 if(dec){ r=(a&0x0f)+(b&0x0f)+c; if(r>0x09)r+=0x06; r=(a&0xf0)+(b&0xf0)+(r>0x0f?0x10:0)+(r&0x0f); if(r>0x9f)r+=0x60; r=(a&0xf00)+(b&0xf00)+(r>0xff?0x100:0)+(r&0xff); if(r>0x9ff)r+=0x600; r=(a&0xf000)+(b&0xf000)+(r>0xfff?0x1000:0)+(r&0xfff); }
 else r=(uint32_t)a+b+c;
 ov=((~(a^b)&(a^(uint16_t)r)&0x8000)!=0); if(dec&&r>0x9fff)r+=0x6000; {uint16_t rr=(uint16_t)r; *flags=(r>0xffff?JS_P_C:0)|(rr==0?JS_P_Z:0)|(ov?JS_P_V:0)|(rr&0x8000?JS_P_N:0); return rr;}}
static uint16_t ref_sub16(uint16_t a,uint16_t bb,unsigned c,int dec,uint8_t *flags){ uint16_t b=(uint16_t)~bb; int32_t r; int ov;
 if(dec){ r=(int32_t)(a&0x0f)+(b&0x0f)+(int)c; if(r<=0x0f)r-=0x06; r=(int32_t)(a&0xf0)+(b&0xf0)+(r>0x0f?0x10:0)+(r&0x0f); if(r<=0xff)r-=0x60; r=(int32_t)(a&0xf00)+(b&0xf00)+(r>0xff?0x100:0)+(r&0xff); if(r<=0xfff)r-=0x600; r=(int32_t)(a&0xf000)+(b&0xf000)+(r>0xfff?0x1000:0)+(r&0xfff); }
 else r=(int32_t)a+(int32_t)b+(int)c;
 ov=((~(a^b)&(a^(uint16_t)r)&0x8000)!=0); if(dec&&r<=0xffff)r-=0x6000; {uint16_t rr=(uint16_t)r; *flags=(r>0xffff?JS_P_C:0)|(rr==0?JS_P_Z:0)|(ov?JS_P_V:0)|(rr&0x8000?JS_P_N:0); return rr;}}

static void test_arithmetic(void){ static const uint16_t binops[]={0,1,0x7f,0x80,0xff,0x7fff,0x8000,0xffff}; static const uint16_t decops[]={0,9,0x0a,0x99,0x9a,0x999,0x0a00,0x9999,0x9a99,0xffff}; JSCPU c; size_t i; unsigned a,cin;
 for(a=0;a<65536u;++a)for(i=0;i<sizeof binops/sizeof binops[0];++i)for(cin=0;cin<2;++cin){uint8_t f;uint16_t w; memset(&c,0,sizeof c);c.a=(uint16_t)a;c.p=cin?JS_P_C:0;w=ref_add16((uint16_t)a,binops[i],cin,0,&f);js_op_adc(&c,binops[i],16);CHECK(c.a==w&&((c.p&F_MASK)==f)); memset(&c,0,sizeof c);c.a=(uint16_t)a;c.p=cin?JS_P_C:0;w=ref_sub16((uint16_t)a,binops[i],cin,0,&f);js_op_sbc(&c,binops[i],16);CHECK(c.a==w&&((c.p&F_MASK)==f));}
 for(a=0;a<65536u;++a)for(i=0;i<sizeof decops/sizeof decops[0];++i)for(cin=0;cin<2;++cin){uint8_t f;uint16_t w; memset(&c,0,sizeof c);c.a=(uint16_t)a;c.p=JS_P_D|(cin?JS_P_C:0);w=ref_add16((uint16_t)a,decops[i],cin,1,&f);js_op_adc(&c,decops[i],16);CHECK(c.a==w&&((c.p&F_MASK)==f)); memset(&c,0,sizeof c);c.a=(uint16_t)a;c.p=JS_P_D|(cin?JS_P_C:0);w=ref_sub16((uint16_t)a,decops[i],cin,1,&f);js_op_sbc(&c,decops[i],16);CHECK(c.a==w&&((c.p&F_MASK)==f));}
}

static void test_dispatch_and_boundaries(JSBus *bus,TestBus *tb){ JSCPU c;JSStop s;JSExecResult r;
 c=cpu_for(0x00,0x8000,1,1,1);r=js_v05c_step(&c,NULL,&s);CHECK(r==JS_EXEC_OK&&c.pbr==0x80&&c.pc==0x800c);
 c=cpu_for(0x7f,0x1234,0,0,0);r=js_v05c_step(&c,NULL,&s);CHECK(r==JS_EXEC_STOP&&s.reason==JS_STOP_UNKNOWN_CONTEXT);
 c=cpu_for(0x80,0x8181,0,1,1);r=js_v05c_step(&c,bus,&s);CHECK(r==JS_EXEC_STOP&&s.reason==JS_STOP_UNPROVED_DYNAMIC_TARGET);
 c=cpu_for(0x80,0x8196,0,0,0);r=js_v05c_step(&c,bus,&s);CHECK(r==JS_EXEC_STOP&&s.reason==JS_STOP_UNPROVED_INTERRUPT_REENTRY);
 c=cpu_for(0x80,0x8362,0,0,0);r=js_v05c_step(&c,bus,&s);CHECK(r==JS_EXEC_STOP&&s.reason==JS_STOP_UNPROVED_RETURN);
 c=cpu_for(0x80,0x8177,0,1,1);r=js_v05c_step(&c,NULL,&s);CHECK(r==JS_EXEC_STOP&&s.reason==JS_STOP_BUS_UNAVAILABLE);
 c=cpu_for(0x80,0x8040,0,1,1);reset_bus(tb);r=js_v05c_step(&c,bus,&s);CHECK(r==JS_EXEC_OK&&c.pc==0x8138&&c.s==0x01fd);CHECK(tb->count==2&&tb->log[0].kind=='W'&&tb->log[0].addr==0x01ff&&tb->log[0].value==0x80&&tb->log[1].addr==0x01fe&&tb->log[1].value==0x42);
 c=cpu_for(0x80,0x812f,0,1,1);reset_bus(tb);c.s=0x01fd;tb->mem[0x01fe]=0x4c;tb->mem[0x01ff]=0x80;r=js_v05c_step(&c,bus,&s);CHECK(r==JS_EXEC_OK&&c.pc==0x804d&&c.s==0x01ff);
 /* Mixed proved/unproved return key must reject a live target outside its source-specific V04 set. */
 c=cpu_for(0x80,0x83a2,0,0,0);reset_bus(tb);c.s=0x01fc;tb->mem[0x01fd]=0xff;tb->mem[0x01fe]=0x8f;tb->mem[0x01ff]=0x80;r=js_v05c_step(&c,bus,&s);CHECK(r==JS_EXEC_STOP&&s.reason==JS_STOP_UNPROVED_RETURN&&c.pbr==0x80&&c.pc==0x9000);
 /* Contradictory external E state is rejected rather than normalized into authority. */
 c=cpu_for(0x80,0x800c,1,0,0);c.p=0;r=js_v05c_step(&c,bus,&s);CHECK(r==JS_EXEC_STOP&&s.reason==JS_STOP_INVALID_CPU_STATE);
}

static void test_memory_order(JSBus *bus,TestBus *tb){JSCPU c;JSStop s;JSExecResult r;uint32_t a=0x7e127e;
 c=cpu_for(0x80,0x818c,0,0,0);c.dbr=0x7e;reset_bus(tb);tb->mem[a]=0xff;tb->mem[a+1]=0x00;r=js_v05c_step(&c,bus,&s);CHECK(r==JS_EXEC_OK&&tb->mem[a]==0x00&&tb->mem[a+1]==0x01);CHECK(tb->count==4);CHECK(tb->log[0].kind=='R'&&tb->log[0].addr==a);CHECK(tb->log[1].kind=='R'&&tb->log[1].addr==a+1);CHECK(tb->log[2].kind=='W'&&tb->log[2].addr==a+1&&tb->log[2].value==0x01);CHECK(tb->log[3].kind=='W'&&tb->log[3].addr==a&&tb->log[3].value==0x00);
 c=cpu_for(0x80,0x818c,1,1,1);c.dbr=0x7e;reset_bus(tb);tb->mem[a]=0x7f;r=js_v05c_step(&c,bus,&s);CHECK(r==JS_EXEC_OK&&tb->mem[a]==0x80);CHECK(tb->count==3);CHECK(tb->log[0].kind=='R'&&tb->log[1].kind=='W'&&tb->log[1].value==0x7f&&tb->log[2].kind=='W'&&tb->log[2].value==0x80);
}

static void test_addressing_and_width(JSBus *bus,TestBus *tb){JSCPU c;JSStop s;uint32_t ea=0;
 memset(&c,0,sizeof c);c.e=1;c.p=JS_P_M|JS_P_X;c.d=0x1200;c.y=2;reset_bus(tb);tb->mem[0x12ff]=0x34;tb->mem[0x1200]=0x56;CHECK(js_addr_dp_ind_y(&c,bus,0xff,&ea,&s,1));CHECK(ea==0x005636);CHECK(tb->count==2&&tb->log[0].addr==0x12ff&&tb->log[1].addr==0x1200);
 memset(&c,0,sizeof c);c.a=0xab55;c.p=JS_P_M;js_op_eor(&c,0x00ff,8);CHECK(c.a==0xabaa);
}

int main(void){ TestBus tb; JSBus bus; tb.mem=(uint8_t*)calloc(MEMSIZE,1); if(!tb.mem){fprintf(stderr,"alloc failed\n");return 2;} tb.count=0;bus.opaque=&tb;bus.read8=rd;bus.write8=wr;
 test_arithmetic();test_dispatch_and_boundaries(&bus,&tb);test_memory_order(&bus,&tb);test_addressing_and_width(&bus,&tb);free(tb.mem);if(fails){fprintf(stderr,"V05C native failures: %d\n",fails);return 1;}printf("V05C native semantic/access/dispatch tests: PASS\n");return 0;}
