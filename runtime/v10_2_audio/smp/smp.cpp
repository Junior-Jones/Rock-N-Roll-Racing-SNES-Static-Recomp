#include "../static_snes.hpp"
#define SMP_CPP
namespace SC_STATIC_SNES {
SMP smp;
#include "algorithms.cpp"
#include "core.cpp"
#include "iplrom.cpp"
#include "memory.cpp"
#include "timing.cpp"
bool SMP::sc_aot_fail(uint32 reason,uint16 pc,uint8 expected,uint8 actual){
  if(!sc_aot_failed_value){
    sc_aot_failed_value=1;sc_aot_fail_reason_value=reason;
    sc_aot_fail_pc_value=pc;sc_aot_expected_opcode=expected;
    sc_aot_actual_opcode=actual;
  }
  clock=0;return false;
}
void SMP::sc_aot_reset_metrics(){
  sc_aot_instructions=0;sc_aot_failed_value=0;sc_aot_fail_pc_value=0;
  sc_aot_fail_reason_value=0;sc_aot_expected_opcode=0xff;
  sc_aot_actual_opcode=0xff;
}
#include "sc_smp_aot_lookup.inc"
void SMP::enter(){
  if(sc_aot_failed_value){clock=0;return;}
  while(clock<0){
    if(sc_aot_failed_value){clock=0;break;}
    op_step();
  }
}
void SMP::power(){Processor::clock=0;timer0.target=timer1.target=timer2.target=0;reset();}
void SMP::reset(){
  sc_aot_reset_metrics();
  for(unsigned n=0;n<=0xffff;n++)apuram[n]=0;
  /* Preserve Rock's established deterministic power-on image.  The former
     Snes9x-derived runtime initialized all 64 KiB of ARAM to zero; Rock reads
     bytes from that image (including stack-page data) before overwriting them.
     Treat that captured power-on image as known, then let later writes update
     value and knownness normally. */
  for(unsigned n=0;n<8192u;n++)aram_known[n]=0xffu;
  opcode_cycle=0;current_static_pc=0xffc0u;guard_byte=0xffu;
  instruction_count=0;regs.pc=0xffc0;regs.sp=0xef;
  regs.B.a=0;regs.x=0;regs.B.y=0;regs.p=0x02;
  status.iplrom_enable=true;status.dsp_addr=0;status.ram00f8=status.ram00f9=0;
  timer0.enable=timer1.enable=timer2.enable=false;
  timer0.stage1_ticks=timer1.stage1_ticks=timer2.stage1_ticks=0;
  timer0.stage2_ticks=timer1.stage2_ticks=timer2.stage2_ticks=0;
  timer0.stage3_ticks=timer1.stage3_ticks=timer2.stage3_ticks=0;
}
bool SMP::aram_is_known(uint16 address) const {
  return (aram_known[address>>3u]&(uint8)(1u<<(address&7u)))!=0u;
}
void SMP::mark_aram_known(uint16 address){
  aram_known[address>>3u]|=(uint8)(1u<<(address&7u));
}
SMP::SMP(){apuram=new uint8[64*1024];aram_known=new uint8[8192];}
SMP::~SMP(){delete[] aram_known;delete[] apuram;}
}
