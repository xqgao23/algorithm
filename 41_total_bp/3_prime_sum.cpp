/**
 * Description:
 *  任何大于 1 的自然数 n 都可以写成若干个大于等于 2 且小于等于 n 的质数之和表达式（包括只有一个数构成的和表达式的情况），并且可能有不止一种质数和的形式。例如，9 的质数和表达式就有四种本质不同的形式：9=2+5+2=2+3+2+2=3+3+3=2+7 。
 *  这里所谓两个本质相同的表达式是指可以通过交换其中一个表达式中参加和运算的各个数的位置而直接得到另一个表达式。
 *  试编程求解自然数 n 可以写成多少种本质不同的质数和表达式。
 *
 * Input:
 *  自然数n(2≤n≤1000)
 *
 * Output:
 *  输出n 的本质不同的质数和表达式的数目。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
200
 *
 *  output:
9845164
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int n, m, w[1010];
LL f[1010][1010];
// f[i][j] 表示前i个质数组成j的方案数

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

int main()
{
    cin >> m;
    for (int i = 2; i <= m; i++) {
        if (isPrime(i)) {
            w[++n] = i;
        }
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) {
                f[i][j] += f[i][j - w[i]];
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}