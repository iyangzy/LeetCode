/*
小美和小团造了一个机器人,现在想给机器人编写一个自动寻路功能.
机器人所处的地形图可以被分成一个n * m的网格,每个网格上可能有障碍.
机器人每次可向上下左右四个相邻的没有障碍的网格移动,消耗一点能量.
机器人装备了一个一次性的武器系统,可破坏场上的任意一个障碍.
现在小美和小团想知道机器人从第1行1列到第n行m列所需要消耗的最少能量是多少?

第一行两个数n和m，表示网格的行和列。

接下来n行每行一个长度为m的字符串,由’.’和’*’，第i行第j个字母为’*’则网格i行j列有障碍,否则没有障碍。

1≤n,m≤500，数据保证第1行第1列没有障碍。
 */

// bfs，每条路最多有一个*