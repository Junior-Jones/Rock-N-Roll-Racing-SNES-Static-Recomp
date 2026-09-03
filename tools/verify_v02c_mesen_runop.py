#!/usr/bin/env python3
"""Compare all 256 V02C opcode mnemonic/address-mode rows with pinned MesenCE RunOp."""
from __future__ import annotations
import argparse, hashlib, re, sys, zipfile
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT))
from analysis.w65c816.opcodes import OPCODES

MEMBER='Mesen Linux Source\\Core\\SNES\\SnesCpu.Shared.h'
MODE_MAP={
 'Abs':'ABS','AbsIdxX':'ABS_X','AbsIdxY':'ABS_Y','AbsLng':'ABS_LONG','AbsLngIdxX':'ABS_LONG_X',
 'AbsJmp':'ABS_JUMP','AbsLngJmp':'ABSL_JUMP','AbsInd':'ABS_IND','AbsIndLng':'ABS_IND_LONG',
 'Acc':'ACC','BlkMov':'BLOCK','Dir':'DP','DirIdxX':'DP_X','DirIdxY':'DP_Y','DirInd':'DP_IND',
 'DirIdxIndX':'DP_X_IND','DirIndIdxY':'DP_IND_Y','DirIndLng':'DP_IND_LONG','DirIndLngIdxY':'DP_IND_LONG_Y',
 'Imm8':'SIG8','Imm16':'IMM16','ImmX':'IMM_X','ImmM':'IMM_M','Imp':'IMP','RelLng':'REL16','Rel':'REL8',
 'StkRel':'STACK_REL','StkRelIndIdxY':'STACK_REL_IND_Y',
}
# Imm8 is signature for BRK/COP/WDM but REP/SEP also use it and are project IMM8.
SPECIAL_MODE={0x22:'ABSL_JUMP',0x7C:'ABS_X_IND',0xFC:'ABS_X_IND'}
SPECIAL_MNEMONIC={0x7C:'JMP',0xFC:'JSR'}


def sha256(data:bytes)->str: return hashlib.sha256(data).hexdigest()

def parse_cases(text:str):
    pat=re.compile(r'case\s+0x([0-9A-Fa-f]{2}):\s*(.*?)\s*break;',re.S)
    cases={int(h,16): body.strip() for h,body in pat.findall(text)}
    if set(cases)!=set(range(256)):
        missing=sorted(set(range(256))-set(cases)); extra=sorted(set(cases)-set(range(256)))
        raise RuntimeError(f'RunOp case coverage invalid: count={len(cases)} missing={missing} extra={extra}')
    return cases

def actual(op:int, body:str):
    if op in SPECIAL_MNEMONIC:
        mn=SPECIAL_MNEMONIC[op]
    else:
        calls=re.findall(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\(',body)
        ignore={'Idle','IdleOrRead'} | {c for c in calls if c.startswith('AddrMode_')}
        candidates=[c for c in calls if c not in ignore]
        if not candidates:
            raise RuntimeError(f'cannot find semantic call ${op:02X}: {body}')
        mn=candidates[-1].replace('_Acc','')
    if op in SPECIAL_MODE:
        mode=SPECIAL_MODE[op]
    else:
        m=re.search(r'AddrMode_([A-Za-z0-9]+)\s*\(',body)
        if m:
            mode=MODE_MAP[m.group(1)]
            if m.group(1)=='Imm8' and op in (0xC2,0xE2): mode='IMM8'
        else:
            mode='IMP'
    return mn,mode

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('mesen_source_zip',type=Path)
    ap.add_argument('--output',type=Path)
    ns=ap.parse_args()
    raw=ns.mesen_source_zip.read_bytes()
    with zipfile.ZipFile(ns.mesen_source_zip) as z:
        src=z.read(MEMBER)
    text=src.decode('utf-8-sig')
    cases=parse_cases(text[text.index('void SnesCpu::RunOp'):])
    mism=[]
    rows=[]
    for spec in OPCODES:
        got=actual(spec.opcode,cases[spec.opcode])
        want=(spec.mnemonic,spec.mode)
        rows.append((spec.opcode,*want,*got))
        if got!=want: mism.append(rows[-1])
    report=[
      'V02C MESENCE RUNOP INDEPENDENT COMPARISON',
      f'Mesen source ZIP: {ns.mesen_source_zip}',
      f'Mesen source ZIP SHA-256: {sha256(raw)}',
      f'{MEMBER} SHA-256: {sha256(src)}',
      f'RunOp cases parsed: {len(cases)}',
      f'Mnemonic/address-mode rows compared: {len(rows)}',
      f'Mismatches: {len(mism)}',
      'Result: '+('PASS' if not mism else 'FAIL'),
    ]
    if mism:
      report.append('Mismatch rows:')
      report.extend(f'${op:02X}: expected {wm}/{wmode}, got {gm}/{gmode}' for op,wm,wmode,gm,gmode in mism)
    out='\n'.join(report)+'\n'
    if ns.output:
        ns.output.parent.mkdir(parents=True,exist_ok=True); ns.output.write_text(out,encoding='utf-8')
    print(out,end='')
    return 1 if mism else 0
if __name__=='__main__': raise SystemExit(main())
