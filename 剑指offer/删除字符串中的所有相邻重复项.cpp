#include <iostream>
using namespace std;
// 栈
// string提供了与“入栈”、“出栈”功能类似的接口，只不过用法要区分一下
string removeDuplicates(string S)
{
    string res;
    for (char ch : S)
    {
        if (!res.empty() && res.back() == ch)
        {
            res.pop_back();
        }
        else
        {
            res.push_back(ch);
        }
    }
    return res;
}
int main()
{
    cout << removeDuplicates("a") << endl;
    return 0;
}