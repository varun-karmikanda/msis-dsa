#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "q01_double_linked_list.h"
#include "q02_stack.h"

void q01_test_dll(){

    printf("----- Q01 - DOUBLE LINED LIST -----");

    List *list = dll_new();

    assert(list -> head == NULL);
    assert(list -> tail == NULL);
    assert(list -> length == 0);

    dll_display(list);

//     add_head

    dll_add_head(list, 67);
    dll_add_head(list, 29);
    dll_add_head(list, 25);
    dll_add_head(list, 1);

    assert(list -> head -> data == 1);
    assert(list -> tail -> data = 67);
    assert(list -> length == 4);

    dll_display(list);

//     add_tail

    dll_add_tail(list, 420);
    dll_add_tail(list, 747);
    dll_add_tail(list, 911);

    assert(list -> tail -> data == 911);
    assert(list -> tail -> prev -> data == 747);
    assert(list -> length == 7);

    dll_display(list);

//     add_on_data

    dll_add_on_data(list, 67, 95);
    dll_add_on_data(list, 1, 18);
    dll_add_on_data(list, 911, 1067);

    assert(list -> tail -> data == 1067);
    assert(list -> length == 10);

    dll_display(list);

//    delete_head

    dll_delete_head(list);

    assert(list -> head -> data == 18);
    assert(list -> length == 9);

    dll_display(list);

//    delete_tail

    dll_delete_tail(list);

    assert(list -> tail -> data == 911);
    assert(list -> length == 8);

    dll_display(list);

//    delete_on_data

    dll_delete_on_data(list, 18);
    dll_delete_on_data(list, 911);
    dll_delete_on_data(list, 95);
    dll_delete_on_data(list, 77);

    assert(list -> head -> data == 25);
    assert(list -> tail -> data == 747);
    assert(list -> length == 5);

    dll_display(list);
}

void q02_test_stack(){
    printf("----- Q02 - STACK -----");

    Stack stack = stack_new(6);
    StackResult stack_result;

    stack_push(&stack, 20, &stack_result);
    assert(stack.top == 0);
    assert(stack.stk[stack.top] == 20);
    assert(stack_result.status == STACK_OK);

    stack_display(&stack, &stack_result);

    stack_push(&stack, 45, &stack_result);
    stack_push(&stack, 65, &stack_result);
    stack_push(&stack, 75, &stack_result);
    stack_push(&stack, 33, &stack_result);
    stack_push(&stack, 50, &stack_result);
    stack_display(&stack, &stack_result);

    stack_display_key(&stack, 65, &stack_result);

    stack_display_key(&stack, 67, &stack_result);
    stack_display(&stack, &stack_result);

}

int main()
{
//    q01_test_dll();
    q02_test_stack();
    return 0;
}
