/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值
https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
        {
            return 0;
        }
        
        int maxSum = array[0];
        int sum = array[0];
        for(int i = 1; i < array.size(); i++)
        {
            sum = sum > 0 ? sum + array[i] : array[i];
            maxSum = sum > maxSum ? sum : maxSum;
        }
        
        return maxSum;
    }
};