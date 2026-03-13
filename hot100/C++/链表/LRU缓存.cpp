// 定义双向链表节点结构
class node{
public:
    node* next;   // 指向后一个节点的指针
    node* pre;    // 指向前一个节点的指针
    int key;      // 节点的key（用于哈希表定位）
    int val;      // 节点存储的value

    // 节点构造函数：初始化key和val，前后指针置空
    node (int k,int v){
        key = k;
        val = v;
        next = NULL;
        pre = NULL;
    }
};

class LRUCache {
public:
    // LRU缓存构造函数：初始化容量 + 创建头尾虚拟节点
    LRUCache(int capacity) {
        cap = capacity;                // 设置缓存最大容量
        head = new node(0,0);          // 创建头虚拟节点（key=0,val=0）
        tail = new node(0,0);          // 创建尾虚拟节点（key=0,val=0）
        head->next = tail;            // 头节点的next指向尾节点
        tail->pre = head;              // 尾节点的pre指向头节点（修正你原代码笔误）
    }
    
    // 获取key对应的value
    int get(int key) {
        if(u_map.count(key))           // 如果哈希表中存在这个key
        {
            remove(u_map[key]);       // 把该节点从原来的位置删除
            headinsert(u_map[key]);   // 把该节点移动到链表头部（表示最近使用）
            return u_map[key]->val;    // 返回节点的value
        }
        return -1;                     // 不存在返回-1
    }
    
    // 插入/更新key-value
    void put(int key, int value) {
        if(u_map.count(key))           // 如果key已经存在
        {
            remove(u_map[key]);       // 先删除旧节点
            delete u_map[key];        // 释放旧节点内存
            u_map[key] = NULL;        // 哈希表对应位置置空
        }
        node* tmp = new node(key,value); // 创建新节点
        headinsert(tmp);              // 新节点插入头部
        u_map[key] = tmp;             // 哈希表记录key与节点的映射
        
        if(u_map.size()>cap)          // 如果缓存超过容量
        {
            node* todel = tail->pre;  // 找到要删除的节点（最后一个，最久未使用）
            remove(todel);            // 从链表中移除
            u_map.erase(todel->key);  // 从哈希表中删除映射
            delete todel;             // 释放节点内存
        }
    }

    // 从双向链表中删除指定节点
    void remove(node* tmp)
    {
        node* tmp_pre = tmp->pre;     // 保存要删除节点的前驱
        node* tmp_nxt = tmp->next;    // 保存要删除节点的后继
        tmp_pre->next = tmp_nxt;      // 前驱的next指向后继
        tmp_nxt->pre = tmp_pre;      // 后继的pre指向前驱
    }

    // 将节点插入到链表头部（靠近head）
    void headinsert(node* tmp)
    {
        node* nxt = head->next;       // 保存原来的第一个节点
        head->next = tmp;             // head的next指向新节点
        tmp->pre = head;              // 新节点的pre指向head
        tmp->next = nxt;              // 新节点的next指向原来第一个节点
        nxt->pre = tmp;               // 原来第一个节点的pre指向新节点
    }

private:                            // 本题需要用到双向链表和哈希表
    int cap;                        // 缓存容量
    node* head;                     // 双向链表头节点（虚拟）
    node* tail;                     // 双向链表尾节点（虚拟）
    unordered_map<int,node*> u_map;  // 哈希表：key -> 链表节点地址
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
