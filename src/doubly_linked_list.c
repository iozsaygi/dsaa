#include "doubly_linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

dll_t* dll_allocate() {
    dll_t* dll = (dll_t*) malloc(sizeof(dll_t));
    assert(dll != NULL);

    dll->head = NULL;

    return dll;
}

void dll_traverseForwards(const dll_t* dll) {
    assert(dll != NULL);
    assert(dll->head != NULL);

    struct dlln* current = dll->head;
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("\n");
}

void dll_traverseBackwards(const dll_t* dll) {
    assert(dll != NULL);
    assert(dll->head != NULL);

    // Okay this might not be the good idea, we are iterating on list for two times to traverse it backwards.
    // I could also store a 'tail' node pointer in the 'dll_t' struct to avoid this.

    // Find the last (tail) node.
    struct dlln* tail = NULL;

    struct dlln* itr = dll->head;
    while (tail == NULL) {
        if (itr->next == NULL) tail = itr;
        itr = itr->next;
    }

    // Now we know which node is the last node. Iterate through list with previous node pointers.
    struct dlln* current = tail;
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->previous;
    }
    printf("\n");
}

void dll_insertBeginning(dll_t* dll, struct dlln* node) {
    assert(dll != NULL);
    assert(dll->head != NULL);
    assert(dll->head->previous == NULL);
    assert(node != NULL);

    dll->head->previous = node;
    node->next = dll->head;
    node->previous = NULL;
    dll->head = node;
}

void dll_insertAfter(struct dlln* target, struct dlln* node) {
    assert(target != NULL);
    assert(node != NULL);

    struct dlln* temp = target->next;
    target->next = node;
    node->next = temp;

    if (temp != NULL) temp->previous = node;
    node->previous = target;
}

void dll_removeBeginning(dll_t* dll) {
    assert(dll != NULL);
    assert(dll->head != NULL);

    struct dlln* temp = dll->head->next;
    temp->previous = NULL;
    free(dll->head);
    dll->head = temp;
}

void dll_removeAfter(struct dlln* target) {
    assert(target != NULL);

    if (target->next != NULL) {
        struct dlln* old = target->next;
        target->next = old->next;

        if (old->next != NULL) old->next->previous = target;

        free(old);
    }
}

void dll_free(dll_t* dll) {
    assert(dll != NULL);

    struct dlln* current = dll->head;
    struct dlln* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(dll);
}

// ------------------------- TESTS -------------------------
void dll_test_0() {
    printf("----- DLL TEST 0 -----\n");
    struct dlln* first = (struct dlln*) malloc(sizeof(struct dlln));
    struct dlln* second = (struct dlln*) malloc(sizeof(struct dlln));
    struct dlln* third = (struct dlln*) malloc(sizeof(struct dlln));
    struct dlln* fourth = (struct dlln*) malloc(sizeof(struct dlln));
    struct dlln* fifth = (struct dlln*) malloc(sizeof(struct dlln));

    first->data = 0;
    second->data = 1;
    third->data = 2;
    fourth->data = 3;
    fifth->data = 4;

    first->previous = NULL;
    first->next = second;

    second->previous = first;
    second->next = third;

    third->previous = second;
    third->next = fourth;

    fourth->previous = third;
    fourth->next = fifth;

    fifth->previous = fourth;
    fifth->next = NULL;

    dll_t* dll = dll_allocate();
    dll->head = first;

    dll_traverseForwards(dll);
    dll_traverseBackwards(dll);

    dll_free(dll);
}

void dll_test_1() {
    printf("----- DLL TEST 1 -----\n");
    struct dlln* first = (struct dlln*) malloc(sizeof(struct dlln));
    struct dlln* second = (struct dlln*) malloc(sizeof(struct dlln));
    struct dlln* third = (struct dlln*) malloc(sizeof(struct dlln));
    struct dlln* fourth = (struct dlln*) malloc(sizeof(struct dlln));
    struct dlln* fifth = (struct dlln*) malloc(sizeof(struct dlln));

    first->data = 0;
    second->data = 1;
    third->data = 2;
    fourth->data = 3;
    fifth->data = 4;

    first->previous = NULL;
    first->next = second;

    second->previous = first;
    second->next = third;

    third->previous = second;
    third->next = fourth;

    fourth->previous = third;
    fourth->next = fifth;

    fifth->previous = fourth;
    fifth->next = NULL;

    dll_t* dll = dll_allocate();
    dll->head = first;

    struct dlln* sixth = (struct dlln*) malloc(sizeof(struct dlln));
    sixth->data = 6;
    dll_insertBeginning(dll, sixth);
    dll_traverseForwards(dll);

    struct dlln* seventh = (struct dlln*) malloc(sizeof(struct dlln));
    seventh->data = 7;

    struct dlln* eighth = (struct dlln*) malloc(sizeof(struct dlln));
    eighth->data = 8;

    dll_insertAfter(fifth, seventh);
    dll_traverseForwards(dll);
    dll_insertAfter(second, eighth);
    dll_traverseForwards(dll);
    dll_traverseBackwards(dll);
    dll_traverseForwards(dll);

    dll_removeAfter(eighth);
    dll_removeAfter(seventh);
    dll_removeAfter(sixth);
    dll_removeAfter(fourth);

    dll_traverseForwards(dll);
    dll_traverseBackwards(dll);

    dll_removeBeginning(dll);
    dll_traverseForwards(dll);
    dll_removeBeginning(dll);
    dll_traverseForwards(dll);

    dll_free(dll);
}
// ---------------------------------------------------------