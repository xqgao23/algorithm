/**
 * Description:
 *  有一个箱子容量为V（正整数， 0≤V≤20000 ），同时有 n 个物品（ 0<n≤30 ，每个物品有一个体积（正整数）。
 *  要求 n 个物品中，任取若干个装在箱内，使箱的剩余空间为最小。
 *
 * Input:
 *  输入只有1行：
 *  第 1 个正整数，表示箱子容量
 *  第 2 个正整数 n ，表示有 n 个物品
 *  接下来 n 个正整数，分别表示这 n 个物品的各自体积
 *
 * Output:
 *  1 个整数，表示箱子剩余空间。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
24 6 8 3 12 7 9 7
 *
 *  output:
0
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, m, v[35];
bool f[35][20005];
// f[i][j] 表示前i个物品装入容量为j箱子中，能否恰好装满

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] |= f[i - 1][j - v[i]];
            }
        }
    }
    for (int j = m; j >= 0; j--) {
        if (f[n][j]) {
            cout << m - j << endl;
            break;
        }
    }
    return 0;
}