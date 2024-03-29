#include <iostream>
#include <vector>
using namespace std;
vector<string> res;
void backTrack(int left, int right, string &track)
{
    if (right < left)
    {
        return;
    }
    if (left < 0 || right < 0)
    {
        return;
    }
    if (left == 0 && right == 0)
    {
        res.push_back(track);
        return;
    }

    track.push_back('(');
    backTrack(left - 1, right, track);
    track.pop_back();

    track.push_back(')');
    backTrack(left, right - 1, track);
    track.pop_back();
}
vector<string> generateParenthesis(int n)
{
    string track;
    backTrack(n, n, track);
    return res;
}
int main()
{
    vector<string> genStr = generateParenthesis(0);
    for (auto str : genStr)
    {
        cout << str << endl;
    }
    return 0;
}