#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
int kthToLast(ListNode *head, int k)
{
    ListNode *p = head;
    for (int i = 0; i < k && p; i++)
    {
        p = p->next;
    }

    while (p)
    {
        p = p->next;
        head = head->next;
    }
    return head->val;
}
int main()
{
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << kthToLast(head, 2) << endl;
}