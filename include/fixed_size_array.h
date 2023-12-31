#ifndef FIXED_SIZE_ARRAY_H
#define FIXED_SIZE_ARRAY_H

#include <stddef.h>

// Represents basic array with a fixed size. (It's size will not change at runtime)
typedef struct {
    int* data;
    size_t length;
} fsa_t;

// Allocates resources for the fixed size array instance.
fsa_t* fsa_allocate(size_t length);

// Returns the value at given index.
int fsa_getAt(const fsa_t* fsa, size_t index);

// Sets the value at specific index to given value.
void fsa_setAt(const fsa_t* fsa, size_t index, int value);

// Updates the every element in the array with given value.
void fsa_setAll(const fsa_t* fsa, int value);

// Copies source fixed size array instance to destination instance.
void fsa_copy(const fsa_t* src, const fsa_t* dst);

// Logs every element of fixed size array instance.
void fsa_log(const fsa_t* fsa);

// Clears resources for fixed size array instance.
void fsa_free(fsa_t* fsa);

// ------------------------- TESTS -------------------------
void fsa_test_0();
void fsa_test_1();
void fsa_test_2();
// ---------------------------------------------------------

#endif// !FIXED_SIZE_ARRAY_H