//
// Created by seongchan-joe on 21. 10. 28..
//

#ifndef LINKED_LIST_TEST_MODULE_LINKED_LIST_API_H
#define LINKED_LIST_TEST_MODULE_LINKED_LIST_API_H

#include "../utilities/utilities.h"

// function to search node.
data_node *list_search(struct list_head *sentinel, int data);

// function to delete node.
int list_delete(struct list_head *sentinel, int data);

// function to print all node in linked list.
void list_print_all(struct list_head *sentinel);

// function to delete all node in linked list.
void list_delete_all(struct list_head *sentinel);

#endif //LINKED_LIST_TEST_MODULE_LINKED_LIST_API_H
