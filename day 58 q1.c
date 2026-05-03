#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findIndex(int inorder[], int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if(inStart > inEnd)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;
    struct Node* root = createNode(rootVal);

    if(inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
