#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "q02_stack.h"

void q02_test_stack(){

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
    printf("----- Q02 - STACK -----\n");
    q02_test_stack();
    return 0;
}
