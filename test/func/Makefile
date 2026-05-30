obj_path = ./obj
SKIP_DIV ?= 1
inst_div_srcs = ./inst/n30_div_w.S ./inst/n31_div_wu.S ./inst/n35_mod_w.S ./inst/n36_mod_wu.S
inst_srcs_all = $(wildcard ./inst/*.S)
ifeq ($(SKIP_DIV),1)
inst_srcs = $(filter-out $(inst_div_srcs),$(inst_srcs_all))
else
inst_srcs = $(inst_srcs_all)
endif
EXP = 0

.PHONY: FORCE

default: 
	make all
	make tidy
	@echo "=====\nNote: do \"make EXP=N\"(N={0,6-16,18-19,21-23}) for corresponding EXP"
	@echo "      do \"make SKIP_DIV=0\" to include div/mod tests\n====="

all:
	mkdir -p ${obj_path}
	make ${obj_path}/inst_ram.coe ${obj_path}/test.s

tidy: 
	rm -f ${obj_path}/convert ${obj_path}/main.bin ${obj_path}/main.data ${obj_path}/main.elf
	rm -f ${obj_path}/start.s ${obj_path}/start.o ${obj_path}/init.s ${obj_path}/init.o
	make -C inst clean 

${obj_path}/test.s: ${obj_path}/main.elf
	loongarch32r-linux-gnusf-objdump -alD ${obj_path}/main.elf > ${obj_path}/test.s

${obj_path}/libinst.a: FORCE ${inst_srcs}
	make -C inst EXP=$(EXP) SKIP_DIV=$(SKIP_DIV) libinst.a

${obj_path}/start.o: ${obj_path}/start.s
	loongarch32r-linux-gnusf-as -mabi=ilp32 ${obj_path}/start.s -o ${obj_path}/start.o
${obj_path}/init.o: ${obj_path}/init.s
	loongarch32r-linux-gnusf-as -mabi=ilp32 ${obj_path}/init.s -o ${obj_path}/init.o

${obj_path}/inst_ram.coe ${obj_path}/inst_ram.mif: ${obj_path}/main.bin ${obj_path}/main.data ${obj_path}/convert
	cd ${obj_path} && ./convert 

${obj_path}/convert: convert.c
	gcc ./convert.c -o ${obj_path}/convert 

${obj_path}/main.bin: ${obj_path}/main.elf
	loongarch32r-linux-gnusf-objcopy -O binary -j .text ${obj_path}/main.elf ${obj_path}/main.bin
${obj_path}/main.data: ${obj_path}/main.elf
	loongarch32r-linux-gnusf-objcopy -O binary -j .data ${obj_path}/main.elf ${obj_path}/main.data

${obj_path}/main.elf: bin.lds ${obj_path}/libinst.a ${obj_path}/start.o ${obj_path}/init.o
	loongarch32r-linux-gnusf-ld ${obj_path}/start.o ${obj_path}/init.o ${obj_path}/libinst.a -T bin.lds -o ${obj_path}/main.elf

${obj_path}/start.s: start.S
	@mkdir -p ${obj_path}
	loongarch32r-linux-gnusf-gcc \
		-Iinclude -nostdinc -nostdlib -D_KERNEL -fno-builtin -D__loongarch32\
		-DMEMSTART=0x10000000 -DMEMSIZE=0x04000 -DCPU_COUNT_PER_US=1000 -DEXP=$(EXP) -DSKIP_DIV=$(SKIP_DIV)    \
		-S start.S > ${obj_path}/start.s 
${obj_path}/init.s: init.S
	@mkdir -p ${obj_path}
	loongarch32r-linux-gnusf-gcc \
		-Iinclude -nostdinc -nostdlib -D_KERNEL -fno-builtin -D__loongarch32\
		-DMEMSTART=0x10000000 -DMEMSIZE=0x04000 -DCPU_COUNT_PER_US=1000 -DEXP=$(EXP) -DSKIP_DIV=$(SKIP_DIV)    \
		-S init.S > ${obj_path}/init.s 

clean:
	rm -rf obj

help:
	@echo "################################################################"
	@echo "### help for compiling func"
	@echo "################################################################"
	@echo "### options:"
	@echo "###     make      : get compiled result, which is saved in ./obj"
	@echo "###     SKIP_DIV=0: include div.w/div.wu/mod.w/mod.wu tests"
	@echo "###     make clean: remove *.o, *.a, and ./obj"
	@echo "###     make help : show help information"
	@echo "###############################################################"

FORCE:
