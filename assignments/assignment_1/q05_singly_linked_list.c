#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include "q05_singly_linked_list.h"

static Node *_list_new_node_(uint32_t data){
    Node *node = (Node*) malloc (sizeof(Node));

    if(node == NULL) return NULL;

    node -> data = data;
    node -> next = NULL;
    return node;
}

List *sll_new(){
    List *list = (List*) malloc (sizeof(List));

    if(list == NULL) return NULL;

    list -> head = NULL;
    list -> tail = NULL;
    list -> min = 0;
    list -> max = 0;
    list -> length = 0;
    return list;
}

List *sll_free(List *list){
    if(list == NULL) return NULL;
    Node *p;
    while(list -> head != NULL){
        p = list -> head;
        list -> head = list -> head -> next;
        free(p);
    }
    list -> tail = NULL;
    list -> min = 0;
    list -> max = 0;
    list -> length = 0;
    free(list);
    return NULL;
}

List *sll_add_head(List *list, uint32_t data) {
    if(list == NULL) return NULL;

    Node * new_node = _list_new_node_(data);

    if(new_node == NULL) return list;

    if(list -> head == NULL){
        list -> head = list -> tail = new_node;

        list -> min = list -> max = data;
    } else {
        new_node -> next = list -> head;
        list -> head = new_node;

        if(data < list -> min) list -> min = data;

        if(data > list -> max) list -> max = data;
    }


    ++list -> length;
    return list;
}

List *sll_add_tail(List *list, uint32_t data){
    if(list == NULL) return NULL;

    Node *new_node = _list_new_node_(data);

    if(new_node == NULL) return list;

    if(list -> head == NULL){
        list -> head = list -> tail = new_node;

        list -> min = list -> max = data;
    } else {
        list -> tail -> next = new_node;
        list -> tail = new_node;

        if(data < list -> min) list -> min = data;

        if(data > list -> max) list -> max = data;
    }

    ++list -> length;
    return list;
}

void sll_display_list(List *list){
    if(list == NULL){
        printf("--- NULL ---");
    } else {
        printf("\nLINKEDLIST{");
        printf("\n\tmin: %d", list -> min);
        printf("\n\tmax: %d", list -> max);
        printf("\n\tlength: %d", list -> length);
        printf("\n\tnodes: ");
        for(Node *node = list -> head; node != NULL; node = node -> next){
            printf("%d -> ", node -> data);
        }
        printf("NULL\n}\n");
    }
}

uint32_t sll_minimum(List *list){
    if(list == NULL || list -> length == 0) return 0;
    return list -> min;
}

uint32_t sll_maximum(List *list){
    if(list == NULL || list -> length == 0) return 0;
    return list -> max;
}


List *sll_delete_dupicates(List *list){
    if(list == NULL) return NULL;

    Node *ptr_1 = list -> head, *ptr_2;
    for(; ptr_1 != NULL && ptr_1 -> next != NULL; ptr_1 = ptr_1 -> next){
        for(ptr_2 = ptr_1; ptr_2 -> next != NULL;){
            if(ptr_1 -> data == ptr_2 -> next -> data){
                Node *duplicate = ptr_2 -> next;
                ptr_2 -> next = ptr_2 -> next -> next;

                if(duplicate == list -> tail){
                    list -> tail = ptr_2;
                }

                free(duplicate);
                --list -> length;
            } else {
                ptr_2 = ptr_2 -> next;
            }
        }
    }
    return list;
}
