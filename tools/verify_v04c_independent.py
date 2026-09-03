#!/usr/bin/env python3
"""Independent V04C evidence reviewer.

Deliberately does not import the V03/V04 decoders or control-flow analyser.  It
uses only the frozen V02C opcode/context matrix, raw target ROM bytes, and the
emitted V03/V04 evidence files.
"""
from __future__ import annotations
import argparse,csv,hashlib,json
from collections import Counter,defaultdict
from pathlib import Path

ROM_SHA256='9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182'
ROM_SIZE=1_048_576
LEGAL={(0,0,0),(0,0,1),(0,1,0),(0,1,1),(1,1,1)}

def rows(p:Path):
    with p.open(encoding='utf-8',newline='') as f:return list(csv.DictReader(f))

def lorom(bank:int,addr:int)->int|None:
    bank&=0xff; addr&=0xffff
    if bank in (0x7e,0x7f): return None
    if addr<0x8000:return None
    return ((((bank&0x7f)<<15)|(addr&0x7fff)) % ROM_SIZE)

def short(r:dict)->str:
    c=r['Carry']; db=r['DBR'];
    return f"{r['PBR']}:{r['PC']}:E{r['E']}M{r['M']}X{r['X']}:C{c}:DBR{db}:S{r['Stack_Depth']}"

