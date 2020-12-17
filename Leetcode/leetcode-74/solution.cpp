class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
        {
            return false;
        }
        
        int row = matrix.size(), col = matrix[0].size();
        int begin = 0, end = row * col - 1;
        
        while(begin <= end)
        {
            int mid = (end - begin) / 2 + begin;
            int curRow = mid / col, curCol = mid % col;
            
            if(matrix[curRow][curCol] == target)
            {
                return true;
            }
            else if(matrix[curRow][curCol] < target)
            {
                begin = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return false;
    }
};