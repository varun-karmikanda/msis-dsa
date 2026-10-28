#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void test_queue(){
    QueueResult res;
    Queue *queue = queue_new(10, &res);

    assert(queue->capacity == 10);

    queue_enqueue(queue, 67, &res);
    queue_enqueue(queue, 10, &res);
    queue_enqueue(queue, 63, &res);
    queue_enqueue(queue, 95, &res);
    queue_enqueue(queue, 51, &res);
    queue_enqueue(queue, 33, &res);
    queue_enqueue(queue, 48, &res);
    queue_enqueue(queue, 88, &res);
    queue_enqueue(queue, 11, &res);
    queue_enqueue(queue, 18, &res);
    queue_enqueue(queue, 64, &res);

    queue_dequeue(queue, &res);
    assert(res.data == 67);

    queue_display(queue);
    queue_enqueue(queue, 100, &res);
    queue_display(queue);

    queue_peek(queue, &res);
    assert(res.data == 10);
}

int main()
{
    test_queue();
    return 0;
}
