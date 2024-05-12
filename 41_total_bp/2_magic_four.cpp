/**
 * Description:
 *  将一个整数 n 分解为若干个四次方数的和，求四次方数的最小个数。
 *  例如对 n=17，17=2<4> + 1<4>，最小个数为2
 *
 * Input:
 *  整数n
 *
 * Output:
 *  输出一行一个整数，代表最小个数。
 *
 * Hints:
 *  0≤n≤100000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
17
 *
 *  output:
2
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int n, f[20][100010];
// f[i][j] 表示前i个整数恰好组成和为j的最小个数

int main()
{
    cin >> n;
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= 18; i++) {
        int w = i * i * i * i;
        for (int j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w) {
                f[i][j] = min(f[i][j], f[i][j - w] + 1);
            }
        }
    }
    cout << f[18][n] << endl;
    return 0;
}