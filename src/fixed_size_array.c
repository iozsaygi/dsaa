#include "fixed_size_array.h"
#include <assert.h>
#include <printf.h>
#include <stdlib.h>

fsa_t* fsa_allocate(size_t length) {
    fsa_t* fsa = (fsa_t*) malloc(sizeof(fsa_t));
    if (fsa == NULL) {
        printf("Failed to allocate memory for fixed size array");
        return NULL;
    }

    fsa->length = length;
    fsa->data = (int*) malloc(sizeof(int) * fsa->length);

    if (fsa->data == NULL) {
        printf("Failed to allocate memory for context for fixed size array");
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

void fsa_log(const fsa_t* fsa) {
    for (size_t i = 0; i < fsa->length; i++) {
        int valueAt = fsa_getAt(fsa, i);
        printf("The value of element %zu is %d\n", i, valueAt);
    }
}

void fsa_free(fsa_t* fsa) {
    fsa->length = 0;
    free(fsa->data);
    free(fsa);

    printf("Cleared resources for fixed size array instance");
}

void fsa_tests() {
    fsa_t* fsa = fsa_allocate(10);
    if (fsa == NULL) return;

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