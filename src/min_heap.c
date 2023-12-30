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

void minHeap_removeElementByIndex(mh_t* mh, size_t index) {
    assert(mh != NULL);

    // Ensure that target is lesser than current root of min-heap.
    mh->data[index] = mh->data[0] - 1;

    // Now start swapping to update tree.
    size_t current = index;
    size_t parentIndex = minHeap_findParentNodeIndex(current);

    while (current > 0 && mh->data[parentIndex] > mh->data[current]) {
        int temp = mh->data[parentIndex];
        mh->data[parentIndex] = mh->data[current];
        mh->data[current] = temp;

        // Update the indices.
        current = parentIndex;
        parentIndex = minHeap_findParentNodeIndex(current);
    }

    // Now we just need to remove the root.
    minHeap_removeRoot(mh);
}

void minHeap_removeElementByValue(mh_t* mh, int value) {
    assert(mh != NULL);

    // Find the index of element with specified value.
    int index = -1;
    for (size_t i = 0; i < mh->length; i++) {
        if (mh->data[i] == value) {
            index = (int) i;
            break;
        }
    }

    // Ensure we found the value in heap.
    if (index == -1) {
        return;
    }

    // Set the element we want to remove as smaller than root.
    mh->data[index] = mh->data[0] - 1;

    // Update the heap.
    minHeap_heapify(mh, index);

    // Just remove the root node.
    minHeap_removeRoot(mh);
}

mh_t* minHeap_heapify(mh_t* mh, size_t index) {// NOLINT(*-no-recursion)
    if (mh->length <= 1) {
        return mh;
    }

    // Calculate the left and right node indices of current index.
    size_t left = minHeap_findLeftNodeIndex(index);
    size_t right = minHeap_findRightNodeIndex(index);

    // Keep track of smallest element in subtree.
    size_t smallest = index;

    // Check if the left child is the smaller than current.
    if (left < mh->length && mh->data[left] < mh->data[smallest]) {
        smallest = left;
    }

    // Check if the right child is the smaller than current.
    if (right < mh->length && mh->data[right] < mh->data[smallest]) {
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
    printf("Peek: %d\n", minHeap_peek(mh));

    // data[0]
    minHeap_insert(mh, 6);

    // data[1]
    minHeap_insert(mh, 2);

    // data[2]
    minHeap_insert(mh, 8);

    // data[3]
    minHeap_insert(mh, 5);

    // data[4]
    minHeap_insert(mh, 1);

    // data[5]
    minHeap_insert(mh, -1);

    // data[6]
    minHeap_insert(mh, 3);

    // data[7]
    minHeap_insert(mh, 0);

    printf("Peek: %d\n", minHeap_peek(mh));

    printf("Length: %zu\n", mh->length);
    minHeap_removeRoot(mh);
    printf("Length: %zu\n", mh->length);

    printf("Peek: %d\n", minHeap_peek(mh));

    minHeap_removeElementByIndex(mh, 2);

    printf("Peek: %d\n", minHeap_peek(mh));
    printf("Length: %zu\n", mh->length);

    minHeap_removeElementByValue(mh, 0);

    printf("Peek: %d\n", minHeap_peek(mh));
    printf("Length: %zu\n", mh->length);

    minHeap_removeElementByValue(mh, 2);

    printf("Peek: %d\n", minHeap_peek(mh));
    printf("Length: %zu\n", mh->length);

    minHeap_free(mh);
}
// ---------------------------------------------------------