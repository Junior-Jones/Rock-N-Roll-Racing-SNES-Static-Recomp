"""Exhaustive/boundary 16-bit ADC/SBC checks against independent MesenCE transcription."""
import unittest
from analysis.w65c816.semantics import CPUState,SemanticEngine,C,Z,D,V,N
MASK_FLAGS=C|Z|V|N

def mesen_add16(a,b,c,decimal):
 if decimal:
  r=(a&0x0f)+(b&0x0f)+c
  if r>0x09:r+=0x06
  r=(a&0xf0)+(b&0xf0)+(0x10 if r>0x0f else 0)+(r&0x0f)
  if r>0x9f:r+=0x60
  r=(a&0xf00)+(b&0xf00)+(0x100 if r>0xff else 0)+(r&0xff)
  if r>0x9ff:r+=0x600
  r=(a&0xf000)+(b&0xf000)+(0x1000 if r>0xfff else 0)+(r&0xfff)
 else:r=a+b+c
 ov=bool((~(a^b)&(a^r)&0x8000))
 if decimal and r>0x9fff:r+=0x6000
 rr=r&0xffff; carry=r>0xffff
 return rr,(C if carry else 0)|(Z if rr==0 else 0)|(V if ov else 0)|(N if rr&0x8000 else 0)

def mesen_sub16(a,b,c,decimal):
 b=(~b)&0xffff
 if decimal:
  r=(a&0x0f)+(b&0x0f)+c
  if r<=0x0f:r-=0x06
  r=(a&0xf0)+(b&0xf0)+(0x10 if r>0x0f else 0)+(r&0x0f)
  if r<=0xff:r-=0x60
  r=(a&0xf00)+(b&0xf00)+(0x100 if r>0xff else 0)+(r&0xff)
  if r<=0xfff:r-=0x600
  r=(a&0xf000)+(b&0xf000)+(0x1000 if r>0xfff else 0)+(r&0xfff)
 else:r=a+b+c
 ov=bool((~(a^b)&(a^r)&0x8000))
 if decimal and r<=0xffff:r-=0x6000
 rr=r&0xffff; carry=r>0xffff
 return rr,(C if carry else 0)|(Z if rr==0 else 0)|(V if ov else 0)|(N if rr&0x8000 else 0)

def valid_bcd_values():
 for n in range(10000):
  yield ((n//1000)<<12)|(((n//100)%10)<<8)|(((n//10)%10)<<4)|(n%10)

class DecimalExhaustiveTests(unittest.TestCase):
 def run_domain(self,operation,reference,values,operands,decimal):
  s=CPUState(e=0,p=0); e=SemanticEngine(s); checked=0
  for a in values:
   for b in operands:
    for c in (0,1):
     s.a=a; s.p=(D if decimal else 0)|(C if c else 0)
     getattr(e,operation)(b,16)
     want_a,want_f=reference(a,b,c,decimal); got=(s.a,s.p&MASK_FLAGS)
     if got!=(want_a,want_f): self.fail(f'{operation} mismatch A={a:04X} B={b:04X} C={c} D={decimal}: got {got}, want {(want_a,want_f)}')
     checked+=1
  return checked
 def test_full_binary_a_domain_boundary_operands(self):
  operands=(0x0000,0x0001,0x007f,0x0080,0x00ff,0x7fff,0x8000,0xffff)
  self.assertEqual(65536*len(operands)*2,self.run_domain('adc',mesen_add16,range(65536),operands,False))
  self.assertEqual(65536*len(operands)*2,self.run_domain('sbc',mesen_sub16,range(65536),operands,False))
 def test_entire_valid_four_digit_bcd_a_domain(self):
  vals=tuple(valid_bcd_values()); self.assertEqual(10000,len(vals)); operands=(0x0000,0x0001,0x0009,0x0010,0x0099,0x0100,0x0999,0x9999)
  self.assertEqual(10000*len(operands)*2,self.run_domain('adc',mesen_add16,vals,operands,True))
  self.assertEqual(10000*len(operands)*2,self.run_domain('sbc',mesen_sub16,vals,operands,True))
 def test_full_decimal_bitpattern_a_domain_valid_and_invalid_boundaries(self):
  operands=(0x0000,0x0009,0x000a,0x0099,0x009a,0x0999,0x0a00,0x9999,0x9a99,0xffff)
  self.assertEqual(65536*len(operands)*2,self.run_domain('adc',mesen_add16,range(65536),operands,True))
  self.assertEqual(65536*len(operands)*2,self.run_domain('sbc',mesen_sub16,range(65536),operands,True))
if __name__=='__main__': unittest.main()
