/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/open-the-lock
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> set(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        if(set.count("0000"))
        {
            return -1;
        }

        int res = 0;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string curStr = q.front();
                q.pop();

                if(curStr == target)
                {
                    return res;
                }
            
                for(int i = 0; i < target.size(); i++)
                {
                    string newStr1 = curStr;    //往前加
                    string newStr2 = curStr;    //往后减
                    
                    newStr1[i] = (newStr1[i] == '9') ? '0' : newStr1[i] + 1;
                    newStr2[i] = (newStr2[i] == '0') ? '9' : newStr2[i] - 1;
                    
                    if(!visited.count(newStr1) && !set.count(newStr1))
                    {
                        q.push(newStr1);
                        visited.insert(newStr1);
                    }
                    
                    if(!visited.count(newStr2) && !set.count(newStr2))
                    {
                        q.push(newStr2);
                        visited.insert(newStr2);
                    }
                }         
            }
            res++;
        }
        return -1;
    }
};