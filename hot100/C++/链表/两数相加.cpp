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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        int num1,num2;
        int sum;
        int carry = 0;//进位
        while(l1||l2||carry)
        {
            num1 = 0;
            num2 = 0;
            if(l1)
            {
                num1 = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                num2 = l2->val;
                l2 = l2->next;
            }
            sum = num1 + num2 + carry;
            int newval = sum%10;
            res->next = new ListNode(newval);
            res = res->next;
            carry = sum/10;
        }
        return dummy->next;
    }
};
