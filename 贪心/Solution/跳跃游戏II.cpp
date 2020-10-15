/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        int maxJump = 0;    //当前能到达的最远距离
        int end = 0;        //当前能跳跃到的边界
        int count = 0;      //总次数

        for(int i = 0; i < nums.size() - 1; i++)
        {
            //当前位置可达
            if(i <= maxJump)
            {
                maxJump = max(maxJump, i + nums[i]);

                //每次都从边界起跳，确保次数最少
                if(i == end)
                {
                    end = maxJump;
                    ++count;
                }
            }
        }
        return count;
    }
};