/**
 * Description:
 *  某银行计划引入一个支付现金的机器，这个机器里存有N种钞票，第i种钞票的面值为Di，并且在机器中存有ni张。
 *  当要支付M元的账单时，从存放在机器中的钞票中选取若干张，可以凑出的总额中，不超过M的最大值是多少？
 *
 * Input:
 *  第1行，两个整数M和N
 *  接下来N行，每行两个整数Di和ni
 *
 * Output:
 *  输出可以凑出的不超过M的最大总额
 *
 * Hints:
 *  1≤M≤10<5>, 0≤N≤10, 0≤Di,ni≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
735 3
4 125
6 5
3 350
 *
 *  output:
735
 *
 *  2):
 *  input:
633 4
500 30
100 6
6 5
10 1
 *
 *  output:
630
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int m, n, w[110], cnt, f[100010];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int a, c, s = 1;
        cin >> a >> c;
        while (s <= c) {
            w[++cnt] = s * a;
            c -= s;
            s *= 2;
        }
        if (c > 0) {
            w[++cnt] = c * a;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = m; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}