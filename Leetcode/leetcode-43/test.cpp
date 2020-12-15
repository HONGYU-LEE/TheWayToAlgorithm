class Solution {
public:
	    //字符串相乘后的长度必定不会超过两者的长度之和
        //从最后一个位置依次往前加，方便进位
        //具体思路其实就是将乘法写为竖型乘法,各个位相乘再相加到一块
        /*
            如:   12 
                x 31
                -----
                   2
                  1
                  6
                 3
                -----
                 372
        */
    string multiply(string num1, string num2) {

        int length1 = num1.size();
        int length2 = num2.size();
        string res(length1 + length2, '0');

        //从最后一个位置开始加
        for(int i = length1 - 1; i >= 0; i--)
        {
            for(int j = length2 - 1; j >= 0; j--)
            {
                int temp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = temp % 10 + '0';
                //保留个位
                
                res[i + j] += temp / 10;
                //进位到下一个位置, 这里用到+=的原因是一个位置在不同位相乘中多次进位, 并且初始化时给了'\0',这里不需要再加
            }
        }


        for(int i = 0; i < length1 + length2; i++)
        {
            //找到不为0的位置，从那个位置开始的才是最终的结果，将那个位置开始的子串返回
            if(res[i] != '0')
            {
                return res.substr(i);
            }
        }

        //如果没有找到，则说明不存在
        return "0";
    }
};
