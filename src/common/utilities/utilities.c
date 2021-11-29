//
// Created by seongchan-joe on 21. 11. 8..
//


#include "utilities.h"

// function to log.
void logFn(const char *caller_name, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    printk("-----------------------\n");
    printk("FN : %s\n", caller_name);
    printk("MSG : ");
    vprintk(fmt, args);
    va_end(args);
}

// function to create an integer array. [start_val, start_val+1, ... , end_val]
int *make_ordered_data_list(int start_val, int end_val) {
    int arr_length = end_val - start_val + 1;
    int *data_list = kmalloc(sizeof(int) * arr_length, GFP_KERNEL);
    for (int i = 0, val = start_val; i < arr_length; i++, val++) {
        data_list[i] = val;
    }
    return data_list;
}

// function to mix the sequence of the array.
void shuffle(int *arr, int arr_length) {
    int temp;
    int random_number;
    unsigned int val = 0;
    for (int i = 0; i < arr_length - 1; i++) {
        get_random_bytes(&val, sizeof(unsigned int));
        random_number = (unsigned int) (val % (arr_length - i) + i); // Pick a number randomly from i ~ arr_length-1.
        // swap.
        temp = arr[i];
        arr[i] = arr[random_number];
        arr[random_number] = temp;
    }
}