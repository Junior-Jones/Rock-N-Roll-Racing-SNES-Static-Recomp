# Top Gear Version 27 maturity reference for Rock n' Roll Racing

Top Gear is the local completion reference. Rock n' Roll Racing supplies the repair
method; Top Gear supplies the shape of a mature finished static core. No Top
Gear game code or target constants are valid Rock n' Roll Racing authority.

Reference source inspected:

`D:\Users\build\retro\Recomp\Top Gear\Top-Gear-SNES-Static-Recomp-Version-27-Static-Core-Repair-Windows-Source`

## Production properties to reproduce with target-specific proof

| Area | Top Gear mature property | Rock n' Roll Racing required result |
|---|---|---|
| S-CPU | ROM-wide generated C shards, exact context dispatch, no runtime opcode decoder, unknown keys fail closed | Complete ROM-rooted PBR:PC:E:M:X discovery, generated static shards and exact ROM guards |
| Dynamic execution | Separate generated re-entry, interrupt and executable-WRAM authority | Prove every indirect domain, interrupt return and mutable executable epoch separately |
| Build purity | One current production family; historical/experimental routes absent from the default link | One selected production graph and explicit predecessor retirement ledger |
| Machine | State ownership separated from generated instruction bodies | WRAM, bus, MMIO, DMA/HDMA, PPU, controller and APUIO state owned by the machine layer |
| Scheduler | Independent clock domains and explicit rendezvous | One monotonic S-CPU timeline plus physical S-SMP/DSP synchronization, refresh, interrupts and DMA stalls |
| PPU | Functional target-used modes, OBJ/OAM, VRAM/OAM/CGRAM, windows, main/subscreen, color math and forced blank | Discover and implement every Rock n' Roll Racing-used mode/channel/layer/window/color operation and render frames |
| Input | Both physical controller paths represented where used | Implement the target's controller-port use and frontend mapping without inventing unused players |
| S-SMP | Exact-PC/opcode static authority, compiled-byte write barrier, unknown execution fails closed | Generate the exact uploaded ARAM program beginning at $0400 and all later proved code epochs |
| S-DSP/audio | BRR, pitch/interpolation/noise, ADSR/GAIN, mixing, echo/FIR and stable PCM transport | Complete the native target audio signal path and a bounded PCM FIFO/host contract |
| Frontend seam | Frame, input and PCM are stable one-way public APIs | Port the Rock n' Roll Racing Windows frontend only through Rock-specific stable public contracts |
| Verification | Deterministic regeneration, production-link purity, route tests and fail-closed gap repair | Independent source audits, cold regeneration, Windows build, headless core tests and user Test build |

## Numerical reference, not a target quota

Top Gear V26 reports 8,685 normalized ROM contexts in 29 shards, plus distinct
re-entry/interrupt and 2,703-context executable-WRAM authority. These figures
show why one small reset slice is not a completed core. Rock n' Roll Racing's
final count will be whatever its exact source proof requires; neither 8,685 nor
an estimated 15,000 is used as an acceptance threshold.

## Completion gate

Rock n' Roll Racing is not ready for testing merely when it compiles. Testing
starts after the full discovered S-CPU set is in production, every unsupported
context has a named fail-closed disposition, target-used hardware is owned, and
the production link contains no interpreter, oracle, experimental backend or
stale predecessor route.
