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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=head;
        ListNode* curnode=dummyhead;
        while(curnode->next!=nullptr)
        {
            if(curnode->next->val==val)
            {
                ListNode* tmp=curnode->next;
                curnode->next=curnode->next->next;
                delete tmp;
            }
            else
            {
                curnode=curnode->next;
            }
        }
        head=dummyhead->next;
        delete dummyhead;
        return head;
    }
};
