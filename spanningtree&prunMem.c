/*#include <stdio.h>
#include <limits.h>

#define MAX 100

void printSpanningTree(int tree[MAX - 1][2], int mincost, int n, int queryMembership,int membership[MAX]) {
    printf("Minimum Cost: %d\n", mincost);
    printf("Edges of Minimum Spanning Tree:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d - %d\n", tree[i][0], tree[i][1]);
    }

    // Prune the tree based on the specified group membership
 

    // Prune the tree based on the specified group membership
    printf("\nPruned Tree within Group %d:\n", queryMembership);
    for (int i = 0; i < n - 1; i++) {
        if ((tree[i][0] != 0 && tree[i][1] != 0) &&
            (membership[tree[i][0]] == queryMembership && membership[tree[i][1]] != queryMembership)) {
            printf("%d - %d\n", tree[i][0], tree[i][1]);
        }
    }
}

void prim(int graph[MAX][MAX], int membership[MAX], int n, int queryMembership) {
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

    // Output the initial spanning tree
    printSpanningTree(tree, mincost, n, queryMembership, membership);
}

int main() {
    int graph[MAX][MAX];
    int membership[MAX];
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the group membership for each vertex:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &membership[i]);
    }

    int queryMembership;
    printf("\nEnter the group membership for pruning: ");
    scanf("%d", &queryMembership);

    prim(graph, membership, n, queryMembership);

    return 0;
}
*/
#include <stdio.h>
#include <limits.h>

#define MAX 100

int search(int arr[2], int a) {
    for (int i = 0; i < 2; i++) {
        if (arr[i] == a)
            return 1; // true
    }
    return 0; // false
}

void printSpanningTree(int tree[MAX - 1][2], int mincost, int n, int queryMembership, int membership[MAX][2]) {
    printf("Minimum Cost: %d\n", mincost);
    printf("Edges of Minimum Spanning Tree:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d - %d\n", tree[i][0], tree[i][1]);
    }

    // Prune the tree based on the specified group membership
    printf("\nPruned Tree within Group %d:\n", queryMembership);
    for (int i = 0; i < n - 1; i++) {
        if ((tree[i][0] != 0 && tree[i][1] != 0) &&
            (search(membership[tree[i][0]], queryMembership) && search(membership[tree[i][1]], queryMembership))) {
            printf("%d - %d\n", tree[i][0], tree[i][1]);
        }
    }
}

void prim(int graph[MAX][MAX], int membership[MAX][2], int n, int queryMembership) {
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

    // Output the initial spanning tree
    printSpanningTree(tree, mincost, n, queryMembership, membership);
}

int main() {
    int graph[MAX][MAX];
    int membership[MAX][2];
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the group membership for each vertex:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &membership[i][j]);
        }
    }

    int queryMembership;
    printf("\nEnter the group membership for pruning: ");
    scanf("%d", &queryMembership);

    prim(graph, membership, n, queryMembership);

    return 0;
}

