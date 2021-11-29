obj-m := test_test_and_set.o
test_test_and_set-objs := test_test_and_set_module.o \
							../../common/utilities/utilities.o
ccflags-y := -std=gnu99 -Wno-declaration-after-statement
KERNEL_DIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	rm -rf **/*.o **/*~ core **/*.depend **/.*.cmd **/*.ko **/*.mod.c **/*.tmp_versions **/*.dwo **/*.mod **/*.order **/Module.symvers
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.dwo *.mod *.order Module.symvers
	cd ../../common && make clean