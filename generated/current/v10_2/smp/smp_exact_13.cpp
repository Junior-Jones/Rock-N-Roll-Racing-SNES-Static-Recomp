/* Generated exact-PC static S-SMP shard. */
#include "static_snes.hpp"
namespace SC_STATIC_SNES {
void SMP::op_step_shard_13() {
#define op_readpc() op_read(regs.pc++)
#define op_readdp(addr) op_read((regs.p.p << 8) + ((addr) & 0xff))
#define op_readdp_discard(addr) op_read_discard((uint16)((regs.p.p << 8) + ((addr) & 0xff)))
#define op_writedp(addr,data) op_write((regs.p.p << 8) + ((addr) & 0xff),data)
#define op_readaddr(addr) op_read(addr)
#define op_readaddr_discard(addr) op_read_discard((uint16)(addr))
#define op_writeaddr(addr,data) op_write(addr,data)
switch(current_static_pc) {
case 0x1375u: {
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
case 0x1377u: {
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
case 0x1379u: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}
case 0x137au: {
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
case 0x137cu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
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
