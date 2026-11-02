#include<stdint.h>
#include<stdlib.h>
#include "linked_list.h"

static Node *_list_new_node_(uint32_t data){
    Node *node = (Node*) malloc (sizeof(Node));

    if(node == NULL) return NULL;

    node -> data = data;
    node -> next = NULL;
    return node;
}

List *slist_new(){
    List *list = (List*) malloc (sizeof(List));

    if(list == NULL) return NULL;

    list -> head = NULL;
    list -> tail = NULL;
    list -> length = 0;
    return list;
}

List *slist_free(List *list){
    if(list == NULL) return NULL;
    Node *p;
    while(list -> head != NULL){
        p = list -> head;
        list -> head = list -> head -> next;
        free(p);
    }
    list -> tail = NULL;
    list -> length = 0;
    free(list);
    return NULL;
}

List *slist_add_tail(List *list, uint32_t data){
    Node *new_node = _list_new_node_(data);

    if(list -> head == NULL){
        list -> head = list -> tail = new_node;
    } else {
        list -> tail -> next = new_node;
        list -> tail = new_node;
    }

    ++list -> length;
    return list;
}

List slist_display_list(List *list){
    if(list == NULL){
        printf("--- NULL ---");
    } else {
        printf("\nLINKEDLIST{\n\t");
        for(Node *node = list -> head; node != NULL; node = node -> next){
            printf("%d -> ", node -> data);
        }
        printf("NULL\n}\n");
    }
}
