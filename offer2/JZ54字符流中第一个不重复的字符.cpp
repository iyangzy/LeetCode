#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    //Insert one char from stringstream
    queue<char> q;
    unordered_map<char, int> charMap;
    void Insert(char ch)
    {
        if (charMap.find(ch) != charMap.end())
        {
            charMap[ch]++;
        }
        else
        {
            charMap[ch] = 1;
        }
        q.push(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while (!q.empty())
        {
            if (charMap[q.front()] == 1)
            {
                return q.front();
            }
            else
            {
                q.pop();
            }
        }
        return '#';
    }
};
int main()
{
    string str = "casein";
    Solution sol;
    for (int i = 0; i < str.length(); i++)
    {
        sol.Insert(str[i]);
        cout << sol.FirstAppearingOnce() << endl;
    }
    return 0;
}