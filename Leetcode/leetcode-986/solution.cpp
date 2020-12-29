class Solution {
public:
    //数组本身有序，不需要再进行排序
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i = 0, j = 0;

        while(i < A.size() && j < B.size())
        {
            int curA[2] = {A[i][0], A[i][1]};
            int curB[2] = {B[j][0], B[j][1]};
            if(curA[0] <= curB[1] && curA[1] >= curB[0])
            {
                res.push_back({max(curA[0], curB[0]), min(curA[1], curB[1])});
            }

            //判断哪一个指针进行前行,小区间先走，大区间尽可能匹配更多
            if(curA[1] < curB[1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return res;
    }
};