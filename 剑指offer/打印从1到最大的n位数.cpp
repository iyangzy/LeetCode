#include <iostream>
#include <vector>
using namespace std;
//自己写的递归全排列
void dfs(string str, int n)
{
    if (n == 0)
    {
        while (str[0]=='0')
        {
            str = str.substr(1,str.size());
        }
        
        if (str!="")
        {
            cout << str << endl;
        }
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        str += i + '0';
        dfs(str, n - 1);
        str = str.substr(0,str.size()-1);
    }
}
//这个题是要考虑大数的，只不过力扣规定了返回值为int，下面这种方法才能ac
vector<int> printNumbers(int n)
{
    int len = (int)pow(10, n);
    vector<int> nums;
    for (int i = 1; i < len; i++)
    {
        nums.push_back(i);
    }
    return nums;
}
int main()
{
    // vector<int> p = printNumbers(1);
    // vector<int>::iterator iter = p.begin(); //vector的迭代器遍历要会
    // for (; iter != p.end(); iter++)
    // {
    //     cout << *iter << endl;
    // }
    string str = "";
    dfs(str, 3);
    return 0;
}