#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
// 使用虚拟头结点使处理方式一致化
ListNode *deleteDuplication(ListNode *pHead)
{
    if (pHead == nullptr)
    {
        return pHead;
    }

    ListNode *vir = new ListNode(-1);
    vir->next = pHead;
    ListNode *pre = vir, *cur = pHead;
    while (cur)
    {
        if (cur->next && cur->val == cur->next->val)
        {
            cur = cur->next;
            while (cur->next && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            cur = cur->next;
            pre->next = cur;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return vir->next;
}
// 使用一个虚拟头结点会更简单，那样处理方式就一致了
// ListNode *deleteDuplication(ListNode *pHead)
// {
//     if (pHead == nullptr)
//     {
//         return pHead;
//     }

//     ListNode *pre = pHead, *cur = pHead;
//     while (cur && cur->next)
//     {
//         if (cur->val == cur->next->val)
//         {
//             ListNode *nex = cur->next->next;
//             while (nex)
//             {
//                 if (nex->val == cur->val)
//                 {
//                     nex = nex->next;
//                     continue;
//                 }
//                 break;
//             }
//             if (cur == pHead)
//             {
//                 pHead = nex;
//                 pre = pHead;
//                 cur = pHead;
//                 continue;
//             }
//             else
//             {
//                 pre->next = nex;
//                 if (!nex)
//                 {
//                     break;
//                 }
//                 cur = nex;
//                 continue;
//             }
//         }
//         if (!cur)
//         {
//             break;
//         }
//         pre = cur;
//         cur = cur->next;
//     }
//     return pHead;
// }
int main()
{
    ListNode *pHead = new ListNode(1);
    pHead->next = new ListNode(2);
    pHead->next->next = new ListNode(2);
    pHead->next->next->next = new ListNode(3);
    pHead->next->next->next->next = new ListNode(3);
    ListNode *p = deleteDuplication(pHead);
    while (p)
    {
        cout << p->val << "->";
        p = p->next;
    }
    return 0;
}