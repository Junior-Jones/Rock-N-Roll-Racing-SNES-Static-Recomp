#!/usr/bin/env python3
"""Generate deterministic V03C whole-ROM discovery artifacts."""
from __future__ import annotations
import argparse, json, sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT))
from analysis.v03c_discovery import discover,write_result

V02C_COMMIT="458128b8afa2a9819ef659cf28e447844959c20f"

def main()->int:
    ap=argparse.ArgumentParser()
    ap.add_argument("rom",type=Path)
    ap.add_argument("--output-root",type=Path,required=True)
    ns=ap.parse_args()
    rom=ns.rom.read_bytes()
    profile=json.loads((ROOT/"docs/V01C-cartridge-evidence.json").read_text(encoding="utf-8"))
    result=discover(rom,profile,V02C_COMMIT)
    rels=write_result(result,ns.output_root)
    print(json.dumps({"result":"PASS","files":rels,"summary":result.summary},sort_keys=True))
    return 0
if __name__=="__main__": raise SystemExit(main())
