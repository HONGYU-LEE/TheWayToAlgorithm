# include <iostream>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

/*
    思路：首先找到反转位置m-n的前一个位置和后一个位置，即m-1和n+1
    例如1-2-3-4-5，反转2-4，我们找到1和5
    接着反转m-n，
    1 4-3-2 5 我们让m-1指向原来的结束位置，让原来的起始位置指向n+1，就成功完成了反转
    1-4-3-2-5

    需要注意的是，如果头节点也包含着m-n的范围中，则n节点就是我们新的头节点
*/
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


list_node * reverse_list(list_node * head, int L, int R)
{
    //////在下面完成代码
    if(L < 0 || R < 0 || L > R || !head)
    {
        return head;
    }

    list_node* mPrev = nullptr, *nNext = nullptr;
    list_node* cur = head;
    int count = 0;

    while(cur)  //首先或者m - 1和n + 1的节点
    {
        count++;
        mPrev = (count == L - 1) ? cur : mPrev;
        nNext = (count == R + 1) ? cur : nNext;

        cur = cur->next;
    }
    if(count < R)   //如果越界，则直接返回
    {
        return head;    
    }

    list_node* prev = (mPrev == nullptr) ? head : mPrev->next, *next = nullptr;    //如果从头节点开始反转，则prev为头节点
    cur = prev->next;

    prev->next = nNext; //让第一个位置的next指向n + 1的位置，因为其会被反转到末尾
    while(cur != nNext)  //翻转m-n的节点
    {
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }
    if(!mPrev)  //此时说明头节点也被反转了，此时头节点发生变化，新的头节点为反转后的第一个节点
    {
        return prev;
    }

    mPrev->next = prev; //让m - 1的next指向prev，即反转后的第一个位置

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
    int L, R;
    list_node * head = input_list();
    scanf("%d%d", &L, &R);
    list_node * new_head = reverse_list(head, L, R);
    print_list(new_head);
    return 0;
}