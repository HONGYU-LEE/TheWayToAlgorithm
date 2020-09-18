
/*
给定一个由非负整数填充的m x n的二维数组，现在要从二维数组的左上角走到右下角，请找出路径上的所有数字之和最小的路径。
注意：你每次只能向下或向右移动。
https://www.nowcoder.com/practice/23462ed010024fcabb7dbd3df57c715e?tpId=46&tqId=29115&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        vector<vector<int>> dp(row, vector<int>(col, 0));
        //处理边界
        for(int i = 0; i < row; i++)
        {
            //碰到障碍直接中断
            if(obstacleGrid[i][0])
            {
                break;
            }
            dp[i][0] = 1;
        }
        
        for(int i = 0; i < col; i++)
        {
            if(obstacleGrid[0][i])
            {
                break;
            }
            dp[0][i] = 1;
        }    
        
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                //如果有障碍，说明该点不可达，直接为0
                if(obstacleGrid[i][j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                
            }
        }
        return dp[row - 1][col - 1];
    }
};