class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
        {
            return 0;
        }

        //如果0不同则按照0来升序排序，如果0相同则按照1降序排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2)->bool{
            if(v1[0] == v2[0])
            {
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        });

        int subCount = 0;
        int start[2] = {intervals[0][0], intervals[0][1]};
        for(int i = 1; i < intervals.size(); i++)
        {
            int cur[2] = {intervals[i][0], intervals[i][1]};
            //判断区间是否覆盖
            if(start[0] <= cur[0] && start[1] >= cur[1])
            {
                subCount++;   //当前区间覆盖了，删除
            }

            //判断区间左端是否相交，如果相交则合并
            if(start[1] >= cur[0] && start[1] <= cur[1])
            {
                start[1] = cur[1];
            }

            //判断区间是否无关系
            if(start[1] < cur[0])
            {
                //完全无关，从这个位置继续向后判断
                start[0] = cur[0];
                start[1] = cur[1];
            }
        }
        return intervals.size() - subCount;
    }
};