//203移除链表元素
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;成员变量
 *     ListNode() : val(0), next(nullptr) {}//第一个构造函数（默认构造函数）
 *     ListNode(int x) : val(x), next(nullptr) {}//这是带一个int参数的构造函数，创建节点时传入一个值x时调用。
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}//这是带两个参数的构造函数，创建节点时传入一个值x和一个ListNode指针时调用。
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
