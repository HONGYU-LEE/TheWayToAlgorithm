typedef struct ListNode ListNode;
bool hasCycle(struct ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                return true;
            }
        }
    return false;
}
