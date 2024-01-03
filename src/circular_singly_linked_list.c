#include "circular_singly_linked_list.h"
#include <assert.h>
#include <stdlib.h>

csll_t* circularSinglyLinkedList_allocate() {
    csll_t* csll = (csll_t*) malloc(sizeof(csll_t));
    assert(csll != NULL);
    csll->head = NULL;
    return csll;
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

    circularSinglyLinkedList_free(csll);
}
// ---------------------------------------------------------