# include <iostream>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * find_kth_node(list_node * head, int k)
{
    list_node * c = head;
    for (int i = 1; i < k; ++i) c = c->next;
    return c;
}

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

//把下一个节点的值拿过来，然后把那个节点删除掉
void remove_node_wired(list_node * node)
{
    //////在下面完成代码
    list_node* next = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    
    delete next;
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
    int n;
    scanf("%d", &n);
    list_node * node = find_kth_node(head, n);
    remove_node_wired(node);
    print_list(head);
    return 0;
}