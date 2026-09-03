#!/usr/bin/env python3
"""Version 05C direct static S-CPU lowering for Rock n' Roll Racing.

Authority is the frozen V04C source-proof artifacts plus the exact target ROM.
This is an OFFLINE generator. Generated production C never imports or calls a
runtime 65816 opcode decoder and never consumes gameplay/oracle traces.
"""
from __future__ import annotations
import argparse,csv,hashlib,json,re,shutil
from collections import Counter,defaultdict
from pathlib import Path

GENERATOR_VERSION="V05C-GEN-1"
ROM_SHA256="9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182"
TARGET_RE=re.compile(r"^([0-9A-F]{2}):([0-9A-F]{4}):E([01])M([01])X([01])")
LONG_DATA_MODES={"ABS_LONG","DP_IND_LONG","DP_IND_LONG_Y"}
M_VALUE={"ADC","AND","BIT","CMP","EOR","LDA","ORA","SBC","STA","STZ","ASL","DEC","INC","LSR","ROL"}
X_VALUE={"CPX","CPY","LDX","LDY","STX","STY"}
BOUNDARY_REASON={
    "DYNAMIC_TARGET":"JS_STOP_UNPROVED_DYNAMIC_TARGET",
    "INTERRUPT_REENTRY":"JS_STOP_UNPROVED_INTERRUPT_REENTRY",
    "RETURN":"JS_STOP_UNPROVED_RETURN",
}

def sha256_file(p:Path)->str:
    h=hashlib.sha256()
    with p.open('rb') as f:
        for chunk in iter(lambda:f.read(1<<20),b''): h.update(chunk)
    return h.hexdigest()

def key_tuple(r): return (int(r['PBR'],16),int(r['PC'],16),int(r['E']),int(r['M']),int(r['X']))
def key_int(k):
    b,pc,e,m,x=k
    return ((((b<<16)|pc)<<3)|(e<<2)|(m<<1)|x)
def key_text(k):
    b,pc,e,m,x=k
    return f"{b:02X}:{pc:04X}:E{e}M{m}X{x}"
def parse_target(s:str):
    m=TARGET_RE.match(s)
    if not m: raise ValueError(f"unparseable V04 target/context: {s!r}")
    return (int(m.group(1),16),int(m.group(2),16),int(m.group(3)),int(m.group(4)),int(m.group(5)))

def read_csv(p:Path):
    with p.open(encoding='utf-8',newline='') as f: return list(csv.DictReader(f))

def csv_write(p:Path, fieldnames, rows):
    p.parent.mkdir(parents=True,exist_ok=True)
    with p.open('w',encoding='utf-8',newline='') as f:
        w=csv.DictWriter(f,fieldnames=fieldnames,lineterminator='\n'); w.writeheader(); w.writerows(rows)

def operand_from_bytes(row):
    raw=bytes.fromhex(row['Bytes'])
    if len(raw)!=int(row['Length']): raise ValueError((row['Context_ID'],raw,row['Length']))
    op=0
    for i,b in enumerate(raw[1:]): op|=b<<(8*i)
    return raw,op

def ckey(k): return f"0x{key_int(k):08X}u"
def c_u16(v): return f"0x{v&0xffff:04X}u"
def c_u8(v): return f"0x{v&0xff:02X}u"
def c_u24(v): return f"0x{v&0xffffff:06X}u"

