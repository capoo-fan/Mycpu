MAKEFILE_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
ASM_DIR := $(abspath $(MAKEFILE_DIR)/..)
ROOT_DIR := $(abspath $(ASM_DIR)/..)
SUPERVISOR_DIR := $(ROOT_DIR)/supervisor
SUPERVISOR_BUILD := $(SUPERVISOR_DIR)/build

PROGRAM_NAME := user_sample
PROGRAM_PATH := $(MAKEFILE_DIR)/user_sample.s
PROGRAM_ADDR ?= 0x80100000

ifneq ($(origin PROGRAM),undefined)
  $(error PROGRAM is not supported; replace asm/programs/user_sample.s instead)
endif
ifneq ($(origin ENTRY),undefined)
  $(error ENTRY is automatic and must not be specified)
endif
ifneq ($(origin PROGRAMS),undefined)
  $(error PROGRAMS/suite is not supported; only user_sample.s is simulated)
endif

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


# 打印输入区域的 5 个数据
WATCH_ADDR  ?= 0x80400000
WATCH_WORDS ?= 5

# WATCH_ADDR_2 为打印输出结果的起始地址，WATCH_WORDS_2 为打印输出区域的长度
# 打印输出区域的 5 个数据
WATCH_ADDR_2  ?= 0x80700000
WATCH_WORDS_2 ?= 5

# 默认写入数据的起始地址和值
INIT_ADDR   ?= 0x80400000
INIT_VALUES ?= 1 2 3 4 5
DEFAULT_INIT_FILE := $(BUILD_DIR)/initial_data.init

MAX_CYCLES  ?= 300000000
DATA_ADDR   ?= 0x80400000
EXPECT_ADDR ?= 0x80700000
WAVE ?= 0
WAVE_FILE ?= $(BUILD_DIR)/$(PROGRAM_NAME).vcd

VFLAGS := --timing --trace -Wno-fatal -Wno-DECLFILENAME \
          -Wno-TIMESCALEMOD -Wno-PINCONNECTEMPTY -Wno-UNUSEDSIGNAL \
          -Wno-BLKSEQ -Wno-EOFNEWLINE --binary

# DATA/EXPECT accept either a binary file or a 32-bit binary-text MIF.
DATA_IMAGE :=
EXPECT_IMAGE :=
INIT_IMAGE :=
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
ifneq ($(strip $(INIT)),)
  INIT_IMAGE := $(abspath $(INIT))
else ifeq ($(strip $(DATA)),)
  INIT_IMAGE := $(DEFAULT_INIT_FILE)
endif
OPTIONAL_IMAGES += $(INIT_IMAGE)
ifneq ($(strip $(EXPECT)),)
  ifneq ($(strip $(EXPECT_VALUE)),)
    $(error use either EXPECT or EXPECT_VALUE, not both)
  endif
endif

.PHONY: all help check-tools supervisor program verilate run clean FORCE

all: run

help:
	@printf '%s\n' \
	  '基本用法:' \
	  '  make -C asm/programs' \
	  '  make -C asm/programs program   # 只编译 user_sample.s' \
	  '  make -C asm/programs WAVE=1    # 仿真并生成波形' \
	  '' \
	  '输入/检查: DATA DATA_ADDR INIT INIT_ADDR INIT_VALUES EXPECT EXPECT_ADDR EXPECT_VALUE' \
	  '观察/运行: PROGRAM_ADDR WATCH_ADDR WATCH_WORDS WATCH_ADDR_2 WATCH_WORDS_2 MAX_CYCLES WAVE WAVE_FILE'

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

# FORCE is intentional: PROGRAM_ADDR is command-line configuration and is not
# represented by normal source timestamps.
$(PROGRAM_ELF): FORCE | $(BUILD_DIR)
	@test -f $(PROGRAM_PATH) || { echo 'ERROR: PROGRAM not found: $(PROGRAM_PATH)' >&2; exit 1; }
	$(CC) -x assembler \
		-nostdinc -nostdlib -fno-builtin -mabi=ilp32s -g \
		-Ttext $(PROGRAM_ADDR) -Wl,-e,$(PROGRAM_ADDR) -o $@ $(PROGRAM_PATH)
	@$(OBJDUMP) -h $@ | awk '$$2 == ".text" { found=1; size=$$3 } END { \
		if (!found || size == "00000000") { \
		  print "ERROR: user_sample.s has no executable .text section" > "/dev/stderr"; exit 1 \
		} }'

$(PROGRAM_BIN): $(PROGRAM_ELF)
	$(OBJCOPY) -j .text -j .rodata -O binary $< $@

