#!/usr/bin/env python3
"""Generate deterministic V02C opcode/context/access artifacts."""
from __future__ import annotations
import argparse,csv,hashlib,json,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT))
from analysis.w65c816.opcodes import OPCODES,iter_raw_contexts,instruction_length
from analysis.w65c816.access_contract import access_contract

WDC_PDF_SHA256='b9177e1b045d2c8a801d1b23619abb4e5b29b88868fa491df7296dbc0b13447e'
WDC_DOC='W65C816S datasheet Table 5-4, document dated 2024-03-13, PDF page 31'
MESEN_ZIP_SHA256='2771dea145bc9b1b637f7c1ced821a46d0586f1836fff0df86c721a7903c3f87'

def hfile(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 ap=argparse.ArgumentParser(); ap.add_argument('--output-root',type=Path,default=ROOT); ns=ap.parse_args()
 docs=ns.output_root/'docs'; ref=docs/'reference'; ref.mkdir(parents=True,exist_ok=True)
 wdc=ref/'V02C-WDC-TABLE-5-4.csv'
 with wdc.open('w',newline='',encoding='utf-8') as f:
  wr=csv.writer(f); wr.writerow(['Opcode','WDC_Mnemonic','Canonical_Mnemonic','WDC_Mode','Project_Mode','Base_Cycles','Base_Bytes','Source','Source_PDF_SHA256'])
  for s in OPCODES: wr.writerow([f'{s.opcode:02X}',s.wdc_mnemonic,s.mnemonic,s.wdc_mode,s.mode,s.base_cycles,s.base_bytes,WDC_DOC,WDC_PDF_SHA256])
 matrix=docs/'V02C-opcode-context-matrix.csv'
 fields=['Opcode','E','M','X','Status','Reject_Reason','Mnemonic','Mode','Instruction_Bytes','WDC_Base_Cycles','Fixed_Cycle_Delta','Cycle_Min','Cycle_Max','Dynamic_Cycle_Tags','Fetch_Bytes','Pointer_Read_Bytes','Data_Read_Bytes','Data_Write_Bytes','Dummy_Write_Bytes','Stack_Read_Bytes','Stack_Write_Bytes','Vector_Read_Bytes','RMW_Write_Order','Wait_or_Repeat','Semantic_Test','Addressing_Test']
 legal=rejected=0
 with matrix.open('w',newline='',encoding='utf-8') as f:
  wr=csv.DictWriter(f,fieldnames=fields); wr.writeheader()
  for s,e,m,x,ok in iter_raw_contexts():
   base={k:'' for k in fields}; base.update(Opcode=f'{s.opcode:02X}',E=e,M=m,X=x,Mnemonic=s.mnemonic,Mode=s.mode,WDC_Base_Cycles=s.base_cycles)
   if not ok:
    rejected+=1; base.update(Status='REJECTED',Reject_Reason='E=1 requires architectural M=1 and X=1')
   else:
    legal+=1; c=access_contract(s,e,m,x)
    base.update(Status='LEGAL',Instruction_Bytes=instruction_length(s,m,x),Fixed_Cycle_Delta=c.fixed_cycle_delta,Cycle_Min=c.cycle_min,Cycle_Max=c.cycle_max,
      Dynamic_Cycle_Tags=';'.join(c.dynamic_cycle_tags) or 'NONE',Fetch_Bytes=c.fetch_bytes,Pointer_Read_Bytes=c.pointer_read_bytes,Data_Read_Bytes=c.data_read_bytes,Data_Write_Bytes=c.data_write_bytes,
      Dummy_Write_Bytes=c.dummy_write_bytes,Stack_Read_Bytes=c.stack_read_bytes,Stack_Write_Bytes=c.stack_write_bytes,Vector_Read_Bytes=c.vector_read_bytes,RMW_Write_Order=c.rmw_write_order,
      Wait_or_Repeat=c.wait_or_repeat,Semantic_Test=c.semantic_test,Addressing_Test=c.addressing_test)
   wr.writerow(base)
 summary={
   'schema':1,'milestone':'02C','opcode_count':len(OPCODES),'raw_context_rows':legal+rejected,'legal_context_rows':legal,'rejected_context_rows':rejected,
   'unique_mnemonics':len({s.mnemonic for s in OPCODES}),'unique_project_modes':len({s.mode for s in OPCODES}),
   'wdc_table_5_4_pdf_sha256':WDC_PDF_SHA256,'pinned_mesen_source_zip_sha256':MESEN_ZIP_SHA256,
   'matrix_sha256':hfile(matrix),'wdc_reference_csv_sha256':hfile(wdc),
   'authority':'offline-analysis-only; zero Rock n Roll Racing executable ROM contexts admitted by V02C',
 }
 (docs/'V02C-semantic-summary.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n',encoding='utf-8')
 print(json.dumps(summary,indent=2,sort_keys=True))
if __name__=='__main__': main()
