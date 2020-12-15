class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = new ListNode(NULL);
        newHead->next = head;
        ListNode* cur = newHead, *del = newHead;
        if(head == NULL || n == 0)
            return NULL;

        for(int i = 0; i < n; i++)
        {
            cur = cur->next;
        }
 
        while(cur->next)
        {
            cur = cur->next;
            del = del->next;
        }
        
        ListNode* next = del->next;
        del->next = next->next;  
        delete next; 

        return newHead->next;

    }
};
