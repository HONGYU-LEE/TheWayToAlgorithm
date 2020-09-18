/*
一个机器人在m×n大小的地图的左上角（起点，下图中的标记“start"的位置）。
机器人每次向下或向右移动。机器人要到达地图的右下角。（终点，下图中的标记“Finish"的位置）。
可以有多少种不同的路径从起点走到终点？
https://www.nowcoder.com/practice/166eaff8439d4cd898e3ba933fbc6358?tpId=46&tqId=29117&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!m || !n)
        {
            return false;
        }
        
        //考虑到处理边界较为麻烦，直接全体初始化为1
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};