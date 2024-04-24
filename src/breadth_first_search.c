#include "breadth_first_search.h"
#include <assert.h>
#include <stdlib.h>

struct bfs_node* bfs_createNode(int data) {
    struct bfs_node* node = (struct bfs_node*) malloc(sizeof(struct bfs_node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct bfs_graph* bfs_createGraph(int nodeCount) {
    assert(nodeCount >= 0);

    struct bfs_graph* graph = (struct bfs_graph*) malloc(sizeof(struct bfs_graph));
    graph->nodeCount = nodeCount;
    graph->list = (struct bfs_list*) malloc(nodeCount * sizeof(struct bfs_list));

    for (int i = 0; i < nodeCount; i++) {
        graph->list[i].head = NULL;
    }

    return graph;
}

void bfs_addEdge(struct bfs_graph* graph, int source, int destination) {
    struct bfs_node* node = bfs_createNode(destination);
    node->next = graph->list[source].head;
    graph->list[source].head = node;

    node = bfs_createNode(source);
    node->next = graph->list[destination].head;
    graph->list[destination].head = node;
}

// ------------------------- TESTS -------------------------
void bfs_test_0() {
}
// ---------------------------------------------------------