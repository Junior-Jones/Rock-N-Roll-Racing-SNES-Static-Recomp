import unittest

from analysis.v03c_discovery import (
    State, Decoded, all_offset_scan, graph_discover, raw_apuio_candidates,
    transfer_linear,
)
from analysis.w65c816.opcodes import OPCODES, instruction_length


def profile(reset="0x8000"):
    return {"vectors": {
        "emulation_reset": reset,
        "emulation_abort": "0x0000", "emulation_cop": "0x0000",
        "emulation_nmi": "0x0000", "emulation_irq_brk": "0x0000",
        "native_abort": "0x0000", "native_brk": "0x0000", "native_cop": "0x0000",
        "native_nmi": "0x0000", "native_irq": "0x0000",
    }}


class V03CDiscoveryTests(unittest.TestCase):
    def test_all_offset_scan_covers_every_legal_width_and_bank_boundary(self):
        rom = bytearray([0xEA] * 0x8000)  # NOP
        rom[-2] = 0xA9  # LDA #imm: M-dependent length at $FFFE
        rom[-1] = 0xA9  # LDA #imm: all forms cross $FFFF
        got = all_offset_scan(bytes(rom))
        self.assertEqual(0x8000 * 5, got["rows"])
        self.assertEqual(5, got["legal_contexts_per_offset"])
        self.assertEqual(7, got["invalid_fetch_rows_at_lorom_bank_boundary"])
        self.assertEqual({"1": 163830, "2": 6, "3": 4}, got["instruction_length_histogram"])

    def test_emulation_plp_forces_width_but_invalidates_carry_provenance(self):
        s = State(0, 0x8000, 1, 1, 1, 1, 0, -1, "PROVED")
        spec = OPCODES[0x28]  # PLP
        d = Decoded(s, 0, spec, b"\x28", instruction_length(spec, 1, 1))
        nxt = transfer_linear(d)
        self.assertEqual((1, 1, 1), (nxt.e, nxt.m, nxt.x))
        self.assertEqual(-1, nxt.carry)

    def test_direct_call_target_is_proved_but_return_continuation_is_candidate(self):
        rom = bytearray([0xDB] * 0x8000)  # STP everywhere by default
        # RESET: CLC; XCE; REP #$10; JSR $8020; NOP; STP
        rom[0:9] = bytes([0x18, 0xFB, 0xC2, 0x10, 0x20, 0x20, 0x80, 0xEA, 0xDB])
        rom[0x20] = 0x60  # RTS
        roots, contexts, edges, frontiers, _roles, _graph, _extra = graph_discover(bytes(rom), profile())
        by_pc_level = {(r["PC"], r["Level"]) for r in contexts}
        self.assertIn(("8020", "PROVED"), by_pc_level)
        self.assertIn(("8007", "CANDIDATE"), by_pc_level)
        self.assertTrue(any(f["Class"] == "RETURN" and "RTS" in f["Instruction"] for f in frontiers))
        self.assertTrue(any(e["Edge_Kind"] == "RETURN_CONTINUATION_CANDIDATE" for e in edges))
        self.assertTrue(any(r["Root_Type"] == "RETURN_CONTINUATION_CANDIDATE" for r in roots))

    def test_apuio_absolute_access_requires_graph_and_known_mmio_bank_for_proof(self):
        rom = bytearray([0xDB] * 0x8000)
        # RESET architectural DBR=0, so this absolute STA is an exact MMIO address.
        rom[0:4] = bytes([0x8D, 0x40, 0x21, 0xDB])  # STA $2140; STP
        _roots, _contexts, _edges, _frontiers, _roles, graph, _extra = graph_discover(bytes(rom), profile())
        rows = raw_apuio_candidates(bytes(rom), graph)
        hit = next(r for r in rows if r["Physical"] == "000000")
        self.assertEqual("2140", hit["Register"])
        self.assertEqual("WRITE", hit["Access"])
        self.assertEqual("SOURCE_PROVED_MMIO_ADDRESS", hit["Claim"])
        self.assertEqual("00", hit["Known_DBRs"])

    def test_all_offset_operand_match_without_graph_stays_candidate_only(self):
        rom = bytearray([0xDB] * 0x8000)
        # Keep reset at $8000 as STP. Place unreachable LDA $2142 elsewhere.
        rom[0x40:0x43] = bytes([0xAD, 0x42, 0x21])
        _roots, _contexts, _edges, _frontiers, _roles, graph, _extra = graph_discover(bytes(rom), profile())
        rows = raw_apuio_candidates(bytes(rom), graph)
        hit = next(r for r in rows if r["Physical"] == "000040")
        self.assertEqual("ALL_OFFSET_ONLY", hit["Claim"])
        self.assertEqual("", hit["Graph_Levels"])


if __name__ == "__main__":
    unittest.main()
