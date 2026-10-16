#include <stdint.h>
#include<assert.h>
#include<stddef.h>
#include "heap.h"

static void _swap_(int32_t *a, int32_t *b){
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

static void _heapify_(int32_t data[], uint32_t len, uint32_t parent){
    assert(len > 0 && len <= MAX_HEAP_SIZE && parent > 0);

    uint32_t child = 2 * parent;

    while(child <= len){
        if(child + 1 <= len){
            if(data[child + 1] > data[child]){
                ++child;
            }
        }
        if(data[parent] >= data[child])
            break;
        _swap_(&data[parent], &data[child]);
        parent = child;
        child = 2 * parent;
    }
}


Heap heap_new(int32_t data[], uint32_t len){
    assert(len > 0 && len <= MAX_HEAP_SIZE);

    uint32_t i;
    Heap heap;

    for(i = len / 2; i > 0; i--){
        _heapify_(data, len, i);
    }

    heap.size = len;
    memcpy(heap.data, data, (len + 1) * sizeof(int32_t));


    return heap;
}

void heap_delete(Heap *heap){
    memset(heap->data, 0, MAX_HEAP_SIZE * sizeof(int32_t));
    heap->size = 0;
}

Heap *heap_sort(Heap *heap){
    assert(heap ->size > 0 && heap ->size < MAX_HEAP_SIZE);

    int32_t len = heap ->size;

    for(; len > 1; len --){
        _swap_(&heap ->data[1], &heap ->data[len]);
        _heapify_(heap ->data, len - 1, 1);
    }

    return heap;
}

Heap *heap_insert(Heap *heap, int32_t key){
    assert(heap ->size > 0 && heap ->size < MAX_HEAP_SIZE);

    uint32_t i;
    ++heap ->size;
    i = heap ->size;

    while(i > 1 && heap ->data[i / 2] < key){
        heap ->data[i] = heap ->data[i / 2];
        i = i / 2;
    }
    heap ->data[i] = key;

    return key;
}

int32_t heap_get_max(Heap *heap){
    assert(heap ->size > 0 && heap ->size < MAX_HEAP_SIZE);

    return heap ->data[1];
}

int32_t heap_extract_max(Heap *heap){
    assert(heap ->size > 0 && heap ->size < MAX_HEAP_SIZE);

    uint32_t max = heap ->data[1];

    heap ->data[1] = heap ->data[heap ->size];
    --heap ->size;
    _heapify_(heap -> data, heap ->size, 1);

    return max;

}

uint32_t heap_size(Heap *heap){
    assert(heap ->size > 0 && heap ->size < MAX_HEAP_SIZE);
    return heap ->size;
}

void heap_display(Heap *heap){
    printf("\n[");
    for(int32_t i = 1; i <= heap-> size; i++){
        printf(" %d ", heap ->data[i]);
        if(i != heap ->size){
            printf("|");
        }
    }
    printf("]");
}
