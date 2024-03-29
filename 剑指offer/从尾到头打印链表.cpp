#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<list>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 //递归，vector的初始化有问题，以后再调
 vector<int> reversePrint(ListNode* head) {
     if (head)
     {
         vector<int> v = reversePrint(head->next);
         v.push_back(head->val);
         return v;
     }
     else
     {
         return vector<int> ();
     }
     
 }
 //倒序输出类似栈，因此使用栈做，递归的过程与栈类似，但是如果数据量太大，递归深度太深，容易栈溢出
//  vector<int> reversePrint(ListNode* head) {
//      vector<int> re;
//      stack<ListNode *> nodes;
//      while (head != NULL)
//      {
//          nodes.push(head);
//          head = head->next;
//      }
//      while (!nodes.empty())
//      {
//          re.push_back(nodes.top()->val);
//          nodes.pop();
//      }
//      return re;
//  }
 //使用revers函数将vector中的内容倒置
//  vector<int> reversePrint(ListNode* head) {
//      vector<int> t;
//         while(head != NULL)
//         {
//             t.push_back(head->val);
//             head = head->next;
//         }
//         reverse(t.begin(),t.end());
//         return t;
// }
int main()
{
    int n[3] = {1,3,2};
    vector<int> nums(n,n+3);
    
    ListNode *head,*p;
    head = new ListNode(-1);
    head->next = NULL;
    p = head;
    for (int i = 0; i < nums.size(); i++)
    {
        ListNode *t = new ListNode(nums[i]);
        //尾插
        t->next = NULL;
        p->next = t;
        p = p->next;
        //头插
        // t->next = p->next;
        // p->next = t;
    }
    for(auto v : reversePrint(head))
    {
        cout<<v<<',';
    }
    return 0;
}