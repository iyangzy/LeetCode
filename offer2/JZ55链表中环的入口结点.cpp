#include <iostream>
#include <set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
ListNode *EntryNodeOfLoop(ListNode *pHead)
{
    if (pHead == nullptr)
    {
        return pHead;
    }

    ListNode *head = pHead;
    set<ListNode *> s;
    while (head)
    {
        if (s.find(head) != s.end())
        {
            return head;
        }
        s.insert(head);
        head = head->next;
    }
    return nullptr;
}
int main()
{
    ListNode *pHead = new ListNode(1);
    pHead->next = new ListNode(2);
    pHead->next->next = new ListNode(3);
    pHead->next->next->next = new ListNode(4);
    pHead->next->next->next->next = pHead;
    ListNode *loopHead = EntryNodeOfLoop(pHead);
    if (loopHead)
    {
        cout << loopHead->val << endl;
    }
    else
    {
        cout << "null" << endl;
    }

    return 0;
}