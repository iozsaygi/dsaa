#include "quick_sort.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void quickSort_swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int quickSort_partition(int* array, int left, int right) {
    assert(array != NULL);

    int pivot = array[right];
    int index = left - 1;

    for (int i = left; i <= right - 1; i++) {
        if (array[i] < pivot) {
            index++;
            quickSort_swap(&array[index], &array[i]);
        }
    }

    quickSort_swap(&array[index + 1], &array[right]);

    return index + 1;
}

void quickSort_execute(int* array, int left, int right) {// NOLINT(*-no-recursion)
    assert(array != NULL);

    if (left < right) {
        int partition = quickSort_partition(array, left, right);
        quickSort_execute(array, left, partition - 1);
        quickSort_execute(array, partition + 1, right);
    }
}

// ------------------------- TESTS -------------------------
void quick_sort_test_0() {
    size_t length = 10;
    int* array = (int*) malloc(sizeof(int) * length);
    assert(array != NULL);

    array[0] = 3;
    array[1] = 1;
    array[2] = -12;
    array[3] = 5;
    array[4] = 9;
    array[5] = 2;
    array[6] = 17;
    array[7] = 28;
    array[8] = 9;
    array[9] = 35;

    for (size_t i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");

    quickSort_execute(array, 0, length - 1);// NOLINT(*-narrowing-conversions)

    for (size_t i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }

    free(array);
}
// ---------------------------------------------------------