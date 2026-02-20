/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* cura = headA;
        ListNode* curb = headB;
        int lena = 0,lenb = 0;
        int num = 0;
        while(cura!=NULL)
        {
            lena++;
            cura = cura -> next;
        }
        while(curb!=NULL)
        {
            lenb++;
            curb = curb -> next;
        }
        cura = headA;
        curb = headB;
        if(lena>lenb)
        {
            num = lena-lenb;
            for(int i=0;i<num;i++)
            {
                cura = cura -> next;
            }
        }
        else
        {
            num = lenb-lena;
            for(int i=0;i<num;i++)
            {
                curb = curb -> next;
            }
        }
        while(cura!=NULL||curb!=NULL)
        {
            if(cura==curb)
            {
                return cura;
            }
            cura = cura -> next;
            curb = curb -> next;
        }
        return NULL;
    }
};
