# include <iostream>
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


list_node * merge_list(list_node * head1, list_node * head2)
{
    //////在下面完成代码
    list_node* newHead = new list_node, *cur = newHead, *cur1 = head1, *cur2 = head2;
    
    while(cur1 && cur2)
    {
        if(cur1->val < cur2->val)
        {
            cur->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
    
    //到这里的时候只会剩下一个链表没插入完，因为其本身就有序，所以直接整段插入即可
    if(cur1)
    {
        cur->next = cur1;
    }
    else if(cur2)
    {
        cur->next = cur2;
    }
    
    return newHead->next;
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
    list_node * head1 = input_list();
    list_node * head2 = input_list();
    list_node * new_head = merge_list(head1, head2);
    print_list(new_head);
    return 0;
}