
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));

    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + (left > right ? left : right);
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct TreeNode *root = createNode(3);

    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    printf("Maximum Depth: %d\n", maxDepth(root));

    freeTree(root);
    return 0;
}
