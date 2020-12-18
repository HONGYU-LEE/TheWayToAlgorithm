//解法1：使用栈
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

//解法2：不用栈，两层循环计算长度后反转区间
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
    //将begin-end反转
    pair<ListNode*, ListNode*> reverseSection(ListNode* begin, ListNode* end)
    {
        ListNode* prev = begin, *cur = begin->next, *next = nullptr;

        while(prev != end)
        {
            next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }
        return make_pair(end, begin);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k < 2)
        {
            return head;
        }

        ListNode* newHead = new ListNode, *cur = head, *prev = newHead, *tail = nullptr, *next = nullptr;
        newHead->next = head;
        
        while(cur)
        {
            tail = prev;
            for(int i = 0; i < k; i++)
            {
                tail = tail->next;
                if(!tail)
                {
                    return newHead->next;
                }
            }
            next = tail->next;

            //将反转后的链表拼接回来
            pair<ListNode*, ListNode*> res = reverseSection(cur, tail);
            cur = res.first;
            tail = res.second;

            prev->next = cur;
            tail->next = next;

            prev = tail;
            cur = tail->next;
        }
        return newHead->next;
    }
};