#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "student_slist.h"

static StudentNode *_student_list_new_node_(uint32_t roll_no, char name[MAX_NAME_LENGTH], float marks){
    StudentNode *student_node = (StudentNode
    *) malloc (sizeof(StudentNode));

    if(student_node == NULL) return NULL;

    student_node -> data.roll_no = roll_no;
    strncpy(student_node -> data.name, name, MAX_NAME_LENGTH - 1);
    student_node -> data.name[MAX_NAME_LENGTH - 1] = '\0';
    student_node -> data.marks = marks;

    student_node -> next = NULL;

    return student_node;
}

StudentList *student_list_new(){
    StudentList *student_list = (StudentList*) malloc (sizeof(StudentList));

    if(student_list == NULL) return NULL;

    student_list -> head = NULL;
    student_list -> tail = NULL;
    student_list -> size = 0;

    return student_list;
}

StudentList *student_list_free(StudentList *student_list){
    if(student_list == NULL) return NULL;

    StudentNode *p;
    while(student_list -> head != NULL){
        p = student_list -> head;
        student_list -> head = student_list -> head -> next;
        free(p);
    }
    student_list -> tail = NULL;
    student_list -> size = 0;

    free(student_list);
    return NULL;
}

size_t student_list_size(StudentList *student_list){
    if(student_list == NULL) return 0;

    return student_list -> size;
}

StudentNode *student_list_lookup_roll_no(StudentList *student_list, uint32_t roll_no){
    StudentNode *student_node;
    for(student_node = student_list -> head; student_node != NULL; student_node = student_node -> next){
        if(student_node -> data.roll_no == roll_no) return student_node;
    }
    return NULL;
}

StudentNode *student_list_lookup_name(StudentList *student_list, char name[MAX_NAME_LENGTH]){
    StudentNode *student_node;
    for(student_node = student_list -> head; student_node != NULL; student_node = student_node -> next){
        if(strcmp(student_node -> data.name, name) == 0) return student_node;
    }
    return NULL;
}

StudentList *student_list_add_student(StudentList *student_list, uint32_t roll_no, char name[MAX_NAME_LENGTH], float marks){
    if(student_list == NULL) return NULL;

    StudentNode *new_student_node = _student_list_new_node_(roll_no, name, marks); 
    if(new_student_node == NULL) return NULL;
    
    if(student_list -> head == NULL){
        student_list -> head = student_list ->tail = new_student_node;
    } else {
        student_list -> tail -> next = new_student_node;
        student_list -> tail = new_student_node;
    }
    ++student_list -> size;
    return student_list;
}

StudentList *student_list_remove_student(StudentList *student_list, uint32_t roll_no){
    if(student_list == NULL || student_list -> head == NULL) return student_list;
    
    StudentNode *previous = NULL;
    StudentNode *current = student_list -> head;

    while(current != NULL){
        if(current -> data.roll_no == roll_no){
            if(previous == NULL){
                student_list -> head = current -> next;
            } else {
                previous -> next = current -> next;
            }

            if(current == student_list -> tail){
                student_list -> tail = previous;
            }

            free(current);
            --student_list -> size;

            return student_list;
        }

        previous = current;
        current = current -> next;
    }
    return student_list;
}

bool student_list_contains(StudentList *student_list, uint32_t roll_no){
    StudentNode *student_node = student_list_lookup_roll_no(student_list, roll_no);

    if(student_node == NULL) return false;
    return true;
}

void student_list_display(StudentList *student_list){
    if(student_list == NULL){
        printf("--- NULL ---");
    } else {
        printf("\nSTUDENT_LIST{\n\t");
        for(StudentNode *student_node = student_list -> head; student_node != NULL; student_node = student_node -> next){
            printf("| %d | %s | %f | -> \n\t", student_node -> data.roll_no, student_node -> data.name, student_node -> data.marks);
        }
        printf("NULL\n}\n");
    }
}