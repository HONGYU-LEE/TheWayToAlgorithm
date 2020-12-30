class Solution {
public:
    //贪心：先打好表，然后从大到小往里放即可
    vector<int> nums{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> strs{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        if(num == 0)
        {
            return "";
        }
        string res;

        for(int i = 0; i < nums.size(); i++)
        {
            while(num >= nums[i])
            {
                res += strs[i];
                num -= nums[i];
            }
        }

        return res;
    }
};