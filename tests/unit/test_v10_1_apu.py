from __future__ import annotations
import hashlib,sys,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
if str(ROOT) not in sys.path: sys.path.insert(0,str(ROOT))
from analysis.v10_1_apu_model import *
ROM_PATH=None
class V10_1Apu(unittest.TestCase):
 @classmethod
 def setUpClass(cls):
  p=getattr(cls,'rom_path',None)
  if p is None:
   import os;p=os.environ.get('RNR_ROM')
  if not p: raise unittest.SkipTest('RNR_ROM not set')
  cls.rom=require_rom(Path(p));cls.records=parse_upload_records(cls.rom,4)
 def test_fixed_ipl_hash(self): self.assertEqual(IPL_SHA256,EXPECTED_IPL_SHA256)
 def test_exact_record_chain(self):
  got=[(x.selector,x.header_physical,x.size,x.destination,x.command_entry) for x in self.records]
  self.assertEqual(got,[(0,0x10000,4032,0x0400,0xFFC0),(1,0x10FC6,49936,0x3800,0xFFC0),(2,0x1D2DC,1105,0x1400,0xFFC0),(3,0x1D733,3295,0x2000,0x0400)])
 def test_totals_and_knownness(self):
  a,k,e=reconstruct_aram(self.rom,self.records);self.assertEqual(sum(x.size for x in self.records),58368);self.assertEqual(sum(k),58607);self.assertEqual(len(e),5);self.assertEqual(state_hash(a,k),'54e09724cf5839203d4a5515ef7e1fa70fdbf3b61c905e6cf222bb1d052f4a34')
 def test_ipl_clear_excludes_mmio(self):
  a,k,_=reconstruct_aram(self.rom,[]);self.assertTrue(all(k[x] for x in range(1,0xF0)));self.assertFalse(any(k[x] for x in range(0xF0,0x100)))
 def test_payloads_nonoverlap_and_in_range(self):
  used=set()
  for r in self.records:
   q=set(range(r.destination,r.destination+r.size));self.assertFalse(used&q);used|=q;self.assertLessEqual(r.destination+r.size,0x10000)
 def _send(self,p,r,final=False):
  self.assertEqual((p.read_cpu_port(0),p.read_cpu_port(1)),(0xAA,0xBB));p.write_cpu_port(0,0xFF);p.write_cpu_port(2,r.destination&255);p.write_cpu_port(3,r.destination>>8);p.write_cpu_port(1,1);p.write_cpu_port(0,0xCC);self.assertEqual(p.read_cpu_port(0),0xCC)
  data=self.rom[r.data_physical:r.data_physical+r.size]
  for i,b in enumerate(data):p.write_cpu_port(1,b);p.write_cpu_port(0,i&255);self.assertEqual(p.read_cpu_port(0),i&255)
  p.write_cpu_port(2,r.command_entry&255);p.write_cpu_port(3,r.command_entry>>8);p.write_cpu_port(1,0);term=(r.size+3)&255
  if final:
   with self.assertRaises(AotRequired) as cm:p.write_cpu_port(0,term)
   self.assertEqual(cm.exception.pc,0x0400);self.assertEqual(p.phase,'AOT_REQUIRED')
  else:
   p.write_cpu_port(0,term);self.assertEqual(p.phase,'RESTART_ACK');self.assertEqual(p.read_cpu_port(0),term);self.assertEqual((p.read_cpu_port(0),p.read_cpu_port(1)),(0xAA,0xBB))
 def test_protocol_replays_all_source_records(self):
  p=FixedIplProtocol()
  for i,r in enumerate(self.records):self._send(p,r,i==3)
  a,k,_=reconstruct_aram(self.rom,self.records);self.assertEqual(p.aram,a);self.assertEqual(p.known,k);self.assertEqual(p.entry_pc,0x0400)
 def test_counter_wrap_is_finite(self):
  p=FixedIplProtocol();r=self.records[0];self._send(p,r,False);self.assertEqual(p.phase,'WAIT_CC')
 def test_wrong_counter_fails_closed(self):
  p=FixedIplProtocol();p.write_cpu_port(2,0);p.write_cpu_port(3,4);p.write_cpu_port(0,0xCC);p.write_cpu_port(1,0x12)
  with self.assertRaises(IplProtocolError):p.write_cpu_port(0,7)
 def test_reset_preserves_aram_except_ipl_clear(self):
  p=FixedIplProtocol();p.aram[0x2222]=0x5A;p.known[0x2222]=1;p.aram[0x10]=0x99;p.reset();self.assertEqual((p.aram[0x2222],p.known[0x2222]),(0x5A,1));self.assertEqual((p.aram[0x10],p.known[0x10]),(0,1));self.assertEqual((p.read_cpu_port(0),p.read_cpu_port(1)),(0xAA,0xBB))
 def test_scheduler_sync_monotonic(self):
  p=FixedIplProtocol();p.sync(10);p.sync(10);p.sync(11)
  with self.assertRaises(IplProtocolError):p.sync(9)
 def test_unknown_aram_stays_unknown(self):
  _,k,_=reconstruct_aram(self.rom,self.records);self.assertEqual(sum(k),58607);self.assertEqual(k[0],0);self.assertEqual(k[0x0100],0);self.assertEqual(k[0x3000],0)
 def test_no_generic_spc_decoder_in_model(self):
  s=(ROOT/'analysis/v10_1_apu_model.py').read_text();self.assertNotIn('decode_opcode',s);self.assertNotIn('switch(opcode',s)
if __name__=='__main__':unittest.main()
