#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, vector<int>> memo;
vector<int> diffWaysToCompute(string expression)
{
    if (memo.count(expression))
    {
        return memo[expression];
    }

    vector<int> ways;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (ch == '+' || ch == '-' || ch == '*')
        {
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            for (auto l : left)
            {
                for (auto r : right)
                {
                    switch (ch)
                    {
                    case '+':
                        ways.push_back(l + r);
                        break;
                    case '-':
                        ways.push_back(l - r);
                        break;
                    case '*':
                        ways.push_back(l * r);
                        break;
                    }
                }
            }
        }
    }
    if (ways.empty())
    {
        ways.push_back(stoi(expression));
    }
    memo.insert(pair<string, vector<int>>(expression, ways));
    return ways;
}
int main()
{
    vector<int> res = diffWaysToCompute("2*3-4*5");
    for (auto ans : res)
    {
        cout << ans << "->";
    }
    return 0;
}