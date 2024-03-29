#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool IsContinuous(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end());
    int zero = 0;
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] == 0)
        {
            zero++;
        }
        else
        {
            if (numbers[i] == numbers[i + 1])
            {
                return false;
            }
            else if (numbers[i + 1] - numbers[i] - 1 > zero)
            {
                return false;
            }
            zero -= (numbers[i + 1] - numbers[i] - 1);
        }
    }
    return true;
}
int main()
{
    vector<int> numbers = {13,12,11,0,1};
    cout << IsContinuous(numbers) << endl;
    return 0;
}