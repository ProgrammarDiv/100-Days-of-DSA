#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int isMirror(struct Node* t1, struct Node* t2) {
    if(t1 == NULL && t2 == NULL)
        return 1;

    if(t1 == NULL || t2 == NULL)
        return 0;

    if(t1->data != t2->data)
        return 0;

    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    if(root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}
