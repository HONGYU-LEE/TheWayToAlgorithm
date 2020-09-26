/*
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
*/
class Solution {
public:
    //向量矩阵
    int nextPos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void DFS(vector<vector<int>>& grid,  vector<vector<bool>>& visited, int& count,
int row, int col, int sr, int sc)
    {
        count++;
        visited[sr][sc] = false;

        //向上下左右四个方向进行搜索
        for(int i = 0; i < 4; i++)
        {
            int newRow = sr + nextPos[i][0];
            int newCol = sc + nextPos[i][1];
            
            //如果越界则跳过
            if(newRow < 0 || newRow >= row || newCol < 0 || newCol >= col)
            {
                continue;
            }

            //如果该位置为老颜色，并且没有渲染过则进行渲染
            if(grid[newRow][newCol] == 1 && visited[newRow][newCol])
            {
                DFS(grid, visited, count, row, col, newRow, newCol);
            }
        }    
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, true)); //标记矩阵
        int max = 0; 

        //当找到陆地，并且没有被标记时，说明这是一个岛屿，进行搜索后，统计岛屿数量
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1 && visited[i][j])
                {
                    int count = 0;
                    DFS(grid, visited, count, row, col, i, j);
                    max = max > count ? max : count;
                }
            }
        }
        return max;
    }
};