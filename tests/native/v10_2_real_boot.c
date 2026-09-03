#include "v10_2_machine.h"
#include "v10_2_audio/sc_static_apu.h"

#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    PAD_B = 0x8000u, PAD_Y = 0x4000u, PAD_SELECT = 0x2000u,
    PAD_START = 0x1000u, PAD_UP = 0x0800u, PAD_DOWN = 0x0400u,
    PAD_LEFT = 0x0200u, PAD_RIGHT = 0x0100u, PAD_A = 0x0080u,
    PAD_X = 0x0040u, PAD_L = 0x0020u, PAD_R = 0x0010u
};

typedef enum RunLimitKind {
    LIMIT_INSTRUCTIONS = 0,
    LIMIT_FRAMES = 1,
    LIMIT_SECONDS = 2
} RunLimitKind;

typedef struct RunOptions {
    const char *rom_path;
    const char *log_path;
    const char *frame_output_path;
    const char *state_output_prefix;
    RunLimitKind limit_kind;
    uint64_t limit;
    uint64_t maximum_instructions;
    uint64_t log_every_frames;
    int exercise;
} RunOptions;

typedef struct PortEvent {
    uint16_t pc;
    uint8_t direction, port, value;
} PortEvent;

typedef struct InstructionEvent {
    uint16_t pc;
    uint8_t opcode;
} InstructionEvent;

typedef struct ScpuStepEvent {
    uint64_t step, master_before, master_after;
    uint32_t key_before, key_after;
    uint16_t scanline_before, hclock_before, scanline_after, hclock_after;
    uint8_t result;
} ScpuStepEvent;

static FILE *diagnostic_log;
static uint64_t pcm_frames;
static uint64_t pcm_hash = UINT64_C(1469598103934665603);
static PortEvent port_events[256];
static uint64_t port_event_count;
static InstructionEvent instruction_events[256];
static uint64_t instruction_event_count;
static ScpuStepEvent scpu_step_events[256];
static uint64_t scpu_step_event_count;

static void emit(FILE *console, const char *format, ...) {
    va_list args;
    if (console) {
        va_start(args, format);
        vfprintf(console, format, args);
        va_end(args);
        fflush(console);
    }
    if (diagnostic_log) {
        va_start(args, format);
        vfprintf(diagnostic_log, format, args);
        va_end(args);
        fflush(diagnostic_log);
    }
}

static void log_only(const char *format, ...) {
    va_list args;
    if (!diagnostic_log) return;
    va_start(args, format);
    vfprintf(diagnostic_log, format, args);
    va_end(args);
    fflush(diagnostic_log);
}

static int parse_u64(const char *text, uint64_t *value) {
    char *end = NULL;
    unsigned long long parsed;
    if (!text || !*text || !value) return 0;
    errno = 0;
    parsed = strtoull(text, &end, 10);
    if (errno || !end || *end != '\0' || parsed == 0u) return 0;
    *value = (uint64_t)parsed;
    return 1;
}

static void print_usage(void) {
    fprintf(stderr,
            "usage: v10_2_real_boot ROM [--instructions N | --frames N | --seconds N] "
            "[--exercise] [--log FILE] [--log-every-frames N] "
            "[--frame-output FILE.ppm] [--state-output-prefix PATH] "
            "[--maximum-instructions N]\n"
            "       legacy: v10_2_real_boot ROM [maximum-instructions] [exercise]\n");
}

