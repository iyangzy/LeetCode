#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        nums[i] = t;
    }
    
    int end = 0, farthest = 0;
    int device = 0;
    for (int i = 0; i < n - 1; i++) {
        farthest = max(nums[i] + i, farthest);
        if (end == i) {
            device++;
            end = farthest;
        }
    }
    cout<<device<<endl;
    return 0;
}