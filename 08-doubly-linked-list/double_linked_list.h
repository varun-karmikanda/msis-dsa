#ifndef DOUBLE_LINKED_LIST_H_INCLUDED
#define DOUBLE_LINKED_LIST_H_INCLUDED

#include<stdint.h>
#include<stdbool.h>

typedef struct _node_ Node;
typedef struct _list_ List;

struct _node_ {
    uint32_t data;
    Node *prev;
    Node *next;
};

struct _list_ {
    Node *head;
    Node *tail;
    uint32_t length;
};

List *dll_new();
List *dll_free(List *list);

List *dll_add_head(List* list, uint32_t data);
List *dll_add_tail(List *list, uint32_t data);
List *dll_add_on_data(List *list, uint32_t key, uint32_t data);

List *dll_delete_head(List *list);
List *dll_delete_tail(List *list);
List *dll_delete_on_data(List *list, uint32_t data);

Node *dll_lookup(List *list, uint32_t key);

uint32_t dll_length(List *list);
uint32_t dll_element_at_position(List *list, uint32_t position);

bool dll_detect_cycle(List *list);

List *dll_reverse(List *list);
List *dll_delete_duplicate(List *list);

List *dll_union(List *list_1, List *list_2);
List *dll_intersection(List *list_1, List *list_2);

void dll_display(List *list);

#endif // DOUBLE_LINKED_LIST_H_INCLUDED
