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
        if(!list1)
        {
            res = list2;
            return res;
        }
        if(!list2)
        {
            res = list1;
            return res;
        }
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* add = dummy;//用于向结果链表添加节点
        while(first&&second)
        {
            if(first->val<second->val)
            {
                add->next = first;
                first = first->next;
                add = add->next;
            }
            else
            {
                add->next = second;
                second = second->next;
                add = add->next;
            }
        }
        if(first)//如果还有剩余元素
        {
            add->next = first;
        }
        if(second)
        {
            add->next = second;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        //归并排序
        if(lists.size()==0)
        {
            return NULL;
        }
        while(lists.size()>1)
        {
            vector<ListNode*> tmp;//存储合并后的链表
            for(int i=0;i<lists.size();i+=2)
            {
        
                ListNode* l1 = lists[i];
                ListNode* l2 = NULL;//防止l2溢出，先进行赋空
                if(i+1<lists.size())
                {
                    l2 = lists[i+1];//不溢出再赋值
                }
                tmp.push_back(mergeTwoLists(l1,l2));
            }
            lists = tmp;
        }
        return lists[0];
    }
};
