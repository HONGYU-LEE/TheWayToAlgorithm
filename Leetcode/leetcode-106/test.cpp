/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& postIndex, int inBegin, int inEnd) 
    {
        if(inBegin > inEnd)
            return nullptr;

        int rootIndex = inEnd;
        TreeNode* root = new TreeNode(postorder[postIndex]);

        //根据后序遍历的根节点来划分左右子树
        while(rootIndex >= inBegin)
        {
            if(postorder[postIndex] == inorder[rootIndex])
                break;
            else 
                rootIndex--;
        }

        //左子树为(inBegin, rootIndex - 1) 右子树(rootIndex + 1, inEnd)

        //构建右子树
        if(rootIndex + 1 <= inEnd)
            root->right = _buildTree(inorder, postorder, --postIndex, rootIndex + 1, inEnd);
        else 
            root->right = nullptr;
            
        //构建左子树
        if(inBegin <= rootIndex - 1)
            root->left = _buildTree(inorder, postorder, --postIndex, inBegin, rootIndex - 1);
        else 
            root->left = nullptr;


        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int postIndex = postorder.size() - 1;
        int inBegin = 0, inEnd = inorder.size() - 1;

        return _buildTree(inorder, postorder, postIndex, inBegin, inEnd);
    }
};
