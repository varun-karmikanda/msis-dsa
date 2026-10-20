#include<stdint.h>
#include<stdbool.h>
#include "q02_stack.h"

static void _set_stack_result_(StackResult *stack_result, uint32_t data, uint32_t status){
    stack_result -> data = data;
    stack_result -> status = status;
}

Stack stack_new(uint32_t size){
    size = (size > 0 && size <= MAX_DEPTH) ? size : MAX_DEPTH;
    Stack stack = {size, -1, {0}};
    return stack;
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

Stack *stack_display_key(Stack *stack, uint32_t key, StackResult *StackResult){
    Stack temp_stack = stack_new(stack->size);
    bool found = false;

    while(stack->top != -1){
        stack_peek(stack, StackResult);
        if(StackResult->data == key){
            printf("\nFound key %0.2f", StackResult->data);
            found = true;
            break;
        }
        stack_pop(stack, StackResult);
        if(StackResult->status == STACK_OK)
            stack_push(&temp_stack, StackResult->data, StackResult);
    }

    if(!found)
        printf("\nKey %d not found", key);

    while(temp_stack.top != -1){
        stack_pop(&temp_stack, StackResult);
        stack_push(stack, StackResult->data, StackResult);
    }

    return stack;
}

Stack *stack_clear(Stack *stack, StackResult *StackResult){
    stack->top = -1;
    stack->size = 0;

    StackResult->data = RESULT_INVALID;
    StackResult->status = STACK_OK;
}
