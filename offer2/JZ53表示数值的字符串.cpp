#include <iostream>
using namespace std;
bool isNumeric(string str)
{
    if (str.length() == 0)
    {
        return false;
    }

    int sign = 0, e = 0, dot = 0, digit = 0, i = 0;
    for (; i < str.length(); i++)
    {
        if (str[i] == '.' && i > 0)
        {
            if (dot > 0)
            {
                return false;
            }
            dot++;
            continue;
        }
        else if (str[i] == 'e' || str[i] == 'E')
        {
            if (e > 0 || digit == 0)
            {
                return false;
            }
            if (i + 1 == str.length())
            {
                return false;
            }
            else if (str[i + 1] == '+' || str[i + 1] == '-')
            {
                i++;
                if (i + 1 == str.length())
                {
                    return false;
                }
            }
            e++;
            dot++;
            continue;
        }
        else if (str[i] < '0' || str[i] > '9')
        {
            if (i == 0 && (str[0] == '+' || str[0] == '-'))
            {
                sign++;
                continue;
            }
            else
            {
                return false;
            }
        }
        digit++;
    }
    if (str[i - 1] >= '0' && str[i - 1] <= '9')
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
    cout << isNumeric("+e3") << endl;
    return 0;
}