//
// Created by seongchan-joe on 21. 10. 28..
//

#ifndef LINKED_LIST_TEST_MODULE_DATA_STRUCTURE_H
#define LINKED_LIST_TEST_MODULE_DATA_STRUCTURE_H

#include <linux/list.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/random.h>
#include <linux/module.h>
#include <linux/limits.h>

typedef struct _data_node {
    struct list_head head;
    int data;
} data_node;

// function to make & init sentinel node.
struct list_head *init_sentinel(void);

// function to make & init data node.
data_node *init_data_node(int data);

// function to free data node.
void free_data_node(data_node *target);

#endif //LINKED_LIST_TEST_MODULE_DATA_STRUCTURE_H
