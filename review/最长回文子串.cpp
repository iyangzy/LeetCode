#include <iostream>
using namespace std;
string palindrome(string s, int l, int r)
{
    while (l >= 0 && r < s.length() && s[l] == s[r])
    {
        l--;
        r++;
    }
    return s.substr(l + 1, r - l - 1);
}
string longestPalindrome(string s)
{
    if (s.length() == 1)
    {
        return s;
    }

    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        string odd = palindrome(s, i, i);
        string even = palindrome(s, i, i + 1);
        res = res.length() > odd.length() ? res : odd;
        res = res.length() > even.length() ? res : even;
    }
    return res;
}
int main()
{
    cout << longestPalindrome("ba") << endl;
    return 0;
}