static int parse_options(int argc, char **argv, RunOptions *options) {
    int index, limit_seen = 0;
    if (!options || argc < 2) return 0;
    memset(options, 0, sizeof(*options));
    options->rom_path = argv[1];
    options->limit_kind = LIMIT_INSTRUCTIONS;
    options->limit = UINT64_C(5000000);
    options->maximum_instructions = UINT64_C(1000000000);
    options->log_every_frames = 60u;
    for (index = 2; index < argc; ++index) {
        const char *arg = argv[index];
        if (strcmp(arg, "--exercise") == 0 || strcmp(arg, "exercise") == 0) {
            options->exercise = 1;
        } else if (strcmp(arg, "--instructions") == 0 || strcmp(arg, "--frames") == 0 ||
                   strcmp(arg, "--seconds") == 0) {
            uint64_t value;
            if (limit_seen || ++index >= argc || !parse_u64(argv[index], &value)) return 0;
            options->limit_kind = strcmp(arg, "--frames") == 0 ? LIMIT_FRAMES :
                                  strcmp(arg, "--seconds") == 0 ? LIMIT_SECONDS : LIMIT_INSTRUCTIONS;
            options->limit = value;
            limit_seen = 1;
        } else if (strcmp(arg, "--maximum-instructions") == 0) {
            if (++index >= argc || !parse_u64(argv[index], &options->maximum_instructions)) return 0;
        } else if (strcmp(arg, "--log-every-frames") == 0) {
            if (++index >= argc || !parse_u64(argv[index], &options->log_every_frames)) return 0;
        } else if (strcmp(arg, "--log") == 0) {
            if (++index >= argc || !*argv[index]) return 0;
            options->log_path = argv[index];
        } else if (strcmp(arg, "--frame-output") == 0) {
            if (++index >= argc || !*argv[index]) return 0;
            options->frame_output_path = argv[index];
        } else if (strcmp(arg, "--state-output-prefix") == 0) {
            if (++index >= argc || !*argv[index]) return 0;
            options->state_output_prefix = argv[index];
        } else if (arg[0] != '-' && !limit_seen) {
            if (!parse_u64(arg, &options->limit)) return 0;
            options->limit_kind = LIMIT_INSTRUCTIONS;
            limit_seen = 1;
        } else {
            return 0;
        }
    }
    if (options->limit_kind == LIMIT_INSTRUCTIONS && options->maximum_instructions < options->limit)
        options->maximum_instructions = options->limit;
    if (options->limit_kind == LIMIT_SECONDS &&
        options->limit > UINT64_MAX / JSV10_2_NTSC_MASTER_CLOCK) return 0;
    return 1;
}

static const char *limit_name(RunLimitKind kind) {
    if (kind == LIMIT_FRAMES) return "frames";
    if (kind == LIMIT_SECONDS) return "seconds";
    return "instructions";
}

static uint16_t exercise_pad(uint64_t frame, unsigned port) {
    static const uint16_t sequence[] = {
        PAD_DOWN, PAD_A, PAD_START, PAD_RIGHT, PAD_B, PAD_LEFT,
        PAD_Y, PAD_UP, PAD_X, PAD_L, PAD_R, PAD_SELECT
    };
    uint64_t phase;
    if (frame >= 180u && frame < 186u) return PAD_START;
    if (frame < 240u) return 0u;
    phase = (frame - 240u + (uint64_t)port * 12u) %
            (uint64_t)(sizeof(sequence) / sizeof(sequence[0]) * 24u);
    return (phase % 24u) < 6u ? sequence[phase / 24u] : 0u;
}

static void trace_instruction(void *context, uint16_t pc, uint8_t opcode) {
    InstructionEvent *event = &instruction_events[instruction_event_count & 255u];
    (void)context;
    event->pc = pc;
    event->opcode = opcode;
    instruction_event_count++;
}

static void trace_port(void *context, uint16_t pc, uint8_t direction,
                       uint8_t port, uint8_t value) {
    PortEvent *event = &port_events[port_event_count & 255u];
    (void)context;
    event->pc = pc;
    event->direction = direction;
    event->port = port;
    event->value = value;
    port_event_count++;
}

static void hash_pcm(void *context, int16_t left, int16_t right) {
    const uint16_t samples[2] = {(uint16_t)left, (uint16_t)right};
    unsigned i, byte;
    (void)context;
    for (i = 0u; i < 2u; ++i) {
        for (byte = 0u; byte < 2u; ++byte) {
            pcm_hash ^= (uint8_t)(samples[i] >> (byte * 8u));
            pcm_hash *= UINT64_C(1099511628211);
        }
    }
    pcm_frames++;
}

