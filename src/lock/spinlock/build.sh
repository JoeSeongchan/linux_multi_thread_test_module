make && insmod test_spinlock.ko && rmmod test_spinlock && dmesg && make clean && dmesg -C