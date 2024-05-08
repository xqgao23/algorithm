/**
 * Description:
 *  一个只由1∼m数码组成的n位数, 如果任意两个相邻数之差的绝对值都不超过d,则称这个数是一个"d好数".
 *  给出n,m,d,输出n位"d好数"的个数，除以10<9>+7的余数. d的值只可能取1,2,3.
 *
 * Input:
 *  3个正整数n,m,d
 *
 * Output:
 *  输出n位"d好数"的个数，除以10<9>+7的余数
 *
 * Hints:
 *  1≤n≤10<5>, 1≤m≤9, 1≤d≤3
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3 1
 *
 *  output:
99
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n, m, d, f[100010][10], mod = 1e9 + 7;

int main()
{
    cin >> n >> m >> d;
    for (int j = 1; j <= m; j++) {
        f[1][j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                if (abs(j - k) <= d) {
                    f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + f[n][j]) % mod;
    }
    cout << ans << endl;
    return 0;
}