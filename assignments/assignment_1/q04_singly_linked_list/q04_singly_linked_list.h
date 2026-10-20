#ifndef Q04_SINGLY_LINKED_LIST_H_INCLUDED
#define Q04_SINGLY_LINKED_LIST_H_INCLUDED

#include <stdint.h>

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

List *slist_new();
List *slist_free(List *list);

List *slist_add_head(List *list, uint32_t data);
List *slist_add_tail(List *list, uint32_t data);

void slist_display_list(List *list);

uint32_t slist_minimum(List *list);
uint32_t slist_maximum(List *list);

#endif // Q04_SINGLY_LINKED_LIST_H_INCLUDED
