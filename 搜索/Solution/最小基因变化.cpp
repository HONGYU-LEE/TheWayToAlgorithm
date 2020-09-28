/*
一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。

假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。

例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。

与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。

现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回 -1。

注意:

起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
所有的目标基因序列必须是合法的。
假定起始基因序列与目标基因序列是不一样的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-genetic-mutation
*/
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end)
        {
            return 0;
        }
        unordered_set<string> set(bank.begin(), bank.end());
        unordered_set<string> visited;

        int res = 0;
        queue<string> q;
        q.push(start);
        visited.insert(start);

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string curStr = q.front();
                q.pop();

                for(int i = 0; i < start.size(); i++)
                {
                    string newStr = curStr;
                    for(int j = 0; j < 26; j++)
                    {
                        newStr[i] = 'A' + j;
                        if(visited.count(newStr) || !set.count(newStr))
                        {
                            continue;
                        }
                        if(newStr == end)
                        {
                            return res + 1;
                        }
                        q.push(newStr);
                        visited.insert(newStr);
                    }
                }         
            }
            res++;
        }
        return -1;
    }
};