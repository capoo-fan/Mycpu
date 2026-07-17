.PHONY: all verilator iverilog clean

MAKEFILE_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
ROOT_DIR     := $(abspath $(MAKEFILE_DIR)/../../../..)
MYCPU_DIR    := $(ROOT_DIR)/myCPU
RTL_DIR      := $(abspath $(MAKEFILE_DIR)/../rtl)

VERILATOR ?= verilator
VERILATOR_DIR := $(MAKEFILE_DIR)/project/loongson.sim/sim_1/behav/verilator
VERILATOR_OUT := $(VERILATOR_DIR)/Vtb_top
VERILATOR_FLAGS := --binary --timing -Wno-fatal \
	-Wno-DECLFILENAME -Wno-TIMESCALEMOD -Wno-PINCONNECTEMPTY \
	-Wno-UNUSEDSIGNAL -Wno-BLKSEQ -Wno-EOFNEWLINE
IVERILOG_DIR := $(MAKEFILE_DIR)/project/loongson.sim/sim_1/behav/iverilog
IVERILOG_OUT := $(IVERILOG_DIR)/gettrace
RTL := $(MYCPU_DIR)/*.v $(RTL_DIR)/*.v $(RTL_DIR)/*/*.v \
	$(MAKEFILE_DIR)/sync_ram.v $(MAKEFILE_DIR)/mult_gen_0_sim.v \
	$(MAKEFILE_DIR)/mycpu_tb.v

all: verilator

verilator: $(VERILATOR_OUT)
	cd $(VERILATOR_DIR) && ./Vtb_top

$(VERILATOR_OUT): $(wildcard $(MYCPU_DIR)/*.v) \
	$(wildcard $(RTL_DIR)/*.v) $(wildcard $(RTL_DIR)/*/*.v) \
	$(MAKEFILE_DIR)/sync_ram.v $(MAKEFILE_DIR)/mult_gen_0_sim.v \
	$(MAKEFILE_DIR)/mycpu_tb.v
	mkdir -p $(VERILATOR_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) -I$(MYCPU_DIR) \
		--top-module tb_top $(RTL) -Mdir $(VERILATOR_DIR)

iverilog: $(IVERILOG_OUT)
	cd $(IVERILOG_DIR) && vvp ./gettrace

$(IVERILOG_OUT):
	mkdir -p $(IVERILOG_DIR) && iverilog -g2005-sv -Wall -o $(IVERILOG_OUT) \
		$(RTL) -s tb_top \
		-I $(MYCPU_DIR)

clean:
	rm -rf $(MAKEFILE_DIR)/project
