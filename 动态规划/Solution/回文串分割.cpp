/*
给出一个字符串s，分割s使得分割出的每一个子串都是回文串
计算将字符串s分割成回文分割结果的最小切割数
例如:给定字符串s="aab",
返回1，因为回文分割结果["aa","b"]是切割一次生成的。
示例1
https://www.nowcoder.com/practice/1025ffc2939547e39e8a38a955de1dd3?tpId=46&tqId=29048&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/

class Solution {
public:
    bool isReverse(const string& str, int begin, int end)
    {
        while(begin < end)
        {
            if(str[begin++] != str[end--])
            {
                return false;
            }
        }
        return true;
    }

    int minCut(string s) 
    {
        if(s.empty())
        {
            return INT_MAX;
        }
        
        vector<int> dp(s.size() + 1);
        for(int i = 0; i <= s.size(); i++)
        {
            dp[i] = i - 1;
        }
        
        for(int i = 1; i <= s.size(); i++)
        {
           for(int j = 0; j < i; j++)
           {
               //如果前段字符串是回文，则直接切割一次
               if(isReverse(s, j, i - 1))
               {
                   dp[i] = min(dp[i], dp[j] + 1);
               }
           }
        }
        return dp[s.size()];
    }
};

//方法2
class Solution {
public:
    vector<vector<bool>> isReverse(const string& s)
    {
        int len = s.size();
        vector<vector<bool>> res(len, vector<bool>(len, false));
        //由内至外更新
        for(int i = len - 1; i >= 0; i--)
        {
            for(int j = i; j < len; j++)
            {
                //如果子串只有一个字符，必定是回文
                if(j == i)
                {
                    res[i][j] = true;
                }
                //如果两个字符相邻，并且两者相同，则说明是回文
                else if(j == i + 1)
                {
                    res[i][j] = (s[i] == s[j]);
                }
                //如果当前两个位置的字符相同，并且之前的位置也都匹配，则说明是回文
                else
                {
                    res[i][j] = (s[i] == s[j]) && res[i + 1][j - 1];
                }
            }
        }
        return res;
    }

    int minCut(string s) {
        if(s.empty())
        {
            return INT_MAX;
        }
        
        vector<int> dp(s.size() + 1);
        vector<vector<bool>> mat = isReverse(s);
        
        for(int i = 0; i <= s.size(); i++)
        {
            dp[i] = i - 1;
        }
        
        for(int i = 1; i <= s.size(); i++)
        {
           for(int j = 0; j < i; j++)
           {
               //如果前段字符串是回文，则直接切割一次
               if(mat[j][i - 1])
               {
                   dp[i] = min(dp[i], dp[j] + 1);
               }
           }
        }
        return dp[s.size()];
    }
};