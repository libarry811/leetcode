/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*,Node*> oldmap;
        Node* cur = head;
        while(cur)//第一次遍历，创建这些节点
        {
            Node* newnode = new Node(cur->val);
            oldmap[cur] = newnode;
            cur = cur->next;
        }
        cur = head;
        while(cur)//第二次遍历，连接这些新节点
        {
            Node* newnode = oldmap[cur];
            newnode->next = oldmap[cur->next];
            newnode->random = oldmap[cur->random];
            cur = cur->next;
        }
        return oldmap[head];
    }
};
