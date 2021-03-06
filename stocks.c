#include <stdio.h>
#include <stdlib.h>
#include "stocks.h"

void push_front(t_linked_list* list, void* value) {
    t_list_node* newNode = malloc(sizeof(t_list_node));
    newNode->next = list->front;
    newNode->value = value;
    list->front = newNode;
    if (list->size == 0)
        list->back = newNode;
    list->size ++;
}

void push_back(t_linked_list* list, void* value) {
    t_list_node* newNode = malloc(sizeof(t_list_node));
    newNode->prev = list->back;
    newNode->value = value;
    list->back = newNode;
    if (list->size == 0)
        list->front = newNode;
    list->size ++;
}

void* pop_front(t_linked_list* list) {
    t_list_node* node = list->front;
    void* value = node->value;
    list->front = node->next;
    free(node);
    list->size --;
    if (list->size == 0)
        list->back = NULL;
    return value;
}

void* pop_back(t_linked_list* list) {
    t_list_node* node = list->back;
    void* value = node->value;
    list->back = node->prev;
    free(node);
    list->size --;
    if (list->size == 0)
        list->front = NULL;
    return value;
}

void print_list(t_linked_list* list) {
    t_list_node* node = list->front;
    while (node) {
        printf("%d, ", node->value);
        node = node->next;
    }
}
