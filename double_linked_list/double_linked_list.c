#include<stdint.h>
#include<stdbool.h>
#include<stdio.h>
#include "double_linked_list.h"

static Node *_new_node_(uint32_t data){
    Node *new_node = (Node*) malloc (sizeof(Node));

    if(new_node == NULL) return NULL;

    new_node -> data = data;
    new_node -> prev = NULL;
    new_node -> next = NULL;

    return new_node;
}


List *dll_new(){
    List *new_list = (List*) malloc (sizeof(List));

    if(new_list == NULL) return NULL;

    new_list -> head = NULL;
    new_list -> tail = NULL;
    new_list -> length = 0;

    return new_list;
}

List *dll_free(List *list){
    if(list == NULL) return NULL;

    List *temp;

    while(list -> head != NULL){
        temp = list -> head;
        list -> head = list -> head -> next;
        free(temp);
    }

    list -> tail = NULL;
    list -> length = 0;

    return list;
}

List *dll_add_head(List* list, uint32_t data){
    if(list == NULL) return NULL;

    Node *new_node = _new_node_(data);
    if(new_node == NULL) return list;

    if(list -> head == NULL){
        list -> head = list -> tail = new_node;
    } else {
        new_node -> next = list -> head;
        list -> head -> prev = new_node;
        list -> head = new_node;
    }
    ++list -> length;

    return list;
}

List *dll_add_tail(List *list, uint32_t data){
    if(list == NULL) return NULL;

    Node *new_node = _new_node_(data);
    if(new_node == NULL) return list;

    if(list -> head == NULL){
        list -> head = list -> tail = new_node;
    } else {
        list -> tail -> next = new_node;
        new_node -> prev = list -> tail;
        list -> tail = new_node;
    }
    ++list -> length;

    return list;
}

List *dll_add_on_data(List *list, uint32_t key, uint32_t data){
    if(list == NULL) return NULL;

    Node *curr = list -> head;
    for(; curr != NULL && curr -> data != key; curr = curr -> next);

    if(curr == NULL) return list;


    Node *new_node = _new_node_(data);
    if(new_node == NULL) return list;

    new_node -> prev = curr;
    new_node -> next = curr -> next;

    if(curr -> next != NULL){
        curr -> next -> prev = new_node;
    } else {
        list -> tail = new_node;
    }

    curr -> next = new_node;
    ++list -> length;

    return list;
}


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

void dll_display(List *list){
    printf("\nDOUBLY_LINKED_LIST {");
    if(list -> head != NULL){
        printf("\n\tNULL (%p)", list -> head -> prev);
    } else {
        printf("\n\tNULL");
    }
    for(Node *node = list -> head; node != NULL; node = node -> next){
        printf("\n\t<- (%p) | \033[1;36m%4d\033[0m (%p) | (%p) ->", node -> prev, node -> data, node, node -> next);
    }
    if(list -> head != NULL){
        printf("\n\tNULL (%p)", list -> tail -> next);
    }
    printf("\n}");
}
