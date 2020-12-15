/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 二叉搜索树时如果两个节点一个比根节点大，一个比根节点小，则根节点则是公共祖先。
 如果都比根节点大，则说明都在右子树上。而都比根节点小，则说明都在左子树上。 
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        else if(p == root || q == root)
            return root;

        if((root->val > p->val && root->val < q->val) || (root->val > q->val && root->val < p->val))
            return root;
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p ,q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        return nullptr;
    }
};
