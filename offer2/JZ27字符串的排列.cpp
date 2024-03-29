#include <iostream>
#include <vector>
#include <set>
using namespace std;
void recu(int pos, string str, set<string> &res)
{
    if (pos + 1 == str.length())
    {
        res.insert(str);
        return;
    }
    for (int i = pos; i < str.size(); i++)
    {
        swap(str[pos], str[i]);
        recu(pos + 1, str, res);
        swap(str[pos], str[i]);
    }
}
vector<string> Permutation(string str)
{
    if (str.empty())
    {
        return {};
    }
    set<string> res;
    recu(0, str, res);
    return vector<string>(res.begin(), res.end());
}
int main()
{
    vector<string> res = Permutation("abc");
    for (auto s : res)
    {
        cout << s << endl;
    }
    return 0;
}