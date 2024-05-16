/**
 * Description:
 *  有排成一列的 N 个球. 现在小明想要把这些球都涂成 K 种颜色中的某一种. 若要求任意相邻两个球颜色不同, 共有多少种不同的涂色方法？ 答案可能很大，你只需要输出答案除以 10<9>+7 的余数。
 *
 * Input:
 *  一行，两个正整数N,K
 *
 * Output:
 *  一行, 一个整数代表涂色方法数除以10<9>+7的余数
 *
 * Hints:
 *  1≤N≤1000, 2≤K≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 2
 *
 *  output:
2
 *
 *  2):
 *  input:
10 8
 *
 *  output:
322828856
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
LL n, k, mod = 1e9 + 7;

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
    cin >> n >> k;
    cout << k * ksm(k - 1, n - 1, mod) % mod << endl;
    return 0;
}