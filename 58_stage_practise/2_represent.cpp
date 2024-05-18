/**
 * Description:
 *  求满足以下条件的长度为 n 的整数数列 a1,a2,..,an 的个数。
 *  （1）0≤ai≤9。
 *  （2）至少存在一个 ai=0 的项。
 *  （3）至少存在一个 ai=9 的项。
 *  你只需要输出答案除以 10<9>+7 的余数。
 *
 * Input:
 *  1个正整数n
 *
 * Output:
 *  输出满足条件的数列个数。
 *
 * Hints:
 *  1≤n≤10<6>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
 *
 *  output:
2
 *
 *  2):
 *  input:
5
 *
 *  output:
14670
 *
 *  3):
 *  input:
9999
 *
 *  output:
554127480
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
int n, mod = 1e9 + 7;

LL ksm(LL a, LL b)
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
    cout << (ksm(10, n) - 2 * ksm(9, n) % mod + ksm(8, n) + mod) % mod << endl;
    return 0;
}