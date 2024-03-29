#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x) {}
};
// 翻转整个链表就是翻转a到null之间的链表，把null换为b是同理的
ListNode *reverse(ListNode *a, ListNode *b)
{
    if (a->next == b)
    {
        return a;
    }
    ListNode *last = reverse(a->next, b);
    a->next->next = a;
    a->next = nullptr;
    return last;
}
// ListNode *reverse(ListNode *a, ListNode *b)
// {
//     ListNode *pre, *cur, *nxt;
//     pre = nullptr;
//     cur = a;
//     nxt = a;
//     // while 终止的条件改一下就行了
//     while (cur != b)
//     {
//         nxt = cur->next;
//         cur->next = pre;
//         pre = cur;
//         cur = nxt;
//     }
//     // 返回反转后的头结点
//     return pre;
// }
// }
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head)
    {
        return head;
    }
    ListNode *a, *b;
    a = b = head;
    for (int i = 0; i < k; i++)
    {
        if (!b)
        {
            return head;
        }
        b = b->next;
    }
    ListNode *newHead = reverse(a, b);
    a->next = reverseKGroup(b, k);// 每次翻转后a为末尾节点，其next指向空，然后再通过这里，断了的链接又接上了
    return newHead;
}
int main()
{
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    p->next->next->next->next->next = nullptr;
    ListNode *reverseList = reverseKGroup(p, 6);
    while (reverseList)
    {
        cout << reverseList->val << "->";
        reverseList = reverseList->next;
    }
    cout << "NULL";
    return 0;
}
