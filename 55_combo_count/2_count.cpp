/**
 * Description:
 *  由数字 1，2 和 3 组成的 n 位数，要求 n 位数中 1，2 和 3 的每一个至少出现一次。求所有这种n 位数的个数。
 *  答案可能很大，你只需要输出答案除以 10<9>+7 的余数。
 *
 * Input:
 *  一个整数 n
 *
 * Output:
 *  输出答案除以10<9>+7的余数
 *
 * Hints:
 *  1≤N≤1000, 2≤K≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
 *
 *  output:
6
 *
 *  2):
 *  input:
2
 *
 *  output:
0
 *
 *  3):
 *  input:
199997
 *
 *  output:
837597358
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
typedef long long LL;
int n, mod = 1e9 + 7;

LL ksm(LL a, LL b, LL p)
{
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cin >> n;
    cout << (ksm(3, n, mod) - 3 * ksm(2, n, mod) % mod + 3 + mod) % mod << endl;
    return 0;
}