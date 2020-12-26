class Solution {
public:
    void dfs(vector<vector<int>>& allRes, vector<int>& curRes, int len, int target, int index, int sum)
    {
        if(curRes.size() == len)
        {
            if(sum == target)
            {
                allRes.push_back(curRes);
            }
            return;
        }

        for(int i = index; i < 10; i++)
        {
            curRes.push_back(i);
            dfs(allRes, curRes, len, target, i + 1, sum + i);
            curRes.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> allRes;
        vector<int> curRes;
        dfs(allRes, curRes, k, n, 1, 0);

        return allRes;
    }
};