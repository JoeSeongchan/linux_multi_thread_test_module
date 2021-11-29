//
// Created by seongchan-joe on 21. 10. 28..
//
#include "linked_list_api.h"

// function to search node.
data_node *list_search(struct list_head *sentinel, int data){
    data_node *pos = NULL;
    data_node *pos_next = NULL;
    list_for_each_entry_safe(pos, pos_next, sentinel, head) {
        if (pos->data == data) {
            return pos;
        }
    }
    return NULL;
}

// function to delete node.
int list_delete(struct list_head *sentinel, int data){
    data_node *pos = NULL;
    data_node *pos_next = NULL;
    list_for_each_entry_safe(pos, pos_next, sentinel, head) {
        if (pos->data == data) {
            list_del(&pos->head);
            kfree(pos);
            return 1;
        }
    }
    return 0;
}

// function to print all node in linked list.
void list_print_all(struct list_head *sentinel){
    data_node *pos = NULL;
    data_node *pos_next = NULL;
    int i = 0;
    list_for_each_entry_safe(pos, pos_next, sentinel, head) {
        log("# %d data : %d",i++,pos->data);
    }
}

// function to delete all node in linked list.
void list_delete_all(struct list_head *sentinel){
    data_node *pos = NULL;
    data_node *pos_next = NULL;
    list_for_each_entry_safe(pos, pos_next, sentinel, head)
    {
        list_del(&pos->head);
        kfree(pos);
    }
    kfree(sentinel);
}







