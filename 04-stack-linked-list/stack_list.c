#include<stdio.h>
#include<stdint.h>
#include<stddef.h>
#include "stack_list.h"

static void _set_result_(StackResult *res, uint32_t data, uint32_t status){
    res->data = data;
    res->status = status;
}

static Node* _new_node_(uint32_t data){
    Node *node = (Node*) malloc (sizeof(Node));

    if(node == NULL) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}


Stack *stack_new(uint32_t size, StackResult *res){
    if(res == NULL) return NULL;

    size = size > 0 && size < MAX_DEPTH ? size : MAX_DEPTH;

    Stack *stack = (Stack*) malloc (sizeof(Stack));

    if(stack == NULL) return NULL;

    stack->size = size;
    stack->count = 0;
    stack->top = NULL;

    res->data = RESULT_INVALID;
    res->status = STACK_OK;

    return stack;
}


uint32_t stack_is_full(const Stack *stack){
    if(stack == NULL) return 0;
    return stack->count >= stack->size;
}

uint32_t stack_is_empty(const Stack *stack){
    if(stack == NULL) return 1;
    return stack->count == 0;
}


Stack *stack_push(Stack *stack, uint32_t data, StackResult *res){
    if(stack == NULL|| res == NULL) return NULL;

    if(stack->count >= stack->size){
        _set_result_(res, data, STACK_FULL);
        return stack;
    }

    Node *new_node = _new_node_(data);

    if(new_node == NULL){
        _set_result_(res, data, RESULT_INVALID);
        return stack;
    }

    new_node->next = stack->top;
    stack->top = new_node;
    ++stack->count;
    _set_result_(res, data, STACK_OK);

    return stack;
}

Stack *stack_pop(Stack *stack, StackResult *res){
    if(stack == NULL || res == NULL) return NULL;

    if(stack->count == 0){
        _set_result_(res, RESULT_INVALID, STACK_EMPTY);
        return stack;
    }

    Node *temp = stack->top;
    stack->top = stack->top->next;
    --stack->count;
    _set_result_(res, temp->data, STACK_OK);
    free(temp);

    return stack;
}

Stack *stack_peek(const Stack *stack, StackResult *res){
    if(stack == NULL || res == NULL) return stack;

    if(stack->top == NULL){
        _set_result_(res, RESULT_INVALID, STACK_EMPTY);
        return stack;
    }

    _set_result_(res, stack->top->data, STACK_OK);
    return stack;
}


Stack *stack_clear(Stack *stack){
    if(stack == NULL) return NULL;

    Node *current = stack->top;

    while(current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    stack->count = 0;
    stack->top = NULL;

    return stack;
}


void stack_display(const Stack *stack, StackResult *res){
    if (stack == NULL || res == NULL) return;

    printf("\nSTACK_LIST {");
    printf("\n\tsize: %d", stack->size);
    printf("\n\tcount: %d", stack->count);
    printf("\n\tSTACK {");
    if(stack->count == 0){
        printf("\n\t\tEMPTY");
    }
    Node *current = stack->top;
    uint32_t count = stack->count;
    for(; current != NULL; current = current->next){
        printf("\n\t\tstack[%02d]: %2d", count--, current->data);
        if(current == stack->top){
            printf("  <-- STACK TOP");
        }
    }
    printf("\n\t}");
    printf("\n\tSTACK_RESULT {");
    printf("\n\t\tdata: %d", res->data);
    printf("\n\t\tstatus: %d", res->status);
    printf("\n\t}");
    printf("\n}");
}
