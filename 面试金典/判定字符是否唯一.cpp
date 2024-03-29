#include "iostream"
#include "cstring"
#include "string"
using namespace std;
// 方法2：位向量
bool isUnique(string astr) {
    int flag = 0;
    for (int i = 0; astr[i]; ++i) {
        if (flag & (1 << (astr[i] - 'a'))) {
            return false;
        } else {
            flag |= (1 << (astr[i] - 'a'));
        }
    }
    return true;
}
// 方法1：hash
//bool isUnique(string astr) {
//    int map[26];
//    memset(map, 0, sizeof(map));
//    for (int i = 0; i < astr.length(); ++i) {
//        int index = astr[i] - 'a';
//        if (map[index] != 0) {
//            return false;
//        } else {
//            map[index]++;
//        }
//    }
//    return true;
//}

int main() {
    string str = "leetcode";
    cout << str << "isUnique: " << isUnique(str) << endl;
    string str2 = "abc";
    cout << str << "isUnique: " << isUnique(str2);
}