#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "stack.h"

void test_stack(){
    Stack stack = stack_new(10);
//    Stack stack = stack_new(11);
    StackResult stack_result;

    assert(stack.top == -1);
    assert(stack.size == 10);
//    assert(stack.size == 11);

    stack_display(&stack);

    stack_push(&stack, 67, &stack_result);
    stack_display(&stack);

    stack_push(&stack, 51, &stack_result);
    stack_push(&stack, 63, &stack_result);
    stack_push(&stack, 33, &stack_result);
    stack_push(&stack, 95, &stack_result);
    stack_push(&stack, 88, &stack_result);
    stack_push(&stack, 91, &stack_result);
    stack_push(&stack, 24, &stack_result);
    stack_push(&stack, 12, &stack_result);
    stack_push(&stack, 15, &stack_result);
    stack_push(&stack, 99, &stack_result);
    stack_display(&stack);
}

int main()
{
    test_stack();
    return 0;
}
