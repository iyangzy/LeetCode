#include <iostream>
using namespace std;
string reverseLeftWords(string s, int n)
{
    // string t = s.substr(0,n);
    return s.substr(n,s.length()).append(s.substr(0,n));
}
int main()
{
    cout<<reverseLeftWords("lrloseumgh",6)<<endl;
    return 0;
}