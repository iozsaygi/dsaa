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

// Allocates resources for binary tree.
bt_t* bt_allocate();

// Traverses the binary tree by using pre-order ruleset.
void bt_preOrderTraversal(const struct btn* root);

// Adds given value into the binary tree as node.
struct btn* bt_insert(bt_t* bt, int ctx);

// Recursively removes the node with given value from binary tree.
struct btn* bt_remove(struct btn* root, int ctx);

// Clears allocated resources for binary tree nodes.
void bt_freeNodes(struct btn* root);

// Clears the allocated resources for actual tree.
void bt_free(bt_t* bt);

// ------------------------- TESTS -------------------------
void bt_test_0();
// ---------------------------------------------------------

#endif// !BINARY_TREE_H