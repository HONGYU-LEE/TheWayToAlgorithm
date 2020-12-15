class Solution {
public:
    int firstUniqChar(string s) {
        //利用哈希表实现，将出现过的所有字母计数，如果出现次数为一个，说明是第一个
        int count[26] = {0};

        for(auto ch: s)
        {
            ++count[ch - 'a'];
        } 

        for(int i = 0; i < s.size(); ++i)
        {
            if(count[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};
