/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0)
        {
            return 0;
        }
        
        int sum = 1;
        for(int i = 1; i < number; i++)
        {
            sum *= 2;
        }
        
        return sum;
    }
};