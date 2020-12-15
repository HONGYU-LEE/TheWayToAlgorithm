int treesize(struct TreeNode* root)
{
    if(!root)
        return 0;

    return 1 + treesize(root->right) + treesize(root->left);    
}

void _inorderTraversal(struct TreeNode* root,int* inordertree, int* i)
{
    if(!root)
        return;

    _inorderTraversal(root->left, inordertree, i);
    inordertree[(*i)++] = root->val;
    _inorderTraversal(root->right, inordertree, i);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){

    int size = treesize(root), i = 0;
    *returnSize = size;
    int* inordertree = (int*)malloc(sizeof(int) * size);

    _inorderTraversal(root, inordertree, &i);

    return inordertree;
}
