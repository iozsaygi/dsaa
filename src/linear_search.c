#include "linear_search.h"
#include <assert.h>
#include <stdlib.h>

size_t ls_findIndexOf(const int* data, size_t length, int target) {
    for (size_t i = 0; i < length; i++) {
        if (data[i] == target) return i;
    }

    return INVALID_INDEX;
}

// ------------------------- TESTS -------------------------
void ls_test_0() {
    size_t length = 5;
    int* array = malloc(sizeof(int) * length);
    assert(array != NULL);

    array[0] = 16;
    array[1] = 256;
    array[2] = 4;
    array[3] = 68;
    array[4] = 101;

    size_t firstPass = ls_findIndexOf(array, length, 14);
    assert(firstPass == INVALID_INDEX);

    size_t secondPass = ls_findIndexOf(array, length, 68);
    assert(secondPass == 3);

    free(array);
}
// ---------------------------------------------------------