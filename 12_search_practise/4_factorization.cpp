/**
 * Description:
 *  给出正整数 n，把 n 分解成若干个正整数的乘积的所有方法中，第 m 种方法是什么?
 *  (允许有相同的数，所有数必须都大于 1， n 自身也算一种分解方法)
 *  要求因数从小到大排列，若两种方法中前 k−1 个数相同，则第 k 个数更小的在前.
 *  例如 n=12，共有 4 种分解方法，按顺序如下：
 *  12 = 2 * 2 * 3
 *  12 = 2 * 6
 *  12 = 3 * 4
 *  12 = 12
 *  于是第 2 种分解方法为 12=2×6
 *
 * Input:
 *  一行，两个正整数n,m 用空格分隔。
 *
 * Output:
 *  一行，若干个正整数，用空格分隔，表示n 的第m 种分解方法。
 *
 * Hints:
 *  2<=n<=10000
 */

/**
 *  Samples:
 *  1):
 *  input:
12 2
 *
 *  output:
2 6
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
int n, m, p[70], cnt;

void dfs(int step, int x)
{
    if (x == 1) {
        cnt++;
        if (cnt == m) {
            for (int i = 1; i <= step - 1; i++) {
                cout << p[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (i < p[step - 1] || x % i) {
            continue;
        }
        p[step] = i;
        dfs(step + 1, x / i);
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, n);
    return 0;
}