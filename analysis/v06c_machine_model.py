"""V06C target-specific SNES bus/base-machine proof model.

Offline/project-owned qualification model. This is not linked into production and
never discovers or promotes executable contexts. It exists to prove the generated
V06C machine source against the exact cartridge profile and fixed V05C authority.
"""
from __future__ import annotations
from dataclasses import dataclass, field
from enum import IntEnum
from typing import Optional

ROM_SIZE = 0x100000
WRAM_SIZE = 0x20000
ROM_SHA256 = "9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182"

class Region(IntEnum):
    OPEN_BUS=0; ROM=1; WRAM=2; PPU=3; APU=4; WRAM_PORT=5; CPU_IO=6; INPUT=7; DMA=8

class StopReason(IntEnum):
    NONE=0
    PPU_UNAVAILABLE=1
    APU_UNAVAILABLE=2
    DMA_UNAVAILABLE=3
    INPUT_UNAVAILABLE=4
    TIMING_UNAVAILABLE=5
    ROM_WRITE=6
    STATIC_CODE_MISMATCH=7
    UNKNOWN_CONTEXT=8
    V05_STOP=9
    INVALID_MACHINE=10

REGION_NAMES={r:r.name for r in Region}

def is_system_bank(bank:int)->bool:
    return bank <= 0x3F or 0x80 <= bank <= 0xBF

def classify_address(address:int)->Region:
    address &= 0xFFFFFF
    bank=(address>>16)&0xFF; off=address&0xFFFF
    if bank in (0x7E,0x7F): return Region.WRAM
    if is_system_bank(bank):
        if off <= 0x1FFF: return Region.WRAM
        if 0x2100 <= off <= 0x213F: return Region.PPU
        if 0x2140 <= off <= 0x217F: return Region.APU
        if 0x2180 <= off <= 0x2183: return Region.WRAM_PORT
        if off in (0x4016,0x4017) or 0x4218 <= off <= 0x421F: return Region.INPUT
        if 0x4200 <= off <= 0x4217: return Region.CPU_IO
        if 0x4300 <= off <= 0x437F: return Region.DMA
    if off >= 0x8000: return Region.ROM
    return Region.OPEN_BUS

def lorom_offset(address:int)->Optional[int]:
    address &= 0xFFFFFF
    bank=(address>>16)&0xFF; off=address&0xFFFF
    if bank in (0x7E,0x7F) or off < 0x8000: return None
    # Exact 1 MiB LoROM decoder: 32 physical 32 KiB banks. This is a mask
    # derived from the target's ROM size/board decode, not ROM-size modulo.
    return ((bank & 0x1F) << 15) | (off & 0x7FFF)

def wram_offset(address:int)->Optional[int]:
    address &= 0xFFFFFF
    bank=(address>>16)&0xFF; off=address&0xFFFF
    if bank==0x7E: return off
    if bank==0x7F: return 0x10000|off
    if is_system_bank(bank) and off<=0x1FFF: return off
    return None

def access_clocks(address:int, memsel:int)->int:
    """S-CPU address-class access duration, before V07 timeline placement."""
    address &= 0xFFFFFF
    bank_group=(address>>22)&3
    page=(address>>8)&0xFF
    fast=1 if memsel else 0
    if bank_group==1: return 8                     # $40-$7F
    if bank_group==3: return 6 if fast else 8     # $C0-$FF
    if page<=0x1F: return 8
    if page<=0x3F: return 6
    if page<=0x41: return 12
    if page<=0x5F: return 6
    if page<=0x7F: return 8
    if bank_group==0: return 8                     # $00-$3F:$8000+
    return 6 if fast else 8                        # $80-$BF:$8000+

@dataclass
class CpuState:
    a:int=0; x:int=0; y:int=0; d:int=0; s:int=0x1FF; pc:int=0
    dbr:int=0; pbr:int=0; p:int=0x34; e:int=1

