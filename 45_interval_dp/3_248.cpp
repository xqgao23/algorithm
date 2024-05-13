/**
 * Description:
 *  给出一个长为n的数列a1,a2,…,an。每次可以选择两个相邻的值相等的数，将这两个数合成为1个比它们的值大1的数。
 *  问通过合理的选择合成顺序，在合成过程中，通过合成得到的数的最大值是多少？
 *
 * Input:
 *  第1行，1个正整数n。
 *  第2行，n个正整数a1,a2,...,an
 *
 * Output:
 *  输出通过合成得到的数的最大值。
 *
 * Hints:
 *  2≤n≤248, 1≤ai≤40
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
1 1 1 2
 *
 *  output:
3
 *
 */

#include <cstring>
#include <iostream>

using namespace std;

int n, a[260], f[260][260], ans;
// f[i][j]表示合并[i,j]之间的数得到的最大值

int main()
{
    cin >> n;
    memset(f, -0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans = max(ans, a[i]);
        f[i][i] = a[i];
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                if (f[i][k] == f[k + 1][j]) {
                    f[i][j] = max(f[i][j], f[i][k] + 1);
                    ans = max(ans, f[i][j]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}