class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin < end)
        {
            int mid = ((end - begin) >> 1) + begin;
            if(nums[mid] < nums[end])
            {
                end = mid;
            }
            //如果中间比右边小，则说明最小值在前半部分
            else
            {
                begin = mid + 1;
            }
            //如果中间比右边大，则说明最小值在后半部分
        }

        return nums[end];
    }
};