def addr_lines(mode,operand):
    if mode=='ABS': return [f"uint32_t ea = js_addr_abs(cpu, {c_u16(operand)});"],False
    if mode=='ABS_X': return [f"uint32_t ea = js_addr_abs_x(cpu, {c_u16(operand)});"],False
    if mode=='ABS_Y': return [f"uint32_t ea = js_addr_abs_y(cpu, {c_u16(operand)});"],False
    if mode=='ABS_LONG': return [f"uint32_t ea = js_addr_abs_long({c_u24(operand)});"],True
    if mode=='ABS_LONG_X': return [f"uint32_t ea = js_addr_abs_long_x(cpu, {c_u24(operand)});"],True
    if mode=='DP': return [f"uint32_t ea = js_addr_dp(cpu, {c_u8(operand)});"],False
    if mode=='DP_X': return [f"uint32_t ea = js_addr_dp_x(cpu, {c_u8(operand)});"],False
    if mode=='STACK_REL': return [f"uint32_t ea = js_addr_stack_rel(cpu, {c_u8(operand)});"],False
    if mode=='DP_IND': return ["uint32_t ea = 0u;",f"if (!js_addr_dp_ind(cpu, bus, {c_u8(operand)}, &ea, stop, source_key)) return JS_EXEC_STOP;"],False
    if mode=='DP_IND_Y': return ["uint32_t ea = 0u;",f"if (!js_addr_dp_ind_y(cpu, bus, {c_u8(operand)}, &ea, stop, source_key)) return JS_EXEC_STOP;"],False
    if mode=='DP_IND_LONG': return ["uint32_t ea = 0u;",f"if (!js_addr_dp_ind_long(cpu, bus, {c_u8(operand)}, &ea, stop, source_key)) return JS_EXEC_STOP;"],True
    if mode=='DP_IND_LONG_Y': return ["uint32_t ea = 0u;",f"if (!js_addr_dp_ind_long_y(cpu, bus, {c_u8(operand)}, &ea, stop, source_key)) return JS_EXEC_STOP;"],True
    if mode=='STACK_REL_IND_Y': return ["uint32_t ea = 0u;",f"if (!js_addr_stack_rel_ind_y(cpu, bus, {c_u8(operand)}, &ea, stop, source_key)) return JS_EXEC_STOP;"],False
    raise KeyError(mode)

def emit_read(lines,mode,operand,bits):
    al,linear=addr_lines(mode,operand); lines.extend(al); lines.append("uint16_t value = 0u;")
    if bits==8: lines.append("{ uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }")
    else: lines.append(f"if (!js_bus_read16(bus, ea, {1 if linear else 0}, &value, stop, source_key)) return JS_EXEC_STOP;")
    return linear

def emit_write(lines,mode,operand,bits,value_expr):
    al,linear=addr_lines(mode,operand); lines.extend(al)
    if bits==8: lines.append(f"if (!js_bus_write8(bus, ea, (uint8_t)({value_expr}), stop, source_key)) return JS_EXEC_STOP;")
    else: lines.append(f"if (!js_bus_write16(bus, ea, {1 if linear else 0}, (uint16_t)({value_expr}), stop, source_key)) return JS_EXEC_STOP;")

def branch_code(mn):
    return {'BCC':'C','BCS':'D','BEQ':'E','BMI':'M','BNE':'N','BPL':'P','BRA':'A'}[mn]

def transfer_code(mn):
    return {'TAX':'A','TAY':'B','TCD':'C','TCS':'D','TSX':'E','TXA':'F','TXS':'G','TYA':'H','TXY':'I','TYX':'J','TSC':'K'}[mn]

