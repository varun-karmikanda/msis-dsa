#include<stdio.h>
#include<stdint.h>
#include "queue.h"

static void _set_queue_result_(QueueResult *queue_result, uint32_t data, uint32_t status){
    queue_result -> data = data;
    queue_result -> status = status;
}

Queue queue_new(uint32_t size){
    size = (size > 0 && size <= MAX_QUEUE_LEN) ? size : MAX_QUEUE_LEN;

    Queue queue = { size, /*count*/0, /*head*/0, /*tail*/0, {0}};
    return queue;
}

Queue *queue_add(Queue *queue, uint32_t data, QueueResult *queue_result){
    if(queue -> count < queue -> size){
        queue -> values[queue -> tail] = data;
        queue -> tail = (queue -> tail + 1) % queue -> size;
        ++queue -> count;
        _set_queue_result_(queue_result, data, QUEUE_OK);
    } else {
        _set_queue_result_(queue_result, RESULT_INVALID, QUEUE_FULL);
    }
    return queue;
}

Queue *queue_remove(Queue *queue, QueueResult *queue_result){
    if(queue -> count > 0){
        _set_queue_result_(queue_result, queue -> values[queue -> head], QUEUE_OK);
        queue -> head = (queue -> head + 1) % queue -> size;
        --queue -> count;
    } else {
        _set_queue_result_(queue_result, RESULT_INVALID, QUEUE_EMPTY);
    }
    return queue;
}

Queue *queue_peek(const Queue *queue, QueueResult *queue_result){
    if(queue -> count > 0){
        _set_queue_result_(queue_result, queue -> values[queue -> head], QUEUE_OK);
    } else {
        _set_queue_result_(queue_result, RESULT_INVALID, QUEUE_EMPTY);
    }
    return queue;
}

uint32_t queue_isFull(const Queue *queue){
    return queue -> count == queue -> size;
}

uint32_t queue_isEmpty(const Queue *queue){
    return (queue -> count == 0 && queue -> head == queue -> tail);
}

uint32_t queue_length(const Queue *queue){
    return queue -> count;
}

void queue_display(const Queue *queue, QueueResult *queueResult){
    printf("\nQUEUE {");
    printf("\n\tsize  : %d", queue -> size);
    printf("\n\tcount : %d", queue -> count);
    printf("\n\thead  : %d", queue -> head);
    printf("\n\ttail  : %d", queue -> tail);
    printf("\n\tqueue : ");
    for(int i = 0; i < queue -> size; i++){
        if(i == 0){
            printf("| ");
        }
        uint32_t index = (queue -> head + i) % MAX_QUEUE_LEN;
        if(i < queue -> count){
            printf("%d | ", queue -> values[index]);
        } else {
            printf("0 | ");
        }
    }
    printf("\n\tQUEUE_RESULT {");
    printf("\n\t\tdata   : %d", queueResult -> data);
    printf("\n\t\tstatus : %d", queueResult -> status);
    printf("\n\t}");
    printf("\n}");
}