@dataclass
class AluState:
    mult_operand1:int=0xFF
    mult_operand2:int=0
    mult_or_remainder:int=0
    dividend:int=0xFFFF
    divisor:int=0
    div_result:int=0
    shift:int=0
    mult_counter:int=0
    div_counter:int=0
    prev_cpu_cycle:int=0

    def run(self,cpu_cycle:int,is_read:bool)->None:
        target=cpu_cycle-(1 if is_read else 0)
        if target < self.prev_cpu_cycle:
            target=self.prev_cpu_cycle
        cycles=target-self.prev_cpu_cycle
        while cycles:
            cycles-=1
            if not self.mult_counter and not self.div_counter: break
            if self.mult_counter:
                self.mult_counter-=1
                if self.div_result & 1:
                    self.mult_or_remainder=(self.mult_or_remainder+self.shift)&0xFFFF
                self.shift=(self.shift<<1)&0xFFFFFFFF
                self.div_result=(self.div_result>>1)&0xFFFF
            if self.div_counter:
                self.div_counter-=1
                self.shift >>= 1
                self.div_result=(self.div_result<<1)&0xFFFF
                if self.mult_or_remainder >= self.shift:
                    self.mult_or_remainder=(self.mult_or_remainder-self.shift)&0xFFFF
                    self.div_result |= 1
        self.prev_cpu_cycle=target

    def read(self,addr:int,cpu_cycle:int)->int:
        self.run(cpu_cycle,True)
        if addr==0x4214:return self.div_result&0xFF
        if addr==0x4215:return (self.div_result>>8)&0xFF
        if addr==0x4216:return self.mult_or_remainder&0xFF
        if addr==0x4217:return (self.mult_or_remainder>>8)&0xFF
        raise ValueError(hex(addr))

    def write(self,addr:int,value:int,cpu_cycle:int)->None:
        value &= 0xFF
        self.run(cpu_cycle,True)
        block=bool(self.div_counter or self.mult_counter)
        self.run(cpu_cycle,False)
        if addr==0x4202:
            self.mult_operand1=value
        elif addr==0x4203:
            self.mult_or_remainder=0
            if not block:
                self.mult_counter=8; self.mult_operand2=value
                self.div_result=((value<<8)|self.mult_operand1)&0xFFFF
                self.shift=value
            elif block and not self.div_counter and not self.mult_counter:
                self.div_result=((value<<8)|self.mult_operand1)&0xFFFF
        elif addr==0x4204:
            self.dividend=(self.dividend&0xFF00)|value
        elif addr==0x4205:
            self.dividend=(self.dividend&0x00FF)|(value<<8)
        elif addr==0x4206:
            self.mult_or_remainder=self.dividend
            if not block:
                self.div_counter=16; self.divisor=value; self.shift=value<<16
        else: raise ValueError(hex(addr))

