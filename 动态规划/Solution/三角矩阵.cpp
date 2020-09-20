//给出一个三角形，计算从三角形顶部到底部的最小路径和，每一步都可以移动到下面一行相邻的数字，
//https://www.nowcoder.com/practice/2b7995aa4f7949d99674d975489cb7da?tpId=46&tqId=29060&tPage=2&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-rankin

//自底向上
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(!triangle.size() || !triangle[0].size())
        {
            return 0;   
        }
        int row = triangle.size();
        vector<vector<int>> dp(triangle);
        
        for(int i = 1; i < row; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0)	//处理左边界
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else if(j == i)	//处理右边界
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else	//状态方程
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
                
                dp[i][j] += triangle[i][j];	//加上当前项
            }
        }
        
        //找到最后一列中的最小值
        int res = dp[row - 1][0];
        for(int i = 1; i < row; i++)
        {
                res = min(dp[row - 1][i], res);
        }
        
        return res;
    }
};

//自顶向下
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(!triangle.size() || !triangle[0].size())
        {
            return 0;   
        }
        int row = triangle.size();
        vector<vector<int>> dp(triangle);
        
        //从顶部往下更新，以为每列的个数是由多到少，所以并不需要进行边界的处理，并且结果只有f(0, 0)一个，也不需要进行结果的筛选
        for(int i = row - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[i][j] = min(dp[i + 1][j + 1], dp[i + 1][j]) + triangle[i][j];
            }
        }
        
        return dp[0][0];
    }
};