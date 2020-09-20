/*
给定两个单词word1和word2，请计算将word1转换为word2至少需要多少步操作。
你可以对一个单词执行以下3种操作：
a）在单词中插入一个字符
b）删除单词中的一个字符
c）替换单词中的一个字符
https://www.nowcoder.com/practice/81d7738f954242e5ade5e65ec40e5027?tpId=46&tqId=29106&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.size(), col = word2.size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        
        //处理边界
        for(int i = 0; i <= row; i++)
        {
            dp[i][0] = i;
        }
        for(int i = 0; i <= col; i++)
        {
            dp[0][i] = i; 
        }
        
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                //找出插入和删除的最小结果
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                
                //如果当前两个位置的数据相同，则不需要进行替换
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[row][col];
    }
};