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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* temp;
        while(cur)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* dummy = new ListNode(0,head);
        ListNode* pre = dummy;
        ListNode* start = dummy;
        ListNode* end = dummy;
        while(end)
        {
            for(int i=0;i<k;i++)
            {
                end = end->next;//寻找k个节点
                if(!end)
                {
                    return dummy->next;
                }
            }
            ListNode* nextnode = end->next;//翻转区域后面的第一个节点
            //翻转链表,pre记录改组前一个节点，start记录翻转区域第一个节点
            start = pre->next;
            end->next = NULL;
            pre->next = reverseList(start);
            start->next = nextnode;
            pre = start;
            end = pre;
        }
        return dummy->next;
    }
};
