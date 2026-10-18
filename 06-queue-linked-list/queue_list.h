#ifndef QUEUE_LIST_H_INCLUDED
#define QUEUE_LIST_H_INCLUDED

#include<stdint.h>

#define MAX_QUEUE_LEN 32

#define RESULT_INVALID 0
#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 4

typedef struct _node_ Node;
typedef struct _queue_ Queue;
typedef struct _queue_result_ QueueResult;

struct _node_ {
    uint32_t data;
    Node *next;
};

struct _queue_ {
    uint32_t size;
    uint32_t count;
    Node *head;
    Node *tail;
};

struct _queue_result_ {
    uint32_t data;
    uint32_t status;
};

Queue *queue_new(uint32_t size, QueueResult *res);

uint32_t queue_is_full(const Queue *queue);
uint32_t queue_is_empty(const Queue *queue);

Queue *queue_enqueue(Queue *queue, uint32_t data, QueueResult *res);
Queue *queue_dequeue(Queue *queue, QueueResult *res);
Queue *queue_peek(const Queue *queue, QueueResult *res);

Queue *queue_clear(Queue *queue);

void queue_display(const Queue *queue, QueueResult *res);

#endif // QUEUE_LIST_H_INCLUDED
