import csv
import hashlib
import importlib.util
import json
import os
import tempfile
import unittest
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ANALYZER = ROOT / "analysis" / "v01c_cartridge_profile.py"
ROM = Path(os.environ.get("JS_V01C_TEST_ROM", str(ROOT.parent / "00_inputs" / "Rock n' Roll Racing (USA).sfc")))
spec = importlib.util.spec_from_file_location("v01c", ANALYZER)
v01c = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = v01c
assert spec.loader is not None
spec.loader.exec_module(v01c)


class V01CProfileTests(unittest.TestCase):
    def test_exact_identity_and_header(self):
        profile, evidence, rows, summary = v01c.build_outputs(ROM)
        self.assertEqual(profile["rom"]["canonical_sha256"], v01c.EXPECTED_CANONICAL_SHA256)
        self.assertEqual(profile["rom"]["canonical_size_bytes"], 1_048_576)
        self.assertEqual(profile["rom"]["copier_header_bytes"], 0)
        self.assertEqual(profile["cartridge"]["mapping"], "LoROM")
        self.assertEqual(profile["cartridge"]["speed"], "FastROM")
        self.assertEqual(profile["cartridge"]["sram_bytes"], 0)
        self.assertEqual(profile["cartridge"]["enhancement_hardware"], [])
        self.assertEqual(profile["vectors"]["emulation_reset"], "0x8000")
        self.assertTrue(profile["internal_header"]["checksum_pair_valid"])
        self.assertTrue(profile["internal_header"]["checksum_matches_canonical_byte_sum"])
        self.assertGreaterEqual(evidence["selection_margin"], 6)
        self.assertEqual(summary["total_bytes"], 1_048_576)
        self.assertEqual(summary["classification_totals"]["HEADER_VECTOR"], 64)
        self.assertEqual(summary["classification_totals"]["UNRESOLVED"], 1_048_512)

    def test_canonical_lorom_mapping_and_fail_closed_invalids(self):
        size = 1_048_576
        self.assertEqual(v01c.canonical_lorom_offset(0x008000, size), 0x000000)
        self.assertEqual(v01c.canonical_lorom_offset(0x00FFFC, size), 0x007FFC)
        self.assertEqual(v01c.canonical_lorom_offset(0x1FFFFF, size), 0x0FFFFF)
        self.assertEqual(v01c.canonical_lorom_offset(0x808000, size), 0x000000)
        with self.assertRaises(ValueError):
            v01c.canonical_lorom_offset(0x007FFF, size)
        with self.assertRaises(ValueError):
            v01c.canonical_lorom_offset(0x208000, size)
        with self.assertRaises(ValueError):
            v01c.canonical_lorom_offset(0x7E8000, size)
        with self.assertRaises(ValueError):
            v01c.canonical_lorom_offset(0x1000000, size)

    def test_census_has_no_gap_overlap_or_unclassified_byte(self):
        _, _, rows, summary = v01c.build_outputs(ROM)
        totals = v01c.validate_census(rows, summary["total_bytes"])
        self.assertEqual(sum(totals.values()), summary["total_bytes"])
        self.assertNotIn("", totals)

    def test_second_generation_is_byte_identical(self):
        with tempfile.TemporaryDirectory() as a, tempfile.TemporaryDirectory() as b:
            for root in (Path(a), Path(b)):
                profile, evidence, rows, summary = v01c.build_outputs(ROM)
                v01c.write_json(root / "config/target-profile.json", profile)
                v01c.write_json(root / "docs/V01C-cartridge-evidence.json", evidence)
                v01c.write_census(root / "config/byte-ownership.csv", rows)
                v01c.write_json(root / "docs/V01C-byte-census-summary.json", summary)
            rels = [
                Path("config/target-profile.json"),
                Path("docs/V01C-cartridge-evidence.json"),
                Path("config/byte-ownership.csv"),
                Path("docs/V01C-byte-census-summary.json"),
            ]
            for rel in rels:
                ba = (Path(a) / rel).read_bytes()
                bb = (Path(b) / rel).read_bytes()
                self.assertEqual(hashlib.sha256(ba).digest(), hashlib.sha256(bb).digest(), str(rel))

    def test_wrong_rom_fails_identity(self):
        data = bytearray(ROM.read_bytes())
        data[0] ^= 1
        with tempfile.TemporaryDirectory() as td:
            p = Path(td) / "wrong.sfc"
            p.write_bytes(data)
            with self.assertRaisesRegex(ValueError, "unsupported ROM SHA-256"):
                v01c.build_outputs(p)


if __name__ == "__main__":
    unittest.main()
