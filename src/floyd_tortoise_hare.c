#include "floyd_tortoise_hare.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int fth_hasCycle(struct node* head) {
    if (head == NULL) return 0;

    struct node* slow = head;
    struct node* fast = head->next;

    while (slow != fast) {
        if (fast->next == NULL || fast->next->next == NULL) return 0;
        slow = slow->next;
        fast = fast->next->next;
    }

    return 1;
}

// ------------------------- TESTS -------------------------
void fth_test_0() {
    struct node* first = malloc(sizeof(struct node));
    struct node* second = malloc(sizeof(struct node));
    struct node* third = malloc(sizeof(struct node));

    first->next = second;
    second->next = third;
    third->next = NULL;

    assert(fth_hasCycle(first) == 0);

    third->next = first;
    assert(fth_hasCycle(first) == 1);

    first = NULL;
    assert(fth_hasCycle(first) == 0);
}
// ---------------------------------------------------------