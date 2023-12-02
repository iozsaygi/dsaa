// https://en.wikipedia.org/wiki/Cycle_detection

#ifndef FLOYD_TORTOISE_HARE
#define FLOYD_TORTOISE_HARE

// Basic node struct.
struct node {
    int data;
    struct node* next;
};

int fth_hasCycle(struct node* head);

// ------------------------- TESTS -------------------------
void fth_test_0();
// ---------------------------------------------------------

#endif//! FLOYD_TORTOISE_HARE