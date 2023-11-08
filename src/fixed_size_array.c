#include "fixed_size_array.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

fsa_t* fsa_allocate(size_t length) {
    fsa_t* fsa = (fsa_t*) malloc(sizeof(fsa_t));
    if (fsa == NULL) {
        perror("Failed to allocate memory for fixed size array");
        return NULL;
    }

    fsa->length = length;
    fsa->data = (int*) malloc(sizeof(int) * fsa->length);

    if (fsa->data == NULL) {
        perror("Failed to allocate memory for context for fixed size array");
        return NULL;
    }

    return fsa;
}

int fsa_getAt(const fsa_t* fsa, size_t index) {
    assert(index < fsa->length);
    return fsa->data[index];
}

void fsa_setAt(const fsa_t* fsa, size_t index, int value) {
    assert(index < fsa->length);
    fsa->data[index] = value;
}

void fsa_setAll(const fsa_t* fsa, int value) {
    for (size_t i = 0; i < fsa->length; i++) {
        fsa_setAt(fsa, i, value);
    }
}

void fsa_copy(const fsa_t* src, const fsa_t* dst) {
    assert(src != NULL && src->data != NULL);
    assert(dst != NULL && dst->data != NULL);

    for (size_t i = 0; i < dst->length; i++) {
        fsa_setAt(dst, i, src->data[i]);
    }
}

void fsa_log(const fsa_t* fsa) {
    for (size_t i = 0; i < fsa->length; i++) {
        int valueAt = fsa_getAt(fsa, i);
        printf("[%zu]: %d\n", i, valueAt);
    }
}

void fsa_free(fsa_t* fsa) {
    fsa->length = 0;
    free(fsa->data);
    free(fsa);

    printf("Cleared resources for fixed size array instance\n");
}

// ------------------------- TESTS -------------------------
void fsa_test_0() {
    printf("----- FSA TEST 0 -----\n");
    fsa_t* fsa = fsa_allocate(10);
    if (fsa == NULL) return;
    fsa_setAll(fsa, 0);

    fsa_log(fsa);
    for (size_t i = 0; i < fsa->length; i++) {
        const int incrementation = 5;
        int value = fsa_getAt(fsa, i) + incrementation;
        fsa_setAt(fsa, i, value);
    }
    fsa_log(fsa);

    for (size_t i = 0; i < fsa->length; i++) {
        const int incrementation = 5;
        int value = fsa_getAt(fsa, i) + incrementation;
        fsa_setAt(fsa, i, value);
    }
    fsa_log(fsa);

    fsa_free(fsa);
}

void fsa_test_1() {
    printf("----- FSA TEST 1 -----\n");
    fsa_t* fsa = fsa_allocate(10);
    if (fsa == NULL) return;
    fsa_setAll(fsa, 0);

    fsa_log(fsa);
    fsa_setAt(fsa, 4, -15);
    fsa_log(fsa);
    fsa_setAt(fsa, 3, 24);
    fsa_log(fsa);

    fsa_free(fsa);
}

void fsa_test_2() {
    printf("----- FSA TEST 2 -----\n");
    fsa_t* src = fsa_allocate(10);
    fsa_t* dst = fsa_allocate(5);

    fsa_setAll(src, 5);
    fsa_setAll(dst, 0);

    fsa_log(src);
    fsa_log(dst);

    fsa_copy(src, dst);
    fsa_log(src);
    fsa_log(dst);

    fsa_free(src);
    fsa_free(dst);
}
// ---------------------------------------------------------