#include <iostream>
#include <set>
#include <vector>
using namespace std;

multiset<double> mset;
void Insert(int num)
{
    mset.insert(double(num));
}

double GetMedian()
{
    int size = mset.size();
    vector<double> vec(mset.begin(), mset.end());
    if ((size & 1) == 0)
    {
        size /= 2;
        return (vec[size - 1] + vec[size]) / 2.0;
    }
    else
    {
        return vec[size / 2];
    }
}

int main()
{
    Insert(5);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(1);
    Insert(6);
    cout << GetMedian() << endl;
    return 0;
}