/* Generated exact-PC static S-SMP shard. */
#include "static_snes.hpp"
namespace SC_STATIC_SNES {
void SMP::op_step_shard_0a() {
#define op_readpc() op_read(regs.pc++)
#define op_readdp(addr) op_read((regs.p.p << 8) + ((addr) & 0xff))
#define op_readdp_discard(addr) op_read_discard((uint16)((regs.p.p << 8) + ((addr) & 0xff)))
#define op_writedp(addr,data) op_write((regs.p.p << 8) + ((addr) & 0xff),data)
#define op_readaddr(addr) op_read(addr)
#define op_readaddr_discard(addr) op_read_discard((uint16)(addr))
#define op_writeaddr(addr,data) op_write(addr,data)
switch(current_static_pc) {
case 0x0a01u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a03u: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0a04u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
case 0x0a07u: {
  rd = op_readpc();
  if(!regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a09u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}
case 0x0a0bu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a0eu: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}
case 0x0a10u: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0a11u: {
  rd = op_readpc();
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
case 0x0a13u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a16u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x0a17u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a1au: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0a26u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a29u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a2bu: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_dec(rd);
  op_writedp(dp + regs.x, rd);
  break;
}
case 0x0a2du: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a2fu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a32u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}
case 0x0a35u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a37u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a3au: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a3du: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a3fu: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0a40u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
case 0x0a43u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a46u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a49u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a4bu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0a4cu: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.a = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a4eu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a50u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a53u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a55u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a57u: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_dec(rd);
  op_writedp(dp + regs.x, rd);
  break;
}
case 0x0a59u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a5bu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a5eu: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a60u: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.a = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a62u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}
case 0x0a65u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a67u: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a69u: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.a = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a6bu: {
  op_io();
  regs.p.c = 1;
  break;
}
case 0x0a6cu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}
case 0x0a6fu: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a71u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}
case 0x0a74u: {
  rd = op_readpc();
  if(!regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a76u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a78u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a7bu: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0a7cu: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
case 0x0a7eu: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a80u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}
case 0x0a83u: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a85u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a88u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a8au: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.y = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a8cu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0a8fu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0a90u: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.a = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a92u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a94u: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_dec(rd);
  op_writedp(dp + regs.x, rd);
  break;
}
case 0x0a96u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a98u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0a9bu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a9du: {
  rd = op_readpc();
  if(!regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0a9fu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0aa2u: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0aa3u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
case 0x0aa6u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0aa9u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x0aabu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
case 0x0aaeu: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0ab1u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x0ab4u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0ab7u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}
case 0x0ab9u: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}
case 0x0abau: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0abbu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
case 0x0abeu: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0ac1u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x0ac3u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
case 0x0ac6u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0ac9u: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_dec(rd);
  op_writedp(dp + regs.x, rd);
  break;
}
case 0x0acbu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0acdu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0ad0u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0ad2u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0ad4u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0ad7u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}
case 0x0ad9u: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}
case 0x0adau: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0addu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0adeu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0ae1u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0ae3u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0ae6u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0ae8u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0aebu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0aedu: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0aefu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0af2u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}
case 0x0af4u: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}
case 0x0af5u: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0af6u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
case 0x0af9u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0afcu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0affu: {
  rd = op_readpc();
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}
default: sc_aot_fail(3u,current_static_pc,0xffu,guard_byte); break;
}
#undef op_readpc
#undef op_readdp
#undef op_readdp_discard
#undef op_writedp
#undef op_readaddr
#undef op_readaddr_discard
#undef op_writeaddr
}
}
