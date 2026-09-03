import csv,hashlib,json,sys,unittest
from pathlib import Path
P=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(P))
from analysis.v06c_machine_model import *
ROM_PATH=Path('/mnt/data/Rock n\' Roll Racing (USA).sfc')

def rom(): return ROM_PATH.read_bytes()
def csv_rows(path):
 with path.open(newline='',encoding='utf-8') as f:return list(csv.DictReader(f))

class V06MachineTests(unittest.TestCase):
 def test_01_mapping_boundaries_and_exact_lorom(self):
  cases={0x000000:Region.WRAM,0x001FFF:Region.WRAM,0x002000:Region.OPEN_BUS,0x002100:Region.PPU,0x00213F:Region.PPU,0x002140:Region.APU,0x00217F:Region.APU,0x002180:Region.WRAM_PORT,0x002183:Region.WRAM_PORT,0x004016:Region.INPUT,0x004200:Region.CPU_IO,0x004217:Region.CPU_IO,0x004218:Region.INPUT,0x004300:Region.DMA,0x00437F:Region.DMA,0x008000:Region.ROM,0x7E0000:Region.WRAM,0x7FFFFF:Region.WRAM,0x808000:Region.ROM,0xFF8000:Region.ROM}
  for a,r in cases.items(): self.assertEqual(classify_address(a),r,hex(a))
  self.assertEqual(lorom_offset(0x008000),0);self.assertEqual(lorom_offset(0x808000),0)
  self.assertEqual(lorom_offset(0x1FFFFF),0xFFFFF);self.assertEqual(lorom_offset(0x9FFFFF),0xFFFFF)
  self.assertIsNone(lorom_offset(0x7E8000));self.assertIsNone(lorom_offset(0x7F8000))

 def test_02_pregenerated_full_census_is_total_and_zero_sram(self):
  rows=csv_rows(P/'docs/V06C-bus-census.csv')
  got={r['Region']:int(r['Address_Count']) for r in rows}
  exp={'ROM':8323072,'OPEN_BUS':7236864,'WRAM':1179648,'DMA':16384,'PPU':8192,'APU':8192,'CPU_IO':3072,'INPUT':1280,'WRAM_PORT':512}
  self.assertEqual(got,exp);self.assertEqual(sum(got.values()),1<<24);self.assertNotIn('SRAM',got)

 def test_03_timing_boundaries_and_memsel(self):
  self.assertEqual(access_clocks(0x000000,0),8);self.assertEqual(access_clocks(0x002000,0),6)
  self.assertEqual(access_clocks(0x004000,0),12);self.assertEqual(access_clocks(0x004200,0),6)
  self.assertEqual(access_clocks(0x006000,0),8);self.assertEqual(access_clocks(0x008000,1),8)
  self.assertEqual(access_clocks(0x808000,0),8);self.assertEqual(access_clocks(0x808000,1),6)
  self.assertEqual(access_clocks(0xC00000,0),8);self.assertEqual(access_clocks(0xC00000,1),6)
  rows=csv_rows(P/'docs/V06C-speed-census.csv');self.assertEqual(sum(int(r['Cell_Count']) for r in rows),131072)

 def test_04_power_on_reset_is_untimed_and_reset_preserves_machine_state(self):
  m=Machine(rom());m.power_on();self.assertEqual(m.cpu.pc,0x8000);self.assertEqual(m.access_clock_sum,0)
  m.wram[0x1234]=0xA5;m.wram_position=0x12345;m.open_bus=0x7B;m.memsel=1;m.io_port_output=0x42;m.htimer=0x166;m.vtimer=0x155
  m.alu.mult_operand1=0x12;m.alu.dividend=0x3456;m.cpu.a=0xBEEF;m.cpu.x=0xCAFE;m.cpu.y=0xBABE;m.cpu.s=0x12A5;m.cpu.p=0xFF
  m.reset();self.assertEqual(m.access_clock_sum,0);self.assertEqual(m.cpu.pc,0x8000);self.assertEqual(m.wram[0x1234],0xA5);self.assertEqual(m.wram_position,0x12345);self.assertEqual(m.open_bus,0x7B);self.assertEqual(m.memsel,1);self.assertEqual(m.io_port_output,0x42);self.assertEqual(m.htimer,0x166);self.assertEqual(m.vtimer,0x155);self.assertEqual(m.alu.mult_operand1,0x12);self.assertEqual(m.alu.dividend,0x3456);self.assertEqual(m.cpu.a,0xBEEF);self.assertEqual(m.cpu.x,0xFE);self.assertEqual(m.cpu.y,0xBE);self.assertEqual(m.cpu.s,0x1A5);self.assertTrue(m.cpu.e);self.assertEqual(m.cpu.dbr,0);self.assertEqual(m.cpu.d,0);self.assertEqual(m.cpu.pbr,0);self.assertTrue(m.cpu.p&0x04);self.assertTrue(m.cpu.p&0x20);self.assertTrue(m.cpu.p&0x10);self.assertFalse(m.cpu.p&0x08)

 def test_05_wram_mirrors_port_and_open_bus(self):
  m=Machine(rom());m.power_on();m.write8(0x7E1234,0x66);self.assertEqual(m.read8(0x001234),0x66)
  m.write8(0x002181,0x34);m.write8(0x002182,0x12);m.write8(0x002183,0x01);m.write8(0x002180,0xAB);self.assertEqual(m.wram[0x11234],0xAB);self.assertEqual(m.wram_position,0x11235)
  _=m.read8(0x008000);v=m.open_bus;self.assertEqual(m.read8(0x006000),v)
  before=m.open_bus;m.write8(0x006000,0x5A);self.assertEqual(m.open_bus,before)

 def test_06_component_failures_are_distinct(self):
  m=Machine(rom());m.power_on()
  for a,r in [(0x002100,StopReason.PPU_UNAVAILABLE),(0x002140,StopReason.APU_UNAVAILABLE),(0x004300,StopReason.DMA_UNAVAILABLE),(0x004016,StopReason.INPUT_UNAVAILABLE),(0x004210,StopReason.TIMING_UNAVAILABLE)]:
   with self.assertRaises(MachineStop) as cm:m.read8(a)
   self.assertEqual(cm.exception.reason,r)
  with self.assertRaises(MachineStop) as cm:m.write8(0x008000,1)
  self.assertEqual(cm.exception.reason,StopReason.ROM_WRITE)

 def test_07_alu_final_busy_and_partial(self):
  m=Machine(rom());m.power_on();m.write8(0x004202,13);m.write8(0x004203,17)
  self.assertEqual(m.alu.mult_counter,8);m.cpu_cycle_count+=4;m.alu.run(m.cpu_cycle_count,False);self.assertEqual(m.alu.mult_counter,4)
  m.cpu_cycle_count+=4;m.alu.run(m.cpu_cycle_count,False);self.assertEqual(m.alu.mult_counter,0);self.assertEqual(m.alu.mult_or_remainder,221)
  # Busy write clears result but does not restart another operation.
  m.write8(0x004202,9);m.write8(0x004203,9);self.assertEqual(m.alu.mult_counter,8);m.write8(0x004203,7);self.assertLessEqual(m.alu.mult_counter,8)
  m=Machine(rom());m.power_on();m.write8(0x004204,0x34);m.write8(0x004205,0x12);m.write8(0x004206,0x11);m.cpu_cycle_count+=16;m.alu.run(m.cpu_cycle_count,False);self.assertEqual(m.alu.div_result,0x1234//0x11);self.assertEqual(m.alu.mult_or_remainder,0x1234%0x11)
  m=Machine(rom());m.power_on();m.write8(0x004204,0x34);m.write8(0x004205,0x12);m.write8(0x004206,0);m.cpu_cycle_count+=16;m.alu.run(m.cpu_cycle_count,False);self.assertEqual(m.alu.div_result,0xFFFF);self.assertEqual(m.alu.mult_or_remainder,0x1234)

 def test_08_fetch_projection_is_exact_and_does_not_promote(self):
  v5={r['Key_Hex']:r for r in csv_rows(P/'docs/V05C-production-manifest.csv')}
  v6={r['Key_Hex']:r for r in csv_rows(P/'docs/V06C-fetch-manifest.csv')}
  self.assertEqual(set(v5),set(v6));self.assertEqual(len(v6),2258);self.assertEqual(len({r['Shard'] for r in v6.values()}),18)
  rb=rom()
  for k,r in v6.items():
   self.assertEqual(r['Bytes'],v5[k]['Bytes']);pbr=int(r['PBR'],16);pc=int(r['PC'],16)
   for i,b in enumerate(bytes.fromhex(r['Bytes'])):self.assertEqual(rb[lorom_offset((pbr<<16)|((pc+i)&0xFFFF))],b)
  s=json.loads((P/'docs/V06C-machine-summary.json').read_text());self.assertEqual(s['v05_context_promotion_count'],0);self.assertEqual(s['gameplay_promotion_count'],0);self.assertEqual(s['trace_promotion_count'],0);self.assertEqual(s['oracle_promotion_count'],0)

 def test_09_generated_source_has_no_runtime_decoder_or_master_clock_total(self):
  text=(P/'runtime/v06c_machine.c').read_text()+''.join(x.read_text() for x in sorted((P/'generated/current/v06c').glob('*.c')))
  self.assertNotIn('RunOp',text);self.assertNotIn('opcode decoder',text.lower());self.assertNotIn('master_clock',text);self.assertIn('access_clock_sum',text);self.assertIn('& 0x1Fu',text);self.assertNotIn('% JSV06_ROM_SIZE',text)

if __name__=='__main__':unittest.main()
