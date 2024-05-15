/**
 * Description:
 *  给出一个数列，要求找出两个不相邻的非空子段，使得两个子段和的乘积最大。
 *  例如对数列2,3,1,9,−2,3，可取子段2,3和9,−2,3，两段的和分别是2+3=5和9+(−2)+3=10，乘积为50。
 *
 * Input:
 *  第1行，1个正整数n
 *  第2行，n个整数a1,a2,..,an
 *
 * Output:
 *  输出最大的乘积。
 *
 * Hints:
 *  3≤n≤10<5>, -10<4>≤ai≤10<4>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
2 3 1 9 -2 3
 *
 *  output:
50
 *
 *  2):
 *  input:
6
6 -7 5 -1 -8 7
 *
 *  output:
63
 *
 *  3):
 *  input:
12
17 -19 -12 14 4 6 -4 -11 1 3 -7 14
 *
 *  output:
558
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], f[N], g[N], l1[N], l2[N], r1[N], r2[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    l1[0] = -1e9;
    l2[0] = 1e9;
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1], 0) + a[i];
        g[i] = min(g[i - 1], 0) + a[i];
        l1[i] = max(l1[i - 1], f[i]);
        l2[i] = min(l2[i - 1], g[i]);
    }
    r1[n + 1] = -1e9;
    r2[n + 1] = 1e9;
    for (int i = n; i >= 1; i--) {
        f[i] = max(f[i + 1], 0) + a[i];
        g[i] = min(g[i + 1], 0) + a[i];
        r1[i] = max(r1[i + 1], f[i]);
        r2[i] = min(r2[i + 1], g[i]);
    }
    long long ans = -1e18;
    for (int i = 2; i < n; i++) {
        ans = max(ans, 1ll * l1[i - 1] * r1[i + 1]);
        ans = max(ans, 1ll * l2[i - 1] * r2[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
