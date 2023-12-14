#include "counting_sort.h"
#include <assert.h>
#include <stdio.h>

int* cs_execute(const int* array, size_t length) {
    assert(array != NULL);

    int* result = (int*) malloc(sizeof(int) * length);
    assert(result != NULL);

    int max = INT_MIN;
    for (size_t i = 0; i < length; i++) {
        if (array[i] > max) max = array[i];
    }

    int* buffer = (int*) calloc(max + 1, sizeof(int));
    assert(buffer != NULL);

    for (size_t i = 0; i < length; i++) {
        buffer[array[i]]++;
    }

    for (size_t i = 1; i <= max; i++) {
        buffer[i] += buffer[i - 1];
    }

    for (int i = (int) (length - 1); i >= 0; i--) {
        result[buffer[array[i]] - 1] = array[i];
        buffer[array[i]]--;
    }

    free(buffer);
    return result;
}

// ------------------------- TESTS -------------------------
void cs_test_0() {
    const size_t length = 10;
    int* array = (int*) malloc(sizeof(int) * length);

    array[0] = 4;
    array[1] = 10;
    array[2] = 2;
    array[3] = 1;
    array[4] = 5;
    array[5] = 19;
    array[6] = 2;
    array[7] = 2;
    array[8] = 0;
    array[9] = 13;

    for (size_t i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n------------------------------\n");

    int* sorted = cs_execute(array, length);

    for (size_t i = 0; i < length; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(array);
    free(sorted);
}
// ---------------------------------------------------------