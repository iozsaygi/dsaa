// https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct {
    int* data;
    size_t length;
    size_t capacity;
} stck_t;

// Allocates required resources for stack.
stck_t* stack_allocate();

// Adds given value at the end of stack.
void stack_push(stck_t* stack, int value);

// Removes and returns last element of stack.
int stack_pop(stck_t* stack);

// Prints values of stack members.
void stack_log(const stck_t* stack);

// Clears allocated resources for stack.
void stack_free(stck_t* stack);

// ------------------------- TESTS -------------------------
void stack_test_0();
// ---------------------------------------------------------

#endif// !STACK_H