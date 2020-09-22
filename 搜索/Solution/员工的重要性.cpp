/*
给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。

比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。

现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/employee-importance
*/
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        //用哈希表进行存储方便查询
        unordered_map<int, Employee*> info;
        for(const auto& ep : employees)
        {
            info[ep->id] = ep;
        }

        int sum = 0;
        queue<int> q;
        q.push(id); //队首入队

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            sum += info[cur]->importance;   //加上当前结果

            for(auto subId : info[cur]->subordinates)
            {
                q.push(subId);
            }
        }
        return sum;
    }
};