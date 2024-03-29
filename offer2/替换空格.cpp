#include <iostream>
using namespace std;
string replaceSpace(string s)
{
    int n = s.size();
    int i = 0;
    string newStr = "";
    while (i<n)
    {
        if(s[i]==' ')
        {
            newStr.append("%20");
        }
        else
        {
            newStr.push_back(s[i]);
        }
        i++;
    }
    return newStr;
}
int main()
{
    cout << replaceSpace("We Are Happy") << endl;
    return 0;
}