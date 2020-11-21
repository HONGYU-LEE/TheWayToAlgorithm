#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int func(int N, int M, int K, int P)
{
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    dp[0][P] = 1;    //设置起点
    
    for(int i = 1; i <= K; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            //走到前端，返回
            if(j == 1)
            {
                dp[i][j] = dp[i - 1][j + 1] % 1000000007;
            }
            //走到后端，返回
            else if(j == N)
            {
                dp[i][j] = dp[i - 1][j - 1] % 1000000007;
            }
            //尝试往前走和往后走
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i -1][j + 1]) % 1000000007;
            }
        }
    }
    
    return dp[K][M];
}

int main()
{ 
    int N, M, K, P;
    
    while(cin >> N >> M >> K >> P)
    {
        cout << func(N, M, K, P) << endl;
    }
    return 0;
}