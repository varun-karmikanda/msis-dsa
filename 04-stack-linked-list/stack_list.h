#ifndef STACK_LIST_H_INCLUDED
#define STACK_LIST_H_INCLUDED

#include<stdint.h>

#define MAX_DEPTH 32

#define RESULT_INVALID 0
#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 4

typedef struct _node_ Node;
typedef struct _stack_ Stack;
typedef struct _stack_result_ StackResult;

struct _node_ {
    uint32_t data;
    Node* next;
};

struct _stack_ {
    uint32_t size;
    uint32_t count;
    Node* top;
};

struct _stack_result_ {
    uint32_t data;
    uint32_t status;
};

Stack *stack_new(uint32_t size, StackResult *res);

uint32_t stack_is_full(const Stack *stack);
uint32_t stack_is_empty(const Stack *stack);

Stack *stack_push(Stack *stack, uint32_t data, StackResult *res);
Stack *stack_pop(Stack *stack, StackResult *res);
Stack *stack_peek(const Stack *stack, StackResult *res);

Stack *stack_clear(Stack *stack);

void stack_display(const Stack *stack, StackResult *res);

#endif // STACK_LIST_H_INCLUDED
