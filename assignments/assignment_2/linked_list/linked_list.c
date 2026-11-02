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

static Node *_list_middle_node_(Node *node){
    Node *slow = node;
    Node *fast = node->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

static Node *_merge_(Node *left, Node *right){
    Node *dummy = _list_new_node_(0);
    Node *temp = dummy;

    while(left != NULL && right != NULL){
        if(left->data <= right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if(left) temp->next = left;
    else temp->next = right;

    return dummy->next;
}

static Node *_merge_sort_(Node *node){
    if(node == NULL || node->next == NULL) return node;

    Node *middle_node = _list_middle_node_(node);
    Node *left = node;
    Node *right = middle_node->next;
    middle_node->next = NULL;

    left = _merge_sort_(left);
    right = _merge_sort_(right);

    return _merge_(left, right);
}

List *slist_merge_sort(List *list){
    if(list == NULL || list->head == NULL) return NULL;

    if(list->head == list->tail) return list;

    list ->head = _merge_sort_(list->head);

    Node *temp = list->head;
    while(temp != NULL) temp = temp->next;

    list->tail = temp;

    return list;
}

List *slist_merge_list(List *list_1, List *list_2){
    if(list_1 == NULL) return list_2;
    if(list_2 == NULL) return list_1;

    List *merged = slist_new();

    merged->head = _merge_(list_1->head, list_2->head);

    Node *temp = merged->head;

    while(temp->next != NULL) temp = temp->next;

    merged->tail = temp;
    merged->length = list_1->length + list_2->length;

    return merged;
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
