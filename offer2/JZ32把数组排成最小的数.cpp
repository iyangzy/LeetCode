#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string PrintMinNumber(vector<int> numbers)
{
    int n = numbers.size();
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        strs[i] = to_string(numbers[i]);
    }

    sort(strs.begin(), strs.end(), [](string a, string b){ return a + b < b + a; });
    string res = "";
    for (int i = 0; i < n; i++)
    {
        res.append(strs[i]);
    }
    return res;
}
int main()
{
    vector<int> numbers = {3, 32, 321};
    cout << PrintMinNumber(numbers) << endl;
    return 0;
}