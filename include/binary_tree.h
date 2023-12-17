// https://en.wikipedia.org/wiki/Binary_tree

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Actual node structure for the binary tree.
struct btn {
    int ctx;
    struct btn* left;
    struct btn* right;
};

// Actual tree that stores root node.
typedef struct {
    struct btn* root;
} bt_t;

// ------------------------- TESTS -------------------------
void bt_test_0();
// ---------------------------------------------------------

#endif// !BINARY_TREE_H