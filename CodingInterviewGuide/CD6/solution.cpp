/*
    维护一个入队栈和出队栈，分别进行Push和pop操作。
    push的数据全部往入队在栈放，pop的时候从出队栈出。
    如果出队栈为空则把入队栈的数据全部拿过来就行
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Queue
{
public:
    //数据全部入到出队栈
    void add(int num)
    {
        in.push(num);
    }

    void poll()
    {
        //如果出队栈没数据，则将入队栈的数据全部导过来
        if(out.empty())
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        out.pop();
    }

    int peek()
    {
        if(out.empty())
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
private:
    stack<int> in;    //入队栈
    stack<int> out;   //出队栈
};

int main()
{
    int count = 0, num;
    string str;
    Queue q;
    while(cin >> count)
    {
        for(int i = 0; i < count; i++)
        {
            if(cin >> str)
            {
                if(str == "add")
                {
                    cin >> num;
                    q.add(num);
                }
                else if(str == "poll")
                {
                    q.poll();
                }
                else if(str == "peek")
                {
                    cout << q.peek() << endl;
                }
            }
        }
    }
    return 0;
}