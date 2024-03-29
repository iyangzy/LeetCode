#include <iostream>
#include <sstream>
using namespace std;
// 自己的解法，结合stringstream，不得不说，这东西对string和int的相互转换时真的好使
int strToInt(string str)
{
    if (str.length() == 0)
    {
        return 0;
    }
    int i = 0, j;
    while (str[i] == ' ')
    {
        i++;
    }
    if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
    {
        j = i+1;
        while (j < str.length())
        {
            if (str[j] < '0' || str[j] > '9')
            {
                break;
            }
            j++;
        }
        str = str.substr(i, j);
    }
    else
    {
        return 0;
    }

    long long res;
    stringstream ss;
    ss << str;
    ss >> res;
    if (res > INT_MAX)
    {
        return INT_MAX;
    }
    else if (res < INT_MIN)
    {
        return INT_MIN;
    }
    return res;
}
int main()
{
    cout << strToInt("-dfs") << endl;
    return 0;
}