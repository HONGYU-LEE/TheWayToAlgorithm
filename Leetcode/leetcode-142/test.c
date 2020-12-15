typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) 
{
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            ListNode* cur = head;
            while(1)
            {
                if(cur != slow)
                {
                    cur = cur->next;
                    slow = slow->next;
                }
                else
                {
                    return cur;
                }
            }
        }
    }
    return NULL;
}
