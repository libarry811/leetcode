//707链表基础操作
class MyLinkedList {
public:
    struct Linkednode
    {
        int val;
        Linkednode* next;
        Linkednode(int val):val(val),next(nullptr) {}
    };
    MyLinkedList() 
    {
        dummyhead=new Linkednode(0);
        size=0;
    }
    
    int get(int index) 
    {
        if(index<0||index>size-1)
        {
            return -1;
        }
        Linkednode* cur=dummyhead->next;
        while(index)
        {
            cur=cur->next;
            index--;
        }
        return cur->val;
    }
    
    void addAtHead(int val) 
    {
        Linkednode* add=new Linkednode(val);
        Linkednode* cur=dummyhead->next;
        add->next=cur;
        dummyhead->next=add;
        size++;
        //delete cur;
    }
    
    void addAtTail(int val) 
    {
        Linkednode* cur=dummyhead;
        Linkednode* add=new Linkednode(val);
        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }
        cur->next=add;
        size++;
    }
    
    void addAtIndex(int index, int val) 
    {
        Linkednode* add=new Linkednode(val);
        Linkednode* cur=dummyhead->next;
        if(index<0||index>size)
        {
            delete add;
            return;
        }
        else if(index==0)
        {
            add->next=cur;
            dummyhead->next=add;
            size++;
            return;
        }
        else
        {
            cur=dummyhead;
            while(index)
            {
                index--;
                cur=cur->next;
            }
            add->next=cur->next;
            cur->next=add;
            size++;
            return;
        }
    }
    
    void deleteAtIndex(int index) 
    {
        if(index<0||index>size-1)
        {
            return;
        }
        Linkednode* cur=dummyhead;
        while(index)
        {
            cur=cur->next;
            index--;
        }
        Linkednode* del=cur->next;
        cur->next=cur->next->next;
        size--;
        delete del;
    }
private:
    int size;
    Linkednode* dummyhead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
