int treeSize(struct TreeNode* root)
{
    if(root == NULL)
		 return 0;
    return 1 + treeSize(root->right) + treeSize(root->left);

}



void _preorderTraversal(struct TreeNode* root, int* pretree, int* i)

{
    if(root == NULL)
        return;

    pretree[(*i)++] = root->val;
    _preorderTraversal(root->left, pretree, i);
    _preorderTraversal(root->right, pretree, i);
}



int* preorderTraversal(struct TreeNode* root, int* returnSize){

    int size = treeSize(root), i = 0;
    int *pretree = (int*)malloc(sizeof(int) * size);
    *returnSize = size;

    _preorderTraversal(root, pretree, &i);

    return pretree;

}
