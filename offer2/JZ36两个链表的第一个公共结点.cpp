#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    int n1 = 0, n2 = 0;
    ListNode *p1 = pHead1, *p2 = pHead2;
    while (p1)
    {
        n1++;
        p1 = p1->next;
    }
    while (p2)
    {
        n2++;
        p2 = p2->next;
    }
    while (n1-- > n2)
    {
        pHead1 = pHead1->next;
    }
    while (n2-- > n1)
    {
        pHead2 = pHead2->next;
    }
    for (int i = 0; i < n1; i++)
    {
        if (pHead1 == pHead2)
        {
            return pHead1;
        }
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
    }
    return nullptr;
}
int main()
{
    ListNode *pH1, *pH2;
    ListNode *comm = FindFirstCommonNode(pH1, pH2);
    while (comm)
    {
        cout << comm->val << "->";
        comm = comm->next;
    }
    return 0;
}