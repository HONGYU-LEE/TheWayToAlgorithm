/*
给定一个二维的矩阵，包含 `'X'` 和 `'O'`（**字母 O**）。

找到所有被 `'X'` 围绕的区域，并将这些区域里所有的 `'O'` 用 `'X'` 填充。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions/
*/

class Solution {
public:
    //向量矩阵
    int nextPos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void DFS(vector<vector<char>>& board,  vector<vector<bool>>& visited,
int row, int col, int sr, int sc)
    {
        //将边界上的全部渲染为Y
        board[sr][sc] = 'Y';
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

            //渲染与边界相邻的位置
            if(board[newRow][newCol] == 'O' && visited[newRow][newCol])
            {
                DFS(board, visited, row, col, newRow, newCol);
            }
        }    
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
        {
            return;
        }
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, true)); //标记矩阵

        //将与边界接壤的岛屿全部渲染为临时值Y
        //寻找左右边界
        for(int i = 0; i < row; i++)
        {
            //左边界
            if(board[i][0] == 'O')
            {
                DFS(board, visited, row, col, i, 0);
            }
            //右边界
            if(board[i][col - 1] == 'O')
            {
                DFS(board, visited, row, col, i, col - 1);
            }
        }

        //寻找上下边界
        for(int j = 0; j < col; j++)
        {
            //上边界
            if(board[0][j] == 'O')
            {
                DFS(board, visited, row, col, 0, j);
            }
            //下边界
            if(board[row - 1][j] == 'O')
            {
                DFS(board, visited, row, col, row - 1, j);
            }
        }

        //状态更替
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                //将所有没有被渲染到的内部岛屿变为X
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }

                //恢复所有与边界接壤的岛屿
                if(board[i][j] == 'Y')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};