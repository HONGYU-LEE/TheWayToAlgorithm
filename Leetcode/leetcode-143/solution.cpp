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
    //反转链表
    ListNode* reverse(ListNode* head)
    {
        ListNode* cur = head, *prev = nullptr, *next = nullptr;

        while(cur)
        {
            next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }
        return prev;
    }

    //合并链表
    void merge()
    {


    }

    void reorderList(ListNode* head) {
        if(!head || !head->next)
        {
            return;
        }

        ListNode* slow = head, *fast = head;

        while(fast->next && fast->next->next)   //快慢指针找到中间节点
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = slow->next;
        slow->next = nullptr;   //拆分链表

        ListNode* left = head;  //合并链表
        right = reverse(right); //反转右部分链表
        
        while(left && right)   
        {
            ListNode* rNext = right->next;
            ListNode* lNext = left->next;
            
            left->next = right;
            left = lNext;

            right->next = left;
            right = rNext;
        }
    }
};