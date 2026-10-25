
#include <stdio.h>
#include <stdlib.h>

// Define a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a value into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search for a value
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Find minimum node
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// Find maximum node
struct Node* findMax(struct Node* root) {
    while (root != NULL && root->right != NULL)
        root = root->right;

    return root;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Display elements in sorted order
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Free memory
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    struct Node* temp;

    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);

    printf("Inorder Traversal: ");
    inorder(root);

    temp = findMin(root);
    if (temp != NULL)
        printf("\nMinimum Value: %d", temp->data);

    temp = findMax(root);
    if (temp != NULL)
        printf("\nMaximum Value: %d", temp->data);

    if (search(root, 30) != NULL)
        printf("\n30 found in BST");
    else
        printf("\n30 not found in BST");

    root = deleteNode(root, 20);

    printf("\nAfter Deletion: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
