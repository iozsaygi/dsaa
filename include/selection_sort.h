// https://en.wikipedia.org/wiki/Selection_sort

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <stddef.h>

void ss_swap(int* first, int* second);
void ss_execute(int* data, size_t length);

// ------------------------- TESTS -------------------------
void ss_test_0();
// ---------------------------------------------------------

#endif// !SELECTION_SORT_H