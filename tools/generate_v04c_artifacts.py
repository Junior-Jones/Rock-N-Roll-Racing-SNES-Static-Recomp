#!/usr/bin/env python3
from pathlib import Path
import argparse,json,sys
ROOT=Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path: sys.path.insert(0,str(ROOT))
from analysis.v04c_control_flow import analyse,write_result,load_csv

p=argparse.ArgumentParser()
p.add_argument('rom',type=Path); p.add_argument('--output-root',type=Path,default=ROOT)
a=p.parse_args()
rom=a.rom.read_bytes(); profile=json.loads((ROOT/'docs/V01C-cartridge-evidence.json').read_text(encoding='utf-8'))
res=analyse(rom,profile,
    load_csv(ROOT/'docs/V03C-root-contexts.csv'),
    load_csv(ROOT/'docs/V03C-frontiers.csv'),
    load_csv(ROOT/'docs/V03C-conflicts.csv'),
    load_csv(ROOT/'docs/V03C-apuio-candidates.csv'),
    load_csv(ROOT/'docs/V03C-byte-ownership.csv'),
    'e52ddb5200e1ec87eb0dc0426789e0370299e659')
rels=write_result(res,a.output_root)
print(json.dumps({'generated':rels,'summary':res.summary},indent=2,sort_keys=True))
