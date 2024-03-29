#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 利用栈模拟整个过程
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> s = {};
    int i = 0, j = 0;
    while (j < popped.size())
    {
        while ((s.empty() || s.top() != popped[j]) && i < pushed.size())
        {
            s.push(pushed[i++]);
        }
        if (!s.empty() && s.top() == popped[j])
        {
            s.pop();
            j++;
        }
        else
        {
            break;
        }
    }
    if (j == popped.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    vector<int> pushed = {2};
    vector<int> popped = {1};
    cout << validateStackSequences(pushed, popped);
    return 0;
}