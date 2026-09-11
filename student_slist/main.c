#include <assert.h>
#include <stdio.h>
#include<string.h>
#include "student_slist.h"

int main(void) {

   StudentList *studentList = student_list_new();

   assert(studentList -> head == NULL);
   assert(studentList -> tail == NULL);
   assert(studentList -> size == 0);
   student_list_display(studentList);

   assert(student_list_size(studentList) == 0);


   student_list_add_student(studentList, 67, "Varun", 100);
   student_list_add_student(studentList, 74, "Arun", 90);
   student_list_add_student(studentList, 67, "Ajay", 80);

   assert(studentList -> head -> data.roll_no == 67);
   assert(strcmp(studentList -> head -> data.name, "Varun") == 0);
   assert(studentList -> tail -> data.roll_no == 74);
   student_list_display(studentList);

   student_list_add_student(studentList, 45, "Nitr0x", 99);
   student_list_add_student(studentList, 39, "Goku", 85);
   student_list_add_student(studentList, 88, "Dev", 75);

   student_list_display(studentList);


   StudentNode *node = student_list_lookup_roll_no(studentList, 67);
   assert(node != NULL);
   assert(node -> data.roll_no == 67);


   node = student_list_lookup_name(studentList, "Nitr0x");
   assert(node != NULL);
   assert(node -> data.roll_no == 45);

   student_list_display(studentList);


   assert(student_list_contains(studentList, 67));
   assert(!student_list_contains(studentList, 1));
   assert(student_list_contains(studentList, 88));
   assert(!student_list_contains(studentList, 44));


   assert(student_list_lookup_roll_no(studentList, 74));
   student_list_remove_student(studentList, 74);
   assert(!student_list_lookup_roll_no(studentList, 74));
   student_list_display(studentList);

}
