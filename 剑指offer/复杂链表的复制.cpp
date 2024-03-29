#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// 哈希表，看起来更简单
Node *copyRandomList(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    unordered_map<Node*,Node*> hashMap;
    Node *p = head;
    while (p)
    {
        Node *t = new Node(p->val);
        hashMap.insert(pair(p,t));
        p = p->next;
    }
    p = head;
    while (p)
    {
        hashMap[p]->next = hashMap[p->next];
        hashMap[p]->random = hashMap[p->random];
        p = p->next;
    }
    return hashMap[head];
}
// 书上的解法，先拼接再拷贝，先拷贝节点并添加到原节点的后面，再拷贝random指针，最后将拷贝的链表与原链表拆分
// void copyNode(Node *head)
// {
//     Node *p = head;
//     while (p)
//     {
//         Node *t = new Node(p->val);
//         t->next = p->next;
//         t->random = NULL;
//         p->next = t;
//         p = t->next;
//     }
// }
// void copyRandom(Node *head)
// {
//     Node *p = head;
//     while (p)
//     {
//         if (p->random != NULL)
//         {
//             p->next->random = p->random->next;
//         }
//         p = p->next->next;
//     }
// }
// Node *reconnent(Node *head)
// {
//     Node *copy = nullptr, *copyHead = nullptr;
//     Node *p = head;
//     if (p)
//     {
//         copyHead = copy = p->next;
//         p->next = copy->next;
//         p = p->next;
//     }

//     while (p)
//     {
//         copy->next = p->next;
//         copy = copy->next;
//         p->next = copy->next;
//         p = p->next;
//     }
//     return copyHead;
// }
// Node *copyRandomList(Node *head)
// {
//     copyNode(head);
//     copyRandom(head);
//     return reconnent(head);
// }
int main()
{
    vector<int> v = {7, 13, 11, 10, 1};
    Node *head = new Node(v[0]);
    Node *p = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *t = new Node(v[i]);
        t->random = NULL;
        p->next = t;
        p = t;
    }
    Node *copy = copyRandomList(head);
    return 0;
}