#include "singly_linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

sll_t* sll_allocate() {
    sll_t* sll = (sll_t*) malloc(sizeof(sll_t));
    assert(sll != NULL);

    // TODO: Consider allocating for head later on.
    struct slln* head = (struct slln*) malloc(sizeof(struct slln));
    assert(head != NULL);

    // Initialize the value of head. (Optional)
    head->data = 0;

    sll->head = head;
    return sll;
}

void sll_traverse(const sll_t* sll) {
    assert(sll != NULL);
    assert(sll->head != NULL);

    struct slln* current = sll->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void sll_insertBeginning(sll_t* sll, struct slln* node) {
    assert(sll != NULL);
    assert(node != NULL);

    node->next = sll->head;
    sll->head = node;
}

void sll_insertAfter(struct slln* target, struct slln* node) {
    assert(target != NULL);
    assert(node != NULL);

    node->next = target->next;
    target->next = node;
}

void sll_removeBeginning(sll_t* sll) {
    assert(sll != NULL);

    // Update the pointers.
    struct slln* ntr = sll->head;
    sll->head = sll->head->next;

    free(ntr);
    ntr = NULL;
}

void sll_removeAfter(struct slln* target) {
    assert(target != NULL);

    struct slln* ntr = target->next;
    assert(ntr != NULL);

    target->next = ntr->next;

    free(ntr);
    ntr = NULL;
}

void sll_free(sll_t* sll) {
    assert(sll != NULL);

    struct slln* current = sll->head;
    struct slln* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(sll);
}

// ------------------------- TESTS -------------------------
void sll_test_0() {
    printf("----- SLL TEST 0 -----\n");

    sll_t* sll = sll_allocate();
    sll_traverse(sll);

    // Allocate nodes to add.
    struct slln* s1 = (struct slln*) malloc(sizeof(struct slln));
    struct slln* s2 = (struct slln*) malloc(sizeof(struct slln));
    struct slln* s3 = (struct slln*) malloc(sizeof(struct slln));
    struct slln* s4 = (struct slln*) malloc(sizeof(struct slln));

    s1->data = 1;
    s2->data = 2;
    s3->data = 3;
    s4->data = 4;

    sll_insertBeginning(sll, s1);
    sll_insertAfter(s1, s2);
    sll_insertAfter(s2, s3);

    sll_traverse(sll);

    sll_insertAfter(s2, s4);

    sll_traverse(sll);

    sll_free(sll);
}

void sll_test_1() {
    printf("----- SLL TEST 1 -----\n");

    sll_t* sll = sll_allocate();

    struct slln* s1 = (struct slln*) malloc(sizeof(struct slln));
    struct slln* s2 = (struct slln*) malloc(sizeof(struct slln));
    struct slln* s3 = (struct slln*) malloc(sizeof(struct slln));
    struct slln* s4 = (struct slln*) malloc(sizeof(struct slln));

    s1->data = 1;
    s2->data = 2;
    s3->data = 3;
    s4->data = 4;

    sll_insertBeginning(sll, s1);
    sll_insertAfter(s1, s2);
    sll_insertAfter(s2, s3);
    sll_insertAfter(s3, s4);

    sll_traverse(sll);

    sll_removeBeginning(sll);

    sll_traverse(sll);

    sll_removeAfter(s2);
    sll_traverse(sll);
    sll_removeAfter(s4);
    sll_traverse(sll);

    sll_free(sll);
}
// ---------------------------------------------------------