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

// Adds given value at the given index by shifting existing elements.
void da_insertAt(da_t* da, size_t index, int value);

// Updates the existing value of dynamic array with the given new 'value'.
void da_setAt(da_t* da, size_t index, int value);

// Removes last element from dynamic array.
void da_remove(da_t* da);

// Removes an element at given index from dynamic array.
void da_removeAt(da_t* da, size_t index);

// Prints the value of dynamic array.
void da_log(const da_t* da);

// Clears allocated resources for dynamic array.
void da_free(da_t* da);

// ------------------------- TESTS -------------------------
void da_test_0();
void da_test_1();
void da_test_2();
// ---------------------------------------------------------

#endif// !DYNAMIC_ARRAY_H