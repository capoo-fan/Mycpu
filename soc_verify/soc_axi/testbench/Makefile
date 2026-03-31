.PHONY: clean run trace compile

IVERILOG_DIR = project/loongson.sim/sim_1/behav/iverilog
SIM_LOG      = $(IVERILOG_DIR)/sim.log

# default: compile, run simulation, and check trace result
run: trace

# compile all verilog sources with iverilog
compile: $(IVERILOG_DIR)/gettrace

$(IVERILOG_DIR)/gettrace:
	mkdir -p $(IVERILOG_DIR) && iverilog -g2005-sv -Wall -o $(IVERILOG_DIR)/gettrace \
		../../../myCPU/*.v ../rtl/*.v ../rtl/*/*.v \
		sync_ram.v mycpu_tb.v \
		-I ../../../myCPU/

# run simulation and save log
$(SIM_LOG): $(IVERILOG_DIR)/gettrace
	cd $(IVERILOG_DIR) && vvp ./gettrace 2>&1 | tee sim.log

# check golden trace comparison result from simulation log
trace: $(SIM_LOG)
	@echo "=============================================="
	@echo "  Golden Trace Comparison Result"
	@echo "=============================================="
	@if grep -q "Error!!!" $(SIM_LOG); then \
		echo "  [FAIL] Trace mismatch detected:"; \
		grep "Error!!!" $(SIM_LOG); \
		grep -A 2 "reference:" $(SIM_LOG); \
		exit 1; \
	elif grep -q "^----PASS!!!" $(SIM_LOG); then \
		echo "  [PASS] Simulation matches golden trace!"; \
	elif grep -q "Fail!!!" $(SIM_LOG); then \
		echo "  [FAIL] Simulation failed:"; \
		grep "Fail!!!" $(SIM_LOG); \
		exit 1; \
	else \
		echo "  [UNKNOWN] Could not determine result. Check log:"; \
		echo "  $(SIM_LOG)"; \
		exit 1; \
	fi
	@echo "=============================================="

clean:
	rm -rf ./project
