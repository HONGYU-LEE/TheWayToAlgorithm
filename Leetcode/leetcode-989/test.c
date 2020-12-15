typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    ListNode* headA = l1, * headB = l2, *cur = NULL;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));

    cur = head;

    if(NULL == headA)
        return l2;

    if(NULL == headB)
        return l1;

    while(headA && headB)
    {
        if(headA->val > headB->val)
        {
            cur->next = headB;            
            headB = headB->next;
        }
        else
        {
            cur->next = headA;
            headA = headA->next;
        }
        cur = cur->next;
    }
    
    if(headA != NULL)
        cur->next = headA;

    if(headB != NULL)
        cur->next = headB;

    return head->next;

}


