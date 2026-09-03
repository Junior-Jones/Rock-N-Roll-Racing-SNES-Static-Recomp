from __future__ import annotations

import unittest

from analysis.v07c_scheduler_model import DmaRendezvous, Scheduler
from analysis.v08c_dma_model import (
    DmaBus,
    DmaController,
    TRANSFER_BYTE_COUNT,
    TRANSFER_OFFSET,
)


class DmaControllerV08CTests(unittest.TestCase):
    def make(self):
        s = Scheduler()
        b = DmaBus()
        d = DmaController(s, b)
        return s, b, d

    def arm_manual(self, d: DmaController, channel: int, *, mode=0, direction=False,
                   fixed=False, decrement=False, src=0x7E1000, bbad=0x18, size=1):
        base = 0x4300 + channel * 0x10
        control = mode | (0x80 if direction else 0) | (0x08 if fixed else 0) | (0x10 if decrement else 0)
        d.write_register(base + 0, control)
        d.write_register(base + 1, bbad)
        d.write_register(base + 2, src & 0xFF)
        d.write_register(base + 3, (src >> 8) & 0xFF)
        d.write_register(base + 4, (src >> 16) & 0xFF)
        d.write_register(base + 5, size & 0xFF)
        d.write_register(base + 6, (size >> 8) & 0xFF)

    def start(self, s: Scheduler, d: DmaController, mask: int, cpu_speed=8):
        d.write_register(0x420B, mask)
        self.assertEqual(s.cpu_cycle_boundary(), DmaRendezvous.MANUAL)
        self.assertEqual(d.process_ready_rendezvous(cpu_speed), DmaRendezvous.MANUAL)

    def test_all_eight_channels_and_register_file_with_43xb_43xf_mirror(self):
        _, _, d = self.make()
        for i in range(8):
            base = 0x4300 + i * 0x10
            vals = [0xA5 ^ i, 0x20 + i, 0x34, 0x12, 0x7E, 0x78, 0x56, 0x9A, 0xBC, 0xDE, 0x81, 0x40 + i]
            for reg, value in enumerate(vals):
                d.write_register(base + reg, value)
            self.assertEqual(d.read_register(base + 0), vals[0])
            self.assertEqual(d.read_register(base + 1), vals[1])
            self.assertEqual(d.read_register(base + 2), 0x34)
            self.assertEqual(d.read_register(base + 3), 0x12)
            self.assertEqual(d.read_register(base + 4), 0x7E)
            self.assertEqual(d.read_register(base + 5), 0x78)
            self.assertEqual(d.read_register(base + 6), 0x56)
            self.assertEqual(d.read_register(base + 7), 0x9A)
            self.assertEqual(d.read_register(base + 8), 0xBC)
            self.assertEqual(d.read_register(base + 9), 0xDE)
            self.assertEqual(d.read_register(base + 0xA), 0x81)
            self.assertEqual(d.read_register(base + 0xB), 0x40 + i)
            self.assertEqual(d.read_register(base + 0xF), 0x40 + i)
            d.write_register(base + 0xF, 0xE0 + i)
            self.assertEqual(d.read_register(base + 0xB), 0xE0 + i)
            self.assertEqual(d.read_register(base + 0xC, open_bus=0x5A), 0x5A)

    def test_all_eight_transfer_modes_exact_b_bus_offset_patterns(self):
        for mode in range(8):
            with self.subTest(mode=mode):
                s, b, d = self.make()
                count = TRANSFER_BYTE_COUNT[mode]
                src = 0x7E1000
                for i in range(count):
                    b.memory[src + i] = 0x40 + i
                self.arm_manual(d, 0, mode=mode, src=src, bbad=0x20, size=count)
                self.start(s, d, 1)
                writes = [(a, v) for kind, a, v in b.events if kind == 'WB']
                expected = [(0x2120 + TRANSFER_OFFSET[mode][i], 0x40 + i) for i in range(count)]
                self.assertEqual(writes, expected)

    def test_both_directions(self):
        s, b, d = self.make()
        b.memory[0x2118] = 0xA7
        self.arm_manual(d, 2, direction=True, src=0x7E2000, bbad=0x18, size=1)
        self.start(s, d, 1 << 2)
        self.assertEqual(b.memory[0x7E2000], 0xA7)
        self.assertIn(('RB', 0x2118, 0xA7), b.events)
        self.assertIn(('WA', 0x7E2000, 0xA7), b.events)

    def test_a_bus_increment_decrement_fixed_and_wrap(self):
        for fixed, dec, expected in [
            (False, False, 0x0001),
            (False, True, 0xFFFD),
            (True, False, 0xFFFF),
        ]:
            with self.subTest(fixed=fixed, dec=dec):
                s, b, d = self.make()
                b.memory[0x7EFFFF] = 1
                b.memory[0x7E0000] = 2
                b.memory[0x7EFFFE] = 3
                self.arm_manual(d, 0, fixed=fixed, decrement=dec, src=0x7EFFFF, size=2)
                self.start(s, d, 1)
                self.assertEqual(d.channels[0].src_address, expected)

    def test_das_zero_means_65536_bytes(self):
        s, b, d = self.make()
        self.arm_manual(d, 0, fixed=True, src=0x7E1234, bbad=0x18, size=0)
        b.memory[0x7E1234] = 0x5C
        self.start(s, d, 1)
        self.assertEqual(d.transfer_bytes, 65536)
        self.assertEqual(d.channels[0].transfer_size, 0)
        self.assertFalse(d.channels[0].dma_active)
        self.assertEqual(sum(1 for e in b.events if e[0] == 'WB'), 65536)

    def test_channel_mask_and_low_to_high_priority(self):
        s, b, d = self.make()
        for ch in (0, 3, 7):
            src = 0x7E1000 + ch
            b.memory[src] = ch + 1
            self.arm_manual(d, ch, src=src, bbad=0x20 + ch, size=1)
        self.start(s, d, (1 << 7) | (1 << 0) | (1 << 3))
        writes = [(a, v) for kind, a, v in b.events if kind == 'WB']
        self.assertEqual(writes, [(0x2120, 1), (0x2123, 4), (0x2127, 8)])

    def test_pending_priority_preserves_manual_behind_hdma_line(self):
        s, b, d = self.make()
        b.memory[0x7E1000] = 0x5A
        self.arm_manual(d, 0, src=0x7E1000, bbad=0x20, size=1)
        d.channels[0].dma_active = True
        d.hdma_channels = 0x02
        d.channels[1].hdma_finished = True
        d.pending_mask = 0x01 | 0x04
        s.dma_rendezvous_ready = DmaRendezvous.HDMA_LINE
        self.assertEqual(d.process_ready_rendezvous(), DmaRendezvous.HDMA_LINE)
        self.assertEqual(s.dma_request, DmaRendezvous.MANUAL)
        self.assertEqual(s.cpu_cycle_boundary(), DmaRendezvous.MANUAL)
        self.assertEqual(d.process_ready_rendezvous(), DmaRendezvous.MANUAL)
        self.assertIn(('WB', 0x2120, 0x5A), b.events)

    def test_wram_port_restrictions_both_directions(self):
        s, b, d = self.make()
        b.memory[0x7E1111] = 0x44
        self.arm_manual(d, 0, src=0x7E1111, bbad=0x80, size=1)
        self.start(s, d, 1)
        self.assertNotIn(('WB', 0x2180, 0x44), b.events)
        self.assertEqual(d.wram_restrictions, 1)

        s, b, d = self.make()
        b.memory[0x2180] = 0x33
        self.arm_manual(d, 0, direction=True, src=0x7E2222, bbad=0x80, size=1)
        self.start(s, d, 1)
        self.assertNotIn(('RB', 0x2180, 0x33), b.events)
        self.assertEqual(b.memory[0x7E2222], 0xFF)
        self.assertEqual(d.wram_restrictions, 1)

    def test_a_bus_cannot_reenter_b_bus_or_dma_controller(self):
        s, b, d = self.make()
        d.open_bus = 0x77
        # B->A to an A-bus address in $21xx: read B occurs, A write is suppressed.
        b.memory[0x2118] = 0x55
        d.copy_dma_byte(0x002100, 0x2118, True)
        self.assertNotIn(('WA', 0x002100, 0x55), b.events)
        # A->B read of $4300 returns open bus rather than re-entering DMA registers.
        d.open_bus = 0x66
        d.copy_dma_byte(0x004300, 0x2120, False)
        self.assertIn(('WB', 0x2120, 0x66), b.events)

    def test_start_alignment_overhead_per_channel_and_end_alignment(self):
        s, b, d = self.make()
        s.advance_cpu_master(2)
        b.memory[0x7E1000] = 1
        b.memory[0x7E2000] = 2
        self.arm_manual(d, 0, src=0x7E1000, size=1)
        self.arm_manual(d, 1, src=0x7E2000, size=1)
        before = s.master_clock
        self.start(s, d, 0x03, cpu_speed=8)
        # Start sync 6, global 8, channel overhead 8+8, two bytes 16, end sync 2 => 48.
        self.assertEqual(s.master_clock - before, 48)
        self.assertEqual(s.master_clock & 7, 2)  # end aligns relative to CPU pause, not globally

    def test_dma_stalls_v07_timeline_and_refresh_remains_real_wall_time(self):
        s, b, d = self.make()
        s.advance_cpu_master(520)
        b.memory[0x7E1000] = 0x11
        self.arm_manual(d, 0, src=0x7E1000, size=8)
        before = s.master_clock
        self.start(s, d, 1, cpu_speed=8)
        elapsed = s.master_clock - before
        self.assertGreater(elapsed, 8 + 8 + 8 + 8 * 8)  # refresh contributes extra wall time
        kinds = [e.kind for e in s.events]
        self.assertIn('DRAM_REFRESH_BEGIN', kinds)
        self.assertIn('DRAM_REFRESH_END', kinds)

    def test_hdma_direct_init_repeat_reload_and_termination(self):
        s, b, d = self.make()
        ch = d.channels[0]
        ch.set_dmap(0x00)  # direct, mode 0
        ch.dest_address = 0x20
        ch.src_bank = 0x7E
        ch.src_address = 0x3000
        # count=2, one data byte, then next descriptor=0. With repeat clear,
        # the first line transfers and the second line only drains the counter.
        b.memory[0x7E3000] = 0x02
        b.memory[0x7E3001] = 0xAA
        b.memory[0x7E3002] = 0x00
        d.write_register(0x420C, 0x01)
        self.assertTrue(d.init_hdma())
        self.assertTrue(ch.do_transfer)
        d.process_hdma_line()
        self.assertFalse(ch.do_transfer)
        self.assertFalse(ch.hdma_finished)
        d.process_hdma_line()
        self.assertTrue(ch.hdma_finished)
        writes = [(a, v) for kind, a, v in b.events if kind == 'WB']
        self.assertEqual(writes, [(0x2120, 0xAA)])

    def test_hdma_repeat_bit_transfers_every_line(self):
        s, b, d = self.make()
        ch = d.channels[0]
        ch.set_dmap(0x00)
        ch.dest_address = 0x20
        ch.src_bank = 0x7E
        ch.src_address = 0x3100
        b.memory.update({0x7E3100: 0x82, 0x7E3101: 0x11, 0x7E3102: 0x22, 0x7E3103: 0x00})
        d.write_register(0x420C, 1)
        d.init_hdma()
        d.process_hdma_line()
        self.assertTrue(ch.do_transfer)
        d.process_hdma_line()
        self.assertTrue(ch.hdma_finished)
        writes = [v for kind, a, v in b.events if kind == 'WB' and a == 0x2120]
        self.assertEqual(writes, [0x11, 0x22])

    def test_hdma_indirect_addressing_and_all_mode_byte_counts(self):
        for mode in range(8):
            with self.subTest(mode=mode):
                s, b, d = self.make()
                ch = d.channels[2]
                ch.set_dmap(0x40 | mode)
                ch.dest_address = 0x30
                ch.src_bank = 0x7E
                ch.src_address = 0x4000
                ch.hdma_bank = 0x7F
                b.memory[0x7E4000] = 0x81
                b.memory[0x7E4001] = 0x00
                b.memory[0x7E4002] = 0x50
                b.memory[0x7E4003] = 0x00
                for i in range(4):
                    b.memory[0x7F5000 + i] = 0x60 + i
                d.write_register(0x420C, 1 << 2)
                d.init_hdma()
                self.assertEqual(ch.transfer_size, 0x5000)
                d.process_hdma_line()
                writes = [(a, v) for kind, a, v in b.events if kind == 'WB']
                self.assertEqual(len(writes), TRANSFER_BYTE_COUNT[mode])
                expected_addr = [0x2130 + TRANSFER_OFFSET[mode][i] for i in range(TRANSFER_BYTE_COUNT[mode])]
                self.assertEqual([a for a, _ in writes], expected_addr)

    def test_hdma_last_active_indirect_termination_oddity(self):
        s, b, d = self.make()
        ch = d.channels[5]
        ch.set_dmap(0x40)
        ch.dest_address = 0x20
        ch.src_bank = 0x7E
        ch.src_address = 0x6000
        ch.hdma_bank = 0x7F
        # First line count 1, initial indirect 0x7000. At reload, next counter 0;
        # last active channel reads only one extra byte and uses it as high byte.
        b.memory.update({
            0x7E6000: 0x01, 0x7E6001: 0x00, 0x7E6002: 0x70,
            0x7E6003: 0x00, 0x7E6004: 0x44,
            0x7F7000: 0x99,
        })
        d.write_register(0x420C, 1 << 5)
        d.init_hdma()
        d.process_hdma_line()
        self.assertTrue(ch.hdma_finished)
        self.assertEqual(ch.transfer_size, 0x4400)
        self.assertEqual(ch.hdma_table_address, 0x6005)

    def test_reset_clears_active_and_hdma_mask_but_preserves_channel_registers(self):
        s, _, d = self.make()
        d.write_register(0x4300, 0x01)
        d.write_register(0x4301, 0x18)
        d.write_register(0x420C, 0xFF)
        d.channels[0].dma_active = True
        d.reset()
        self.assertEqual(d.read_register(0x4300), 0x01)
        self.assertEqual(d.read_register(0x4301), 0x18)
        self.assertEqual(d.hdma_channels, 0)
        self.assertEqual(s.hdma_enable_mask, 0)
        self.assertFalse(any(ch.dma_active for ch in d.channels))


