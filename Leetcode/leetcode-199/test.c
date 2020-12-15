/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 1000

void DFS(struct TreeNode* root, int* path, int deep, int* row)
{
    if(root != NULL)
    {
        path[deep] = root->val;
        if(*row < deep + 1)
            *row = deep + 1;
    
	    DFS(root->left,path,deep +1,row);
    	DFS(root->right, path, deep + 1, row);
    }
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    int *path = (int*)malloc(sizeof(int) * MAXSIZE);
    int row = 0;
    memset(path, 0, sizeof(int) * MAXSIZE);

    DFS(root, path, 0 , &row);

    *returnSize = row;
    return path;

}



