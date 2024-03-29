#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
    stack<int> s;

    int i = 0;
    for (int j = 0; j < popV.size(); j++)
    {
        if(!s.empty() && s.top() == popV[j])
        {
            s.pop();
            continue;
        }
        while (i<pushV.size() && pushV[i] != popV[j])
        {
            s.push(pushV[i++]);
            continue;
        }
        if (pushV[i] == popV[j])
        {
            i++;
            continue;
        }
        return false;
    }
    return true;
}
int main()
{
    vector<int> pushV = {1, 2, 3, 4, 5};
    vector<int> popV = {4,5,3,2,1};
    cout << IsPopOrder(pushV, popV) << endl;
    return 0;
}