#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 双指针，交替遍历
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *pA = headA, *pB = headB;
    while (pA != pB)
    {
        pA = pA != nullptr ? pA->next : headB;
        pB = pB != nullptr ? pB->next : headA;
    }
    return pA;
}
// 书上的解法，遍历较长的链表先走，让其剩余的步数相同，第一个相同的节点就是公共节点
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
// {
//     int lenA = 0, lenB = 0;
//     ListNode *pA = headA, *pB = headB;
//     while (pA)
//     {
//         pA = pA->next;
//         lenA++;
//     }
//     while (pB)
//     {
//         pB = pB->next;
//         lenB++;
//     }
//     while (lenA > lenB)
//     {
//         headA = headA->next;
//         lenA--;
//     }
//     while (lenB > lenA)
//     {
//         headB = headB->next;
//         lenB--;
//     }
//     while(headA != headB)
//     {
//         headA = headA->next;
//         headB = headB->next;
//     }
//     if (headA != nullptr)
//     {
//         return headA;
//     }
//     else
//     {
//         return nullptr;
//     }
// }
int main()
{

    return 0;
}