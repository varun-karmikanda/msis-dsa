#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

void test_heap(){
    int32_t data[] = {0, 10, 20, 30, 45, 50, 67, 95};
    int32_t len = 7;
    Heap heap = heap_new(data, len);

    heap_display(&heap);

    assert(heap_get_max(&heap) == 95);


    heap_extract_max(&heap);
    heap_insert(&heap, 77);
    heap_display(&heap);

    assert(heap_size(&heap) == 7);

    heap_display(&heap);

    heap_sort(&heap);
    heap_display(&heap);


    heap_delete(&heap);
    heap_display(&heap);


}

int main()
{
    test_heap();
    return 0;
}