def emit_semantics(k,row):
    b,pc,e,m,x=k; mn=row['Mnemonic']; mode=row['Mode']; raw,operand=operand_from_bytes(row)
    length=len(raw); fall=(pc+length)&0xffff; lines=[f"cpu->pc = {c_u16(fall)};"]
    mbits=8 if m else 16; xbits=8 if x else 16

    # Branch/control first.
    if mn in {'BCC','BCS','BEQ','BMI','BNE','BPL','BRA'}:
        off=operand&0xff; signed=off if off<0x80 else off-0x100; lines.append(f"if (js_branch_condition(cpu, '{branch_code(mn)}')) cpu->pc = (uint16_t)(cpu->pc + ({signed}));")
    elif mn=='BRL':
        signed=(operand&0xffff) if (operand&0xffff)<0x8000 else (operand&0xffff)-0x10000; lines.append(f"cpu->pc = (uint16_t)(cpu->pc + ({signed}));")
    elif mn=='JMP':
        if mode=='ABS_JUMP': lines.append(f"cpu->pc = {c_u16(operand)};")
        elif mode=='ABS_IND': lines += ["{ uint16_t target = 0u;",f"  if (!js_bus_read16(bus, {c_u16(operand)}, 0, &target, stop, source_key)) return JS_EXEC_STOP;","  cpu->pc = target; }"]
        elif mode=='ABS_X_IND': lines += [f"uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)({c_u16(operand)} + cpu->x);","uint16_t target = 0u;","if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;","cpu->pc = target;"]
        else: raise RuntimeError(f'unsupported JMP mode {mode}')
    elif mn=='JML': lines += [f"cpu->pbr = {c_u8(operand>>16)};",f"cpu->pc = {c_u16(operand)};"]
    elif mn=='JSR':
        if mode=='ABS_X_IND':
            lines += [f"uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)({c_u16(operand)} + cpu->x);","uint16_t target = 0u;","if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;","if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;","cpu->pc = target;"]
        else:
            lines += ["if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;",f"cpu->pc = {c_u16(operand)};"]
    elif mn=='JSL':
        lines += ["if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;","if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;",f"cpu->pbr = {c_u8(operand>>16)};",f"cpu->pc = {c_u16(operand)};","js_cpu_normalize(cpu);"]
    elif mn=='RTS': lines += ["{ uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }"]
    elif mn=='RTL': lines += ["{ uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }"]
    elif mn=='RTI': raise RuntimeError('RTI must remain boundary-only in V05C')
    elif mn in {'CLC','CLD','CLI','SEC','SED','SEI'}:
        mask={'CLC':'JS_P_C','CLD':'JS_P_D','CLI':'JS_P_I','SEC':'JS_P_C','SED':'JS_P_D','SEI':'JS_P_I'}[mn]; setv=mn.startswith('S')
        lines.append(f"cpu->p = (uint8_t)(cpu->p {'|' if setv else '& (uint8_t)~'} {mask});")
    elif mn=='REP': lines.append(f"js_op_rep(cpu, {c_u8(operand)});")
    elif mn=='SEP': lines.append(f"js_op_sep(cpu, {c_u8(operand)});")
    elif mn=='XCE': lines.append("js_op_xce(cpu);")
    elif mn=='XBA': lines.append("js_op_xba(cpu);")
    elif mn in {'TAX','TAY','TCD','TCS','TSC','TSX','TXA','TXS','TXY','TYA','TYX'}: lines.append(f"js_op_transfer(cpu, '{transfer_code(mn)}');")
    elif mn in {'DEX','INX','DEY','INY'}:
        reg='x' if mn in {'DEX','INX'} else 'y'; delta=-1 if mn in {'DEX','DEY'} else 1
        loader='js_op_load_x' if reg=='x' else 'js_op_load_y'
        lines.append(f"{loader}(cpu, js_op_incdec(cpu, cpu->{reg}, {delta}, {xbits}u), {xbits}u);")
    elif mn in {'PHA','PHX','PHY','PHB','PHK','PHP','PHD','PEA','PEI'}:
        if mn=='PHA': lines.append(f"if (!js_stack_push{mbits}(cpu, bus, (uint{mbits}_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;")
        elif mn=='PHX': lines.append(f"if (!js_stack_push{xbits}(cpu, bus, (uint{xbits}_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;")
        elif mn=='PHY': lines.append(f"if (!js_stack_push{xbits}(cpu, bus, (uint{xbits}_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;")
        elif mn=='PHB': lines.append("if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;")
        elif mn=='PHK': lines.append("if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;")
        elif mn=='PHP': lines.append("if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;")
        elif mn=='PHD': lines.append("if (!js_stack_push16(cpu, bus, cpu->d, 1, stop, source_key)) return JS_EXEC_STOP;")
        elif mn=='PEA': lines += [f"if (!js_stack_push16(cpu, bus, {c_u16(operand)}, 0, stop, source_key)) return JS_EXEC_STOP;","js_cpu_normalize(cpu);"]
        elif mn=='PEI': lines += ["{ uint16_t v = 0u;",f"  if (!js_read_dp16(cpu, bus, {c_u8(operand)}, &v, stop, source_key)) return JS_EXEC_STOP;","  if (!js_stack_push16(cpu, bus, v, 1, stop, source_key)) return JS_EXEC_STOP; }"]
    elif mn in {'PLA','PLX','PLY','PLB','PLD','PLP'}:
        if mn=='PLA':
            if mbits==8: lines.append("{ uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 8u); }")
            else: lines.append("{ uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }")
        elif mn=='PLX':
            if xbits==8: lines.append("{ uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 8u); }")
            else: lines.append("{ uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }")
        elif mn=='PLY':
            if xbits==8: lines.append("{ uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 8u); }")
            else: lines.append("{ uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }")
        elif mn=='PLB': lines.append("{ uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }")
        elif mn=='PLD': lines.append("{ uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->d = v; js_op_set_nz(cpu, v, 16u); }")
        elif mn=='PLP': lines.append("{ uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }")
    elif mn in {'LDA','LDX','LDY','ADC','SBC','AND','EOR','ORA','CMP','CPX','CPY','BIT'}:
        bits=mbits if mn in {'LDA','ADC','SBC','AND','EOR','ORA','CMP','BIT'} else xbits
        if mode.startswith('IMM'):
            lines.append(f"uint16_t value = {c_u16(operand)};")
        else: emit_read(lines,mode,operand,bits)
        if mn=='LDA': lines.append(f"js_op_load_a(cpu, value, {bits}u);")
        elif mn=='LDX': lines.append(f"js_op_load_x(cpu, value, {bits}u);")
        elif mn=='LDY': lines.append(f"js_op_load_y(cpu, value, {bits}u);")
        elif mn=='ADC': lines.append(f"js_op_adc(cpu, value, {bits}u);")
        elif mn=='SBC': lines.append(f"js_op_sbc(cpu, value, {bits}u);")
        elif mn=='AND': lines.append(f"js_op_and(cpu, value, {bits}u);")
        elif mn=='EOR': lines.append(f"js_op_eor(cpu, value, {bits}u);")
        elif mn=='ORA': lines.append(f"js_op_ora(cpu, value, {bits}u);")
        elif mn=='CMP': lines.append(f"js_op_compare(cpu, cpu->a, value, {bits}u);")
        elif mn=='CPX': lines.append(f"js_op_compare(cpu, cpu->x, value, {bits}u);")
        elif mn=='CPY': lines.append(f"js_op_compare(cpu, cpu->y, value, {bits}u);")
        elif mn=='BIT': lines.append(f"js_op_bit(cpu, value, {bits}u, {1 if mode.startswith('IMM') else 0});")
    elif mn in {'STA','STX','STY','STZ'}:
        bits=mbits if mn in {'STA','STZ'} else xbits
        expr={'STA':f'js_op_store_a(cpu, {bits}u)','STX':f'js_op_store_x(cpu, {bits}u)','STY':f'js_op_store_y(cpu, {bits}u)','STZ':'0u'}[mn]
        emit_write(lines,mode,operand,bits,expr)
    elif mn in {'ASL','LSR','ROL','ROR','DEC','INC'}:
        bits=mbits
        if mode=='ACC':
            op={'ASL':'js_op_asl','LSR':'js_op_lsr','ROL':'js_op_rol','ROR':'js_op_ror'}.get(mn)
            if mn in {'DEC','INC'}: lines.append(f"js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, {-1 if mn=='DEC' else 1}, {bits}u), {bits}u);")
            else: lines.append(f"js_op_load_a(cpu, {op}(cpu, cpu->a, {bits}u), {bits}u);")
        else:
            al,linear=addr_lines(mode,operand); lines.extend(al); lines.append("uint16_t original = 0u;")
            if bits==8: lines.append("{ uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }")
            else: lines.append(f"if (!js_bus_read16(bus, ea, {1 if linear else 0}, &original, stop, source_key)) return JS_EXEC_STOP;")
            if mn in {'DEC','INC'}: lines.append(f"uint16_t result = js_op_incdec(cpu, original, {-1 if mn=='DEC' else 1}, {bits}u);")
            else: lines.append(f"uint16_t result = { {'ASL':'js_op_asl','LSR':'js_op_lsr','ROL':'js_op_rol','ROR':'js_op_ror'}[mn] }(cpu, original, {bits}u);")
            lines.append(f"if (!js_bus_rmw_write(bus, ea, {1 if linear else 0}, {bits}u, {e}u, original, result, stop, source_key)) return JS_EXEC_STOP;")
    elif mn=='MVN':
        destination=raw[1]; source_bank=raw[2]
        xmask='0x00FFu' if xbits==8 else '0xFFFFu'
        lines += [f"cpu->dbr = {c_u8(destination)};",f"uint32_t source_address = ((uint32_t){c_u8(source_bank)} << 16) | (cpu->x & {xmask});",f"uint32_t destination_address = ((uint32_t){c_u8(destination)} << 16) | (cpu->y & {xmask});","uint8_t moved = 0u;","if (!js_bus_read8(bus, source_address, &moved, stop, source_key)) return JS_EXEC_STOP;","if (!js_bus_write8(bus, destination_address, moved, stop, source_key)) return JS_EXEC_STOP;",f"cpu->x = (uint16_t)((cpu->x + 1u) & {xmask});",f"cpu->y = (uint16_t)((cpu->y + 1u) & {xmask});","{ uint16_t before = cpu->a; cpu->a = (uint16_t)(cpu->a - 1u);",f"  cpu->pc = before != 0u ? {c_u16(pc)} : {c_u16(fall)}; }}"]
    elif mn=='NOP':
        pass
    else:
        raise RuntimeError(f"V05C emitter missing reached instruction {mn}/{mode} at {key_text(k)}")
    return lines

