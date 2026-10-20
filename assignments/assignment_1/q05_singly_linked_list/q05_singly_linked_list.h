#ifndef Q05_SINGLY_LINKED_LIST_H_INCLUDED
#define Q05_SINGLY_LINKED_LIST_H_INCLUDED

#include<stdint.h>

typedef struct _node_ Node;
typedef struct _list_ List;

struct _node_ {
    uint32_t data;
    Node *next;
};

struct _list_ {
    Node *head;
    Node *tail;
    uint32_t min;
    uint32_t max;
    uint32_t length;
};

List *sll_new();
List *sll_free(List *list);

List *sll_add_head(List *list, uint32_t data);
List *sll_add_tail(List *list, uint32_t data);

void sll_display_list(List *list);

uint32_t sll_minimum(List *list);
uint32_t sll_maximum(List *list);

List *sll_delete_dupicates(List *list);

#endif // Q05_SINGLY_LINKED_LIST_H_INCLUDED
