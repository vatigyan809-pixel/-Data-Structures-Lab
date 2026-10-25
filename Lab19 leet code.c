
#include <stdio.h>

int findCenter(int edges[][2], int edgesSize) {
    if (edges[0][0] == edges[1][0] ||
        edges[0][0] == edges[1][1]) {
        return edges[0][0];
    }

    return edges[0][1];
}

int main(void) {
    int edges[][2] = {
        {1, 2},
        {2, 3},
        {4, 2}
    };

    int edgesSize = sizeof(edges) / sizeof(edges[0]);

    printf("Center of Star Graph: %d\n",
           findCenter(edges, edgesSize));

    return 0;
}
