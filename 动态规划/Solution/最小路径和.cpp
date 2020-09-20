/*
给定一个由非负整数填充的m x n的二维数组，现在要从二维数组的左上角走到右下角，请找出路径上的所有数字之和最小的路径。
注意：你每次只能向下或向右移动。
https://www.nowcoder.com/practice/23462ed010024fcabb7dbd3df57c715e?tpId=46&tqId=29115&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        //判空
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(grid);
        
        //赋初值
        for(int i = 1; i < row; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < col; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};