#ifndef SEARCHING_H_INCLUDED
#define SEARCHING_H_INCLUDED

#include<stdint.h>

int32_t linear_search(const uint32_t arr[], uint32_t n, uint32_t key);
int32_t binary_search_iterative(const uint32_t arr[], uint32_t n, uint32_t key);
int32_t binary_search_recursive(const uint32_t arr[], uint32_t n, uint32_t key);

#endif // SEARCHING_H_INCLUDED
