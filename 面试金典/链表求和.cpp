#include <iostream>
#include <math.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *p = nullptr, *q = nullptr;
    bool isCarry = false;
    while (l1 || l2)
    {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int t = v1 + v2 + (isCarry ? 1 : 0);
        if (p == nullptr)
        {
            p = q = new ListNode(t % 10);
        }
        else
        {
            q->next = new ListNode(t % 10);
            q = q->next;
        }
        isCarry = (t > 0 && t / 10);
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }

    if (isCarry)
    {
        q->next = new ListNode(1);
    }
    return p;
}

// 解1 暴力遍历求和 不能通过全部case，求的和会越界
// ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// {
//     int count = 0;
//     long sum = 0;
//     while (l1)
//     {
//         sum += (l1->val * pow(10, count++));
//         l1 = l1->next;
//     }
//     count = 0;
//     while (l2)
//     {
//         sum += (l2->val * pow(10, count++));
//         l2 = l2->next;
//     }

//     ListNode *s = new ListNode(-1);
//     if (sum==0)
//     {
//         s->next = new ListNode(sum);
//         return s->next;
//     }

//     ListNode *p = s;
//     while (sum % 10 || sum >= 10)
//     {
//         s->next = new ListNode(sum % 10);
//         sum /= 10;
//         s = s->next;
//     }

//     return p->next;
// }
int main()
{
    ListNode *head;
    head = new ListNode(6);
    // head->next = new ListNode(1);
    // head->next->next = new ListNode(7);
    ListNode *head2;
    head2 = new ListNode(4);
    // head2->next = new ListNode(9);
    // head2->next->next = new ListNode(5);
    ListNode *p = addTwoNumbers(head, head2);
    while (p)
    {
        cout << p->val << ", ";
        p = p->next;
    }
}