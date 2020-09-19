/*
给定两个字符串S和T，返回S子序列等于T的不同子序列个数有多少个？
字符串的子序列是由原来的字符串删除一些字符（也可以不删除）在不改变相对位置的情况下的剩余字符（例如，"ACE"is a subsequence of"ABCDE"但是"AEC"不是）
例如：
S ="rabbbit", T ="rabbit"
返回3
https://www.nowcoder.com/practice/ed2923e49d3d495f8321aa46ade9f873?tpId=46&tqId=29065&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/

class Solution {
public:
    int numDistinct(string S, string T) {
        int row = S.size(), col = T.size();
        vector<vector<int>> dp(row  + 1, vector<int>(col + 1, 0));
        
        /*
            边界处理
            F(i, 0) = 1;
            F(0, i) = 0;空集无法删除，S所以不可能变换到T
        */
        for(int i = 0; i <= row; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= col; i++)
        {
            dp[0][i] = 0;
        }
        
        
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                if(S[i - 1] != T[j  - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[row][col];
    }
};