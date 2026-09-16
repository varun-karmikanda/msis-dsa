#include<stdio.h>
#include<stdint.h>
#include "stack.h"

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


Stack *stack_push(Stack *stack, float data, StackResult *stackResult){
    if(stack -> top + 1 < stack -> size){
        stack -> stk[++stack -> top] = data;
        stackResult -> data = stack -> stk[stack -> top];
        stackResult -> status = STACK_OK;
    } else {
        stackResult -> data = data;
        stackResult -> status = STACK_FULL;
    }
    return stack;
}

Stack *stack_pop(Stack *stack, StackResult *stackResult){
    stack_display(stack, stackResult);
    if(stack -> top > -1){
        stackResult -> data = stack -> stk[stack -> top];
        stackResult -> status = STACK_OK;
        --stack -> top;
    } else {
        stackResult -> data = RESULT_INVALID;
        stackResult -> status = STACK_EMPTY;
    }
    return stack;
}

Stack *stack_peek(const Stack *stack, StackResult *stackResult){
    if(stack -> top > -1){
        stackResult -> data = stack -> stk[stack -> top];
        stackResult -> status = STACK_OK;
    } else {
        stackResult -> data = RESULT_INVALID;
        stackResult -> status = STACK_EMPTY;
    }
}


void stack_display(const Stack *stack, StackResult *stackResult){
    printf("\nSTACK {");
    printf("\n\tsize : %d", stack -> size);
    printf("\n\ttop  : %d", stack -> top);
    printf("\n\tstk  : {");
    if(stack -> top != -1){
//        for(int i = 0; i < stack -> size; i++) {
//            printf("\n\t\tstack[%02d] = %f", i, stack -> stk[i]);
//        }
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
