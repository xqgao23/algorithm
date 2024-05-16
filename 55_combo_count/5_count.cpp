/**
 * Description:
 *  由数字 1,2,3,4,5 组成的 n 位数，要求 n 位中包含数码 5，且 3 不能出现在 5 前面。求所有这种 n 位数的个数。
 *  答案可能很大，你只需要输出答案除以 10<9>+7 的余数。
 *
 * Input:
 *  一个整数 n
 *
 * Output:
 *  输出答案除以10<9>+7的余数
 *
 * Hints:
 *  1≤n≤5000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
 *
 *  output:
48
 *
 *  2):
 *  input:
100000
 *
 *  output:
382019221
 *
 */

// 方法一
#include <iostream>
using namespace std;
typedef long long LL;
LL n, C[5010][5010], ans, mod = 1e9 + 7;

void init()
{
    for (int i = 0; i <= 5000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

LL ksm(LL a, LL b, LL p)
{
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        ans = (ans + 1ll * i * C[n][i] % mod * ksm(3, n - i, mod)) % mod;
    }
    cout << ans << endl;
    return 0;
}