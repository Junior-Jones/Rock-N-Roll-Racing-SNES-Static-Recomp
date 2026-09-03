/* Generated exact-PC static S-SMP shard. */
#include "static_snes.hpp"
namespace SC_STATIC_SNES {
void SMP::op_step_shard_06() {
#define op_readpc() op_read(regs.pc++)
#define op_readdp(addr) op_read((regs.p.p << 8) + ((addr) & 0xff))
#define op_readdp_discard(addr) op_read_discard((uint16)((regs.p.p << 8) + ((addr) & 0xff)))
#define op_writedp(addr,data) op_write((regs.p.p << 8) + ((addr) & 0xff),data)
#define op_readaddr(addr) op_read(addr)
#define op_readaddr_discard(addr) op_read_discard((uint16)(addr))
#define op_writeaddr(addr,data) op_write(addr,data)
switch(current_static_pc) {
case 0x0600u: {
  rd = op_readpc();
  regs.B.a = op_or(regs.B.a, rd);
  break;
}
case 0x0602u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0605u: {
  switch(++opcode_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0608u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x060au: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  rd = op_readaddr(dp);
  rd = op_inc(rd);
  op_writeaddr(dp, rd);
  break;
}
case 0x060du: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x060fu: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0612u: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0613u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x0616u: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0617u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0632u: {
  op_io();
  regs.x = regs.B.a;
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}
case 0x0633u: {
  op_io();
  regs.x = op_dec(regs.x);
  break;
}
case 0x0634u: {
  switch(++opcode_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.x);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0636u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0639u: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x063cu: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x063fu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0642u: {
  op_io();
  regs.p.c = 1;
  break;
}
case 0x0643u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0644u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x0647u: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x064au: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x064du: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x064eu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x067cu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x067fu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.B.y);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}
case 0x0682u: {
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
case 0x0685u: {
  op_io();
  regs.p.c = 0;
  break;
}
case 0x0686u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0687u: {
  switch(++opcode_cycle) {
  case 1:
    dp = op_readpc();
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
case 0x0689u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0693u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x0696u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x0697u: {
  switch(++opcode_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x069au: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x069bu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}
case 0x069du: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x069fu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x06a1u: {
  rd = op_readpc();
  if(!regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x06a3u: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06a5u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}
case 0x06a7u: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x06a9u: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06acu: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06afu: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}
case 0x06b1u: {
  switch(++opcode_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06b3u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x06b5u: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06b7u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}
case 0x06b9u: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x06bbu: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06beu: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06c1u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}
case 0x06c3u: {
  switch(++opcode_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06c5u: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06c8u: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06cbu: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06ceu: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06d1u: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06d4u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}
case 0x06d6u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x06d9u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}
case 0x06dbu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x06deu: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}
case 0x06e0u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x06e3u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}
case 0x06e5u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x06e8u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}
case 0x06eau: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x06edu: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}
case 0x06efu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x06f2u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}
case 0x06f4u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x06f7u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}
case 0x06f9u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x06fcu: {
  switch(++opcode_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x06ffu: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    opcode_cycle = 0;
    break;
  }
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
