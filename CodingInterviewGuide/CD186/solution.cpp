#include<iostream>
#include<vector>
using namespace std;

int func(vector<vector<int>>& vec)
{
    if(vec.empty() || vec[0].empty())
    {
        return 0;
    }
    int row = vec.size(), col = vec[0].size();
    
    vector<vector<int>> dp(row, vector<int>(col, 0));
    //base
    dp[0][0] = vec[0][0];
    for(int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i - 1][0] + vec[i][0];
    }
    for(int j = 1; j < col; j++)
    {
        dp[0][j] = dp[0][j - 1] + vec[0][j];
    }
    
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + vec[i][j];
        }
    }
    
    return dp[row - 1][col - 1];
}

int main()
{ 
    int row, col;
    
    while(cin >> row >> col)
    {
        vector<vector<int>> vec(row, vector<int>(col));
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> vec[i][j];
            }
        }
        
        cout << func(vec) << endl;
    }
    return 0;
}