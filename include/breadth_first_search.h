// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

struct bfs_node {
    int data;
    struct bfs_node* next;
};

struct bfs_list {
    struct bfs_node* head;
};

struct bfs_graph {
    int nodeCount;
    struct bfs_list* list;
};

// Creates node to be used during search.
struct bfs_node* bfs_createNode(int data);

// Creates the graph with the given node count.
struct bfs_graph* bfs_createGraph(int nodeCount);

// ------------------------- TESTS -------------------------
void bfs_test_0();
// ---------------------------------------------------------

#endif// !BREADTH_FIRST_SEARCH_H