$(PROGRAM_MIF): $(PROGRAM_BIN)
	$(PYTHON) $(SUPERVISOR_DIR)/utility/bin_to_mem.py $< $@

$(PROGRAM_DISASM): $(PROGRAM_ELF)
	$(OBJDUMP) -d $< > $@

$(DEFAULT_INIT_FILE): FORCE | $(BUILD_DIR)
	@addr=$$(( $(INIT_ADDR) )); \
	{ for value in $(INIT_VALUES); do \
	    printf '%08x %08x\n' "$$addr" "$$value"; \
	    addr=$$((addr + 4)); \
	  done; } > $@
	@echo '[INIT] $(INIT_ADDR): $(INIT_VALUES)'

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
	@chmod +x $(VLT_EXE)

$(VLT_EXE): $(RTL) $(TB)
	mkdir -p $(VLT_DIR)
	$(VERILATOR) $(VFLAGS) -I$(ROOT_DIR)/myCPU --top-module asm_monitor_tb \
		$(RTL) $(TB) -Mdir $(VLT_DIR)

run: check-tools supervisor program verilate $(OPTIONAL_IMAGES)
	@set -eu; \
	program_words="$$(wc -l < $(PROGRAM_MIF))"; \
	program_start=$$(( $(PROGRAM_ADDR) )); \
	program_end=$$((program_start + program_words * 4)); \
	symbol_addr="$$( $(NM) -n $(PROGRAM_ELF) | awk '$$3 == "_start" { print "0x" $$1; exit }')"; \
	text_addr="$$( $(OBJDUMP) -h $(PROGRAM_ELF) | awk '$$2 == ".text" { print "0x" $$4; exit }')"; \
	entry_num=''; entry_source=''; \
	if test -n "$$symbol_addr"; then \
	  symbol_num=$$((symbol_addr)); \
	  if test "$$symbol_num" -ge "$$program_start" && test "$$symbol_num" -lt "$$program_end"; then \
	    entry_num="$$symbol_num"; entry_source='_start'; \
	  fi; \
	fi; \
	if test -z "$$entry_num"; then \
	  test -n "$$text_addr" || { echo 'ERROR: cannot resolve .text entry' >&2; exit 1; }; \
	  text_num=$$((text_addr)); \
	  test "$$text_num" -ge "$$program_start" && test "$$text_num" -lt "$$program_end" || \
	    { echo 'ERROR: .text entry is outside the uploaded program image' >&2; exit 1; }; \
	  entry_num="$$text_num"; entry_source='.text'; \
	fi; \
	test $$((entry_num % 4)) -eq 0 || { echo 'ERROR: resolved entry is unaligned' >&2; exit 1; }; \
	entry_addr="$$(printf '0x%08x' "$$entry_num")"; \
	printf '[ENTRY] source=%s address=%s _start=%s\n' "$$entry_source" "$$entry_addr" "$${symbol_addr:-absent}"; \
	$(VLT_EXE) \
	  +BASE_MIF=$(BASE_MIF) +BASE_WORDS=$(BASE_WORDS) \
	  +PROGRAM_MIF=$(PROGRAM_MIF) +PROGRAM_WORDS=$$program_words \
	  +PROGRAM_ADDR=$(PROGRAM_ADDR) +ENTRY_ADDR=$$entry_addr \
	  +WATCH_ADDR=$(WATCH_ADDR) +WATCH_WORDS=$(WATCH_WORDS) \
	  +WATCH_ADDR_2=$(WATCH_ADDR_2) +WATCH_WORDS_2=$(WATCH_WORDS_2) \
	  +TOTAL_PERF_TABLE \
	  +MAX_CYCLES=$(MAX_CYCLES) \
	  $(if $(DATA_IMAGE),+DATA_MIF=$(DATA_IMAGE) +DATA_WORDS=$$(wc -l < $(DATA_IMAGE)) +DATA_ADDR=$(DATA_ADDR),) \
	  $(if $(INIT_IMAGE),+INIT_FILE=$(INIT_IMAGE),) \
	  $(if $(EXPECT_IMAGE),+EXPECT_MIF=$(EXPECT_IMAGE) +EXPECT_WORDS=$$(wc -l < $(EXPECT_IMAGE)) +EXPECT_ADDR=$(EXPECT_ADDR),) \
	  $(if $(strip $(EXPECT_VALUE)),+EXPECT_VALUE=$(EXPECT_VALUE) +EXPECT_ADDR=$(EXPECT_ADDR),) \
	  $(if $(filter 1,$(WAVE)),+wave +WAVE_FILE=$(abspath $(WAVE_FILE)),)

clean:
	rm -rf $(BUILD_ROOT)

FORCE:
