#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

// https://en.wikipedia.org/wiki/Linked_list

// Core declaration for singly linked list node.
struct slln {
    int data;
    struct slln* next;
};

// Core declaration for singly linked list.
typedef struct {
    struct slln* head;
} sll_t;

// Allocates required memory for singly linked list and head node.
// Also, setups the initial value of head node with 0.
sll_t* sll_allocate();

// Traverses the entire singly linked list and prints the values of each node.
void sll_traverse(const sll_t* sll);

// Adds given node before the head of given singly linked list.
// Eventually, updates the head node.
void sll_insertBeginning(sll_t* sll, struct slln* node);

// Adds the given 'node' right after specified 'target' node.
void sll_insertAfter(struct slln* target, struct slln* node);

// Removes the head node.
void sll_removeBeginning(sll_t* sll);

// Removes the next node after given 'target' node.
void sll_removeAfter(struct slln* target);

// Clears allocated resources for singly linked list.
void sll_free(sll_t* sll);

// ------------------------- TESTS -------------------------
void sll_test_0();
void sll_test_1();
// ---------------------------------------------------------

#endif// !SINGLY_LINKED_LIST_H