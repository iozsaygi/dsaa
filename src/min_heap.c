#include "min_heap.h"
#include <assert.h>
#include <stdio.h>

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

void minHeap_insert(mh_t* mh, int value) {
    assert(mh != NULL);

    // Check if we are already on capacity.
    if (mh->length == mh->capacity) {
        return;
    }

    // We passed the capacity check, we can add given element.
    mh->length++;

    // Add given element as the latest.
    mh->data[mh->length - 1] = value;

    size_t current = mh->length - 1;

    // Ensure that we are swapping until value at correct position.
    size_t parentIndex = minHeap_findParentNodeIndex(current);

    while (current > 0 && mh->data[parentIndex] > mh->data[current]) {
        int temp = mh->data[parentIndex];
        mh->data[parentIndex] = mh->data[current];
        mh->data[current] = temp;

        // Update current and parent index.
        current = minHeap_findParentNodeIndex(current);
        parentIndex = minHeap_findParentNodeIndex(current);
    }
}

void minHeap_removeRoot(mh_t* mh) {
    assert(mh != NULL);

    // Update the root element as the last element.
    mh->data[0] = mh->data[mh->length - 1];

    // Update the length of the heap.
    mh->length--;

    // Maintain the order of the min-heap.
    minHeap_heapify(mh, 0);
}

mh_t* minHeap_heapify(mh_t* mh, size_t index) { // NOLINT(*-no-recursion)
    if (mh->length <= 1) {
        return mh;
    }

    // Calculate the left and right node indices of current index.
    size_t left = minHeap_findLeftNodeIndex(index);
    size_t right = minHeap_findRightNodeIndex(index);

    // Keep track of smallest element in subtree.
    size_t smallest = index;

    // Check if the left child is the smaller than current.
    if (left < mh->length && mh->data[left] < mh->data[index]) {
        smallest = left;
    }

    // Check if the right child is the smaller than current.
    if (right < mh->length && mh->data[right] < mh->data[index]) {
        smallest = right;
    }

    if (smallest != index) {
        int temp = mh->data[index];
        mh->data[index] = mh->data[smallest];
        mh->data[smallest] = temp;
        mh = minHeap_heapify(mh, smallest);
    }

    return mh;
}

void minHeap_free(mh_t* mh) {
    assert(mh != NULL);
    free(mh->data);
    free(mh);
}

// ------------------------- TESTS -------------------------
void min_heap_test_0() {
    mh_t* mh = minHeap_allocate(10);
    printf("%d\n", minHeap_peek(mh));

    minHeap_insert(mh, 6);
    minHeap_insert(mh, 2);
    minHeap_insert(mh, 8);
    minHeap_insert(mh, 5);
    minHeap_insert(mh, 1);
    minHeap_insert(mh, -1);
    minHeap_insert(mh, 3);
    minHeap_insert(mh, 0);

    printf("%d\n", minHeap_peek(mh));

    minHeap_free(mh);
}
// ---------------------------------------------------------