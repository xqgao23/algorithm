/**
 * Description:
 *  给出两个正整数 n,m。
 *  考虑所有满足 a1+a2+⋯+an=m 的正整数数列 a1,a2,…,an。即将 m 分割成 n 个正整数之和的所有方法。
 *  如果求 a1,a2,…,an 的最大公约数 d，可能得到的 d 的最大值是多少？
 *
 * Input:
 *  2个正整数n,m
 *
 * Output:
 *  输出可能得到的最大公约数的最大值。
 *
 * Hints:
 *  1≤n≤100000, n≤m≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 8
 *
 *  output:
2
 *
 *  2):
 *  input:
10 123
 *
 *  output:
3
 *
 *  1):
 *  input:
3 8
 *
 *  output:
2
 *
 *  3):
 *  input:
100000 1000000000
 *
 *  output:
10000
 *
 */

#include <iostream>
using namespace std;

int main()
{
    int n, m, ans = 1;
    cin >> n >> m;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0 && 1ll * i * n <= m) {
            ans = max(ans, i);
            if (1ll * m / i * n <= m) {
                ans = max(ans, m / i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}