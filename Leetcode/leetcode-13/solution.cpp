class Solution {
public:
    int romanToInt(string s) {
        if(s.empty())
        {
            return 0;
        }
        unordered_map<char, int> map;
        map['I'] = 1, map['V'] = 5, map['X'] = 10, map['L'] = 50, map['C'] = 100, map['D'] = 500, map['M'] = 1000;
        
        //如果左边的比右边的小，则说明左边的是负数
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(i + 1 < s.size() && map[s[i]] < map[s[i + 1]])
            {
                res += (map[s[i + 1]] - map[s[i]]);
                i++;
            }
            else
            {
                res += map[s[i]];
            }
        }
        return res;
    }
};