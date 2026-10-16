#include<stdint.h>
#include "sorting.h"

static void _swap_(uint32_t *a, uint32_t *b){
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
}


void bubble_sort(uint32_t arr[], uint32_t n){
    for(uint32_t i = n - 1; i > 0; i--){
        uint32_t swapped = 0;
        for(uint32_t j = 0; j < i; j++){
            if(arr[j] > arr[j + 1]){
                _swap_(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}


void selection_sort(uint32_t arr[], uint32_t n){
    for(uint32_t i = 0; i < n - 1; i++){
        uint32_t min = i;
        for(uint32_t j = i + 1; j < n; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i) _swap_(&arr[i], &arr[min]);
    }
}


void insertion_sort(uint32_t arr[], uint32_t n){
    for(uint32_t i = 1; i < n; i++){
        uint32_t key = arr[i];
        int32_t j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


static void _merge_(uint32_t arr[], int32_t low, int32_t mid, int32_t high){
    int temp[high + 1];
    int left = low;
    int right = mid + 1;
    int i = low;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right])
            temp[i++] = arr[left++];
        else
            temp[i++] = arr[right++];
    }

    while(left <= mid){
        temp[i++] = arr[left++];
    }

    while(right <= high){
        temp[i++] = arr[right++];
    }

    for(int32_t k = low; k <= high; k++)
        arr[k] = temp[k];
}

static void _merge_sort_(uint32_t arr[], int32_t low, int32_t high){
    if(low >= high) return;
    uint32_t mid = low + (high - low) / 2;
    _merge_sort_(arr, low, mid);
    _merge_sort_(arr, mid + 1, high);
    _merge_(arr, low, mid, high);
}

void merge_sort(uint32_t arr[], uint32_t n){
    if(n <= 1) return;
    _merge_sort_(arr, 0, n - 1);
}


static uint32_t _partition_(uint32_t arr[], int32_t low, int32_t high){
    uint32_t pivot = arr[low];
    int32_t i = low + 1;
    int32_t j = high;

    while(1){
        while(i <= high && arr[i] <= pivot)
            i++;

        while(j >= low && arr[j] > pivot)
            j--;

        if(i >= j) break;

        _swap_(&arr[i], &arr[j]);
    }
    _swap_(&arr[low], &arr[j]);

    return j;
}

static void _quick_sort_(uint32_t arr[], int32_t low, int32_t high){
    if(low < high){
        int p = _partition_(arr, low, high);
        _quick_sort_(arr, low, p - 1);
        _quick_sort_(arr, p + 1, high);
    }
}

void quick_sort(uint32_t arr[], uint32_t n){
    if(n <= 1) return;
    _quick_sort_(arr, 0, n - 1);
}
