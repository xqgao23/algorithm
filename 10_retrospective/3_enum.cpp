/**
 * Description:
 *  写一个递归函数，枚举n个数x1,...,xn的所有排列方式（全排列枚举）.
 *  若两种排列方法中前k−1个数相同，则第k个数序号更小的在前.
 *  例如对n=3,
 * X={100,20,3}应该按如下顺序给出结果{100,20,3},{100,3,20},{20,100,3},{20,3,100},{3,100,20},{3,20,100}.
 *
 * Input:
 *  第一行一个正整数n
 *  第二行n个正整数，x1,...,xn
 *
 * Output:
 *  n!行, 每行一个排列, 按题目要求顺序.
 *
 * Hints:
 *  1≤n<=8;1<=xi<=10<7>
 */

/**
 *  Samples:
 *  1):
 *  input:
3
100 20 3
 *
 *  output:
100 20 3
100 3 20
20 100 3
20 3 100
3 100 20
3 20 100
 *
 */

#include <iostream>
using namespace std;
int n, a[20], p[20], vis[20];

void dfs(int step)
{
    if (step > n) {
        for (int i = 1; i <= n; i++) {
            cout << a[p[i]] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            p[step] = i;
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1);
    return 0;
}