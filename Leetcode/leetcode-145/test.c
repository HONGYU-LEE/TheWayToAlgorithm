int treesize(struct TreeNode* root)
{
    if(!root)
        return 0;

    return 1 + treesize(root->right) + treesize(root->left);    
}

void _postorderTraversal(struct TreeNode* root,int* postordertree, int* i)
{
    if(!root)
        return;

    _postorderTraversal(root->left, postordertree, i);
    _postorderTraversal(root->right, postordertree, i);
    postordertree[(*i)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){

    int size = treesize(root), i = 0;
    *returnSize = size;
    int* postordertree = (int*)malloc(sizeof(int) * size);

    _postorderTraversal(root, postordertree, &i);

    return postordertree;
}
