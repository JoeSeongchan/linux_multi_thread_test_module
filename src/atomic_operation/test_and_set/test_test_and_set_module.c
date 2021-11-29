//
// Created by seongchan-joe on 21. 11. 17..
//
#include "../../common/utilities/utilities.h"
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/unistd.h>

MODULE_LICENSE ("GPL v2");

int thread_run_code(void *_arg) {
    unsigned char *arg = (unsigned char *) _arg;
    while (__sync_lock_test_and_set(arg, 1));
    log("1");
    log("2");
    log("3");
    __sync_lock_release(arg);
    return 0;
}

void create_thread(void) {
    static const int THREAD_NUM = 5;
    unsigned char *arg = (unsigned char *) kmalloc(sizeof(unsigned char), GFP_KERNEL);
    *arg = 0;
    kthread_run(&thread_run_code, (void *) arg, "thread_run_code");
    kthread_run(&thread_run_code, (void *) arg, "thread_run_code");
    kthread_run(&thread_run_code, (void *) arg, "thread_run_code");
}

// function to run assignment 9.
void run_assign_10(void) {
    create_thread();
}

int __init

test_test_and_set_module_init(void) {
    run_assign_10();
    return 0;
}

void __exit

test_test_and_set_module_cleanup(void) {
    log("Module that tests the 'test_and_set' in linux kernel.\n"
        "LINUX SYSTEM AND ITS APPLICATIONS\n"
        "Subclass : 02\n"
        "ID : 20160570\n"
        "Name : Joe Seong-chan\n");
    return;
}

module_init(test_test_and_set_module_init);
module_exit(test_test_and_set_module_cleanup);

