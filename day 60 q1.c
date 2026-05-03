#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int isMinHeap(struct Node* root) {
    if(root == NULL)
        return 1;

    if(root->left != NULL && root->data > root->left->data)
        return 0;

    if(root->right != NULL && root->data > root->right->data)
        return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}
