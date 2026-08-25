#include<stdlib.h>
#include<stdint.h>
#include "slist.h"

static Node *_list_new_node_(uint32_t data){
    Node *node = (Node*) malloc (sizeof(Node));

    if(node == NULL) return NULL;

    node -> data = data;
    node -> next = NULL;
    return node;
}

List *slist_new(){
    List *list;
    list -> head = NULL;
    list -> tail = NULL;
    list -> length = 0;
    return list;
}

List *slist_free(List *list){
    Node *p;
    list -> tail = NULL;
    while(list != NULL){
        p = list -> head;
        list -> head = list -> head -> next;
        free(p);
        --list -> length;
    }
    return list;
}

uint32_t slist_length(List *list){
    return list -> length;
}

Node *slist_lookup(List *list, uint32_t key){
    Node *node = list -> head;
    for(; node != NULL; node = node -> next){
        if(node -> data == key) return node;
    }
    return NULL;
}

List *slist_add_head(List *list, uint32_t data) {
    Node * new_node = _list_new_node_(data);

    if(list -> head == NULL){
        list -> head = list -> tail = new_node;
    } else {
        new_node -> next = list -> head;
        list -> head = new_node;
    }

    ++list -> length;
    return list;
}

List *slist_add_tail(List *list, uint32_t data){
    Node *new_node = _list_new_node_(data);

    if(list -> head == NULL){
        list -> head = list -> tail = NULL;
    } else {
        list -> tail -> next = new_node;
        list -> tail = new_node;
    }

    ++list -> length;
    return list;
}

List *slist_delete_head(List *list){
    Node *node;

    if(list -> head != NULL){
        node = list -> head;
        list -> head = list -> head -> next;
        if(list -> head == NULL) {
            list -> tail == NULL;
        }
        free(node);
        --list -> length;
    }
    return list;
}

List *slist_delete_tail(List *list){
    if(list -> tail != NULL){
        Node *node = list -> tail;
        if(list -> head == list -> tail){
            list -> head = list -> tail = NULL;
        } else {
            Node *n;
            for(n = list -> head; n -> next != list -> tail; n = n -> next);
            n -> next = NULL;
            list -> tail = n;
        }
        --list -> length;
        free(node);
    }
    return list;
}

List *slist_add_in_between(List *list, uint32_t key, uint32_t data){

}

List *slist_add_after_data(List *list, uint32_t key, uint32_t data){
    Node *current = list-> head;
    for( ; current != NULL && current -> data != key; current = current -> next);
    if(current != NULL){
        Node * node = _list_new_node_(data);
        node -> next = current -> next;
        current -> next = node;
        if(current == list -> tail){
            list -> tail = node;
        }
        ++list -> length;
    }
    return list;
}

List *slist_reverse_list(List *list){
    Node *previous = NULL;
    Node *current = list-> head;
    Node *next;
    Node *new_tail = list -> head;
    while(current != NULL){
        next = current -> next;
        current -> next = previous;
        previous = current;
        current = next;
    }
    list -> head = previous;
    list -> tail = new_tail;
    return list;
}

List *slist_display_list(List *list){
    printf("\nLINKEDLIST{\n\t");
    for(Node *node = list -> head; node != NULL; node = node -> next){
        printf("%d -> ", node -> data);
    }
    printf("NULL\n}\n");
}
