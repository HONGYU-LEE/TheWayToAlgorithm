class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        int i = 0, count = 0;
        
        for(int i = 0; i < n - 1; i++)
        {
            string cur;
            int end = 0;
            for(int i = 0; i < prev.size(); i++)
            {
                //如果走到底了，或者下一个和之前的不同则保存结果
                if(i + 1 == prev.size() || prev[i] != prev[i + 1])
                {
                    cur += ('0' + i - end + 1);
                    cur += prev[i];
                    end = i + 1;
                }
            }
            prev = cur; //记录本轮结果，下一轮继续判断
        }
        return prev;
    }
};