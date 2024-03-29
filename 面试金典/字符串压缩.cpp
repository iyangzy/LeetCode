#include <iostream>
#include <string>
using namespace std;
string compressString(string S)
{
    string newStr;
    for (int i = 0; i < S.size(); i++)
    {
        int count = 1;
        int j = i + 1;
        for (; j < S.size(); j++)
        {
            if (S[j] != S[i])
            {
                break;
            }
            count++;
        }
        newStr.append(1, S[i]);
        newStr.append(to_string(count));
        i = j-1;
    }
    return newStr.size() < S.size() ? newStr : S;
}
int main()
{
    string s1 = "aabcccccaaa";
    cout << compressString(s1) << endl;
    string s2 = "abbccd";
    cout << compressString(s2) << endl;
}