/*
有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。

给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。

为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

最后返回经过上色渲染后的图像。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flood-fill
*/

class Solution {
public:
    //向量矩阵
    int nextPos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void DFS(vector<vector<int>>& image, vector<vector<bool>>& visited, 
        int row, int col, int sr, int sc, int oldColor, int newColor)
    {
        //染色并进行标记
        image[sr][sc] = newColor;
        visited[sr][sc] = false;

        //向上下左右四个方向进行渲染
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
            if(image[newRow][newCol] == oldColor && visited[newRow][newCol])
            {
                DFS(image, visited, row, col, newRow, newCol, oldColor, newColor);
            }
        }    
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty() || image[0].empty())
        {
            return image;
        }

        int row = image.size(), col = image[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, true));    //标记矩阵        
        int oldColor = image[sr][sc];
        DFS(image, visited, row, col, sr, sc, oldColor, newColor);

        return image;
    }
};