static uint64_t hash_bytes(const uint8_t *data, size_t size) {
    uint64_t hash = UINT64_C(1469598103934665603);
    size_t index;
    for (index = 0u; index < size; ++index) {
        hash ^= data[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static uint32_t count_nonzero_pixels(const uint8_t *data, size_t size) {
    uint32_t count = 0u;
    size_t index;
    for (index = 0u; index + 1u < size; index += 2u)
        if (data[index] || data[index + 1u]) count++;
    return count;
}

static uint32_t count_unique_colors(const uint8_t *data, size_t size) {
    uint8_t seen[32768u / 8u];
    uint32_t count = 0u;
    size_t index;
    memset(seen, 0, sizeof(seen));
    for (index = 0u; index + 1u < size; index += 2u) {
        const uint16_t color = (uint16_t)(data[index] | ((uint16_t)data[index + 1u] << 8u));
        const uint16_t value = color & 0x7FFFu;
        const uint8_t mask = (uint8_t)(1u << (value & 7u));
        if (!(seen[value >> 3u] & mask)) {
            seen[value >> 3u] |= mask;
            count++;
        }
    }
    return count;
}

static int write_frame_ppm(const JSV10_2Machine *machine, const char *path) {
    FILE *file = NULL;
    const unsigned height = machine->ppu.overscan ? 239u : 224u;
    unsigned x, y;
    if (!path || fopen_s(&file, path, "wb") != 0 || !file) return 0;
    if (fprintf(file, "P6\n%u %u\n255\n", (unsigned)JSV10_2_FRAME_WIDTH, height) < 0) {
        fclose(file);
        return 0;
    }
    for (y = 0u; y < height; ++y) {
        for (x = 0u; x < JSV10_2_FRAME_WIDTH; ++x) {
            const size_t offset = ((size_t)y * JSV10_2_FRAME_WIDTH + x) * 2u;
            const uint16_t color = (uint16_t)(machine->published_framebuffer[offset] |
                                   ((uint16_t)machine->published_framebuffer[offset + 1u] << 8u));
            const uint8_t rgb[3] = {
                (uint8_t)(((color & 31u) * 255u + 15u) / 31u),
                (uint8_t)((((color >> 5u) & 31u) * 255u + 15u) / 31u),
                (uint8_t)((((color >> 10u) & 31u) * 255u + 15u) / 31u)
            };
            if (fwrite(rgb, 1u, sizeof(rgb), file) != sizeof(rgb)) {
                fclose(file);
                return 0;
            }
        }
    }
    return fclose(file) == 0;
}

static int write_binary_file(const char *path, const void *data, size_t size) {
    FILE *file = NULL;
    if (!path || !data || fopen_s(&file, path, "wb") != 0 || !file) return 0;
    if (fwrite(data, 1u, size, file) != size) {
        fclose(file);
        return 0;
    }
    return fclose(file) == 0;
}

static int write_state_bundle(const JSV10_2Machine *machine, const char *prefix) {
    char path[4096];
    uint8_t cgram[JSV10_2_CGRAM_WORDS * 2u];
    unsigned index;
#define WRITE_MEMBER(suffix, member) \
    do { \
        if (snprintf(path, sizeof(path), "%s%s", prefix, suffix) < 0 || \
            !write_binary_file(path, (member), sizeof(member))) return 0; \
    } while (0)
    if (!machine || !prefix) return 0;
    for (index = 0u; index < JSV10_2_CGRAM_WORDS; ++index) {
        cgram[index * 2u] = (uint8_t)machine->ppu.cgram[index];
        cgram[index * 2u + 1u] = (uint8_t)(machine->ppu.cgram[index] >> 8u);
    }
    WRITE_MEMBER(".wram.bin", machine->wram);
    WRITE_MEMBER(".vram.bin", machine->ppu.vram);
    WRITE_MEMBER(".oam.bin", machine->ppu.oam);
    WRITE_MEMBER(".frame.bgr555", machine->published_framebuffer);
    WRITE_MEMBER(".rendering-frame.bgr555", machine->ppu.framebuffer);
    if (snprintf(path, sizeof(path), "%s.cgram.bin", prefix) < 0 ||
        !write_binary_file(path, cgram, sizeof(cgram))) return 0;
#undef WRITE_MEMBER
    return 1;
}

static uint8_t *load_rom(const char *path) {
    FILE *file = NULL;
    uint8_t *rom = NULL;
    long size;
    if (fopen_s(&file, path, "rb") != 0 || !file) return NULL;
    if (fseek(file, 0, SEEK_END) != 0) goto fail;
    size = ftell(file);
    if (size != (long)JSV10_2_ROM_SIZE) goto fail;
    if (fseek(file, 0, SEEK_SET) != 0) goto fail;
    rom = (uint8_t *)malloc(JSV10_2_ROM_SIZE);
    if (!rom || fread(rom, 1u, JSV10_2_ROM_SIZE, file) != JSV10_2_ROM_SIZE) {
        free(rom);
        rom = NULL;
    }
fail:
    fclose(file);
    return rom;
}

static void record_scpu_before(ScpuStepEvent *event, const JSV10_2Machine *machine,
                               uint64_t step) {
    memset(event, 0, sizeof(*event));
    event->step = step;
    event->key_before = js_cpu_context_key(&machine->cpu);
    event->master_before = machine->scheduler.master_clock;
    event->scanline_before = machine->scheduler.scanline;
    event->hclock_before = machine->scheduler.hclock;
}

static void record_scpu_after(ScpuStepEvent *event, const JSV10_2Machine *machine,
                              JSExecResult result) {
    event->result = (uint8_t)result;
    event->key_after = js_cpu_context_key(&machine->cpu);
    event->master_after = machine->scheduler.master_clock;
    event->scanline_after = machine->scheduler.scanline;
    event->hclock_after = machine->scheduler.hclock;
    scpu_step_event_count++;
}

static void print_scpu_tail(void) {
    uint64_t first = scpu_step_event_count > 96u ? scpu_step_event_count - 96u : 0u;
    uint64_t index;
    emit(stderr, "SCPU_STEP_TAIL count=%" PRIu64 "\n", scpu_step_event_count);
    for (index = first; index < scpu_step_event_count; ++index) {
        const ScpuStepEvent *event = &scpu_step_events[index & 255u];
        emit(stderr, "  step=%" PRIu64 " key=%08X->%08X master=%" PRIu64
             "->%" PRIu64 " raster=%u:%u->%u:%u result=%u\n",
             event->step, (unsigned)event->key_before, (unsigned)event->key_after,
             event->master_before, event->master_after,
             (unsigned)event->scanline_before, (unsigned)event->hclock_before,
             (unsigned)event->scanline_after, (unsigned)event->hclock_after,
             (unsigned)event->result);
    }
}

static void print_port_tail(void) {
    uint64_t first = port_event_count > 64u ? port_event_count - 64u : 0u;
    uint64_t index;
    emit(stderr, "SMP_PORT_TAIL count=%" PRIu64 "\n", port_event_count);
    for (index = first; index < port_event_count; ++index) {
        const PortEvent *event = &port_events[index & 255u];
        emit(stderr, "  event=%" PRIu64 " pc=%04X %s port=%u value=%02X\n",
             index, (unsigned)event->pc,
             event->direction ? "SMP_WRITE" : "SMP_READ",
             (unsigned)event->port, (unsigned)event->value);
    }
}

static void print_instruction_tail(void) {
    uint64_t first = instruction_event_count > 96u ? instruction_event_count - 96u : 0u;
    uint64_t index;
    emit(stderr, "SMP_INSTRUCTION_TAIL count=%" PRIu64 "\n", instruction_event_count);
    for (index = first; index < instruction_event_count; ++index) {
        const InstructionEvent *event = &instruction_events[index & 255u];
        emit(stderr, "  event=%" PRIu64 " pc=%04X opcode=%02X\n",
             index, (unsigned)event->pc, (unsigned)event->opcode);
    }
}

static void dump_machine_state(const JSV10_2Machine *machine) {
    SCStaticApuStatus status;
    uint8_t *aram = (uint8_t *)malloc(65536u);
    uint8_t dsp[128];
    unsigned index;
    memset(&status, 0, sizeof(status));
    memset(dsp, 0, sizeof(dsp));
    (void)sc_static_apu_status(&status);
    for (index = 0u; index < sizeof(dsp); ++index)
        (void)js_v10_2_apu_read_dsp_register((uint8_t)index, &dsp[index]);
    emit(stderr,
         "MACHINE CPU A=%04X X=%04X Y=%04X S=%04X D=%04X DBR=%02X P=%02X "
         "PC=%02X:%04X E=%u key=%08X open_bus=%02X memsel=%u\n",
         (unsigned)machine->cpu.a, (unsigned)machine->cpu.x,
         (unsigned)machine->cpu.y, (unsigned)machine->cpu.s,
         (unsigned)machine->cpu.d, (unsigned)machine->cpu.dbr,
         (unsigned)machine->cpu.p, (unsigned)machine->cpu.pbr,
         (unsigned)machine->cpu.pc, (unsigned)machine->cpu.e,
         (unsigned)js_cpu_context_key(&machine->cpu), (unsigned)machine->open_bus,
         (unsigned)machine->memsel);
    emit(stderr,
         "SCHED master=%" PRIu64 " frame=%" PRIu64 " sequence=%" PRIu64
         " raster=%u:%u field=%u cpu_cycles=%" PRIu64 " stop=%u "
         "nmi=%u/%u/%u irq=%u/%u/%u autojoy=%u step=%d event=%u@%u\n",
         machine->scheduler.master_clock, machine->scheduler.frame_number,
         machine->frame_sequence, (unsigned)machine->scheduler.scanline,
         (unsigned)machine->scheduler.hclock, (unsigned)machine->scheduler.field_odd,
         machine->scheduler.cpu_cycle_count, (unsigned)machine->scheduler.cpu_stop,
         (unsigned)machine->scheduler.enable_nmi, (unsigned)machine->scheduler.nmi_flag,
         (unsigned)machine->scheduler.nmi_pending, (unsigned)machine->scheduler.irq_level,
         (unsigned)machine->scheduler.need_irq, (unsigned)machine->scheduler.irq_flag,
         (unsigned)machine->scheduler.autojoy_active, (int)machine->scheduler.autojoy_step,
         (unsigned)machine->scheduler.next_primary_event,
         (unsigned)machine->scheduler.next_primary_clock);
    emit(stderr,
         "PPU mode=%u brightness=%u blank=%u overscan=%u interlace=%u "
         "frame_ready=%u scanlines_rendered=%u published_hash=%016" PRIX64
         " rendering_hash=%016" PRIX64
         " nonzero_pixels=%u vram_hash=%016" PRIX64 " cgram_hash=%016" PRIX64 "\n",
         (unsigned)machine->ppu.bg_mode, (unsigned)machine->ppu.brightness,
         (unsigned)machine->ppu.forced_blank, (unsigned)machine->ppu.overscan,
         (unsigned)machine->scheduler.interlace, (unsigned)machine->frame_ready,
         (unsigned)machine->scanlines_rendered,
         hash_bytes(machine->published_framebuffer, sizeof(machine->published_framebuffer)),
         hash_bytes(machine->ppu.framebuffer, sizeof(machine->ppu.framebuffer)),
         (unsigned)count_nonzero_pixels(machine->ppu.framebuffer,
                                        sizeof(machine->ppu.framebuffer)),
         hash_bytes(machine->ppu.vram, sizeof(machine->ppu.vram)),
         hash_bytes((const uint8_t *)machine->ppu.cgram, sizeof(machine->ppu.cgram)));
    emit(stderr,
         "APU owner=%u failed=%u reason=%u error=%s master=%" PRIu64
         " smp_pc=%04X cycles=%" PRIu64 " instructions=%" PRIu64
         " validated=%" PRIu64 " pcm=%" PRIu64 " pcm_known=%" PRIu64
         " pcm_unknown=%" PRIu64 " sink_pcm=%" PRIu64
         " barriers=%u overshoot=%d phase=%u timers=%u dsp_hash=%016" PRIX64 "\n",
         (unsigned)machine->apu.acquired, (unsigned)machine->apu.failed,
         (unsigned)machine->apu.fail_reason, machine->apu.last_error,
         status.synchronized_master_clock, (unsigned)status.smp_pc,
         status.smp_cycles, status.smp_instructions,
         status.aot_validated_instructions, status.pcm_frames,
         status.pcm_known_frames, status.pcm_unknown_frames, pcm_frames,
         (unsigned)status.code_write_barriers, (int)status.smp_cycle_overshoot,
         (unsigned)status.dsp_phase, (unsigned)status.timer_enable_mask,
         hash_bytes(dsp, sizeof(dsp)));
    for (index = 0u; index < 8u; ++index) {
        const JSV10_2DmaChannel *channel = &machine->dma.channel[index];
        emit(stderr,
             "DMA channel=%u active=%u mode=%u direction=%u fixed=%u decrement=%u "
             "source=%02X:%04X size=%04X dest=%02X hdma=%u finished=%u lines=%02X\n",
             index, (unsigned)channel->dma_active, (unsigned)channel->transfer_mode,
             (unsigned)channel->invert_direction, (unsigned)channel->fixed_transfer,
             (unsigned)channel->decrement, (unsigned)channel->src_bank,
             (unsigned)channel->src_address, (unsigned)channel->transfer_size,
             (unsigned)channel->dest_address, (unsigned)channel->hdma_indirect,
             (unsigned)channel->hdma_finished, (unsigned)channel->line_counter_repeat);
    }
    if (aram && js_v10_2_apu_read_aram(0u, aram, 65536u)) {
        emit(stderr, "ARAM hash=%016" PRIX64 " direct=%02X%02X%02X%02X "
             "ports=%02X%02X%02X%02X\n", hash_bytes(aram, 65536u),
             aram[0], aram[1], aram[2], aram[3],
             aram[0xF4u], aram[0xF5u], aram[0xF6u], aram[0xF7u]);
    }
    free(aram);
    print_scpu_tail();
    print_port_tail();
    print_instruction_tail();
}

static int validate_natural_frame(JSV10_2Machine *machine, uint64_t frame,
                                  uint64_t step, uint64_t previous_frame_step) {
    const uint64_t expected_smp =
        (machine->scheduler.master_clock * (uint64_t)JSV10_2_SMP_RATIO_NUM) /
        (uint64_t)JSV10_2_SMP_RATIO_DEN;
    const uint64_t pcm_cycle_position = machine->apu.pcm_frames * 32u;
    if (!machine->frame_ready) {
        emit(stderr, "INVARIANT frame=%" PRIu64 " step=%" PRIu64
             " frame publication was not ready\n", frame, step);
        return 0;
    }
    if (machine->apu.failed || machine->apu.code_write_barriers != 0u ||
        machine->apu.validated_instructions != machine->apu.smp_instructions) {
        emit(stderr, "INVARIANT frame=%" PRIu64 " step=%" PRIu64
             " static APU validation failed failed=%u barriers=%u validated=%" PRIu64
             " instructions=%" PRIu64 "\n", frame, step,
             (unsigned)machine->apu.failed, (unsigned)machine->apu.code_write_barriers,
             machine->apu.validated_instructions, machine->apu.smp_instructions);
        return 0;
    }
    if (machine->apu.smp_cycles != expected_smp || pcm_frames != machine->apu.pcm_frames ||
        pcm_cycle_position + 31u < machine->apu.smp_cycles ||
        pcm_cycle_position > machine->apu.smp_cycles + 31u) {
        emit(stderr, "INVARIANT frame=%" PRIu64 " step=%" PRIu64
             " audio clock/sink mismatch expected_smp=%" PRIu64 " actual_smp=%" PRIu64
             " pcm_cycle_position=%" PRIu64 " sink_pcm=%" PRIu64
             " core_pcm=%" PRIu64 "\n", frame, step,
             expected_smp, machine->apu.smp_cycles, pcm_cycle_position,
             pcm_frames, machine->apu.pcm_frames);
        return 0;
    }
    if (step - previous_frame_step > UINT64_C(1000000)) {
        emit(stderr, "INVARIANT frame=%" PRIu64 " step=%" PRIu64
             " frame required too many S-CPU steps delta=%" PRIu64 "\n",
             frame, step, step - previous_frame_step);
        return 0;
    }
    return 1;
}

static void log_frame(const JSV10_2Machine *machine, uint64_t frame, uint64_t step,
                      uint64_t pcm_delta) {
    log_only("FRAME sequence=%" PRIu64 " scheduler_frame=%" PRIu64
             " step=%" PRIu64 " master=%" PRIu64 " raster=%u:%u "
             "pc=%02X:%04X key=%08X smp=%04X smp_cycles=%" PRIu64
             " smp_instructions=%" PRIu64 " pcm=%" PRIu64 " pcm_delta=%" PRIu64
             " frame_hash=%016" PRIX64 " nonzero_pixels=%u unique_colors=%u "
             "mode=%u brightness=%u "
             "blank=%u dma=%02X hdma=%02X pad1=%04X pad2=%04X\n",
             frame, machine->scheduler.frame_number, step,
             machine->scheduler.master_clock, (unsigned)machine->scheduler.scanline,
             (unsigned)machine->scheduler.hclock, (unsigned)machine->cpu.pbr,
             (unsigned)machine->cpu.pc, (unsigned)js_cpu_context_key(&machine->cpu),
             (unsigned)machine->apu.entry_pc, machine->apu.smp_cycles,
             machine->apu.smp_instructions, machine->apu.pcm_frames, pcm_delta,
             hash_bytes(machine->published_framebuffer,
                        sizeof(machine->published_framebuffer)),
             (unsigned)count_nonzero_pixels(machine->published_framebuffer,
                                            sizeof(machine->published_framebuffer)),
             (unsigned)count_unique_colors(machine->published_framebuffer,
                                           sizeof(machine->published_framebuffer)),
             (unsigned)machine->ppu.bg_mode, (unsigned)machine->ppu.brightness,
             (unsigned)machine->ppu.forced_blank,
             (unsigned)machine->scheduler.manual_dma_mask,
             (unsigned)machine->scheduler.hdma_enable_mask,
             (unsigned)machine->scheduler.controller_state[0],
             (unsigned)machine->scheduler.controller_state[1]);
}

static int run_complete(const RunOptions *options, const JSV10_2Machine *machine,
                        uint64_t steps, uint64_t target_master) {
    if (options->limit_kind == LIMIT_FRAMES)
        return machine->frame_sequence >= options->limit;
    if (options->limit_kind == LIMIT_SECONDS)
        return machine->scheduler.master_clock >= target_master;
    return steps >= options->limit;
}

int main(int argc, char **argv) {
    RunOptions options;
    JSV10_2Machine *machine;
    JSV10_2Stop stop;
    uint8_t *rom;
    uint64_t steps = 0u, input_frame = UINT64_MAX, observed_frame = 0u;
    uint64_t last_frame_pcm = 0u, last_frame_step = 0u, target_master = 0u;
    int exit_code = 1;
    if (!parse_options(argc, argv, &options)) {
        print_usage();
        return 2;
    }
    if (options.log_path &&
        (fopen_s(&diagnostic_log, options.log_path, "wb") != 0 || !diagnostic_log)) {
        fprintf(stderr, "could not create diagnostic log: %s\n", options.log_path);
        return 2;
    }
    if (options.limit_kind == LIMIT_SECONDS)
        target_master = options.limit * (uint64_t)JSV10_2_NTSC_MASTER_CLOCK;
    emit(stdout, "HEADLESS_START schema=RRR_V10_2_NATURAL_HEADLESS_V1 limit_kind=%s "
         "limit=%" PRIu64 " exercise=%u max_instructions=%" PRIu64 " rom=%s\n",
         limit_name(options.limit_kind), options.limit, (unsigned)options.exercise,
         options.maximum_instructions, options.rom_path);
    rom = load_rom(options.rom_path);
    if (!rom) {
        emit(stderr, "ROM must be an exact %u-byte headerless image: %s\n",
             (unsigned)JSV10_2_ROM_SIZE, options.rom_path);
        goto cleanup_log;
    }
    machine = (JSV10_2Machine *)calloc(1u, sizeof(*machine));
    if (!machine) {
        free(rom);
        goto cleanup_log;
    }
    {
        SCStaticTraceCallbacks callbacks = {trace_instruction, NULL, NULL, trace_port, NULL};
        sc_static_apu_set_trace_callbacks(&callbacks);
    }
    js_v10_2_apu_set_sink(hash_pcm, NULL);
    if (!js_v10_2_power_on(machine, rom, JSV10_2_ROM_SIZE, NULL)) {
        emit(stderr, "power-on failed: %s\n", machine->apu.last_error);
        dump_machine_state(machine);
        goto cleanup_machine;
    }
    while (!run_complete(&options, machine, steps, target_master)) {
        ScpuStepEvent *event;
        JSExecResult result;
        uint64_t frame_before = machine->frame_sequence;
        if (steps >= options.maximum_instructions) {
            emit(stderr, "WATCHDOG steps=%" PRIu64 " frame=%" PRIu64
                 " master=%" PRIu64 " target_kind=%s target=%" PRIu64 "\n",
                 steps, machine->frame_sequence, machine->scheduler.master_clock,
                 limit_name(options.limit_kind), options.limit);
            dump_machine_state(machine);
            goto cleanup_machine;
        }
        if (options.exercise && machine->frame_sequence != input_frame) {
            input_frame = machine->frame_sequence;
            js_v10_2_set_controller_state(machine, 0u, exercise_pad(input_frame, 0u));
            js_v10_2_set_controller_state(machine, 1u, exercise_pad(input_frame, 1u));
            log_only("INPUT frame=%" PRIu64 " pad1=%04X pad2=%04X\n", input_frame,
                     (unsigned)machine->scheduler.controller_state[0],
                     (unsigned)machine->scheduler.controller_state[1]);
        }
        event = &scpu_step_events[scpu_step_event_count & 255u];
        record_scpu_before(event, machine, steps);
        result = js_v10_2_step(machine, &stop);
        record_scpu_after(event, machine, result);
        steps++;
        if (result == JS_EXEC_STOP) {
            emit(stderr,
                 "STOP step=%" PRIu64 " reason=%u address=%06X value=%02X "
                 "source=%08X observed=%08X pc=%02X:%04X E/M/X=%u/%u/%u "
                 "master=%" PRIu64 " raster=%u:%u smp=%04X smp_cycles=%" PRIu64
                 " smp_instructions=%" PRIu64 " pcm=%" PRIu64
                 " v05_reason=%u v05_address=%06X v05_source=%08X"
                 " v05_observed=%08X v05_value=%02X error=%s\n",
                 steps, (unsigned)stop.reason, (unsigned)stop.address,
                 (unsigned)stop.value, (unsigned)stop.source_key,
                 (unsigned)stop.observed_key, (unsigned)machine->cpu.pbr,
                 (unsigned)machine->cpu.pc, (unsigned)machine->cpu.e,
                 (unsigned)!!(machine->cpu.p & JS_P_M),
                 (unsigned)!!(machine->cpu.p & JS_P_X), stop.master_clock,
                 (unsigned)stop.scanline, (unsigned)stop.hclock,
                 (unsigned)machine->apu.entry_pc, machine->apu.smp_cycles,
                 machine->apu.smp_instructions, machine->apu.pcm_frames,
                 (unsigned)stop.v05.reason, (unsigned)stop.v05.address,
                 (unsigned)stop.v05.source_key, (unsigned)stop.v05.observed_key,
                 (unsigned)stop.v05.value,
                 machine->apu.last_error);
            dump_machine_state(machine);
            goto cleanup_machine;
        }
        if (machine->frame_sequence != frame_before) {
            const uint64_t frame = machine->frame_sequence;
            const uint64_t frame_delta = frame - observed_frame;
            const uint64_t pcm_delta = machine->apu.pcm_frames - last_frame_pcm;
            if (frame <= observed_frame || frame_delta > 4u) {
                emit(stderr, "INVARIANT step=%" PRIu64 " impossible frame sequence "
                     "change from %" PRIu64 " to %" PRIu64 "\n",
                     steps, observed_frame, frame);
                dump_machine_state(machine);
                goto cleanup_machine;
            }
            if (frame_delta > 1u)
                log_only("FRAME_BATCH step=%" PRIu64 " previous=%" PRIu64
                         " current=%" PRIu64 " delta=%" PRIu64
                         " dma_clocks=%" PRIu64 "\n", steps, observed_frame,
                         frame, frame_delta, machine->dma.dma_clock_counter);
            if (frame > frame_delta &&
                (pcm_delta < 500u * frame_delta || pcm_delta > 560u * frame_delta))
                log_only("FRAME_CROSSING_STEP step=%" PRIu64 " previous=%" PRIu64
                         " current=%" PRIu64 " frame_delta=%" PRIu64
                         " pcm_delta=%" PRIu64 " raster=%u:%u dma_clocks=%" PRIu64
                         "\n", steps, observed_frame, frame, frame_delta, pcm_delta,
                         (unsigned)machine->scheduler.scanline,
                         (unsigned)machine->scheduler.hclock,
                         machine->dma.dma_clock_counter);
            if (!validate_natural_frame(machine, frame, steps, last_frame_step)) {
                dump_machine_state(machine);
                goto cleanup_machine;
            }
            if (frame == 1u || frame / options.log_every_frames !=
                                  observed_frame / options.log_every_frames ||
                (options.limit_kind == LIMIT_FRAMES && frame == options.limit))
                log_frame(machine, frame, steps, pcm_delta);
            observed_frame = frame;
            last_frame_pcm = machine->apu.pcm_frames;
            last_frame_step = steps;
            js_v10_2_frame_acknowledge(machine);
        }
    }
    emit(stdout, "PASS steps=%" PRIu64 " pc=%02X:%04X master=%" PRIu64
         " emulated_seconds=%.6f frames=%" PRIu64 " scheduler_frames=%" PRIu64
         " frame_ready=%u smp=%04X smp_cycles=%" PRIu64
         " smp_instructions=%" PRIu64 " validated=%" PRIu64
         " pcm=%" PRIu64 " pcm_known=%" PRIu64 " pcm_unknown=%" PRIu64
         " sink_pcm=%" PRIu64 " pcm_hash=%016" PRIX64
         " code_barriers=%u sdsp_steps=%" PRIu64 " brr_steps=%" PRIu64
         " exercise=%u pad1=%04X pad2=%04X\n",
         steps, (unsigned)machine->cpu.pbr, (unsigned)machine->cpu.pc,
         machine->scheduler.master_clock,
         (double)machine->scheduler.master_clock / (double)JSV10_2_NTSC_MASTER_CLOCK,
         machine->frame_sequence, machine->scheduler.frame_number,
         (unsigned)machine->frame_ready, (unsigned)machine->apu.entry_pc,
         machine->apu.smp_cycles, machine->apu.smp_instructions,
         machine->apu.validated_instructions, machine->apu.pcm_frames,
         machine->apu.pcm_known_frames, machine->apu.pcm_unknown_frames,
         pcm_frames, pcm_hash, (unsigned)machine->apu.code_write_barriers,
         machine->apu.sdsp_primitive_steps, machine->apu.sdsp_brr_steps,
         (unsigned)options.exercise, (unsigned)machine->scheduler.controller_state[0],
         (unsigned)machine->scheduler.controller_state[1]);
    if (options.frame_output_path) {
        if (!write_frame_ppm(machine, options.frame_output_path)) {
            emit(stderr, "FRAME_OUTPUT_ERROR path=%s\n", options.frame_output_path);
            goto cleanup_machine;
        }
        emit(stdout, "FRAME_OUTPUT format=ppm path=%s\n", options.frame_output_path);
    }
    if (options.state_output_prefix) {
        if (!write_state_bundle(machine, options.state_output_prefix)) {
            emit(stderr, "STATE_OUTPUT_ERROR prefix=%s\n", options.state_output_prefix);
            goto cleanup_machine;
        }
        emit(stdout, "STATE_OUTPUT prefix=%s assets=wram,vram,oam,cgram,frame\n",
             options.state_output_prefix);
    }
    exit_code = 0;

cleanup_machine:
    js_v10_2_shutdown(machine);
    free(machine);
    free(rom);
cleanup_log:
    if (diagnostic_log) {
        fclose(diagnostic_log);
        diagnostic_log = NULL;
    }
    return exit_code;
}
