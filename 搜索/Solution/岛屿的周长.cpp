/*
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/island-perimeter
*/
class Solution {
public:
    //向量矩阵
    int nextPos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void DFS(vector<vector<int>>& grid,  vector<vector<bool>>& visited, int row, int col,
int& count, int sr, int sc)
    {   
        visited[sr][sc] = false;

        for(int i = 0; i < 4; i++)
        {
            int newRow = sr + nextPos[i][0];
            int newCol = sc + nextPos[i][1];
            
            //如果为边界或者为水域，则计数后跳过
            if(newRow < 0 || newRow >= row || newCol < 0 || newCol >= col || grid[newRow][newCol] == 0)
            {
                count++;
                continue;
            }

            if(grid[newRow][newCol] == 1 && visited[newRow][newCol])
            {
                DFS(grid, visited, row, col, count, newRow, newCol);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, true));
        int count = 0;

        //找到一个水池的边界，沿着边界搜索
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(visited[i][j] && grid[i][j] == 1)
                {
                    DFS(grid, visited, row, col, count, i, j);
                    break;
                }
            }
        }
        return count;
    }
};