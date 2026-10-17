#include<stdint.h>
#include<stddef.h>
#include "queue_list.h"

static void _set_result_(QueueResult *res, uint32_t data, uint32_t status){
    res->data = data;
    res->status = status;
}

static Node *new_node(uint32_t data){
    Node *node = (Node*) malloc (sizeof(Node));

    if(node == NULL) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

Queue *queue_new(uint32_t size, QueueResult *res);

uint32_t queue_is_full(const Queue *queue);
uint32_t queue_is_empty(const Queue *queue);

Queue *queue_enqueue(Queue *queue, uint32_t data, QueueResult *res);
Queue *queue_dequeue(Queue *queue, QueueResult *res);
Queue *queue_peek(const Queue *queue);

Queue *queue_clear(Queue queue);

void queue_display(const Queue *queue, QueueResult *res);
