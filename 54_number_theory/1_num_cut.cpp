/**
 * Description:
 *  所有的正整数均可以表示为一个、两个或者多个连续正整数的和。
 *  给定一个不超过 9×10<14>的正整数，求出它可以用几种不同的方法表示成连续正整数之和。例如给出 9，则有三种方式：9,4+5,2+3+4。
 *
 * Input:
 *  输入一个正整数 n，表示要被拆分的正整数。
 *
 * Output:
 *  输出方法个数
 *
 * Hints:
 *  n≤9*10<14>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
9
 *
 *  output:
3
 *
 *  2):
 *  input:
11
 *
 *  output:
2
 *
 *  3):
 *  input:
12
 *
 *  output:
2
 *
 */

// 60分
#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
    LL n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if ((i + j) * (j - i + 1) / 2 == n) {
                ans++;
            }
            if ((i + j) * (j - i + 1) / 2 > n) {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}