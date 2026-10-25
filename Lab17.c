
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void createGraph(void) {
    int edges, u, v, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of vertices!\n");
        n = 0;
        return;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0) {
        printf("Invalid number of edges!\n");
        n = 0;
        return;
    }

    for (i = 0; i < edges; i++) {
        printf("Enter edge (u v), vertices 0 to %d: ", n - 1);
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge! Try again.\n");
            i--;
            continue;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

void DFS(int v) {
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

int main(void) {
    int start, i;

    createGraph();

    if (n == 0)
        return 1;

    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    printf("\nEnter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    BFS(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
