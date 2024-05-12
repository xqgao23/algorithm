/**
 * Description:
 *  输出文件只有一行数字：顾客不能用包装盒买到麦香牛块的最大块数或0（如果所有购买方案都能得到满足或者顾客不能买到的块数没有上限）使用n个火柴棍可以摆成的整数中，最大的是多少？
 *  但是能够出现在整数中的数码，必须是给定集合{a1,a2,…,am}中的数。要求把所有n根火柴全用光。
 *  摆出0,1,2,3,4,5,6,7,8,9分别需要6,2,5,5,4,5,6,3,7,6根火柴
 *
 * Input:
 *  第1行，2个正整数n,m
 *  第2行，m个整数{a1,a2,…,am}
 *
 * Output:
 *  输出可以摆成的整数中，最大的数
 *
 * Hints:
 *  2≤n≤10<4>, 1≤m≤10 0≤ai≤9，且ai互不相同
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
20 4
3 7 8 4
 *
 *  output:
777773
 *
 *  2):
 *  input:
101 9
9 8 7 6 5 4 3 2 1
 *
 *  output:
71111111111111111111111111111111111111111111111111
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, a[15], w[15], c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int f[15][10010];
// f[i][j] 表示前i种数码恰好消耗j个火柴棍得到的整数的最大长度

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        w[i] = c[a[i]];
    }
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) {
                f[i][j] = max(f[i][j], f[i][j - w[i]] + 1);
            }
        }
    }
    sort(a + 1, a + m + 1, greater<int>());
    for (int i = 1; i <= m; i++) {
        w[i] = c[a[i]];
    }
    while (n) {
        for (int i = 1; i <= m; i++) {
            if (w[i] <= n && f[m][n - w[i]] == f[m][n] - 1) {
                cout << a[i];
                n -= w[i];
                break;
            }
        }
    }
    return 0;
}