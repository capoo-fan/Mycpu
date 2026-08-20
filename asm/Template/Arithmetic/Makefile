VERILATOR ?= verilator
IVERILOG ?= iverilog

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

MAP_RTL := $(OPERATION_RTL) accelerator_logic.v

RTL := \
	$(OPERATION_RTL) \
	contest_arithmetic_unit.v \
	contest_function_unit.v \
	accelerator_logic.v \
	arithmetic_map_adapter.v \
	function_map_adapter.v

TB_ARITH := tb_contest_arithmetic_unit.v
TB_FUNCTION := tb_contest_function_unit.v
HEADER := la32_arithmetic_ops.vh la32_function_ops.vh
BUILD_DIR := build
ARITH_BUILD_DIR := $(BUILD_DIR)/arithmetic
FUNCTION_BUILD_DIR := $(BUILD_DIR)/function
STANDALONE_BUILD_DIR := $(BUILD_DIR)/standalone
SIM_ARITH := $(ARITH_BUILD_DIR)/Vtb_contest_arithmetic_unit
SIM_FUNCTION := $(FUNCTION_BUILD_DIR)/Vtb_contest_function_unit
SIM_STANDALONE := $(STANDALONE_BUILD_DIR)/Vtb_arithmetic_accelerator_logic

.PHONY: all check-version lint compat test clean

all: test

check-version:
	@if ! printf '%s\n' "$(ACTUAL_VERSION)" | grep -Fq "$(EXPECTED_VERSION)"; then \
		echo "ERROR: expected $(EXPECTED_VERSION)"; \
		echo "actual: $(ACTUAL_VERSION)"; \
		exit 1; \
	fi

lint: check-version
	$(VERILATOR) --lint-only --timing -Wall -Wno-fatal \
		--top-module contest_function_unit $(RTL)
	$(VERILATOR) --lint-only --timing -Wall -Wno-fatal \
		--top-module function_map_adapter $(RTL)
	$(VERILATOR) --lint-only --timing -Wall -Wno-fatal \
		--top-module accelerator_logic $(MAP_RTL)

compat:
	$(IVERILOG) -g2005 -tnull -s contest_function_unit $(RTL)
	$(IVERILOG) -g2005 -tnull -s accelerator_logic $(MAP_RTL)

$(ARITH_BUILD_DIR) $(FUNCTION_BUILD_DIR) $(STANDALONE_BUILD_DIR):
	mkdir -p $@

$(SIM_ARITH): $(RTL) $(TB_ARITH) $(HEADER) | check-version $(ARITH_BUILD_DIR)
	$(VERILATOR) --binary --timing -Wall -Wno-fatal \
		--top-module tb_contest_arithmetic_unit \
		--Mdir $(ARITH_BUILD_DIR) $(RTL) $(TB_ARITH)

$(SIM_FUNCTION): $(RTL) $(TB_FUNCTION) $(HEADER) | check-version $(FUNCTION_BUILD_DIR)
	$(VERILATOR) --binary --timing -Wall -Wno-fatal \
		--top-module tb_contest_function_unit \
		--Mdir $(FUNCTION_BUILD_DIR) $(RTL) $(TB_FUNCTION)

$(SIM_STANDALONE): $(MAP_RTL) tb_arithmetic_accelerator_logic.v la32_function_ops.vh | check-version $(STANDALONE_BUILD_DIR)
	$(VERILATOR) --binary --timing -Wall -Wno-fatal \
		--top-module tb_arithmetic_accelerator_logic \
		--Mdir $(STANDALONE_BUILD_DIR) $(MAP_RTL) tb_arithmetic_accelerator_logic.v

test: $(SIM_ARITH) $(SIM_FUNCTION) $(SIM_STANDALONE)
	$(SIM_ARITH)
	$(SIM_FUNCTION)
	$(SIM_STANDALONE)

clean:
	$(RM) -r $(BUILD_DIR)
