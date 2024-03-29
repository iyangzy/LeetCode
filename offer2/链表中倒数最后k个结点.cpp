#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};

ListNode *FindKthToTail(ListNode *pHead, int k)
{
    ListNode *fast = pHead, *slow = pHead;
    while (k && fast)
    {
        fast = fast->next;
        k--;
    }
    if (k > 0)
    {
        return nullptr;
    }

    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode *k = FindKthToTail(head, 5);
    cout << k->val << endl;
    return 0;
}