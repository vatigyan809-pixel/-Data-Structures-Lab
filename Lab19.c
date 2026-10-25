
#include <stdio.h>

#define MAX 20
#define INF 999999

int main(void) {
    int graph[MAX][MAX];
    int distance[MAX], visited[MAX] = {0};
    int n, source, i, j;
    int min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("Enter weighted adjacency matrix:\n");
    printf("Enter 0 where there is no edge.\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        distance[i] = INF;
    }

    distance[source] = 0;

    for (i = 0; i < n; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] > 0 &&
                distance[u] + graph[u][j] < distance[j]) {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (distance[i] == INF) {
            printf("To vertex %d: Unreachable\n", i);
        } else {
            printf("To vertex %d: %d\n", i, distance[i]);
        }
    }

    return 0;
}
