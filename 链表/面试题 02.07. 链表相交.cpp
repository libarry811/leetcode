/面试题 02.07. 链表相交
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* cura=headA;
        ListNode* curb=headB;
        int lena=0;
        int lenb=0;
        int len=0;
        while(cura!=nullptr)
        {
            lena++;
            cura=cura->next;
        }
        while(curb!=nullptr)
        {
            lenb++;
            curb=curb->next;
        }
        cura=headA;
        curb=headB;
        if(lena>lenb)
        {
            len=lena-lenb;
            while(len>0)
            {
                cura=cura->next;
                len--;
            }
        }
        else
        {
            len=lenb-lena;
            while(len>0)
            {
                curb=curb->next;
                len--;
            }
        }
        while(cura&&curb)
        {
            if(cura==curb)
            {
                return cura;
            }
            else
            {
                cura=cura->next;
                curb=curb->next;
            }
        }
        return nullptr;
    }
};
