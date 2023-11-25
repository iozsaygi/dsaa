#include "binary_search.h"
#include <assert.h>
#include <stdlib.h>

size_t bs_findIndexOf(const int* data, size_t length, int target) {
    size_t left = 0;
    size_t right = length - 1;

    while (left <= right) {
        size_t middleIndex = (left + right) / 2;
        if (data[middleIndex] == target) return middleIndex;

        if (data[middleIndex] > target) right = middleIndex - 1;
        else
            left = middleIndex + 1;

        if (data[left] == target) return left;
    }

    return INVALID_INDEX;
}

// ------------------------- TESTS -------------------------
void bs_test_0() {
    size_t length = 5;
    int* array = malloc(sizeof(int) * length);
    assert(array != NULL);

    array[0] = 16;
    array[1] = 256;
    array[2] = 4;
    array[3] = 68;
    array[4] = 101;

    size_t firstPass = bs_findIndexOf(array, length, 14);
    assert(firstPass == INVALID_INDEX);

    size_t secondPass = bs_findIndexOf(array, length, 68);
    assert(secondPass == 3);

    free(array);
}
// ---------------------------------------------------------