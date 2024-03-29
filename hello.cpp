#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int n = 10;
    stringstream ss;
    ss << n;
    string str;
    ss >> str;
    cout << str<< endl;
    cout<<(char)65<<endl;
    return 0;
}