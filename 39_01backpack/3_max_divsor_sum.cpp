/**
 * Description:
 *  选取和不超过S的若干个不同的正整数，使得所有数的约数（不含它本身）之和最大。
 *
 * Input:
 *  输入一个正整数S.
 *
 * Output:
 *  输出最大的约数之和。
 *
 * Hints:
 *  1<=S<=1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
11
 *
 *  output:
9
 *
 */

// 二维
#include <algorithm>
#include <iostream>
using namespace std;
int s, f[1010][1010];

int factor_sum(int n)
{
    int sum = -n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i) {
                sum += i;
            } else {
                sum += i + n / i;
            }
        }
    }
    return sum;
}

int main()
{
    cin >> s;
    for (int i = 1; i <= s; i++) {
        for (int j = 0; j <= s; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= i) {
                f[i][j] = max(f[i][j], f[i - 1][j - i] + factor_sum(i));
            }
        }
    }
    cout << f[s][s] << endl;
    return 0;
}