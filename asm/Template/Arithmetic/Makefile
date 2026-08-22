VERILATOR ?= verilator
IVERILOG ?= iverilog
VERILATOR_FLAGS := --timing -Wall -Wno-fatal \
	-Wno-DECLFILENAME -Wno-UNUSEDPARAM -Wno-UNUSEDSIGNAL

EXPECTED_VERSION := Verilator 5.050 2026-07-01
ACTUAL_VERSION := $(shell $(VERILATOR) --version 2>/dev/null)

OPERATION_RTL := \
	la32_divmod.v \
	la32_isqrt.v \
	la32_gcd.v \
	la32_bit_count.v \
	la32_bit_permute.v \
	la32_bitfield.v \
	la32_simple_ops.v \
	la32_mul_full.v \
	la32_crc32.v

RTL := \
	$(OPERATION_RTL) \
	contest_arithmetic_unit.v \
	contest_function_unit.v \
	arithmetic_map_adapter.v \
	function_map_adapter.v

TB_ARITH := tb_contest_arithmetic_unit.v
TB_FUNCTION := tb_contest_function_unit.v
HEADER := la32_arithmetic_ops.vh
BUILD_DIR := build
ARITH_BUILD_DIR := $(BUILD_DIR)/arithmetic
FUNCTION_BUILD_DIR := $(BUILD_DIR)/function
SIM_ARITH := $(ARITH_BUILD_DIR)/Vtb_contest_arithmetic_unit
SIM_FUNCTION := $(FUNCTION_BUILD_DIR)/Vtb_contest_function_unit

.PHONY: all check-version lint compat test clean

all: test

check-version:
	@if ! printf '%s\n' "$(ACTUAL_VERSION)" | grep -Fq "$(EXPECTED_VERSION)"; then \
		echo "ERROR: expected $(EXPECTED_VERSION)"; \
		echo "actual: $(ACTUAL_VERSION)"; \
		exit 1; \
	fi

lint: check-version
	@for rtl in $(OPERATION_RTL); do \
		$(VERILATOR) --lint-only $(VERILATOR_FLAGS) \
			--top-module accelerator_logic $$rtl || exit $$?; \
	done
	$(VERILATOR) --lint-only $(VERILATOR_FLAGS) \
		-DLA32_CORE_ONLY --top-module contest_function_unit $(RTL)
	$(VERILATOR) --lint-only $(VERILATOR_FLAGS) \
		-DLA32_CORE_ONLY --top-module function_map_adapter $(RTL)

compat:
	@for rtl in $(OPERATION_RTL); do \
		$(IVERILOG) -g2005 -tnull -s accelerator_logic $$rtl || exit $$?; \
	done
	$(IVERILOG) -g2005 -DLA32_CORE_ONLY -tnull \
		-s contest_function_unit $(RTL)

$(ARITH_BUILD_DIR) $(FUNCTION_BUILD_DIR):
	mkdir -p $@

$(SIM_ARITH): $(RTL) $(TB_ARITH) $(HEADER) | check-version $(ARITH_BUILD_DIR)
	$(VERILATOR) --binary $(VERILATOR_FLAGS) \
		-DLA32_CORE_ONLY \
		--top-module tb_contest_arithmetic_unit \
		--Mdir $(ARITH_BUILD_DIR) $(RTL) $(TB_ARITH)

$(SIM_FUNCTION): $(RTL) $(TB_FUNCTION) $(HEADER) | check-version $(FUNCTION_BUILD_DIR)
	$(VERILATOR) --binary $(VERILATOR_FLAGS) \
		-DLA32_CORE_ONLY \
		--top-module tb_contest_function_unit \
		--Mdir $(FUNCTION_BUILD_DIR) $(RTL) $(TB_FUNCTION)

test: $(SIM_ARITH) $(SIM_FUNCTION)
	$(SIM_ARITH)
	$(SIM_FUNCTION)

clean:
	$(RM) -r $(BUILD_DIR)
