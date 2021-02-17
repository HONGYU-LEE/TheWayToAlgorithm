class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);

        int i = 0, j = 1;
        while(j <= num)
        {
            while(i < j && i + j <= num)
            {
                res[j + i] = res[i] + 1;
                i++;
            }
            //计算下一位
            i = 0;
            j <<= 1;
        }
        return res;
    }
};