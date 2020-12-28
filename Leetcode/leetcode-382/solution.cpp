/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode* oddHead = head, *evenHead = head->next;
        ListNode* oddTail = head, *evenTail = head->next;

        //将链表拆分为奇数链表和偶数链表，然后将它们合并
        while(evenTail && evenTail->next)
        {
            oddTail->next = evenTail->next;
            evenTail->next = evenTail->next->next;

            oddTail = oddTail->next;
            evenTail = evenTail->next;
        }
        oddTail->next = evenHead;   //连接奇偶链表

        return oddHead;
    }
};