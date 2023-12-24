#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void quickSort_swap(int* first, int* second);
int quickSort_partition(int* array, int left, int right);
void quickSort_execute(int* array, int left, int right);

// ------------------------- TESTS -------------------------
void quick_sort_test_0();
// ---------------------------------------------------------

#endif//! QUICK_SORT_H