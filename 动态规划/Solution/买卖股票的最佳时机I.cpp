/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] = -prices[0];    //初始状态
        for(int i = 1; i < size; i++)
        {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);   //卖出或者休息
            dp[i][1] = max(-prices[i], dp[i - 1][1]);   //买入或者休息
        }

        return dp[size - 1][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        int size = prices.size();

        int dp_i_0 = 0, dp_i_1 = -prices[0];  //初始状态,dp_i_0是前一天没买入的状态，dp_i_1是前一天买入的状态
        for(int i = 1; i < size; i++)
        {
            dp_i_0 = max(dp_i_1 + prices[i], dp_i_0);   //卖出或者休息
            dp_i_1 = max(-prices[i], dp_i_1);   //买入或者休息
        }

        return dp_i_0;
    }
};