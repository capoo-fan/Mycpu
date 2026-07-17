ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/..)
SUPERVISOR_DIR := $(ROOT_DIR)/supervisor
BUILD_DIR := $(SUPERVISOR_DIR)/build
SIM_EXE := /tmp/mycpu-supervisor-perf.vvp
VERILATOR_DIR := /tmp/mycpu-supervisor-perf-vlt
VERILATOR_EXE := $(VERILATOR_DIR)/Vsupervisor_perf_tb
RTL := $(wildcard $(ROOT_DIR)/myCPU/*.v)
TB := $(ROOT_DIR)/test/supervisor_perf_tb.v
SYMBOLS := $(BUILD_DIR)/kernel/auto/utest_symbols.txt
KERNEL_WORDS := $(shell wc -l < $(BUILD_DIR)/kernel/auto/axi_ram.mif)
VERILATOR ?= verilator
VERILATOR_FLAGS := --binary --timing -Wno-fatal \
	-Wno-DECLFILENAME -Wno-TIMESCALEMOD -Wno-PINCONNECTEMPTY \
	-Wno-UNUSEDSIGNAL -Wno-BLKSEQ -Wno-EOFNEWLINE

.PHONY: compile verilate stream matrix cryptonight mixed suite \
	istream imatrix icryptonight imixed isuite \
	vstream vmatrix vcryptonight vmixed vsuite

compile:
	iverilog -g2005-sv -Wall -I $(ROOT_DIR)/myCPU -s supervisor_perf_tb \
		-o $(SIM_EXE) $(RTL) $(TB)

verilate: $(VERILATOR_EXE)

$(VERILATOR_EXE): $(RTL) $(TB)
	$(VERILATOR) $(VERILATOR_FLAGS) -I$(ROOT_DIR)/myCPU \
		--top-module supervisor_perf_tb $(RTL) $(TB) -Mdir $(VERILATOR_DIR)

define entry
$(shell awk '$$2 == "$(1)" { print "0x" $$1 }' $(SYMBOLS))
endef

istream: compile
	cd $(ROOT_DIR) && vvp $(SIM_EXE) \
		+TEST_ID=1 +ENTRY_ADDR=$(call entry,UTEST_STREAM) \
		+BASE_MIF=$(BUILD_DIR)/utility/stream/axi_ram.mif \
		+BASE_WORDS=1048576 +MAX_CYCLES=300000000

imatrix: compile
	cd $(ROOT_DIR) && vvp $(SIM_EXE) \
		+TEST_ID=2 +ENTRY_ADDR=$(call entry,UTEST_MATRIX) \
		+BASE_MIF=$(BUILD_DIR)/kernel/auto/axi_ram.mif +BASE_WORDS=$(KERNEL_WORDS) \
		+EXT_MIF=$(BUILD_DIR)/utility/matrix/matrix.mif +EXT_WORDS=65536 \
		+MAX_CYCLES=300000000

icryptonight: compile
	cd $(ROOT_DIR) && vvp $(SIM_EXE) \
		+TEST_ID=3 +ENTRY_ADDR=$(call entry,UTEST_CRYPTONIGHT) \
		+BASE_MIF=$(BUILD_DIR)/kernel/auto/axi_ram.mif +BASE_WORDS=$(KERNEL_WORDS) \
		+REF_MIF=$(BUILD_DIR)/utility/crypto/crypto.mif +REF_WORDS=524288 \
		+MAX_CYCLES=300000000

imixed: compile
	cd $(ROOT_DIR) && vvp $(SIM_EXE) \
		+TEST_ID=4 +ENTRY_ADDR=$(call entry,UTEST_MIXED) \
		+BASE_MIF=$(BUILD_DIR)/kernel/auto/axi_ram.mif +BASE_WORDS=$(KERNEL_WORDS) \
		+REF_MIF=$(BUILD_DIR)/utility/mixed/mixed_signature.mif +REF_WORDS=5 \
		+MAX_CYCLES=300000000

isuite: istream imatrix icryptonight imixed

vstream: verilate
	cd $(ROOT_DIR) && $(VERILATOR_EXE) \
		+TEST_ID=1 +ENTRY_ADDR=$(call entry,UTEST_STREAM) \
		+BASE_MIF=$(BUILD_DIR)/utility/stream/axi_ram.mif \
		+BASE_WORDS=1048576 +MAX_CYCLES=300000000

vmatrix: verilate
	cd $(ROOT_DIR) && $(VERILATOR_EXE) \
		+TEST_ID=2 +ENTRY_ADDR=$(call entry,UTEST_MATRIX) \
		+BASE_MIF=$(BUILD_DIR)/kernel/auto/axi_ram.mif +BASE_WORDS=$(KERNEL_WORDS) \
		+EXT_MIF=$(BUILD_DIR)/utility/matrix/matrix.mif +EXT_WORDS=65536 \
		+MAX_CYCLES=300000000

vcryptonight: verilate
	cd $(ROOT_DIR) && $(VERILATOR_EXE) \
		+TEST_ID=3 +ENTRY_ADDR=$(call entry,UTEST_CRYPTONIGHT) \
		+BASE_MIF=$(BUILD_DIR)/kernel/auto/axi_ram.mif +BASE_WORDS=$(KERNEL_WORDS) \
		+REF_MIF=$(BUILD_DIR)/utility/crypto/crypto.mif +REF_WORDS=524288 \
		+MAX_CYCLES=300000000

vmixed: verilate
	cd $(ROOT_DIR) && $(VERILATOR_EXE) \
		+TEST_ID=4 +ENTRY_ADDR=$(call entry,UTEST_MIXED) \
		+BASE_MIF=$(BUILD_DIR)/kernel/auto/axi_ram.mif +BASE_WORDS=$(KERNEL_WORDS) \
		+REF_MIF=$(BUILD_DIR)/utility/mixed/mixed_signature.mif +REF_WORDS=5 \
		+MAX_CYCLES=300000000

vsuite: vstream vmatrix vcryptonight vmixed

stream: vstream
matrix: vmatrix
cryptonight: vcryptonight
mixed: vmixed
suite: vsuite
