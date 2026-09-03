from __future__ import annotations

from dataclasses import dataclass, field
from typing import Callable

from analysis.v07c_scheduler_model import DmaRendezvous, Scheduler

TRANSFER_BYTE_COUNT = (1, 2, 2, 4, 4, 4, 2, 4)
TRANSFER_OFFSET = (
    (0, 0, 0, 0),
    (0, 1, 0, 1),
    (0, 0, 0, 0),
    (0, 0, 1, 1),
    (0, 1, 2, 3),
    (0, 1, 0, 1),
    (0, 0, 0, 0),
    (0, 0, 1, 1),
)


def _system_bank(bank: int) -> bool:
    bank &= 0xFF
    return bank <= 0x3F or 0x80 <= bank <= 0xBF


def is_wram_address(address: int) -> bool:
    address &= 0xFFFFFF
    bank = address >> 16
    off = address & 0xFFFF
    return bank in (0x7E, 0x7F) or (_system_bank(bank) and off <= 0x1FFF)


def _a_bus_hits_b_bus(address: int) -> bool:
    address &= 0xFFFFFF
    bank = address >> 16
    off = address & 0xFFFF
    return _system_bank(bank) and 0x2100 <= off <= 0x21FF


def _a_bus_hits_dma_controller(address: int) -> bool:
    address &= 0xFFFFFF
    bank = address >> 16
    off = address & 0xFFFF
    return _system_bank(bank) and (off in (0x420B, 0x420C) or 0x4300 <= off <= 0x437F)


@dataclass
class DmaChannel:
    src_address: int = 0xFFFF
    transfer_size: int = 0xFFFF
    hdma_table_address: int = 0xFFFF
    src_bank: int = 0xFF
    dest_address: int = 0xFF
    dma_active: bool = False
    invert_direction: bool = True
    decrement: bool = True
    fixed_transfer: bool = True
    hdma_indirect: bool = True
    transfer_mode: int = 7
    hdma_bank: int = 0xFF
    line_counter_repeat: int = 0xFF
    do_transfer: bool = False
    hdma_finished: bool = False
    unused_control: bool = True
    unused_register: int = 0xFF

    def dmap(self) -> int:
        return (
            (0x80 if self.invert_direction else 0)
            | (0x40 if self.hdma_indirect else 0)
            | (0x20 if self.unused_control else 0)
            | (0x10 if self.decrement else 0)
            | (0x08 if self.fixed_transfer else 0)
            | (self.transfer_mode & 7)
        )

    def set_dmap(self, value: int) -> None:
        value &= 0xFF
        self.invert_direction = bool(value & 0x80)
        self.hdma_indirect = bool(value & 0x40)
        self.unused_control = bool(value & 0x20)
        self.decrement = bool(value & 0x10)
        self.fixed_transfer = bool(value & 0x08)
        self.transfer_mode = value & 7


class DmaBus:
    """Abstract byte bus for the V08 controller model.

    Timing and SNES bus-A restrictions belong to DmaController. Device semantics
    remain supplied by the caller so V08 does not pretend to implement V09 PPU or
    later APU/input behavior.
    """

    def __init__(self) -> None:
        self.memory: dict[int, int] = {}
        self.events: list[tuple[str, int, int]] = []

    def read_a(self, address: int) -> int:
        address &= 0xFFFFFF
        value = self.memory.get(address, 0) & 0xFF
        self.events.append(("RA", address, value))
        return value

    def write_a(self, address: int, value: int) -> None:
        address &= 0xFFFFFF
        value &= 0xFF
        self.events.append(("WA", address, value))
        self.memory[address] = value

    def read_b(self, address: int) -> int:
        address &= 0xFFFF
        value = self.memory.get(address, 0) & 0xFF
        self.events.append(("RB", address, value))
        return value

    def write_b(self, address: int, value: int) -> None:
        address &= 0xFFFF
        value &= 0xFF
        self.events.append(("WB", address, value))
        self.memory[address] = value


