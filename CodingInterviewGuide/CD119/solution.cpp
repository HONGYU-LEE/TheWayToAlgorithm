# include <iostream>
# include <stack>

using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list()
{
    int val, n;
    scanf("%d", &n);
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
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

//通过栈来反转部分区间
list_node* revrese_list(stack<list_node*>& st, list_node* begin, list_node* end)
{
    list_node* cur = st.top();
    st.pop();
    
    if(begin)   //拼接前部分即m-1
    {
        begin->next = cur;
    }
    
    list_node* next = nullptr;  //通过栈来反转
    while(!st.empty())
    {
        next = st.top();
        st.pop();
        
        cur->next = next;
        cur = next;
    }
    
    cur->next = end;    //连接后半区间
    
    return cur;
}

list_node * reverse_knode(list_node * head1, int K)
{
    //////在下面完成代码
    if(!head1 || K < 2)
    {
        return head1;
    }    

    list_node* newHead = head1, *cur = head1, *prev = nullptr, *next = nullptr;
    stack<list_node*> st;
    
    while(cur)
    {
        next = cur->next;
        st.push(cur);
        
        if(st.size() == K)    //当凑齐一组时才反转
        {
            prev = revrese_list(st, prev, next);
            newHead = newHead == head1 ? cur : newHead;    //如果为第一组反转，则让cur成为新的头节点
        }
        cur = next;
    }
    return newHead;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    list_node * head = input_list();
    int K;
    scanf("%d", &K);
    list_node * new_head = reverse_knode(head, K);
    print_list(new_head);
    return 0;
}