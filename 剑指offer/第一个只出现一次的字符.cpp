#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
// 本人感觉这个题根本就没牵扯到算法，奈何人家都说这题考察了哈希表的使用，行吧行吧
char firstUniqChar(string s)
{
    int index = -1, alp[26];
    memset(alp, -1, sizeof(alp));
    for (int i = 0; i < s.length(); i++)
    {
        alp[s[i] - 'a']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (alp[s[i] - 'a'] == 0)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        return s[index];
    }
    return ' ';
}
int main()
{
    cout << firstUniqChar("abaccdeff") << endl;
    return 0;
}