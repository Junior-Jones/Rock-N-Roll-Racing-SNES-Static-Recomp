"""Abstract V02C access and CPU-cycle contract.

Counts are architectural byte transfers, separated from later SNES master-clock
phase/timing.  Emulation-mode 8-bit RMW dummy writes are recorded separately.
"""
from __future__ import annotations

from dataclasses import dataclass
from .opcodes import OpcodeSpec, instruction_length
from .semantics import semantic_family

MEMORY_MODES = {
    "ABS", "ABS_X", "ABS_Y", "ABS_LONG", "ABS_LONG_X", "DP", "DP_X", "DP_Y",
    "DP_IND", "DP_X_IND", "DP_IND_Y", "DP_IND_LONG", "DP_IND_LONG_Y",
    "STACK_REL", "STACK_REL_IND_Y",
}
POINTER_MODE_BYTES = {
    "DP_IND": 2, "DP_X_IND": 2, "DP_IND_Y": 2,
    "DP_IND_LONG": 3, "DP_IND_LONG_Y": 3,
    "STACK_REL_IND_Y": 2, "ABS_IND": 2, "ABS_X_IND": 2, "ABS_IND_LONG": 3,
}
M_READ = {"ADC", "AND", "BIT", "CMP", "EOR", "LDA", "ORA", "SBC"}
X_READ = {"CPX", "CPY", "LDX", "LDY"}
M_STORE = {"STA", "STZ"}
X_STORE = {"STX", "STY"}
RMW = {"ASL", "DEC", "INC", "LSR", "ROL", "ROR", "TRB", "TSB"}
CONDITIONAL_BRANCH = {"BCC", "BCS", "BEQ", "BMI", "BNE", "BPL", "BVC", "BVS"}
INDEXED_CONDITIONAL_IDLE_MODES = {"ABS_X", "ABS_Y", "DP_IND_Y"}


@dataclass(frozen=True)
class AccessContract:
    fetch_bytes: int
    pointer_read_bytes: int
    data_read_bytes: int
    data_write_bytes: int
    dummy_write_bytes: int
    stack_read_bytes: int
    stack_write_bytes: int
    vector_read_bytes: int
    rmw_write_order: str
    base_cycles_wdc: int
    fixed_cycle_delta: int
    cycle_min: int
    cycle_max: int
    dynamic_cycle_tags: tuple[str, ...]
    wait_or_repeat: str
    semantic_test: str
    addressing_test: str


def _value_width(spec: OpcodeSpec, m: int, x: int) -> int:
    if spec.mnemonic in M_READ | M_STORE | RMW:
        return 1 if m else 2
    if spec.mnemonic in X_READ | X_STORE:
        return 1 if x else 2
    return 0


def _is_memory_rmw(spec: OpcodeSpec) -> bool:
    return spec.mnemonic in RMW and spec.mode != "ACC"


def _is_write_like(spec: OpcodeSpec) -> bool:
    return spec.mnemonic in M_STORE | X_STORE or _is_memory_rmw(spec)


def _fixed_width_cycle_delta(spec: OpcodeSpec, m: int, x: int) -> int:
    delta = 0
    if spec.mode == "IMM_M" and m == 0:
        delta += 1
    elif spec.mode == "IMM_X" and x == 0:
        delta += 1

    if spec.mode in MEMORY_MODES:
        if spec.mnemonic in M_READ | M_STORE and m == 0:
            delta += 1
        elif _is_memory_rmw(spec) and m == 0:
            delta += 2
        elif spec.mnemonic in X_READ | X_STORE and x == 0:
            delta += 1

    if spec.mnemonic in {"PHA", "PLA"} and m == 0:
        delta += 1
    if spec.mnemonic in {"PHX", "PHY", "PLX", "PLY"} and x == 0:
        delta += 1

    # Mesen/WDC addressing behavior: an indexed read gets one fixed idle when
    # indexes are 16-bit.  Stores/RMW already pay the corresponding base idle.
    if spec.mode in INDEXED_CONDITIONAL_IDLE_MODES and x == 0 and not _is_write_like(spec):
        delta += 1
    return delta


