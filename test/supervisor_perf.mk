ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/..)
SUPERVISOR_DIR := $(ROOT_DIR)/supervisor
BUILD_DIR := $(SUPERVISOR_DIR)/build
SIM_EXE := /tmp/mycpu-supervisor-perf.vvp
RTL := $(wildcard $(ROOT_DIR)/myCPU/*.v)
TB := $(ROOT_DIR)/test/supervisor_perf_tb.v
SYMBOLS := $(BUILD_DIR)/kernel/auto/utest_symbols.txt
KERNEL_WORDS := $(shell wc -l < $(BUILD_DIR)/kernel/auto/axi_ram.mif)

.PHONY: compile stream matrix cryptonight mixed suite

compile:
	iverilog -g2005-sv -Wall -I $(ROOT_DIR)/myCPU -s supervisor_perf_tb \
		-o $(SIM_EXE) $(RTL) $(TB)

define entry
$(shell awk '$$2 == "$(1)" { print "0x" $$1 }' $(SYMBOLS))
endef

stream: compile
	cd $(ROOT_DIR) && vvp $(SIM_EXE) \
		+TEST_ID=1 +ENTRY_ADDR=$(call entry,UTEST_STREAM) \
		+BASE_MIF=$(BUILD_DIR)/utility/stream/axi_ram.mif \
		+BASE_WORDS=1048576 +MAX_CYCLES=300000000

matrix: compile
	cd $(ROOT_DIR) && vvp $(SIM_EXE) \
		+TEST_ID=2 +ENTRY_ADDR=$(call entry,UTEST_MATRIX) \
		+BASE_MIF=$(BUILD_DIR)/kernel/auto/axi_ram.mif +BASE_WORDS=$(KERNEL_WORDS) \
		+EXT_MIF=$(BUILD_DIR)/utility/matrix/matrix.mif +EXT_WORDS=65536 \
		+MAX_CYCLES=300000000

cryptonight: compile
	cd $(ROOT_DIR) && vvp $(SIM_EXE) \
		+TEST_ID=3 +ENTRY_ADDR=$(call entry,UTEST_CRYPTONIGHT) \
		+BASE_MIF=$(BUILD_DIR)/kernel/auto/axi_ram.mif +BASE_WORDS=$(KERNEL_WORDS) \
		+REF_MIF=$(BUILD_DIR)/utility/crypto/crypto.mif +REF_WORDS=524288 \
		+MAX_CYCLES=300000000

mixed: compile
	cd $(ROOT_DIR) && vvp $(SIM_EXE) \
		+TEST_ID=4 +ENTRY_ADDR=$(call entry,UTEST_MIXED) \
		+BASE_MIF=$(BUILD_DIR)/kernel/auto/axi_ram.mif +BASE_WORDS=$(KERNEL_WORDS) \
		+REF_MIF=$(BUILD_DIR)/utility/mixed/mixed_signature.mif +REF_WORDS=5 \
		+MAX_CYCLES=300000000

suite: stream matrix cryptonight mixed
