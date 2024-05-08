/**
 * Description:
 *  求将n划分为k个正整数的和的方法数，k个正整数不计顺序。例如5=1+1+3和5=1+3+1是同一种划分方法。
 *
 * Input:
 *  1 行， 2 个用单个空格隔开的正整数n,k。
 *
 * Output:
 *  1 行， 1 个正整数 ans ，是将n划分为k个正整数的和的方法数模 1000000007 的结果（即方法数除以 1000000007 的余数）。
 *
 * Hints:
 *  1≤k≤n≤2000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
7 3
 *
 *  output:
4
 *
 *  2):
 *  input:
1453 529
 *
 *  output:
714845206
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n, k, f[2010][2010], mod = 1e9 + 7;

int main()
{
    cin >> n >> k;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;
        }
    }
    cout << f[n][k] << endl;
    return 0;
}