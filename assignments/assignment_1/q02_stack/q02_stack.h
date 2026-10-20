#ifndef Q02_STACK_H_INCLUDED
#define Q02_STACK_H_INCLUDED

#define MAX_DEPTH 32

#define RESULT_INVALID 0
#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 4

#include<stdint.h>

struct _stack_ {
    uint32_t size;
    int32_t top;
    float stk[MAX_DEPTH];
};

typedef struct _stack_ Stack;

struct _stack_result_ {
    float data;
    uint32_t status;
};

typedef struct _stack_result_ StackResult;

Stack stack_new(uint32_t size);

Stack *stack_push(Stack *stack, float data, StackResult *stackResult);
Stack *stack_pop(Stack *stack, StackResult *stackResult);
Stack *stack_peek(const Stack *stack, StackResult *stackResult);

void stack_display(const Stack *stack, StackResult *stackResult);

Stack *stack_display_key(Stack *stack, uint32_t key, StackResult *StackResult);

Stack *stack_clear(Stack *stack, StackResult *StackResult);

#endif // Q02_STACK_H_INCLUDED
