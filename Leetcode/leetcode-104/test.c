/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(root ==  NULL)
        return 0;
    
    int right_high = maxDepth(root->right);
    int left_high = maxDepth(root->left);

    return right_high < left_high ? left_high + 1 : right_high + 1;
}
