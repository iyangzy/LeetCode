#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// sort函数的自定义方法必须是static的
static bool comp(const string &a,const string &b)
{
    return a+b<b+a;
}
string minNumber(vector<int> &nums)
{
    vector<string> strNums;
    for(auto num:nums)
    {
        strNums.push_back(to_string(num));
    }
    sort(strNums.begin(),strNums.end(),comp);
    string str = "";
    for(auto s:strNums)
    {
        str += s;
    }
    return str;
}
int main()
{
    vector<int> v = {3,30,34,5,9};
    cout << minNumber(v) << endl;
    return 0;
}