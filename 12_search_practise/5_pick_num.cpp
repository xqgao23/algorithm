/**
 * Description:
 *  已知 n 个整数 x1,x2,..,xn，以及 1 个整数 k(k<n)。从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。例如当 n=4，k=3,
 * 4 个整数分别为 3,7,12,19 时，可得全部的组合与它们的和为： (3,7,12)：3+7+12=22
 *  (3,7,19): 3+7+19=29
 *  (7,12,19)：7+12+19=38
 *  (3,12,19)：3+12+19=34。
 *  其中只有一种的和为素数：3+7+19=29。
 *  现在，要求你计算出和为素数的组合方案共有多少种。（注意不同的组合方案可能得到同样的和，这些方案各算一种）
 *
 * Input:
 *  第一行两个正整数 n,k(1≤n≤20,k<n)。
 *  第二行 n 个正整数 x1,x2,…,xn(1<=xi<=5000000)
 *
 * Output:
 *  输出一个整数, 为满足条件的种数。
 *
 * Hints:
 */

/**
 *  Samples:
 *  1):
 *  input:
4 3
3 7 12 19
 *
 *  output:
6
 *
 */

#include <iostream>
using namespace std;

int n, k, x[30], p[30], vis[30], ans;

bool isPrime(int n)
{
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int step, int sum)
{
    if (step > k) {
        cout << sum << endl;
        if (isPrime(sum)) {
            ans++;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            p[step] = i;
            vis[i] = 1;
            dfs(step + 1, sum + x[i]);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}