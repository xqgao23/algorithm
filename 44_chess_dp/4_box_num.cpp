/**
 * Description:
 *  设有n×m的方格图，每个方格中都有一个整数。现有一只小熊，想从图的左上角走到右下角，每一步只能向上、向下或向右走一格，并且不能重复经过已经走过的方格，也不能走出边界。小熊会取走所有经过的方格中的整数，求它能取到的整数之和的最大值。
 *
 * Input:
 *  第1行两个正整数 n,m。
 *  接下来n行每行m个整数，依次代表每个方格中的整数。
 *
 * Output:
 *  一个整数，表示小熊能取到的整数之和的最大值。
 *
 * Hints:
 *  n,m≤1000, 方格中整数的绝对值不超过10<4>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 4
1 -1 3 2
2 -1 4 -1
-2 2 -3 -1
 *
 *  output:
9
 *
 *  2):
 *  input:
2 5
-1 -1 -3 -2 -7
-2 -1 -4 -1 -2
 *
 *  output:
-10
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, a[1010][1010];
long long f[1010][1010][3];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(f, -0x3f, sizeof f);
    f[0][1][0] = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            f[i][j][0] = max(max(f[i][j - 1][0], f[i][j - 1][1]), f[i][j - 1][2]) + a[i][j];
            f[i][j][1] = max(f[i - 1][j][0], f[i - 1][j][1]) +
                         a[i][j];
        }
        for (int i = n; i >= 1; i--) {
            f[i][j][2] = max(f[i + 1][j][0], f[i + 1][j][2]) +
                         a[i][j];
        }
    }
    cout << max(f[n][m][0], f[n][m][1]) << endl;
    return 0;
}