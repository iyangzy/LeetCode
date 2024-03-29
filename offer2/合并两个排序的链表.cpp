#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (!pHead1)
    {
        return pHead2;
    }
    if (!pHead2)
    {
        return pHead1;
    }

    ListNode *mergeHead = new ListNode(-1);
    ListNode *newHead = mergeHead;
    while (pHead1 && pHead2)
    {
        if (pHead1->val <= pHead2->val)
        {
            newHead->next = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            newHead->next = pHead2;
            pHead2 = pHead2->next;
        }
        newHead = newHead->next;
    }
    if (pHead1)
    {
        newHead->next = pHead1;
    }
    if (pHead2)
    {
        newHead->next = pHead2;
    }
    return mergeHead->next;
}
int main()
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);
    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);
    ListNode *mergeList = Merge(head1, head2);
    while (mergeList)
    {
        cout << mergeList->val << "->";
        mergeList = mergeList->next;
    }
    return 0;
}