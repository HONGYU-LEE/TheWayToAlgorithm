#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<pair<int, int>> findMinOfLeftAndRight(vector<int>& arr)
{
    vector<pair<int, int>> res(arr.size());
    int num, index;
    stack<int> st;
    
    for(int i = 0; i < arr.size(); i++)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
        {
            index = st.top();
            st.pop();
  
            num = st.empty() ? -1 : st.top();
            
            res[index].first = num;
            res[index].second = i;
        }
        st.push(i);
    }
    
    //清算剩下的
    while(!st.empty())
    {
        index = st.top();
        st.pop();

        num = st.empty() ? -1 : st.top();

        res[index].first = num;
        res[index].second = -1;
    }
    
    return res;
}

int main()
{
    int count = 0, num;
    
    while(cin >> count)
    {
        vector<int> data(count);
        for(int i = 0; i < count; i++)
        {
            cin >> data[i];
        }
        auto res = findMinOfLeftAndRight(data);
        
        for(const auto& ans : res)
        {
            cout << ans.first << " " << ans.second << endl;
        }
    }
    
    return 0;
}