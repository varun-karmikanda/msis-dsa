#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

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

List *dll_add_tail(List *list, uint32_t data);

bool dll_detect_cycle(List *list);

void dll_display(List *list);

#endif // DLL_H_INCLUDED
