#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <stdint.h>

void bubble_sort(uint32_t arr[], uint32_t n);
void selection_sort(uint32_t arr[], uint32_t n);
void insertion_sort(uint32_t arr[], uint32_t n);
void merge_sort(uint32_t arr[], uint32_t n);
void quick_sort(uint32_t arr[], uint32_t n);

#endif // SORTING_H_INCLUDED
