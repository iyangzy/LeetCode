#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    stack<int> d, minS;
    void push(int value)
    {
        d.push(value);
        if (minS.empty())
        {
            minS.push(value);
        }
        else
        {
            if (value <= minS.top())
            {
                minS.push(value);
            }
        }
    }
    void pop()
    {
        if (d.top() == minS.top())
        {
            minS.pop();
        }
        d.pop();
    }
    int top()
    {
        return d.top();
    }
    int min()
    {
        return minS.top();
    }
};
int main()
{
}