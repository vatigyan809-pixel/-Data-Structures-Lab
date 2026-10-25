
#include <stdio.h>

#define MAX 100

// Function to display array elements
void display(int a[], int n)
{
    int i;

    printf("Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to insert an element at the beginning
void insertBeginning(int a[], int *n)
{
    int i, value;

    if (*n >= MAX)
    {
        printf("Array is full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    // Shift elements towards the right
    for (i = *n; i > 0; i--)
    {
        a[i] = a[i - 1];
    }

    a[0] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

// Function to insert an element at the end
void insertEnd(int a[], int *n)
{
    int value;

    if (*n >= MAX)
    {
        printf("Array is full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    // Store the element at the last position
    a[*n] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

// Function to insert an element at any position
void insertPosition(int a[], int *n)
{
    int i, pos, value;

    if (*n >= MAX)
    {
        printf("Array is full!\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *n + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    // Shift elements to make space
    for (i = *n; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }

    a[pos - 1] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

// Function to delete the first element
void deleteBeginning(int a[], int *n)
{
    int i;

    if (*n == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    // Shift remaining elements to the left
    for (i = 0; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully.\n");
}

// Function to delete the last element
void deleteEnd(int *n)
{
    if (*n == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    // Reduce the logical size of the array
    (*n)--;

    printf("Element deleted successfully.\n");
}

// Function to delete an element at any position
void deletePosition(int a[], int *n)
{
    int i, pos;

    if (*n == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *n)
    {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to fill the deleted position
    for (i = pos - 1; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully.\n");
}

int main()
{
    int a[MAX], n, i, choice;

    // Read the initial array size
    printf("Enter array size (0 to 100): ");
    scanf("%d", &n);

    if (n < 0 || n > MAX)
    {
        printf("Invalid array size!\n");
        return 0;
    }

    // Read array elements
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Display the menu until the user exits
    do
    {
        printf("\n--- ARRAY OPERATIONS ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Position\n");
        printf("7. Display Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function
        if (choice == 1)
            insertBeginning(a, &n);
        else if (choice == 2)
            insertEnd(a, &n);
        else if (choice == 3)
            insertPosition(a, &n);
        else if (choice == 4)
            deleteBeginning(a, &n);
        else if (choice == 5)
            deleteEnd(&n);
        else if (choice == 6)
            deletePosition(a, &n);
        else if (choice == 7)
            display(a, n);
        else if (choice == 0)
            printf("Program terminated.\n");
        else
            printf("Invalid choice!\n");

    } while (choice != 0);

    return 0;
}
