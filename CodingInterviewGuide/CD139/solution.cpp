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


/*
    思路很简单，每次找到最小的节点的前一个位置，通过它把最小节点从未排序链表中删除，再将这个节点尾插到有序链表中，实现选择排序。
*/
//获取当前最小的节点
list_node* getSmallPrev(list_node* head)
{
    list_node* cur = head, *prev = nullptr, *small = nullptr, *smallPrev = nullptr;
    
    while(cur)
    {
        if(!small || cur->val < small->val)
        {
            small = cur;
            smallPrev = prev;
        }
        prev = cur;
        cur = cur->next;
    }
    return smallPrev;
}

list_node * selection_sort(list_node * head)
{
    //////在下面完成代码
    list_node* sortList = nullptr;    //有序部分
    list_node* unsortList = head;            //无序部分
    
    list_node* small = nullptr, *smallPrev;    //无序中的最小值节点与其前节点

    while(unsortList)
    {
        smallPrev = getSmallPrev(unsortList);    //获取未排序部分的最小节点的前一个位置
        if(smallPrev)
        {
            small = smallPrev->next;
            smallPrev->next = small->next;    //从原链表中删除最小节点
        }
        else  //如果为空则说明当前第一个位置就是最小节点，不存在前驱节点
        {
            small = unsortList;
            unsortList = unsortList->next;    //删除头节点，让下一个位置成为新的头节点
        }
        
        if(sortList == nullptr)
        {
            head = small;
        }
        else
        {
            sortList->next = small;
        }
        sortList = small;
    }
    
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
    list_node * new_head = selection_sort(head);
    print_list(new_head);
    return 0;
}