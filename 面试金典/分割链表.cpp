#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *partition(ListNode *head, int x)
{
    if (head == nullptr)
    {
        return head;
    }

    ListNode *p = new ListNode(INT32_MAX);
    p->next = head;
    while (p->next && p->next->val < x)
    {
        p = p->next;
    }
    ListNode *q = p->next;
    while (q && q->next)
    {
        if (q->next->val < x)
        {
            ListNode *mov = q->next;
            q->next = q->next->next;
            mov->next = nullptr;
            mov->next = p->next;
            p->next = mov;
            // 如果是发生在头结点之前，需要更新头结点
            if (p->val == INT32_MAX)
            {
                head = p->next;
            }
            p = p->next;
            continue;
        }

        q = q->next;
    }
    return head;
}
int main()
{
    ListNode *head;
    head = new ListNode(1);
    // head->next = new ListNode(4);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(2);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(2);
    ListNode *p = partition(head, 2);
    while (p)
    {
        cout << p->val << ", ";
        p = p->next;
    }
}