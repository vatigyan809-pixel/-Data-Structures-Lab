
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to input square matrix elements
void inputMatrix(int a[MAX][MAX], int n)
{
    int i, j;

    printf("Enter matrix elements:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to calculate the diagonal sum difference
int diagonalDifference(int a[MAX][MAX], int n)
{
    int i;
    int primarySum = 0;
    int secondarySum = 0;

    // Calculate both diagonal sums
    for (i = 0; i < n; i++)
    {
        primarySum += a[i][i];
        secondarySum += a[i][n - 1 - i];
    }

    // Return the absolute difference
    return abs(primarySum - secondarySum);
}

int main()
{
    int a[MAX][MAX], n, difference;

    // Input the order of the square matrix
    printf("Enter order of square matrix (1-10): ");
    scanf("%d", &n);

    // Validate the matrix order
    if (n < 1 || n > MAX)
    {
        printf("Invalid matrix order!\n");
        return 0;
    }

    // Input matrix elements
    inputMatrix(a, n);

    // Calculate the difference between diagonal sums
    difference = diagonalDifference(a, n);

    // Display the final result
    printf("Difference between diagonal sums: %d\n",
           difference);

    return 0;
}