def expand_ownership(rs:list[dict])->list[str]:
    out=['']*ROM_SIZE; nxt=0
    for r in rs:
        lo=int(r['Physical_Start'],16); hi=int(r['Physical_End'],16)
        assert lo==nxt and lo<=hi<ROM_SIZE,(nxt,r)
        for i in range(lo,hi+1):out[i]=r['Classification']
        nxt=hi+1
    assert nxt==ROM_SIZE
    assert all(out)
    return out

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('rom',type=Path)
    ap.add_argument('--artifact-root',type=Path,default=Path(__file__).resolve().parents[1])
    a=ap.parse_args(); root=a.artifact_root
    rom=a.rom.read_bytes(); assert len(rom)==ROM_SIZE; assert hashlib.sha256(rom).hexdigest()==ROM_SHA256

    matrix=rows(root/'docs/V02C-opcode-context-matrix.csv')
    assert len(matrix)==2048
    legal_matrix={(int(r['Opcode'],16),int(r['E']),int(r['M']),int(r['X'])):r for r in matrix if r['Status']=='LEGAL'}
    assert len(legal_matrix)==1280

    ctx=rows(root/'docs/V04C-contexts.csv'); edges=rows(root/'docs/V04C-edges.csv')
    bounds=rows(root/'docs/V04C-fail-closed-boundaries.csv'); proofs=rows(root/'docs/V04C-dynamic-proofs.csv')
    ids=set(); shorts=Counter(); starts=defaultdict(set); proved_bytes=set()
    for r in ctx:
        cid=r['Context_ID']; assert cid not in ids; ids.add(cid)
        e,m,x=int(r['E']),int(r['M']),int(r['X']); assert (e,m,x) in LEGAL
        bank=int(r['PBR'],16); pc=int(r['PC'],16); off=lorom(bank,pc)
        assert off is not None and off==int(r['Physical'],16),(cid,off,r['Physical'])
        op=rom[off]; assert op==int(r['Opcode'],16)
        mr=legal_matrix[(op,e,m,x)]
        assert mr['Mnemonic']==r['Mnemonic'],(cid,mr['Mnemonic'],r['Mnemonic'])
        assert mr['Mode']==r['Mode'],(cid,mr['Mode'],r['Mode'])
        ln=int(mr['Instruction_Bytes']); assert ln==int(r['Length'])
        raw=bytearray()
        for i in range(ln):
            oi=lorom(bank,(pc+i)&0xffff); assert oi is not None
            raw.append(rom[oi]); proved_bytes.add(oi)
        assert raw.hex().upper()==r['Bytes'],(cid,raw.hex(),r['Bytes'])
        starts[off].add(ln); shorts[short(r)]+=1
    assert all(len(v)==1 for v in starts.values()),[(k,v) for k,v in starts.items() if len(v)>1][:5]

    # Every graph edge comes from an admitted context and every non-terminal To
    # has an admitted state with the same externally serialized short identity.
    terminal={'TERMINAL_STOP'}
    edge_from=Counter()
    for e in edges:
        assert e['From'] in ids,e
        edge_from[e['From']]+=1
        if e['To']:
            assert shorts[e['To']]>0,(e['From'],e['To'])
        else:
            assert e['Edge_Kind'] in terminal,e

    # Boundary contexts must correspond to at least one admitted serialized state.
    bclass=Counter()
    for b in bounds:
        assert b['Disposition']=='FAIL_CLOSED'
        assert shorts[b['Context']]>0,b
        bclass[b['Class']]+=1

    # Dynamic proofs are tied to admitted consumers and finite admitted targets.
    by_consumer={(r['PBR']+':'+r['PC']):r for r in ctx}
    pclass=Counter()
    for p in proofs:
        assert p['Evidence'] in ids,p
        er=next(r for r in ctx if r['Context_ID']==p['Evidence'])
        assert p['Consumer']==er['PBR']+':'+er['PC']
        assert p['Admitted_Targets']
        for t in p['Admitted_Targets'].split(';'):
            bank,pc=(int(z,16) for z in t.split(':'))
            # V04C has no executable-WRAM epochs; every target must be ROM.
            assert lorom(bank,pc) is not None,(p['Proof_ID'],t)
        pclass[p['Class']]+=1

    # Full ownership must preserve V03 predecessor classifications except exact
    # source-proved promotions; V03 proof/header may never be demoted.
    v03=expand_ownership(rows(root/'docs/V03C-byte-ownership.csv'))
    v04=expand_ownership(rows(root/'config/byte-ownership.csv'))
    for i,(a3,a4) in enumerate(zip(v03,v04)):
        if i in proved_bytes and not (0x7fc0<=i<=0x7fff): assert a4=='PROVED_CODE',(i,a3,a4)
        elif a3=='CANDIDATE': assert a4=='CANDIDATE',(i,a3,a4)
        elif a3 in {'PROVED_CODE','HEADER_VECTOR'}: assert a4==a3,(i,a3,a4)
        else: assert a4==a3,(i,a3,a4)

    # V03 queue/discovery artifacts must be exhaustively dispositioned one-for-one.
    pairs=[
      ('V03C-frontiers.csv','V04C-v03-frontier-dispositions.csv','Frontier_ID','V03_Frontier_ID'),
      ('V03C-root-contexts.csv','V04C-v03-root-dispositions.csv','Root_ID','V03_Root_ID'),
      ('V03C-conflicts.csv','V04C-v03-conflict-dispositions.csv','Conflict_ID','Conflict_ID'),
      ('V03C-apuio-candidates.csv','V04C-apuio-dispositions.csv','Candidate_ID','Candidate_ID'),
    ]
    dispositions={}
    for old,new,ok,nk in pairs:
        arows=rows(root/'docs'/old); brows=rows(root/'docs'/new)
        assert len(arows)==len(brows),(old,len(arows),new,len(brows))
        assert {r[ok] for r in arows}=={r[nk] for r in brows}
        dispositions[new]=len(brows)

    apu=rows(root/'docs/V04C-apuio-dispositions.csv')
    assert all(r['V04_Disposition'] in {'SOURCE_PROVED_MMIO','REJECTED_V03_CANDIDATE','BANK_OR_INDEX_UNPROVED'} for r in apu)
    for r in apu:
        if r['V04_Disposition']=='SOURCE_PROVED_MMIO':
            reg=int(r['Register'],16)
            assert r['Effective_Addresses']
            for z in r['Effective_Addresses'].split(';'):
                addr=int(z,16); assert (addr&0xffff)==reg and 0x2140<=reg<=0x2143

    summary=json.loads((root/'docs/V04C-control-summary.json').read_text(encoding='utf-8'))
    assert summary['rom_sha256']==ROM_SHA256
    assert summary['admitted_context_rows']==len(ctx)
    assert summary['dynamic_proof_rows']==len(proofs)
    assert summary['fail_closed_boundary_rows']==len(bounds)
    assert summary['proved_conflict_blockers']==0
    assert summary['runtime_decoder_added'] is False and summary['trace_promotions']==0 and summary['oracle_promotions']==0
    assert summary['executable_wram_epochs']==0
    owncount=Counter(v04); assert dict(sorted(owncount.items()))==summary['ownership_bytes']
    assert dict(sorted(pclass.items()))==summary['dynamic_proofs_by_class']
    assert dict(sorted(bclass.items()))==summary['fail_closed_by_class']

    out={
      'status':'PASS','rom_sha256':ROM_SHA256,'contexts_checked':len(ctx),
      'instruction_bytes_checked':len(proved_bytes),'v02_matrix_legal_rows':len(legal_matrix),
      'dynamic_proofs_checked':len(proofs),'fail_closed_boundaries_checked':len(bounds),
      'v03_dispositions_checked':dispositions,'ownership_bytes':dict(sorted(owncount.items())),
      'decoder_source':'frozen V02C opcode-context matrix plus independent LoROM/raw-byte reader',
    }
    print(json.dumps(out,indent=2,sort_keys=True))

if __name__=='__main__': main()
