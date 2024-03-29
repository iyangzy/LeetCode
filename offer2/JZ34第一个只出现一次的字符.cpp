#include <iostream>
#include <bitset>
using namespace std;
int FirstNotRepeatingChar(string str)
{
    bitset<128> b1, b2;
    for (auto ch : str)
    {
        if (!b1[ch] && !b2[ch])
        {
            b1[ch] = 1;
        }
        else if (b1[ch] && !b2[ch])
        {
            b2[ch] = 1;
        }
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (b1[str[i]] && !b2[str[i]])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    cout << FirstNotRepeatingChar("google") << endl;
    return 0;
}