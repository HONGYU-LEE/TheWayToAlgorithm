/*
    利用一个辅助栈来辅助排序
    
    1.如果当前数据小于等于辅助栈的栈顶，则将数据放入辅助栈中
    2.如果数据大于辅助栈的栈顶，则不停的将辅助栈的数据移动到数据栈中，直到数据小于等于辅助栈的栈顶
    通过这种方法来保证有序
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

void sortByStack(stack<int>& data)
{
    stack<int> help;
    
    while(!data.empty())
    {
        int cur = data.top();
        data.pop();
        
        //当当前数据大于辅助栈栈顶时，为了将数据放到合适的位置，需要一直将辅助栈数据挪动导
        //数据栈中，直到当前数据小于等于栈顶
        while(!help.empty() && cur > help.top())
        {
            data.push(help.top());
            help.pop();
        }
        help.push(cur);
    }
    
    //最后再将辅助栈中的数据全部放到原栈中
    while(!help.empty())
    {
        data.push(help.top());
        help.pop();
    }
}

int main()
{
    int count = 0, num;
    stack<int> data;

    while(cin >> count)
    {
        for(int i = 0; i < count; i++)
        {
            cin >> num;
            data.push(num);
        }
        sortByStack(data);
        
        while(!data.empty())
        {
            cout << data.top() << " ";
            data.pop();
        }
        cout << endl;
    }
    return 0;
}