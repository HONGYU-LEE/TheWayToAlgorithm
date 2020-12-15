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
 求公共祖先有三种情况
 二叉搜索树时如果两个节点一个比根节点大，一个比根节点小，则根节点则是公共祖先。
 对于三叉链来说，则直接找到交点即可
 而普通的二叉树，则两个节点一个要在根节点的左子树，一个要在根节点的右子树。
 */
class Solution {
public:
    bool Find(TreeNode* root, TreeNode* cur)
    {
        if(root == nullptr)
            return false;
        else if(root == cur)
            return true;

        return Find(root->left, cur) || Find(root->right, cur);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;

        //如果任意一个节点为根节点，那么最近公共祖先必定为根节点
        if(root == p || root == q)
            return root;

        //查找p和q分别在哪个子树上
        bool pInLeft = Find(root->left, p);
        bool pInRight = !pInLeft;
        bool qInLeft = Find(root->left, q);
        bool qInRight = !qInLeft;

        //如果p和q分别在根节点的左右子树上，则根节点为最近公共祖先
        if((pInLeft && qInRight) || (pInRight && qInLeft))
            return root;
        //都在左子树上，则进入左子树继续找
        else if(pInLeft && qInLeft)
            return lowestCommonAncestor(root->left, p, q);
        //如果都在右子树上则进入右子树继续找
        else if(qInRight && pInRight)
            return lowestCommonAncestor(root->right, p, q);

        //没找到，返回空
        return nullptr;
    }
};
