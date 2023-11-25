// https://en.wikipedia.org/wiki/Binary_search_algorithm

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>

#define INVALID_INDEX (-1)

size_t bs_findIndexOf(const int* data, size_t length, int target);

// ------------------------- TESTS -------------------------
void bs_test_0();
// ---------------------------------------------------------

#endif//! BINARY_SEARCH_H