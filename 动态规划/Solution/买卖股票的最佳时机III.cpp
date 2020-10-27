/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }

        int size = prices.size();
        int maxK = 2;
        int dp[size][maxK + 1][2];
        memset(dp, 0, sizeof(dp));  //初始化
        for(int i = 0; i < prices.size(); i++)
        {
            for(int j = maxK; j >= 1; j--)
            {
                //处理初始状态
                if(i == 0)
                {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);    //卖出或者休息
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);    //买入或者休息
            }
        }
        return dp[size - 1][maxK][0];
    }
};