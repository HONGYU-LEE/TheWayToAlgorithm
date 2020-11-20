# include <iostream>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(int n)
{
    int val;
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

list_node* reverse(list_node* node)
{
    list_node* prev = nullptr;
    list_node* next = nullptr;
    while(node)
    {
        next = node->next;
        node->next = prev;
        
        prev = node;
        node = next;
    }
    
    return prev;
}

/*
    由于数据需要从低位向高位进位，因此我们先需要反转
    两种做法，一种用栈逆序，一种直接反转链表
    为了节省空间这里用的第二种方法
*/
list_node * add_list(list_node * head1, list_node * head2)
{
    //////在下面完成代码
    if(!head1)
    {
        return head2;
    }
    else if(!head2)
    {
        return head1;
    }
    
    //首先反转两个链表，将低位变为高位
    head1 = reverse(head1);
    head2 = reverse(head2);
    
    int sum = 0, next = 0;
    list_node* head = new list_node;
    list_node* cur = head;
    
    while(head1 || head2 || next)
    {
        int val1 = (head1 == nullptr) ? 0 : head1->val;
        int val2 = (head2 == nullptr) ? 0 : head2->val;
        
        sum = val1 + val2 + next;
        next = 0;
        
        list_node* newNode = new list_node;
        if(sum >= 10)
        {
            next = sum / 10;
            sum %= 10;
        }
        newNode->val = sum;
        
        cur->next = newNode;
        cur = newNode;

        head1 = (head1 == nullptr) ? head1 : head1->next;
        head2 = (head2 == nullptr) ? head2 : head2->next;
    }
    head->next = reverse(head->next);
    return head->next;
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
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}