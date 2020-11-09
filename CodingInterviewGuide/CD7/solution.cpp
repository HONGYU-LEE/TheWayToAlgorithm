/*
    设置两个函数，一个用来获取栈底的值，一个用来进行逆置
    
    逆置时先获取栈底的值，但不立即进行插入，而是先递归进入最深处，先将栈顶的值插入进去，然后由内向外进行插入，最后插入栈底，完成逆置
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//获取栈底的值
int getLastOfStack(stack<int>& st)
{
    int num = st.top();
    st.pop();
    
    if(st.empty())
    {
        return num;    //如果当前栈为空，则说明刚出栈的数据就是栈中最后一个数据
    }
    else
    {
        int last = getLastOfStack(st);    //递归获取栈底的数据
        st.push(last);    //把刚刚的数据放回去
        return last;      //返回栈底  
    }
}

//逆置
void reverse(stack<int>& st)
{
    if(st.empty())
    {
        return;
    }
    
    int num = getLastOfStack(st);    //递归到最深处，然后从里往外开始放，完成逆置
    reverse(st);
    st.push(num);
}

int main()
{
    int count = 0, num;
    stack<int> st;
    
    while(cin >> count)
    {
        for(int i = 0; i < count; i++)
        {
            cin >> num;
            st.push(num);
        }
        
        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
    
    return 0;
}