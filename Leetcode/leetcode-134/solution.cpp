class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int curSum = 0, totalSum = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            curSum += (gas[i] - cost[i]);
            totalSum += (gas[i] - cost[i]);

            //如果当前油箱小于0，则说明0到i都不可能成功出发，继续从下一个位置查找
            if(curSum < 0)
            {
                curSum = 0;
                start = i + 1;
            }
        }
        //如果总资源不够，则不可能抵达终点
        if(totalSum < 0)
        {
            return -1;
        }

        return start;
    }
};