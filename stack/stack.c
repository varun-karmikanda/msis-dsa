#include<stdio.h>
#include<stdint.h>
#include "stack.h"

static void _set_stack_result_(StackResult *stack_result, uint32_t data, uint32_t status){
    stack_result -> data = data;
    stack_result -> status = status;
}

Stack stack_new(uint32_t size){
    size = (size > 0 && size <= MAX_DEPTH) ? size : MAX_DEPTH;
    Stack stack = {size, -1, {0}};
    return stack;
}

uint32_t stack_is_full(const Stack *stack){
    return stack -> top + 1 == stack -> size;
}

uint32_t stack_is_empty(const Stack *stack){
    return stack -> top == -1;
}


Stack *stack_push(Stack *stack, float data, StackResult *stack_result){
    if(stack -> top + 1 < stack -> size){
        stack -> stk[++stack -> top] = data;
        _set_stack_result_(stack_result, data, STACK_OK);
    } else {
        _set_stack_result_(stack_result, data, STACK_FULL);
    }
    return stack;
}

Stack *stack_pop(Stack *stack, StackResult *stack_result){
    if(stack -> top > -1){
        _set_stack_result_(stack_result, stack -> stk[stack -> top], STACK_OK);
        --stack -> top;
    } else {
        _set_stack_result_(stack_result, RESULT_INVALID, STACK_EMPTY);
    }
    return stack;
}

Stack *stack_peek(const Stack *stack, StackResult *stack_result){
    if(stack -> top > -1){
        _set_stack_result_(stack_result, stack -> stk[stack -> top], STACK_OK);
    } else {
        _set_stack_result_(stack_result, RESULT_INVALID, STACK_EMPTY);
    }
}


void stack_display(const Stack *stack, StackResult *stackResult){
    printf("\nSTACK {");
    printf("\n\tsize : %d", stack -> size);
    printf("\n\ttop  : %d", stack -> top);
    printf("\n\tstk  : {");
    if(stack -> top != -1){
        for(int i = stack -> size - 1; i >= 0; i--) {
            if(stack -> size -1 >= 10) printf("\n\t\tstack[%02d] = %5.2f", i, stack -> stk[i]);
            else printf("\n\t\tstack[%d] = %5.2f", i, stack -> stk[i]);
            if(i == stack -> top) printf(" <-- TOP OF STACK");
        }
    } else {
        printf("\n\t\tEMPTY");
    }
    printf("\n\tSTACK_RESULT {");
    printf("\n\t\tdata   : %5.2f", stackResult-> data);
    printf("\n\t\tstatus : %d", stackResult -> status);
    printf("\n\t}");
    printf("\n\t}");
    printf("\n}");
}
