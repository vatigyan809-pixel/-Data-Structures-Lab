
#include <stdio.h>

#define ROWS 4
#define COLS 5

void dfs(char grid[ROWS][COLS], int r, int c) {
    if (r < 0 || r >= ROWS ||
        c < 0 || c >= COLS ||
        grid[r][c] != '1') {
        return;
    }

    grid[r][c] = '0';

    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

int numIslands(char grid[ROWS][COLS]) {
    int i, j, count = 0;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main(void) {
    char grid[ROWS][COLS] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    printf("Number of Islands: %d\n", numIslands(grid));

    return 0;
}
