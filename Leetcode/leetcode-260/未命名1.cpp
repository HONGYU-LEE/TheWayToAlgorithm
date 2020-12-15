class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int flag=0,i,x=0,y=0;
        for(i=0; i<nums.size(); i++)
        {
            flag ^= nums[i];
        }
        flag &= -flag;
        for(i=0; i<nums.size(); i++)
        {
            if((nums[i] & flag) ==0)
                x ^= nums[i];
            else
                y ^= nums[i];
        }
        return {x,y};
    }
    
};
