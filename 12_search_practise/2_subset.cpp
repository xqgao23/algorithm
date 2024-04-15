/**
 * Description:
 *  给定一个正整数k，和n个正整数a1,a2,..,an和，现在想要从a1,a2,..,an中选出若干个数（也可以一个都不取），使得选出的数之和除以k的余数恰好等于r。问有多少种取数的方案？
 *  例如：k=3，要从1,3,8中选若干数。和除以k=3的余数为0的有0, 3, 1+8, 1+3+8共4种；除3余1的有1, 1+3这2种；除3余2的有8, 3,8这2种。
 *  注意：我们认为一个数都不取也是一种取数方案，此时认为和为0。
 *  对每个余数r=0,1,⋯,k−1，输出和除以k余r的取数方法数。
 *
 * Input:
 *  第1行，2个正整数n,k
 *  第2行，n个正整数a1,a2,...,an
 *
 * Output:
 *  输出k行，第i行输出和除以k余数为i−1的取数方法数。
 *
 * Hints:
 *  1<=n<=20, 1<=k<=10<6>, 1<=ai<=10<8>
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
1 3 8
 *
 *  output:
4
2
2
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
int n, k, a[30], cnt[1000010];

void dfs(int step, int sum)
{
    if (step > n) {
        cnt[sum % k]++;
        return;
    }
    dfs(step + 1, sum + a[step]);
    dfs(step + 1, sum);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    for (int i = 1; i <= k; i++) {
        cout << cnt[i - 1] << "\n";
    }
    return 0;
}