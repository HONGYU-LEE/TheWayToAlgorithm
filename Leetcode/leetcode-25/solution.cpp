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
    ListNode* reverseSection(stack<ListNode*>& st, ListNode* begin, ListNode* end)
    {
        ListNode* cur = st.top();
        st.pop();
        if(begin)
        {
            begin->next = cur;
        }
        ListNode* next = nullptr;

        while(!st.empty())
        {
            next = st.top();
            st.pop();

            cur->next = next;
            cur = next;
        }
        cur->next = end;

        return cur;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr | k < 2)
        {
            return head;
        }    

        ListNode* newHead = head, *cur = head, *prev = nullptr, *next = nullptr;
        stack<ListNode*> st;
        while(cur)
        {
            next = cur->next;
            st.push(cur);

            if(st.size() == k)
            {
                prev = reverseSection(st, prev, next);
                newHead = head == newHead ? cur : newHead;
            }
            cur = next;
        }
        return newHead;
    }
};