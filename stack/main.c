#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "stack.h"

void test_stack(){
    Stack stack = stack_new(18);

    assert(stack.top == -1);
    assert(stack.size == 18);

    stack_display(&stack);
}

int main()
{
    test_stack();
    return 0;
}
