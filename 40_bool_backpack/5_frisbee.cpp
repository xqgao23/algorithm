/**
 * Description:
 *  老唐最近迷上了飞盘，约翰想和他一起玩，于是打算从他家的 N 头奶牛中选出一支队伍。
 *  每只奶牛的能力为整数，第 i 头奶牛的能力为Ri 。飞盘队的队员数量不能少于 1、大于N。一支队伍的总能力就是所有队员能力的总和。
 *  约翰比较迷信，他的幸运数字是 F ，所以他要求队伍的总能力必须是 F 的倍数。请帮他算一下，符合这个要求的队伍组合有多少？由于这个数字很大，只要输出答案对 10<8> 取模的值。
 *
 * Input:
 *  第1行：两个用空格分开的整数：N 和 F。
 *  第2行到 N+1 行：第 i+1 行有一个整数Ri ，表示第 i 头奶牛的能力。
 *
 * Output:
 *  第1行：1个整数，表示方案数对 10<8> 取模的值。
 *
 * Hints:
 *  1≤N≤2000, 1≤F≤1000, 1≤Ri≤10<5>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 5
1
2
8
2
 *
 *  output:
3
 *
 */

// 70分
#include <algorithm>
#include <iostream>
using namespace std;
int n, f, r[2005], dp[2005][10005], mod = 1e8; // f[i][j] 表示前i个奶牛的能力之和为j的方案数

int main()
{
    cin >> n >> f;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10000; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= r[i]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - r[i]]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = f; i <= 10000; i += f) {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}