# Starter SNES v9 migration audit

The v10.1 project predates Starter SNES v9. Its historical milestone numbers
remain unchanged, while v10.2 adopts the current governance and verification
requirements.

The current production core is not being treated as complete merely because it
matches its old discovery set. V10.2 separates discovery completion from
production completion, records one selected authority for every machine role,
and requires an explicit retirement row whenever a predecessor implementation
is replaced.

The Windows Mesen headless oracle at
`D:\Users\build\retro\Recomp\Mesen Headless Oracle\MesenCE-2.2.1-SNES-Headless-Oracle-V02-Windows`
is the target oracle. The Linux-only Starter package binary is not used on this
Windows project. Oracle observations are limited to S-CPU discovery checking;
they do not promote contexts.

Migration work still open:

- complete independent RESET/vector/bank/shard S-CPU rediscovery;
- close source-proved indirect, return, interrupt and executable-RAM frontiers;
- regenerate production static rows and timing plans for the final discovery;
- add deterministic cold regeneration and independent production-shard audits;
- complete S-SMP, DSP/audio, renderer and input milestones after S-CPU closure;
- port the Rock n' Roll Racing Windows frontend as a clean source port only after the
  core exposes stable frame, input and PCM contracts.
