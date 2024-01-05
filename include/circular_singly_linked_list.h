// https://www.geeksforgeeks.org/circular-linked-list/

#ifndef CIRCULAR_SINGLY_LINKED_LIST_H
#define CIRCULAR_SINGLY_LINKED_LIST_H

// Special node structure for circular singly linked list.
struct cslln {
    int data;
    struct cslln* next;
};

// The actual struct to represent circular singly linked list.
typedef struct {
    struct cslln* head;
} csll_t;

// Allocates required resources.
csll_t* circularSinglyLinkedList_allocate();

// Adds node with given value.
struct cslln* circularSinglyLinkedList_insert(csll_t* csll, int value);

// Clears the allocated resources.
void circularSinglyLinkedList_free(csll_t* csll);

// ------------------------- TESTS -------------------------
void circular_singly_linked_list_test_0();
// ---------------------------------------------------------

#endif// !CIRCULAR_SINGLY_LINKED_LIST_H