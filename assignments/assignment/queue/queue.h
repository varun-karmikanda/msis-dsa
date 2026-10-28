#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdint.h>
#include "stack.h"

#define RESULT_INVALID 0
#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 4

#define MAX_CAPACITY 32

typedef struct _queue_ Queue;
typedef struct _queue_result_ QueueResult;

struct _queue_ {
    Stack *stack;
    Stack *temp_stack;
    uint32_t capacity;
};

struct _queue_result_ {
    uint32_t data;
    uint32_t status;
};

Queue *queue_new(uint32_t capacity, QueueResult * res);

Queue *queue_enqueue(Queue *queue, uint32_t data, QueueResult * res);

Queue *queue_dequeue(Queue *queue, QueueResult * res);

Queue *queue_peek(const Queue *queue, QueueResult *res);

void queue_display(const Queue *queue);

#endif // QUEUE_H_INCLUDED
