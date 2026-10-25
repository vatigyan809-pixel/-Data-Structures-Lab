
#include <stdio.h>

#define MAX 20
#define INF 999999

int main(void) {
    int cost[MAX][MAX];
    int selected[MAX] = {0};
    int n, i, j;
    int edges = 0;
    int totalCost = 0;
    int min, u = -1, v = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("Enter weighted adjacency matrix:\n");
    printf("Enter 0 if there is no edge.\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    selected[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;
        u = -1;
        v = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] &&
                        cost[i][j] > 0 &&
                        cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            printf("Graph is not connected!\n");
            return 1;
        }

        printf("%d - %d : %d\n", u, v, min);

        selected[v] = 1;
        totalCost += min;
        edges++;
    }

    printf("Minimum Cost of MST: %d\n", totalCost);

    return 0;
}
