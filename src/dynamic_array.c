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
        printf("Reallocating memory for dynamic array, length was %zu and capacity was %zu \n", da->length, da->capacity);
        da->capacity *= 2;

        // Allocate new memory for dynamic array.
        int* ptr = (int*) realloc(da->data, sizeof(int) * da->capacity);

        // Copy the context of existng array into new allocated one.
        memcpy(ptr, da->data, sizeof(int) * da->length);

        da->data = ptr;
    }

    da->data[da->length] = value;
    da->length++;
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
    da_t* da = da_allocate(2);
    da_log(da);
    da_append(da, 8);
    da_append(da, 2);
    da_append(da, 5);
    da_append(da, 1);
    da_append(da, 13);
    da_log(da);
    da_append(da, 17);
    da_append(da, 21);
    da_log(da);
    da_free(da);
}
// ---------------------------------------------------------