#include<stdio.h>
#include<criterion/criterion.h>
#include<criterion/new/assert.h>
#include "../src/wildsort.h"

#define PRINT_ARR(arr, size) for(int i = 0; i < size; i++) printf("%d, ", arr[i]);

// This function generates two arrays i.e. original array
// with shuffled values between start & end and expected
// array after sort.
static int** generate_test_case(int start, int end) {
    if(start >= end) {
        fprintf(stderr, "Failed to generate test case as start >= end");
        return NULL;
    }
    srand(time(0));

    int size = (end - start) + 2;

    int* expected = malloc(sizeof(int) * (size - 1));
    int num = start;
    for(int i = 0; i < size - 1; i++) {
        expected[i] = num;
        num += 1;
    }
    
    int* arr = malloc(sizeof(int) * size);
    arr[0] = size - 1;
    for(int i = 1; i < size; i++) {
        arr[i] = expected[i - 1];
    }

    // Randominze the array
    for(int i = 1; i < size; i++) {
        int p = (rand() % (size - 1)) + 1;  
        int q = (rand() % (size - 1)) + 1;
        
        //printf("p = %d, q = %d\n", p, q);
        if (p != q) {
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }

    int** test_case = malloc(sizeof(int*) * 2);
    test_case[0] = arr;
    test_case[1] = expected;

    return test_case;
}

Test(wildsort_test, bubble_sort) {
    const int size = 7 - 2 + 1;

    int** test = generate_test_case(2, 7);

    bad_sort(test[0]);

    cr_assert(eq(int[size], &test[0][1], test[1]));

    free(test);
}

Test(wildsort_test, insertion_sort) {
    const int size = 214 - 123 + 1;

    int** test = generate_test_case(123, 214);

    bad_sort(test[0]);

    cr_assert(eq(int[size], &test[0][1], test[1]));

    free(test);
}
