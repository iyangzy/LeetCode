#include <iostream>
#include <stack>
using namespace std;
//官解的动画很形象
class CQueue
{
    // stack<int> stack1,stack2;//官解在此处声明变量
public:
    //官解中两个栈的声明位置不一样，官解在类域中声明的
    stack<int> stack1;
    stack<int> stack2;
    CQueue()
    {
        stack1 = stack2 = {};
    }

    void appendTail(int value)
    {
        stack1.push(value);
    }

    int deleteHead()
    {
        int head;
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty())
        {
            head = -1;
        }
        else
        {
            head = stack2.top();
            stack2.pop();
        }
        return head;
    }
};
int main()
{
    CQueue *obj = new CQueue();
    cout << obj->deleteHead() << endl;
    obj->appendTail(1);
    obj->appendTail(9);
    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;
    return 0;
}