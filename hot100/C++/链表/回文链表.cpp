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
    ListNode* reverse(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* temp = NULL;
        ListNode* pre = NULL;
        while(cur)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) 
    {
        //寻找链表中心将链表一分为二
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //翻转后半段链表
        ListNode* second = reverse(slow->next);
        //对比两部分链表
        ListNode* first = head;
        while(second)//后半可能比前半少应该节点（奇数情况），以后半数量为条件，不用管奇数时中间的元素
        {
            if(first->val!=second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
