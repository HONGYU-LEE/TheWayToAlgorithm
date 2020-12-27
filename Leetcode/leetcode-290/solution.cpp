class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pMap;
        unordered_map<string, char> sMap;
        
        int i = 0, j = 0;
        for(auto ch : pattern)
        {   
            if(i >= s.size())
            {
                return false;
            }

            j = i;
            while(j < s.size() && s[j] != ' ')
            {
                j++;
            } 

            string str = s.substr(i, j - i);
            if((pMap.count(ch) && pMap[ch] != str) || (sMap.count(str) && sMap[str] != ch))
            {
                return false;
            }
            pMap[ch] = str;
            sMap[str] = ch;
            i = j + 1;   
        }
        return i >= s.size();
    }
};