def load_authority(project:Path):
    docs=project/'docs'
    contexts=read_csv(docs/'V04C-contexts.csv')
    edges=read_csv(docs/'V04C-edges.csv')
    boundaries=read_csv(docs/'V04C-fail-closed-boundaries.csv')
    grouped=defaultdict(list); idkey={}
    for r in contexts:
        k=key_tuple(r); grouped[k].append(r); idkey[r['Context_ID']]=k
    canonical={}
    for k,rs in grouped.items():
        sig={(r['Physical'],r['Opcode'],r['Mnemonic'],r['Mode'],r['Length'],r['Bytes']) for r in rs}
        if len(sig)!=1: raise ValueError(f"inconsistent instruction definition for {key_text(k)}: {sig}")
        canonical[k]=rs[0]
    succ=defaultdict(set)
    edge_kinds=defaultdict(Counter)
    for r in edges:
        src=idkey[r['From']]; dst=parse_target(r['To']); succ[src].add(dst); edge_kinds[src][r['Edge_Kind']]+=1
    bclasses=defaultdict(Counter)
    brows=defaultdict(list)
    for r in boundaries:
        k=parse_target(r['Context']); bclasses[k][r['Class']]+=1; brows[k].append(r)
    allkeys=set(canonical)
    if set(succ)-allkeys: raise ValueError('edge source outside contexts')
    for src,targets in succ.items():
        missing=targets-allkeys
        if missing: raise ValueError(f"successor(s) outside V04 authority for {key_text(src)}: {sorted(missing)}")
    return contexts,canonical,succ,bclasses,brows,edge_kinds

