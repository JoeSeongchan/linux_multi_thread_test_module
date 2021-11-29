obj-m := test_spinlock.o
test_spinlock-objs := test_spinlock_module.o \
						../../common/linked_list/data_structure.o \
						../../common/linked_list/linked_list_api.o \
						../../common/utilities/time_calculating.o \
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