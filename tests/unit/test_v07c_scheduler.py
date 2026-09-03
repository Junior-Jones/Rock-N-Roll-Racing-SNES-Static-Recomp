from __future__ import annotations

import unittest

from analysis.v07c_scheduler_model import (
    CpuStop,
    DmaRendezvous,
    NORMAL_SCANLINE_CLOCKS,
    SHORT_SCANLINE_CLOCKS,
    Scheduler,
    SPC_RATIO_DEN,
    SPC_RATIO_NUM,
)


class SchedulerV07CTests(unittest.TestCase):
    def test_monotonic_timeline_and_cpu_reset_does_not_rewind(self):
        s = Scheduler()
        s.advance_cpu_master(200)
        before = (s.master_clock, s.hclock, s.scanline, s.field_odd, s.frame_number)
        s.enable_nmi = True
        s.enable_hirq = True
        s.hdma_enable_mask = 0xFF
        s.reset_cpu_side()
        self.assertEqual(before, (s.master_clock, s.hclock, s.scanline, s.field_odd, s.frame_number))
        self.assertFalse(s.enable_nmi)
        self.assertFalse(s.enable_hirq)
        self.assertEqual(s.hdma_enable_mask, 0)
        self.assertEqual(s.cpu_stop, CpuStop.RUNNING)

    def test_read_and_write_effect_phases(self):
        s = Scheduler()
        read_effect_clock = []
        value = s.timed_read(8, lambda: read_effect_clock.append(s.master_clock) or 0x5A)
        self.assertEqual(value, 0x5A)
        self.assertEqual(read_effect_clock, [4])
        self.assertEqual(s.master_clock, 8)
        write_effect_clock = []
        s.timed_write(12, lambda: write_effect_clock.append(s.master_clock))
        self.assertEqual(write_effect_clock, [20])
        self.assertEqual(s.master_clock, 20)
        self.assertEqual(s.cpu_cycle_count, 2)

    def test_refresh_consumes_wall_time_inside_cpu_access(self):
        s = Scheduler()
        s.advance_cpu_master(532)
        self.assertEqual((s.master_clock, s.hclock), (532, 532))
        effect_clock = []
        before = s.master_clock
        s.timed_read(8, lambda: effect_clock.append(s.master_clock) or 0)
        self.assertEqual(effect_clock, [536])
        self.assertEqual(s.master_clock - before, 48)
        self.assertEqual(s.hclock, 580)
        kinds = [e.kind for e in s.events]
        self.assertIn("DRAM_REFRESH_BEGIN", kinds)
        self.assertIn("DRAM_REFRESH_END", kinds)

    def test_normal_short_and_interlace_line_lengths(self):
        s = Scheduler()
        s.advance_cpu_master(NORMAL_SCANLINE_CLOCKS)
        line_end = next(e for e in s.events if e.kind == "SCANLINE_END")
        self.assertEqual(line_end.master_clock, NORMAL_SCANLINE_CLOCKS)
        self.assertEqual(s.scanline, 1)
        # 40 CPU-requested clocks remain after refresh consumed 40 wall clocks.
        self.assertEqual(s.hclock, 40)
        self.assertEqual(s.master_clock, NORMAL_SCANLINE_CLOCKS + 40)

        # Isolate the documented non-interlace odd-field short line.
        s = Scheduler()
        s.field_odd = 1
        s.scanline = 240
        s.hclock = 0
        s.master_clock = 0
        s.dram_refresh_position = 538
        s.next_primary_clock = 538
        from analysis.v07c_scheduler_model import PrimaryEvent
        s.next_primary_event = PrimaryEvent.DRAM_REFRESH
        s.advance_cpu_master(SHORT_SCANLINE_CLOCKS)
        line_end = next(e for e in s.events if e.kind == "SCANLINE_END")
        self.assertEqual(line_end.master_clock, SHORT_SCANLINE_CLOCKS)
        self.assertEqual(s.scanline, 241)
        self.assertEqual(s.hclock, 40)
        self.assertEqual(s.master_clock, SHORT_SCANLINE_CLOCKS + 40)

        s = Scheduler(interlace=True)
        self.assertEqual(s.last_scanline, 262)
        s.field_odd = 1
        self.assertEqual(s.last_scanline, 261)

    def test_nmi_flag_signal_and_4210_forced_set_window(self):
        from analysis.v07c_scheduler_model import PrimaryEvent
        s = Scheduler()
        s.enable_nmi = True
        s.scanline = s.nmi_scanline
        s.hclock = 0
        s.master_clock = 0
        s.next_primary_event = PrimaryEvent.DRAM_REFRESH
        s.next_primary_clock = 538
        s.advance_cpu_master(2)
        self.assertTrue(s.nmi_flag)
        self.assertEqual(s.read_4210(0) & 0x80, 0x80)
        self.assertTrue(s.nmi_flag)  # forced-set H=2..5
        s.advance_cpu_master(4)
        self.assertTrue(s.nmi_signal)
        s.cpu_cycle_boundary()
        self.assertTrue(s.nmi_pending)
        self.assertFalse(s.nmi_signal)
        self.assertEqual(s.read_4210(0) & 0x80, 0x80)
        self.assertFalse(s.nmi_flag)

    def test_hirq_delay_and_4211_ack(self):
        s = Scheduler()
        # Select H=1. After the hcounter reset sequence it matches at the first
        # post-reset counting tick; the model must delay IRQ flag/source assertion.
        s.htimer = 1
        s.enable_hirq = True
        s._update_irq_level()
        for _ in range(20):
            s.advance_cpu_master(2)
            if s.irq_source:
                break
        self.assertTrue(s.irq_flag)
        self.assertTrue(s.irq_source)
        val = s.read_4211(0x55)
        self.assertTrue(val & 0x80)
        self.assertFalse(s.irq_flag)
        self.assertFalse(s.irq_source)

    def test_autojoy_timing_busy_and_completion(self):
        s = Scheduler()
        s.enable_autojoy = True
        s._set_autojoy_clock()
        start = s.autojoy_clock_start
        self.assertGreaterEqual(start, 0)
        if s.master_clock < start:
            s.advance_cpu_master(start - s.master_clock)
        self.assertTrue(s.autojoy_strobe)
        s.advance_cpu_master(128)
        self.assertTrue(s.autojoy_active)
        self.assertEqual(s.read_4212(0) & 1, 1)
        s.advance_cpu_master(128 * 33)
        self.assertFalse(s.autojoy_active)
        self.assertFalse(s.autojoy_strobe)
        self.assertTrue(s.autojoy_disabled)
        self.assertEqual(s.autojoy_step, 34)

    def test_dma_one_cpu_boundary_admission_and_hdma_boundary(self):
        s = Scheduler()
        s.request_manual_dma(0x01)
        self.assertEqual(s.dma_request, DmaRendezvous.MANUAL)
        # Request exists before a CPU boundary; admission happens at the next boundary.
        self.assertEqual(s.cpu_cycle_boundary(), DmaRendezvous.MANUAL)
        self.assertEqual(s.consume_dma_rendezvous(), DmaRendezvous.MANUAL)
        self.assertEqual(s.consume_dma_rendezvous(), DmaRendezvous.NONE)

        from analysis.v07c_scheduler_model import PrimaryEvent
        s = Scheduler()
        s.hdma_enable_mask = 1
        s.next_primary_event = PrimaryEvent.HDMA_LINE
        s.next_primary_clock = 2
        s.advance_cpu_master(2)
        self.assertEqual(s.dma_request, DmaRendezvous.HDMA_LINE)
        self.assertEqual(s.cpu_cycle_boundary(), DmaRendezvous.HDMA_LINE)

    def test_smp_rational_target_is_exact_and_monotonic(self):
        s = Scheduler()
        prev = s.smp_target_cycle
        for delta in (2, 6, 8, 12, 1000, 1364):
            s.advance_cpu_master(delta)
            q, r = divmod(s.master_clock * SPC_RATIO_NUM, SPC_RATIO_DEN)
            self.assertEqual((s.smp_target_cycle, s.smp_target_remainder), (q, r))
            self.assertGreaterEqual(s.smp_target_cycle, prev)
            prev = s.smp_target_cycle

    def test_wai_wakes_but_stp_only_advances_global_time(self):
        s = Scheduler()
        s.wai()
        self.assertEqual(s.cpu_stop, CpuStop.WAITING_FOR_INTERRUPT)
        before = s.master_clock
        s.halted_quantum()
        self.assertEqual(s.master_clock - before, 6)
        self.assertEqual(s.cpu_stop, CpuStop.WAITING_FOR_INTERRUPT)
        s.irq_source = True
        s.halted_quantum()
        self.assertEqual(s.cpu_stop, CpuStop.RUNNING)

        s.stp()
        before = s.master_clock
        cycles = s.cpu_cycle_count
        s.halted_quantum()
        self.assertEqual(s.master_clock - before, 4)
        self.assertEqual(s.cpu_cycle_count, cycles)
        self.assertEqual(s.cpu_stop, CpuStop.STOPPED)


if __name__ == '__main__':
    unittest.main()
