/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }

        //因为购买和卖出需要两天，所以k应该不大于天数的一半，如果大于我们则可以认为k接近于无限
        //由于k等于无限，所以可以忽略k的作用，这里使用第二题的解法即可
        if(k > prices.size() / 2)
        {
            int size = prices.size();

            int dp_i_0 = 0, dp_i_1 = -prices[0];  //初始状态,dp_i_0是前一天没买入的状态，dp_i_1是前一天买入的状态
            int temp;   //临时变量，用来保存dp_i_0
            for(int i = 1; i < size; i++)
            {
                temp = dp_i_0;
                dp_i_0 = max(dp_i_1 + prices[i], dp_i_0);   //卖出或者休息
                dp_i_1 = max(temp - prices[i], dp_i_1);   //买入或者休息
            }

            return dp_i_0;
        }

        int size = prices.size();
        int dp[size][k + 1][2];
        memset(dp, 0, sizeof(dp));  //初始化
        for(int i = 0; i < prices.size(); i++)
        {
            for(int j = k; j >= 1; j--)
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
        return dp[size - 1][k][0];
    }
};