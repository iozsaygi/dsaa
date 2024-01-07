#include "circular_singly_linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

csll_t* circularSinglyLinkedList_allocate() {
    csll_t* csll = (csll_t*) malloc(sizeof(csll_t));
    assert(csll != NULL);
    csll->head = NULL;
    return csll;
}

void circularSinglyLinkedList_insert(csll_t* csll, struct cslln* cslln) {
    assert(csll != NULL);
    assert(cslln != NULL);

    cslln->next = NULL;

    // Check if it is the first node that will be added to list.
    if (csll->head == NULL) {
        csll->head = cslln;
        return;
    }

    // Traverse the list to find the last node.
    struct cslln* itr = csll->head;
    while (itr->next != NULL && itr->next != csll->head) {
        itr = itr->next;
    }

    itr->next = cslln;
    cslln->next = csll->head;
}

void circularSinglyLinkedList_removeByValue(csll_t* csll, int value) {
    assert(csll != NULL);

    if (csll->head == NULL) {
        return;
    }

    struct cslln* current = csll->head;
    struct cslln* previous = NULL;

    do {
        if (current->data == value) {
            if (previous == NULL) {
                csll->head = current->next;
            } else {
                previous->next = current->next;
            }

            current->next = NULL;

            free(current);

            return;
        }

        previous = current;
        current = current->next;
    } while (current != csll->head);
}

void circularSinglyLinkedList_log(const csll_t* csll) {
    assert(csll != NULL);

    const struct cslln* current = csll->head;

    // Check if the list is empty.
    if (current == NULL) {
        return;
    }

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != csll->head);

    printf("\n");
}

void circularSinglyLinkedList_free(csll_t* csll) {
    assert(csll != NULL);

    struct cslln* current = csll->head;
    struct cslln* next = NULL;

    while (current != NULL) {
        next = current->next;

        if (next == csll->head) {
            current->next = NULL;
        }

        free(current);
        current = next;
    }

    free(csll);
}

// ------------------------- TESTS -------------------------
void circular_singly_linked_list_test_0() {
    csll_t* csll = circularSinglyLinkedList_allocate();

    circularSinglyLinkedList_log(csll);

    struct cslln* firstCslln = (struct cslln*) malloc(sizeof(struct cslln));
    struct cslln* secondCslln = (struct cslln*) malloc(sizeof(struct cslln));
    struct cslln* thirdCslln = (struct cslln*) malloc(sizeof(struct cslln));
    struct cslln* fourthCslln = (struct cslln*) malloc(sizeof(struct cslln));
    struct cslln* fifthCslln = (struct cslln*) malloc(sizeof(struct cslln));

    firstCslln->data = 2;
    secondCslln->data = 6;
    thirdCslln->data = 4;
    fourthCslln->data = 1;
    fifthCslln->data = 10;

    circularSinglyLinkedList_insert(csll, firstCslln);
    circularSinglyLinkedList_insert(csll, secondCslln);
    circularSinglyLinkedList_insert(csll, thirdCslln);
    circularSinglyLinkedList_insert(csll, fourthCslln);
    circularSinglyLinkedList_insert(csll, fifthCslln);

    circularSinglyLinkedList_log(csll);

    circularSinglyLinkedList_removeByValue(csll, 2);
    circularSinglyLinkedList_removeByValue(csll, 6);
    circularSinglyLinkedList_removeByValue(csll, 13);

    circularSinglyLinkedList_log(csll);

    circularSinglyLinkedList_free(csll);
}
// ---------------------------------------------------------