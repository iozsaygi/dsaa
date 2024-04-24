#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

queue_t* queue_allocate() {
    queue_t* queue = (queue_t*) malloc(sizeof(queue_t));
    assert(queue != NULL);

    queue->front = 0;
    queue->back = 0;
    queue->length = 0;
    queue->capacity = 2;

    queue->data = (int*) calloc(0, sizeof(int) * queue->capacity);
    assert(queue->data != NULL);

    return queue;
}

void queue_enqueue(queue_t* queue, int value) {
    assert(queue != NULL);
    assert(queue->data != NULL);

    // Ensure we have enough room to store new elements in queue.
    if (queue->length == queue->capacity) {
        queue->capacity *= 2;

        int* ptr = (int*) realloc(queue->data, sizeof(int) * queue->capacity);
        assert(ptr != NULL);

        memcpy(ptr, queue->data, sizeof(int) * queue->length);

        queue->data = ptr;
    }

    queue->data[queue->length] = value;
    queue->length++;
    queue->back = queue->length;
}

int queue_dequeue(queue_t* queue) {
    assert(queue != NULL);
    assert(queue->data != NULL);
    assert(queue->length > 0);

    int firstItem = queue->data[queue->front];

    // Shift elements to the right.
    for (size_t i = queue->front; i < queue->length - 1; i++) {
        queue->data[i] = queue->data[i + 1];
    }

    queue->length--;
    queue->back = queue->length - 1;

    // I might want to consider binding reallocation to a specific case later on.
    // This is just for practice; this introduces a lot of memory allocation during the usage.
    // We'll want to avoid this practice in a real-world scenario if we think about memory fragmentation.
    if (queue->length < queue->capacity / 2) {
        queue->capacity /= 2;
        int* ptr = (int*) realloc(queue->data, sizeof(int) * queue->capacity);
        assert(ptr != NULL);
        queue->data = ptr;
    }

    return firstItem;
}

int queue_isEmpty(const queue_t* queue) {
    assert(queue != NULL);
    if (queue->length > 0) {
        return 0;
    } else {
        return 1;
    }
}

void queue_log(const queue_t* queue) {
    assert(queue != NULL);
    assert(queue->data != NULL);

    for (size_t i = 0; i < queue->length; i++) {
        printf("%d, ", queue->data[i]);
    }
    printf("\n");
}

void queue_free(queue_t* queue) {
    free(queue->data);
    free(queue);
}

// ------------------------- TESTS -------------------------
void queue_test_0() {
    printf("----- QUEUE TEST 0 -----\n");
    queue_t* queue = queue_allocate();
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 4);
    queue_log(queue);
    queue_dequeue(queue);
    queue_log(queue);
    queue_enqueue(queue, 17);
    queue_enqueue(queue, 10);
    queue_enqueue(queue, 11);
    queue_enqueue(queue, 19);
    queue_log(queue);
    queue_dequeue(queue);
    queue_dequeue(queue);
    queue_dequeue(queue);
    queue_log(queue);
    queue_free(queue);
}
// ---------------------------------------------------------