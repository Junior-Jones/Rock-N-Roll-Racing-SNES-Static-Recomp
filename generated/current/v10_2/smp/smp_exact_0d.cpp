/* Generated exact-PC static S-SMP shard. */
#include "static_snes.hpp"
namespace SC_STATIC_SNES {
void SMP::op_step_shard_0d() {
#define op_readpc() op_read(regs.pc++)
#define op_readdp(addr) op_read((regs.p.p << 8) + ((addr) & 0xff))
#define op_readdp_discard(addr) op_read_discard((uint16)((regs.p.p << 8) + ((addr) & 0xff)))
#define op_writedp(addr,data) op_write((regs.p.p << 8) + ((addr) & 0xff),data)
#define op_readaddr(addr) op_read(addr)
#define op_readaddr_discard(addr) op_read_discard((uint16)(addr))
#define op_writeaddr(addr,data) op_write(addr,data)
switch(current_static_pc) {
case 0x0d01u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0d03u: {
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
case 0x0d06u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0d08u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x0d0au: {
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
case 0x0d0cu: {
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
case 0x0d0eu: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}
case 0x0d0fu: {
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
case 0x0d11u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0d12u: {
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
case 0x0d15u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0d17u: {
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
case 0x0d1au: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0d1cu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x0d1eu: {
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
case 0x0d21u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0d24u: {
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
case 0x0d26u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0d27u: {
  switch(++opcode_cycle) {
  case 1:
    dp = op_readpc() + regs.x;
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0d29u: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_inc(rd);
  op_writedp(dp + regs.x, rd);
  break;
}
case 0x0d2bu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0d2du: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_inc(rd);
  op_writedp(dp + regs.x, rd);
  break;
}
case 0x0d2fu: {
  rd = op_readpc();
  regs.B.a = op_or(regs.B.a, rd);
  break;
}
case 0x0d31u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0da6u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0da9u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}
case 0x0daau: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0dadu: {
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
case 0x0dafu: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}
case 0x0db0u: {
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
case 0x0db2u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x0db5u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0db8u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}
case 0x0db9u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0dbcu: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}
case 0x0dbdu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0dc0u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}
case 0x0dc1u: {
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
case 0x0dc3u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}
case 0x0dc4u: {
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
case 0x0dc6u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x0dc9u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0dccu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x0dcfu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0dd2u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}
case 0x0dd3u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0dd6u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}
case 0x0dd7u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0ddau: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x0dddu: {
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
case 0x0ddfu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0de2u: {
  op_io();
  regs.B.a = op_dec(regs.B.a);
  break;
}
case 0x0de3u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x0de5u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
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
case 0x0de8u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0debu: {
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
case 0x0dedu: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0df0u: {
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
case 0x0df2u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x0df5u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x0df6u: {
  op_io();
  regs.p.c = 1;
  break;
}
case 0x0df7u: {
  rd = op_readpc();
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}
case 0x0df9u: {
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
case 0x0dfbu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x0dfeu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
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
