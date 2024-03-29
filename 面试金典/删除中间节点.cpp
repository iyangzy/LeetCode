#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
void deleteNode(ListNode *node)
{
    // 把下一个节点的值赋值给这个待删除的节点
    node->val = node->next->val;
    // 删除下一个节点（转嫁）
    ListNode* t =node->next;
    node->next = t->next;
    t->next = nullptr;
}
int main()
{
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    deleteNode(head->next->next);
    while (head)
    {
        cout << head->val << ", ";
        head = head->next;
    }
}