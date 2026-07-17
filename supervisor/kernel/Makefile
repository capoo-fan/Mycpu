RM	:= rm -f
ifeq ($(OS),Windows_NT)
# Windows Host
GCCPREFIX	?= 
else
GCCPREFIX	?= loongarch32r-linux-gnusf-
endif
LD	:= $(GCCPREFIX)ld
CC	:= $(GCCPREFIX)gcc
OBJCOPY	:= $(GCCPREFIX)objcopy
OBJDUMP	:= $(GCCPREFIX)objdump
HOSTCC	?= gcc
OBJDIR	:= obj
INCLUDE	:= include
SRCDIR	:= kern
LDSCRIPT	:= kern/kernel.ld
BSPDIR	:= ../../../bsp
SDKDIR	:= ../../../..
CONVERT_SRC	:= $(BSPDIR)/env/convert.c
CONVERT	:= $(OBJDIR)/convert
SRC	:= $(foreach sdir, $(SRCDIR), $(wildcard $(sdir)/*.S))
OBJ	:= $(patsubst $(SRCDIR)/%.S, $(OBJDIR)/%.o, $(SRC))
TARGET	:= kernel.elf
ASFLAG	:= -nostdinc -nostdlib -fno-builtin -mabi=ilp32s -g

override ON_FPGA ?= y
ifeq ($(ON_FPGA), y)
	MACH_DEF = -DMACH_FPGA
else
   	MACH_DEF = -DMACH_QEMU
endif
ASFLAG += $(MACH_DEF)
CONFIG_FILE := .config_$(ON_FPGA)_$(EN_INT)_$(EN_TLB)

.PHONY: all clean checkdirs show-utest

all: $(TARGET) kernel.bin kernel.s axi_ram.mif $(SDKDIR)/axi_ram.mif $(SDKDIR)/kernel.bin $(SDKDIR)/kernel.s show-utest

$(CONFIG_FILE):
	@rm -f .config_*
	touch $@

$(TARGET): $(OBJ) $(LDSCRIPT) | $(OBJDIR)
	$(LD) $(OBJ) -T$(LDSCRIPT) -o $@

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.S $(CONFIG_FILE) | $(OBJDIR)
	$(CC) -o $@ $< -c -I$(INCLUDE) $(ASFLAG)

checkdirs: $(OBJDIR)

$(OBJDIR):
	test -d $@ || mkdir $@

kernel.bin: $(TARGET)
	@$(OBJCOPY) -j .text -j .rodata -j .got -O binary $< $@

$(SDKDIR)/kernel.bin: kernel.bin
	cp $< $@

kernel.s: $(TARGET)
	$(OBJDUMP) -d -S -l $< > $@

$(SDKDIR)/kernel.s: kernel.s
	cp $< $@

$(CONVERT): $(CONVERT_SRC) | $(OBJDIR)
	$(HOSTCC) -o $@ $<

$(OBJDIR)/axi_ram.mif: kernel.bin $(CONVERT) | $(OBJDIR)
	$(CONVERT) ../kernel.bin $(OBJDIR)/

axi_ram.mif: $(OBJDIR)/axi_ram.mif
	cp $< $@

$(SDKDIR)/axi_ram.mif: $(OBJDIR)/axi_ram.mif
	cp $< $@

show-utest: $(TARGET)
	@$(OBJDUMP) -D $< | grep "^[0-9a-f]\{8\} <UTEST_" | grep -n --color=auto 'UTEST_'

clean:
	-$(RM) -r $(OBJDIR)
	-$(RM) $(TARGET) kernel.bin kernel.s axi_ram.coe axi_ram.mif rom.vlog
