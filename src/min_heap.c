#include "min_heap.h"
#include <assert.h>

mh_t* minHeap_allocate(size_t capacity) {
    assert(capacity > 0);

    // Allocate the min-heap itself.
    mh_t* mh = (mh_t*) malloc(sizeof(mh_t));
    assert(mh != NULL);

    mh->capacity = capacity;
    mh->length = 0;

    // Allocate for the internal array.
    mh->data = (int*) calloc(capacity, sizeof(int));

    return mh;
}

int minHeap_peek(const mh_t* mh) {
    assert(mh != NULL);
    return mh->data[0];
}

size_t minHeap_findParentNodeIndex(size_t index) {
    return (index - 1) / 2;
}

size_t minHeap_findLeftNodeIndex(size_t index) {
    return (index * 2) + 1;
}

size_t minHeap_findRightNodeIndex(size_t index) {
    return (index * 2) + 2;
}

void minHeap_free(mh_t* mh) {
    assert(mh != NULL);
    free(mh->data);
    free(mh);
}

// ------------------------- TESTS -------------------------
void min_heap_test_0() {
}
// ---------------------------------------------------------