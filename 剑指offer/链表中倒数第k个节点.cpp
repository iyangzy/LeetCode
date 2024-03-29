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
ListNode *getKthFromEnd(ListNode *head, int k)
{
    ListNode *p = head;
    while (k-- && p)
    {
        p = p->next;
    }
    while (p)
    {
        p = p->next;
        head = head->next;
    }
    return head;
}
//最简单的遍历两遍
// ListNode *getKthFromEnd(ListNode *head, int k)
// {
//     ListNode *p = head;
//     int length = 0;
//     while (p)
//     {
//         length++;
//         p = p->next;
//     }
//     length -= k;
//     while (length--)
//     {
//         head = head->next;
//     }
//     return head;
// }
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(v[0]);
    ListNode *p = head;
    for (int i = 1; i < v.size(); i++)
    {
        ListNode *temp = new ListNode(v[i]);
        p->next = temp;
        p = temp;
    }
    ListNode *re = getKthFromEnd(head, 2);
    if (re!=nullptr)
    {
        cout << re->val << endl;
    }
    else
    {
        cout<< "list is null" << endl;
    }
    

    return 0;
}