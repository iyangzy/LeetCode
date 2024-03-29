#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseList(ListNode *head)
{
    if (!head)
    {
        return NULL;
    }
    ListNode *re = new ListNode(-1);
    re->next = NULL;
    ListNode *p;
    while (head)
    {
        p = head;
        head = head->next;
        p->next = re->next;
        re->next = p;
    }
    return re->next;
}
int main()
{
    vector<int> v = {1, 2, 3, 4};
    ListNode *head = new ListNode(v[0]);
    ListNode *p = head;
    for (int i = 1; i < v.size(); i++)
    {
        ListNode *t = new ListNode(v[i]);
        t->next = NULL;
        p->next = t;
        p = t;
    }
    ListNode *re = reverseList(head);
    while (re)
    {
        cout << re->val << "->";
        re = re->next;
    }
    return 0;
}