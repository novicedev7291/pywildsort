#ifndef _WILDSORT_H_
#define _WILDSORT_H_

// This returns the pointer to sorted array.
// The function creates the new array instead of using the passed as 
// function argument, hence you must deallocate the memory for the same.
// The function will not behave as intended if above is not followed.
//
// Also, note that the passed array should have the first element as 
// size of array.
// 
// Usage Example:
// int[] arr = { 1, 5, 3, 21, 32 };
// int* sorted = imperfect_sort(arr);
void bad_sort(int*);

#endif
