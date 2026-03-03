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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* res = NULL;
        if(!list1||!list2)
        {
            if(!list1)
            {
                res = list2;
            }
            else
            {
                res = list1;
            }
            return res;
        }
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* out;
        while(first&&second)
        {
            if(second->val>=first->val)
            {
                if(!res)
                {
                    res = list1;
                    out = res;
                }
                else
                {
                    res->next = first;
                    res = res->next;
                }
                first = first->next;
            }
            else
            {
                if(!res)
                {
                    res = list2;
                    out = res;
                }
                else
                {
                    res->next = second;
                    res = res->next;
                }
                second = second->next;
            }
        }
        if(first)//如果第一个链表还有剩余节点
        {
            res->next = first;
        }
        if(second)//如果第二个链表还有剩余节点
        {
            res->next = second;
        }
        return out;
    }
};
