VERILATOR ?= verilator
VERILATOR_FLAGS := --binary --timing -Wall -Wno-fatal \
	-Wno-PROCASSINIT -Wno-UNUSEDSIGNAL
EXPECTED_VERSION := Verilator 5.050 2026-07-01
ACTUAL_VERSION := $(shell $(VERILATOR) --version 2>/dev/null)
BUILD_DIR := build
CASES := 0 1 8 9

.PHONY: all check-version lint test clean $(addprefix test-,$(CASES))

all: test

check-version:
	@if ! printf '%s\n' "$(ACTUAL_VERSION)" | grep -Fq "$(EXPECTED_VERSION)"; then \
		echo "ERROR: expected $(EXPECTED_VERSION)"; \
		echo "actual: $(ACTUAL_VERSION)"; \
		exit 1; \
	fi

lint: check-version
	$(VERILATOR) --lint-only -Wall -Wno-fatal \
		--top-module array_accel_engine array_accel_engine.v

$(addprefix test-,$(CASES)): test-%: check-version
	mkdir -p $(BUILD_DIR)/words_$*
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_array_reverse_engine \
		-GWORDS=$* --Mdir $(BUILD_DIR)/words_$* \
		tb_array_reverse_engine.v array_accel_engine.v
	$(BUILD_DIR)/words_$*/Vtb_array_reverse_engine

test: $(addprefix test-,$(CASES))

clean:
	$(RM) -r $(BUILD_DIR)
