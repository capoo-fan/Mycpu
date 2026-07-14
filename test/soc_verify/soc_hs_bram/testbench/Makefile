.PHONY: all iverilog clean

MAKEFILE_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
ROOT_DIR     := $(abspath $(MAKEFILE_DIR)/../../../..)
MYCPU_DIR    := $(ROOT_DIR)/myCPU
RTL_DIR      := $(abspath $(MAKEFILE_DIR)/../rtl)

IVERILOG_DIR := $(MAKEFILE_DIR)/project/loongson.sim/sim_1/behav/iverilog
IVERILOG_OUT := $(IVERILOG_DIR)/gettrace

all: iverilog

iverilog: $(IVERILOG_OUT)
	cd $(IVERILOG_DIR) && vvp ./gettrace

$(IVERILOG_OUT):
	mkdir -p $(IVERILOG_DIR) && iverilog -g2005-sv -Wall -o $(IVERILOG_OUT) \
		$(MYCPU_DIR)/*.v $(RTL_DIR)/*.v $(RTL_DIR)/*/*.v \
		$(MAKEFILE_DIR)/sync_ram.v $(MAKEFILE_DIR)/mycpu_tb.v -s tb_top \
		-I $(MYCPU_DIR)

clean:
	rm -rf $(MAKEFILE_DIR)/project
