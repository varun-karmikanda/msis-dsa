#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue_list.h"

void test_queue_list(){
    QueueResult res;

    Queue *queue = queue_new(7, &res);

    queue_display(queue, &res);

    assert(queue_is_empty(queue) == 1);
    assert(queue_is_full(queue) == 0);

    queue_enqueue(queue, 67, &res);
    queue_enqueue(queue, 51, &res);
    queue_enqueue(queue, 63, &res);
    queue_enqueue(queue, 95, &res);
    queue_display(queue, &res);

    assert(queue->count == 4);

    queue_enqueue(queue, 44, &res);
    queue_enqueue(queue, 18, &res);
    queue_enqueue(queue, 77, &res);
    queue_enqueue(queue, 38, &res);
    queue_display(queue, &res);

    assert(queue_is_full(queue) == 1);
    assert(queue_is_empty(queue) == 0);

    queue_dequeue(queue, &res);
    assert(res.data == 67);
    queue_display(queue, &res);



    queue_dequeue(queue, &res);
    queue_dequeue(queue, &res);
    queue_dequeue(queue, &res);
    queue_dequeue(queue, &res);
    queue_dequeue(queue, &res);
    queue_dequeue(queue, &res);

    assert(queue_is_empty(queue) == 1);

    queue_display(queue, &res);
}

int main()
{
    test_queue_list();
    return 0;
}
