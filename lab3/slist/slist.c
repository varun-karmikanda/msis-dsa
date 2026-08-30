#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include "slist.h"

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

uint32_t slist_length(List *list){
    if(list == NULL) return 0;
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

    if(new_node == NULL) return list;

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
        list -> head = list -> tail = new_node;
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
            list -> tail = NULL;
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


List *slist_add_on_data(List *list, uint32_t key, uint32_t data){
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

List *slist_delete_on_data(List *list, uint32_t key){
    if(list -> head != NULL){
        Node *current, *previous;
        current = list -> head;
        if(current -> data == key){
            list -> head = current -> next;
            --list -> length;
        } else {
            previous = current;
            current = current -> next;
            while(current !=NULL){
                if(current -> data == key){
                    previous -> next = current -> next;
                    --list -> length;
                    break;
                } else {
                    previous = current;
                    current = current -> next;
                }
            }
            if(current == list -> tail){
                list -> tail = previous;
            }
        }
        if(list -> head == NULL){
            list -> tail = NULL;
        }
        free(current);
    }
    return list;
}

List *slist_reverse_list(List *list){
    if(list == NULL) return NULL;
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

List *slist_delete_dupicates(List *list){
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

bool slist_detect_cycle(List *list){
    Node *slow = list -> head;
    Node *fast = list -> head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return true;
    }
    return false;
}
uint32_t slist_element_at_position(List *list, uint32_t position){
    Node *node = list -> head;
    if(position == 0 || position > list -> length){
        return -1;
    } else {
        for(int i = 1; i < position; i++){
            node = node -> next;
        }
    }
    return node -> data;
}

static bool slist_is_duplicate(List *list, uint32_t key){
    Node *node = list -> head;
    for(; node != NULL; node = node -> next){
        if(node -> data == key) return true;
    }
    return false;
}

List *slist_union(List *list_1, List *list_2){
    List *list_union = slist_new();

    if(list_1 != NULL){
        for(Node *node = list_1 -> head; node != NULL; node = node -> next){
            if(!slist_is_duplicate(list_union, node -> data)){
                slist_add_tail(list_union, node -> data);
            }
        }
    }

    if(list_2 != NULL){
        for(Node *node = list_2 -> head; node != NULL; node = node -> next){
            if(!slist_is_duplicate(list_union, node -> data)){
                slist_add_tail(list_union, node -> data);
            }
        }
    }

    return list_union;
}

List *slist_intersection(List *list_1, List *list_2){
    if(list_1 == NULL || list_2 == NULL) return NULL;

    List *list_intersection = slist_new();

    for(Node *node = list_1 -> head; node != NULL; node = node -> next){
        if(slist_is_duplicate(list_2, node -> data) && !slist_is_duplicate(list_intersection, node -> data)){
            printf("EXIST %d", node -> data);
            slist_add_tail(list_intersection, node -> data);
        }
    }
    return list_intersection;
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
