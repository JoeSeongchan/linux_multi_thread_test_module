//
// Created by seongchan-joe on 21. 10. 29..
//

#include "../../common/linked_list/linked_list_api.h"
#include "../../common/utilities/time_calculating.h"
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/spinlock.h>
#include <linux/mutex.h>


MODULE_LICENSE ("GPL v2");

// source.
int *source_arr;
int *random_arr;
int arr_len;
int arr_idx;

int thread_count = 0;
int THREAD_NUM = 4;

// spinlock.
struct mutex linked_list_mutex;
struct mutex arr_idx_mutex;
struct mutex progress_mutex;

// linked list.
struct list_head *sentinel;

// thread.
struct task_struct *thread1, *thread2, *thread3, *thread4;

// function that threads call [ADD]
int _thread_add_node_function(void *useless) {
    int target_data;
    while (true) {
        mutex_lock(&arr_idx_mutex);
        // when program reaches the end of array.
        if (arr_idx >= arr_len) {
            thread_count++;
            mutex_unlock(&arr_idx_mutex);
            // if this thread is last thread, stop measuring elapsed time.
            if (thread_count == THREAD_NUM) {
                mutex_unlock(&progress_mutex);
            }
            break;
        }
        target_data = source_arr[arr_idx];
//        log("%04d / %04d", arr_idx, arr_len - 1);
        arr_idx += 1;
        mutex_unlock(&arr_idx_mutex);

        data_node *new_node = init_data_node(target_data);
        mutex_lock(&linked_list_mutex);
        list_add(&new_node->head, sentinel);
        mutex_unlock(&linked_list_mutex);
    }
    return 0;
}

// function that threads call [SEARCH]
int _thread_search_node_function(void *useless) {
    int target_data;
    data_node *result;
    while (true) {
        mutex_lock(&arr_idx_mutex);
        // when program reaches the end of array.
        if (arr_idx >= arr_len) {
            thread_count++;
            mutex_unlock(&arr_idx_mutex);
            // if this thread is last thread, stop measuring elapsed time.
            if (thread_count == THREAD_NUM) {
                mutex_unlock(&progress_mutex);
            }
            break;
        }
        target_data = random_arr[arr_idx];
//        log("%04d / %04d", arr_idx, arr_len - 1);
        arr_idx += 1;
        mutex_unlock(&arr_idx_mutex);
        result = list_search(sentinel, target_data);
        if(result == NULL){
            log("error.");
        }
    }
    return 0;
}

// function that threads call [DELETE]
int _thread_delete_node_function(void *useless) {
    int target_data;
    int result;
    while (true) {
        mutex_lock(&arr_idx_mutex);
        // when program reaches the end of array.
        if (arr_idx >= arr_len) {
            thread_count++;
            mutex_unlock(&arr_idx_mutex);
            // if this thread is last thread, stop measuring elapsed time.
            if (thread_count == THREAD_NUM) {
                mutex_unlock(&progress_mutex);
            }
            break;
        }
        target_data = random_arr[arr_idx];
//        log("%04d / %04d", arr_idx, arr_len - 1);
        arr_idx += 1;
        mutex_unlock(&arr_idx_mutex);

        mutex_lock(&linked_list_mutex);
        result = list_delete(sentinel, target_data);
        mutex_unlock(&linked_list_mutex);
        if(result == 0){
            log("error.");
        }
    }
    return 0;
}

void init_mutex_lock(void) {
    mutex_init(&linked_list_mutex);
    mutex_init(&arr_idx_mutex);
    mutex_init(&progress_mutex);
}

// function to measure time to copy "item_num" items from int array into data_node array.
void measure_insert_time(void) {
    struct timespec64 start_time, end_time;
    ktime_get_raw_ts64(&start_time);
    mutex_lock(&progress_mutex);
    thread1 = kthread_run(_thread_add_node_function, NULL, "_thread_add_node_function");
    thread2 = kthread_run(_thread_add_node_function, NULL, "_thread_add_node_function");
    thread3 = kthread_run(_thread_add_node_function, NULL, "_thread_add_node_function");
    thread4 = kthread_run(_thread_add_node_function, NULL, "_thread_add_node_function");
    mutex_lock(&progress_mutex);
    arr_idx = 0;
    ktime_get_raw_ts64(&end_time);
    struct timespec64 spclock[2] = {start_time, end_time};
    unsigned long long time_diff = calclock3(spclock);
    // print.
    log("---example of insertion--\n"
        "number of items : %d\n"
        "elpased time : %llu nsec", arr_len, time_diff);
    mutex_unlock(&progress_mutex);
}

// function to measure time to find item in the linked list.
void measure_search_time(void) {
    struct timespec64 start_time, end_time;
    ktime_get_raw_ts64(&start_time);
    mutex_lock(&progress_mutex);
    thread_count = 0;
    thread1 = kthread_run(_thread_search_node_function, NULL, "_thread_search_node_function");
    thread2 = kthread_run(_thread_search_node_function, NULL, "_thread_search_node_function");
    thread3 = kthread_run(_thread_search_node_function, NULL, "_thread_search_node_function");
    thread4 = kthread_run(_thread_search_node_function, NULL, "_thread_search_node_function");
    mutex_lock(&progress_mutex);
    arr_idx = 0;
    ktime_get_raw_ts64(&end_time);
    struct timespec64 spclock[2] = {start_time, end_time};
    unsigned long long time_diff = calclock3(spclock);
    // print.
    log("---example of search--\n"
        "number of items : %d\n"
        "elpased time : %llu nsec", arr_len, time_diff);
    mutex_unlock(&progress_mutex);
}

//
// function to measure time to remove item from the linked list.
// target item = One of the items in the target_list.
void measure_delete_time(void) {
    struct timespec64 start_time, end_time;
    ktime_get_raw_ts64(&start_time);
    mutex_lock(&progress_mutex);
    thread_count = 0;
    thread1 = kthread_run(_thread_delete_node_function, NULL, "_thread_delete_node_function");
    thread2 = kthread_run(_thread_delete_node_function, NULL, "_thread_delete_node_function");
    thread3 = kthread_run(_thread_delete_node_function, NULL, "_thread_delete_node_function");
    thread4 = kthread_run(_thread_delete_node_function, NULL, "_thread_delete_node_function");
    mutex_lock(&progress_mutex);
    arr_idx = 0;
    ktime_get_raw_ts64(&end_time);
    struct timespec64 spclock[2] = {start_time, end_time};
    unsigned long long time_diff = calclock3(spclock);
    // print.
    log("---example of deletion--\n"
        "number of items : %d\n"
        "elpased time : %llu nsec", arr_len, time_diff);
    mutex_unlock(&progress_mutex);
}

// function to run assignment 7.
void run_assign_10(void) {
    init_mutex_lock();
    sentinel = init_sentinel();
    source_arr = make_ordered_data_list(0, 100000);
    random_arr = make_ordered_data_list(0, 100000);
    shuffle(random_arr, 100000);

    arr_len = 100000;
    arr_idx = 0;
    measure_insert_time();
    measure_search_time();
    measure_delete_time();
}

int __init

test_mutex_lock_module_init(void) {
    printk("start");
    run_assign_10();
    return 0;
}

void __exit

test_mutex_lock_module_cleanup(void) {
    log("Module that tests 'mutex' in linux kernel.\n"
        "LINUX SYSTEM AND ITS APPLICATIONS\n"
        "Subclass : 02\n"
        "ID : 20160570\n"
        "Name : Joe Seong-chan\n");
    return;
}

module_init(test_mutex_lock_module_init);
module_exit(test_mutex_lock_module_cleanup);

