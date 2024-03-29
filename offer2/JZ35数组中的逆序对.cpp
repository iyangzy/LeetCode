#include <iostream>
#include <vector>
using namespace std;
long long InversePairsCore(vector<int> &data, vector<int> &cp, int start, int end)
{
    if (start == end)
    {
        cp[start] = data[start];
        return 0;
    }

    long long length = (end - start) / 2;
    long long left = InversePairsCore(cp, data, start, start + length);
    long long right = InversePairsCore(cp, data, start + length + 1, end);

    int i = start + length;
    int j = end;
    int indexCp = end;
    int count = 0;
    while (i >= start && j >= start + length + 1)
    {
        if (data[i] > data[j])
        {
            cp[indexCp--] = data[i--];
            count += j - start - length;
        }
        else
        {
            cp[indexCp--] = data[j--];
        }
    }
    for (; i >= start; i--)
    {
        cp[indexCp--] = data[i];
    }
    for (; j >= start + length + 1; j--)
    {
        cp[indexCp--] = data[j];
    }
    return left + right + count;
}
int InversePairs(vector<int> data)
{
    if (data.empty())
    {
        return 0;
    }

    vector<int> cp(data.size());
    for (int i = 0; i < data.size(); i++)
    {
        cp[i] = data[i];
    }
    long long count = InversePairsCore(data, cp, 0, data.size() - 1);
    return count % 1000000007;
}
int main()
{
    vector<int> data = {7, 5, 6, 4};
    cout << InversePairs(data) << endl;
    return 0;
}