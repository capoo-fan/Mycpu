# LoongArch32R C -> Assembly
# 用法：
#   make                 # 2025.c -> 2025.s，默认 -O2
#   make SRC=xxx.c       # xxx.c -> xxx.s
#   make o0 / o1 / o2 / o3
#   make check
#   make clean

CROSS_COMPILE ?= loongarch32r-linux-gnusf-
CC := $(CROSS_COMPILE)gcc

SRC ?= 2025.c
OUT ?= $(basename $(SRC)).asm

COMMON_FLAGS := \
	-ffreestanding \
	-fno-builtin \
	-fno-stack-protector \
	-fomit-frame-pointer \
	-fno-pic \
	-fno-pie \
	-fno-asynchronous-unwind-tables \
	-fno-unwind-tables

OPT ?= -O3

.PHONY: all asm o0 o1 o2 o3 check clean

all: asm

asm: check
	$(CC) $(COMMON_FLAGS) $(OPT) -S $(SRC) -o $(OUT)
	@echo "Generated: $(OUT)"

o0: check
	$(CC) $(COMMON_FLAGS) -O0 -S $(SRC) -o $(OUT)
	@echo "Generated with -O0: $(OUT)"

o1: check
	$(CC) $(COMMON_FLAGS) -O1 -S $(SRC) -o $(OUT)
	@echo "Generated with -O1: $(OUT)"

o2: check
	$(CC) $(COMMON_FLAGS) -O2 -S $(SRC) -o $(OUT)
	@echo "Generated with -O2: $(OUT)"

o3: check
	$(CC) $(COMMON_FLAGS) -O3 -S $(SRC) -o $(OUT)
	@echo "Generated with -O3: $(OUT)"

check:
	@command -v $(CC) >/dev/null 2>&1 || { \
		echo "ERROR: cannot find $(CC)"; \
		echo "Please check TOOLCHAIN_DIR or CROSS_COMPILE."; \
		exit 1; \
	}
	@$(CC) --version | head -n 1

clean:
	rm -f $(OUT)
