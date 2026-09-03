from __future__ import annotations
from dataclasses import dataclass, field
from enum import IntEnum
from hashlib import sha256
import json

NTSC_MASTER_CLOCK = 21_477_270
SPC_RATIO_NUM = 32_000 * 64
SPC_RATIO_DEN = NTSC_MASTER_CLOCK
NORMAL_SCANLINE_CLOCKS = 1364
SHORT_SCANLINE_CLOCKS = 1360
DRAM_REFRESH_CLOCKS = 40
HDMA_LINE_HCLOCK = 276 * 4

class PrimaryEvent(IntEnum):
    HDMA_INIT = 0
    DRAM_REFRESH = 1
    HDMA_LINE = 2
    END_SCANLINE = 3

class CpuStop(IntEnum):
    RUNNING = 0
    WAITING_FOR_INTERRUPT = 1
    STOPPED = 2

class DmaRendezvous(IntEnum):
    NONE = 0
    MANUAL = 1
    HDMA_INIT = 2
    HDMA_LINE = 3

@dataclass(frozen=True)
class Event:
    master_clock: int
    scanline: int
    hclock: int
    kind: str
    detail: str = ""

@dataclass
class Scheduler:
    master_clock: int = 0
    hclock: int = 0
    scanline: int = 0
    field_odd: int = 0
    frame_number: int = 0
    overscan: bool = False
    interlace: bool = False
    forced_blank: bool = True
    dram_refresh_position: int = 538
    next_primary_clock: int = 538
    next_primary_event: PrimaryEvent = PrimaryEvent.DRAM_REFRESH

    # $4200/$4207-$420A timing/interrupt state
    enable_nmi: bool = False
    enable_hirq: bool = False
    enable_virq: bool = False
    enable_autojoy: bool = False
    htimer: int = 0x1FF
    vtimer: int = 0x1FF
    hcounter: int = 0
    vcounter: int = 0
    nmi_flag: bool = False
    nmi_signal: bool = False
    nmi_pending: bool = False
    irq_level: bool = False
    need_irq: int = 0
    irq_flag: bool = False
    irq_source: bool = False

    # auto joypad timing. Controller electrical semantics are a later input milestone;
    # V07 schedules the strobe/busy/shift windows deterministically.
    autojoy_clock_start: int = 0
    autojoy_next_clock: int = 0
    autojoy_active: bool = False
    autojoy_disabled: bool = True
    autojoy_strobe: bool = False
    autojoy_step: int = -1
    controller_data: list[int] = field(default_factory=lambda: [0, 0, 0, 0])
    autojoy_sample_bits: list[int] = field(default_factory=lambda: [0, 0])

    # CPU and later-subsystem rendezvous ownership
    cpu_cycle_count: int = 0
    cpu_stop: CpuStop = CpuStop.RUNNING
    dma_request: DmaRendezvous = DmaRendezvous.NONE
    dma_start_delay: int = 0
    dma_rendezvous_ready: DmaRendezvous = DmaRendezvous.NONE
    hdma_enable_mask: int = 0
    manual_dma_mask: int = 0

    smp_target_cycle: int = 0
    smp_target_remainder: int = 0
    events: list[Event] = field(default_factory=list)

    def __post_init__(self) -> None:
        self._recalculate_frame_timing()
        self.dram_refresh_position = 538 - (self.master_clock & 7)
        self.next_primary_clock = self.dram_refresh_position
        self.next_primary_event = PrimaryEvent.DRAM_REFRESH
        self._update_smp_target()

    @property
    def vblank_start(self) -> int:
        return 240 if self.overscan else 225

    @property
    def nmi_scanline(self) -> int:
        return self.vblank_start

    @property
    def last_scanline(self) -> int:
        # NTSC: interlace field with field bit 0 has 263 scanlines; all other
        # target fields have 262. This matches the pinned independent oracle source.
        return 262 if self.interlace and not self.field_odd else 261

    @property
    def in_vblank(self) -> bool:
        return self.scanline >= self.nmi_scanline

    @property
    def in_hblank(self) -> bool:
        # CPU $4212 timing convention used by the pinned source: clear H=4..1096.
        return not (4 <= self.hclock <= 1096)

    def _recalculate_frame_timing(self) -> None:
        # Kept as a named hook because V09 will own overscan/interlace register writes.
        pass

    def log(self, kind: str, detail: str = "") -> None:
        self.events.append(Event(self.master_clock, self.scanline, self.hclock, kind, detail))

    def event_digest(self) -> str:
        payload = [e.__dict__ for e in self.events]
        return sha256(json.dumps(payload, sort_keys=True, separators=(",", ":")).encode()).hexdigest()

    def _update_smp_target(self) -> None:
        product = self.master_clock * SPC_RATIO_NUM
        self.smp_target_cycle, self.smp_target_remainder = divmod(product, SPC_RATIO_DEN)

    def set_display_timing(self, *, overscan: bool | None = None, interlace: bool | None = None) -> None:
        # V07 owns timeline semantics; V09 will call this when SETINI/overscan becomes live.
        if overscan is not None:
            self.overscan = bool(overscan)
        if interlace is not None:
            self.interlace = bool(interlace)

    def reset_cpu_side(self) -> None:
        """CPU RESET does not rewind the V07 master timeline/raster/refresh phase."""
        self.enable_autojoy = False
        self.enable_nmi = False
        self.enable_hirq = False
        self.enable_virq = False
        self.nmi_flag = False
        self.nmi_signal = False
        self.nmi_pending = False
        self.irq_level = False
        self.need_irq = 0
        self.irq_flag = False
        self.irq_source = False
        self.autojoy_clock_start = 0
        self.autojoy_next_clock = 0
        self.autojoy_active = False
        self.autojoy_disabled = True
        self.autojoy_strobe = False
        self.autojoy_step = -1
        self.dma_request = DmaRendezvous.NONE
        self.dma_start_delay = 0
        self.dma_rendezvous_ready = DmaRendezvous.NONE
        self.manual_dma_mask = 0
        self.hdma_enable_mask = 0
        self.cpu_stop = CpuStop.RUNNING
        self.log("CPU_RESET_WITHOUT_TIMELINE_REWIND")

    def _set_autojoy_clock(self) -> None:
        range_start = self.master_clock + 130
        self.autojoy_clock_start = range_start + ((256 - (range_start & 0xFF)) if (range_start & 0xFF) else 0) - 128
        self.autojoy_next_clock = self.autojoy_clock_start
        self.autojoy_disabled = False
        self.autojoy_step = -1
        self.log("AUTOJOY_WINDOW_ARM", str(self.autojoy_clock_start))

    def _process_autojoy_due(self) -> None:
        if self.autojoy_disabled:
            return
        while self.autojoy_next_clock <= self.master_clock:
            clock = self.autojoy_next_clock
            self.autojoy_next_clock += 128
            step = (clock - self.autojoy_clock_start) // 128
            self.autojoy_step = int(step)
            if step == 0:
                self.autojoy_strobe = self.enable_autojoy
            elif step == 1:
                if not self.enable_autojoy:
                    self.autojoy_disabled = True
                    self.autojoy_active = False
                else:
                    self.autojoy_active = True
                    self.controller_data[:] = [0, 0, 0, 0]
            elif step == 2:
                self.autojoy_strobe = False
            else:
                if not self.enable_autojoy:
                    step = 34
                elif step & 1:
                    # Electrical controller reads are deferred; deterministic sample
                    # bits are a narrow seam set by the future input subsystem.
                    pass
                else:
                    p1, p2 = self.autojoy_sample_bits
                    self.controller_data[0] = ((self.controller_data[0] << 1) | (p1 & 1)) & 0xFFFF
                    self.controller_data[1] = ((self.controller_data[1] << 1) | (p2 & 1)) & 0xFFFF
                    self.controller_data[2] = ((self.controller_data[2] << 1) | ((p1 >> 1) & 1)) & 0xFFFF
                    self.controller_data[3] = ((self.controller_data[3] << 1) | ((p2 >> 1) & 1)) & 0xFFFF
            self.log("AUTOJOY_STEP", str(step))
            if step >= 34:
                self.autojoy_disabled = True
                self.autojoy_active = False
                self.autojoy_strobe = False
                return

    def _update_irq_level(self) -> None:
        enabled = self.enable_hirq or self.enable_virq
        if not enabled:
            self.irq_level = False
            return
        level = ((not self.enable_hirq or self.htimer == self.hcounter) and
                 (not self.enable_virq or self.vtimer == self.vcounter))
        if not self.irq_level and level:
            self.need_irq = 3 if self.enable_hirq and self.hclock == 6 else 2
            self.log("IRQ_MATCH", f"delay={self.need_irq}")
        self.irq_level = level

    def _process_irq_counters(self) -> None:
        if self.need_irq > 0:
            self.need_irq -= 1
            if self.need_irq == 1:
                self.irq_flag = True
                self.log("IRQ_FLAG_SET")
            elif self.need_irq == 0:
                self.irq_source = bool(self.irq_flag)
                self.log("IRQ_SOURCE_ASSERT" if self.irq_source else "IRQ_SOURCE_CLEAR")
        h = self.hclock
        if h > 10:
            self.hcounter = (self.hcounter + 1) & 0x1FF
        elif h == 10:
            self.hcounter = 0
        elif h == 6:
            self.hcounter = 0
            if self.scanline > 0:
                self.vcounter = (self.vcounter + 1) & 0x1FF
            if self.enable_nmi and self.scanline == self.nmi_scanline:
                self.nmi_signal = True
                self.log("NMI_SIGNAL_ASSERT")
        elif h == 2:
            self.hcounter = (self.hcounter + 1) & 0x1FF
            if self.scanline == self.nmi_scanline:
                self.nmi_flag = True
                self.log("NMI_FLAG_SET")
            elif self.scanline == 0:
                self.nmi_flag = False
                self.vcounter = 0
        self._update_irq_level()

    def _line_ends_now(self) -> bool:
        if self.hclock >= NORMAL_SCANLINE_CLOCKS:
            return True
        return self.hclock == SHORT_SCANLINE_CLOCKS and self.scanline == 240 and bool(self.field_odd) and not self.interlace

    def _queue_dma(self, kind: DmaRendezvous) -> None:
        # Priority between simultaneous later-controller requests is V08-owned.
        # V07 guarantees a deterministic request and one CPU-boundary admission delay.
        if kind == DmaRendezvous.NONE:
            return
        if self.dma_request == DmaRendezvous.NONE or kind > self.dma_request:
            self.dma_request = kind
        self.dma_start_delay = 1
        self.log("DMA_RENDEZVOUS_REQUEST", kind.name)

    def _process_primary_event(self) -> None:
        ev = self.next_primary_event
        if ev == PrimaryEvent.HDMA_INIT:
            self.log("HDMA_INIT_BOUNDARY")
            if self.hdma_enable_mask:
                self._queue_dma(DmaRendezvous.HDMA_INIT)
            self.next_primary_event = PrimaryEvent.DRAM_REFRESH
            self.next_primary_clock = self.dram_refresh_position
            return
        if ev == PrimaryEvent.DRAM_REFRESH:
            self.log("DRAM_REFRESH_BEGIN")
            # Wall-time stall: these 40 clocks are real scheduler clocks but do not
            # consume requested CPU access duration.
            self._advance_wall(DRAM_REFRESH_CLOCKS)
            self.log("DRAM_REFRESH_END")
            if self.scanline < self.vblank_start:
                self.next_primary_event = PrimaryEvent.HDMA_LINE
                self.next_primary_clock = HDMA_LINE_HCLOCK
            else:
                self.next_primary_event = PrimaryEvent.END_SCANLINE
                self.next_primary_clock = 1360
            return
        if ev == PrimaryEvent.HDMA_LINE:
            self.log("HDMA_LINE_BOUNDARY")
            if self.hdma_enable_mask:
                self._queue_dma(DmaRendezvous.HDMA_LINE)
            self.next_primary_event = PrimaryEvent.END_SCANLINE
            self.next_primary_clock = 1360
            return
        if ev == PrimaryEvent.END_SCANLINE:
            if not self._line_ends_now():
                self.next_primary_clock += 2
                return
            ended_line = self.scanline
            self.scanline += 1
            self.hclock = 0
            self.log("SCANLINE_END", str(ended_line))
            if self.scanline == self.nmi_scanline:
                self.log("VBLANK_ENTER")
                self._set_autojoy_clock()
            if self.scanline > self.last_scanline:
                self.field_odd ^= 1
                self.scanline = 0
                self.frame_number += 1
                self.log("FRAME_START", f"field_odd={self.field_odd}")
            self.dram_refresh_position = 538 - (self.master_clock & 7)
            if self.scanline == 0:
                self.next_primary_event = PrimaryEvent.HDMA_INIT
                self.next_primary_clock = 12 + (self.master_clock & 7)
            else:
                self.next_primary_event = PrimaryEvent.DRAM_REFRESH
                self.next_primary_clock = self.dram_refresh_position
            return
        raise AssertionError(ev)

    def _tick2(self) -> None:
        self.master_clock += 2
        self.hclock += 2
        if self.hclock == self.next_primary_clock:
            self._process_primary_event()
        # Match the pinned event order: primary event first; then PPU phase on
        # hclock%4==0, otherwise the inverted master/4 IRQ circuit at h=2,6,...
        if (self.hclock & 3) == 0:
            # PPU rendering is V09-owned. V07 still owns the raster phase.
            pass
        elif self.hclock & 2:
            self._process_irq_counters()
        self._process_autojoy_due()
        self._update_smp_target()

    def _advance_wall(self, master_clocks: int) -> None:
        if master_clocks < 0 or (master_clocks & 1):
            raise ValueError("master clocks must be a non-negative even count")
        for _ in range(master_clocks // 2):
            self._tick2()

    def advance_cpu_master(self, master_clocks: int) -> int:
        """Advance requested CPU-owned clocks; return real elapsed wall clocks."""
        before = self.master_clock
        self._advance_wall(master_clocks)
        return self.master_clock - before

    def cpu_cycle_boundary(self) -> DmaRendezvous:
        self.cpu_cycle_count += 1
        # NMI signal is edge-owned at CPU cycle boundaries.
        if self.nmi_signal:
            self.nmi_signal = False
            self.nmi_pending = True
            self.log("NMI_CPU_PENDING")
        if self.dma_request != DmaRendezvous.NONE:
            if self.dma_start_delay > 0:
                self.dma_start_delay -= 1
            if self.dma_start_delay == 0:
                self.dma_rendezvous_ready = self.dma_request
                self.dma_request = DmaRendezvous.NONE
                self.log("DMA_RENDEZVOUS_READY", self.dma_rendezvous_ready.name)
        return self.dma_rendezvous_ready

    def consume_dma_rendezvous(self) -> DmaRendezvous:
        out = self.dma_rendezvous_ready
        self.dma_rendezvous_ready = DmaRendezvous.NONE
        return out

    def internal_cpu_cycle(self) -> int:
        self.cpu_cycle_boundary()
        return self.advance_cpu_master(6)

    def timed_read(self, clocks: int, effect) -> object:
        if clocks not in (6, 8, 12):
            raise ValueError(clocks)
        self.cpu_cycle_boundary()
        self.advance_cpu_master(clocks - 4)
        self.log("CPU_READ_EFFECT")
        value = effect()
        self.advance_cpu_master(4)
        return value

    def timed_write(self, clocks: int, effect) -> None:
        if clocks not in (6, 8, 12):
            raise ValueError(clocks)
        self.cpu_cycle_boundary()
        self.advance_cpu_master(clocks)
        self.log("CPU_WRITE_EFFECT")
        effect()

    def write_nmitimen(self, value: int) -> None:
        value &= 0xFF
        old_nmi = self.enable_nmi
        self._process_autojoy_due()
        self.enable_virq = bool(value & 0x20)
        self.enable_hirq = bool(value & 0x10)
        self.enable_autojoy = bool(value & 0x01)
        new_nmi = bool(value & 0x80)
        if self.nmi_flag and new_nmi and not old_nmi:
            # Mid-vblank enable: arm the CPU-visible edge without inventing a PC.
            self.nmi_signal = True
            self.log("NMI_ENABLE_DURING_FLAG")
        self.enable_nmi = new_nmi
        if not (self.enable_hirq or self.enable_virq):
            self.irq_flag = False
            self.irq_source = False
        self._update_irq_level()

    def write_htimer_low(self, value: int) -> None:
        self.htimer = (self.htimer & 0x100) | (value & 0xFF); self._update_irq_level()
    def write_htimer_high(self, value: int) -> None:
        self.htimer = (self.htimer & 0xFF) | ((value & 1) << 8); self._update_irq_level()
    def write_vtimer_low(self, value: int) -> None:
        self.vtimer = (self.vtimer & 0x100) | (value & 0xFF); self._update_irq_level()
    def write_vtimer_high(self, value: int) -> None:
        self.vtimer = (self.vtimer & 0xFF) | ((value & 1) << 8); self._update_irq_level()

    def read_4210(self, open_bus: int = 0) -> int:
        value = (0x80 if self.nmi_flag else 0) | 0x02 | (open_bus & 0x70)
        if self.nmi_flag and (self.hclock >= 6 or self.scanline != self.nmi_scanline):
            self.nmi_flag = False
        return value

    def read_4211(self, open_bus: int = 0) -> int:
        value = (0x80 if self.irq_flag else 0) | (open_bus & 0x7F)
        if self.irq_flag and self.need_irq == 0:
            self.irq_flag = False
            self.irq_source = False
        return value

    def read_4212(self, open_bus: int = 0) -> int:
        self._process_autojoy_due()
        return ((0x80 if self.in_vblank else 0) |
                (0x40 if self.in_hblank else 0) |
                (0x01 if self.autojoy_active else 0) |
                (open_bus & 0x3E))

    def request_manual_dma(self, mask: int) -> None:
        self.manual_dma_mask = mask & 0xFF
        if self.manual_dma_mask:
            self._queue_dma(DmaRendezvous.MANUAL)

    def set_hdma_enable(self, mask: int) -> None:
        self.hdma_enable_mask = mask & 0xFF

    def wai(self) -> None:
        self.cpu_stop = CpuStop.WAITING_FOR_INTERRUPT
        self.log("CPU_WAI")

    def stp(self) -> None:
        self.cpu_stop = CpuStop.STOPPED
        self.log("CPU_STP")

    def halted_quantum(self) -> None:
        if self.cpu_stop == CpuStop.STOPPED:
            # Global hardware continues; only S-CPU instruction execution is stopped.
            self.advance_cpu_master(4)
            return
        if self.cpu_stop == CpuStop.WAITING_FOR_INTERRUPT:
            self.internal_cpu_cycle()
            if self.nmi_pending or self.irq_source:
                self.cpu_stop = CpuStop.RUNNING
                self.log("CPU_WAI_WAKE")


def schedule_certificate() -> dict:
    return {
        "schema": 1,
        "region": "NTSC",
        "master_clock_rate": NTSC_MASTER_CLOCK,
        "spc_ratio_numerator": SPC_RATIO_NUM,
        "spc_ratio_denominator": SPC_RATIO_DEN,
        "read_effect_phase": "duration_minus_4_then_effect_then_final_4",
        "write_effect_phase": "full_duration_then_effect",
        "internal_cpu_cycle_master_clocks": 6,
        "dram_refresh_wall_clocks": DRAM_REFRESH_CLOCKS,
        "dram_refresh_start": "538-(master_clock&7) per scanline",
        "hdma_line_hclock": HDMA_LINE_HCLOCK,
        "normal_scanline_master_clocks": NORMAL_SCANLINE_CLOCKS,
        "short_scanline_master_clocks": SHORT_SCANLINE_CLOCKS,
        "vblank_start_non_overscan": 225,
        "vblank_start_overscan": 240,
        "event_tie_order": ["PRIMARY_RASTER_EVENT", "PPU_OR_IRQ_PHASE", "AUTOJOY", "S_SMP_RENDEZVOUS"],
        "gameplay_promotion_count": 0,
        "trace_promotion_count": 0,
        "oracle_promotion_count": 0,
    }
