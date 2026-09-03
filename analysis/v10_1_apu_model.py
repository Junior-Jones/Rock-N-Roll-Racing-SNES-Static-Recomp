from __future__ import annotations
from dataclasses import dataclass, field
import hashlib
from pathlib import Path

ROM_SHA256 = '9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182'
IPL_BYTES = bytes([
    0xCD,0xEF,0xBD,0xE8,0x00,0xC6,0x1D,0xD0,0xFC,0x8F,0xAA,0xF4,0x8F,0xBB,0xF5,0x78,
    0xCC,0xF4,0xD0,0xFB,0x2F,0x19,0xEB,0xF4,0xD0,0xFC,0x7E,0xF4,0xD0,0x0B,0xE4,0xF5,
    0xCB,0xF4,0xD7,0x00,0xFC,0xD0,0xF3,0xAB,0x01,0x10,0xEF,0x7E,0xF4,0x10,0xEB,0xBA,
    0xF6,0xDA,0x00,0xBA,0xF4,0xC4,0xF4,0xDD,0x5D,0xD0,0xDB,0x1F,0x00,0x00,0xC0,0xFF,
])
IPL_SHA256 = hashlib.sha256(IPL_BYTES).hexdigest()
EXPECTED_IPL_SHA256 = 'c95f88b299030d5afa55b1031e2b5ef2dff650c4b4e6bb6f8b1359436521278f'
assert IPL_SHA256 == EXPECTED_IPL_SHA256
ARAM_SIZE = 0x10000
TABLE_PHYSICAL = 0x10000  # LoROM $82:8000
RESET_UPLOAD_CALLS = (
    ('80:F8E0','0078E0',0),('80:F8E5','0078E5',1),('80:F8EA','0078EA',2),('80:F8EF','0078EF',3),
)

@dataclass(frozen=True)
class UploadRecord:
    selector: int
    header_physical: int
    header_cpu: str
    size: int
    destination: int
    entry_field: int
    command_entry: int
    data_physical: int
    data_sha256: str

    @property
    def end_destination(self) -> int:
        return (self.destination + self.size - 1) & 0xFFFF


def require_rom(path: Path) -> bytes:
    data = path.read_bytes()
    got = hashlib.sha256(data).hexdigest()
    if got != ROM_SHA256:
        raise ValueError(f'wrong ROM sha256 {got}')
    if len(data) != 0x100000:
        raise ValueError(f'wrong ROM size {len(data)}')
    return data


