#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include<stdint.h>

#define MAX_QUEUE_LEN 32

#define RESULT_INVALID 0
#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 4

struct _queue_ {
    uint32_t size;
    uint32_t count;
    uint32_t head;
    uint32_t tail;
    int32_t values[MAX_QUEUE_LEN];
};

typedef struct _queue_ Queue;

struct _queue_result_ {
    uint32_t data;
    uint32_t status;
};

typedef struct _queue_result_ QueueResult;

Queue queue_new(uint32_t size);

Queue *queue_add(Queue *queue, uint32_t data, QueueResult *queueResult);
Queue *queue_remove(Queue *queue, QueueResult *queueResult);
Queue *queue_peek(const Queue *queue, QueueResult *queueResult);

uint32_t queue_isFull(const Queue * queue);
uint32_t queue_isEmpty(const Queue *queue);

uint32_t queue_length(const Queue *queue);

void queue_display(const Queue *queue, QueueResult *queueResult);

#endif // QUEUE_H_INCLUDED
