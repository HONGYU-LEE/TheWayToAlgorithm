/*
斐波那契数列

写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出
https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    int Fibonacci(int n) {
        //处理边界
        if(n <= 0)
        {
            return 0;
        }else if(n == 1)
        {
            return 1;
        }
        
        //状态方程：f(n) = f(n - 1) + f(n - 2)
        int fib1 = 0, fib2 = 1, res = 1;
        for(int i = 2; i < n; i++)
        {
            fib1 = fib2;
            fib2 = res;
            res = fib1 + fib2;
        }
        
        return res;
    }
};