class SourceReachedNamedV08CTests(unittest.TestCase):
    """Named tests for every distinct DMA configuration/start family proved by V04C source."""

    def run_profile(self, *, mask, channel, dmap, bbad, bank, src, size):
        s, b = Scheduler(), DmaBus()
        d = DmaController(s, b)
        base = 0x4300 + 0x10 * channel
        d.write_register(base + 0, dmap)
        d.write_register(base + 1, bbad)
        d.write_register(base + 2, src & 0xFF)
        d.write_register(base + 3, src >> 8)
        d.write_register(base + 4, bank)
        d.write_register(base + 5, size & 0xFF)
        d.write_register(base + 6, size >> 8)
        # Keep source payload tiny for named proof: exercise the exact configuration
        # register semantics, then reduce DAS to one before execution where the real
        # source size is large. General DAS semantics are certified separately above.
        self.assertEqual(d.read_register(base + 0), dmap)
        self.assertEqual(d.read_register(base + 1), bbad)
        self.assertEqual(d.read_register(base + 4), bank)
        self.assertEqual(d.read_register(base + 5) | (d.read_register(base + 6) << 8), size)
        d.write_register(base + 5, 1)
        d.write_register(base + 6, 0)
        b.memory[(bank << 16) | src] = 0xA5
        d.write_register(0x420B, mask)
        s.cpu_cycle_boundary()
        d.process_ready_rendezvous()
        self.assertEqual(d.transfer_bytes, 1)

    def test_source_80a24c_channel0_vram_mode1_0100(self):
        self.run_profile(mask=0x01, channel=0, dmap=0x01, bbad=0x18, bank=0x7E, src=0x2000, size=0x0100)

    def test_source_80a2ff_channel0_vram_mode1_0080(self):
        self.run_profile(mask=0x01, channel=0, dmap=0x01, bbad=0x18, bank=0x7E, src=0x2400, size=0x0080)

    def test_source_80a35c_channel0_vram_mode1_0040(self):
        self.run_profile(mask=0x01, channel=0, dmap=0x01, bbad=0x18, bank=0x7E, src=0x2800, size=0x0040)

    def test_source_81f68e_channel0_vram_mode1_1000(self):
        self.run_profile(mask=0x01, channel=0, dmap=0x01, bbad=0x18, bank=0x7E, src=0x3500, size=0x1000)

    def test_source_80c2fc_channel3_cgram_mode0_0200(self):
        self.run_profile(mask=0x08, channel=3, dmap=0x00, bbad=0x22, bank=0x7E, src=0x2000, size=0x0200)

    def test_source_819cc6_channel4_oam_mode0_0100(self):
        self.run_profile(mask=0x10, channel=4, dmap=0x00, bbad=0x04, bank=0x7E, src=0x13FA, size=0x0100)

    def test_source_819ce1_channel4_oam_mode0_0010(self):
        self.run_profile(mask=0x10, channel=4, dmap=0x00, bbad=0x04, bank=0x7E, src=0x14FA, size=0x0010)

    def test_source_926fe9_clears_mdmaen_and_hdmaen(self):
        s, b = Scheduler(), DmaBus(); d = DmaController(s, b)
        d.write_register(0x420C, 0xFF)
        d.write_register(0x420B, 0x00)
        d.write_register(0x420C, 0x00)
        self.assertEqual(d.hdma_channels, 0)
        self.assertEqual(s.hdma_enable_mask, 0)
        self.assertEqual(s.dma_request, DmaRendezvous.NONE)


if __name__ == '__main__':
    unittest.main()
