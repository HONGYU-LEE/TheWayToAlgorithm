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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inBegin, int inEnd) 
    {
        if(inBegin > inEnd)
            return nullptr;

        //前序的第一个节点就是中序的根节点
        TreeNode* Inroot = new TreeNode(preorder[preIndex]);

        //通过根节点来划分左右子树
        int rootIndex = inBegin;
        while(rootIndex <= inEnd)
        {
            if(inorder[rootIndex] == preorder[preIndex])
                break;
            else 
                rootIndex++;
        }

        //此时找到根节点的位置，根节点的左边(inBegin, rootIndex - 1)则是左子树，右边(rootIndex + 1, inEnd)则是右子树。
        //构建左子树，如果在范围内则递归构建，不在范围内说明没有左子树
        if(inBegin <= rootIndex -1)
            Inroot->left = _buildTree(preorder, inorder, ++preIndex, inBegin, rootIndex - 1);
        else 
            Inroot->left = nullptr;

        //构建右子树
        if(rootIndex + 1 <= inEnd)
            Inroot->right = _buildTree(preorder, inorder, ++preIndex, rootIndex + 1, inEnd);
        else 
            Inroot->right = nullptr;

        return Inroot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex = 0;
        int inBegin = 0, inEnd = inorder.size() - 1;

        return _buildTree(preorder, inorder, preIndex, inBegin, inEnd);
    }
};
