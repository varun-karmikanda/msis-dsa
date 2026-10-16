#ifndef STUDENT_SLIST_H_INCLUDED
#define STUDENT_SLIST_H_INCLUDED

#define MAX_NAME_LENGTH 25

#include<stdint.h>
#include<stddef.h>
#include<stdbool.h>

typedef struct _student_ Student;
typedef struct _student_node_ StudentNode;
typedef struct _student_list_ StudentList;

struct _student_ {
    uint32_t roll_no;
    char name[MAX_NAME_LENGTH];
    float marks;
};

struct _student_node_ {
    Student data;
    StudentNode *next;
};

struct _student_list_ {
    StudentNode *head;
    StudentNode *tail;
    size_t size;
};

StudentList *student_list_new();
StudentList *student_list_free(StudentList *student_list);

size_t student_list_size(StudentList *student_list);

StudentNode *student_list_lookup_roll_no(StudentList *student_list, uint32_t roll_no);
StudentNode *student_list_lookup_name(StudentList *student_list, char name[MAX_NAME_LENGTH]);

StudentList *student_list_add_student(StudentList *student_list, uint32_t roll_no, char name[MAX_NAME_LENGTH], float marks);

StudentList *student_list_remove_student(StudentList *student_list, uint32_t roll_no);

bool student_list_contains(StudentList *student_list, uint32_t roll_no);

void student_list_display(StudentList *student_list);

#endif // STUDENT_SLIST_H_INCLUDED
