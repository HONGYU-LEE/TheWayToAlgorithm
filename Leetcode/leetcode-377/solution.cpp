class Solution {
public:
    /*
        做法有两种，回溯和动规，由于本题有时间限制，经尝试回溯会超时，因此下面采用动规做法，直接转换成爬楼梯问题，每次能爬1-n阶
    */
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty())
        {
            return 0;
        }
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; i++)
        {
            for(auto num : nums)
            {
                if(i - num >= 0)
                {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};