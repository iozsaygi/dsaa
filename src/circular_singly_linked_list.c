#include "circular_singly_linked_list.h"
#include <assert.h>
#include <stdlib.h>

csll_t* circularSinglyLinkedList_allocate() {
    csll_t* csll = (csll_t*) malloc(sizeof(csll_t));
    assert(csll != NULL);
    csll->head = NULL;
    return csll;
}

struct cslln* circularSinglyLinkedList_insert(csll_t* csll, int value) {
    assert(csll != NULL);

    // Allocate the actual node.
    struct cslln* cslln = (struct cslln*) malloc(sizeof(struct cslln));
    assert(cslln != NULL);

    // Check if it is the first node that will be added to list.
    if (csll->head == NULL) {
        csll->head = cslln;
        return cslln;
    }

    return cslln;
}

void circularSinglyLinkedList_free(csll_t* csll) {
    assert(csll != NULL);

    struct cslln* current = csll->head;
    struct cslln* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(csll);
}

// ------------------------- TESTS -------------------------
void circular_singly_linked_list_test_0() {
    csll_t* csll = circularSinglyLinkedList_allocate();

    struct cslln* firstCslln = circularSinglyLinkedList_insert(csll, 0);
    struct cslln* secondCslln = circularSinglyLinkedList_insert(csll, 2);
    struct cslln* thirdCslln = circularSinglyLinkedList_insert(csll, 4);
    struct cslln* fourthCslln = circularSinglyLinkedList_insert(csll, 1);
    struct cslln* fifthCslln = circularSinglyLinkedList_insert(csll, 6);

    circularSinglyLinkedList_free(csll);
}
// ---------------------------------------------------------