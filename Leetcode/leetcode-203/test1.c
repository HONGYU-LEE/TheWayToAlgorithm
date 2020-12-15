typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val){
    ListNode *p = head, *pre = NULL;
    while(p)
    {      
        if(p->val == val)
        {
            ListNode *q = p->next;
            free(p);
            if(p == head)
                head = q;
            else
                pre->next = q;
                p = q;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return head;
}
