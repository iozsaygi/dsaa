// https://en.wikipedia.org/wiki/Bubble_sort

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdlib.h>

void bs_swap(int* first, int* second);
void bs_execute(int* array, size_t length);

// ------------------------- TESTS -------------------------
void bsort_test_0();
// ---------------------------------------------------------

#endif// !BUBBLE_SORT_H