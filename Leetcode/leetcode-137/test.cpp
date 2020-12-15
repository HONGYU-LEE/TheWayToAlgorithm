class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        //计算出每一个位的1在所有数据中出现过的次数，然后%3,就可以去掉出现了三次的元素，找到只出现一次的元素
        for(int i = 0; i < 32; i++)
        {
            int count = 0;

            for(int j = 0; j < nums.size(); j++)
            {
                //如果当前数据的第i位为1，计数加一
                if((nums[j] >> i) & 1)
                {
                    count++;
                }
            }
            //去掉出现了三次的数据
            count %= 3;
            //将第i位的结果放进res中
            res |= (count << i);
        }

        return res;
    }
};
