#include <iostream>
#include <unordered_map>
using namespace std;
struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
RandomListNode *Clone(RandomListNode *pHead)
{
    if (!pHead)
    {
        return nullptr;
    }

    unordered_map<int, RandomListNode *> nodes;
    RandomListNode *newHead = new RandomListNode(pHead->label);
    nodes.insert(pair<int, RandomListNode *>(newHead->label, newHead));
    RandomListNode *p = pHead, *t = newHead;
    while (p->next)
    {
        RandomListNode *nxt = new RandomListNode(p->next->label);
        nodes.insert(pair<int, RandomListNode *>(nxt->label, nxt));
        t->next = nxt;
        t = t->next;
        p = p->next;
    }
    p = pHead;
    t = newHead;
    while (p)
    {
        if (p->random)
        {
            auto iter = nodes.find(p->random->label);
            t->random = iter->second;
        }
        p = p->next;
        t = t->next;
    }
    return newHead;
}
int main()
{
    RandomListNode *head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->next->next->next = new RandomListNode(4);
    head->next->next->next->next = new RandomListNode(5);
    head->random = head->next->next;
    head->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next;
    RandomListNode *cv = Clone(head);
    RandomListNode *t = cv;
    while (t)
    {
        cout << t->label << "->";
        t = t->next;
    }
    cout << endl;
    while (cv)
    {
        if (!cv->random)
        {
            cout << "#->";
        }
        else
        {
            cout << cv->random->label << "->";
        }
        cv = cv->next;
    }
    return 0;
}