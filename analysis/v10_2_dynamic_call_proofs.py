"""Source-only finite proofs for Rock n' Roll Racing indirect S-CPU calls.

Every accepted target domain below is derived from exact ROM instructions.  The
tool deliberately does not consume emulator/oracle traces or the old V10.1
production manifest.  A signature mismatch is fatal so that a proof cannot be
silently reused with another ROM or after the source bytes change.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.v01c_cartridge_profile import canonical_lorom_offset
from analysis.v03c_discovery import ROM_SHA256, ROM_SIZE


def offset(bank: int, pc: int, rom_size: int) -> int:
    return canonical_lorom_offset((bank << 16) | pc, rom_size)


def read(rom: bytes, bank: int, pc: int, size: int) -> bytes:
    return bytes(rom[offset(bank, (pc + i) & 0xFFFF, len(rom))] for i in range(size))


def require(rom: bytes, bank: int, pc: int, expected_hex: str, reason: str) -> None:
    expected = bytes.fromhex(expected_hex)
    actual = read(rom, bank, pc, len(expected))
    if actual != expected:
        raise ValueError(
            f"source proof mismatch at {bank:02X}:{pc:04X} for {reason}: "
            f"expected {expected.hex().upper()}, got {actual.hex().upper()}"
        )


def table_targets(rom: bytes, bank: int, base: int, offsets: list[int]) -> list[str]:
    targets: list[str] = []
    for index in offsets:
        raw = read(rom, bank, (base + index) & 0xFFFF, 2)
        pc = raw[0] | (raw[1] << 8)
        # The indexed-indirect JSR keeps PBR.  Reject low-half/open-bus targets.
        if pc < 0x8000:
            raise ValueError(
                f"invalid LoROM call target {bank:02X}:{pc:04X} "
                f"from table {bank:02X}:{base:04X}+{index:04X}"
            )
        targets.append(f"{bank:02X}:{pc:04X}")
    return sorted(set(targets))


def build(rom: bytes) -> dict:
    digest = hashlib.sha256(rom).hexdigest()
    if len(rom) != ROM_SIZE or digest != ROM_SHA256:
        raise ValueError(f"wrong ROM identity: size={len(rom)} sha256={digest}")

    # $81:D0BA loads literal 2, stores it to $0297, reloads X from the same
    # byte and dispatches without an intervening writer.  Therefore X is 2.
    require(rom, 0x81, 0xD0BA, "A9028D9702AE9702FC05D1", "literal-$02 dispatch")

    # Both $92 dispatches load an arbitrary 16-bit word, mask it with $001F,
    # ASL once, then TAX.  The complete X domain is consequently the even set
    # $0000..$003E; no data provenance assumption is needed.
    require(rom, 0x92, 0x8B81, "BD001B291F000AAAFC CB8B".replace(" ", ""),
            "$001F-masked first tile dispatch")
    require(rom, 0x92, 0x8BA7, "BD001B291F000AAAFC0B8C",
            "$001F-masked second tile dispatch")
    mask_offsets = list(range(0, 0x40, 2))

    proofs = [
        {
            "context": "81:D0C2:E0M1X1",
            "flow_kind": "CALL",
            "table": "81:D105",
            "proved_x_offsets": [2],
            "targets": table_targets(rom, 0x81, 0xD105, [2]),
            "source_proof": [
                "81:D0BA LDA #$02",
                "81:D0BC STA $0297",
                "81:D0BF LDX $0297",
                "81:D0C2 JSR ($D105,X)",
            ],
            "proof_kind": "EXACT_LITERAL_RELOAD_CHAIN",
        },
        {
            "context": "92:8B89:E0M0X0",
            "flow_kind": "CALL",
            "table": "92:8BCB",
            "proved_x_offsets": mask_offsets,
            "targets": table_targets(rom, 0x92, 0x8BCB, mask_offsets),
            "source_proof": [
                "92:8B81 LDA $1B00,X",
                "92:8B84 AND #$001F",
                "92:8B87 ASL A",
                "92:8B88 TAX",
                "92:8B89 JSR ($8BCB,X)",
            ],
            "proof_kind": "MASK_AND_SCALE_DOMAIN",
        },
        {
            "context": "92:8BAF:E0M0X0",
            "flow_kind": "CALL",
            "table": "92:8C0B",
            "proved_x_offsets": mask_offsets,
            "targets": table_targets(rom, 0x92, 0x8C0B, mask_offsets),
            "source_proof": [
                "92:8BA7 LDA $1B00,X",
                "92:8BAA AND #$001F",
                "92:8BAD ASL A",
                "92:8BAE TAX",
                "92:8BAF JSR ($8C0B,X)",
            ],
            "proof_kind": "MASK_AND_SCALE_DOMAIN",
        },
    ]

    require(rom, 0x92, 0x8EBC, "BD001B291F000AAA7CC78E",
            "$001F-masked renderer tail dispatch")
    proofs.append({
        "context": "92:8EC4:E0M0X0",
        "flow_kind": "JUMP",
        "table": "92:8EC7",
        "proved_x_offsets": mask_offsets,
        "targets": table_targets(rom, 0x92, 0x8EC7, mask_offsets),
        "source_proof": [
            "92:8EBC LDA $1B00,X",
            "92:8EBF AND #$001F",
            "92:8EC2 ASL A",
            "92:8EC3 TAX",
            "92:8EC4 JMP ($8EC7,X)",
        ],
        "proof_kind": "MASK_AND_SCALE_DOMAIN",
    })

    # The following ROM-owned dispatch tables are source-bounded by adjacent
    # code/sentinels.  Their data producer is not reduced to one literal, so
    # production must retain both the listed index-domain guard and a fetched
    # target-set guard.  This is the same finite fail-closed form used by the
    # mature Top Gear static core; it is not a trace-based reachability claim.
    bounded_specs = [
        {
            "context": "81:B03F:E0M1X1", "flow_kind": "CALL",
            "bank": 0x81, "base": 0xB081, "offsets": list(range(2, 10, 2)),
            "signature_pc": 0xB03A, "signature": "680AAAA000FC81B0",
            "description": "$13B8 five-entry first game-state table",
        },
        {
            "context": "81:B04A:E0M1X1", "flow_kind": "CALL",
            "bank": 0x81, "base": 0xB089, "offsets": list(range(0, 10, 2)),
            "signature_pc": 0xB045, "signature": "680AAAA000FC89B0",
            "description": "$13B8 five-entry alternate game-state table",
        },
        {
            "context": "81:C3F3:E0M1X1", "flow_kind": "CALL",
            "bank": 0x81, "base": 0xC3F6, "offsets": [2, 4, 6, 8, 14],
            "signature_pc": 0xC3ED, "signature": "A00FB15A0AAAFCF6C3",
            "description": "object handler table with $FFFF sentinels at offsets $0A/$0C",
        },
        {
            "context": "81:CB46:E0M1X1", "flow_kind": "CALL",
            "bank": 0x81, "base": 0xCB54, "offsets": list(range(0, 26, 2)),
            "signature_pc": 0xCB3F, "signature": "AD9702300F0AAAFC54CB",
            "description": "$0297 nonnegative 13-state sequence table",
        },
        {
            "context": "80:A489:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x80, "base": 0xA484,
            "offsets": list(range(6, 48, 2)),
            "signature_pc": 0xA484, "signature": "AD9E0B0AAA7C84A4",
            "description": "$0B9E overlapping tail-dispatch table; non-handler prologue words excluded",
        },
        {
            "context": "92:A7C6:E0M0X0", "flow_kind": "CALL",
            "bank": 0x92, "base": 0xA7CD, "offsets": [0, 2, 4],
            "signature_pc": 0xA7AB,
            "signature": "A603BD0F1B29FF003A301BC90600B0160AAABD4BA7F00F850BA60FFCCDA7",
            "description": "three-entry collision/action table ending where continuation code begins",
        },
        {
            "context": "9F:F01B:E0M0X0", "flow_kind": "JUMP",
            "bank": 0x9F, "base": 0xF031, "offsets": list(range(0, 16, 2)),
            "signature_pc": 0xF012, "signature": "B90000C8C8AAF41DF07C31F0",
            "description": "eight-entry stream-command tail-dispatch table",
        },
        {
            "context": "81:FB31:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x81, "base": 0xFB34, "offsets": list(range(0, 12, 2)),
            "signature_pc": 0xFB1F,
            "signature": "B9FD0EF008AEFF0BE002F0011A0AAA8CB8137C34FB3EFBA8FB12FC5DFC9BFCBEA6",
            "description": (
                "six-entry player-panel tail table; the only three direct callers "
                "load Y=$00/$01/$02 and the source sequence derives an even X"
            ),
            "extra_signatures": [
                (0xF904, "A000201FFBA001201FFBA002201FFB",
                 "complete literal-Y caller sequence"),
            ],
        },
        {
            "context": "81:FD5A:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x81, "base": 0xFD5D, "offsets": list(range(0, 26, 2)),
            "signature_pc": 0xFD55,
            "signature": (
                "AD97020AAA7C5DFD80FD9FFD91FD77FD80FDB3FD91FD77FD"
                "80FDC7FD91FDDBFD7FFD"
            ),
            "description": (
                "thirteen-entry $0297 state tail table; the dispatcher loads the "
                "state byte and doubles it immediately before the indexed jump"
            ),
        },
    ]
    for spec in bounded_specs:
        require(rom, spec["bank"], spec["signature_pc"], spec["signature"], spec["description"])
        for signature_pc, signature, reason in spec.get("extra_signatures", []):
            require(rom, spec["bank"], signature_pc, signature, reason)
        proofs.append({
            "context": spec["context"],
            "flow_kind": spec["flow_kind"],
            "table": f"{spec['bank']:02X}:{spec['base']:04X}",
            "proved_x_offsets": spec["offsets"],
            "targets": table_targets(rom, spec["bank"], spec["base"], spec["offsets"]),
            "source_proof": [spec["description"], "exact adjacent ROM signature verified"],
            "proof_kind": "FINITE_ROM_TABLE_WITH_FAIL_CLOSED_INDEX_AND_TARGET_GUARDS",
            "reachability_class": "SOURCE_DERIVED_FINITE_CANDIDATE_SET",
            "production_guards_required": ["index domain", "fetched target set"],
        })

    later_bounded_specs = [
        {
            "context": "92:A2E1:E0M0X0", "flow_kind": "CALL",
            "bank": 0x92, "base": 0xA20C, "offsets": [0, 2, 4, 6],
            "signature_pc": 0xA2DD, "signature": "9005A625FC0CA2",
            "description": "four-entry secondary object geometry call table",
        },
        {
            "context": "81:9868:E0M1X1", "flow_kind": "CALL",
            "bank": 0x81, "base": 0x986D, "offsets": list(range(0, 14, 2)),
            "signature_pc": 0x9860, "signature": "C8B95C9B30290AAAFC6D98",
            "description": "seven-entry race/object action call table",
        },
        {
            "context": "92:A2DA:E0M0X0", "flow_kind": "CALL",
            "bank": 0x92, "base": 0xA200, "offsets": list(range(0, 20, 2)),
            "signature_pc": 0xA2D1, "signature": "98187D7E90850DA623FC00A2",
            "description": "ten-entry object geometry call table",
        },
        {
            "context": "92:B2AA:E0M0X0", "flow_kind": "CALL",
            "bank": 0x92, "base": 0xB2F3, "offsets": [0, 2],
            "signature_pc": 0xB29D, "signature": "BF00007F290200AABDF7B28503FCF3B2",
            "description": "bit-$0002 two-entry terrain call table",
        },
        {
            "context": "80:A8BB:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x80, "base": 0xA8BE, "offsets": list(range(0, 10, 2)),
            "signature_pc": 0xA8B5, "signature": "207FAB980AAA7CBEA8",
            "description": "five-entry first vehicle-state tail table; $AB7F proves Y=0..4",
        },
        {
            "context": "80:A975:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x80, "base": 0xA978, "offsets": list(range(0, 10, 2)),
            "signature_pc": 0xA96F, "signature": "207FAB980AAA7C78A9",
            "description": "five-entry second vehicle-state tail table; $AB7F proves Y=0..4",
        },
        {
            "context": "80:AA25:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x80, "base": 0xAA28, "offsets": list(range(0, 10, 2)),
            "signature_pc": 0xAA1F, "signature": "207FAB980AAA7C28AA",
            "description": "five-entry third vehicle-state tail table; $AB7F proves Y=0..4",
        },
        {
            "context": "80:AAD5:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x80, "base": 0xAAD8, "offsets": list(range(0, 10, 2)),
            "signature_pc": 0xAACF, "signature": "207FAB980AAA7CD8AA",
            "description": "five-entry fourth vehicle-state tail table; $AB7F proves Y=0..4",
        },
        {
            "context": "81:96B7:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x81, "base": 0x96BA, "offsets": list(range(0, 14, 2)),
            "signature_pc": 0x96AD, "signature": "209C99BD5C9B30130AAA7CBA96",
            "description": "eight-entry positive object-state tail table",
        },
        {
            "context": "81:97D1:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x81, "base": 0x97D4, "offsets": list(range(0, 14, 2)),
            "signature_pc": 0x97C6, "signature": "AC3C03209C99BD5C9B0AAA7CD497",
            "description": "eight-entry alternate object-state tail table",
        },
    ]
    for spec in later_bounded_specs:
        require(rom, spec["bank"], spec["signature_pc"], spec["signature"], spec["description"])
        proofs.append({
            "context": spec["context"],
            "flow_kind": spec["flow_kind"],
            "table": f"{spec['bank']:02X}:{spec['base']:04X}",
            "proved_x_offsets": spec["offsets"],
            "targets": table_targets(rom, spec["bank"], spec["base"], spec["offsets"]),
            "source_proof": [spec["description"], "exact adjacent ROM signature verified"],
            "proof_kind": "FINITE_ROM_TABLE_WITH_FAIL_CLOSED_INDEX_AND_TARGET_GUARDS",
            "reachability_class": "SOURCE_DERIVED_FINITE_CANDIDATE_SET",
            "production_guards_required": ["index domain", "fetched target set"],
        })

    # The two $1F47 indexed calls use X=0 and the pointer comes from a compact
    # ROM record.  The caller loads the record address as a literal; the common
    # routine consumes its count/key words and copies the following word to
    # $1F47 immediately before the call.
    require(rom, 0x92, 0xA214, "A03EA2200CA6", "first $1F47 record caller")
    require(rom, 0x92, 0xA23E, "01009C0B51A2", "first $1F47 count/key/target record")
    require(rom, 0x92, 0xA63B, "B1138D471FA20000FC471F", "first $1F47 local dispatch chain")
    proofs.append({
        "context": "92:A643:E0M0X0",
        "flow_kind": "CALL",
        "table": "92:A23E-counted-record",
        "proved_x_offsets": [0],
        "targets": ["92:A251"],
        "source_proof": [
            "92:A214 LDY #$A23E",
            "record count=1, key=$0B9C, following target=$A251",
            "92:A63B copies that target to $1F47; 92:A640 sets X=0",
        ],
        "proof_kind": "COUNTED_ROM_RECORD_POINTER",
    })

    # $92:8E31 is a source-visible synthetic call trampoline. Four entry
    # blocks load one of four literal targets, the common suffix pushes
    # continuation $8E31 and target-1, then RTS transfers to the target. The
    # target's eventual RTS resumes at $8E32.
    require(rom, 0x92, 0x8E00, "F48CA0A90500852FA9518C801B",
            "first synthetic RTS-call producer")
    require(rom, 0x92, 0x8E0D, "F43CA1A90F00852FA9F48C800E",
            "second synthetic RTS-call producer")
    require(rom, 0x92, 0x8E1A, "F4FC9FA94C8C8006",
            "third synthetic RTS-call producer")
    require(rom, 0x92, 0x8E22, "F444A0A9EF8CD40DD403F4318E3A4860",
            "fourth producer and common synthetic RTS-call suffix")
    proofs.append({
        "context": "92:8E31:E0M0X0",
        "flow_kind": "SYNTHETIC_RTS_CALL",
        "table": "literal-producers-92:8E00/8E0D/8E1A/8E22",
        "proved_x_offsets": [],
        "targets": ["92:8C4C", "92:8C51", "92:8CEF", "92:8CF4"],
        "continuation": "92:8E32",
        "source_proof": [
            "four exact literal target producers",
            "92:8E2C PEA $8E31",
            "92:8E2F DEC A; 92:8E30 PHA; 92:8E31 RTS",
        ],
        "proof_kind": "SYNTHETIC_RTS_CALL_LITERAL_DOMAIN",
    })

    for proof in proofs:
        if proof["context"] == "9F:F01B:E0M0X0":
            proof["synthetic_return_continuation"] = "9F:F01E"
            proof["source_proof"].append("9F:F018 PEA $F01D creates handler RTS continuation $F01E")
            break
    require(rom, 0x92, 0xD971, "A091D92067A6", "second $1F47 record caller")
    require(rom, 0x92, 0xD991,
            "04000000000000000000ABD904000040004000400040C2D9",
            "complete pair of $1F47 count/key/target records")
    require(rom, 0x92, 0xA696, "B1138D471FA20000FC471F", "second $1F47 local dispatch chain")
    proofs.append({
        "context": "92:A69E:E0M0X0",
        "flow_kind": "CALL",
        "table": "92:D991/D99D-counted-records",
        "proved_x_offsets": [0],
        "targets": ["92:D9AB", "92:D9C2"],
        "source_proof": [
            "92:D971 LDY #$D991",
            "first record count=4, four $0000 keys, following target=$D9AB",
            "second record count=4, four $4000 keys, following target=$D9C2",
            "92:A696 copies that target to $1F47; 92:A69B sets X=0",
        ],
        "proof_kind": "COUNTED_ROM_RECORD_POINTER",
    })

    # $92:A22A reloads the pointer it has just fetched from the seven-word ROM
    # table. Entry zero is explicitly rejected by BEQ; the six nonzero words
    # are therefore the complete finite target candidates for the local jump.
    require(rom, 0x92, 0xA21A, "AD441F29FF000AAABD2EA2F0068D471F6C471F",
            "$1F47 local ROM-table pointer jump")
    proofs.append({
        "context": "92:A22A:E0M0X0",
        "flow_kind": "JUMP",
        "table": "92:A22E",
        "proved_x_offsets": list(range(2, 14, 2)),
        "targets": table_targets(rom, 0x92, 0xA22E, list(range(2, 14, 2))),
        "source_proof": [
            "92:A222 LDA $A22E,X",
            "92:A225 BEQ rejects the zero entry",
            "92:A227 STA $1F47",
            "92:A22A JMP ($1F47)",
        ],
        "proof_kind": "LOCAL_ROM_TABLE_POINTER_WITH_FAIL_CLOSED_TARGET_GUARD",
        "reachability_class": "SOURCE_DERIVED_FINITE_CANDIDATE_SET",
        "production_guards_required": ["fetched target set"],
    })

    require(rom, 0x92, 0xA7D9, "BD001B291F000AAA FCE5A7".replace(" ", ""),
            "$001F-masked object dispatch")
    proofs.append({
        "context": "92:A7E1:E0M0X0",
        "flow_kind": "CALL",
        "table": "92:A7E5",
        "proved_x_offsets": mask_offsets,
        "targets": table_targets(rom, 0x92, 0xA7E5, mask_offsets),
        "source_proof": [
            "92:A7D9 LDA $1B00,X",
            "92:A7DC AND #$001F",
            "92:A7DF ASL A",
            "92:A7E0 TAX",
            "92:A7E1 JSR ($A7E5,X)",
        ],
        "proof_kind": "MASK_AND_SCALE_DOMAIN",
    })

    # $92:A296 walks four-byte ROM records and calls $A2AC after pushing Y and
    # both record words.  $A2EB is a deliberate stack rewrite, not an ordinary
    # data pull: it pulls the $A2A1 JSR return, stores that return over the
    # lower record word with STA $03,S, discards the upper word, and RTSes back
    # to $A2A4.  Preserve this exact source-visible transformation so the
    # RESET-forward analyser does not mistake it for a missing PHA.
    require(rom, 0x92, 0xA296, "B90000F0105A48B902004820ACA27AC8C8C8C880EB60",
            "four-byte record walker and $A2AC call")
    require(rom, 0x92, 0xA2E4, "A3033A8303D0C16883036860",
            "$A2EB stack-return rewrite suffix")
    proofs.append({
        "context": "92:A2EB:E0M0X0",
        "flow_kind": "STACK_RETURN_REWRITE",
        "table": "none-exact-stack-sequence",
        "proved_x_offsets": [],
        "targets": [],
        "source_proof": [
            "92:A29B PHY; A29C PHA; A2A0 PHA; A2A1 JSR $A2AC",
            "92:A2EB PLA pulls the exact $A2A1 JSR return",
            "92:A2EC STA $03,S replaces the lower record word with that return",
            "92:A2EE PLA discards the upper record word; A2EF RTS resumes at A2A4",
        ],
        "proof_kind": "EXACT_STACK_RETURN_REWRITE_SEQUENCE",
    })

    # The four-word self-check failure/sabotage branch deliberately abandons a
    # JSR stack through a JML into an RTL wrapper.  Following the resulting
    # cross-frame bytes lands in mirrored non-code data and stop opcodes.  It is
    # an exact terminal cartridge path, not a callable code root.
    require(rom, 0x81, 0xBE12,
            "ADC413C9DBB7D049ADC613C96BA7D041ADC813C9C453D039ADCA13C9F04DD031",
            "four-word self-check terminal guard")
    require(rom, 0x81, 0xBE32,
            "E2309C1C03A9068D9C028D6F02A9018DFF0BA91E8DA802A9058D99029C9A02A9028D3603A9008D550322EAA3805C69C881",
            "self-check failure state setup and nonlocal JML")
    require(rom, 0x81, 0xC869, "8B4BAB2071C8AB6B",
            "JML destination RTL wrapper")
    proofs.append({
        "context": "81:BE5F:E0M1X1",
        "flow_kind": "TERMINAL_PATH",
        "table": "none-exact-self-check-sequence",
        "proved_x_offsets": [],
        "targets": [],
        "source_proof": [
            "81:BE12-BE30 compares four generated words with exact sentinels",
            "81:BE32-BE5B sets terminal state and calls the final notification routine",
            "81:BE5F JML $81:C869 reaches an RTL wrapper without a matching long-call frame",
            "the resulting cross-frame execution maps to mirrored non-code bytes and hardware stop instructions",
        ],
        "proof_kind": "EXACT_SELF_CHECK_TERMINAL_PATH",
        "terminal_reason": "cartridge self-check sabotage path",
    })

    # The second 64-object pass loads $0D from the exact $91B8 word table.
    # Every possible first-pass handler either returns immediately or preserves
    # $0D with PEI/PLA around its work.  The two negative object guards in
    # $A777/$A77C intentionally RTS through the saved $0D value; all 64 possible
    # destinations are in bank $92 below $8000 and therefore are not cartridge
    # ROM.  This is the game's invalid-object terminal route, not undiscovered
    # executable ROM.
    require(rom, 0x92, 0x8B95,
            "A200008601BDB891850DA5010A0A0A8503AABD001B291F000AAAFC0B8C20D2A7A601E8E8E0800090DA2014A2",
            "second object pass $0D producer and handlers")
    require(rom, 0x92, 0x8C0B,
            "4B8C4B8CC78FCF8F4B8C4B8C4B8C4B8CD78FDF8F4B8C4B8CD78FD78FDF8FDF8FDF8FD78FDF8FD78FE78F4B8C4B8C4B8C4B8C4B8C4B8C4B8C4B8C4B8C4B8C4B8C",
            "second-pass finite handler table")
    require(rom, 0x92, 0x8FC7,
            "A28801A9349F8036A27E01A9989F802EA2BC00A9F6A18026A2D400A9ECA1801E",
            "four preserving handler prologues")
    require(rom, 0x92, 0x8FE7,
            "A603BD031B48BD051B9D031BD40D20D78F68850D20DF8FA603689D031B60",
            "nested preserving handler")
    require(rom, 0x92, 0x9005,
            "D40D850B860FA603BD031B29FF000AA8A50D18650F38F97E90850DB20B8505A00200B10B8509C8C8AAF01DA60DA5058507B10B20CC8DE8E8C607D0F5A50D1869C000850DC609D0E368850D60",
            "PEI/PLA $0D preserving common handler")
    require(rom, 0x92, 0xA777,
            "A957A78003A967A7D40D850BA603BD061B29FF000AA8BD0E1B3A303E2903000A0AAAA50D38F97E90189B710B850DC8C8B10B850FA603BD0F1B29FF003A301BC90600B0160AAABD4BA7F00F850BA60FFCCDA768850D6050A47EA460",
            "invalid-object guard and saved-$0D RTS")
    object_handler_targets = set(table_targets(rom, 0x92, 0x8C0B, list(range(0, 64, 2))))
    expected_object_handlers = {
        "92:8C4B", "92:8FC7", "92:8FCF", "92:8FD7", "92:8FDF", "92:8FE7",
    }
    if object_handler_targets != expected_object_handlers:
        raise ValueError(f"unexpected second-pass handler domain: {sorted(object_handler_targets)}")
    object_pointer_values = []
    for index in range(0, 128, 2):
        raw = read(rom, 0x92, 0x91B8 + index, 2)
        object_pointer_values.append(raw[0] | (raw[1] << 8))
    invalid_rts_targets = [f"92:{(value + 1) & 0xFFFF:04X}"
                           for value in object_pointer_values]
    if any(int(target[3:7], 16) >= 0x8000 for target in invalid_rts_targets):
        raise ValueError("invalid-object RTS unexpectedly reaches cartridge ROM")
    proofs.append({
        "context": "92:A7D1:E0M0X0",
        "flow_kind": "TERMINAL_PATH",
        "table": "92:91B8-9237",
        "proved_x_offsets": list(range(0, 128, 2)),
        "targets": [],
        "non_rom_rts_targets": invalid_rts_targets,
        "source_proof": [
            "92:8B95 initializes X=0 and the loop advances X by two to $0080",
            "92:8B9A loads $0D from the complete 64-word $91B8 table",
            "the finite $8C0B handler domain returns directly or preserves $0D with PEI/PLA",
            "92:A77F PEI $0D saves that word above the ordinary JSR return",
            "92:A791/A7B4 negative object guards branch to A7D1 RTS through the saved word",
            "all resulting bank-$92 PCs are below $8000 and are not cartridge ROM",
        ],
        "proof_kind": "FINITE_NON_ROM_INVALID_OBJECT_RTS_DOMAIN",
        "terminal_reason": "invalid object descriptor route leaves cartridge ROM",
    })

    # $9F:F588 is a long-jump state handler that saves DBR with PHB.  Its
    # zero-$0336 guard jumps into the local $F610 subroutine instead of calling
    # it.  $F610 ends in RTS, so that path consumes the one-byte saved DBR as
    # part of a return address.  The nonzero path is the valid state route; the
    # zero path is an exact fail-stop guard and must not seed arbitrary code.
    require(rom, 0x9F, 0xF588, "8B4BABC230AD360329FF00D0034C10F6",
            "zero-state fail-stop jump into local RTS routine")
    require(rom, 0x9F, 0xF610,
            "20E5F6AD360329FF00F021A9AB002028FDA9AC002028FDA9AD002028FDA9AE002028FDE23022EAA380C23060",
            "local $F610 subroutine through final RTS")
    proofs.append({
        "context": "9F:F595:E0M0X0",
        "flow_kind": "TERMINAL_PATH",
        "table": "none-exact-zero-state-guard",
        "proved_x_offsets": [],
        "targets": [],
        "source_proof": [
            "81:C6D3 JML $9F:F588 enters with an existing long-return frame",
            "9F:F588 PHB saves DBR above that frame",
            "9F:F58D-F595 tests $0336 and jumps to $F610 only for zero",
            "$F610 is a local RTS subroutine and cannot consume the one-byte DBR save as a valid return",
        ],
        "proof_kind": "EXACT_ZERO_STATE_FAIL_STOP_PATH",
        "terminal_reason": "invalid zero state violates the long-jump handler stack contract",
    })

    # $80:FEC2 classifies a signed delta into exactly three classes. X starts
    # at zero and each of the two passed thresholds can increment it by two,
    # so both following indexed calls have the complete domain {0,2,4}.
    require(rom, 0x80, 0xFDED,
            "AE810BAC7F0B20C2FEAD6D0BAC6E0BFC00FFAE820BAC800B20C2FEAD6E0BAC6D0BFC00FF",
            "two finite $FF00 indexed-call sites")
    require(rom, 0x80, 0xFEC2,
            "9C7C0B9C7D0B8A1003CE7C0B8D7E0B981003CE7D0B38ED7E0BA8AD7D0BA200ED7C0B300DC0089008E8E8C01E9002E8E860C0F8B0FBE8E8C0E2B0F5E8E860",
            "three-class X producer")
    require(rom, 0x80, 0xFF00, "5CFE69FE77FE", "three-entry $FF00 call table")
    finite_ff00_targets = table_targets(rom, 0x80, 0xFF00, [0, 2, 4])
    for context in ("80:FDFC:E0M1X1", "80:FE0E:E0M1X1"):
        proofs.append({
            "context": context,
            "flow_kind": "CALL",
            "table": "80:FF00",
            "proved_x_offsets": [0, 2, 4],
            "targets": finite_ff00_targets,
            "source_proof": [
                "80:FEC2 initializes X=0",
                "two source-visible threshold regions can each INX twice",
                "all branches therefore return X in the exact set {0,2,4}",
                "the caller stores no new X value before JSR ($FF00,X)",
            ],
            "proof_kind": "THREE_CLASS_SOURCE_BRANCH_DOMAIN",
        })

    # $81:808B implements a two-stage RTS call.  The 24-slot loop pushes a
    # continuation with PEA $809A, loads a handler word from WRAM $0F41,X,
    # decrements/pushes it, and executes RTS at $809B.  Every writer of that
    # WRAM handler table is source-visible and stores one of the literals
    # below.  The handler's own RTS returns through the PEA to $809B; the same
    # instruction then performs the ordinary JSR return to $8083.
    require(rom, 0x81, 0x806D,
            "8B4BABC230A01800A2FEFFE8E8BD110FF0055A208B807A88D0F1E230AB6B8E57128A0A8D5912F49A80BD410F3A4860",
            "24-slot synthetic RTS caller")
    require(rom, 0x80, 0x93F4, "A99A8220CC95", "literal handler $829A producer")
    require(rom, 0x80, 0x9484, "A9DF8220CC95", "literal handler $82DF producer")
    require(rom, 0x80, 0x94F1, "A9268520CC95", "literal handler $8526 producer")
    require(rom, 0x80, 0x9581, "A9E58520CC95", "literal handler $85E5 producer")
    require(rom, 0x80, 0x95CC, "EE0F0F9D410F", "generic literal handler store")
    direct_handler_writers = [
        (0x80, 0x9FBF, 0x8905), (0x80, 0xBB8F, 0x8768),
        (0x81, 0x82A0, 0x82A7), (0x81, 0x82C0, 0x82C7),
        (0x81, 0x82E5, 0x82EC), (0x81, 0x8305, 0x830C),
        (0x81, 0x834F, 0x8356), (0x81, 0x852C, 0x8533),
        (0x81, 0x854F, 0x8556), (0x81, 0x8585, 0x86D5),
        (0x81, 0x85EB, 0x85F2), (0x81, 0x860E, 0x8615),
        (0x81, 0x8657, 0x85EB), (0x81, 0x86ED, 0x86F4),
        (0x81, 0x8716, 0x871D), (0x81, 0x871D, 0x8724),
        (0x81, 0x8724, 0x872B), (0x81, 0x8731, 0x8738),
        (0x81, 0x8738, 0x873F), (0x81, 0x873F, 0x8746),
        (0x81, 0x874C, 0x8753), (0x81, 0x8753, 0x875A),
        (0x81, 0x875A, 0x8761), (0x81, 0x876E, 0x8775),
        (0x81, 0x8778, 0x877F), (0x81, 0x8782, 0x8789),
        (0x81, 0x8792, 0x8799), (0x81, 0x879C, 0x87A3),
        (0x81, 0x87A6, 0x87AD), (0x81, 0x87B6, 0x87BD),
        (0x81, 0x87C0, 0x87C7), (0x81, 0x87CA, 0x87D1),
        (0x81, 0x8807, 0x880E), (0x81, 0x8814, 0x881B),
        (0x81, 0x8821, 0x8828), (0x81, 0x882E, 0x8835),
        (0x81, 0x883B, 0x8842), (0x81, 0x8875, 0x887C),
        (0x81, 0x8882, 0x8889), (0x81, 0x888F, 0x8896),
        (0x81, 0x88AD, 0x88DC), (0x81, 0x88E1, 0x88E8),
        (0x81, 0x890B, 0x8912), (0x81, 0x89B6, 0x87F5),
        (0x81, 0x8A92, 0x8ABA), (0x81, 0x8B11, 0x8B18),
        (0x81, 0x8B20, 0x8B27), (0x81, 0x8C02, 0x8C5B),
        (0x81, 0x8C5E, 0x8C65),
    ]
    for bank, pc, value in direct_handler_writers:
        require(rom, bank, pc,
                f"A9{value & 0xFF:02X}{value >> 8:02X}9D410F",
                f"literal handler ${value:04X} store")
    handler_targets = {0x829A, 0x82DF, 0x8526, 0x85E5}
    handler_targets.update(value for _, _, value in direct_handler_writers)
    proofs.append({
        "context": "81:809B:E0M0X0",
        "flow_kind": "SYNTHETIC_RTS_CALL",
        "table": "WRAM 81:0F41-0F70 with complete source-writer proof",
        "proved_x_offsets": list(range(0, 48, 2)),
        "targets": [f"81:{value:04X}" for value in sorted(handler_targets)],
        "continuation": "81:809B",
        "source_proof": [
            "81:8072 LDY #$0018 and 81:8075 LDX #$FFFE bound the loop to 24 even slots",
            "81:807D BEQ rejects inactive zero slots",
            "81:8093 PEA $809A creates the handler-return continuation $809B",
            "81:8096 loads the WRAM handler word; DEC/PHA/RTS calls that exact address",
            "all 49 direct literal stores and all four generic-call literals are enumerated",
        ],
        "proof_kind": "FINITE_WRAM_HANDLER_WRITER_DOMAIN",
    })

    # Recompute after appending the independently verified later sites.
    unique_targets = {target for proof in proofs for target in proof["targets"]}
    return {
        "schema": "RRR_V10_2_DYNAMIC_CALL_PROOFS_V1",
        "rom": {"size": len(rom), "sha256": digest},
        "authority_policy": {
            "source_bytes_only": True,
            "oracle_promotions": 0,
            "trace_promotions": 0,
            "unknown_domains_fail_closed": True,
        },
        "proofs": proofs,
        "summary": {
            "proved_call_sites": len(proofs),
            "unique_targets": len(unique_targets),
        },
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument(
        "--out",
        type=Path,
        default=ROOT / "generated/current/v10_2/V10.2-DYNAMIC-CALL-PROOFS.json",
    )
    args = parser.parse_args()
    report = build(args.rom.read_bytes())
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps({"path": str(args.out), "summary": report["summary"]}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
