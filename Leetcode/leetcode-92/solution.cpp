/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m < 0 || n < 0 || m > n || !head)
        {
            return head;
        }

        ListNode* mPrev = nullptr, *nNext = nullptr;
        ListNode* cur = head;
        int count = 0;

        while(cur)  //首先或者m - 1和n + 1的节点
        {
            count++;
            mPrev = (count == m - 1) ? cur : mPrev;
            nNext = (count == n + 1) ? cur : nNext;

            cur = cur->next;
        }
        if(count < n)   //如果越界，则直接返回
        {
            return head;    
        }

        ListNode* prev = (mPrev == nullptr) ? head : mPrev->next, *next = nullptr;    //如果从头节点开始反转，则prev为头节点
        cur = prev->next;
        
        prev->next = nNext; //让第一个位置的next指向n + 1的位置，因为其会被反转到末尾
        while(cur != nNext)  //翻转m-n的节点
        {
            next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }
        if(!mPrev)  //此时说明头节点也被反转了，此时头节点发生变化，新的头节点为反转后的第一个节点
        {
            return prev;
        }

        mPrev->next = prev; //让m - 1的next指向prev，即反转后的第一个位置

        return head;
    }
};

//方法2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseSection(ListNode* head, ListNode* begin, ListNode* end)
    {
        ListNode* prev = (begin == nullptr) ? head : begin->next, *cur = prev->next, *next = nullptr;
        
        prev->next = end;
        while(cur != end)
        {
            next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }
        if(begin != nullptr)
        {
            begin->next = prev;
        }
       
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m < 0 || n < 0 || m > n || !head)
        {
            return head;
        }

        ListNode* prev = nullptr, *next = nullptr, *cur = head;
        int count = 0;

        //找到m的前一个节点，以及n的后一个节点
        while(cur)
        {
            count++;
            prev = (count == m - 1) ? cur : prev;
            next = (count == n + 1) ? cur : next;

            cur = cur->next;
        }
        //越界了
        if(count < n)
        {
            return head;
        }

        cur = reverseSection(head, prev, next);
        //如果头节点为空，则反转后的位置为新的头节点
        return (prev == nullptr) ? cur : head;
    }
};