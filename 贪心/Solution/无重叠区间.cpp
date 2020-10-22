/*
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals[0].empty())
        {
            return 0;
        }

        //按照结束时间从早到晚排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& e1, const vector<int>& e2){
            return e1[1] < e2[1];
        });


        int endNum = 0;
        int count = 1;
        for(int i = 1; i < intervals.size(); i++)
        {
            //如果起始时间大于当前结束时间，则执行该会议
            if(intervals[i][0] >= intervals[endNum][1])
            {
                //设置结束时间
                endNum = i;
                count++;
            }
        }
        return intervals.size() - count;
    }
};