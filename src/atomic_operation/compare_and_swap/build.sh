make && insmod test_compare_and_swap.ko && rmmod test_compare_and_swap && dmesg && make clean && sudo dmesg -C