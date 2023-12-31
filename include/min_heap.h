#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdlib.h>

// Core struct to represent min-heap.
typedef struct {

    // Maximum numbers of elements allowed.
    size_t capacity;

    // Current size of the min-heap.
    size_t length;

    // Actual pointer to store array.
    int* data;

} mh_t;

// Allocates required resources and returns pointer to min-heap.
mh_t* minHeap_allocate(size_t capacity);

// Returns the smallest element from min-heap.
int minHeap_peek(const mh_t* mh);

// Calculates the index of the parent node for the node with given index.
size_t minHeap_findParentNodeIndex(size_t index);

// Calculates the index of the left node for the node with given index.
size_t minHeap_findLeftNodeIndex(size_t index);

// Calculates the index of the right node for the node with given index.
size_t minHeap_findRightNodeIndex(size_t index);

// Adds given value to the min-heap.
void minHeap_insert(mh_t* mh, int value);

// Returns and removes root (smallest) element from min-heap.
void minHeap_removeRoot(mh_t* mh);

// Removes element with given index from min-heap.
void minHeap_removeElementByIndex(mh_t* mh, size_t index);

// Removes the given value from min-heap.
void minHeap_removeElementByValue(mh_t* mh, int value);

// Converts the internal array to the tree/heap structure to maintain the smallest element rule.
mh_t* minHeap_heapify(mh_t* mh, size_t index);

// Clears allocated resources for the min-heap.
void minHeap_free(mh_t* mh);

// ------------------------- TESTS -------------------------
void min_heap_test_0();
// ---------------------------------------------------------

#endif// !MIN_HEAP_H