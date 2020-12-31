class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n <= 0)
        {
            return {};
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        int end = n * n;
        
        int left = 0, right = n - 1, up = 0, down = n - 1, cur = 1;
        
        while(cur <= end)
        {
            for(int i = left; i <= right && cur <= end; i++)
            {
                res[up][i] = cur++;
            }
            if(++up > down)
            {
                break;
            }

            for(int i = up; i <= down && cur <= end; i++)
            {
                res[i][right] = cur++;
            }
            if(--right < left)
            {
                break;
            }

            for(int i = right; i >= left && cur <= end; i--)
            {
                res[down][i] = cur++;
            }
            if(--down < up)
            {
                break;
            }

            for(int i = down; i >= up && cur <= end; i--)
            {
                res[i][left] = cur++;
            }
            if(++left > right)
            {
                break;
            }
        }
        return res;
    }
};