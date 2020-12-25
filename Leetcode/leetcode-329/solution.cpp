class Solution {
public:
    int nextPos[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int row, int col)
    {
        //已经访问过了则直接返回记忆化的结果
        if(memo[row][col] != 0)
        {
            return memo[row][col];
        }
        memo[row][col]++;

        for(int i = 0; i < 4; i++)
        {
            int newRow = row + nextPos[i][0], newCol = col + nextPos[i][1];

            if((newRow < matrix.size() && newRow >= 0 && newCol < matrix[0].size() && newCol >= 0)
            && matrix[newRow][newCol] > matrix[row][col])
            {
                memo[row][col] = max(memo[row][col], dfs(matrix, memo, newRow, newCol) + 1);    //更新结果
            }
        }
        return memo[row][col];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int res = 0;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));  //为了防止大量的重复计算，使用矩阵来记忆化结果
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j  = 0; j < matrix[0].size(); j++)
            {
                res = max(res, dfs(matrix, memo, i, j));    //从每个位置开始搜索
            }
        }
        return res;
    }
};