#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
void backTrack(int n, int k, int index, vector<int> &track)
{
    if (track.size()==k)
    {
        res.push_back(track);
        return;
    }
    
    for (int i = index; i < n+1; i++)
    {
        track.push_back(i);
        backTrack(n,k,i+1,track);
        track.pop_back();
    }
    
}
vector<vector<int>> combine(int n, int k)
{
    vector<int> track;
    backTrack(n,k,1,track);
    return res;
}
int main()
{
    vector<vector<int>> re = combine(4, 2);
    for (auto v : re)
    {
        for (vector<int>::iterator iter = v.begin(); iter < v.end(); iter++)
        {
            cout << *iter << ",";
        }
        cout << endl;
    }
    return 0;
}