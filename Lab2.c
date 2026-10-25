
#include <stdio.h>

#define MAX 10

// Function to input matrix elements
void inputMatrix(int a[MAX][MAX], int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX],
                    int result[MAX][MAX],
                    int r1, int c1, int c2)
{
    int i, j, k;

    // Traverse each row of the first matrix
    for (i = 0; i < r1; i++)
    {
        // Traverse each column of the second matrix
        for (j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            // Calculate the product of row and column
            for (k = 0; k < c1; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int a[MAX][MAX], int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    // Input dimensions of both matrices
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Validate dimensions before using the arrays
    if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX ||
        r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX)
    {
        printf("Invalid matrix dimensions!\n");
        return 0;
    }

    // Check the multiplication condition
    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    // Input elements of both matrices
    printf("Enter first matrix elements:\n");
    inputMatrix(a, r1, c1);

    printf("Enter second matrix elements:\n");
    inputMatrix(b, r2, c2);

    // Perform matrix multiplication
    multiplyMatrix(a, b, result, r1, c1, c2);

    // Display the resultant matrix
    printf("Resultant matrix:\n");
    displayMatrix(result, r1, c2);

    return 0;
}
    

