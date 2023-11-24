// https://en.wikipedia.org/wiki/Linear_search

#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <stddef.h>

#define INVALID_INDEX (-1)

size_t ls_findIndexOf(const int* data, size_t length, int target);

// ------------------------- TESTS -------------------------
void ls_test_0();
// ---------------------------------------------------------

#endif// !LINEAR_SEARCH_H