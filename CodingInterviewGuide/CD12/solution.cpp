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
    
    vector<int> dp(count + 1, INT_MAX - 1);
    
    dp[0] = 0;
    for(int i = 0; i <= count; i++)
    {
        for(int j = 0; j < vec.size(); j++)
        {
            //如果当前背包小于面额时，则跳过
            if(i < vec[j])
            {
                continue;
            }
            dp[i] = min(dp[i], dp[i - vec[j]] + 1);
        }
    }
    //如果没走到最后一个位置，说明无解
    return (dp[count] == INT_MAX - 1) ? -1 : dp[count];
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