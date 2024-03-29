#include <iostream>
#include <vector>
using namespace std;
bool recu(vector<int> sequence)
{
     if (sequence.empty())
    {
        return true;
    }

    int n = sequence.size();
    int root = sequence[n - 1];
    int i = 0;
    for (; i < n && sequence[i] < root; i++);

    for (int j = i; j < n - 1; j++)
    {
        if (sequence[j] < root)
        {
            return false;
        }
    }

    return recu({sequence.begin(), sequence.begin() + i}) && recu({sequence.begin() + i, sequence.end()-1});
}
bool VerifySquenceOfBST(vector<int> sequence)
{
    if (sequence.empty())
    {
        return false;
    }
    return recu(sequence);
}
int main()
{
    vector<int> seq = {4,8,6,12,16,14,10};
    cout << VerifySquenceOfBST(seq) << endl;
    return 0;
}