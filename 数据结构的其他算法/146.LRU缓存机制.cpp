// 这个题考察LRU（Least Recently Used），一种缓存淘汰策略，简单说就是当内存不足时，优先淘汰最久未使用的数据
// 还有LFU（Least Frequently Used），淘汰使用次数最少的数据，相比LRU更难一些
// 在java中借助LinkedHashMap实现这个算法，但是c++并没有，所以得自己实现一个类似的结构——哈希链表（哈希表+双向链表）
#include <iostream>
#include <unordered_map>
using namespace std;
struct Node
{
    int key, val;
    Node *pre;
    Node *next;
    Node(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {}
};
class LRUCache
{
private:
    int size;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> map;

public:
    LRUCache(int capacity)
    {
        this->size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
    // 表尾是最近刚使用的数据
    void addLast(Node *node)
    {
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
    }
    // 删除一个节点
    void remove(Node *node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    // 删除头结点，head只是指向头结点的指针
    void removeFirst()
    {
        if (head->next == tail)
        {
            return;
        }
        Node *first = head->next;
        remove(first);
    }

    int get(int key)
    {
        if (map.count(key) > 0)
        {
            Node *node = map[key];
            int val = node->val;
            remove(node);
            addLast(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (map.count(key) > 0)
        {
            Node *node = map[key];
            remove(node);
            node->val = value;
            map[key] = node;
            addLast(node);
        }
        else
        {
            Node *node = new Node(key, value);
            if (map.size() >= size)
            {
                removeFirst();
                // 从unordered_map中删除元素的方法要学习一下
                unordered_map<int, Node *>::iterator iter = map.find(head->next->key);
                map.erase(iter);
            }

            addLast(node);
            map[key] = node;
        }
    }
};
int main()
{
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl;
    obj->put(3,3);
    cout<<obj->get(2)<<endl;
    obj->put(4,4);
    cout<<obj->get(1)<<endl;
    cout<<obj->get(3)<<endl;
    cout<<obj->get(4)<<endl;
    return 0;
}