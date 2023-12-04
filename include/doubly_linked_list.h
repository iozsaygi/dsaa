// https://en.wikipedia.org/wiki/Doubly_linked_list

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct dlln {
    int data;
    struct dlln* next;
    struct dlln* previous;
};

typedef struct {
    struct dlln* head;
} dll_t;

// Allocates required memory for doubly linked list instance.
dll_t* dll_allocate();

// Traverses and logs the value of each node in doubly linked list by using next node pointers.
void dll_traverseForwards(const dll_t* dll);

// Traverses and logs the value of each node in doubly linked list by using previous node pointers.
void dll_traverseBackwards(const dll_t* dll);

// Inserts new node at the beginning of the list. Updates the head.
void dll_insertBeginning(dll_t* dll, struct dlln* node);

// Adds given 'node' to list right after 'target' node.
void dll_insertAfter(struct dlln* target, struct dlln* node);

// Removes 'head' node from list.
void dll_removeBeginning(dll_t* dll);

// Removes the node that is next to 'target' node.
void dll_removeAfter(struct dlln* target);

// Clears allocated resources.
void dll_free(dll_t* dll);

// ------------------------- TESTS -------------------------
void dll_test_0();
void dll_test_1();
// ---------------------------------------------------------

#endif// !DOUBLY_LINKED_LIST_H