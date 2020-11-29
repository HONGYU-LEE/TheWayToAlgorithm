# include <iostream>
# include <unordered_set>
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

//利用哈希表保存节点，当重复出现后删除
list_node * remove_rep(list_node * head)
{
    //////在下面完成代码
    unordered_set<int> set;
    
    list_node* newHead = new list_node;
    newHead->next = head;
    list_node* cur = head, *prev = newHead, *next = nullptr;

    while(cur)
    {
        if(set.find(cur->val) != set.end())
        {
            next = cur->next;
            prev->next = next;
            cur = next;
        }
        else
        {
            set.insert(cur->val);
            prev = cur;
            cur = cur->next;
        }
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
    list_node * head = input_list();
    list_node * new_head = remove_rep(head);
    print_list(new_head);
    return 0;
}