#include <iostream>
using namespace std;
int GetUglyNumber_Solution(int index)
{
    if (index <= 1)
    {
        return index;
    }

    int uglyNums[index];
    uglyNums[0] = 1;
    int index2 = 0, index3 = 0, index5 = 0, nextNum, next2, next3, next5;
    for (int i = 1; i < index; i++)
    {
        next2 = uglyNums[index2] * 2;
        next3 = uglyNums[index3] * 3;
        next5 = uglyNums[index5] * 5;
        nextNum = min(next2, next3);
        nextNum = min(nextNum, next5);
        uglyNums[i] = nextNum;
        if (nextNum == next2)
            index2++;
        if (nextNum == next3)
            index3++;
        if (nextNum == next5)
            index5++;
    }
    return uglyNums[index - 1];
}
int main()
{
    cout << GetUglyNumber_Solution(7) << endl;
    return 0;
}