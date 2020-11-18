#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int func(vector<int>& vec, int count)
{
    if(vec.empty() || count == 0)
    {
        return 0;
    }
    
    vector<vector<int>> dp(vec.size() + 1, vector<int>(count + 1, 0));
    //初态，当钱数为0的时候不需要任何操作就可以完成，但是当没有纸币的时候则无法操作
    for(int i = 0; i <= vec.size(); i++)
    {
        dp[i][0] = 1;
    }
    
    for(int i = 1; i <= vec.size(); i++)
    {
        for(int j = 1; j <= count; j++)
        {
            //如果当前背包小于面额时，则跳过
            if(j < vec[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - vec[i - 1]]) % 1000000007;
            }
            
        }
    }
    return dp[vec.size()][count] % 1000000007;
}

//优化
int func2(vector<int>& vec, int count)
{
    if(vec.empty() || count == 0)
    {
        return 0;
    }
    
    vector<int> dp(count + 1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 1; j <= count; j++)
        {
            //如果当前背包小于面额时，则跳过
            if(j < vec[i])
            {
                dp[j] = dp[j];
            }
            else
            {
                dp[j] = (dp[j] + dp[j - vec[i]]) % 1000000007;
            }
            
        }
    }
    return dp[count] % 1000000007;
}


int main()
{ 
    int count, size;
    
    while(cin >> size >> count)
    {
        vector<int> vec(size);
        
        for(int i = 0; i < size; i++)
        {
            cin >> vec[i];
        }
        
        cout << func(vec, count) << endl;
    }
    return 0;
}


