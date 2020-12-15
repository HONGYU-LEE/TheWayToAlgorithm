/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return NULL;

    TreeNode* right = invertTree(root->right);
    TreeNode* left = invertTree(root->left);

    root->right = left;
    root->left = right;

    return root; 
}
