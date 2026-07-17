VERILATOR ?= verilator
VERILATOR_DIR := gettrace.sim/sim_1/behav/verilator
VERILATOR_EXE := $(VERILATOR_DIR)/Vtb_top
IVERILOG_DIR := gettrace.sim/sim_1/behav/iverilog
IVERILOG_EXE := $(IVERILOG_DIR)/gettrace
RTL := ./src/*.v ./src/*/*.v
VERILATOR_FLAGS := --binary --timing -Wno-fatal \
	-Wno-DECLFILENAME -Wno-TIMESCALEMOD -Wno-PINCONNECTEMPTY \
	-Wno-UNUSEDSIGNAL -Wno-BLKSEQ -Wno-EOFNEWLINE

.PHONY: all verilator iverilog clean

all: verilator

verilator: $(VERILATOR_EXE)
	cd $(VERILATOR_DIR) && ./Vtb_top

$(VERILATOR_EXE): $(shell find src -name '*.v')
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module tb_top $(RTL) -Mdir $(VERILATOR_DIR)

iverilog: $(IVERILOG_EXE)
	cd $(IVERILOG_DIR) && vvp ./gettrace

$(IVERILOG_EXE):
	mkdir -p $(IVERILOG_DIR) && iverilog -Wall -o $(IVERILOG_EXE) $(RTL)

clean:
	rm -rf gettrace.sim
	rm -f golden_trace.txt
