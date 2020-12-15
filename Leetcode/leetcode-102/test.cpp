class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();
            while(size--)
            {  
                TreeNode* node = q.front();
                level.push_back(node->val);
                q.pop();

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ret.push_back(level);     
        }
        return ret;
    }
};
