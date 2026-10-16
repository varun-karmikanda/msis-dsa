#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

#include<stdint.h>
#include<stdbool.h>

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

uint32_t slist_length(List *list);
Node *slist_lookup(List *list, uint32_t key);

List *slist_add_head(List *list, uint32_t data);
List *slist_add_tail(List *list, uint32_t data);

List *slist_delete_head(List *list);
List *slist_delete_tail(List *list);

List *slist_add_on_data(List *list, uint32_t key, uint32_t data);
List *slist_delete_on_data(List *list, uint32_t key);

List *slist_reverse_list(List *list);
List *slist_delete_dupicates(List *list);

bool slist_detect_cycle(List *list);
uint32_t slist_element_at_position(List *list, uint32_t position);

List *slist_union(List *list_1, List *list_2);
List *slist_intersection(List *list_1, List *list_2);

List slist_display_list(List *list);


#endif // SLIST_H_INCLUDED
