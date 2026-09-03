from __future__ import annotations
import argparse,csv,hashlib,json
from pathlib import Path
import sys
ROOT_IMPORT = Path(__file__).resolve().parents[1]
if str(ROOT_IMPORT) not in sys.path:
    sys.path.insert(0, str(ROOT_IMPORT))
from analysis.v10_1_apu_model import (
    ROM_SHA256, IPL_SHA256, RESET_UPLOAD_CALLS, require_rom, parse_upload_records,
    reconstruct_aram, state_hash,
)

def sha_bytes(b: bytes) -> str: return hashlib.sha256(b).hexdigest()
def sha_path(p: Path) -> str: return sha_bytes(p.read_bytes())

def write_text_lf(path: Path, text: str):
    """Write generated text with stable LF bytes on every host OS."""
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('w', encoding='utf-8', newline='\n') as f:
        f.write(text)

def _write_csv(path:Path, rows:list[dict], fields:list[str]):
    path.parent.mkdir(parents=True,exist_ok=True)
    with path.open('w',newline='',encoding='utf-8') as f:
        w=csv.DictWriter(f,fieldnames=fields,lineterminator='\n');w.writeheader();w.writerows(rows)

def build(root:Path, rom_path:Path):
    rom=require_rom(rom_path)
    contexts=list(csv.DictReader((root/'docs/V04C-contexts.csv').open(newline='',encoding='utf-8')))
    edges=list(csv.DictReader((root/'docs/V04C-edges.csv').open(newline='',encoding='utf-8')))
    by_site={(r['PBR']+':'+r['PC'],r['Physical']):r for r in contexts}
    calls=[]
    for cpu,physical,selector in RESET_UPLOAD_CALLS:
        row=by_site.get((cpu,physical))
        if not row: raise ValueError(f'missing V04 reset upload call {cpu}')
        if row['Mnemonic']!='JSR' or row['Bytes'].upper()!='2038FA' or row['XR']!=f'{selector:04X}' or row['Root']!='emulation_reset':
            raise ValueError(f'call-site proof mismatch {cpu}')
        if not any(e['From']==row['Context_ID'] and e['Edge_Kind']=='SOURCE_PROVED_CALL' and e['To'].startswith('80:FA38:') for e in edges):
            raise ValueError(f'missing source-proved FA38 edge {cpu}')
        calls.append({
            'Order':selector,'Caller_CPU':cpu,'Caller_Physical':physical,'Context':row['Context_ID'],
            'Selector_X':f'{selector:02X}','Call_Bytes':row['Bytes'],'Target':'80:FA38',
            'Root':row['Root'],'Authority':'V04C_SOURCE_PROVED_CALL_AND_REGISTER_FACT',
        })
    _write_csv(root/'docs/V10.1-upload-call-sites.csv',calls,list(calls[0]))

    records=parse_upload_records(rom,4)
    rec_rows=[]
    total=0
    for r in records:
        total+=r.size
        rec_rows.append({
            'Selector':r.selector,'Header_CPU':r.header_cpu,'Header_Physical':f'{r.header_physical:06X}',
            'Data_Physical':f'{r.data_physical:06X}','Size_Decimal':r.size,'Size_Hex':f'{r.size:04X}',
            'Destination':f'{r.destination:04X}','End':f'{r.end_destination:04X}',
            'Entry_Field':f'{r.entry_field:04X}','Command_Entry':f'{r.command_entry:04X}',
            'Payload_SHA256':r.data_sha256,'Source_Call':RESET_UPLOAD_CALLS[r.selector][0],
        })
    _write_csv(root/'docs/V10.1-apu-upload-records.csv',rec_rows,list(rec_rows[0]))

    aram,known,epochs=reconstruct_aram(rom,records)
    _write_csv(root/'docs/V10.1-aram-epochs.csv',epochs,['Epoch','Selector','Start','End','Byte_Count','Entry','Provenance'])
    known_count=sum(known)
    if known_count != 58607 or total != 58368 or records[-1].command_entry != 0x0400:
        raise ValueError('unexpected RNR bootstrap totals')
    uploaded_ranges=[[f'{r.destination:04X}',f'{r.end_destination:04X}'] for r in records]
    summary={
        'schema':1,'milestone':'V10.1','rom_sha256':ROM_SHA256,'fixed_ipl_sha256':IPL_SHA256,
        'production_s_cpu_contexts':2258,'scheduler_executable_s_cpu_contexts':2250,'source_proved_s_cpu_rom_bytes':4803,
        'reset_upload_call_count':len(calls),'reset_upload_selectors':[r['Order'] for r in calls],
        'upload_record_count':len(records),'uploaded_aram_bytes':total,'ipl_cleared_aram_bytes':0xEF,
        'known_aram_bytes_at_frontier':known_count,'unknown_aram_bytes_at_frontier':0x10000-known_count,
        'uploaded_ranges':uploaded_ranges,'final_uploaded_entry':'0400','next_frontier':'JSV10_1_STOP_SMP_AOT_REQUIRED',
        'aram_knownness_sha256':sha_bytes(bytes(known)),'aram_storage_sha256':sha_bytes(bytes(aram)),
        'aram_state_sha256':state_hash(aram,known),'generic_spc700_runtime_decoder':False,
        'fixed_ipl_protocol_state_machine':True,'smp_scheduler_rendezvous_reused':True,
        'exact_uploaded_spc700_aot_implemented':False,'gameplay_promotion_count':0,'trace_promotion_count':0,
        'oracle_pc_promotion_count':0,'static_core_compilation_performed':False,
        'notes':'V10.1 reconstructs source-proved bootstrap ARAM and stops before executing uploaded SPC700 at $0400.'
    }
    write_text_lf(root/'docs/V10.1-aram-summary.json', json.dumps(summary,indent=2,sort_keys=True)+'\n')

    # Target-specific WRAM epoch result: V04/V05 have no admitted successor into
    # executable WRAM. Keep ordinary low-WRAM data writes separate from execution.
    low_wram_write_phys=set()
    with (root/'docs/V04C-memory-accesses.csv').open(newline='',encoding='utf-8') as f:
        for row in csv.DictReader(f):
            if row['Access']!='WRITE': continue
            for token in row['WRAM'].replace(';',' ').replace('|',' ').split():
                try:a=int(token,16)&0xffffff
                except ValueError:continue
                if (a&0xffff)<0x0100: low_wram_write_phys.add(row['Physical'])
    wram_targets=[]
    with (root/'docs/V05C-successors.csv').open(newline='',encoding='utf-8') as f:
        for row in csv.DictReader(f):
            to=row['To_Key']
            try:
                bank=int(to[0:2],16);pc=int(to[3:7],16)
            except Exception: continue
            if pc<0x2000 and (bank<=0x3f or 0x80<=bank<=0xbf or bank in (0x7e,0x7f)):
                wram_targets.append(to)
    wr={
        'schema':1,'milestone':'V10.1','admitted_executable_wram_epochs':len(wram_targets),
        'admitted_executable_wram_targets':sorted(set(wram_targets)),
        'source_proved_low_wram_write_physical_sites':sorted(low_wram_write_phys),
        'status':'NO_EXECUTABLE_WRAM_EPOCH_PROMOTION_REQUIRED' if not wram_targets else 'REVIEW_REQUIRED',
        'rule':'Low-WRAM writes remain data unless a finite source-proved execution target and producer epoch exist.'
    }
    if wram_targets: raise ValueError(f'unexpected executable WRAM successors: {wram_targets[:8]}')
    write_text_lf(root/'docs/V10.1-wram-epoch-summary.json', json.dumps(wr,indent=2,sort_keys=True)+'\n')

    # Hash exact uploader + pointer-walk helpers used by the source proof.
    uploader=rom[0x7A38:0x7B2F]
    auth={
        'schema':1,'milestone':'V10.1','uploader_cpu_start':'80:FA38','uploader_physical_start':'007A38',
        'uploader_helper_physical_end_exclusive':'007B2F','uploader_and_helpers_sha256':sha_bytes(uploader),
        'record_table_cpu_start':'82:8000','record_table_physical_start':'010000','fixed_ipl_sha256':IPL_SHA256,
        'protocol':'standard SNES fixed IPL $AA/$BB -> $CC upload -> terminator -> entry',
        'timing_claim':'APUIO protocol is synchronized at the inherited V07 rational S-SMP target seam; exact uploaded-program execution begins in V10.2.'
    }
    write_text_lf(root/'docs/V10.1-ipl-authority.json', json.dumps(auth,indent=2,sort_keys=True)+'\n')

    g=root/'generated/current/v10_1';g.mkdir(parents=True,exist_ok=True)
    rec_lines=[]
    for r in records:
        rec_lines.append(f'  {{{r.selector}u,0x{r.size:04X}u,0x{r.destination:04X}u,0x{r.command_entry:04X}u,0x{r.header_physical:06X}u}},')
    hdr='''#ifndef RNR_V10_1_AUDIO_AUTHORITY_H\n#define RNR_V10_1_AUDIO_AUTHORITY_H\n#include <stdint.h>\n#define RNR_V10_1_UPLOAD_RECORD_COUNT 4u\n#define RNR_V10_1_UPLOADED_ARAM_BYTES 58368u\n#define RNR_V10_1_KNOWN_ARAM_BYTES 58607u\n#define RNR_V10_1_FINAL_SMP_ENTRY 0x0400u\n#define RNR_V10_1_IPL_CLEAR_START 0x0001u\n#define RNR_V10_1_IPL_CLEAR_END 0x00EFu\ntypedef struct RnrV10_1UploadAuthority { uint8_t selector; uint16_t size,destination,entry; uint32_t header_physical; } RnrV10_1UploadAuthority;\nstatic const RnrV10_1UploadAuthority rnr_v10_1_upload_authority[4] = {\n'''+"\n".join(rec_lines)+'''\n};\n#endif\n'''
    write_text_lf(g/'rnr_v10_1_audio_authority.h', hdr)
    rels=[
        'docs/V10.1-upload-call-sites.csv','docs/V10.1-apu-upload-records.csv','docs/V10.1-aram-epochs.csv',
        'docs/V10.1-aram-summary.json','docs/V10.1-wram-epoch-summary.json','docs/V10.1-ipl-authority.json',
        'generated/current/v10_1/rnr_v10_1_audio_authority.h',
    ]
    man={'schema':1,'milestone':'V10.1','files':{rel:sha_path(root/rel) for rel in rels}}
    write_text_lf(g/'V10.1-GENERATED-SHA256.json', json.dumps(man,indent=2,sort_keys=True)+'\n')
    return summary

def main():
    p=argparse.ArgumentParser();p.add_argument('--project',type=Path,required=True);p.add_argument('--rom',type=Path,required=True);a=p.parse_args()
    s=build(a.project,a.rom)
    print(f"V10.1 generated: records={s['upload_record_count']} uploaded={s['uploaded_aram_bytes']} known={s['known_aram_bytes_at_frontier']} entry=${s['final_uploaded_entry']}")
if __name__=='__main__':main()