@dataclass
class DmaController:
    scheduler: Scheduler
    bus: DmaBus
    channels: list[DmaChannel] = field(default_factory=lambda: [DmaChannel() for _ in range(8)])
    hdma_channels: int = 0
    open_bus: int = 0
    active_channel: int = 0xFF
    dma_clock_counter: int = 0
    transfer_bytes: int = 0
    bus_cycles: int = 0
    wram_restrictions: int = 0
    pending_mask: int = 0

    def reset(self) -> None:
        self.hdma_channels = 0
        self.scheduler.hdma_enable_mask = 0
        self.scheduler.manual_dma_mask = 0
        self.scheduler.dma_request = DmaRendezvous.NONE
        self.scheduler.dma_rendezvous_ready = DmaRendezvous.NONE
        self.scheduler.dma_start_delay = 0
        self.pending_mask = 0
        for ch in self.channels:
            ch.dma_active = False

    @staticmethod
    def _pending_bit(kind: DmaRendezvous) -> int:
        return 0 if kind == DmaRendezvous.NONE else 1 << (int(kind) - 1)

    @staticmethod
    def _highest_pending(mask: int) -> DmaRendezvous:
        if mask & 4:
            return DmaRendezvous.HDMA_LINE
        if mask & 2:
            return DmaRendezvous.HDMA_INIT
        if mask & 1:
            return DmaRendezvous.MANUAL
        return DmaRendezvous.NONE

    def _capture_scheduler_request(self) -> None:
        self.pending_mask |= self._pending_bit(self.scheduler.dma_request)

    def _restore_pending_request(self) -> None:
        if self.scheduler.dma_request == DmaRendezvous.NONE and self.pending_mask:
            self.scheduler.dma_request = self._highest_pending(self.pending_mask)
            self.scheduler.dma_start_delay = 0

    def _advance(self, clocks: int) -> None:
        self._capture_scheduler_request()
        self.scheduler.advance_cpu_master(clocks)
        self._capture_scheduler_request()

    def _advance_dma(self, clocks: int) -> None:
        self.dma_clock_counter += clocks
        self._advance(clocks)

    def _read_a(self, address: int) -> int:
        address &= 0xFFFFFF
        self._advance_dma(4)
        self.bus_cycles += 1
        if _a_bus_hits_b_bus(address) or _a_bus_hits_dma_controller(address):
            value = self.open_bus
        else:
            value = self.bus.read_a(address) & 0xFF
        self.open_bus = value
        return value

    def _write_a(self, address: int, value: int) -> None:
        address &= 0xFFFFFF
        value &= 0xFF
        self._advance_dma(4)
        self.bus_cycles += 1
        if not (_a_bus_hits_b_bus(address) or _a_bus_hits_dma_controller(address)):
            self.bus.write_a(address, value)
        self.open_bus = value

    def _read_b(self, address: int) -> int:
        address &= 0xFFFF
        self._advance_dma(4)
        self.bus_cycles += 1
        value = self.bus.read_b(address) & 0xFF
        self.open_bus = value
        return value

    def _write_b(self, address: int, value: int) -> None:
        address &= 0xFFFF
        value &= 0xFF
        self._advance_dma(4)
        self.bus_cycles += 1
        self.bus.write_b(address, value)
        self.open_bus = value

    def copy_dma_byte(self, address_a: int, address_b: int, from_b_to_a: bool) -> None:
        address_a &= 0xFFFFFF
        address_b &= 0xFFFF
        if from_b_to_a:
            if address_b == 0x2180 and is_wram_address(address_a):
                # $2180->WRAM performs no B read; the A write still occurs with invalid $FF.
                self._advance_dma(4)
                self.bus_cycles += 1
                self._write_a(address_a, 0xFF)
                self.wram_restrictions += 1
            else:
                self._write_a(address_a, self._read_b(address_b))
        else:
            if address_b == 0x2180 and is_wram_address(address_a):
                # WRAM->$2180 performs neither external access, but still costs one byte time.
                self._advance_dma(8)
                self.bus_cycles += 2
                self.wram_restrictions += 1
            else:
                self._write_b(address_b, self._read_a(address_a))
        self.transfer_bytes += 1

    def _sync_start(self) -> None:
        clocks = 8 - (self.scheduler.master_clock & 7)
        self.dma_clock_counter = 0
        self._advance_dma(clocks)

    def _sync_end(self, cpu_speed: int) -> None:
        if cpu_speed not in (6, 8, 12):
            raise ValueError(cpu_speed)
        clocks = cpu_speed - (self.dma_clock_counter % cpu_speed)
        self._advance(clocks)

    def _table_read(self, address: int) -> int:
        # HDMA table reads are 8 clocks: one 4-clock DMA read + one 4-clock internal phase.
        value = self._read_a(address)
        self._advance_dma(4)
        return value

    def write_register(self, address: int, value: int) -> None:
        address &= 0xFFFF
        value &= 0xFF
        if address == 0x420B:
            self.scheduler.manual_dma_mask = value
            for i, ch in enumerate(self.channels):
                if value & (1 << i):
                    ch.dma_active = True
            if value:
                self.scheduler.request_manual_dma(value)
                self.pending_mask |= 1
            return
        if address == 0x420C:
            self.hdma_channels = value
            self.scheduler.hdma_enable_mask = value
            return
        if not 0x4300 <= address <= 0x437F:
            raise ValueError(hex(address))
        ch = self.channels[(address & 0x70) >> 4]
        reg = address & 0x0F
        if reg == 0x0:
            ch.set_dmap(value)
        elif reg == 0x1:
            ch.dest_address = value
        elif reg == 0x2:
            ch.src_address = (ch.src_address & 0xFF00) | value
        elif reg == 0x3:
            ch.src_address = (ch.src_address & 0x00FF) | (value << 8)
        elif reg == 0x4:
            ch.src_bank = value
        elif reg == 0x5:
            ch.transfer_size = (ch.transfer_size & 0xFF00) | value
        elif reg == 0x6:
            ch.transfer_size = (ch.transfer_size & 0x00FF) | (value << 8)
        elif reg == 0x7:
            ch.hdma_bank = value
        elif reg == 0x8:
            ch.hdma_table_address = (ch.hdma_table_address & 0xFF00) | value
        elif reg == 0x9:
            ch.hdma_table_address = (ch.hdma_table_address & 0x00FF) | (value << 8)
        elif reg == 0xA:
            ch.line_counter_repeat = value
        elif reg in (0xB, 0xF):
            ch.unused_register = value
        # $43xC-$43xE are open/unimplemented registers and ignore writes.

    def read_register(self, address: int, open_bus: int | None = None) -> int:
        address &= 0xFFFF
        if not 0x4300 <= address <= 0x437F:
            raise ValueError(hex(address))
        ch = self.channels[(address & 0x70) >> 4]
        reg = address & 0x0F
        if reg == 0x0:
            return ch.dmap()
        if reg == 0x1:
            return ch.dest_address
        if reg == 0x2:
            return ch.src_address & 0xFF
        if reg == 0x3:
            return ch.src_address >> 8
        if reg == 0x4:
            return ch.src_bank
        if reg == 0x5:
            return ch.transfer_size & 0xFF
        if reg == 0x6:
            return ch.transfer_size >> 8
        if reg == 0x7:
            return ch.hdma_bank
        if reg == 0x8:
            return ch.hdma_table_address & 0xFF
        if reg == 0x9:
            return ch.hdma_table_address >> 8
        if reg == 0xA:
            return ch.line_counter_repeat
        if reg in (0xB, 0xF):
            return ch.unused_register
        return self.open_bus if open_bus is None else open_bus & 0xFF

    def _service_pending_during_dma(self, cpu_speed: int) -> None:
        # V08 preserves simultaneous requests instead of letting the V07 single
        # diagnostic request slot discard a lower-priority transfer.
        s = self.scheduler
        self._capture_scheduler_request()
        if not self.pending_mask:
            return
        if s.dma_start_delay:
            s.dma_start_delay -= 1
            return
        kind = self._highest_pending(self.pending_mask)
        self.pending_mask &= ~self._pending_bit(kind)
        if s.dma_request == kind:
            s.dma_request = DmaRendezvous.NONE
        if kind == DmaRendezvous.HDMA_LINE:
            self.process_hdma_line(cpu_speed, nested=True)
        elif kind == DmaRendezvous.HDMA_INIT:
            self.init_hdma(cpu_speed, nested=True)
        self._restore_pending_request()

    def _run_manual_channel(self, index: int, cpu_speed: int) -> None:
        ch = self.channels[index]
        if not ch.dma_active:
            return
        self.active_channel = index
        self._advance_dma(8)
        self._service_pending_during_dma(cpu_speed)
        offsets = TRANSFER_OFFSET[ch.transfer_mode]
        i = 0
        # uint16 DAS=$0000 means 65,536 bytes because the decrement wraps to $FFFF.
        while True:
            address_a = ((ch.src_bank & 0xFF) << 16) | (ch.src_address & 0xFFFF)
            address_b = 0x2100 | ((ch.dest_address + offsets[i & 3]) & 0xFF)
            self.copy_dma_byte(address_a, address_b, ch.invert_direction)
            if not ch.fixed_transfer:
                ch.src_address = (ch.src_address + (-1 if ch.decrement else 1)) & 0xFFFF
            ch.transfer_size = (ch.transfer_size - 1) & 0xFFFF
            i += 1
            self._service_pending_during_dma(cpu_speed)
            if ch.transfer_size == 0 or not ch.dma_active:
                break
        ch.dma_active = False

    def run_manual(self, cpu_speed: int = 8) -> None:
        if not any(ch.dma_active for ch in self.channels):
            return
        self._sync_start()
        self._advance_dma(8)
        self._service_pending_during_dma(cpu_speed)
        for i in range(8):
            self._run_manual_channel(i, cpu_speed)
        self._sync_end(cpu_speed)
        self.active_channel = 0xFF

    def init_hdma(self, cpu_speed: int = 8, *, nested: bool = False) -> bool:
        for ch in self.channels:
            ch.hdma_finished = False
            ch.do_transfer = False
        if not self.hdma_channels:
            return False
        need_sync = not any(ch.dma_active for ch in self.channels)
        if need_sync and not nested:
            self._sync_start()
        self._advance_dma(8)
        for i, ch in enumerate(self.channels):
            ch.do_transfer = True
            if not (self.hdma_channels & (1 << i)):
                continue
            ch.hdma_table_address = ch.src_address
            ch.dma_active = False
            ch.line_counter_repeat = self._table_read((ch.src_bank << 16) | ch.hdma_table_address)
            ch.hdma_table_address = (ch.hdma_table_address + 1) & 0xFFFF
            if ch.line_counter_repeat == 0:
                ch.hdma_finished = True
            if ch.hdma_indirect:
                lsb = self._table_read((ch.src_bank << 16) | ch.hdma_table_address)
                ch.hdma_table_address = (ch.hdma_table_address + 1) & 0xFFFF
                if not ch.hdma_finished:
                    msb = self._table_read((ch.src_bank << 16) | ch.hdma_table_address)
                    ch.hdma_table_address = (ch.hdma_table_address + 1) & 0xFFFF
                    ch.transfer_size = (msb << 8) | lsb
                else:
                    ch.transfer_size = lsb << 8
        if need_sync and not nested:
            self._sync_end(cpu_speed)
        return True

    def _run_hdma_transfer(self, index: int) -> None:
        ch = self.channels[index]
        ch.dma_active = False
        offsets = TRANSFER_OFFSET[ch.transfer_mode]
        count = TRANSFER_BYTE_COUNT[ch.transfer_mode]
        self.active_channel = 0x80 | index
        for i in range(count):
            if ch.hdma_indirect:
                address_a = (ch.hdma_bank << 16) | ch.transfer_size
                ch.transfer_size = (ch.transfer_size + 1) & 0xFFFF
            else:
                address_a = (ch.src_bank << 16) | ch.hdma_table_address
                ch.hdma_table_address = (ch.hdma_table_address + 1) & 0xFFFF
            address_b = 0x2100 | ((ch.dest_address + offsets[i]) & 0xFF)
            self.copy_dma_byte(address_a, address_b, ch.invert_direction)

    def _is_last_active_hdma_channel(self, index: int) -> bool:
        for i in range(index + 1, 8):
            if (self.hdma_channels & (1 << i)) and not self.channels[i].hdma_finished:
                return False
        return True

    def process_hdma_line(self, cpu_speed: int = 8, *, nested: bool = False) -> bool:
        if not self.hdma_channels:
            return False
        need_sync = not any(ch.dma_active for ch in self.channels)
        if need_sync and not nested:
            self._sync_start()
        self._advance_dma(8)
        original_active = self.active_channel
        for i, ch in enumerate(self.channels):
            if not (self.hdma_channels & (1 << i)) or ch.hdma_finished:
                continue
            ch.dma_active = False
            if ch.do_transfer:
                self._run_hdma_transfer(i)
        for i, ch in enumerate(self.channels):
            if not (self.hdma_channels & (1 << i)) or ch.hdma_finished:
                continue
            ch.line_counter_repeat = (ch.line_counter_repeat - 1) & 0xFF
            ch.do_transfer = bool(ch.line_counter_repeat & 0x80)
            new_counter = self._table_read((ch.src_bank << 16) | ch.hdma_table_address)
            if (ch.line_counter_repeat & 0x7F) == 0:
                ch.line_counter_repeat = new_counter
                ch.hdma_table_address = (ch.hdma_table_address + 1) & 0xFFFF
                if ch.hdma_indirect:
                    if ch.line_counter_repeat == 0 and self._is_last_active_hdma_channel(i):
                        msb = self._table_read((ch.src_bank << 16) | ch.hdma_table_address)
                        ch.hdma_table_address = (ch.hdma_table_address + 1) & 0xFFFF
                        ch.transfer_size = msb << 8
                    else:
                        lsb = self._table_read((ch.src_bank << 16) | ch.hdma_table_address)
                        ch.hdma_table_address = (ch.hdma_table_address + 1) & 0xFFFF
                        msb = self._table_read((ch.src_bank << 16) | ch.hdma_table_address)
                        ch.hdma_table_address = (ch.hdma_table_address + 1) & 0xFFFF
                        ch.transfer_size = (msb << 8) | lsb
                if ch.line_counter_repeat == 0:
                    ch.hdma_finished = True
                ch.do_transfer = True
        if need_sync and not nested:
            self._sync_end(cpu_speed)
        self.active_channel = original_active
        return True

    def process_ready_rendezvous(self, cpu_speed: int = 8) -> DmaRendezvous:
        self._capture_scheduler_request()
        kind = self.scheduler.consume_dma_rendezvous()
        self.pending_mask &= ~self._pending_bit(kind)
        if kind == DmaRendezvous.MANUAL:
            self.run_manual(cpu_speed)
        elif kind == DmaRendezvous.HDMA_INIT:
            self.init_hdma(cpu_speed)
        elif kind == DmaRendezvous.HDMA_LINE:
            self.process_hdma_line(cpu_speed)
        self._restore_pending_request()
        return kind
