// LFU的难点，在删除是有多个相同频率的数据，要删除其中那个最旧的，因此要存在时序性
// labuladong的代码是java的，使用了java的LinkedHashSet，c++没有，下面的解法是力扣的官解
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
struct Node
{
    int key, val, freq;
    Node(int k, int v, int f) : key(k), val(v), freq(f) {}
};

class LFUCache
{
    int minFreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;// key_table 以键值 key 为索引，每个索引存放对应缓存在 freq_table 中链表里的内存地址
    unordered_map<int, list<Node>> freq_table;// freq_table 以频率 freq 为索引，每个索引存放一个双向链表，这个链表里存放所有使用频率为 freq 的缓存

public:
    LFUCache(int capacity)
    {
        minFreq = 0;
        this->capacity = capacity;
        key_table.clear();
        freq_table.clear();
    }

    int get(int key)
    {
        if (capacity == 0)
        {
            return -1;
        }
        auto it = key_table.find(key);
        if (it == key_table.end())
        {
            return -1;
        }
        list<Node>::iterator node = it->second;// first对应的是key，second对应的事value，即list的迭代器
        int val = node->val, freq = node->freq;
        freq_table[freq].erase(node);
        if (freq_table[freq].size() == 0)
        {
            freq_table.erase(freq);
            if (minFreq == freq)
            {
                minFreq++;
            }
        }
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }
        auto it = key_table.find(key);
        if (it == key_table.end())
        {
            if (key_table.size() == capacity)
            {
                auto it2 = freq_table[minFreq].back();
                key_table.erase(it2.key);
                freq_table[minFreq].pop_back();
                if (freq_table[minFreq].size() == 0)
                {
                    freq_table.erase(minFreq);
                }
            }
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minFreq = 1;
        }
        else
        {
            list<Node>::iterator node = it->second;
            int freq = node->freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0)
            {
                freq_table.erase(freq);
                if (minFreq == freq)
                {
                    minFreq++;
                }
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};
int main()
{
    LFUCache *obj = new LFUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    return 0;
}