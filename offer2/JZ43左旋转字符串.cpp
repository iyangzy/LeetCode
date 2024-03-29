#include <iostream>
using namespace std;
string LeftRotateString(string str, int n)
{
    if (str.empty())
    {
        return str;
    }

    int len = str.length();
    str.resize(len + n);
    for (int i = 0; i < n; i++)
    {
        str[len + i] = str[i];
    }
    return str.substr(n, len + n);
}
int main()
{
    cout << LeftRotateString("abcXYZdef", 3);
    return 0;
}