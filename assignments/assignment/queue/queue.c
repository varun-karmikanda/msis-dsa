#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include "stack.h"
#include "queue.h"

static void _set_result_(QueueResult *res, uint32_t data, uint32_t status){
    res->data = data;
    res->status = status;
}

Queue *queue_new(uint32_t capacity, QueueResult * res){
    capacity = capacity > 0 && capacity <= 32 ? capacity: MAX_CAPACITY;

    Queue *queue = (Queue*) malloc (sizeof(Queue));
    if(queue == NULL) return NULL;

    queue->stack = (Stack*) malloc (sizeof(Stack));
    queue->temp_stack = (Stack*) malloc (sizeof(Stack));

    queue->capacity = capacity;
    *queue->stack = stack_new(capacity);
    *queue->temp_stack = stack_new(capacity);

    res->data = RESULT_INVALID;
    res->status = QUEUE_OK;

    return queue;
}

Queue *queue_enqueue(Queue *queue, uint32_t data, QueueResult * res){
    if(!stack_is_full(queue->stack)){
        while(queue->stack->top != -1){
            stack_push(queue->temp_stack, queue->stack->stk[queue->stack->top]);
            stack_pop(queue->stack);
        }
        stack_push(queue->stack, data);
        while(queue->temp_stack->top != -1){
            stack_push(queue->stack, queue->temp_stack->stk[queue->temp_stack->top]);
            stack_pop(queue->temp_stack);
        }
        _set_result_(res, data, QUEUE_OK);
    } else {
        _set_result_(res, RESULT_INVALID, QUEUE_FULL);
    }
    return queue;
}

Queue *queue_dequeue(Queue *queue, QueueResult * res){

    if(!stack_is_empty(queue->stack)){
        _set_result_(res, queue->stack->stk[queue->stack->top], QUEUE_OK);
        --queue->stack->top;
    } else {
        _set_result_(res, RESULT_INVALID, QUEUE_EMPTY);
    }
    return queue;
}

Queue *queue_peek(const Queue *queue, QueueResult *res){
    if(!stack_is_empty(queue->stack))
        _set_result_(res, queue->stack->stk[queue->stack->top], STACK_OK);
    else
        _set_result_(res, RESULT_INVALID, STACK_EMPTY);

    return queue;
}

void queue_display(const Queue *queue)
{
    if (queue == NULL)
    {
        printf("\nQUEUE { NULL }\n");
        return;
    }

    printf("\nQUEUE {");
    printf("\n\tcapacity : %u", queue->capacity);

    printf("\n\tstack :");
    stack_display(queue->stack);

    printf("\n\ttemp_stack :");
    stack_display(queue->temp_stack);

    printf("\n}");
}
