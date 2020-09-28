/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord)
        {
            return 0;
        }

        unordered_set<string> dict(wordList.begin(), wordList.end());   //哈希映射，方便查找
        unordered_set<string> visited;  //标记矩阵

        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int res = 1;    //序列长度包含原字符串

        //用BFS必定能求出最小序列，因为BFS是一轮一轮从内往外，每层的结果都只进行了一次变化。
        while(!q.empty())
        {
            int size = q.size();
            
            //对上轮的结果进行一次变化
            while(size--)
            {
                string curStr = q.front();
                q.pop();

                //对每个位一次变化
                for(int i = 0; i < curStr.size(); i++)
                {
                    string newStr = curStr; //副本
                    for(int j = 0; j < 26; j++)
                    {
                        newStr[i] = 'a' + j;
                        //如果访问过或者词典中不存在则跳过
                        if(visited.count(newStr) || !dict.count(newStr))
                        {
                            continue;
                        }

                        //如果得到最终结果，则返回res + 1(本轮)
                        if(newStr == endWord)
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
        return 0;   //如果中间没返回，说明不存在
    }
};