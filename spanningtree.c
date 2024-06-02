#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure to represent a node in the graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    Node* adjacencyList[MAX_NODES];
} Graph;

// Function to add an edge to the graph
void addEdge(Graph* graph, int node1, int node2) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = node2;
    newNode->next = graph->adjacencyList[node1];
    graph->adjacencyList[node1] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = node1;
    newNode->next = graph->adjacencyList[node2];
    graph->adjacencyList[node2] = newNode;
}

// Function to perform depth-first search and construct a spanning tree
void dfs(Graph* graph, int start, bool visited[MAX_NODES], Graph* spanningTree) {
    visited[start] = true;
    Node* current = graph->adjacencyList[start];
    while (current != NULL) {
        if (!visited[current->data]) {
            addEdge(spanningTree, start, current->data);
            dfs(graph, current->data, visited, spanningTree);
        }
        current = current->next;
    }
}

// Function to construct a spanning tree
Graph constructSpanningTree(Graph* graph) {
    Graph spanningTree;
    for (int i = 0; i < MAX_NODES; ++i) {
        spanningTree.adjacencyList[i] = NULL;
    }

    bool visited[MAX_NODES] = {false};
    dfs(graph, 0, visited, &spanningTree);

    return spanningTree;
}

// Function to prune the tree based on group membership
void pruneTree(Graph* spanningTree, char groupMembership[MAX_NODES], char targetGroup) {
    for (int i = 0; i < MAX_NODES; ++i) {
        if (groupMembership[i] == targetGroup) {
            Node* current = spanningTree->adjacencyList[i];
            while (current != NULL) {
                if (groupMembership[current->data] != targetGroup) {
                    // Remove the edge from the pruned tree
                    // (Note: This is a simple example; a more sophisticated implementation may involve a proper data structure)
                    current->data = -1;
                }
                current = current->next;
            }
        }
    }
}

// Function to display a graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < MAX_NODES; ++i) {
        Node* current = graph->adjacencyList[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    for (int i = 0; i < MAX_NODES; ++i) {
        graph.adjacencyList[i] = NULL;
    }

    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 4, 5);
    addEdge(&graph, 4, 6);

    char groupMembership[MAX_NODES] = {'A', 'A', 'B', 'B', 'B', 'A'};

    printf("Original Graph:\n");
    displayGraph(&graph);

    Graph spanningTree = constructSpanningTree(&graph);
    printf("\nOriginal Spanning Tree:\n");
    displayGraph(&spanningTree);

    char targetGroup;
    printf("\nEnter the group to prune the tree: ");
    scanf(" %c", &targetGroup);

    pruneTree(&spanningTree, groupMembership, targetGroup);
    printf("\nPruned Spanning Tree:\n");
    displayGraph(&spanningTree);

    return 0;
}
