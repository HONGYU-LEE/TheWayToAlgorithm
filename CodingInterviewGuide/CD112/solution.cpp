# include <iostream>
#include<stack>

using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

//首先用快慢指针找到中间节点，然后将后半部分节点存入栈中于前半部分对比。
list_node * check(list_node * head)
{
    //////在下面完成代码
    list_node* slow = head;
    list_node* fast = head;   
    
    //找到链表的中间位置
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    stack<list_node*> st;
    while(slow)
    {
        st.push(slow);
        slow = slow->next;
    }
    
    slow = head;
    while(!st.empty())
    {
        list_node* cur = st.top();
        st.pop();
        
        if(cur->val == slow->val)
        {
            slow = slow->next;
        }
        else
        {
            cout << "false" << endl;
            return head;
        }
    }
    
    cout << "true" << endl;
    return head;
}


int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}