def emit_case(k,row,succ,bclasses):
    source=ckey(k); lines=[f"case {source}: {{",f"    const uint32_t source_key = {source};"]
    if not succ:
        classes=bclasses.get(k,Counter())
        if len(classes)!=1: raise ValueError(f"boundary-only key does not have exactly one class: {key_text(k)} {classes}")
        cls=next(iter(classes)); reason=BOUNDARY_REASON[cls]
        lines.append(f"    return js_stop_now(stop, {reason}, source_key, source_key);")
        lines.append("}")
        return '\n'.join(lines)
    for x in emit_semantics(k,row): lines.append('    '+x)
    ordered=sorted(succ,key=key_int)
    vals=', '.join(ckey(t) for t in ordered)
    lines.append(f"    static const uint32_t allowed[] = {{ {vals} }};")
    reject='JS_STOP_UNPROVED_RETURN' if bclasses.get(k,Counter()).get('RETURN',0) else 'JS_STOP_UNPROVED_SUCCESSOR'
    lines.append(f"    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], {reject});")
    lines.append("}")
    return '\n'.join(lines)

def generate(project:Path,rom:Path,output_root:Path):
    if sha256_file(rom)!=ROM_SHA256: raise SystemExit('target ROM SHA-256 mismatch')
    contexts,canonical,succ,bclasses,brows,edge_kinds=load_authority(project)
    out=output_root/'generated/current/v05c'; docsout=output_root/'docs'; out.mkdir(parents=True,exist_ok=True); docsout.mkdir(parents=True,exist_ok=True)
    # Ensure exactly the known V04 projection shape.
    keys=sorted(canonical,key=key_int)
    if len(keys)!=2258: raise ValueError(len(keys))
    boundary_only=[k for k in keys if not succ.get(k)]
    if len(boundary_only)!=20: raise ValueError(len(boundary_only))
    groups=defaultdict(list)
    for k in keys:
        group=(((k[0]<<16)|k[1])>>10); groups[group].append(k)
    if len(groups)!=18: raise ValueError(f"expected 18 1-KiB shards, got {len(groups)}")

    header='''#ifndef ROCKNROLL_V05C_DISPATCH_H\n#define ROCKNROLL_V05C_DISPATCH_H\n\n#include "v05c_static_cpu.h"\n\n#ifdef __cplusplus\nextern "C" {\n#endif\n\nJSExecResult js_v05c_step(JSCPU *cpu, const JSBus *bus, JSStop *stop);\n\n#ifdef __cplusplus\n}\n#endif\n#endif\n'''
    (out/'js_v05c_dispatch.h').write_text(header,encoding='utf-8',newline='\n')

    shard_meta=[]
    for group in sorted(groups):
        name=f"js_v05c_shard_{group:04X}"
        path=out/(name+'.c')
        body=["#include \"v05c_static_cpu.h\"","",f"JSExecResult {name}(JSCPU *cpu, const JSBus *bus, JSStop *stop) {{","    (void)bus;", "    (void)stop;", "    switch (js_cpu_context_key(cpu)) {"]
        for k in groups[group]:
            for line in emit_case(k,canonical[k],succ.get(k,set()),bclasses).splitlines(): body.append('        '+line)
        body += ["        default: return JS_EXEC_NOT_MINE;","    }","}",""]
        path.write_text('\n'.join(body),encoding='utf-8',newline='\n')
        shard_meta.append((group,name,path,len(groups[group])))

    dispatch=["#include \"js_v05c_dispatch.h\"",""]
    for group,name,path,count in shard_meta: dispatch.append(f"JSExecResult {name}(JSCPU *cpu, const JSBus *bus, JSStop *stop);")
    dispatch += ["","JSExecResult js_v05c_step(JSCPU *cpu, const JSBus *bus, JSStop *stop) {","    JSExecResult r;","    uint32_t group;","    if (!cpu) return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, 0u, 0u);","    js_stop_clear(stop);","    if (cpu->e > 1u || (cpu->e && ((cpu->p & (JS_P_M|JS_P_X)) != (JS_P_M|JS_P_X))))","        return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, js_cpu_context_key(cpu), js_cpu_context_key(cpu));","    if ((cpu->p & JS_P_X) && ((cpu->x & 0xFF00u) || (cpu->y & 0xFF00u)))","        return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, js_cpu_context_key(cpu), js_cpu_context_key(cpu));","    group = ((((uint32_t)cpu->pbr << 16) | cpu->pc) >> 10);","    switch (group) {"]
    for group,name,path,count in shard_meta: dispatch.append(f"        case 0x{group:04X}u: r = {name}(cpu, bus, stop); break;")
    dispatch += ["        default: r = JS_EXEC_NOT_MINE; break;","    }","    if (r == JS_EXEC_NOT_MINE) return js_stop_now(stop, JS_STOP_UNKNOWN_CONTEXT, js_cpu_context_key(cpu), js_cpu_context_key(cpu));","    return r;","}",""]
    (out/'js_v05c_dispatch.c').write_text('\n'.join(dispatch),encoding='utf-8',newline='\n')

    # Projection manifest.
    manifests=[]; successors=[]
    for idx,k in enumerate(keys,1):
        r=canonical[k]; group=(((k[0]<<16)|k[1])>>10); targets=sorted(succ.get(k,set()),key=key_int)
        classes=';'.join(sorted(bclasses.get(k,{})))
        manifests.append({
            'Production_ID':f'V05C{idx:06d}','Key':key_text(k),'Key_Hex':f'{key_int(k):08X}','PBR':f'{k[0]:02X}','PC':f'{k[1]:04X}','E':k[2],'M':k[3],'X':k[4],
            'Physical':r['Physical'],'Opcode':r['Opcode'],'Mnemonic':r['Mnemonic'],'Mode':r['Mode'],'Length':r['Length'],'Bytes':r['Bytes'],
            'Shard':f'{group:04X}','Successor_Count':len(targets),'Boundary_Classes':classes,'Disposition':'NATIVE_BODY' if targets else 'NAMED_BOUNDARY'
        })
        for t in targets: successors.append({'From_Key':key_text(k),'From_Key_Hex':f'{key_int(k):08X}','To_Key':key_text(t),'To_Key_Hex':f'{key_int(t):08X}'})
    csv_write(docsout/'V05C-production-manifest.csv',list(manifests[0]),manifests)
    csv_write(docsout/'V05C-successors.csv',['From_Key','From_Key_Hex','To_Key','To_Key_Hex'],successors)
    bmanifest=[]
    for k in sorted(bclasses,key=key_int):
        for cls,count in sorted(bclasses[k].items()):
            bmanifest.append({'Key':key_text(k),'Key_Hex':f'{key_int(k):08X}','Class':cls,'Boundary_Row_Count':count,'Has_Proved_Successor':'YES' if succ.get(k) else 'NO','Production_Failure':BOUNDARY_REASON[cls]})
    csv_write(docsout/'V05C-boundary-projection.csv',list(bmanifest[0]),bmanifest)

    unique_phys=set()
    for k,r in canonical.items():
        start=int(r['Physical'],16); ln=int(r['Length']); unique_phys.update(range(start,start+ln))
    generator_hash=sha256_file(Path(__file__))
    status=(project/'config/v05c-release-state.txt').read_text(encoding='utf-8').strip()
    if status not in {'TECHNICAL_CANDIDATE','ACCEPTED'}: raise ValueError(f'invalid V05C release state: {status!r}')
    v04_inputs=['docs/V04C-contexts.csv','docs/V04C-edges.csv','docs/V04C-fail-closed-boundaries.csv','docs/V04C-control-summary.json','config/v05c-release-state.txt']
    input_hashes={rel:sha256_file(project/rel) for rel in v04_inputs}
    summary={
        'schema':1,'milestone':'05C','status':status,'generator_version':GENERATOR_VERSION,'generator_sha256':generator_hash,
        'rom_sha256':ROM_SHA256,'authority':'frozen V04C source-proof projection only; no gameplay/oracle/trace authority',
        'v04c_commit':'851b3d004682cde7a16c345a19117ed2d51f448d','production_context_keys':len(keys),'unique_pbr_pc':len({(k[0],k[1]) for k in keys}),
        'source_proved_rom_bytes':len(unique_phys),'native_body_keys':len(keys)-len(boundary_only),'named_boundary_keys':len(boundary_only),
        'mixed_fail_closed_keys':sum(1 for k in bclasses if succ.get(k)),'successor_relations':len(successors),'shard_count':len(groups),'shard_shift':10,
        'runtime_opcode_decoder':False,'gameplay_promotions':0,'trace_promotions':0,'oracle_promotions':0,
        'input_hashes':input_hashes,'gate':'Every V04C production key has exactly one fixed body or named boundary; every live body successor is checked against its source-specific finite V04C set; final dispatch miss stops.'
    }
    (docsout/'V05C-lowering-summary.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n',encoding='utf-8',newline='\n')

    # Hash every generated C/H deterministically, excluding this hash manifest itself.
    genfiles=sorted(p for p in out.iterdir() if p.is_file() and p.name!='V05C-GENERATED-SHA256.json')
    hashes={'schema':1,'generator_version':GENERATOR_VERSION,'files':[{'path':str(p.relative_to(output_root)).replace('\\','/'),'size':p.stat().st_size,'sha256':sha256_file(p)} for p in genfiles]}
    hashes['aggregate_sha256']=hashlib.sha256(''.join(f["sha256"] for f in hashes['files']).encode()).hexdigest()
    (out/'V05C-GENERATED-SHA256.json').write_text(json.dumps(hashes,indent=2,sort_keys=True)+'\n',encoding='utf-8',newline='\n')
    return summary

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('rom',type=Path); ap.add_argument('--project-root',type=Path,default=Path(__file__).resolve().parents[1]); ap.add_argument('--output-root',type=Path)
    a=ap.parse_args(); project=a.project_root.resolve(); out=(a.output_root or project).resolve()
    s=generate(project,a.rom.resolve(),out); print(json.dumps(s,sort_keys=True))
if __name__=='__main__': main()
