#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    // 辅助栈改进
    stack<int> dataStack,minStack;
    MinStack() {
        dataStack = {};
        minStack = {};
    }
    
    void push(int x) {
        dataStack.push(x);
        if (minStack.empty() || minStack.top() >= x) // 这里的等号有效的解决了重复最小值的问题
        {
            minStack.push(x);
        }
    }
    
    void pop() {
        if (dataStack.top() == minStack.top())
        {
            minStack.pop();
        }
        
        dataStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int min() {
        return minStack.top();
    }
    // 辅助栈，有冗余
    // stack<int> dataStack,minStack;
    // MinStack() {
    //     dataStack = {};
    //     minStack = {};
    // }
    
    // void push(int x) {
    //     if (dataStack.size()==0)
    //     {
    //         minStack.push(x);
    //     }
    //     else
    //     {
    //         int t = minStack.top();
    //         minStack.push(t < x ? t : x);
    //     }
    //     dataStack.push(x);
    // }
    
    // void pop() {
    //     dataStack.pop();
    //     minStack.pop();
    // }
    
    // int top() {
    //     return dataStack.top();
    // }
    
    // int min() {
    //     return minStack.top();
    // }
};
int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->min() << endl;//   --> 返回 -3.
    minStack->pop();
    cout << minStack->top() << endl;//      --> 返回 0.
    cout << minStack->min() << endl;//   --> 返回 -2.
    return 0;
}