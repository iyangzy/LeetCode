#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }

    ListNode *p = new ListNode(-1);
    p->next = head;
    ListNode *pre = p, *cur = head;
    while (cur && cur->next)
    {
        if (cur->val == cur->next->val)
        {
            int t = cur->val;
            while (cur->next != nullptr && cur->next->val == t)
            {
                cur->next = cur->next->next;
            }
            pre->next = cur->next;
        }
        else
        {
            pre = cur;
        }
        cur = cur->next;
    }
    return p->next;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    ListNode *res = deleteDuplicates(head);
    while (res)
    {
        cout << res->val << "->";
        res = res->next;
    }
    return 0;
}