struct Node* LCA(struct Node* root, int n1, int n2) {
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;

    return right;
}
