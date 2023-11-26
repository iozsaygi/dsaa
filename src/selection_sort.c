#include "selection_sort.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void ss_swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void ss_execute(int* data, size_t length) {
    assert(data != NULL);

    for (size_t i = 0; i < length - 1; i++) {
        size_t sidx = i;

        for (size_t j = i + 1; j < length; j++) {
            if (data[j] < data[sidx]) sidx = j;
        }

        if (sidx != i) ss_swap(&data[i], &data[sidx]);
    }
}

// ------------------------- TESTS -------------------------
void ss_test_0() {
    size_t length = 6;
    int* array = malloc(sizeof(int) * length);
    assert(array != NULL);

    array[0] = -4;
    array[1] = -9;
    array[2] = 25;
    array[3] = 1;
    array[4] = 7;
    array[5] = 0;

    for (size_t i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");

    ss_execute(array, length);

    for (size_t i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");

    free(array);
}
// ---------------------------------------------------------