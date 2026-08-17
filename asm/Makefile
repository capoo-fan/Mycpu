ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/..)
ASM_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
SUPERVISOR_DIR := $(ROOT_DIR)/supervisor
SUPERVISOR_BUILD := $(SUPERVISOR_DIR)/build

PROGRAM ?= programs/hello.s
ENTRY ?= _start
PROGRAM_ADDR ?= 0x80100000
PROGRAM_PATH := $(abspath $(PROGRAM))
PROGRAM_NAME := $(basename $(notdir $(PROGRAM)))
BUILD_ROOT := $(ASM_DIR)/.build
BUILD_DIR := $(BUILD_ROOT)/$(PROGRAM_NAME)
PROGRAM_ELF := $(BUILD_DIR)/$(PROGRAM_NAME).elf
PROGRAM_BIN := $(BUILD_DIR)/$(PROGRAM_NAME).bin
PROGRAM_MIF := $(BUILD_DIR)/$(PROGRAM_NAME).mif
PROGRAM_DISASM := $(BUILD_DIR)/$(PROGRAM_NAME).disasm

VLT_DIR := $(BUILD_ROOT)/verilator
VLT_EXE := $(VLT_DIR)/Vasm_monitor_tb
TB := $(ASM_DIR)/sim/asm_monitor_tb.v
RTL := $(wildcard $(ROOT_DIR)/myCPU/*.v)
BASE_MIF := $(SUPERVISOR_BUILD)/kernel/auto/axi_ram.mif
BASE_WORDS = $(shell wc -l < $(BASE_MIF) 2>/dev/null || echo 0)

PYTHON ?= $(ROOT_DIR)/.venv/bin/python
GCCPREFIX ?= loongarch32r-linux-gnusf-
CC := $(GCCPREFIX)gcc
NM := $(GCCPREFIX)nm
OBJCOPY := $(GCCPREFIX)objcopy
OBJDUMP := $(GCCPREFIX)objdump
VERILATOR ?= verilator
VERILATOR_VERSION := $(shell $(VERILATOR) --version 2>/dev/null)

WATCH_ADDR ?= 0x80700000
WATCH_WORDS ?= 8
MAX_CYCLES ?= 300000000
DATA_ADDR ?= 0x80400000
EXPECT_ADDR ?= 0x80700000
WAVE ?= 0
WAVE_FILE ?= $(BUILD_DIR)/$(PROGRAM_NAME).vcd

VFLAGS := --timing --trace -Wno-fatal -Wno-DECLFILENAME \
          -Wno-TIMESCALEMOD -Wno-PINCONNECTEMPTY -Wno-UNUSEDSIGNAL \
          -Wno-BLKSEQ -Wno-EOFNEWLINE --binary

# DATA/EXPECT accept either a binary file or a 32-bit binary-text MIF.
DATA_IMAGE :=
EXPECT_IMAGE :=
OPTIONAL_IMAGES :=
ifneq ($(strip $(DATA)),)
  ifeq ($(suffix $(DATA)),.bin)
    DATA_IMAGE := $(BUILD_DIR)/input.mif
  else ifeq ($(suffix $(DATA)),.mif)
    DATA_IMAGE := $(abspath $(DATA))
  else
    $(error DATA must end in .bin or .mif)
  endif
  OPTIONAL_IMAGES += $(DATA_IMAGE)
endif
ifneq ($(strip $(EXPECT)),)
  ifeq ($(suffix $(EXPECT)),.bin)
    EXPECT_IMAGE := $(BUILD_DIR)/expected.mif
  else ifeq ($(suffix $(EXPECT)),.mif)
    EXPECT_IMAGE := $(abspath $(EXPECT))
  else
    $(error EXPECT must end in .bin or .mif)
  endif
  OPTIONAL_IMAGES += $(EXPECT_IMAGE)
endif
ifneq ($(strip $(EXPECT)),)
  ifneq ($(strip $(EXPECT_VALUE)),)
    $(error use either EXPECT or EXPECT_VALUE, not both)
  endif
endif

.PHONY: all help check-tools supervisor program verilate run suite clean FORCE

all: run

help:
	@printf '%s\n' \
	  '基本用法:' \
	  '  make -C asm PROGRAM=programs/hello.s run' \
	  '  make -C asm PROGRAM=answer/2025/2025.asm ENTRY=count_first DATA=input.bin EXPECT_VALUE=1 run' \
	  '' \
	  '入口/地址: ENTRY PROGRAM_ADDR DATA DATA_ADDR INIT EXPECT EXPECT_ADDR EXPECT_VALUE' \
	  '观察/运行: WATCH_ADDR WATCH_WORDS MAX_CYCLES WAVE WAVE_FILE VERILATOR GCCPREFIX' \
	  '多题运行:   make -C asm suite PROGRAMS="programs/a.s programs/b.asm"'

check-tools:
	@command -v $(CC) >/dev/null 2>&1 || { echo 'ERROR: cannot find $(CC)' >&2; exit 1; }
	@command -v $(VERILATOR) >/dev/null 2>&1 || { echo 'ERROR: cannot find $(VERILATOR)' >&2; exit 1; }
	@case "$(VERILATOR_VERSION)" in \
	  'Verilator 5.050 2026-07-01'*) ;; \
	  *) echo 'ERROR: required Verilator 5.050 2026-07-01.' >&2; \
	     echo '       detected: $(VERILATOR_VERSION)' >&2; exit 1 ;; \
	esac

supervisor: $(BASE_MIF)

$(BASE_MIF):
	@echo '[BUILD] supervisor monitor'
	cd $(SUPERVISOR_DIR) && GCCPREFIX=$(GCCPREFIX) PYTHON=$(PYTHON) ./build_all.sh

program: $(PROGRAM_MIF) $(PROGRAM_DISASM)

$(BUILD_DIR):
	mkdir -p $@

# FORCE is intentional: ENTRY/PROGRAM_ADDR are command-line configuration and
# therefore are not represented by normal source timestamps.
$(PROGRAM_ELF): FORCE | $(BUILD_DIR)
	@test -f $(PROGRAM_PATH) || { echo 'ERROR: PROGRAM not found: $(PROGRAM_PATH)' >&2; exit 1; }
	$(CC) -x $(if $(filter %.S,$(PROGRAM_PATH)),assembler-with-cpp,assembler) \
		-nostdinc -nostdlib -fno-builtin -mabi=ilp32s -g \
		-Ttext $(PROGRAM_ADDR) -Wl,-e,$(ENTRY) -o $@ $(PROGRAM_PATH)
	@$(NM) -n $@ | awk '$$3 == "$(ENTRY)" { found=1 } END { \
		if (!found) { print "ERROR: entry symbol $(ENTRY) not found" > "/dev/stderr"; exit 1 } }'

$(PROGRAM_BIN): $(PROGRAM_ELF)
	$(OBJCOPY) -j .text -j .rodata -O binary $< $@

$(PROGRAM_MIF): $(PROGRAM_BIN)
	$(PYTHON) $(SUPERVISOR_DIR)/utility/bin_to_mem.py $< $@

$(PROGRAM_DISASM): $(PROGRAM_ELF)
	$(OBJDUMP) -d $< > $@

ifneq ($(strip $(DATA)),)
ifeq ($(suffix $(DATA)),.bin)
$(DATA_IMAGE): $(abspath $(DATA)) | $(BUILD_DIR)
	$(PYTHON) $(SUPERVISOR_DIR)/utility/bin_to_mem.py $< $@
endif
endif

ifneq ($(strip $(EXPECT)),)
ifeq ($(suffix $(EXPECT)),.bin)
$(EXPECT_IMAGE): $(abspath $(EXPECT)) | $(BUILD_DIR)
	$(PYTHON) $(SUPERVISOR_DIR)/utility/bin_to_mem.py $< $@
endif
endif

verilate: check-tools $(VLT_EXE)

$(VLT_EXE): $(RTL) $(TB)
	mkdir -p $(VLT_DIR)
	$(VERILATOR) $(VFLAGS) -I$(ROOT_DIR)/myCPU --top-module asm_monitor_tb \
		$(RTL) $(TB) -Mdir $(VLT_DIR)

run: check-tools supervisor program verilate $(OPTIONAL_IMAGES)
	@entry_addr="$$( $(NM) -n $(PROGRAM_ELF) | awk '$$3 == "$(ENTRY)" { print "0x" $$1; exit }')"; \
	program_words="$$(wc -l < $(PROGRAM_MIF))"; \
	test -n "$$entry_addr" || { echo 'ERROR: cannot resolve ENTRY=$(ENTRY)' >&2; exit 1; }; \
	$(VLT_EXE) \
	  +BASE_MIF=$(BASE_MIF) +BASE_WORDS=$(BASE_WORDS) \
	  +PROGRAM_MIF=$(PROGRAM_MIF) +PROGRAM_WORDS=$$program_words \
	  +PROGRAM_ADDR=$(PROGRAM_ADDR) +ENTRY_ADDR=$$entry_addr \
	  +WATCH_ADDR=$(WATCH_ADDR) +WATCH_WORDS=$(WATCH_WORDS) \
	  +MAX_CYCLES=$(MAX_CYCLES) \
	  $(if $(DATA_IMAGE),+DATA_MIF=$(DATA_IMAGE) +DATA_WORDS=$$(wc -l < $(DATA_IMAGE)) +DATA_ADDR=$(DATA_ADDR),) \
	  $(if $(strip $(INIT)),+INIT_FILE=$(abspath $(INIT)),) \
	  $(if $(EXPECT_IMAGE),+EXPECT_MIF=$(EXPECT_IMAGE) +EXPECT_WORDS=$$(wc -l < $(EXPECT_IMAGE)) +EXPECT_ADDR=$(EXPECT_ADDR),) \
	  $(if $(strip $(EXPECT_VALUE)),+EXPECT_VALUE=$(EXPECT_VALUE) +EXPECT_ADDR=$(EXPECT_ADDR),) \
	  $(if $(filter 1,$(WAVE)),+wave +WAVE_FILE=$(abspath $(WAVE_FILE)),)

suite:
	@test -n "$(PROGRAMS)" || { echo 'PROGRAMS is required, e.g. PROGRAMS="programs/a.s programs/b.asm"' >&2; exit 2; }
	@set -e; for p in $(PROGRAMS); do $(MAKE) --no-print-directory PROGRAM=$$p run; done

clean:
	rm -rf $(BUILD_ROOT)

FORCE:
