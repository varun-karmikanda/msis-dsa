#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<stdio.h>
#include "sorting.h"

void test_sorting(){
    uint32_t arr[] = {67, 63, 51, 95, 44, 78};
//    bubble_sort(&arr, 6);
//    selection_sort(&arr, 6);
//    insertion_sort(&arr, 6);
//    merge_sort(&arr, 6);
    quick_sort(&arr, 6);

    printf("%d", arr[3]);

    assert(arr[0] == 44);
    assert(arr[1] == 51);
    assert(arr[2] == 63);
    assert(arr[3] == 67);
    assert(arr[4] == 78);
    assert(arr[5] == 95);
}

int main()
{
    test_sorting();
    return 0;
}
