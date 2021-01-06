class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        size = N - blacklist.size();

        //�������������ȼ����ϣ����
        for (auto num : blacklist)
        {
            whiteList[num] = -1;
        }

        int end = N - 1;    //ĩβ�±�
        for (auto num : blacklist)
        {
            //������������ֱ������ں��棬����Բ���ӳ�䣬ֱ������
            if (num >= size)
            {
                continue;
            }
            //��������ں������У�������
            while (whiteList.count(end))
            {
                end--;
            }
            //��������������������ӳ��
            whiteList[num] = end--;
        }
    }

    int pick() {
        int index = rand() % size;

        //����ں���������ȡ����������Ӧ��ӳ�䣬����ֱ�ӷ���
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