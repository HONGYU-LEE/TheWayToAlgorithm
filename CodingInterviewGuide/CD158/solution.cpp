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
            if (i == n) {
                new_pnode->next = phead;
            }
        }
    }
    return phead;
}


list_node * insert_num(list_node * head, int num)
{
    //////在下面完成代码
    list_node* cur = head->next, *prev = head;
    
    while(cur != head)    //当走到头时说明走了一圈都没有合适的位置，此时就代表sum比链表中所有节点都小
    {
        //如果到了合适的位置，就退出
        if(cur->val >= num && prev->val <= num)
        {
            break;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    list_node* newNode = new list_node; //插入新节点
    newNode->val = num;
        
    newNode->next = prev->next;
    prev->next = newNode;

    if(head->val > num) //如果比头节点小，则让其成为新的头节点
    {
        head = newNode;
    }
    
    return head;
}


void print_list(list_node * head)
{
    list_node * h = head;
    while (1) {
        printf("%d ", head->val);
        if (head->next == h) break;
        head = head->next;
    }
    puts("");
}


int main ()
{
    list_node * head = input_list();
    int n;
    scanf("%d", &n);
    list_node * new_head = insert_num(head, n);
    print_list(new_head);
    return 0;
}