def access_contract(spec: OpcodeSpec, e: int, m: int, x: int) -> AccessContract:
    width = _value_width(spec, m, x)
    fetch = instruction_length(spec, m, x)
    pointer = POINTER_MODE_BYTES.get(spec.mode, 0)
    data_r = data_w = dummy_w = 0
    stack_r = stack_w = vector_r = 0
    rmw_order = "NONE"

    if spec.mode in MEMORY_MODES:
        if spec.mnemonic in M_READ | X_READ:
            data_r = width
        elif spec.mnemonic in M_STORE | X_STORE:
            data_w = width
        elif _is_memory_rmw(spec):
            data_r = width
            data_w = width
            if width == 2:
                rmw_order = "HIGH_THEN_LOW"
            else:
                rmw_order = "LOW_FINAL"
                dummy_w = 1 if e else 0
    if spec.mnemonic in {"MVN", "MVP"}:
        data_r = data_w = 1
    if spec.mnemonic == "PEI":
        # PEI uses DP addressing to obtain a 16-bit effective-indirect word.
        pointer = 2

    if spec.mnemonic in {"PHA"}: stack_w = 1 if m else 2
    elif spec.mnemonic in {"PHX", "PHY"}: stack_w = 1 if x else 2
    elif spec.mnemonic in {"PHB", "PHK", "PHP"}: stack_w = 1
    elif spec.mnemonic == "PHD": stack_w = 2
    elif spec.mnemonic in {"PEA", "PEI", "PER"}: stack_w = 2
    elif spec.mnemonic == "PLA": stack_r = 1 if m else 2
    elif spec.mnemonic in {"PLX", "PLY"}: stack_r = 1 if x else 2
    elif spec.mnemonic in {"PLB", "PLP"}: stack_r = 1
    elif spec.mnemonic == "PLD": stack_r = 2
    elif spec.mnemonic == "JSR": stack_w = 2
    elif spec.mnemonic == "JSL": stack_w = 3
    elif spec.mnemonic == "RTS": stack_r = 2
    elif spec.mnemonic == "RTL": stack_r = 3
    elif spec.mnemonic == "RTI": stack_r = 3 if e else 4
    elif spec.mnemonic in {"BRK", "COP"}:
        stack_w = 3 if e else 4
        vector_r = 2

    delta = _fixed_width_cycle_delta(spec, m, x)
    if spec.mnemonic in {"BRK", "COP"} and not e:
        delta += 1  # extra PBR stack transfer vs WDC emulation-mode base
    if spec.mnemonic == "RTI" and e:
        delta -= 1  # WDC Table 5-4 base assumes native RTI
    if spec.mnemonic == "BRA":
        delta += 1  # WDC branch base is the not-taken two-cycle base

    tags: list[str] = []
    dyn_max = 0
    if spec.mode.startswith("DP"):
        tags.append("DIRECT_LOW_NONZERO:+1")
        dyn_max += 1
    if spec.mode in INDEXED_CONDITIONAL_IDLE_MODES and not _is_write_like(spec) and x == 1:
        tags.append("INDEX_PAGE_CROSS:+1")
        dyn_max += 1
    if spec.mnemonic in CONDITIONAL_BRANCH:
        tags.append("BRANCH_TAKEN:+1")
        dyn_max += 1
        if e:
            tags.append("BRANCH_PAGE_CROSS_EMULATION:+1")
            dyn_max += 1
    elif spec.mnemonic == "BRA" and e:
        tags.append("BRANCH_PAGE_CROSS_EMULATION:+1")
        dyn_max += 1

    wait_or_repeat = "NONE"
    if spec.mnemonic == "WAI": wait_or_repeat = "WAIT_UNTIL_INTERRUPT_SIGNAL"
    elif spec.mnemonic == "STP": wait_or_repeat = "STOP_UNTIL_RESET"
    elif spec.mnemonic in {"MVN", "MVP"}: wait_or_repeat = "REPEAT_7_CYCLES_PER_BYTE_UNTIL_A_FFFF"

    cycle_min = spec.base_cycles + delta
    return AccessContract(
        fetch_bytes=fetch,
        pointer_read_bytes=pointer,
        data_read_bytes=data_r,
        data_write_bytes=data_w,
        dummy_write_bytes=dummy_w,
        stack_read_bytes=stack_r,
        stack_write_bytes=stack_w,
        vector_read_bytes=vector_r,
        rmw_write_order=rmw_order,
        base_cycles_wdc=spec.base_cycles,
        fixed_cycle_delta=delta,
        cycle_min=cycle_min,
        cycle_max=cycle_min + dyn_max,
        dynamic_cycle_tags=tuple(tags),
        wait_or_repeat=wait_or_repeat,
        semantic_test=f"SEM_{semantic_family(spec.mnemonic).upper()}",
        addressing_test=("ADDR_PEI_DIRECT_WORD" if spec.mnemonic == "PEI" else f"ADDR_{spec.mode}"),
    )
