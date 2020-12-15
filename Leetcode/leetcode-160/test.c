typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    ListNode* LongList = headA, *ShortList = headB;
    int LenA = 0, LenB = 0, i;
    if(headA == NULL || headB == NULL)
        return NULL;
    while(LongList->next != NULL)
    {
        LenA++;
        LongList = LongList->next;
    }
    while(ShortList->next != NULL)
    {
        LenB++;
        ShortList = ShortList->next;
    }

    i = LenA - LenB;

    if(i >= 0)
    {
        LongList = headA;
        ShortList = headB;
    }
    else
    {
        LongList = headB;
        ShortList = headA;
        i *= -1;
    }

    
    while(i--)
    {
        LongList = LongList->next;
    }

    while(LongList != ShortList)
    {
        LongList = LongList->next;
        ShortList = ShortList->next;
    }

    return LongList;
}
