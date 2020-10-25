/*
在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。

给出一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。

返回可以通过分割得到的平衡字符串的最大数量。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-a-string-in-balanced-strings
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        if(s.empty())
        {
            return 0;
        }

        int count = 0;
        int balance = 0;	//当前是否平衡

        for(auto ch : s)
        {
            if(ch == 'R')
            {
                ++balance;
            }
            else
            {
                --balance;
            }
			
            //每次凑成一队就直接切割
            if(balance == 0)
            {
                ++count;
            }
        }
        return count;
    }
};