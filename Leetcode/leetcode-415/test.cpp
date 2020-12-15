class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string res;
        int next = 0, val1 = 0, val2 = 0, count = 0;

        //当两个字符串全都遍历完才停止
        while(end1 >= 0 || end2 >= 0)
        {
            //如果某个字符串已经遍历完，则让它多出的部分变为0，方便计算
            if(end1 >= 0)
                val1 = num1[end1--] - '0';
            else 
                val1 = 0;

            if(end2 >= 0)
                val2 = num2[end2--] - '0';
            else
                val2 = 0;

            //先算出当前大小，然后进位置零
            count = val1 + val2 + next;
            next = 0;

            //如果为两位数，则进位
            if(count > 9)
            {
                count -= 10;
                next = 1;
            }

            res.push_back(count + '0');
        }

        //当最后一次还有进位的时候
        if(next)
        {
            res.push_back('1');
        }

        //翻转数据
        reverse(res.begin(), res.end());
        return res;
    }
};
