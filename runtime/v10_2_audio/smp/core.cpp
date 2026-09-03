#include "../sc_static_apu.h"
void SMP::tick() {
  timer0.tick();
  timer1.tick();
  timer2.tick();

  clock++;
  sc_static_sdsp_advance(1u);
}

void SMP::tick(unsigned clocks) {
  timer0.tick(clocks);
  timer1.tick(clocks);
  timer2.tick(clocks);

  clock += clocks;
  sc_static_sdsp_advance(clocks);
}

void SMP::op_io() {
  tick();
}

void SMP::op_io(unsigned clocks) {
  tick(clocks);
}

uint8 SMP::op_read(uint16 addr) {
  tick();
  if((addr & 0xfff0) == 0x00f0) return mmio_read(addr);
  if(addr >= 0xffc0 && status.iplrom_enable) return iplrom[addr & 0x3f];
  if(!aram_is_known(addr)) {
    sc_aot_fail(5u,current_static_pc,(uint8)(addr>>8u),(uint8)addr);
    return 0;
  }
  return apuram[addr];
}

void SMP::op_read_discard(uint16 addr) {
  tick();
  if((addr & 0xfff0u) == 0x00f0u) (void)mmio_read(addr);
}

void SMP::op_write(uint16 addr, uint8 data) {
  tick();
  if(!sc_static_apu_trace_aram_write_event(addr,data)) {
    sc_aot_fail(4u,regs.pc,0xffu,data);
    return;
  }
  if((addr & 0xfff0) == 0x00f0) mmio_write(addr, data);
  apuram[addr] = data;
  mark_aram_known(addr);
}

uint8 SMP::op_readstack()
{
  tick();
  const uint16 addr=(uint16)(0x0100 | ++regs.sp);
  if(!aram_is_known(addr)) { sc_aot_fail(5u,current_static_pc,(uint8)(addr>>8u),(uint8)addr); return 0; }
  return apuram[addr];
}

void SMP::op_writestack(uint8 data)
{
  tick();
  const uint16 addr=(uint16)(0x0100 | regs.sp);
  if(sc_static_apu_trace_aram_write_event(addr,data)) { apuram[addr]=data; mark_aram_known(addr); }
  else {
    sc_aot_fail(4u,regs.pc,0xffu,data);
  }
  regs.sp--;
}

void SMP::op_step() {
  #define op_readpc() op_read(regs.pc++)
  #define op_readdp(addr) op_read((regs.p.p << 8) + ((addr) & 0xff))
  #define op_writedp(addr, data) op_write((regs.p.p << 8) + ((addr) & 0xff), data)
  #define op_readaddr(addr) op_read(addr)
  #define op_writeaddr(addr, data) op_write(addr, data)

  if(opcode_cycle == 0)
  {
    const uint16 opcode_pc = regs.pc;
    ++instruction_count;
    current_static_pc=opcode_pc;
    guard_byte = op_readpc();
    sc_static_apu_trace_instruction_event(opcode_pc, guard_byte);
    if(!sc_aot_prepare(opcode_pc, guard_byte)) return;
  }
  switch(current_static_pc>>8u) {
    #include "smp_exact_index.inc"
  }
}
