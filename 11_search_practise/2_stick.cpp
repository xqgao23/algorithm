/**
 * Description:
 *  现给出一些木棒长度，小猴能否用给出的木棒（必须全部用完）组成一个正方形呢？
 *
 * Input:
 *  第一行是一个整数 n(1≤n≤10)表示测试的组数，接下来 n 行表示每组测试数据。
 *  每组测试数据的第一个数为 m(4≤m≤20),接下来 m 个数 ai(1<=ai≤1000) 表示木棒的长度。
 *
 * Output:
 *  对于每组测试数据，如果可以组成正方形输出"yes"，否则输出"no"。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
4 1 1 1 1
5 10 20 30 40 50
8 1 7 2 6 4 4 3 5
 *
 *  output:
yes
no
yes
 *
 */

#include <iostream>
using namespace std;
int n, m, a[30], p[30], s, flag;
void dfs(int step, int la, int lb, int lc, int ld)
{
    if (flag || la > s / 4 || lb > s / 4 || lc > s / 4 || ld > s / 4) {
        return;
    }
    if (step > m) {
        flag = 1;
        return;
    }
    dfs(step + 1, la + a[step], lb, lc, ld);
    dfs(step + 1, la, lb + a[step], lc, ld);
    dfs(step + 1, la, lb, lc + a[step], ld);
    dfs(step + 1, la, lb, lc, ld + a[step]);
}
int main()
{
    cin >> n;
    while (n--) {
        cin >> m;
        s = 0;
        flag = 0;
        for (int i = 1; i <= m; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s % 4 != 0) {
            cout << "no" << endl;
        } else {
            dfs(1, 0, 0, 0, 0);
            if (flag) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}