#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<stdint.h>

#define MAX_DEPTH 32

#define RESULT_INVALID 0
#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 4

struct _stack_ {
    uint32_t size;
    int32_t top;
    float stk[MAX_DEPTH];
};

typedef struct _stack_ Stack;

Stack stack_new(uint32_t size);

uint32_t stack_is_full(const Stack *stack);
uint32_t stack_is_empty(const Stack *stack);

Stack *stack_push(Stack *stack, float data);
Stack *stack_pop(Stack *stack);

void stack_display(const Stack *stack);

#endif // STACK_H_INCLUDED