@dataclass
class Machine:
    rom:bytes
    wram:bytearray=field(default_factory=lambda:bytearray(WRAM_SIZE))
    cpu:CpuState=field(default_factory=CpuState)
    alu:AluState=field(default_factory=AluState)
    wram_position:int=0
    open_bus:int=0
    memsel:int=0
    nmitimen:int=0
    io_port_output:int=0xFF
    htimer:int=0x1FF
    vtimer:int=0x1FF
    access_clock_sum:int=0
    cpu_cycle_count:int=0
    stop_reason:StopReason=StopReason.NONE
    stop_address:int=0
    stop_value:int=0

    def __post_init__(self):
        if len(self.rom)!=ROM_SIZE: raise ValueError("exact 1 MiB ROM required")

    def _reset_stop(self): self.stop_reason=StopReason.NONE; self.stop_address=0; self.stop_value=0
    def _stop(self,r:StopReason,a:int,v:int=0)->None:
        self.stop_reason=r; self.stop_address=a&0xFFFFFF; self.stop_value=v&0xFF
        raise MachineStop(r,a,v)
    def _begin_access(self,address:int):
        self.cpu_cycle_count += 1
        self.access_clock_sum += access_clocks(address,self.memsel)
    def cpu_internal_cycle(self): self.cpu_cycle_count += 1

    def peek8(self,address:int)->int:
        address &= 0xFFFFFF; r=classify_address(address)
        if r==Region.ROM:
            o=lorom_offset(address); assert o is not None; return self.rom[o]
        if r==Region.WRAM:
            o=wram_offset(address); assert o is not None; return self.wram[o]
        if r==Region.WRAM_PORT and (address&0xFFFF)==0x2180: return self.wram[self.wram_position]
        if r==Region.CPU_IO:
            off=address&0xFFFF
            if off==0x4213:return self.io_port_output
            if 0x4214<=off<=0x4217:
                # Untimed peek does not advance the ALU.
                if off==0x4214:return self.alu.div_result&0xFF
                if off==0x4215:return (self.alu.div_result>>8)&0xFF
                if off==0x4216:return self.alu.mult_or_remainder&0xFF
                return (self.alu.mult_or_remainder>>8)&0xFF
        return self.open_bus

    def reset_vector(self)->int:
        # Side-effect-free untimed vector sampling before V07 scheduler ownership.
        return self.peek8(0x00FFFC) | (self.peek8(0x00FFFD)<<8)

    def power_on(self,initial_wram:Optional[bytes]=None)->None:
        if initial_wram is None: self.wram[:] = b'\0'*WRAM_SIZE
        else:
            if len(initial_wram)!=WRAM_SIZE: raise ValueError("WRAM image size")
            self.wram[:]=initial_wram
        self.wram_position=0; self.open_bus=0; self.memsel=0; self.nmitimen=0
        self.io_port_output=0xFF; self.htimer=0x1FF; self.vtimer=0x1FF
        self.access_clock_sum=0; self.cpu_cycle_count=0; self.alu=AluState(); self._reset_stop()
        self.cpu=CpuState(pc=self.reset_vector())

    def reset(self)->None:
        # Preserve WRAM, open bus, WRAM port, MEMSEL, timer/output latches and ALU;
        # reset only CPU/reset-owned state and interrupt enables.
        c=self.cpu
        c.p=((c.p|0x34)&~0x08)&0xFF; c.e=1; c.dbr=0; c.d=0; c.pbr=0
        c.x &= 0xFF; c.y &= 0xFF; c.s=0x0100|(c.s&0xFF); c.pc=self.reset_vector()
        self.nmitimen=0; self.access_clock_sum=0; self.cpu_cycle_count=0; self._reset_stop()

    def read8(self,address:int)->int:
        address &= 0xFFFFFF; self._begin_access(address); r=classify_address(address); off=address&0xFFFF
        if r==Region.ROM:
            o=lorom_offset(address); assert o is not None; v=self.rom[o]; self.open_bus=v; return v
        if r==Region.WRAM:
            o=wram_offset(address); assert o is not None; v=self.wram[o]; self.open_bus=v; return v
        if r==Region.OPEN_BUS: return self.open_bus
        if r==Region.PPU:self._stop(StopReason.PPU_UNAVAILABLE,address)
        if r==Region.APU:self._stop(StopReason.APU_UNAVAILABLE,address)
        if r==Region.DMA:self._stop(StopReason.DMA_UNAVAILABLE,address)
        if r==Region.INPUT:self._stop(StopReason.INPUT_UNAVAILABLE,address)
        if r==Region.WRAM_PORT:
            if off==0x2180:
                v=self.wram[self.wram_position]; self.wram_position=(self.wram_position+1)&0x1FFFF; self.open_bus=v; return v
            return self.open_bus
        if r==Region.CPU_IO:
            if off in (0x4210,0x4211,0x4212): self._stop(StopReason.TIMING_UNAVAILABLE,address)
            if off==0x4213:return self.io_port_output
            if 0x4214<=off<=0x4217:return self.alu.read(off,self.cpu_cycle_count)
            return self.open_bus
        raise AssertionError(r)

    def write8(self,address:int,value:int)->None:
        address &= 0xFFFFFF; value &= 0xFF; self._begin_access(address); r=classify_address(address); off=address&0xFFFF
        if r==Region.ROM:self._stop(StopReason.ROM_WRITE,address,value)
        if r==Region.WRAM:
            o=wram_offset(address); assert o is not None; self.wram[o]=value; return
        if r==Region.OPEN_BUS:return
        if r==Region.PPU:self._stop(StopReason.PPU_UNAVAILABLE,address,value)
        if r==Region.APU:self._stop(StopReason.APU_UNAVAILABLE,address,value)
        if r==Region.DMA:self._stop(StopReason.DMA_UNAVAILABLE,address,value)
        if r==Region.INPUT:self._stop(StopReason.INPUT_UNAVAILABLE,address,value)
        if r==Region.WRAM_PORT:
            if off==0x2180:self.wram[self.wram_position]=value; self.wram_position=(self.wram_position+1)&0x1FFFF
            elif off==0x2181:self.wram_position=(self.wram_position&0x1FF00)|value
            elif off==0x2182:self.wram_position=(self.wram_position&0x100FF)|(value<<8)
            elif off==0x2183:self.wram_position=(self.wram_position&0x0FFFF)|((value&1)<<16)
            return
        if r==Region.CPU_IO:
            if off==0x4200:self.nmitimen=value; return
            if off==0x4201:self.io_port_output=value; return
            if 0x4202<=off<=0x4206:self.alu.write(off,value,self.cpu_cycle_count); return
            if off==0x4207:self.htimer=(self.htimer&0x100)|value; return
            if off==0x4208:self.htimer=(self.htimer&0xFF)|((value&1)<<8); return
            if off==0x4209:self.vtimer=(self.vtimer&0x100)|value; return
            if off==0x420A:self.vtimer=(self.vtimer&0xFF)|((value&1)<<8); return
            if off in (0x420B,0x420C): self._stop(StopReason.DMA_UNAVAILABLE,address,value)
            if off==0x420D:self.memsel=value&1; return
            return
        raise AssertionError(r)

class MachineStop(RuntimeError):
    def __init__(self,reason:StopReason,address:int,value:int=0):
        self.reason=reason; self.address=address&0xFFFFFF; self.value=value&0xFF
        super().__init__(f"{reason.name} at {self.address:06X}")
