#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include<stdint.h>

#define MAX_HEAP_SIZE 16

typedef struct _heap_ Heap;

struct _heap_ {
    uint32_t size;
    int32_t data[MAX_HEAP_SIZE];
};

Heap heap_new(int32_t data[], uint32_t len);
void heap_delete(Heap *heap);

Heap *heap_sort(Heap *heap);

Heap *heap_insert(Heap *heap, int32_t key);

int32_t heap_get_max(Heap *heap);
int32_t heap_extract_max(Heap *heap);

uint32_t heap_size(Heap *heap);

void heap_display(Heap *heap);

#endif // HEAP_H_INCLUDED
