
#include <stdio.h>

#define MAX 200

int graph[MAX][MAX];
int visited[MAX];

int validPath(int n, int edges[][2], int edgesSize,
              int source, int destination) {
    int queue[MAX];
    int front = 0, rear = 0;
    int i, u, v;

    if (source == destination)
        return 1;

    for (i = 0; i < edgesSize; i++) {
        u = edges[i][0];
        v = edges[i][1];

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    queue[rear++] = source;
    visited[source] = 1;

    while (front < rear) {
        u = queue[front++];

        for (v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                if (v == destination)
                    return 1;

                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return 0;
}

int main(void) {
    int edges[][2] = {
        {0, 1}, {1, 2}, {2, 0}
    };

    int n = 3;
    int edgesSize = sizeof(edges) / sizeof(edges[0]);
    int source = 0;
    int destination = 2;

    if (validPath(n, edges, edgesSize, source, destination))
        printf("Path exists between %d and %d.\n",
               source, destination);
    else
        printf("Path does not exist between %d and %d.\n",
               source, destination);

    return 0;
}
