#include <stdio.h>

#define MAX_NODES 8
#define INFINITY 1000000000

int n = 8;
int graph[MAX_NODES][MAX_NODES] = {
    {0, 2, INFINITY, INFINITY, INFINITY, INFINITY, 6, INFINITY},
    {2, 0, 7, INFINITY, 2, INFINITY, INFINITY, INFINITY},
    {INFINITY, 7, 0, 3, INFINITY, 3, INFINITY, INFINITY},
    {INFINITY, INFINITY, 3, 0, INFINITY, INFINITY, INFINITY, 2},
    {INFINITY, 2, INFINITY, INFINITY, 0, 2, 1, INFINITY},
    {INFINITY, INFINITY, 3, INFINITY, 2, 0, INFINITY, 4},
    {6, INFINITY, INFINITY, INFINITY, 1, INFINITY, 0, 4},
    {INFINITY, INFINITY, INFINITY, 2, INFINITY, 2, 4, 0}
};

void shortest_path(int s, int t, int path[], int *mincost);

int main() {
    int source = 0;
    int destination = 3;
    int path[MAX_NODES];
    int mincost;

    shortest_path(source, destination, path, &mincost);

    printf("Shortest Path from %d to %d: ", source, destination);
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i]);
        if(path[i]==destination){
            break;
        }
    }

    printf("\nMinimum Cost: %d\n", mincost);

    return 0;
}

void shortest_path(int s, int t, int path[], int *mincost) {
    struct state {
        int predecessor;
        int length;
        enum {permanent, tentative} label;
    };

    struct state state[MAX_NODES];

    int i, k, min;
    struct state *p;

    // Initialize state
    for (p = &state[0]; p < &state[n]; p++) {
        p->predecessor = -1;
        p->length = INFINITY;
        p->label = tentative;
    }

    state[t].length = 0;
    state[t].label = permanent;

    // Main loop
    k = t;
    do {
        // Update tentative distances
        for (i = 0; i < n; i++) {
            if (graph[k][i] > 0 && state[i].label == tentative) {
                if (state[k].length + graph[k][i] < state[i].length) {
                    state[i].predecessor = k;
                    state[i].length = state[k].length + graph[k][i];
                }
            }
        }

        // Find the tentatively labeled node with the smallest label
        k = 0;
        min = INFINITY;

        for (i = 0; i < n; i++) {
            if (state[i].label == tentative && state[i].length < min) {
                min = state[i].length;
                k = i;
            }
        }

        // Mark the node as permanent
        state[k].label = permanent;
    } while (k != s);

    // Copy the path into the output array
    i = 0;
    k = s;
    do {
        path[i++] = k;
        k = state[k].predecessor;
    } while (k >= 0);

    // Calculate and return the minimum cost
    *mincost = state[s].length;
}
