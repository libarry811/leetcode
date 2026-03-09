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
    ListNode* sortList(ListNode* head) 
    {
        //采用递归和归并排序
        if(!head||!head->next)
        {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }//链表一分为二
        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = NULL;
        first = sortList(first);
        second = sortList(second);
        return mergelist(first,second);
    }
    ListNode* mergelist(ListNode* left,ListNode* right)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;//尾指针始终指向合并链表的最后一个节点
        while(left&&right)
        {
            if(left->val<right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if(left)//哪边还有剩余元素
        {
            tail->next = left;
        }
        else
        {
            tail->next = right;
        }
        return dummy->next;
    }
};
