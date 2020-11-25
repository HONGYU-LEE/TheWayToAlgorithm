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


list_node * relocate(list_node * head)
{
    //////在下面完成代码
    //首先使用快慢指针来找到中间节点
    list_node* slow = head, *fast = head->next;

    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    list_node* right = slow->next;    //将左右链表拆开
    slow->next = nullptr;    
    
    list_node* left = head;    //奇偶合并链表
    while(left->next)
    {
        list_node* next = right->next;
        
        right->next = left->next;
        left->next = right;
        
        left = right->next;
        right = next;
    }
    left->next = right;
    /*
    这样思路更加清晰，但是需要小心指针悬空的问题
     while(left && right)
    {
        list_node* lNext = left->next;
        list_node* rNext = right->next;
        
        left->next = right;
        left = lNext;
        
        if(left == nullptr)
        {
            break;
        }
        right->next = left;
        right = rNext;
        
    }
    */


    return head;
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
    list_node * new_head = relocate(head);
    print_list(new_head);
    return 0;
}