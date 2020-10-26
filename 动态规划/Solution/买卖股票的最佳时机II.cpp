/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
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
};