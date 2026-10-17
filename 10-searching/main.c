#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searching.h"

static void _print_array_(uint32_t arr[], uint32_t n){
    for(int32_t i = 0; i < n; i++){
        printf("%d", arr[i]);
        if(i != n - 1){
            printf(", ");
        }
    }
}

static void _display_search_details_(
    const char *search_name,
    uint32_t arr[],
    uint32_t n,
    uint32_t key,
    int32_t (*search_fn)(const uint32_t arr[], uint32_t n, uint32_t key)
){
    printf("\n%s {", search_name);
    printf("\n\tarray: [");
    _print_array_(arr, n);
    printf("]");
    printf("\n\tkey: %d", key);
    printf("\n\telement_position: %d", search_fn(arr, n, key));
    printf("\n}\n");
}

void test_linear_search(uint32_t arr[], uint32_t n, uint32_t key){
    _display_search_details_("LINEAR SEARCH", arr, n, key, linear_search);
}

void test_binary_search_iterative(uint32_t arr[], uint32_t n, uint32_t key){
    _display_search_details_("BINARY SEARCH (ITERATIVE)", arr, n, key, binary_search_iterative);
}

void test_binary_search_recursive(uint32_t arr[], uint32_t n, uint32_t key){
    _display_search_details_("BINARY SEARCH (RECURSIVE)", arr, n, key, binary_search_recursive);
}

int main()
{
    uint32_t arr[] = {6, 7, 18, 21, 36, 45, 51, 63, 67, 73, 86, 95};
    uint32_t n = sizeof(arr) / sizeof(arr[0]);
    uint32_t key = 67;

    uint32_t arr_linear[n];
    uint32_t arr_binary_iterative[n];
    uint32_t arr_binary_recursive[n];

    memcpy(arr_linear, arr, sizeof(arr));
    memcpy(arr_binary_iterative, arr, sizeof(arr));
    memcpy(arr_binary_recursive, arr, sizeof(arr));

    test_linear_search(arr_linear, n, key = 67);

    test_binary_search_iterative(arr_binary_iterative, n, key = 95);

    test_binary_search_recursive(arr_binary_recursive, n, key = 51);

    return 0;
}
