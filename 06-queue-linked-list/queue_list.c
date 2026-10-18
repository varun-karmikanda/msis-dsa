#include<stdint.h>
#include<stddef.h>
#include<stdio.h>
#include "queue_list.h"

static void _set_result_(QueueResult *res, uint32_t data, uint32_t status){
    res->data = data;
    res->status = status;
}

static Node *_new_node_(uint32_t data){
    Node *node = (Node*) malloc (sizeof(Node));

    if(node == NULL) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

Queue *queue_new(uint32_t size, QueueResult *res){
    if(res ==  NULL) return NULL;

    size = size > 0 && size < MAX_QUEUE_LEN ? size : MAX_QUEUE_LEN;

    Queue *queue = (Queue*) malloc (sizeof(Queue));

    if(queue == NULL) return NULL;

    queue->size = size;
    queue->count = 0;
    queue->head = NULL;
    queue->tail = NULL;

    res->data = RESULT_INVALID;
    res->status = QUEUE_OK;

    return queue;
}


uint32_t queue_is_full(const Queue *queue){
    if(queue == NULL) return 0;
    return queue->count == queue->size;
}

uint32_t queue_is_empty(const Queue *queue){
    if(queue == NULL) return 1;
    return queue->count == 0;
}


Queue *queue_enqueue(Queue *queue, uint32_t data, QueueResult *res){
    if(queue == NULL || res == NULL) return NULL;

    if(queue->count == queue->size){
        _set_result_(res, data, QUEUE_FULL);
        return queue;
    }

    Node *new_node = _new_node_(data);

    if(new_node == NULL){
        _set_result_(res, data, RESULT_INVALID);
        return queue;
    }

    if(queue->head == NULL)
        queue->head = new_node;
    else
        queue->tail->next = new_node;
    queue->tail = new_node;
    ++queue->count;
    _set_result_(res, data, QUEUE_OK);

    return queue;
}

Queue *queue_dequeue(Queue *queue, QueueResult *res){
    if(queue == NULL || res == NULL) return NULL;

    if(queue->count == 0){
        _set_result_(res, RESULT_INVALID, QUEUE_EMPTY);
        return queue;
    }

    Node *temp = queue->head;
    queue->head = queue->head->next;
    if(queue->head == NULL){
        queue->tail = NULL;
    }
    --queue->count;
    _set_result_(res, temp->data, QUEUE_OK);
    free(temp);

    return queue;
}

Queue *queue_peek(const Queue *queue);


Queue *queue_clear(Queue queue);


void queue_display(const Queue *queue, QueueResult *res){
    printf("\nQUEUE_LIST {");
    printf("\n\tsize: %d", queue->size);
    printf("\n\tcount: %d", queue->count);
    printf("\n\thead: ");
    queue->head != NULL ? printf("%d", queue->head->data) : printf("NULL");
    printf("\n\ttail: ");
    queue->tail != NULL ? printf("%d", queue->tail->data) : printf("NULL");
    printf("\n\tqueue: {");
    if(queue->head == NULL){
        printf("\n\t\tEMPTY");
    }
    for(Node *current = queue->head; current != NULL; current = current->next){
        printf("\n\t\t| %d |", current->data);
        if(current == queue->head)
            printf(" <-- HEAD");
        else if(current == queue->tail)
            printf(" <-- TAIL");
    }
    printf("\n\t}");
    printf("\n\tQUEUE_RESULT {");
    printf("\n\t\tdata: %d", res->data);
    printf("\n\t\tstatus: %d", res->status);
    printf("\n\t}");
    printf("\n}\n");
}
