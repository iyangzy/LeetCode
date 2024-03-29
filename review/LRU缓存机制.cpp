// LRU 的全称是 Least Recently Used
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
private:
    struct DListNode
    {
        int key, val;
        DListNode *pre, *next;
        DListNode(int x, int y) : key(x), val(y), pre(nullptr), next(nullptr){};
    };

public:
    unordered_map<int, DListNode *> map;
    DListNode *head, *tail;
    int size, cap;
    LRUCache(int capacity)
    {
        head = new DListNode(-1, -1);
        tail = new DListNode(-1, -1);
        head->next = tail;
        tail->pre = head;

        size = 0;
        cap = capacity;
    }

    void removeNode(DListNode *node)
    {
        unordered_map<int, DListNode *>::iterator iter = map.find(node->key);
        map.erase(iter);

        DListNode *preNode = node->pre;
        DListNode *nextNode = node->next;
        preNode->next = nextNode;
        nextNode->pre = preNode;
        size--;
    }

    void addNode(DListNode *node)
    {
        map[node->key] = node;

        node->pre = tail->pre;
        tail->pre->next = node;

        node->next = tail;
        tail->pre = node;
        size++;
        if (size > cap)
        {
            removeNode(head->next);
        }
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
        {
            return -1;
        }

        DListNode *node = map[key];
        removeNode(node);
        addNode(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (map.find(key) == map.end())
        {
            DListNode *node = new DListNode(key, value);
            addNode(node);
            return;
        }
        DListNode *node = map[key];
        removeNode(node);
        node->val = value;
        addNode(node);
    }
};
int main()
{
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(2, 1);              // 缓存是 {2=1}
    lRUCache->put(2, 2);              // 缓存是 {2=2}
    cout << lRUCache->get(2) << endl; // 返回 2
    lRUCache->put(1, 1);              // 缓存是 {2=1,1=1}
    lRUCache->put(4, 1);              // 缓存是 {1=1,4=1}
    cout << lRUCache->get(2) << endl; // 返回 -1

    // LRUCache *lRUCache = new LRUCache(2);
    // lRUCache->put(1, 1);              // 缓存是 {1=1}
    // lRUCache->put(2, 2);              // 缓存是 {1=1, 2=2}
    // cout << lRUCache->get(1) << endl; // 返回 1
    // lRUCache->put(3, 3);              // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    // cout << lRUCache->get(2) << endl; // 返回 -1 (未找到)
    // lRUCache->put(4, 4);              // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    // cout << lRUCache->get(1) << endl; // 返回 -1 (未找到)
    // cout << lRUCache->get(3) << endl; // 返回 3
    // cout << lRUCache->get(4) << endl; // 返回 4
    return 0;
}