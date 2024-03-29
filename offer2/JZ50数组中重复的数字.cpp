#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int duplicate(vector<int> &numbers)
{
    if (numbers.empty())
    {
        return -1;
    }

    int n = numbers.size();
    int freq[n];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++)
    {
        if (freq[numbers[i]] != 0)
        {
            return numbers[i];
        }
        else
        {
            freq[numbers[i]]++;
        }
    }
    return -1;
}
int main()
{
    vector<int> num = {2, 3, 1, 0, 2, 5, 3};
    cout << duplicate(num) << endl;
    return 0;
}