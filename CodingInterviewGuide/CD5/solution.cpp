/*
    维护两个栈，一个用来存放当前最小值，一个用来存放所有数据。
    如果当前插入的数据小于等于最小值，则将其放入最小栈中。这样做的目的是保证最小栈中的数据始终是最大的

    当出栈的是否，如果当前数据栈出栈数据与最小栈不同，则只让数据栈出栈，因为此刻出栈的数据对最小值不会有任何影响
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class MinStack
{
public:
    void push(int num)
    {
        //如果栈为空或者当前数据小于等于最小值时，则将其放入最小栈
        if(min.empty() || num <= min.top())
        {
            min.push(num);
        }
        data.push(num);
    }

    void pop()
    {
        //如果最小栈的栈顶和数据栈栈顶相同，则让最小栈出栈
        if(min.top() == data.top())
        {
            min.pop();
        }
        data.pop();
    }

    //最小值即为最小栈的栈顶
    int getMin()
    {
        return min.top();
    }
private:
    stack<int> min;    //保存最小值的栈
    stack<int> data;   //保存数据的栈
};

int main()
{
    int count = 0, num;
    string str;
    MinStack s;
    while(cin >> count)
    {
        for(int i = 0; i < count; i++)
        {
            if(cin >> str)
            {
                if(str == "push")
                {
                    cin >> num;
                    s.push(num);
                }
                else if(str == "pop")
                {
                    s.pop();
                }
                else
                {
                    cout << s.getMin() << endl;
                }
            }
        }
    }
    return 0;
}