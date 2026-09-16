#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "queue.h"

void test_queue(){
    Queue queue = queue_new(10);
    QueueResult queue_result = {-1, RESULT_INVALID};
    queue_display(&queue, &queue_result);

    queue_add(&queue, 67, &queue_result);
    assert(queue_result.data == 67);
    assert(queue_result.status== QUEUE_OK);
    queue_display(&queue, &queue_result);

    queue_peek(&queue, &queue_result);
    assert(queue_result.data == 67);
    assert(queue_result.status== QUEUE_OK);
    queue_display(&queue, &queue_result);

    queue_add(&queue, 51, &queue_result);

    queue_add(&queue, 63, &queue_result);
    assert(queue_result.data == 63);
    assert(queue_result.status== QUEUE_OK);

    assert(queue_length(&queue) == 3);

    queue_add(&queue, 95, &queue_result);
    queue_add(&queue, 44, &queue_result);
    queue_add(&queue, 77, &queue_result);
    queue_add(&queue, 32, &queue_result);
    queue_add(&queue, 21, &queue_result);
    queue_add(&queue, 12, &queue_result);

    queue_add(&queue, 78, &queue_result);
    assert(queue_result.data == 78);
    assert(queue_result.status== QUEUE_OK);

    assert(queue_length(&queue) == 10);

    queue_display(&queue, &queue_result);

    assert(queue_isFull(&queue));

    queue_add(&queue, 99, &queue_result);
    assert(queue_result.data == RESULT_INVALID);
    assert(queue_result.status== QUEUE_FULL);
    queue_display(&queue, &queue_result);

    queue_remove(&queue, &queue_result);
    assert(queue_result.data == 67);
    assert(queue_result.status== QUEUE_OK);

    queue_remove(&queue, &queue_result);
    queue_remove(&queue, &queue_result);
    queue_display(&queue, &queue_result);

    queue_remove(&queue, &queue_result);
    queue_remove(&queue, &queue_result);
    queue_remove(&queue, &queue_result);
    queue_remove(&queue, &queue_result);
    queue_remove(&queue, &queue_result);
    queue_remove(&queue, &queue_result);
    queue_remove(&queue, &queue_result);
    assert(queue_result.data == 78);
    assert(queue_result.status== QUEUE_OK);
    queue_display(&queue, &queue_result);

    assert(queue_isEmpty(&queue));

    assert(queue_length(&queue) == 0);

    queue_remove(&queue, &queue_result);
    assert(queue_result.data == RESULT_INVALID);
    assert(queue_result.status== QUEUE_EMPTY);
}

int main()
{
    test_queue();
    return 0;
}
