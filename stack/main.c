#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "stack.h"

void test_stack(){
    Stack stack = stack_new(10);
    StackResult stack_result;

    assert(stack_is_empty(&stack));

    assert(stack.top == -1);
    assert(stack.size == 10);

    stack_push(&stack, 67, &stack_result);
    assert(stack.top == 0);
    assert(stack.stk[stack.top] == 67);
    assert(stack_result.status == STACK_OK);

    stack_push(&stack, 51, &stack_result);
    stack_push(&stack, 63, &stack_result);
    stack_push(&stack, 33, &stack_result);
    stack_display(&stack, &stack_result);

    stack_push(&stack, 95, &stack_result);
    assert(stack.top == 4);
    assert(stack.stk[stack.top] == 95);
    assert(stack_result.status == STACK_OK);

    stack_push(&stack, 88, &stack_result);
    stack_push(&stack, 91, &stack_result);
    stack_push(&stack, 24, &stack_result);
    stack_push(&stack, 12, &stack_result);
    stack_push(&stack, 15, &stack_result);
    stack_display(&stack, &stack_result);

    stack_push(&stack, 99, &stack_result);
    assert(stack.top == 9);
    assert(stack.stk[stack.top] == 15);
    assert(stack_result.status == STACK_FULL);

    assert(stack_is_full(&stack));

    stack_pop(&stack, &stack_result);
    assert(stack.top == 8);
    assert(stack.stk[stack.top] == 12);
    assert(stack_result.status == STACK_OK);

    stack_display(&stack, &stack_result);

    stack_push(&stack, 55, &stack_result);
    assert(stack.top == 9);
    assert(stack.stk[stack.top] == 55);
    assert(stack_result.status == STACK_OK);

    stack_display(&stack, &stack_result);

    stack_pop(&stack, &stack_result);
    stack_display(&stack, &stack_result);

    stack_peek(&stack, &stack_result);
    assert(stack.top == 8);
    assert(stack.stk[stack.top] == 12);
    assert(stack_result.status == STACK_OK);

    stack_display(&stack, &stack_result);

    stack_pop(&stack, &stack_result);
    stack_pop(&stack, &stack_result);
    stack_pop(&stack, &stack_result);
    stack_pop(&stack, &stack_result);
    stack_pop(&stack, &stack_result);
    stack_pop(&stack, &stack_result);
    stack_pop(&stack, &stack_result);

    stack_pop(&stack, &stack_result);
    assert(stack.top == 0);
    assert(stack.stk[stack.top] == 67);
    assert(stack_result.status == STACK_OK);

    stack_pop(&stack, &stack_result);
    stack_display(&stack, &stack_result);

    stack_pop(&stack, &stack_result);
    stack_display(&stack, &stack_result);

    assert(stack.top == -1);
    assert(stack_result.status == STACK_EMPTY);

    stack_peek(&stack, &stack_result);
    stack_display(&stack, &stack_result);
}

int main()
{
    test_stack();
    return 0;
}