def physical_to_lorom_cpu(p: int) -> str:
    if not (0 <= p < 0x100000):
        raise ValueError(p)
    bank = (p // 0x8000) & 0x1F
    off = 0x8000 | (p & 0x7FFF)
    return f'{0x80|bank:02X}:{off:04X}'


def parse_upload_records(rom: bytes, count: int = 4) -> list[UploadRecord]:
    out: list[UploadRecord] = []
    p = TABLE_PHYSICAL
    for selector in range(count):
        if p + 6 > len(rom):
            raise ValueError('record header outside ROM')
        size = int.from_bytes(rom[p:p+2], 'little')
        destination = int.from_bytes(rom[p+2:p+4], 'little')
        entry = int.from_bytes(rom[p+4:p+6], 'little')
        if size == 0 or p + 6 + size > len(rom):
            raise ValueError(f'invalid upload record {selector}')
        data = rom[p+6:p+6+size]
        command_entry = entry if entry else 0xFFC0
        out.append(UploadRecord(
            selector=selector,
            header_physical=p,
            header_cpu=physical_to_lorom_cpu(p),
            size=size,
            destination=destination,
            entry_field=entry,
            command_entry=command_entry,
            data_physical=p+6,
            data_sha256=hashlib.sha256(data).hexdigest(),
        ))
        p += 6 + size
    return out


def reconstruct_aram(rom: bytes, records: list[UploadRecord]) -> tuple[bytearray, bytearray, list[dict]]:
    aram = bytearray(ARAM_SIZE)
    known = bytearray(ARAM_SIZE)
    # The fixed IPL's first loop clears $0001-$00EF. MMIO $00F0-$00FF is not
    # promoted to ordinary ARAM knowledge merely because register writes touch it.
    for a in range(0x0001, 0x00F0):
        aram[a] = 0
        known[a] = 1
    epochs = [{
        'Epoch': 'IPL_BOOT', 'Selector': '', 'Start': '0001', 'End': '00EF',
        'Byte_Count': 0xEF, 'Entry': 'FFC0', 'Provenance': 'FIXED_IPL_CLEAR',
    }]
    for rec in records:
        end = rec.destination + rec.size
        if end > ARAM_SIZE:
            raise ValueError(f'record {rec.selector} wraps ARAM')
        # The reset bootstrap records are source-proved non-overlapping with
        # previously uploaded ranges; repeat IPL clears are idempotent.
        for a in range(rec.destination, end):
            if known[a] and not (0x0001 <= a < 0x00F0):
                raise ValueError(f'unproved bootstrap overlap at {a:04X}')
        payload = rom[rec.data_physical:rec.data_physical+rec.size]
        aram[rec.destination:end] = payload
        known[rec.destination:end] = b'\x01' * rec.size
        epochs.append({
            'Epoch': f'UPLOAD_{rec.selector}', 'Selector': str(rec.selector),
            'Start': f'{rec.destination:04X}', 'End': f'{rec.end_destination:04X}',
            'Byte_Count': rec.size, 'Entry': f'{rec.command_entry:04X}',
            'Provenance': f'ROM_RECORD_{rec.selector}',
        })
    return aram, known, epochs


def state_hash(aram: bytes, known: bytes) -> str:
    h = hashlib.sha256()
    h.update(b'RNR-V10.1-ARAM\0')
    h.update(bytes(aram))
    h.update(bytes(known))
    return h.hexdigest()


class IplProtocolError(RuntimeError): pass
class AotRequired(RuntimeError):
    def __init__(self, pc: int):
        self.pc = pc
        super().__init__(f'static SPC700 AOT required at ${pc:04X}')

@dataclass
class FixedIplProtocol:
    """Dedicated standard-SNES IPL transfer protocol model.

    This is deliberately not a generic SPC700 decoder. It owns only the fixed IPL
    handshake/upload contract needed before V10.2 exact-PC SPC700 AOT.
    """
    aram: bytearray = field(default_factory=lambda: bytearray(ARAM_SIZE))
    known: bytearray = field(default_factory=lambda: bytearray(ARAM_SIZE))
    cpu_to_smp: bytearray = field(default_factory=lambda: bytearray(4))
    smp_to_cpu: bytearray = field(default_factory=lambda: bytearray(4))
    phase: str = 'WAIT_CC'
    destination: int = 0
    expected_counter: int = 0
    bytes_written: int = 0
    entry_pc: int = 0xFFC0
    last_smp_target_cycle: int = 0
    restart_ack_pending: bool = False

    def __post_init__(self):
        self.ipl_restart(initial=True)

    def ipl_restart(self, initial: bool = False):
        for a in range(0x0001,0x00F0):
            self.aram[a] = 0
            self.known[a] = 1
        self.phase = 'WAIT_CC'
        self.destination = 0
        self.expected_counter = 0
        self.bytes_written = 0
        self.entry_pc = 0xFFC0
        self.smp_to_cpu[0] = 0xAA
        self.smp_to_cpu[1] = 0xBB
        if initial:
            self.smp_to_cpu[2] = self.smp_to_cpu[3] = 0
        self.restart_ack_pending = False

    def reset(self):
        """Reset S-SMP registers/IPL state while preserving ARAM storage/knownness."""
        self.cpu_to_smp[:] = b"\x00" * 4
        self.smp_to_cpu[:] = b"\x00" * 4
        self.ipl_restart(initial=True)

    def sync(self, smp_target_cycle: int):
        if smp_target_cycle < self.last_smp_target_cycle:
            raise IplProtocolError('S-SMP target cycle moved backwards')
        self.last_smp_target_cycle = smp_target_cycle

    def read_cpu_port(self, port: int) -> int:
        port &= 3
        v = self.smp_to_cpu[port]
        if port == 0 and self.phase == 'RESTART_ACK':
            # The host uploader observes the terminator echo, then the fixed IPL
            # restarts and exposes AA/BB for the next call.
            self.ipl_restart()
        return v

    def write_cpu_port(self, port: int, value: int):
        port &= 3; value &= 0xFF
        self.cpu_to_smp[port] = value
        if port != 0:
            return
        if self.phase == 'WAIT_CC':
            if value == 0xCC:
                self.destination = self.cpu_to_smp[2] | (self.cpu_to_smp[3] << 8)
                self.expected_counter = 0
                self.bytes_written = 0
                self.smp_to_cpu[0] = 0xCC
                self.phase = 'TRANSFER'
            # $FF and other pre-command values are legal while the IPL waits.
            return
        if self.phase != 'TRANSFER':
            raise IplProtocolError(f'port0 write in phase {self.phase}')
        if value == self.expected_counter:
            self.aram[self.destination] = self.cpu_to_smp[1]
            self.known[self.destination] = 1
            self.destination = (self.destination + 1) & 0xFFFF
            self.bytes_written += 1
            self.smp_to_cpu[0] = value
            self.expected_counter = (self.expected_counter + 1) & 0xFF
            return
        terminator = (self.expected_counter + 3) & 0xFF
        if value != terminator:
            raise IplProtocolError(f'unexpected IPL counter {value:02X}, expected {self.expected_counter:02X} or terminator {terminator:02X}')
        self.entry_pc = self.cpu_to_smp[2] | (self.cpu_to_smp[3] << 8)
        self.smp_to_cpu[0] = value
        if self.entry_pc == 0xFFC0:
            self.phase = 'RESTART_ACK'
            return
        self.phase = 'AOT_REQUIRED'
        raise AotRequired(self.entry_pc)
