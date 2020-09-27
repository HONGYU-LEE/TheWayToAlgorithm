/*
给定一个 N 叉树，返回其节点值的*层序遍历*。 (即从左到右，逐层遍历)。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
        {
            return {};
        }

        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> level;  //当前层的所有结果

            int size = q.size();
            //遍历当前层
            while(size--)
            {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                
                //将下一层加入到队列末尾
                for(const auto& sub : cur->children)
                {
                    q.push(sub);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};