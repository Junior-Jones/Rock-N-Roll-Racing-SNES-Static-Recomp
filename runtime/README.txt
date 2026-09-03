runtime contains hand-owned portable production support layers.
Version 05C introduces v05c_static_cpu.c/.h: pure fixed W65C816 semantic/address/stack helpers plus an abstract byte-bus seam for generated bodies.
It is not a generic opcode decoder and does not implement the SNES bus; target mapping/timing begins in V06C.
