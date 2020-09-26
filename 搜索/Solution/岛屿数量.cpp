/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
*/

class Solution {
public:
    //向量矩阵
    int nextPos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void DFS(vector<vector<char>>& grid,  vector<vector<bool>>& visited, 
int row, int col, int sr, int sc)
    {
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
            if(grid[newRow][newCol] == '1' && visited[newRow][newCol])
            {
                DFS(grid, visited, row, col, newRow, newCol);
            }
        }    
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, true)); //标记矩阵
        int count = 0;

        //当找到陆地，并且没有被标记时，说明这是一个岛屿，进行搜索后，统计岛屿数量
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1' && visited[i][j])
                {
                    count++;
                    DFS(grid, visited, row, col, i, j);    
                }
            }
        }
        return count;
    }
};