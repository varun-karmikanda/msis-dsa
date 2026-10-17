#include<stdint.h>
#include "searching.h"

int32_t linear_search(const uint32_t arr[], uint32_t n, uint32_t key){
    for(int32_t i = 0; i < n; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int32_t binary_search_iterative(const uint32_t arr[], uint32_t n, uint32_t key){
    int32_t low = 0;
    int32_t high = n - 1;

    while(low <= high){
        int32_t mid = low + (high - low) / 2;

        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

static int32_t _binary_search_(const uint32_t arr[], uint32_t key, int32_t low, int32_t high){
    if(low > high)
        return -1;

    int32_t mid = low + (high - low) / 2;

    if(arr[mid] == key)
        return mid;
    else if(key < arr[mid])
        _binary_search_(arr, key, low, mid - 1);
    else
        _binary_search_(arr, key, mid + 1, high);
}

int32_t binary_search_recursive(const uint32_t arr[], uint32_t n, uint32_t key){
    int32_t low = 0;
    int32_t high = n - 1;

    _binary_search_(arr, key, low, high);
}
