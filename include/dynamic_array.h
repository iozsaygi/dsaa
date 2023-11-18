// https://en.wikipedia.org/wiki/Dynamic_array

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct {
    int* data;
    size_t length;
    size_t capacity;
} da_t;

// Allocates initial required resources for dynamic array.
da_t* da_allocate(size_t length);

// Adds given value at the end of dynamic array.
void da_append(da_t* da, int value);

// Prints the value of dynamic array.
void da_log(const da_t* da);

// Clears allocated resources for dynamic array.
void da_free(da_t* da);

// ------------------------- TESTS -------------------------
void da_test_0();
// ---------------------------------------------------------

#endif// !DYNAMIC_ARRAY_H