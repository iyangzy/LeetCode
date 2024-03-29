#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
string up(string str, int index)
{
    str[index] = str[index] == '9' ? '0' : str[index] + 1;
    return str;
}
string down(string str, int index)
{
    str[index] = str[index] == '0' ? '9' : str[index] - 1;
    return str;
}
// 双向bfs，使用双向bfs的前提是明确知道终点
int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> dead(deadends.begin(), deadends.end());
    unordered_set<string> vis;
    unordered_set<string> q1, q2;
    q1.insert("0000");
    q2.insert(target);
    // vis.insert("0000");//优化一下添加到vis的时机
    // vis.insert(target);

    int step = 0;
    while (!q1.empty() && !q2.empty())
    {
        // 双向bfs还可以再优化
        if (q1.size() > q2.size())
        {
            swap(q1,q2);
        }

        unordered_set<string> t;
        for (auto str : q1)
        {
            if (dead.count(str))
            {
                continue;
            }
            // 终止条件变了
            if (q2.count(str))
            {
                return step;
            }
            vis.insert(str);//vis位置改变
            for (int j = 0; j < 4; j++)
            {
                string nextStr = up(str, j);
                if (!vis.count(nextStr))
                {
                    t.insert(nextStr);
                }
                nextStr = down(str, j);
                if (!vis.count(nextStr))
                {
                    t.insert(nextStr);
                }
            }
        }
        step++;
        q1 = q2;
        //双向bfs的核心
        q2 = t;
    }
    return -1;
}
// 普通bfs
// int openLock(vector<string> &deadends, string target)
// {
//     queue<string> q;
//     q.push("0000");
//     unordered_set<string> dead(deadends.begin(), deadends.end());
//     unordered_set<string> vis;
//     vis.insert("0000");

//     int step = 0;
//     while (!q.empty())
//     {
//         int t = q.size();
//         for (int i = 0; i < t; i++)
//         {
//             string str = q.front();
//             q.pop();

//             if (dead.count(str))
//             {
//                 continue;
//             }
//             if (str == target)
//             {
//                 return step;
//             }

//             for (int j = 0; j < 4; j++)
//             {
//                 string nextStr = up(str, j);
//                 if (!vis.count(nextStr))
//                 {
//                     q.push(nextStr);
//                     vis.insert(nextStr);
//                 }
//                 nextStr = down(str, j);
//                 if (!vis.count(nextStr))
//                 {
//                     q.push(nextStr);
//                     vis.insert(nextStr);
//                 }
//             }
//         }
//         step++;
//     }
//     return -1;
// }
int main()
{
    vector<string> deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    cout << openLock(deadends, "8888") << endl;
    return 0;
}