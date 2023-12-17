#include "binary_tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

bt_t* bt_allocate() {
    bt_t* bt = (bt_t*) malloc(sizeof(bt_t));
    assert(bt != NULL);
    bt->root = NULL;
    return bt;
}

void bt_preOrderTraversal(const struct btn* root) {// NOLINT(*-no-recursion)
    if (root != NULL) {
        printf("%d ", root->ctx);
        bt_preOrderTraversal(root->left);
        bt_preOrderTraversal(root->right);
    }
}

struct btn* bt_insert(bt_t* bt, int ctx) {
    assert(bt != NULL);

    struct btn* btn = (struct btn*) malloc(sizeof(struct btn));
    btn->ctx = ctx;
    btn->left = NULL;
    btn->right = NULL;

    // Make the new allocated node root if the tree is empty.
    if (bt->root == NULL) {
        bt->root = btn;
        return btn;
    }

    struct btn* itr = bt->root;
    while (1) {
        if (ctx < itr->ctx) {
            // Place the element on the left branch.
            if (itr->left == NULL) {
                itr->left = btn;
                return btn;
            } else {
                itr = itr->left;
            }
        } else if (ctx > itr->ctx) {
            // Place the element on the right branch.
            if (itr->right == NULL) {
                itr->right = btn;
                return btn;
            } else {
                itr = itr->right;
            }
        } else {
            // Do not add node into tree because it is duplicate.
            free(btn);
            return NULL;
        }
    }
}

struct btn* bt_remove(struct btn* root, int ctx) {// NOLINT(*-no-recursion)
    if (root == NULL) {
        return NULL;
    }

    // Figure out branch to follow.
    if (ctx < root->ctx) {
        root->left = bt_remove(root->left, ctx);
    } else if (ctx > root->ctx) {
        root->right = bt_remove(root->right, ctx);
    } else {
        if (root->left == NULL) {
            struct btn* tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL) {
            struct btn* tmp = root->right;
            free(root);
            return tmp;
        }

        struct btn* itr = root->right;
        while (itr->left != NULL) {
            itr = itr->left;
        }

        root->ctx = itr->ctx;
        root->right = bt_remove(root->right, itr->ctx);
    }

    return root;
}

void bt_freeNodes(struct btn* root) {// NOLINT(*-no-recursion)
    if (root != NULL) {
        bt_freeNodes(root->left);
        bt_freeNodes(root->right);
        free(root);
    }
}

void bt_free(bt_t* bt) {
    assert(bt != NULL);
    free(bt);
}

// ------------------------- TESTS -------------------------
void bt_test_0() {
    bt_t* bt = bt_allocate();

    bt_preOrderTraversal(NULL);

    struct btn* first = bt_insert(bt, 3);
    struct btn* second = bt_insert(bt, 1);
    struct btn* third = bt_insert(bt, 7);
    struct btn* fourth = bt_insert(bt, 2);
    struct btn* fifth = bt_insert(bt, 9);
    struct btn* sixth = bt_insert(bt, 10);
    struct btn* seventh = bt_insert(bt, 8);

    bt_preOrderTraversal(first);
    printf("\n------------------------------\n");

    bt_remove(first, 7);
    bt_remove(first, -4);
    bt_remove(first, 2);
    bt_remove(first, 10);

    bt_preOrderTraversal(first);
    printf("\n------------------------------\n");

    bt_freeNodes(first);
    bt_free(bt);
}
// ---------------------------------------------------------