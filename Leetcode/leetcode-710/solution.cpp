class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        size = N - blacklist.size();

        //将黑名单数字先加入哈希表中
        for (auto num : blacklist)
        {
            whiteList[num] = -1;
        }

        int end = N - 1;    //末尾下标
        for (auto num : blacklist)
        {
            //如果黑名单数字本来就在后面，则可以不用映射，直接跳过
            if (num >= size)
            {
                continue;
            }
            //如果数字在黑名单中，则跳过
            while (whiteList.count(end))
            {
                end--;
            }
            //建立起黑名单与白名单的映射
            whiteList[num] = end--;
        }
    }

    int pick() {
        int index = rand() % size;

        //如果在黑名单里，则获取到白名单对应的映射，否则直接返回
        if (whiteList.count(index))
        {
            return whiteList[index];
        }
        else
        {
            return index;
        }
    }
    unordered_map<int, int> whiteList;
    size_t size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */