#include <iostream>
#include <math.h>
using namespace std;
int StrToInt(string str)
{
    if (str.empty())
    {
        return 0;
    }

    int flag = 0;
    if (str[0] == '-')
    {
        flag = 1;
    }
    long digit = pow(10, str.length() - 1), sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            digit /= 10;
            continue;
        }
        else if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        else
        {
            int t = str[i] - '0';
            sum += t * digit;
            digit /= 10;
        }
    }
    return flag ? sum * -1 : sum;
}
int main()
{
    cout << StrToInt("1a33") << endl;
    return 0;
}