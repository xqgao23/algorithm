/**
 * Description:
 *  给出n项的数列，要求将数列划分成若干段，且每一段之和都不超过s。 求一共有多少种满足要求的划分方法。
 *  方法数很大，只要求输出除以10<9>的余数。
 *
 * Input:
 *  第1行，两个正整数n,s
 *  第2行，n个正整数a1,a2,...,an
 *
 * Output:
 *  一个整数，划分方法数除以10<9>的余数。
 *
 * Hints:
 *  1≤n,ai≤1000, 1≤s≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3
1 2 1 1 1
 *
 *  output:
10
 *
 */

#include <iostream>
#include <string>

using namespace std;

int n, sum, a[1010], s[1010], f[1010], mod = 1e9;
// f[i] 表示以 a[i] 结尾的划分方案

int main()
{
    cin >> n >> sum;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (s[i] - s[j - 1] <= sum) {
                f[i] = (f[i] + f[j - 1]) % mod;
            }
        }
    }
    
    cout << f[n] << endl;

    return 0;
}