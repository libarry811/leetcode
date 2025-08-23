//19. 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummyhead=new ListNode(0);
        dummyhead->next=head;
        ListNode* fast=dummyhead;
        ListNode* slow=dummyhead;
        ListNode* temp=nullptr;
        ListNode* result=nullptr;
        while(n>=0)
        {
            fast=fast->next;
            n--;
        }
        while(fast!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        temp=slow->next;
        slow->next=temp->next;
        delete temp;
        result=dummyhead->next;
        delete dummyhead;
        return result;
    }
    
};
