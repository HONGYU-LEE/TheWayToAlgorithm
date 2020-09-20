//给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列，使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。
//https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty() || dict.empty())
        {
            return false;
        }
        
        //找到最长的单词长度
        int maxLen = 0;
        for(auto it = dict.begin(); it != dict.end(); it++)
        {
            if(it->size() > maxLen)
            {
                maxLen = it->size();
            }
        }
        
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); i++)
        {
           for(int j = i - 1; j >= 0; j--)
           {
               //超过最大长度
               if((i - j) > maxLen)
               {
                   break;
               }
               
               if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
               {
                   dp[i] = true;
                   break;
               }
           }
        }
        return dp[s.size()];
    }
};
