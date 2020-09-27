/*
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
*/
class Solution {
public:
    int nextPos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //方向矩阵

    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        
        //将所有腐烂的橘子入队
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
            }
        }

        int count = 0;
        while(!q.empty())
        {
            bool flag = false;
            int size = q.size();
            //由已腐烂的橘子带入被感染的橘子
            while(size--)
            {
                auto cur = q.front();
                q.pop();

                //本轮感染的橘子
                for(int i = 0; i < 4; i++)
                {
                    int newRow = cur.first + nextPos[i][0];
                    int newCol = cur.second + nextPos[i][1];
                    
                    //如果越界则跳过
                    if(newRow < 0 || newRow >= row || newCol < 0 || newCol >= col)
                    {
                        continue;
                    }
                    //腐烂新鲜橘子
                    if(grid[newRow][newCol] == 1)
                    {
                        flag = true;
                        grid[newRow][newCol] = 2;
                        q.push(make_pair(newRow, newCol));
                    }
                }

            }
            //如果有橘子腐烂才计数
            if(flag)
            {
                count++;
            }       
        }

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                //如果有任何一个新鲜橘子，则说明不可能完成
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return count;
    }
};