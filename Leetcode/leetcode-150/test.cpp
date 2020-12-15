#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h> 
bool isnum(const char* str)
{
    if(*str == '-' && strlen(str) == 1)
        return false;

    if(*str == '*' || *str == '/' || *str == '+')
        return false;

    return true;
}

int getnum(const char* str)
{
    int i = 0;
    int ret = 0, flag = 1;
    if(str[i] == '-')
    {
        i++;
        flag = 0;
    }

    for(; i < strlen(str); i++)
    {
        ret = ret * 10 + str[i] - '0';
    }

    return flag ? ret : - ret;
}

int evalRPN(char tokens[13][3], int tokensSize){
    int count, num1, num2, j = 0;
    int *stack = (int*)malloc(sizeof(int) * tokensSize);
	int i;
    for(i = 0; i < tokensSize; i++)
    {
        if (isnum(tokens[i]))
        {
            stack[j++] = getnum(tokens[i]);
        }
        else
        {
            switch(*tokens[i])
            {
                case '+': 
                    num1 = stack[--j];
                    num2 = stack[--j];
                    stack[j++] = num2 + num1;
                    break;

                case '-': 
                    num1 = stack[--j];
                    num2 = stack[--j];
                    stack[j++] = num2 - num1;
                    break;    

                case '*': 
                    num1 = stack[--j];
                    num2 = stack[--j];
                    stack[j++] = num2 * num1;
                    break;          

                case '/': 
                    num1 = stack[--j];
                    num2 = stack[--j];
                    if(!num1)
                        break;
                    stack[j++] = num2 / num1;
                    break;
            }
        }
    }
    
    count = stack[j - 1];
    return count;
}

int main()
{
	char str[13][3] ={"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	printf("%d", evalRPN(str, 13));
	return 0;
	
} 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = 0, max = nums[0];

        for(const auto& i : nums)
        {
            //如果上一次和小于0, 说明其中必定有相减过程，子集和必定不为最大，所以重新开始计算
            if(count <= 0)
            {
                count = 0;
            }
            //加上当前数据
            count += i;

            //如果当前和超过最大值，则更新最大值
            if(count > max)
            {
                max = count;
            }
        }
    
        return max;
    }
};
