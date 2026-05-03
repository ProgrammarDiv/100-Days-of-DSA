#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void zigzagTraversal(struct Node* root) {
    if(root == NULL) return;

    struct Node* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;

    int leftToRight = 1;

    while(front < rear) {
        int size = rear - front;
        int level[1000];

        for(int i = 0; i < size; i++) {
            struct Node* temp = q[front++];
            int index;

            if(leftToRight)
                index = i;
            else
                index = size - i - 1;

            level[index] = temp->data;

            if(temp->left != NULL)
                q[rear++] = temp->left;
            if(temp->right != NULL)
                q[rear++] = temp->right;
        }

        for(int i = 0; i < size; i++)
            printf("%d ", level[i]);

        leftToRight = !leftToRight;
    }
}
