#include<iostream>
#include<map>
using namespace std;

struct Node{
    int val;
    struct Node * lch, * rch;
};

Node * input_BST()
{
    int n, fa, lch, rch;
    scanf("%d", &n);
    Node * root, * new_node;
    map<int, Node *> mp;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &fa, &lch, &rch);
        if (mp.find(fa) == mp.end()) {
            new_node = (Node *)malloc(sizeof(Node));
            mp[fa] = new_node;
            new_node->val = fa;
            if (i == 1) root = new_node;
        }
        if (lch && mp.find(lch) == mp.end()) {
            new_node = (Node *)malloc(sizeof(Node));
            mp[lch] = new_node;
            new_node->val = lch; new_node->lch = new_node->rch = NULL;
        }
        if (rch && mp.find(rch) == mp.end()) {
            new_node = (Node *)malloc(sizeof(Node));
            mp[rch] = new_node;
            new_node->val = rch; new_node->lch = new_node->rch = NULL;
        }
        mp[fa]->lch = (lch ? mp[lch] : NULL);
        mp[fa]->rch = (rch ? mp[rch] : NULL);
    }
    return root;
}

//通过中序遍历来收集所有节点
void inOrderTravel(Node* cur, Node*& prev)
{
    if(!cur)
    {
        return;
    }
    
    if(cur->lch)
        inOrderTravel(cur->lch, prev);
    
    if(prev)
        prev->rch = cur;
    
    cur->lch = prev;
    prev = cur;
    
    if(cur->rch)
        inOrderTravel(cur->rch, prev);
}

Node * convert(Node * root)
{
    //////在下面完成代码
    if(!root)
    {
        return nullptr;
    }
    Node* prev = nullptr;
    inOrderTravel(root, prev);

    while(prev->lch)    //找到最左节点
    {
        prev = prev->lch;
    }
    return prev;
}

void print_double_list(Node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->rch;
    }
    puts("");
}

int main ()
{
    Node * root = input_BST();
    Node * new_double_head = convert(root);
    print_double_list(new_double_head);
    return 0;
}