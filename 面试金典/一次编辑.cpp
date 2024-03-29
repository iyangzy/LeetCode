#include <iostream>
#include <string>
using namespace std;
bool oneEditAway(string first, string second)
{
    int firstLen = first.length(), secondLen = second.length();
    if (firstLen > secondLen)
    {
        // 保证first是短的那个
        return oneEditAway(second, first);
    }
    // case 1：两个字符串的长度不能大于1
    if (firstLen - secondLen > 1)
    {
        return false;
    }
    // case 2：如果两串长度相等，则只能有一个字符不等
    if (firstLen == secondLen)
    {
        int count = 0;
        for (int i = 0; first[i]; i++)
        {
            if (first[i] != second[i])
            {
                count++;
            }
        }
        return count <= 1;
    }
    // case 3：两串长度相差1，同理，只能有一个字符不等（即只能多一个字符），注意应该是用短的串比长的串
    int i = 0, gap = 0;
    while (i + gap < secondLen)
    {
        if (gap > 1)
        {
            return false;
        }

        if (first[i] != second[i + gap])
        {
            gap++;
            continue;
        }
        i++;
    }
    return gap <= 1;
}
int main()
{
    string first = "pale", second = "ple";
    cout << oneEditAway(first, second) << endl;
    string f = "pales", s = "pal";
    cout << oneEditAway(f, s) << endl;
    string f2 = "ab", s2 = "bc"; // false
    cout << oneEditAway(f2, s2) << endl;
    string f3 = "islander", s3 = "slander"; // true
    cout << oneEditAway(f3, s3) << endl;
    string f4 = "teacher", s4 = "tache"; // false
    cout << oneEditAway(f4, s4) << endl;
}