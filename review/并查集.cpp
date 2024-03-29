#include<iostream>
using namespace std;
int pre[100];
int find(int x)
{
    int t = x;
    while (pre[x] != x)
    {
        x = pre[x];
    }
    while(t!=x)
    {
        t = pre[t];
        pre[t] = x;
    }
    return x;
}
void conn(int x,int y)
{
    int px = find(x);
    int py = find(y);
    if(px != py)
    {
        pre[px] = py;
    }
}
int main()
{
    for (int i = 0; i < 100; i++)
    {
        pre[i] = i;
    }
    // do something
    return 0;
}