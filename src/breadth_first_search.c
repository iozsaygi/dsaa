#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
    assert(graph != NULL);

    struct bfs_node* node = bfs_createNode(destination);
    node->next = graph->list[source].head;
    graph->list[source].head = node;

    node = bfs_createNode(source);
    node->next = graph->list[destination].head;
    graph->list[destination].head = node;
}

void bfs_execute(struct bfs_graph* graph, int startingNode) {
    assert(graph != NULL);
    assert(startingNode >= 0);

    bool* visited = (bool*) malloc(graph->nodeCount * sizeof(bool));
    for (int i = 0; i < graph->nodeCount; i++) {
        visited[i] = false;
    }

    int* queue = (int*) malloc(graph->nodeCount * sizeof(int));
    int front = 0, rear = 0;

    visited[startingNode] = true;
    queue[rear++] = startingNode;

    while (front < rear) {
        int currentNode = queue[front++];

        struct bfs_node* temp = graph->list[currentNode].head;
        while (temp != NULL) {
            int adjNode = temp->data;
            if (!visited[adjNode]) {
                visited[adjNode] = true;
                queue[rear++] = adjNode;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

// ------------------------- TESTS -------------------------
void bfs_test_0() {
    int nodeCount = 6;
    struct bfs_graph* graph = bfs_createGraph(nodeCount);
    bfs_addEdge(graph, 0, 1);
    bfs_addEdge(graph, 0, 2);
    bfs_addEdge(graph, 1, 3);
    bfs_addEdge(graph, 1, 4);
    bfs_addEdge(graph, 2, 4);
    bfs_addEdge(graph, 3, 4);
    bfs_addEdge(graph, 3, 5);
    bfs_addEdge(graph, 4, 5);

    bfs_execute(graph, 0);

    free(graph);
}
// ---------------------------------------------------------