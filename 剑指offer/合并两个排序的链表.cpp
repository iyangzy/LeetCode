#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 改进后
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *merge = new ListNode(-1);
    merge->next = nullptr;
    ListNode *head = merge;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            head->next = l1;
            l1 = l1->next;
        }
        else
        {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    head->next = l1 ? l1 : l2;

    return merge->next;
}
// 最开始ac的版本
// ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
// {
//     ListNode *merge = new ListNode(-1);
//     merge->next = nullptr;
//     ListNode *head = merge;
//     while (l1&&l2)
//     {
//         if(l1->val <= l2->val)
//         {
//             ListNode *t = new ListNode(l1->val);
//             t->next = head->next;
//             head->next = t;
//             head = t;
//             l1 = l1->next;
//         }
//         else
//         {
//             ListNode *t = new ListNode(l2->val);
//             t->next = head->next;
//             head->next = t;
//             head = t;
//             l2 = l2->next;
//         }

//     }
//     if (l1)
//     {
//         head->next = l1;
//     }
//     if (!l2)
//     {
//         head->next = l2;
//     }

//     return merge->next;
// }
int main()
{
    vector<int> v1 = {2};
    vector<int> v2 = {1};
    ListNode *l1 = new ListNode(v1[0]);
    ListNode *l2 = new ListNode(v2[0]);
    ListNode *p1 = l1, *p2 = l2;
    for (int i = 1; i < v1.size(); i++)
    {
        ListNode *t = new ListNode(v1[i]);
        p1->next = t;
        p1 = t;
    }
    for (int i = 1; i < v2.size(); i++)
    {
        ListNode *t = new ListNode(v2[i]);
        p2->next = t;
        p2 = t;
    }
    ListNode *mergeList = mergeTwoLists(l1, l2);
    while (mergeList)
    {
        cout << mergeList->val << "->";
        mergeList = mergeList->next;
    }

    return 0;
}