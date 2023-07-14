#include<stdlib.h>
#include<memory.h>
#include "wildsort.h"

static void _sort_insertion(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
} 

static void _sort_bubble(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 1; j < size; j++) {
            if(arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bad_sort(int *arr) {
    // arr should have one extra element for size of array
    int size = (int)(*arr);
    int *numbers = malloc(sizeof(int)*(size));
    memcpy(numbers, &arr[1], sizeof(int) * size);

    if(size > 101) {
        // Do quicksort
    }else if(size > 51) {
        // Do insertion sort
        _sort_insertion(numbers, size);
    } else {
        // Do bubble sort
        _sort_bubble(numbers, size);
    }

    memcpy(&arr[1], numbers, sizeof(int) * size);
    free(numbers);
}
