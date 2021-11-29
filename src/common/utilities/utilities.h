//
// Created by seongchan-joe on 21. 11. 8..
//

#ifndef LINKED_LIST_TEST_MODULE_UTILITIES_H
#define LINKED_LIST_TEST_MODULE_UTILITIES_H

#define log(...) logFn(__func__,##__VA_ARGS__)

#include "../linked_list/data_structure.h"

void logFn(const char *caller_name, const char *fmt, ...);

// function to create an integer array. [start_val, start_val+1, ... , end_val]
int *make_ordered_data_list(int start_val, int end_val);

// function to mix the sequence of the array.
void shuffle(int *arr, int arr_len);

#endif //LINKED_LIST_TEST_MODULE_UTILITIES_H
