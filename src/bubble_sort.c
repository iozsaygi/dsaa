#include "bubble_sort.h"
#include <assert.h>
#include <stdio.h>

void bs_swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bs_execute(int* array, size_t length) {
    for (size_t i = 1; i < length; i++) {
        for (size_t j = 0; j < length - 1; j++) {
            if (array[j] > array[j + 1]) bs_swap(&array[j], &array[j + 1]);
        }
    }
}

// ------------------------- TESTS -------------------------
void bsort_test_0() {
    size_t length = 6;
    int* array = malloc(sizeof(int) * length);
    assert(array != NULL);

    array[0] = 17;
    array[1] = 9;
    array[2] = -3;
    array[3] = 0;
    array[4] = 25;
    array[5] = 4;

    for (size_t i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");

    bs_execute(array, length);

    for (size_t i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");

    free(array);
}
// ---------------------------------------------------------