/*
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。

一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty() || points[0].empty())
        {
            return 0;
        }
        
        //按照尾区间进行排序
        sort(points.begin(), points.end(), [](const vector<int>& vec1, const vector<int>& vec2){
            return vec1[1] < vec2[1];
        });

        int count = 1;  //区间数
        int endNum = 0; //结束位置
        for(int i = 1; i < points.size(); i++)
        {
            /*
            	如果当前区间的结束坐标小于等于前一个区间的起始坐标，则代表两者可以合并，所以不进行计数。
            	而如果大于则说明两者不在一个区间中，所以需要多射一只箭
            */
            if(points[i][0] > points[endNum][1])
            {
                count++;
                
                endNum = i;	//更新新的结束区间
            }
        }
        return count;
    }
};