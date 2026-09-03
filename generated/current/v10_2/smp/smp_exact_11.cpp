/* Generated exact-PC static S-SMP shard. */
#include "static_snes.hpp"
namespace SC_STATIC_SNES {
void SMP::op_step_shard_11() {
#define op_readpc() op_read(regs.pc++)
#define op_readdp(addr) op_read((regs.p.p << 8) + ((addr) & 0xff))
#define op_readdp_discard(addr) op_read_discard((uint16)((regs.p.p << 8) + ((addr) & 0xff)))
#define op_writedp(addr,data) op_write((regs.p.p << 8) + ((addr) & 0xff),data)
#define op_readaddr(addr) op_read(addr)
#define op_readaddr_discard(addr) op_read_discard((uint16)(addr))
#define op_writeaddr(addr,data) op_write(addr,data)
switch(current_static_pc) {
case 0x1101u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_and(regs.B.a, rd);
  break;
}
case 0x1103u: {
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
case 0x1105u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x1108u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x110bu: {
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
case 0x110eu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x1111u: {
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
case 0x1114u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x1117u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x111au: {
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
case 0x111du: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x1120u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x1123u: {
  op_io(2);
  op_writestack(regs.x);
  break;
}
case 0x1124u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x1127u: {
  op_io(2);
  regs.x = op_readstack();
  break;
}
case 0x1128u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x112bu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x112du: {
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
case 0x1130u: {
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
case 0x1133u: {
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
case 0x1136u: {
  op_io();
  regs.B.a = op_dec(regs.B.a);
  break;
}
case 0x1137u: {
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
case 0x113au: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x113cu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}
case 0x113eu: {
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
case 0x1140u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x1141u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x1144u: {
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
case 0x1146u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x1149u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x114bu: {
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
case 0x114eu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x1150u: {
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
case 0x1153u: {
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
case 0x1156u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x1159u: {
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
case 0x115cu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x115eu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x1160u: {
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
case 0x1163u: {
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
case 0x1165u: {
  switch(++opcode_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x1167u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}
case 0x1169u: {
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
case 0x116bu: {
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
case 0x116eu: {
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
case 0x1170u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x1173u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}
case 0x1175u: {
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
case 0x1177u: {
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
case 0x1179u: {
  op_io();
  regs.p.c = 1;
  break;
}
case 0x117au: {
  rd = op_readpc();
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}
case 0x117cu: {
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
case 0x117eu: {
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
case 0x1180u: {
  rd = op_readpc();
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}
case 0x1182u: {
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
case 0x1184u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x1187u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x118au: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}
case 0x118bu: {
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
case 0x118eu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}
case 0x11a1u: {
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
case 0x11a3u: {
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
case 0x11a5u: {
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
case 0x11a7u: {
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
case 0x11a9u: {
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
case 0x11abu: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_inc(rd);
  op_writedp(dp + regs.x, rd);
  break;
}
case 0x11adu: {
  switch(++opcode_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x11afu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x11b0u: {
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
case 0x11b2u: {
  op_io();
  regs.B.y = op_dec(regs.B.y);
  break;
}
case 0x11b3u: {
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
case 0x11b6u: {
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
case 0x11b8u: {
  op_io();
  regs.B.y = op_dec(regs.B.y);
  break;
}
case 0x11b9u: {
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
case 0x11bcu: {
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
case 0x11beu: {
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
    op_writedp(dp, regs.B.y);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x11c0u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x11c1u: {
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
case 0x11c3u: {
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
case 0x11c6u: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_inc(rd);
  op_writedp(dp + regs.x, rd);
  break;
}
case 0x11c8u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x11c9u: {
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
case 0x11cbu: {
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
case 0x11cdu: {
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
case 0x11d0u: {
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
case 0x11d2u: {
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
case 0x11d5u: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}
case 0x11d6u: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}
case 0x11d7u: {
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
    op_writedp(dp, regs.B.y);
    opcode_cycle = 0;
    break;
  }
  break;
}
case 0x11d9u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}
case 0x11dau: {
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
case 0x11ddu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}
case 0x11dfu: {
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
case 0x11e1u: {
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
case 0x11e4u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x11e7u: {
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
case 0x11e9u: {
  op_io();
  regs.x = op_inc(regs.x);
  break;
}
case 0x11eau: {
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
case 0x11ecu: {
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
case 0x11efu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}
case 0x11f2u: {
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
case 0x11f4u: {
  op_io();
  regs.x = op_inc(regs.x);
  break;
}
case 0x11f5u: {
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
case 0x11f7u: {
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
case 0x11fau: {
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
case 0x11fcu: {
  op_io();
  regs.x = op_inc(regs.x);
  break;
}
case 0x11fdu: {
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
case 0x11ffu: {
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
