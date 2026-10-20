#ifndef Q01_DOUBLE_LINKED_LIST_H_INCLUDED
#define Q01_DOUBLE_LINKED_LIST_H_INCLUDED

#include<stdint.h>

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

void dll_display(List *list);

#endif // Q01_DOUBLE_LINKED_LIST_H_INCLUDED
