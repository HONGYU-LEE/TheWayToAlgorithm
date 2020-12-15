class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* cur = head;
        while(cur)
        {
            Node* next = cur->next;

            Node* copy = (Node*)malloc(sizeof(Node)); 
            copy->val = cur->val;

            cur->next = copy;
            copy->next = next;

            cur  = next;
        }
        //拷贝所有节点插入到原节点后
        cur = head;

        while(cur)
        {
            Node* copy = cur->next;
            
            if(cur->random)
                copy->random = cur->random->next;
            else
                copy->random = NULL;
            
            cur = copy->next;
        }
        //拷贝random域
        cur = head;

        Node* copyhead = NULL;
        Node* copytail = NULL;

        while(cur)
        {
            Node* copy = cur->next;
            Node* next = copy->next;

            if(!copytail)
                copyhead = copytail = copy;
            else
            {
                copytail->next = copy;
                copytail = copy;
            }

            cur->next = next;
            cur = next;

        }
        //拆分链表

        return copyhead;
    }
};
