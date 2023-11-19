// https://en.wikipedia.org/wiki/Queue_(abstract_data_type)

#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct {
    int* data;
    size_t front;
    size_t back;
    size_t length;
    size_t capacity;
} queue_t;

// Allocates required resources for basic queue.
queue_t* queue_allocate();

// Adds given 'value' to the end of queue.
void queue_enqueue(queue_t* queue, int value);

// Returns an element from the start of queue.
int queue_dequeue(queue_t* queue);

// Prints the values inside queue.
void queue_log(const queue_t* queue);

// Clears allocated resources for queue.
void queue_free(queue_t* queue);

// ------------------------- TESTS -------------------------
void queue_test_0();
// ---------------------------------------------------------

#endif// !QUEUE_H