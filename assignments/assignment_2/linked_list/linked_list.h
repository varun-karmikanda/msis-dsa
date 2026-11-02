#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

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
    uint32_t length;
};

List *slist_new();
List *slist_free(List *list);

List *slist_add_tail(List *list, uint32_t data);

List *slist_merge_sort(List *list);

List *slist_merge_list(List *list_1, List *list_2);

List slist_display_list(List *list);

#endif // LINKED_LIST_H_INCLUDED
