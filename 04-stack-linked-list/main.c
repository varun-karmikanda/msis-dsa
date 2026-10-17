#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack_list.h"

void test_stack_list(){
    StackResult res;
    Stack *stack = stack_new(7, &res);

    assert(stack_is_empty(stack) == 1);
    assert(stack_is_full(stack) == 0);

    stack_display(stack, &res);

    stack_push(stack, 67, &res);
    stack_push(stack, 51, &res);
    stack_push(stack, 95, &res);
    stack_push(stack, 4, &res);
    stack_display(stack, &res);

    assert(stack_is_empty(stack) == 0);
    assert(stack_is_full(stack) == 0);

    stack_push(stack, 95, &res);
    stack_push(stack, 36, &res);
    stack_push(stack, 78, &res);
    stack_push(stack, 99, &res);
    stack_display(stack, &res);

    assert(stack_is_full(stack) == 1);

    stack_pop(stack, &res);
    stack_pop(stack, &res);
    stack_pop(stack, &res);
    stack_pop(stack, &res);
    stack_display(stack, &res);

    stack_pop(stack, &res);
    stack_pop(stack, &res);

    stack_peek(stack, &res);
    assert(res.data == 67);
    assert(res.status == 1);

    stack_pop(stack, &res);
    stack_pop(stack, &res);
    stack_display(stack, &res);

    assert(stack_is_empty(stack) == 1);

    stack_push(stack, 67, &res);
    stack_push(stack, 51, &res);
    stack_display(stack, &res);

    stack_clear(stack);
    stack_display(stack, &res);
}

int main()
{
    test_stack_list();
    return 0;
}
