 
#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Find height and calculate diameter
int findHeight(struct TreeNode* root, int* diameter) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = findHeight(root->left, diameter);
    int rightHeight = findHeight(root->right, diameter);

    // Update the maximum diameter
    int currentDiameter = leftHeight + rightHeight;

    if (currentDiameter > *diameter) {
        *diameter = currentDiameter;
    }

    // Return the height of the current node
    return 1 + (leftHeight > rightHeight
                ? leftHeight : rightHeight);
}

// Calculate the diameter of the tree
int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;

    findHeight(root, &diameter);

    return diameter;
}

// Free memory
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    // Create the example binary tree
    struct TreeNode* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Display the diameter
    printf("Diameter of Binary Tree: %d\n",
           diameterOfBinaryTree(root));

    freeTree(root);

    return 0;
}
