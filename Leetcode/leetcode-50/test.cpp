class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        else if(n == 1)
            return x;
        //处理边界

        int i = n;
        double res = 1;

        while(i != 0)
        {
            if(i & 1)
            {
                res *= x;
            }
            //如果为奇数次幂，则多乘以一次x。如果第一位为1则说明是奇数，等价于i % 2 == 1

            x *= x;
            i /= 2;
            //这里有负数不能用>>,除非前面先对数据进行处理
        }
        //快速幂算法
        return  n > 0 ? res : 1 / res;
    }
};
