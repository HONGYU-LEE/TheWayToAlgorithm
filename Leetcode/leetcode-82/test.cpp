class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first = new ListNode(0);
        first->next = head;

        ListNode* prev = first;
        ListNode* cur = first->next;

        while(cur && cur->next)
        {
            if(cur->val == cur->next->val)
            {
                while(cur->next && cur->val == cur->next->val)
                {
                    cur = cur->next;
                }
                prev->next = cur->next;
                cur = cur->next;
            }
            else
            {
                prev = prev->next;
                cur = cur->next;
            }

        }
        
        return first->next;
    }
};
