#include <stdio.h>
#include <limits.h>

#define MAX 100

void prim(int graph[MAX][MAX], int n) {
    int near[MAX];  // nearest neighbor array
    int tree[MAX - 1][2];  // to store the edges of the minimum spanning tree

    // Find the initial minimum cost edge
    int mincost = INT_MAX;
    int p, q;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (graph[i][j] < mincost) {
                mincost = graph[i][j];
                p = i;
                q = j;
            }
        }
    }

    // Set the initial vertices of the tree
    tree[0][0] = p;
    tree[0][1] = q;

    // Set initial near values and mark p and q as included in the tree
    for (int i = 1; i <= n; i++) {
        if (graph[i][p] < graph[i][q]) {
            near[i] = p;
        } else {
            near[i] = q;
        }
    }
    near[p] = near[q] = 0;

    // Main loop to find the remaining edges
    for (int i = 1; i <= n - 2; i++) {
        // Find the vertex j such that near[j] != 0 and cost[j][near[j]] is minimum
        int j = 1;
        while (near[j] == 0) {
            j++;
        }
        for (int k = j + 1; k <= n; k++) {
            if (near[k] != 0 && graph[k][near[k]] < graph[j][near[j]]) {
                j = k;
            }
        }

        // Add the edge (j, near[j]) to the tree
        tree[i][0] = j;
        tree[i][1] = near[j];
        mincost += graph[j][near[j]];
        near[j] = 0;

        // Update near values
        for (int k = 1; k <= n; k++) {
            if (near[k] != 0 && graph[k][near[k]] > graph[k][j]) {
                near[k] = j;
            }
        }
    }

    // Output the minimum cost and the minimum spanning tree
    printf("Minimum Cost: %d\n", mincost);
    printf("Edges of Minimum Spanning Tree:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d - %d\n", tree[i][0], tree[i][1]);
    }
}

int main() {
    int graph[MAX][MAX];
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, n);

    return 0;
}
