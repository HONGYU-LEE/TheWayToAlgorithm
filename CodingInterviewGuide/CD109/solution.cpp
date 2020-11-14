#include<iostream>

using namespace std;

class Node
{
public:
    Node(int val)
        : _val(val)
    {}
    
    int _val;
    Node* _next;
};

//用环形链表来模拟删除过程
void Joseph(int n, int m)
{
    //构造循环链表
    Node* head = new Node(1);
    Node* cur = head;
    for(int i = 1; i < n; i++)
    {
        Node* newNode = new Node(i + 1);
        newNode->_next = cur->_next;
        cur->_next = newNode;
        cur = newNode;
    }
    
    cur->_next = head;
    Node* tail = cur, *prev = tail;
    cur = head;
    int count = 0;
    
    //不断删除节点，当剩下一个节点的时候结束
    while(cur != cur->_next)
    {
        count++;
        Node* next = cur->_next;
        
        if(count == m)    //删除节点
        {
            prev->_next = next;
            delete cur;
            count = 0;
            
            cur = next;
        } 
        else
        {
            prev = prev->_next;
            cur = cur->_next;
        }

    }
    
    cout << cur->_val << endl;
    delete cur;
}

int main()
{
    int m, n;
    while(cin >> n >> m)
    {
        Joseph(n, m);
    }

    return 0;
}