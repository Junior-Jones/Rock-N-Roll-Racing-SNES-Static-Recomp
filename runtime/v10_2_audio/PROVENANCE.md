# Rock n' Roll Racing static S-SMP/S-DSP provenance

V10.2 uses the fail-closed construction rules from Starter SNES v10.  The
SPC700 semantic-development material was derived from Snes9x/byuu and retains
its licence in `SNES9X-LICENSE.txt`.  That material is used to generate Rock's
finite exact-PC instruction bodies; no runtime opcode dispatcher is linked.

The exact-PC shards, exact opcode guards, and executable-byte bitmap are
generated from Rock n' Roll Racing's four ROM-derived upload records, immutable
fixed IPL bytes, and documented SPC700 control-flow semantics.  The established
zero-filled power-on ARAM image from Rock's former runtime is explicit and
known; subsequent CPU/DSP writes carry value knownness.  Unknown PCs, opcode
mismatches, unemitted opcodes, unknown semantic reads, and writes to owned
driver-code bytes fail closed.

The production S-DSP is project-owned code adapted from Rock n' Roll Racing's proven
v10.33 implementation.  Its fixed 32-phase schedule produces BRR, envelope,
noise, echo, and knownness-tagged PCM from Rock's live ARAM and DSP state.  The
former snes_spc runtime DSP source has been removed.  No hybrid emulator audio
driver, runtime opcode interpreter, or fallback is linked into production.
