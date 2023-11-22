#include "dynamic_array.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

da_t* da_allocate(size_t length) {
    da_t* da = (da_t*) malloc(sizeof(da_t));
    assert(da != NULL);

    da->capacity = length * 2;
    da->data = (int*) calloc(0, sizeof(int) * da->capacity);
    assert(da->data != NULL);

    da->length = length;

    return da;
}

void da_append(da_t* da, int value) {
    // Check if we have enough room for this.
    if (da->length == da->capacity) {
        da->capacity *= 2;

        // Allocate new memory for dynamic array.
        int* ptr = (int*) realloc(da->data, sizeof(int) * da->capacity);
        assert(ptr != NULL);

        // Copy the context of existing array into new allocated one.
        memcpy(ptr, da->data, sizeof(int) * da->length);

        da->data = ptr;
    }

    da->data[da->length] = value;
    da->length++;
}

void da_insertAt(da_t* da, size_t index, int value) {
    assert(da != NULL);
    assert(da->data != NULL);
    assert(index <= da->length);// Allow inserting at the end as well

    if (da->length == da->capacity) {
        da->capacity *= 2;

        int* ptr = (int*) realloc(da->data, sizeof(int) * da->capacity);
        assert(ptr != NULL);

        da->data = ptr;
    }

    // Shift elements to the right.
    for (size_t i = da->length; i > index; i--) {
        da->data[i] = da->data[i - 1];
    }

    da->data[index] = value;
    da->length++;
}

void da_setAt(da_t* da, size_t index, int value) {
    assert(da != NULL);
    assert(da->data != NULL);
    assert(index < da->length);

    da->data[index] = value;
}

void da_remove(da_t* da) {
    assert(da != NULL);
    assert(da->data != NULL);

    da->length--;
    da->capacity = da->length;

    int* ptr = (int*) realloc(da->data, sizeof(int) * da->length);
    assert(ptr != NULL);

    memcpy(ptr, da->data, sizeof(int) * da->length);

    da->data = ptr;
}

void da_removeAt(da_t* da, size_t index) {
    assert(da != NULL);
    assert(da->data != NULL);
    assert(index < da->length);

    // Shift elements to left.
    for (size_t i = index; i < da->length; i++) {
        da->data[i] = da->data[i + 1];
    }

    da->length--;

    // Also update the physical memory.
    int* ptr = (int*) realloc(da->data, sizeof(int) * da->length);
    assert(ptr != NULL);

    memcpy(ptr, da->data, sizeof(int) * da->length);

    da->data = ptr;
}

void da_clear(da_t* da) {
    assert(da != NULL);
    assert(da->data != NULL);

    free(da->data);
    da->length = 1;
    da->capacity = 1;

    da->data = calloc(0, sizeof(int) * da->capacity);
    assert(da->data != NULL);
}

void da_log(const da_t* da) {
    assert(da != NULL);

    for (size_t i = 0; i < da->length; i++) {
        printf("%d, ", da->data[i]);
    }
    printf("\n");
}

void da_free(da_t* da) {
    free(da->data);
    free(da);
}

// ------------------------- TESTS -------------------------
void da_test_0() {
    printf("----- DA TEST 0 -----\n");
    da_t* da = da_allocate(2);
    da_log(da);
    da_append(da, 8);
    da_append(da, 2);
    da_append(da, 5);
    da_append(da, 1);
    da_append(da, 13);
    da_log(da);
    da_setAt(da, 0, -14);
    da_append(da, 17);
    da_append(da, 21);
    da_log(da);
    da_free(da);
}

void da_test_1() {
    printf("----- DA TEST 1 -----\n");
    da_t* da = da_allocate(3);
    da_setAt(da, 0, 0);
    da_setAt(da, 1, 1);
    da_setAt(da, 2, 2);
    da_log(da);
    da_remove(da);
    da_remove(da);
    da_log(da);
    da_free(da);
}

void da_test_2() {
    printf("----- DA TEST 2 -----\n");
    da_t* da = da_allocate(5);
    da_setAt(da, 0, 0);
    da_setAt(da, 1, 1);
    da_setAt(da, 2, 2);
    da_setAt(da, 3, 3);
    da_setAt(da, 4, 4);
    da_log(da);
    da_removeAt(da, 2);
    da_removeAt(da, 2);
    da_log(da);
    da_insertAt(da, 0, 4);
    da_insertAt(da, 3, 5);
    da_log(da);
    da_free(da);
}

void da_test_3() {
    printf("----- DA TEST 3 -----\n");
    da_t* da = da_allocate(5);
    da_append(da, 4);
    da_append(da, 3);
    da_append(da, 13);
    da_log(da);
    da_clear(da);
    da_log(da);
    da_free(da);
}
// ---------------------------------------------------------