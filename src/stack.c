#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack_t* stack_allocate() {
    stack_t* stack = (stack_t*) malloc(sizeof(stack_t));
    assert(stack != NULL);

    stack->length = 0;
    stack->capacity = 2;

    stack->data = (int*) malloc(sizeof(int) * stack->capacity);
    assert(stack->data != NULL);

    return stack;
}

void stack_push(stack_t* stack, int value) {
    assert(stack != NULL);
    assert(stack->data != NULL);

    // Check if we should allocate more memory.
    if (stack->length == stack->capacity) {
        stack->capacity *= 2;

        int* ptr = (int*) realloc(stack->data, sizeof(int) * stack->capacity);
        assert(ptr != NULL);

        memcpy(ptr, stack->data, sizeof(int) * stack->length);

        stack->data = ptr;
    }

    stack->data[stack->length] = value;
    stack->length++;
}

int stack_pop(stack_t* stack) {
    assert(stack != NULL);
    assert(stack->data != NULL);

    int lastElement = stack->data[stack->length - 1];
    stack->length--;
    return lastElement;
}

void stack_log(const stack_t* stack) {
    assert(stack != NULL);
    assert(stack->data != NULL);

    for (size_t i = 0; i < stack->length; i++) {
        printf("%d, ", stack->data[i]);
    }
    printf("\n");
}

void stack_free(stack_t* stack) {
    free(stack->data);
    free(stack);
}

// ------------------------- TESTS -------------------------
void stack_test_0() {
    printf("----- STACK TEST 0 -----\n");
    stack_t* stack = stack_allocate();
    stack_push(stack, 4);
    stack_push(stack, 7);
    stack_push(stack, 2);
    stack_log(stack);
    stack_pop(stack);
    stack_log(stack);
    stack_push(stack, 4);
    stack_push(stack, 7);
    stack_push(stack, 2);
    stack_log(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_log(stack);
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 4);
    stack_push(stack, 5);
    stack_log(stack);
    stack_free(stack);
}
// ---------------------------------------------------------