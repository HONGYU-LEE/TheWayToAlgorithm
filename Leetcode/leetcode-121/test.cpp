class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;

        int buy = -prices[0], sell = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            buy = max(buy, -prices[i]);
            sell = max(sell, prices[i] + buy);
        }
		//动态规划， 如果当前价格比前一天低就购入，如果售价高于成本就售出 
        return sell;
    }
};
