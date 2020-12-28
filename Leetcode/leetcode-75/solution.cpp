class Solution {
public:
    //荷兰国旗，prev指向0，cur指向1，end指向2
    void sortColors(vector<int>& nums) {
        if(nums.empty())
        {
            return;
        }
        int prev = -1, cur = 0, end = nums.size() - 1;
        while(cur <= end)
        {
            //将0交换到前面去
            if(nums[cur] == 0)
            {
                swap(nums[++prev], nums[cur++]);
            }
            //如果为1，则继续前进
            else if(nums[cur] == 1)
            {
                cur++;
            }
            //将2交换到后面去
            else
            {
                swap(nums[cur], nums[end--]);
            }
        }
    }
};