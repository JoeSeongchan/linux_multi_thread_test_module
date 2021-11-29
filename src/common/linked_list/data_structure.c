//
// Created by seongchan-joe on 21. 10. 28..
//
#include "data_structure.h"

// function to make & init sentinel node.
struct list_head *init_sentinel(void) {
    struct list_head *sentinel = (struct list_head *) kmalloc(\
                    sizeof(struct list_head), GFP_KERNEL);
    INIT_LIST_HEAD(sentinel);
    return sentinel;
}

// function to make & init data node.
data_node *init_data_node(int data) {
    data_node *new_node = (data_node *) kmalloc(sizeof(data_node), GFP_KERNEL);
    new_node->data = data;
    return new_node;
}

// function to free data node.
void free_data_node(data_node *target) {
    kfree(target);
}
