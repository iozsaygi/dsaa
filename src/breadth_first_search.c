#include "breadth_first_search.h"
#include <stdlib.h>

struct bfs_node* bfs_createNode(int data) {
    struct bfs_node* node = (struct bfs_node*) malloc(sizeof(struct bfs_node));
    node->data = data;
    node->next = NULL;
    return node;
}

// ------------------------- TESTS -------------------------
void bfs_test_0() {
}
// ---------------------------------------------------------