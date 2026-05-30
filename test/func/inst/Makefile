obj_path = ../obj
EXP = 0
SKIP_DIV ?= 1

div_srcs = n30_div_w.S n31_div_wu.S n35_mod_w.S n36_mod_wu.S
srcs_all = $(wildcard *.S)
ifeq ($(SKIP_DIV),1)
srcs = $(filter-out $(div_srcs),$(srcs_all))
else
srcs = $(srcs_all)
endif
raws = $(patsubst %.S, ${obj_path}/%.s, $(srcs))
objs = $(patsubst %.S, ${obj_path}/%.o, $(srcs))
div_raws = $(patsubst %.S, ${obj_path}/%.s, $(div_srcs))
div_objs = $(patsubst %.S, ${obj_path}/%.o, $(div_srcs))

.PHONY: libinst.a clean FORCE

libinst.a: $(obj_path)/libinst.a

$(obj_path)/libinst.a: FORCE $(objs)
	rm -f $@
	loongarch32r-linux-gnusf-ar -cr  $@ $(objs)

$(raws):${obj_path}/%.s:%.S
	loongarch32r-linux-gnusf-gcc \
		-I../include -nostdinc -nostdlib -D_KERNEL -fno-builtin -D__loongarch32\
		-DMEMSTART=0x10000000 -DMEMSIZE=0x04000 -DCPU_COUNT_PER_US=1000 -DGUEST -DEXP=$(EXP) -DSKIP_DIV=$(SKIP_DIV)\
		-S $^ > $@

$(objs):${obj_path}/%.o:${obj_path}/%.s %.S
	loongarch32r-linux-gnusf-as -mabi=ilp32 -o $@ $< 

clean:
	rm -rf ${objs} ${raws} ${div_objs} ${div_raws} ${obj_path}/libinst.a ${obj_path}/a.out

FORCE:
