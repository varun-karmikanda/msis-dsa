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


List *dll_delete_head(List *list){
    if(list == NULL) return NULL;

    if(list -> head == NULL) return list;

    Node *temp = list -> head;

    if(list -> head == list -> tail){
        list -> head = list -> tail = NULL;
    } else {
        list -> head = list -> head -> next;
        list -> head -> prev = NULL;
    }

    --list -> length;

    free(temp);

    return list;
}

List *dll_delete_tail(List *list){
    if(list == NULL) return NULL;

    if(list -> head == NULL) return list;

    Node *curr = list -> head;
    Node *temp;

    if(curr == list -> tail){
        temp = curr;
        list -> head = list -> tail = NULL;
    } else {
        for(; curr -> next != list -> tail; curr = curr -> next);
        temp = curr -> next;
        curr -> next = NULL;
        list -> tail = curr;
    }

    --list -> length;

    free(temp);

    return list;
}

List *dll_delete_on_data(List *list, uint32_t data){
    if(list == NULL) return NULL;

    if(list -> head == NULL) return list;

    Node *curr = list -> head;

    while(curr != NULL && curr -> data != data){
        curr = curr -> next;
    }

    if(curr == NULL) return list;

    if(curr -> prev != NULL){
        curr -> prev -> next = curr -> next;
    } else {
        list -> head = curr -> next;
    }

    if(curr -> next != NULL){
        curr -> next -> prev = curr -> prev;
    } else {
        list -> tail = curr -> prev;
    }

    --list -> length;

    free(curr);

    return list;
}


Node *dll_lookup(List *list, uint32_t key){
    if(list == NULL) return NULL;

    Node *curr = list -> head;

    for(; curr != NULL && curr -> data != key; curr = curr -> next);

    if(curr == NULL) return NULL;

    return curr;
}

uint32_t dll_length(List *list){
    if(list == NULL) return 0;
    return list -> length;
}

uint32_t dll_element_at_position(List *list, uint32_t position){
    if(list == NULL) return 0;

    if(position > list -> length) return 0;

    Node *curr = list -> head;
    for(int i = 1; i < position; i++){
        curr = curr -> next;
    }
    return curr -> data;
}

bool dll_detect_cycle(List *list){
    if(list == NULL) return false;

    Node *slow = list -> head, *fast = list -> head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) return true;
    }

    return false;
}


List *dll_reverse(List *list){
    if(list == NULL) return NULL;

    Node *curr = list -> head, *temp;

    while(curr != NULL){
        temp = curr -> next;

        curr -> next = curr -> prev;
        curr -> prev = temp;

        curr = temp;
    }

    temp = list -> head;
    list -> head = list -> tail;
    list -> tail = temp;

    return list;
}

List *dll_delete_duplicate(List *list){
    if(list == NULL) return NULL;

    Node *curr = list -> head;
    for(; curr != NULL && curr -> next != NULL; curr = curr -> next){
        Node *runner = curr -> next;

        while(runner != NULL){
            Node *next_node = runner -> next;

            if(curr -> data == runner -> data){
                runner -> prev -> next = runner -> next;


                if(runner -> next != NULL){
                    runner -> next -> prev = runner -> prev;
                } else {
                    list -> tail = runner -> prev;
                }

                --list -> length;

                free(runner);
            }

            runner = next_node;
        }
    }

    return list;
}


List *dll_union(List *list_1, List *list_2){
    List *list_union = dll_new();

    if(list_1 != NULL){
        for(Node *node = list_1 -> head; node != NULL; node = node -> next){
            if(!dll_lookup(list_union, node -> data)){
                dll_add_tail(list_union, node -> data);
            }
        }
    }

    if(list_2 != NULL){
        for(Node *node = list_2 -> head; node != NULL; node = node -> next){
            if(!dll_lookup(list_union, node -> data)){
                dll_add_tail(list_union, node -> data);
            }
        }
    }

    return list_union;
}

List *dll_intersection(List *list_1, List *list_2){
    List *list_intersection = dll_new();

    if(list_1 != NULL && list_2 != NULL){
        for(Node *node = list_1 -> head; node != NULL; node = node -> next){
            if(dll_lookup(list_2, node -> data) && !dll_lookup(list_intersection, node -> data)){
                dll_add_tail(list_intersection, node -> data);
            }
        }
    }

    return list_intersection;
}


void dll_display(List *list){
    if(dll_detect_cycle(list)){
        printf("\nDOUBLY_LINKED_LIST: << DETECTED CYCLE >>");
        return;
    }

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
