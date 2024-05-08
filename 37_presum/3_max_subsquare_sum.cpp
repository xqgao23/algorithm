/**
 * Description:
 *  给出二维数组a的元素a[1][1],a[1][2],⋯,a[n][m]的值，并排列为矩形. 如果我们取其中一个非空的子矩形区域，那么其中的数字和最大是多少?
 *
 * Input:
 *  第1行,2个正整数n,m,表示数组a存储了n行m列的整数。
 *  之后n行，每行用空格隔开的m个整数，依次是a[1][1],a[1][2],⋯,a[n][m]的值。
 *
 * Output:
 *  1个整数，为所求的最大的和.
 *
 * Hints:
 *  n,m≤400；对1≤i≤n, 1≤j≤m,−10000≤a[i][j]≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
1 2 3
-4 -1 -2
1 2 3
 *
 *  output:
7
 *
 */

#include <iostream>

using namespace std;

int n, m, a[410][410], s[410][410], b[410], f[410], ans;

int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + a[i][j];
        }
    }
    
    for (int x1 = 1; x1 <= n; x1++) {
        for (int x2 = x1; x2 <= n; x2++) {
            for (int j = 1; j <= m; j++) {
                f[j] = max(f[j - 1], 0) + s[x2][j] - s[x1 - 1][j];
                ans = max(ans, f[j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}