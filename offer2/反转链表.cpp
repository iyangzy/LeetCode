#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
// 递归法
ListNode *ReverseList(ListNode *pHead)
{
    if(!pHead || !pHead->next)
    {
        return pHead;
    }

    ListNode *newHead = ReverseList(pHead->next);
    pHead->next->next = pHead;
    pHead->next = nullptr;
    return newHead;
}
// 迭代法
// ListNode *ReverseList(ListNode *pHead)
// {
//     if (!pHead)
//     {
//         return pHead;
//     }
    
//     ListNode *fast = pHead->next,*slow = pHead;
//     slow->next = nullptr;
//     while (fast)
//     {
//         ListNode *t = fast->next;
//         fast->next = slow;
//         slow = fast;
//         fast = t;
//     }
//     return slow;
// }
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode *res = ReverseList(head);
    while (res)
    {
        cout << res->val << "->";
        res = res->next;
    }
    return 0;
}