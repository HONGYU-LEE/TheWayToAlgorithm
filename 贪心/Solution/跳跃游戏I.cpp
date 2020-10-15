/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game/
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
        {
            return true;
        }

        int maxJump = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            //如果当前位置可达，则进行距离的更新
            if(i <= maxJump)
            {
                //更新当前能够跳跃的最远距离
                maxJump = max(maxJump, i + nums[i]);

                //如果能够跳到终点，则返回正确
                if(maxJump >= nums.size() - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};