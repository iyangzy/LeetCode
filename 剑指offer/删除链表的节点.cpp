#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//双指针
ListNode* deleteNode(ListNode *head, int val)
{
    ListNode *newHead = new ListNode(-1);
    newHead->next = head;
    ListNode *p = newHead, *n = newHead->next;
    while (p->next)
    {
        if (p->next->val == val)
        {
            break;
        }
        p=p->next;
        n=n->next;
    }
    p->next = n->next;
    return newHead->next;
}
int main()
{
    vector<int> v = {4, 5, 1, 9};
    ListNode *head, *p;
    head->val = v[0];
    head->next = NULL;
    p = head;
    for (int i = 1; i < v.size(); i++)
    {
        ListNode *temp = new ListNode(v[i]);
        p->next = temp;
        p = temp;
    }
    ListNode *del = deleteNode(head, 5);
    while (del)
    {
        cout << del->val << endl;
        del = del->next;
    }

    return 0;
}