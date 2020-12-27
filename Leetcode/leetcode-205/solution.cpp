class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> _sMap;
        unordered_map<char, int> _tMap;

        for(int i = 0; i < s.size(); i++)
        {
            if((_sMap.count(s[i]) && _sMap[s[i]] != t[i]) || (_tMap.count(t[i]) && _tMap[t[i]] != s[i]))
            {
                return false;
            }

            _sMap[s[i]] = t[i];
            _tMap[t[i]] = s[i];
        }
        return true;
    }
};