#include<stdio.h>
#include<stdint.h>
#include "stack.h"

Stack stack_new(uint32_t size){
    size = (size > 0 && size <= MAX_DEPTH) ? size : MAX_DEPTH;
    Stack stack = {size, -1, {0}};
    return stack;
}

uint32_t stack_full(const Stack *stack);
uint32_t stack_empty(const Stack *stack);

Stack *stack_push(Stack *stack, float data, StackResult *stackResult);
Stack *stack_pop(Stack *stack, StackResult *stackResult);
Stack *stack_peek(const Stack *stack, StackResult *stackResult);

void stack_display(const Stack *stack){
    printf("\nSTACK {");

    if(stack -> top != -1){
        for(int i = 0; i <= stack -> top; i++) {
            printf("\n\tstack[%d] = %d", i, stack -> stk[i]);
        }
    } else {
        printf("\n\tEMPTY");
    }

    printf("\n}");
}
