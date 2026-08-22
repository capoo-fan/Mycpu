VERILATOR ?= verilator
VERILATOR_FLAGS := --binary --timing -Wall -Wno-fatal \
	-Wno-PROCASSINIT -Wno-UNUSEDSIGNAL
EXPECTED_VERSION := Verilator 5.050 2026-07-01
ACTUAL_VERSION := $(shell $(VERILATOR) --version 2>/dev/null)
BUILD_DIR := build
CASES := 0 1 2 9 13

.PHONY: all check-version lint test clean \
	$(addprefix bubble-,$(CASES)) $(addprefix radix-,$(CASES))

all: test

check-version:
	@if ! printf '%s\n' "$(ACTUAL_VERSION)" | grep -Fq "$(EXPECTED_VERSION)"; then \
		echo "ERROR: expected $(EXPECTED_VERSION)"; \
		echo "actual: $(ACTUAL_VERSION)"; \
		exit 1; \
	fi

lint: check-version
	$(VERILATOR) --lint-only -Wall -Wno-fatal \
		--top-module array_accel_engine Bubble/array_accel_engine.v
	$(VERILATOR) --lint-only -Wall -Wno-fatal \
		--top-module array_accel_engine Radix/array_accel_engine.v

$(addprefix bubble-,$(CASES)): bubble-%: check-version
	mkdir -p $(BUILD_DIR)/bubble_$*
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_bubble_sort_engine \
		-GWORDS=$* --Mdir $(BUILD_DIR)/bubble_$* \
		Bubble/tb_bubble_sort_engine.v Bubble/array_accel_engine.v
	$(BUILD_DIR)/bubble_$*/Vtb_bubble_sort_engine

$(addprefix radix-,$(CASES)): radix-%: check-version
	mkdir -p $(BUILD_DIR)/radix_$*
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_radix_sort_engine \
		-GWORDS=$* --Mdir $(BUILD_DIR)/radix_$* \
		Radix/tb_radix_sort_engine.v Radix/array_accel_engine.v
	$(BUILD_DIR)/radix_$*/Vtb_radix_sort_engine

test: $(addprefix bubble-,$(CASES)) $(addprefix radix-,$(CASES))

clean:
	$(RM) -r $(BUILD_DIR)
