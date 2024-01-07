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

// Adds node with given value to the end of the list.
void circularSinglyLinkedList_insert(csll_t* csll, struct cslln* cslln);

// Removes node from list with given value.
void circularSinglyLinkedList_removeByValue(csll_t* csll, int value);

// Prints the values of each node in list.
void circularSinglyLinkedList_log(const csll_t* csll);

// Clears the allocated resources.
void circularSinglyLinkedList_free(csll_t* csll);

// ------------------------- TESTS -------------------------
void circular_singly_linked_list_test_0();
// ---------------------------------------------------------

#endif// !CIRCULAR_SINGLY_LINKED_LIST_H