class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        int begin = 0, end = nums.size() - 1;

        while (begin < end)
        {
            if (copy[begin] == nums[begin])
                ++begin;
            else if (copy[end] == nums[end])
                --end;
            else
                break;
        }
        
        return begin < end ? (end - begin + 1) : 0;
    }
};
