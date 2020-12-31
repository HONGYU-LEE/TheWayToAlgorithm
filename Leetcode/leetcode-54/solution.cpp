class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
        {
            return {};
        }
        vector<int> res;
        int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
        
        //每轮输出一圈
        while(1)
        {
            //从左向右
            for(int i = left; i <= right; i++)
            {
                res.push_back(matrix[up][i]++);
            }
            if(++up > down)
            {
                break;
            }

            //从上往下
            for(int i = up; i <= down; i++)
            {
                res.push_back(matrix[i][right]);
            }
            if(--right < left)
            {
                break;
            }

            //从右往左
            for(int i = right; i >= left; i--)
            {
                res.push_back(matrix[down][i]);
            }
            if(--down < up)
            {
                break;
            }

            //从下往上
            for(int i = down; i >= up; i--)
            {
                res.push_back(matrix[i][left]);
            }
            if(++left > right)
            {
                break;
            }
        }
        return res;
    }
};