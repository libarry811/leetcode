/24两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* dummyhead=new ListNode(0);// 设置一个虚拟头结点
        dummyhead->next=head;// 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur=dummyhead;
        ListNode* temp=nullptr;
        ListNode* aft=nullptr;
        ListNode* result=dummyhead->next;
        while(cur->next)
        {
            aft=cur->next;
            temp=aft->next;
            if(aft!=nullptr&&temp!=nullptr)
            {
                aft->next=temp->next;
                cur->next=temp;
                temp->next=aft;
                cur=aft;
            }
            else
            {
                result=dummyhead->next;
                delete dummyhead;
                return result;
            }
        }
        result=dummyhead->next;
        delete dummyhead;
        return result;
    }
};
