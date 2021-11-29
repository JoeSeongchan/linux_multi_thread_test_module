//
// Created by seongchan-joe on 21. 10. 28..
//

#ifndef LINKED_LIST_TEST_MODULE_TIME_CALCULATING_H
#define LINKED_LIST_TEST_MODULE_TIME_CALCULATING_H

#include <linux/time.h>
#include <linux/ktime.h>

#define BILLION 1000000000

unsigned long long calclock3(struct timespec64 *spclock);

#endif //LINKED_LIST_TEST_MODULE_TIME_CALCULATING_H
