 
#include <stdio.h>
#include <stdlib.h>

// Structure to create a linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode;

    // Allocate memory for a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Initialize node data and link
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a node at the end
void insertEnd(struct Node **head, int value)
{
    struct Node *newNode, *temp;

    newNode = createNode(value);

    if (newNode == NULL)
        return;

    // If the list is empty, make this the first node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = newNode;
}

// Function to reverse the linked list
struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    // Reverse the links of all nodes
    while (current != NULL)
    {
        // Save the address of the next node
        next = current->next;

        // Reverse the current node's link
        current->next = prev;

        // Move prev and current one step forward
        prev = current;
        current = next;
    }

    // Return the new head of the reversed list
    return prev;
}

// Function to display the linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Function to free allocated memory
void freeList(struct Node *head)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    int n, i, value;

    // Input the number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid number of nodes!\n");
        return 0;
    }

    // Create the linked list
    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        insertEnd(&head, value);
    }

    // Display the original linked list
    printf("Original Linked List: ");
    display(head);

    // Reverse the linked list
    head = reverseList(head);

    // Display the reversed linked list
    printf("Reversed Linked List: ");
    display(head);

    // Release memory
    freeList(head);

    return 0;
}

