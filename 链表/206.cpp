/206反转链表
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
    ListNode* reverse(ListNode* pre,ListNode* cur)
    {
        if(cur==nullptr)
        {
            return pre;
        }
        ListNode* tmp=cur->next;
        cur->next=pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,tmp);
    }
    ListNode* reverseList(ListNode* head) 
    {
        /*双指针迭代法
        ListNode* cur=head;
        ListNode* pre=nullptr;
        ListNode* tmp=nullptr;
        while(cur!=nullptr)
        {
            tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
        */
        //递归法
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(nullptr,head);
    }
};
