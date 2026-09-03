#!/usr/bin/env python3
"""Losslessly compact the generated Rock n' Roll Racing S-CPU authority.

The input is the ordinary V10.2 exact-context C output.  Every case body is
parsed, normalized, reconstructed through a compile-time semantic template,
and checked byte-for-byte before compact records are emitted.  Runtime lookup
still uses the exact packed PBR:PC:E:M:X key and unknown keys still fail closed.
No ROM opcode decoding, learning, interpreter, or historical fallback is added.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
EXPECTED_CONTEXTS = 24835
EXPECTED_ROM_SHA256 = (
    "9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182"
)
CASE_RE = re.compile(r"(?m)^\s*case\s+(0x[0-9A-Fa-f]{8}u):\s*\{")
NUMERIC_LITERAL_RE = re.compile(
    r"0x[0-9A-Fa-f]+[uUlL]*|(?<![A-Za-z_])\d+[uUlL]*"
)


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def sha256_path(path: Path) -> str:
    return sha256_bytes(path.read_bytes())


def closing_brace(text: str, opening: int) -> int:
    depth = 0
    for index in range(opening, len(text)):
        if text[index] == "{":
            depth += 1
        elif text[index] == "}":
            depth -= 1
            if depth == 0:
                return index
    raise RuntimeError("unbalanced exact-context case body")


def normalize_body(body: str) -> str:
    lines = body.replace("\r\n", "\n").splitlines()
    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()
    nonempty = [len(line) - len(line.lstrip()) for line in lines if line.strip()]
    indent = min(nonempty, default=0)
    body = "\n".join(line[indent:].rstrip() for line in lines)
    # Template parameters cannot initialize function-static arrays.  These
    # arrays are immutable, automatic, and consumed synchronously by guards.
    return body.replace("static const uint32_t allowed[]", "const uint32_t allowed[]") \
               .replace("static const uint16_t allowed_x[]", "const uint16_t allowed_x[]")


def parse_shards(source: Path) -> tuple[list[dict], list[dict]]:
    contexts: list[dict] = []
    inputs: list[dict] = []
    paths = sorted(source.glob("js_v10_2_scpu_shard_*.c"), key=lambda p: p.name)
    if not paths:
        raise RuntimeError(f"no ordinary V10.2 S-CPU shards found in {source}")
    for path in paths:
        data = path.read_bytes()
        text = data.decode("utf-8").replace("\r\n", "\n")
        matches = list(CASE_RE.finditer(text))
        if not matches:
            raise RuntimeError(f"no exact-context cases parsed from {path.name}")
        for match in matches:
            opening = text.find("{", match.start())
            end = closing_brace(text, opening)
            key = int(match.group(1)[:-1], 16)
            contexts.append({
                "key": key,
                # Packed key is (((PBR << 16) | PC) << 3) | E:M:X.
                # The production shard key is the 24-bit address >> 10.
                "group": (key >> 13),
                "body": normalize_body(text[opening + 1:end]),
                "source": path.name,
            })
        inputs.append({
            "path": path.name,
            "bytes": len(data),
            "sha256": sha256_bytes(data),
            "parsed_cases": len(matches),
        })
    keys = [row["key"] for row in contexts]
    if len(keys) != EXPECTED_CONTEXTS or len(set(keys)) != EXPECTED_CONTEXTS:
        raise RuntimeError(
            f"parsed context count/uniqueness {len(keys)}/{len(set(keys))} "
            f"!= sealed {EXPECTED_CONTEXTS}"
        )
    return contexts, inputs


def skeleton_and_literals(text: str) -> tuple[str, tuple[str, ...]]:
    literals: list[str] = []
    pieces: list[str] = []
    cursor = 0
    for match in NUMERIC_LITERAL_RE.finditer(text):
        pieces.append(text[cursor:match.start()])
        literals.append(match.group(0))
        pieces.append("@N@")
        cursor = match.end()
    pieces.append(text[cursor:])
    return "".join(pieces), tuple(literals)


def analyze_columns(rows: list[dict]) -> tuple[
        list[str], list[tuple[str, ...]], list[str]]:
    width = len(rows[0]["literals"])
    if any(len(row["literals"]) != width for row in rows):
        raise RuntimeError("literal-column mismatch inside semantic skeleton")
    vectors = [tuple(row["literals"][i] for row in rows) for i in range(width)]
    variable_vectors: list[tuple[str, ...]] = []
    replacements: list[str] = []
    for vector in vectors:
        if len(set(vector)) == 1:
            replacements.append(vector[0])
        else:
            if vector not in variable_vectors:
                variable_vectors.append(vector)
            replacements.append(f"p[{variable_vectors.index(vector)}]")
    parameter_types = []
    for vector in variable_vectors:
        maximum = max(literal_to_u32(token) for token in vector)
        parameter_types.append(
            "uint8_t" if maximum <= 0xFF else
            "uint16_t" if maximum <= 0xFFFF else
            "uint32_t"
        )
    return replacements, variable_vectors, parameter_types


def substitute_literals(body: str, replacements: list[str]) -> str:
    index = 0

    def replace(_match: re.Match[str]) -> str:
        nonlocal index
        result = replacements[index]
        index += 1
        return result

    output = NUMERIC_LITERAL_RE.sub(replace, body)
    if index != len(replacements):
        raise RuntimeError("literal substitution did not consume every column")
    return output


def reconstruct(template: str, vectors: list[tuple[str, ...]], row: int) -> str:
    return re.sub(
        r"p\[(\d+)\]",
        lambda match: vectors[int(match.group(1))][row],
        template,
    )


def literal_to_u32(token: str) -> int:
    value = re.sub(r"[uUlL]+$", "", token)
    parsed = int(value, 0)
    if not 0 <= parsed <= 0xFFFFFFFF:
        raise RuntimeError(f"literal does not fit uint32_t: {token}")
    return parsed


def render_header(groups: list[int]) -> str:
    lines = [
        "/* generated compact exact-context S-CPU authority - do not edit */",
        "#ifndef ROCKNROLL_V10_2_SCPU_DISPATCH_H",
        "#define ROCKNROLL_V10_2_SCPU_DISPATCH_H",
        '#include "v05c_static_cpu.h"',
        "#ifdef __cplusplus",
        'extern "C" {',
        "#endif",
        "int js_v10_2_scpu_has_context(const JSCPU *cpu);",
        "int js_v10_2_scpu_index_allowed(uint16_t value, const uint16_t *allowed, size_t count);",
        "JSExecResult js_v10_2_compact_execute(JSCPU *cpu, const JSBus *bus, JSStop *stop,",
        "                                        uint16_t template_id, const uint32_t *parameters);",
    ]
    for group in groups:
        lines += [
            f"JSExecResult js_v10_2_compact_group_{group:04X}(JSCPU *cpu,",
            "                                              const JSBus *bus,",
            "                                              JSStop *stop,",
            "                                              uint32_t packed);",
        ]
    lines += [
        "JSExecResult js_v10_2_scpu_step(JSCPU *cpu, const JSBus *bus, JSStop *stop);",
        "#ifdef __cplusplus",
        "}",
        "#endif",
        "#endif",
        "",
    ]
    return "\n".join(lines)


def render_templates(templates: list[dict]) -> str:
    lines = [
        "/* generated compact exact-context semantic templates - do not edit */",
        "/* Exact key records select these templates; no ROM opcode is decoded. */",
        '#include "js_v10_2_scpu_dispatch.h"',
        "",
    ]
    for template in templates:
        lines += [
            f"static JSExecResult js_v10_2_template_{template['id']:03X}(",
            "        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {",
            "    (void)cpu; (void)bus; (void)stop; (void)p;",
        ]
        lines += ["    " + line for line in template["body"].splitlines()]
        lines += ["}", ""]
    lines += [
        "JSExecResult js_v10_2_compact_execute(JSCPU *cpu, const JSBus *bus, JSStop *stop,",
        "                                        uint16_t template_id, const uint32_t *p) {",
        "    switch (template_id) {",
    ]
    for template in templates:
        lines.append(
            f"        case 0x{template['id']:03X}u: return "
            f"js_v10_2_template_{template['id']:03X}(cpu, bus, stop, p);"
        )
    lines += [
        "        default: return js_stop_now(stop, JS_STOP_UNKNOWN_CONTEXT,",
        "                                    js_cpu_context_key(cpu), js_cpu_context_key(cpu));",
        "    }",
        "}",
        "",
    ]
    return "\n".join(lines)


def render_group(group: int, rows: list[dict]) -> tuple[str, int]:
    rows.sort(key=lambda row: row["key"])
    parameters: list[int] = []
    records: list[str] = []
    for row in rows:
        offset = len(parameters)
        parameters.extend(row["parameters"])
        records.append(
            f"    {{0x{row['key']:08X}u,0x{offset:08X}u,"
            f"0x{row['template_id']:04X}u,0u}},"
        )
    lines = [
        "/* generated compact exact-context S-CPU shard - do not edit */",
        '#include "js_v10_2_scpu_dispatch.h"',
        "typedef struct js_v10_2_compact_record {",
        "    uint32_t key;",
        "    uint32_t parameter_offset;",
        "    uint16_t template_id;",
        "    uint16_t reserved;",
        "} js_v10_2_compact_record;",
        f"static const js_v10_2_compact_record records[{len(rows)}] = {{",
        *records,
        "};",
    ]
    if parameters:
        lines.append(f"static const uint32_t parameters[{len(parameters)}] = {{")
        for start in range(0, len(parameters), 8):
            chunk = parameters[start:start + 8]
            lines.append("    " + ",".join(f"0x{value:08X}u" for value in chunk) + ",")
        lines.append("};")
    else:
        lines.append("static const uint32_t parameters[1] = {0u};")
    lines += [
        f"JSExecResult js_v10_2_compact_group_{group:04X}(JSCPU *cpu,",
        "                                              const JSBus *bus,",
        "                                              JSStop *stop,",
        "                                              uint32_t packed) {",
        f"    size_t lo = 0u, hi = {len(rows)}u;",
        "    while (lo < hi) {",
        "        size_t mid = lo + (hi - lo) / 2u;",
        "        uint32_t found = records[mid].key;",
        "        if (packed < found) hi = mid;",
        "        else if (packed > found) lo = mid + 1u;",
        "        else return js_v10_2_compact_execute(",
        "            cpu, bus, stop, records[mid].template_id,",
        "            parameters + records[mid].parameter_offset);",
        "    }",
        "    return JS_EXEC_NOT_MINE;",
        "}",
        "",
    ]
    return "\n".join(lines), len(parameters)


def render_dispatch(rows: list[dict], groups: list[int]) -> str:
    keys = sorted(row["key"] for row in rows)
    lines = [
        "/* generated compact exact-context S-CPU dispatcher - do not edit */",
        '#include "js_v10_2_scpu_dispatch.h"',
        "static const uint32_t js_v10_2_context_keys[] = {",
    ]
    for start in range(0, len(keys), 8):
        lines.append("    " + ", ".join(f"0x{key:08X}u" for key in keys[start:start + 8]) + ",")
    lines += [
        "};",
        "int js_v10_2_scpu_has_context(const JSCPU *cpu) {",
        "    size_t lo = 0u, hi = sizeof js_v10_2_context_keys / sizeof js_v10_2_context_keys[0];",
        "    uint32_t key;",
        "    if (!cpu) return 0;",
        "    key = js_cpu_context_key(cpu);",
        "    while (lo < hi) {",
        "        size_t mid = lo + (hi - lo) / 2u;",
        "        uint32_t candidate = js_v10_2_context_keys[mid];",
        "        if (candidate < key) lo = mid + 1u; else hi = mid;",
        "    }",
        "    return lo < (sizeof js_v10_2_context_keys / sizeof js_v10_2_context_keys[0])",
        "        && js_v10_2_context_keys[lo] == key;",
        "}",
        "int js_v10_2_scpu_index_allowed(uint16_t value, const uint16_t *allowed, size_t count) {",
        "    size_t index;",
        "    if (!allowed) return 0;",
        "    for (index = 0u; index < count; ++index) if (allowed[index] == value) return 1;",
        "    return 0;",
        "}",
        "JSExecResult js_v10_2_scpu_step(JSCPU *cpu, const JSBus *bus, JSStop *stop) {",
        "    JSExecResult result;",
        "    uint32_t group;",
        "    if (!cpu) return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, 0u, 0u);",
        "    js_stop_clear(stop);",
        "    if (cpu->e > 1u || (cpu->e && ((cpu->p & (JS_P_M|JS_P_X)) != (JS_P_M|JS_P_X))))",
        "        return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, js_cpu_context_key(cpu), js_cpu_context_key(cpu));",
        "    if ((cpu->p & JS_P_X) && ((cpu->x & 0xFF00u) || (cpu->y & 0xFF00u)))",
        "        return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, js_cpu_context_key(cpu), js_cpu_context_key(cpu));",
        "    group = ((((uint32_t)cpu->pbr << 16) | cpu->pc) >> 10);",
        "    switch (group) {",
    ]
    for group in groups:
        lines.append(
            f"        case 0x{group:04X}u: result = js_v10_2_compact_group_{group:04X}("
            "cpu, bus, stop, js_cpu_context_key(cpu)); break;"
        )
    lines += [
        "        default: result = JS_EXEC_NOT_MINE; break;",
        "    }",
        "    if (result == JS_EXEC_NOT_MINE)",
        "        return js_stop_now(stop, JS_STOP_UNKNOWN_CONTEXT, js_cpu_context_key(cpu), js_cpu_context_key(cpu));",
        "    return result;",
        "}",
        "",
    ]
    return "\n".join(lines)


def compact(source: Path, out: Path, rom_path: Path | None) -> dict:
    if rom_path is not None and sha256_path(rom_path) != EXPECTED_ROM_SHA256:
        raise RuntimeError("target ROM SHA-256 mismatch")
    contexts, inputs = parse_shards(source)
    structural: dict[str, list[dict]] = defaultdict(list)
    for row in contexts:
        skeleton, literals = skeleton_and_literals(row["body"])
        item = dict(row)
        item["literals"] = literals
        structural[skeleton].append(item)

    templates: list[dict] = []
    compact_rows: list[dict] = []
    original_hash = hashlib.sha256()
    reconstructed_hash = hashlib.sha256()
    ordered = sorted(structural.items(), key=lambda item: (-len(item[1]), item[0]))
    for template_id, (_skeleton, rows) in enumerate(ordered):
        replacements, vectors, parameter_types = analyze_columns(rows)
        template_body = substitute_literals(rows[0]["body"], replacements)
        compiled_body = re.sub(
            r"p\[(\d+)\]",
            lambda match: (
                f"(({parameter_types[int(match.group(1))]})"
                f"p[{match.group(1)}])"
            ),
            template_body,
        )
        templates.append({
            "id": template_id,
            "body": compiled_body,
            "parameter_count": len(vectors),
            "context_count": len(rows),
        })
        for row_index, row in enumerate(rows):
            rebuilt = reconstruct(template_body, vectors, row_index)
            if rebuilt != row["body"]:
                raise RuntimeError(f"semantic reconstruction mismatch at key {row['key']:08X}")
            key_bytes = row["key"].to_bytes(4, "little")
            original_hash.update(key_bytes)
            original_hash.update(row["body"].encode("utf-8"))
            reconstructed_hash.update(key_bytes)
            reconstructed_hash.update(rebuilt.encode("utf-8"))
            compact_rows.append({
                "key": row["key"],
                "group": row["group"],
                "template_id": template_id,
                "parameters": [literal_to_u32(vector[row_index]) for vector in vectors],
                "source": row["source"],
            })
    if original_hash.digest() != reconstructed_hash.digest():
        raise RuntimeError("whole-authority semantic reconstruction hash mismatch")
    if len(templates) > 0xFFFF:
        raise RuntimeError("template identifier exceeds uint16_t")

    grouped: dict[int, list[dict]] = defaultdict(list)
    for row in compact_rows:
        grouped[row["group"]].append(row)
    groups = sorted(grouped)
    generated: dict[str, str] = {
        "js_v10_2_scpu_dispatch.h": render_header(groups),
        "js_v10_2_compact_templates.c": render_templates(templates),
        "js_v10_2_scpu_dispatch.c": render_dispatch(compact_rows, groups),
    }
    parameter_words = 0
    for group in groups:
        text, words = render_group(group, grouped[group])
        generated[f"js_v10_2_compact_group_{group:04X}.c"] = text
        parameter_words += words

    out.mkdir(parents=True, exist_ok=True)
    for stale in out.glob("js_v10_2_*.c"):
        stale.unlink()
    for stale in out.glob("js_v10_2_*.h"):
        stale.unlink()
    file_receipts: dict[str, dict] = {}
    for name, text in sorted(generated.items()):
        data = text.encode("utf-8")
        (out / name).write_bytes(data)
        file_receipts[name] = {"bytes": len(data), "sha256": sha256_bytes(data)}
    source_bytes = sum(row["bytes"] for row in file_receipts.values())
    manifest = {
        "format": "rock-n-roll-racing-1.0.0-compact-exact-context-aot-v1",
        "status": "COMPACT_REPRESENTATION_CANDIDATE",
        "rom_sha256": EXPECTED_ROM_SHA256,
        "runtime_context_identity": "PBR:PC:E:M:X",
        "runtime_context_count": len(compact_rows),
        "semantic_template_count": len(templates),
        "parameter_word_count": parameter_words,
        "generated_shard_count": len(groups),
        "generated_source_files": len(file_receipts),
        "generated_source_bytes": source_bytes,
        "input_generated_files": inputs,
        "output_files": file_receipts,
        "original_semantics_sha256": original_hash.hexdigest(),
        "reconstructed_semantics_sha256": reconstructed_hash.hexdigest(),
        "all_context_semantics_reconstructed_exactly": True,
        "runtime_rom_opcode_decode": False,
        "runtime_target_learning": False,
        "runtime_emulator_fallback": False,
        "exact_context_resume_points_preserved": True,
        "unknown_contexts_fail_closed": True,
    }
    manifest_text = json.dumps(manifest, indent=2, sort_keys=True) + "\n"
    (out / "V10.2-SCPU-COMPACT-MANIFEST.json").write_text(
        manifest_text, encoding="utf-8", newline="\n"
    )
    return manifest


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    parser.add_argument("--rom", type=Path)
    args = parser.parse_args()
    manifest = compact(args.input.resolve(), args.out.resolve(),
                       args.rom.resolve() if args.rom else None)
    print(json.dumps({
        "contexts": manifest["runtime_context_count"],
        "templates": manifest["semantic_template_count"],
        "parameter_words": manifest["parameter_word_count"],
        "shards": manifest["generated_shard_count"],
        "source_files": manifest["generated_source_files"],
        "source_bytes": manifest["generated_source_bytes"],
        "semantics_sha256": manifest["original_semantics_sha256"],
    }, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
