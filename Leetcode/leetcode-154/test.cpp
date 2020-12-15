class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = begin;
        while(begin < end)
        {
            mid = ((end - begin) >> 1) + begin;
            if(nums[mid] < nums[end])
            {
                end = mid;
            }
            //如果中间比右边小，则说明最小值在前半部分
            else if(nums[mid] > nums[end])
            {
                begin = mid + 1;
            }
            //如果中间比右边大，则说明最小值在后半部分
            else
            {
                --end;
            }
            //如果中间和右边相等，说明无法判断此时的位置，但是最右边一定不是最小，所以收缩区间
        }

        return nums[end];
    }
};{\rtf1}
